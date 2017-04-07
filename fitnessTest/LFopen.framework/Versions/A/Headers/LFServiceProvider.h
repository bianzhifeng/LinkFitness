//
//  LFServiceLib.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "LFResponse.h"
#import "LFOAuthAccessToken.h"
#import "LFAuthRequest.h"
#import "LFXMLReader.h"
#import "LFWorkoutStream.h"
#import "LFWorkoutEntity.h"


/**
 LFServiceProvider.h
 The DeviceCommunicationDelegate provides a functional interface to the LFServiceLib.
 Use the functions declared here to send, retireve data from LifeFitness Apllo Console.


 @updated 27-06-2012
 @version 1.0
 @copyright Life Fitness
 @author Dulip
 */

@protocol DeviceCommunicationDelegate <NSObject>

@required
/**
 Inform that the LifeFitness Device are successfully connected.
 */
-(void) didDeviceConnect;

/**
 Inform that the LifeFitness Device are  disconnected.
 */
-(void) didDeviceDisconnect;


/**
 This delegate get fire when LFopen fail to validate the license
 */
@optional
- (void)didFailWithError:(NSError*)error;


/**
 Received version number of Life Fitness console.
 
 @param consoleVersion Console version number as string value ex: "1.50"
 */

@optional
-(void) didReceivedConsoleVersion:(NSString*)consoleVersion;


/**
 Received max packet size use for communicate between mobile and equipment.
 
 @param int maxpacketSize
 */
@optional
-(void)didReceivedMaxPacketSize:(int)maxpacketSize;

/**
 API ask number of preset (workouts) that match with device type which is going to disply on the console.
 */
-(int)numberOfPresetsToShow:(enum LFDeviceType)deviceTypeValue;

/**
 Retrive Array of presets(workout) names that list on the console.
 
 @param fromIndex Starting preset index
 @param toIndex The number of workout names
 */
-(NSArray*)presetListToShowFrom:(NSInteger)fromIndex toIndex:(NSInteger)toIndex;

/**
 Console wating for the preset file data. If this delegate fires you can use "-(void) sendPresetDataToConsole:(LFWorkout*) workout" method to
 send preset file data to consol
 
 @param Index Preset index number
 */

@optional
-(void) didConsoleWaitingPresetFileDataFor:(NSInteger)index;

/**
 Retrive Name of the music file related to particular preset.
 
 @param index Preset index number
 @result Provide Play list file name as NSstring
 */
@optional
-(NSString*) playListNameForIndex:(NSInteger)index;

/**
 API ask the iOS application version number.
 
 @result Version number version number as NSstring
 */
@optional
-(NSString*) applicationVersionNumber;

/**
 Received the workout result file name after user finished the workout with 
 Life Fitness equipment
 
 @result Result file name as NSString
 */
@optional
-(void) didReceivedResultFileName:(NSString*)fileName;

/**
 @discussion Received the workout result file data as XML string after user finished the workout with 
 Life Fitness equipment
 
 @result Result file data as NSString
 */
@optional
-(void)didReceivedResultData:(LFWorkout*)workout;


/**
 @discussion Get LF user information as XML file, console use this data for communicate with Life fitness server
 Life Fitness equipment
 
 @result User Info
 */
@optional
- (NSString*)returnUserInfoXML;

/**
 @discussion Get LF user settings for console as XML file
 Life Fitness equipment
 
 @result User Info
 */
@optional
- (NSString*)returnUserSettingsXML;

@optional
- (void)didReceivedResultXML:(NSString*)workout;

/**
 @discussion Received the current state the workout stream data as LFStreamData object
 Life Fitness equipment
 
 @result Result file data as NSString
 */
@optional
-(void) didReceivedWorkoutStream:(LFWorkoutStream*)streamData;

/**
 Retrive Preset file data to execute workout on the console.
 
 @param Index Preset index number
 @result Provide preset file data as NSString value
 */
-(LFWorkout*) presetDataForIndex:(NSInteger)index;



// Catch response value that send by the Console

/*
 * In response to setIncline method, LFopen provide this output method
 * ResponseTypeSuccess = 1,  ResponseTypeNotUpdate = 0,
 */
@optional
- (void)didReceivedInclineResponse:(enum ResponseType)resType message:(NSString*)responseMessage;


/*
 * In response to setWatts method, LFopen provide this output method
 * ResponseTypeSuccess = 1,  ResponseTypeNotUpdate = 0,
 */
@optional
- (void)didReceivedWattsResponse:(enum ResponseType)resType message:(NSString*)responseMessage;;


/*
 * In response to setHartRate method, LFopen provide this output method
 * ResponseTypeSuccess = 1,  ResponseTypeNotUpdate = 0,
 */
@optional
- (void)didReceivedHeartRateResponse:(enum ResponseType)resType message:(NSString*)responseMessage;;


/*
 * In response to setConsoleMessage method, LFopen provide this output method
 * ResponseTypeSuccess = 1,  ResponseTypeNotUpdate = 0,
 */
@optional
- (void)didReceivedConsoleMessageResponse:(enum ResponseType)resType;


/*
 * In response to setWorkoutLevel method, LFopen provide this output method
 * ResponseTypeSuccess = 1,  ResponseTypeNotUpdate = 0,
 */
@optional
- (void)didReceivedWorkoutLevelResponse:(enum ResponseType)resType message:(NSString*)responseMessage;;



/*
 * In response to getConsoleMaxTime method, LFopen provide this output method
 * maxConsoleTime in minutes
 */
@optional
- (void)didReceivedMaxConsoleTime:(int)maxConsoleTime;

/*
 * In response to getConsoleMaxIncline method, LFopen provide this output method
 * maxConsoleIncline (0.0 - 15.0)
 */
@optional
- (void)didReceivedMaxConsoleIncline:(double)maxConsoleIncline;


@optional
- (void)didErrorOccuredWithBLEconnection:(NSError*)error;



/*
 * BLE communication method
 * dataObject can be nil, do not use these service since those do not available in LF equipment side
 */
@optional
- (void)didIdentifyLFEquipmentNearby:(NSObject*)dataObject;
- (BOOL)didConsoleHaveInternetConnection:(BOOL)hasConnection macAddres:(NSString*)strMac;
- (void)strengthWithRSSIValue:(double)rssi;
@end



/**
 LFServiceProvider.h
 The WebServiceDelegate provides a functional interface between LFServiceLib and the application that use LFServiceLib for communicate with LFconnect web service.
 Use the functions declared here to send, retireve data from LifeFitness LFconnect Web portal.
 
 @flag LFServiceLib
 @updated 27-06-2012
 @version 1.0
 @copyright Life Fitness
 @author Dulip
 */

@protocol WebServiceDelegate <NSObject>

/**
 Received LFResponse object as response to request for the Life Fitness Web Service request
 
 @result LFResponse with wraping all the result informations
 */
@required
-(void) didReceivedResponseWith:(LFResponse*)response;
-(void) didReceivedLFAuthorizationToken:(LFOAuthAccessToken*)token;

@optional
-(void) didReceivedLFDeveloperLicenseStatus:(NSString*)token;

@end


/**
 Class to communicate between LFServiceLib API and the program which use LFDeviceLib.  
 */
@interface LFServiceProvider : NSObject <LFXmlParseDelegate>
{
    @private
    /**
      Keep instance of WebServiceDelegate
      Once web service give feedback to the API , use this object to transfer data to client wh use the API.
     */

    BOOL didProvideValidLicense;
    NSString *strDevLicense;
}

@property (nonatomic, assign) id<WebServiceDelegate> webDelegate;



/**
 Provide single instance of the LFServiceProvider
 
 @result instence of LFServiceProvider
 */
+(LFServiceProvider*) getInstance;
- (void)clear;

/**
 User program must register for device service if they willing to communicate with Life Fitness Apllo console
 
 @param Object that confirms to DeviceCommunicationDelegate
 */
-(void) registerForDeviceService:(id<DeviceCommunicationDelegate>)deviceServiceListener   simulation:(BOOL)simulation;

/**
 @discussion User program must register for the web service output using this method
 
 @param Object that confirms to WebServiceDelegate
 */
-(void) registerForWebService:(id<WebServiceDelegate>) webServiceListenerDelegate;

/**
 @discussion Send request to the Life Fitness Web portal with appopriate LFRequest object 
 @param LFRequest object
 */
-(void) requestDataFromWebService:(LFRequest*)request;

/**
 @discussion Execute OAuth2 authorization process for LifeFitness web server
 @param LFAuthRequest object
 */
-(void) authorizeLFWebService:(LFAuthRequest*)request;

/**
 @discussion Refresh OAuth2 LifeFitness token to access lf web server
 @param LFAuthRequest object
 */
-(void) refreshLFAccessToken:(LFAuthRequest*)request   token:(LFOAuthAccessToken*)token;

/**
 Set Life Fitness developer licence 
 @param  strLicence  : Liecense string that provide from LFopen developer web site
 @prram  accessToken : OAuth2 accesstoken
 */
-(void) setLicence:(NSString*)strLicence;


#pragma  --
#pragma Send workout parameter to equipment

/*
 * Set incline of the equipment, send incline value as double to the console.
 * The valid incline rage is 0.0 – 15.0 percent,  accept only up to 1 decimal point
 */
- (void)setIncline:(double)inclineVal;

/*
 * Set Watts value of the equipment, send Watts value as double to the console.
 * Only accept up to 1 decimal point
 */
- (void)setWatts:(int)wattsValue;


/*
 * Set Target hart rate of the specific workout, send hart rate value as int to the console.
 */
- (void)setWorkoutTargetHeartRate:(int)targetHeartrateVal;


/*
 * Send message to display on console.
 */
- (void)setConsoleMessage:(NSString*)consoleMessage;


/*
 * Set workout level
 */
- (void)setWorkoutLevel:(int)level;


/*
 * Send Preset Data To Console
 */
- (void)sendPresetDataToConsole:(LFWorkout*) workout;



- (void)sendUserinfo:(NSString*)userXMLstring;

/*
 * Get max console time
 */
- (void)getConsoleMaxTime;


/*
 * Get max console incline
 */
- (void)getConsoleMaxIncline;

/*
 * Start Scan for LF equipment
 */
- (void)startBLEScanForLFEquipment;


/*
 * Stop Scan For LF equipment
 */
- (void)stopScanForLFEquipment;


/*
 * Connect with BLE
 */- (void)connectToConsolewithBLEusingMacAddress:(NSString*)macAddress;


@end
