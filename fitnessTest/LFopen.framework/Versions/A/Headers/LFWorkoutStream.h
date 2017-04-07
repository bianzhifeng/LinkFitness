//
//  LFStreamData.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 16/11/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFGPSLocation.h"

enum LFWorkoutState
{
	LFWorkoutStateIdle = 0,
	LFWorkoutStateActive,
	LFWorkoutStatePaused,
	LFWorkoutStateCoolDown,
	LFWorkoutStateSummary,
};

@interface LFWorkoutStream : NSObject
{
    
}

@property int streamVersion;
@property int elapsedWorkoutSeconds;
@property int targetWorkoutSeconds;
@property int accumulatedCalories;
@property int targetCalories;
@property float accumulatedDistance;
@property float targetDistance;
@property float accumulatedDistanceClimbedMeter;
@property int targetDistanceClimbedMeter;
@property int currentSpeedRPM;
@property float currentSpeedKM;
@property float targetSpeedKM;
@property float currentIncline;
@property float targetIncline;
@property int targetHeartRate;
@property int currentHeartRate;
@property int currentResistance;
@property int currentLevel;
@property int currentResisteance; // watts
@property int elapsedHRZone;
@property int targteHRZone;
@property enum LFWorkoutState workoutState;
@property (nonatomic, retain) LFGPSLocation * matchGPSLocation;

- (double)getCompletedPercentage;
- (int)getTargetParameter;
//- (double)getPace;

@end
