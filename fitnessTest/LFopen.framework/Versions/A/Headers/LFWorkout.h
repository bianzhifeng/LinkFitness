//
//  LFWorkout.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFEquipment.h"

enum LFPresetType {
    LFPresetConsole = 0,
    LFPresetGPS = 1
}LFPresetType;

@interface LFWorkout : NSObject
{

    /**
     workoutId (long)	1/1	 Unique Identifier of the workout segment.
     */
    long workoutId;
    
    
    /**
     workoutId (long)	1/1	 Unique Identifier of activity segment.
     */
    long activityId;

    int time;
    /**
     time (double)	0/1	 Workout elapsed duration in minute.
     */
    int elapsedTime;
    
    /**
     time (double)	0/1	 Workout define duration in minute.
     */
    int defineTime;

    int equipmentId;
    /**
     distance (double)	0/1	 Workout Distance.
     */
    double distanceValue;
    /**
     calories (double)	0/1	 Workout Calories.
     */
    double calories;
    /**
     incline (double)	0/1	 Workout incline.
     */
    double incline;
    /**
     level (double)	0/1	 Workout level.
     */
    double level;
    /**
     heartRate (double)	0/1	 Workout heart rate.
     */
    double heartRate;
    /**
     distanceClimbed (double)	0/1	 Workout distance climbed.
     */
    double distanceClimbed;
    /**
     pace (double)	0/1	 Workout pace.
     */
    double pace;
    /**
     initialSpeed (double)	0/1	 Workout initial speed.
     */
    double initialSpeed;
    /**
     avarage speed (double)	0/1	 Workout initial speed.
     */
    double avarageSpeed;
    /**
     goal (int)	0/1	 indicate which parameter is the goal. id 1 - distance id 2 - calories id 3 - pace id 4 - time id 5 - distance climbed
     */
    int goal;
    /**
     height (double)	0/1	 indicate which parameter is the height.
     */
    double height;
    
    /**
     speed limit (double)	0/1	 indicate which parameter is the speed_limt under user profile data.
     */
    double speed_limit;
    
    /**
     level limit (double)	0/1	 indicate which parameter is the level_limt under user profile data.
     */
    double level_limit;
    
    /**
     deviceType (long)	0/unbounded	 Device type(s) for this workout.
     */
    NSArray *deviceTypesList;
    /**
    workoutName (string)	1/1	 Workout Name e.g. Weight Loss- Beginner Wks 1-4.
     */
    NSString *workoutName;
    /**
     workoutDays (string)	1/1	 Workout Days. Consist of number of days in comma separated. Format : 1 is Sun, 2 is Mon .. 7 is Sat. e.g : 2,5,7 is Monday, Thursday and Saturday.
     */
    NSString *workoutDays;
    /**
     unit (string)	1/1	 Unit. I for imperial and M for metric.
     */
    NSString *unit;
    /**
     filename (string)	0/1	 Preset Filename string.
     */
    NSString *workoutFileName;

    NSString *location;
    /**
    equipment (string)	1/1	 Equipment Name e.g. CrossTrainer.
     */
    NSString *equipmentName;
    /**
     filename (string)	0/1	 Preset Filename string.
     */
    NSString *fileName;
    /**
     presetFile (string)	0/1	 XML of the preset file, encoded in Base64 UTF-8.
     */
    NSString *fileData;
    
    NSString *workoutCreatedDateString;
    
    NSString *workoutModifiedDateString;
    
    /**
     Unique fro each workout result in equipment.
     */
    NSString *guid;
    
    LFEquipment *equipment;
    NSMutableArray *gpsPointList;
}

@property long workoutId;
@property long activityId;;
@property int equipmentId;
@property double distanceValue;
@property double calories;
@property double incline;
@property double level;
@property double heartRate;
@property double distanceClimbed;
@property double pace;
@property double initialSpeed;
@property  double avarageSpeed;
@property int goal;
@property int elapsedTime;
@property int time;
@property double height;
@property double speed_limit;
@property double level_limit;
@property (nonatomic, retain) NSArray *deviceTypesList;
@property (nonatomic, retain) NSString *workoutDays;
@property (nonatomic, retain) NSString *workoutName;
@property (nonatomic, retain) NSString *unit;
@property (nonatomic, retain) NSString *workoutFileName;
@property (nonatomic, retain) NSString *location;
@property (nonatomic, retain) NSString *equipmentName;
@property (nonatomic, retain) NSString *fileName;
@property (nonatomic, retain) NSString *fileData;
@property (nonatomic, retain) NSString *workoutCreatedDateString;
@property (nonatomic, retain) NSString *workoutModifiedDateString;
@property (nonatomic, retain) NSString *guid;
@property (nonatomic, retain) LFEquipment *equipment;
@property (nonatomic, retain) NSMutableArray *gpsPointList;
@property enum LFPresetType workoutType;


- (NSString*)createGPSPresetFile;

@end

