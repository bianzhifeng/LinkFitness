//
//  LFUser.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 28/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFShared.h"

/**
 User's prefered unit used in the workouts, etc. Possible values: I - Imperial M - Metric
 */
#define UNIT_IMPERIAL            @"I"  
#define UNIT_METRIC              @"M"

/**
 Gender of the Virtual Trainer User. Possible values: m - Male f - Female
 */
#define GENDER_MAIL               @"m"
#define GENDER_FEMAIL             @"f"

@interface LFUser : NSObject
{
    NSString *receiveMessages;
    long userId;
    short age; 
    BOOL isRequireEmailNotification;
    NSString *firstName;
    NSString *lastName;
    long locationId; 
    NSString *nickName;
    NSString *password;
    enum LFLanguageCode preferredLanguageCode;
    BOOL isShareName; 
    BOOL isShareProfile;
    BOOL isShareProgram;
    BOOL isShareProgress;
    NSString *gender; // f,m
    NSString *emailAddress;
    double height; 
    NSString *heightUnit; //I,M
    double weight;//I,M
    NSString *weightUnit; 
    NSString *preferredUnit;//I,M
    bool  termsAndPolicyAgreement;
    bool hasFbSharing; 
}

@property (nonatomic, retain) NSString *receiveMessages;
@property long userId;
@property short age; 
@property BOOL isRequireEmailNotification;
@property (nonatomic, retain) NSString *firstName;
@property (nonatomic, retain) NSString *lastName;
@property long locationId; 
@property (nonatomic, retain) NSString *nickName;
@property (nonatomic, retain) NSString *password;
@property enum LFLanguageCode preferredLanguageCode;
@property BOOL isShareName; 
@property BOOL isShareProfile;
@property BOOL isShareProgram;
@property BOOL isShareProgress;
@property (nonatomic, retain) NSString *gender; // f,m
@property (nonatomic, retain) NSString *emailAddress;
@property double height; 
@property (nonatomic, retain) NSString *heightUnit; //I,M
@property double weight;//I,M
@property (nonatomic, retain) NSString *weightUnit; 
@property (nonatomic, retain) NSString *preferredUnit;//I,M
@property bool  termsAndPolicyAgreement;
@property bool hasFbSharing; 


@end
