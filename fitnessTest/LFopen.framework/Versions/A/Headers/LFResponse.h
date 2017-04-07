//
//  LFResponse.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 22/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFRequest.h"
#import "LFProgress.h"

/**
 LFResponseStatus use to define http response status
 */
enum LFResponseStatus 
{
	LFSuccessfulResponse, 
	LFSessionInvalidated,
	LFServerNotResponding,
	LFRequestTimeout,
	LFResponseError,
};

#pragma mark LFResponse

@interface LFResponse : NSObject
{
    /**
     Hold http response status
     */
    enum LFResponseStatus responseStatus;
    /**
     Hold http request type which related to current response
     */
    enum LFRequestType requestType;
    /**
     HTTP error
     */
    NSError *error;
    /**
     Hold response result set, can be list of LFWorkout list, list of strings
     */
    NSMutableArray *resultSet;
    
    /**
     Holds LF error message
     */
    NSString *errorMsg;
    
    /**
     provide HTTP status code
     */
    int httpStatusCode;
    
    /**
     provide HTTP message code
     */
    NSString *httpMessage;
    
    NSMutableDictionary *resultData;
}

@property (nonatomic, retain) NSError *error;
@property (nonatomic, retain) NSString *errorMsg;
@property enum LFResponseStatus responseStatus;
@property (nonatomic, retain) NSMutableArray *resultSet;
@property enum LFRequestType requestType;
@property int httpStatusCode;
@property (nonatomic, retain) NSString *httpMessage;
@property (nonatomic, retain) NSMutableDictionary *resultData;

-(void) addResultSet:(NSMutableArray*)result;

@end

#pragma mark AuthenticationResponse

@interface LFAuthResponse : LFResponse
{
    BOOL isAuthenticated; 
    LFUser *user;
}

@property BOOL isAuthenticated;
@property(nonatomic, retain) LFUser *user;

-(void) setUserObject:(LFUser *)usr;

@end

#pragma mark Progress response

@interface LFProgressResponse : LFResponse
{ 
    LFProgress *progress;
}

@property(nonatomic, retain) LFProgress *progress;

-(void) setProgressObject:(LFProgress *)pr;

@end
