//
//  LFBaseDeviceHandler.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 16/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFServiceProvider.h"
#import "LFWorkout.h"
#import "LFGPSReplayManager.h"

typedef enum LFDeviceCommand
{
    LFCommandGetNumberOfPresets = 1,
    LFCommandRetNumberOfPresets = 2,
    LFCommandGetPresetList = 3,
    LFCommandRetPresetList = 4,
    LFCommandGetPresetData = 5,
    LFCommandRetPresetData = 6,
    LFCommandGetPlayList = 7,
    LFCommandRetPlayList = 8,
    LFCommandSendResultFileName = 9,
    LFCommandSendResultFileData = 10,
    LFCommandGetVersion = 11,
    LFCommandRetVersion = 12,
    LFCommandGetConsoleVersion = 13,
    LFCommandRetConsoleVersion = 14,
    LFCommandGetMaxPacketSize = 15,
    LFCommandRetMaxPacketSize = 16,
    LFCommandReceivedStream = 17,
    LFCommandGetUserInfo               = 0x22,
    LFCommandRetUserInfo               = 0x23,
    LFCommandGetUserSettings           = 0x24,
    LFCommandRetUserSettings           = 0x25,
    LFCommandGetMaxTime = 20,
    LFCommandRetMaxTime = 21,
    LFCommandGetMaxIncline = 22,
    LFCommandRetMaxIncline = 23,
    LFCommandSendIncline = 24,
    LFCommandSendInclineAcknowladgement = 25,
    LFCommandSendWatts = 26,
    LFCommandSendWattsAcknowladgement = 27,
    LFCommandSendWorkoutLevel = 28,
    LFCommandSendWorkoutLevelAcknowladgement = 29,
    LFCommandSendWorkoutTargetHartRate = 30,
    LFCommandSendWorkoutTargetHartRateAcknowladgement = 31,
    LFCommandSendConsoleMessage = 32,
    LFCommandSendConsoleMessageAcknowladgement = 33,
    
}LFDeviceCommand;

@interface LFBaseDeviceHandler : NSObject
{
    NSString *consoleVersion;
    NSMutableDictionary *dicResultFileData;
    int deviceType;
    int maxPacketSize;
    
    NSString *resultFileName;
    enum LFPresetType currentPresetType;
}


@property (nonatomic, strong) LFGPSReplayManager * gpsReplayManager;
@property(nonatomic, retain) NSString *consoleVersion;
@property(nonatomic, retain) NSString *resultFileName;
@property int deviceType;
@property int maxPacketSize;
@property enum LFPresetType currentPresetType;

- (void)sendPresetDataFile:(NSString*)fileData;
- (void)sendUserInformation:(NSString*)xmlstring;
- (void)writeInclineValue:(double)incline;
- (void)writeWattsValue:(int)watts;
- (void)writeWorkoutLevel:(int)level;
- (void)writeWorkoutHeartrate:(int)heartrate;
- (void)writeConsoleMessage:(NSString*)message;
- (void)getConsoleMaxTime;
- (void)getConsoleMaxHeartRate;
- (void)getConsoleMaxIncline;

@end
