//
//  ConnectViewController.m
//  fitnessTest
//
//  Created by SapientiaWind on 17/3/21.
//  Copyright © 2017年 Social Capital Consulting Limited. All rights reserved.
//

#import "ConnectViewController.h"
#import <LFopen/LFopen.h>
#import "ScanViewController.h"
@interface ConnectViewController ()<DeviceCommunicationDelegate,ScanCompletionDelegate>{
    LFServiceProvider *serviceProvider;
}
@property (weak, nonatomic) IBOutlet UILabel *connectLabel;
@property (weak, nonatomic) IBOutlet UILabel *time_headLabel;
@property (weak, nonatomic) IBOutlet UILabel *distance_headLabel;
@property (weak, nonatomic) IBOutlet UILabel *burned_headLabel;
@property (weak, nonatomic) IBOutlet UILabel *timeLabel;
@property (weak, nonatomic) IBOutlet UILabel *distanceLabel;
@property (weak, nonatomic) IBOutlet UILabel *burnedLabel;
@property (strong, nonatomic) NSMutableArray *workouts;
@property (assign, nonatomic) BOOL isStart;
@end

@implementation ConnectViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    serviceProvider = [LFServiceProvider getInstance];
    [serviceProvider registerForDeviceService:self simulation:NO];  // simulation 为true 是模拟模式
    [serviceProvider setLicence:@"2528-4266194561-9929"]; //Your Licence
    
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
//链接
- (void)didDeviceConnect{
    _connectLabel.text = @"已连接";
}
//断开连接
- (void)didDeviceDisconnect{
    _connectLabel.text = @"未连接";
}
//获取到fileName
- (void)didReceivedResultFileName:(NSString *)fileName{

}
//运动类型
- (int)numberOfPresetsToShow:(enum LFDeviceType)deviceTypeValue{

    NSLog(@"deviceTypeValue == %zd",deviceTypeValue);
    return 0;
}
- (NSArray *)presetListToShowFrom:(NSInteger)fromIndex toIndex:(NSInteger)toIndex{
    NSArray *arry = [_workouts valueForKey:@"workoutName"];
    NSRange range = NSMakeRange(fromIndex, toIndex);
    if([arry count] > 0 && arry.count >= (fromIndex+toIndex)) {
        
        return [arry subarrayWithRange:range];
    }
    
    return nil;
}

- (LFWorkout *)presetDataForIndex:(NSInteger)index{

    LFWorkout *workout = [_workouts objectAtIndex:index];
    workout.workoutType = LFPresetConsole;
    return workout;
}

- (void)didReceivedWorkoutStream:(LFWorkoutStream *)streamData{
    if(!_isStart){
        _isStart = true;
    }
    
    _timeLabel.text = [self getFormattedTime:streamData.elapsedWorkoutSeconds];
    _distanceLabel.text = [self getStringForDouble:streamData.accumulatedDistance formatter:@"###0.##"];
    _burnedLabel.text = [self getStringForDouble:streamData.accumulatedCalories formatter:@"###0.##"];
    
    NSLog(@"currentLevel : %d", streamData.currentLevel);
    NSLog(@"workoutState : %d", streamData.workoutState);
    
}

//接收到运动结果了
- (void)didReceivedResultData:(LFWorkout *)workout{

    _isStart = false;
    dispatch_async(dispatch_get_main_queue(), ^{
        _connectLabel.text = @"已完成";
        _timeLabel.text = [self getFormattedTime:workout.elapsedTime];
        _distanceLabel.text = [self getStringForDouble:workout.calories formatter:@"###0.##"];
        _burnedLabel.text = [self getStringForDouble:workout.distanceValue formatter:@"###0.##"];
    });
 
}

- (IBAction)scanButtonClick:(UIButton *)sender {
    
    ScanViewController * scanView = [[ScanViewController alloc] initWithNibName:@"ScanViewController" bundle:nil];
    scanView.delegate = self;
    [self presentViewController:scanView animated:YES completion:nil];
}

- (void)connectTocponsoleWithMacAddress:(NSString *)mac{

    [serviceProvider connectToConsolewithBLEusingMacAddress:mac];
}

- (void)strengthWithRSSIValue:(double)rssi{
    NSLog(@"蓝牙链接RSSI == %f",rssi);
    NSString *message = [NSString stringWithFormat:@"蓝牙链接RSSI == %f",rssi];
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", @"Error (alert title)")
                                                        message:message
                                                       delegate:nil cancelButtonTitle:nil otherButtonTitles:nil];
    
    [alertView addButtonWithTitle:NSLocalizedString(@"OK", @"Button for dismissing alert")];
    [alertView show];
}

- (void)didErrorOccuredWithBLEconnection:(NSError*)error{
    NSLog(@"蓝牙链接error == %@",error);
    NSString *message = [NSString stringWithFormat:@"蓝牙链接error == %@",error];
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", @"Error (alert title)")
                                                        message:message
                                                       delegate:nil cancelButtonTitle:nil otherButtonTitles:nil];
    
    [alertView addButtonWithTitle:NSLocalizedString(@"OK", @"Button for dismissing alert")];
    [alertView show];
}

- (BOOL)didConsoleHaveInternetConnection:(BOOL)hasConnection macAddres:(NSString *)strMac{
    NSString *message = [NSString stringWithFormat:@"蓝牙链接macAddres == %@  hasConnection == %zd",strMac,hasConnection];
    NSLog(@"蓝牙链接macAddres == %@  hasConnection == %zd",strMac,hasConnection);
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", @"Error (alert title)")
                                                        message:message
                                                       delegate:nil cancelButtonTitle:nil otherButtonTitles:nil];
    
    [alertView addButtonWithTitle:NSLocalizedString(@"OK", @"Button for dismissing alert")];
    [alertView show];
    return YES;
    
}


- (NSString*)getStringForDouble:(double)value formatter:(NSString*) format
{
    if(!format)
    {
        format =  @"###,###,###,###,###,##0.00";
    }
    NSNumberFormatter *formatter = [[NSNumberFormatter alloc] init];
    [formatter setFormatterBehavior:NSNumberFormatterBehavior10_4];
    [formatter setPositiveFormat:format];
    [formatter setNegativeFormat:format];
    NSString *returnString = [formatter stringFromNumber:[NSNumber numberWithDouble:value]];
    return returnString;
}

- (NSString *)getFormattedTime:(long)seconds{
    
    NSUInteger h = seconds / 3600;
    NSUInteger m = (seconds / 60) % 60;
    NSUInteger s = seconds % 60;
    
    NSString *formattedTime = [NSString stringWithFormat:@"%lu:%02lu:%02lu", (unsigned long)h, (unsigned long)m, (unsigned long)s];
    
    return formattedTime;
}


@end
