//
//  LFRequest.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"
#import "LFUser.h"


/**
 Class to communicate between LFServiceLib API and the program which use LFDeviceLib.  
 */
@interface LFRequest : NSObject
{
    /**
     LFRequestType use to identify different request
     */
    enum LFRequestType requestType;
    NSString *access_token;
}

@property enum LFRequestType requestType;
@property  (nonatomic, retain) NSString *access_token;

@end

#pragma Interface of LFAuthRequest

///**
// Class to send authentication request  
// */
//@interface LFAuthRequest : LFRequest
//{
//    /**
//     username for hold user name of the authentication function
//     */
//    NSString *username;
//    /**
//     password for hold password of the authentication function
//     */
//    NSString *password;
//    /**
//     token 
//     */
//    NSString *token;
//}
//
//@property (nonatomic, retain) NSString *username;
//@property (nonatomic, retain) NSString *password;
//@property (nonatomic, retain) NSString *token;
//
//@end

#pragma Implementation of LFUserRegisterRequest 

/**
 Class to send user registration request
 */
@interface LFUserRegisterRequest : LFRequest
{
    /**
     LFUser class is defined all the propoerty of the user
     */
    LFUser *user;
}

@property (nonatomic, retain) LFUser *user;
@end


#pragma Interface of LFWorkoutSummaryListRequest 
/**
 LFWorkoutSummaryListRequest use for send workout summary request to the web service
 */
@interface LFWorkoutSummaryListRequest : LFRequest
{
    /**
     List of equipment ID
     */
    NSArray *equipmentIdList;
    /**
     Starting index of the workout list
     */
    int startIndex;
    /**
     Number of workouts are going to retireve from server
     */
    int listsize;
    NSString *querytype;
    NSString *filterCriteria;
    NSString *sortCriteria;
    /**
     Location Home,Gym
     */
    NSString *workoutLocation;
    
    /*
     WorkoutSummaryType LFUserWorkoutList or LFPredefineWorkoutList, If user select LFPredefineWorkoutList value, no need to have values
     for other parameter of this object, default value is LFUserWorkoutList.
     */
    enum LFWorkoutTypes workoutListType;
}

@property (nonatomic, retain) NSArray *equipmentIdList;;
@property (nonatomic, retain) NSString *querytype;
@property (nonatomic, retain) NSString *filterCriteria;
@property (nonatomic, retain) NSString *sortCriteria;
@property (nonatomic, retain) NSString *workoutLocation;
@property int startIndex;
@property int listsize;
@property enum LFWorkoutTypes workoutListType;

@end

#pragma Interface of LFWorkoutDetailRequest 

/**
 LFWorkoutDetailRequest class use to request workout details and default workout detail list
 */
@interface LFWorkoutDetailRequest : LFRequest
{
    /**
     ID of the workout, this need only to get details of the particular workout
     */
    NSString *workoutId;
    /**
     EquipmentId for retrieve default workout list, this property need only to get default workout detail list which is match to the provided equipmentId
     */
    NSString *equipmentId;
    /**
     This property need only to get default workout detail list which is created after the given date
     */
    NSString *lastUpdateDate; //dd/mm/yyyy
}

@property (nonatomic, retain) NSString *workoutId;
@property (nonatomic, retain) NSString *equipmentId;
@property (nonatomic, retain) NSString *lastUpdateDate;
@end

#pragma Interface of LFWorkoutDetailRequest 
/**
 LFWorkoutResultRequest class use to send workout result data to the LFconnect server
 */
@interface LFWorkoutResultRequest : LFRequest
{
    NSString *resultFile;// file format should be XML
}

@property (nonatomic, retain) NSString *resultFile;
@end


#pragma Interface of LFProgressRequest 
/**
 LFProgressRequest class use to extract progress result of the user
 */
@interface LFProgressRequest : LFRequest
{
    /**
     Format : "I" for Imperial unit or "M" for Metric unit.
     */
    NSString *unit;
    
}

@property (nonatomic, retain) NSString *unit;
//@property (nonatomic, retain) NSString *timeZone;
@end

