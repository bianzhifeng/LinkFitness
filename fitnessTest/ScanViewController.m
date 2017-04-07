//
//  ScanViewController.m
//  fitnessTest
//
//  Created by SapientiaWind on 17/3/21.
//  Copyright © 2017年 Social Capital Consulting Limited. All rights reserved.
//

#import "ScanViewController.h"
#import <AVFoundation/AVFoundation.h>
#import "NSString+base.h"
@interface ScanViewController ()<AVCaptureMetadataOutputObjectsDelegate>
@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (nonatomic, strong) AVCaptureSession *captureSession;
@property (nonatomic, strong) AVCaptureVideoPreviewLayer *videoPreviewLayer;
@property (nonatomic, strong) AVAudioPlayer *audioPlayer;
@property (nonatomic, strong) NSString * macAddress;
@property (nonatomic) BOOL isReading;
@property BOOL isAlreadyRead;
@end

@implementation ScanViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    [self startReading];

}

//对base64编码后的字符串进行解码
-(NSString *)base64DecodeString:(NSString *)string

{
    //1.将base64编码后的字符串『解码』为二进制数据
    
    NSData *data = [[NSData alloc]initWithBase64EncodedString:string options:0];

    //2.把二进制数据转换为字符串返回
    
    return [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
    
}



- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidLayoutSubviews
{
    [_videoPreviewLayer setFrame:self.containerView.bounds];
}

- (BOOL)startReading
{
    NSError *error;
    // Get an instance of the AVCaptureDevice class to initialize a device object and provide the video
    // as the media type parameter.
    if ([[AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo] respondsToSelector:@selector(authorizationStatusForMediaType:)]) {
        AVAuthorizationStatus status = [AVCaptureDevice authorizationStatusForMediaType:AVMediaTypeVideo];
        
        if (status == AVAuthorizationStatusNotDetermined) {
            [AVCaptureDevice requestAccessForMediaType:AVMediaTypeVideo completionHandler:^(BOOL granted) {
                if (granted) {
                    NSLog(@"Authorize AVMediaTypeVideo");
                }
            }];
        }
    }
    
    
    AVCaptureDevice *captureDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    
    // Get an instance of the AVCaptureDeviceInput class using the previous device object.
    AVCaptureDeviceInput *input = [AVCaptureDeviceInput deviceInputWithDevice:captureDevice error:&error];
    
    if (!input) {
        // If any error occurs, simply log the description of it and don't continue any more.
        NSLog(@"startReadingError == %@", [error localizedDescription]);
        return NO;
    }
    
    if (_captureSession == nil)
    {
        // Initialize the captureSession object.
        _captureSession = [[AVCaptureSession alloc] init];
        // Set the input device on the capture session.
    }
    
    [_captureSession addInput:input];
    
    
    // Initialize a AVCaptureMetadataOutput object and set it as the output device to the capture session.
    AVCaptureMetadataOutput *captureMetadataOutput = [[AVCaptureMetadataOutput alloc] init];
    [_captureSession addOutput:captureMetadataOutput];
    
    // Create a new serial dispatch queue.
    dispatch_queue_t dispatchQueue;
    dispatchQueue = dispatch_queue_create("myQueue", NULL);
    [captureMetadataOutput setMetadataObjectsDelegate:self queue:dispatchQueue];
    [captureMetadataOutput setMetadataObjectTypes:[NSArray arrayWithObject:AVMetadataObjectTypeQRCode]];
    
    _videoPreviewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:_captureSession];
    [_videoPreviewLayer setVideoGravity:AVLayerVideoGravityResizeAspectFill];
    [_videoPreviewLayer setFrame:self.containerView.bounds];
    [self.containerView.layer addSublayer:_videoPreviewLayer];
    
    // Start video capture.
    [_captureSession startRunning];
    
    return YES;
}


-(void)stopReading{
    // Stop video capture and make the capture session object nil.
    _isReading=NO;
    [_captureSession stopRunning];
    _captureSession = nil;
    
    // Remove the video preview layer from the viewPreview view's layer.
    [_videoPreviewLayer removeFromSuperlayer];
    _videoPreviewLayer = nil;
}


#pragma mark - AVCaptureMetadataOutputObjectsDelegate method implementation

-(void)captureOutput:(AVCaptureOutput *)captureOutput didOutputMetadataObjects:(NSArray *)metadataObjects fromConnection:(AVCaptureConnection *)connection{
    
    // Check if the metadataObjects array is not nil and it contains at least one object.
    if (metadataObjects != nil && [metadataObjects count] > 0) {
        // Get the metadata object.
        AVMetadataMachineReadableCodeObject *metadataObj = [metadataObjects objectAtIndex:0];
        if ([[metadataObj type] isEqualToString:AVMetadataObjectTypeQRCode] && !_isAlreadyRead) {
            [_captureSession stopRunning];
            AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
            _isReading = NO;
            _isAlreadyRead = YES;
            [self performSelectorOnMainThread:@selector(processQRcode:) withObject:[metadataObj stringValue] waitUntilDone:YES];
        }
    }
}

//处理二维码
- (void)processQRcode:(NSString*)value
{
    NSString *qr_result_string_unedit = value;
    NSString * qr_result_string = [[NSString alloc] initWithFormat:@"%@",[qr_result_string_unedit stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]];
    
    if([qr_result_string  rangeOfString:@"t=c&l"].location != NSNotFound)
    {
        [self performSelectorOnMainThread:@selector(stopReading) withObject:nil waitUntilDone:YES];
        
        NSRange base = [qr_result_string  rangeOfString:@"l="];
        NSString *strParameter = [qr_result_string substringFromIndex:base.location];
        
        NSArray *paramList = [strParameter componentsSeparatedByString:@"&"];
        NSString * baseSerial;
        NSString * sessionId;
        int console_network_connection_flag = 1;
        
        for (NSString *str in paramList) {
            if ([str rangeOfString:@"l="].length > 0) {
                baseSerial = [str stringByReplacingOccurrencesOfString:@"l=" withString:@""];;
            }else if([str rangeOfString:@"x="].length > 0){
                sessionId = [str stringByReplacingOccurrencesOfString:@"x=" withString:@""];
            }else if ([str rangeOfString:@"c="].length > 0){
                NSString *strFlag = [str stringByReplacingOccurrencesOfString:@"c=" withString:@""];
                console_network_connection_flag = [strFlag intValue];
            }else if ([str rangeOfString:@"a="].length > 0){
                NSString *strFlag = [str stringByReplacingOccurrencesOfString:@"a=" withString:@""];
                _macAddress = strFlag;
            }
        }
        [_delegate connectTocponsoleWithMacAddress:_macAddress];
        [self dismissViewControllerAnimated:YES completion:nil];
        
    }else{
        
        _isAlreadyRead = NO;
        [_captureSession startRunning];
        [self promptError:value];
    }
}


- (void)promptError:(NSString *)message
{
    UIAlertView* alertView = [[UIAlertView alloc] initWithTitle:NSLocalizedString(@"Error", @"Error (alert title)")
                                                        message:message
                                                       delegate:nil cancelButtonTitle:nil otherButtonTitles:nil];
    
    [alertView addButtonWithTitle:NSLocalizedString(@"OK", @"Button for dismissing alert")];
    [alertView show];
}


@end
