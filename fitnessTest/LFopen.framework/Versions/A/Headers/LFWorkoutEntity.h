//
//  WorkoutEntity.h
//  LFOpenDemo
//
//  Created by Dileepa on 5/11/14.
//  Copyright (c) 2014 Dileepa. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"



@interface LFPresetWorkoutParam : NSObject
{
    enum GoalTypes type;
    NSString * name;
    double value;
}
@property enum GoalTypes type;
@property (nonatomic, strong) NSString * name;
@property (nonatomic, assign) double value;
@end


@interface LFPresetGoal : NSObject
{
    enum GoalTypes goalType;
    enum LFDeviceType eqType;
    enum CardioProgramType woType;
    NSString * goalName;
    NSMutableArray * workoutParameters;
    NSMutableArray * userParameters;
    
}


@property enum GoalTypes goalType;
@property enum LFDeviceType eqType;
@property enum CardioProgramType woType;
@property (nonatomic, strong) NSString * goalName;


@property (nonatomic, strong) NSMutableArray * workoutParameters,* userParameters;
@end

@interface LFCardioProgram : NSObject
{
    NSString *workoutName;
    NSMutableArray *goalList;
    enum CardioProgramType type;
}

@property (nonatomic, strong) NSString *workoutName;
@property (nonatomic, strong) NSMutableArray *goalList;
@property enum CardioProgramType type;

@end


@interface LFActivityInfo : NSObject
{
    long userId;
    long workoutId;
    long workoutActivityId;
    long activityDefinitionId;
}

@property (nonatomic) long userId;
@property (nonatomic) long workoutId;
@property (nonatomic) long workoutActivityId;
@property (nonatomic) long activityDefinitionId;

@end



