//
//  LFDeviceSimulator.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 16/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFBaseDeviceHandler.h"
#import "LFXMLReader.h"
#import "LFWorkout.h"

@interface LFDeviceSimulator : LFBaseDeviceHandler <LFXmlParseDelegate,LFGPSReplayDelegate>
{
    int time;
    
    int numberOfPresets;
    //int maxPacketSize;
    NSMutableArray *presetFileList;
    NSTimer *timer;
    NSTimer *workoutTimer;
    
    NSString *xmlFileData;
    LFWorkout *processWorkout;
    int elapsedWorkoutSecond;
}

+ (LFDeviceSimulator*) getInstance;

@property(nonatomic, assign) id<DeviceCommunicationDelegate> delegate;
@property(nonatomic, retain) NSArray *presetFileList;
@property(nonatomic, retain) LFWorkout *processWorkout;



@end
