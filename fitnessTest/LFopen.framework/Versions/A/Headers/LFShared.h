//
//  LFConstant.h
//  LFDeviceLib
//
//  Created by Dulip Gayan Dasanayaka on 11/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LF_INPUT_BUFFER_SIZE                 512
#define BUILD_FOR_OUTSIDE_DEVELOPER          0

#define STRING_TRUE                  @"true"
#define STRING_FALSE                 @"false"



/**
 Preferred Language code of the Virtual Trainer user. Possible values: 'en_US', 'en', 'de', 'es', 'fr', 'it', 'ja', 'nl', 'pt', 'ru', 'tr', 'zh'
 */
typedef enum LFLanguageCode
{
    LFLangCode_EN_US = 0,
    LFLangCode_EN,
    LFLangCode_DE,
    LFLangCode_ES,
    LFLangCode_FR,
    LFLangCode_IT,
    LFLangCode_JA,
    LFLangCode_NL,
    LFLangCode_PT,
    LFLangCode_RU,
    LFLangCode_TR,
    LFLangCode_ZH,
    
}LFLanguageCode;

typedef enum LFDeviceType
{
    LFDeviceType_Treadmill_Classic_Refresh               =           41,
    LFDeviceType_Bike_Classic_Refresh                    =           42,
    LFDeviceType_Crosstrainer_Classic_Refresh            =           43,
    LFDeviceType_Step_Classic_Refresh                    =           44,
    LFDeviceType_Summittrainer_Classic_Refresh           =           45,
    
    LFDeviceType_Treadmill_Led                           =            4,
    LFDeviceType_Treadmill_Lcd                           =           14,
    LFDeviceType_Treadmill_Lcd_Con                       =           18,
    LFDeviceType_Treadmill_Acheive                       =           21,
    LFDeviceType_Treadmill_Inspire                       =           22,
    LFDeviceType_Treadmill_Engage                        =           23,
    LFDeviceType_Treadmill_1_1                           =            1,
    LFDeviceType_Treadmill_Discover_Engage               =           49,
    LFDeviceType_Treadmill_Discover_Inspire              =           53,
    
    LFDeviceType_Crosstrainer_Fd_Led                     =            5,
    LFDeviceType_Crosstrainer_Rd_Led                     =            6,
    LFDeviceType_Crosstrainer_Lcd                        =           16,
    LFDeviceType_Crosstrainer_Lcd_Adj                    =           17,
    LFDeviceType_Crosstrainer_Acheive                    =           24,
    LFDeviceType_Crosstrainer_Inspire                    =           25,
    LFDeviceType_Crosstrainer_Engage                     =           26,
    LFDeviceType_Crosstrainer_1_1                        =            2,
    LFDeviceType_Crosstrainer_Discover_Engage            =           50,
    LFDeviceType_Crosstrainer_Discover_Inspire           =           54,
    
    LFDeviceType_UprightBike_Led                         =           11,
    LFDeviceType_UprightBike_Acheive                     =           27,
    LFDeviceType_UprightBike_Inspire                     =           28,
    LFDeviceType_UprightBike_Engage                      =           29,
    LFDeviceType_UprightBike_Discover_Engage             =           51,
    LFDeviceType_UprightBike_Discover_Inspire            =           55,
    LFDeviceType_Bike_1_1                                =            0,
    
    LFDeviceType_RecumbentBike_Led                       =           12,
    LFDeviceType_RecumbentBike_Acheive                   =           30,
    LFDeviceType_RecumbentBike_Inspire                   =           31,
    LFDeviceType_RecumbentBike_Engage                    =           32,
    LFDeviceType_RecumbentBike_Discover_Engage           =           52,
    LFDeviceType_RecumbentBike_Discover_Inspire          =           56,
    
    LFDeviceType_Consumer_Treadmill                      =           19,
    LFDeviceType_Consumer_Crosstrainer                   =          260,
    LFDeviceType_Consumer_Lifecycle                      =          261,
    LFDeviceType_Consumer_Treadmill_T3                   =          262,
    LFDeviceType_Consumer_Smart_Crosstrainer             =          263,
    LFDeviceType_Consumer_Smart_Lifecycle                =          264,
    LFDeviceType_Consumer_Treadmill_F3                   =          265,
    LFDeviceType_Consumer_Treadmill_T5                   =          266,
    
    LFDeviceType_Discover_FlexStrider_Engage             =          57,
    LFDeviceType_Discover_FlexStrider_Inspire            =          58,
    LFDeviceType_Discover_Achieve_FlexStrider            =          59,
    
    LFDeviceType_Discover_PowerMill_Engage               =          60,
    LFDeviceType_Discover_PowerMill_Inspire              =          61,
    LFDeviceType_Integrity_PowerMill                     =          62,
    LFDeviceType_Achieve_PowerMill                       =          63
    
}LFDeviceType;



enum CardioProgramType {
    P_NONE = 0,
    P_QUICK_START = 1,
    P_HILL = 2,
    P_RANDOM = 3,
    P_MANUAL = 4,
    P_FAT_BURN = 5,
    P_CARDIO = 6,
    P_HR_HILL = 7,
    P_HR_INTERVAL = 8,
    P_EXTREME_HR = 9,
    P_WATTS = 10,
    P_METS = 11,
    P_AEROBICS = 12,
    P_REVERSE = 13,
    P_PT1 = 14,
    P_PT2 = 15,
    P_PT3 = 16,
    P_PT4 = 17,
    P_PT5 = 18,
    P_PT6 = 19,
    P_LF_FIT_TEST = 20,
    P_GERKIN = 21,
    P_PEB = 22,
    P_ARMY = 23,
    P_NAVY = 24,
    P_AIR_FORCE = 25,
    P_MARINE = 26,
    P_AROUND_THE_WORLD = 27,
    P_KILIMANJARO = 28,
    P_INTERVAL = 29,
    P_CASCADES = 30,
    P_SPEED_TRAINING = 31,
    P_FOOT_HILLS = 32,
    P_SPORT_TRAINING = 33,
    P_SPORT_TRAINING_5K = 34,
    P_SPORT_TRAINING_10K = 35,
    P_CUSTOM1 = 36,
    P_CUSTOM2 = 37,
    P_CUSTOM3 = 38,
    P_CUSTOM4 = 39,
    P_CUSTOM5 = 40,
    P_CUSTOM6 = 41,
    P_CUSTOM7 = 42,
    P_CUSTOM8 = 43,
    P_EZ_RESISTANCE = 44,
    P_SPEED_INTERVAL = 45,
    P_NET_ID = 46,
    P_LF_FIT_TEST_NOT_TRED = 47,
    P_AIR_FORCE_NOT_TRED = 48,
    P_NETWORK_PRESETS = 49,
    P_RANDOM_PLAY = 50,
    P_INTERVAL_RUN = 51,
    P_MOUNTAIN_TREK = 52,
    P_CREATE_YOUR_OWN = 53,
    P_WFI = 54,
    P_BRITISH_ARMY = 55,
    P_AIR_FORCE_WALK = 56,
    P_CREATE_YOUR_OWN_EX = 57,
    TotalProgram = 58,
    P_3_SPEED_INTERVAL = 59
    
}CardioProgramType;



/**
 Enum for Parameters
 */

enum GoalTypes {
    
    NONE = 0,
    TIME = 1,
    DISTANCE = 2,
    CALORIES = 3,
    TIZ = 4,
    MARATHON_MODE = 5,
    DISTANCE_CLIMBED = 6,
    PACE = 10,
    INCLINE =11,
    LEVEL = 12,
    NAME=13,
    SPEED = 14,
    HEART_RATE =15,
    JOG_SPEED =16,
    RUN_SPEED =17,
    RUN_PHASE_SPEED =18,
    WALK_SPEED =19,
    ELEVATION = 20,
    WATTS = 21,
    METS=22
    
    
}GoalType;




typedef enum LFRequestType 
{
    LFAuthenticationRequestType = 1,
    LFWorkoutsListRequestType = 2,         // support for user workouts(LFUserWorkoutList) and Predefine workouts (LFPredefineWorkoutList) type
    LFWorkoutsDetailRequestType = 3,
    LFWorkoutResultRequestType = 4,
    LFUserRegisterRequestType = 5,
    LFDefaultPresetsDetailRequestType = 6, // not support
    LFFacilityRequestType = 7,             // not support
    LFGetProgressRequestType = 8,
    LFServiceAutherizarionType = 9,
    LFPredefineWorkoutRequestType = 10,    // not support
    LFValidateLicense = 11,
}LFRequestType;


enum ResponseType
{
    ResponseTypeNotUpdate = 0,
    ResponseTypeSuccees  = 1
}ResponseType;

enum LFWorkoutTypes {
    LFUserWorkoutList = 0,
    LFPredefineWorkoutList = 1,
    LFGPSReplayWorkout
}LFWorkoutTypes;


extern NSString *const  kLFVTClientIDKey;
extern NSString *const  kLFVTClientIDValue;

extern NSString *const  kLFVTClientSecretKey;
extern NSString *const  kLFVTClientSecretValue;

extern NSString *const  kLFVTUserIDKey;
extern NSString *const  kLFVTUserIDValue;

extern NSString *const  kLFVTPasswordKey;
extern NSString *const  kLFVTPasswordValue;

extern NSString *const  kLFVTMountPoint;

extern NSString *const  kLFVTServiceIdentifier;

extern NSString *const  kLFVTTokenSuccess;
extern NSString *const  kLFVTTokenRefreshed;
extern NSString *const  kLFVTTokenLost;
extern NSString *const  kLFVTTokenFailed;

extern NSString *const  kWorkoutSummaryBatchSize;

extern NSString *const  kGetWorkoutSummaryListRelativePath;
extern NSString *const  kGetWorkoutPresetFileRelativePath;
extern NSString *const  kGetResultFileRelativePath;
extern NSString *const  kGetAuthenticationRelativePath;
extern NSString *const  kGetUserRegistrationRelativePath;
extern NSString *const  kGetUserDefaultPresetsRelativePath;
extern NSString *const  kGetFacilityListRelativePath;
extern NSString *const  kGetProgressRelativePath;

extern NSString *const  kAuthraizeURL;
extern NSString *const  kTokenURL;
extern NSString *const  kBaseURL;

// HTTP ERROR CODE
extern NSString *const  kHTTPRespCodeOk;
extern NSString *const  hHTTPRespCodeNoContent;

extern NSString *const  kLFVTServiceIdentifier;


#define DEVICE_MODEL_TREADMILL              1
#define DEVICE_MODEL_CROSSTRAINER           2
#define DEVICE_MODEL_BIKE                   3
#define DEVICE_MODEL_POWER_MILL             4


@interface LFShared : NSObject
{
    
}


+ (void)logeDebugMessage:(NSString*)msg;
+ (NSURL*)getURLValue:(enum LFRequestType)requestType;
+ (NSString*)getLanguageCode:(enum LFLanguageCode)langCode;
+ (enum LFLanguageCode) getLanguageCodeType:(NSString*)langCode;
+ (NSString*) replaceDateOftheWorkoutResult:(NSString*)data;
+ (int)getDeviceModel:(enum LFDeviceType)selfDevice;
+ (NSString*)getStringForDouble:(double)value formatter:(NSString*) format;

@end

