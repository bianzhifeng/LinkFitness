//
//  LFAuthRequest.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 13/9/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LFRequest.h"

@interface LFAuthRequest : LFRequest
{
    NSString *clientId;
    NSString *clientSecret;
    UIWebView *redirectWebView;
    UIViewController *rootViewDelegate;
    
    /**
     username for hold user name of the authentication function
     */
    NSString *username;
    /**
     password for hold password of the authentication function
     */
    NSString *password;
    /**
     token 
     */
    NSString *token;
}

@property (nonatomic, retain) NSString *clientId;
@property (nonatomic, retain) NSString *clientSecret;
@property (nonatomic, retain) UIWebView *redirectWebView; 
@property (nonatomic, retain) UIViewController *rootViewDelegate;
@property (nonatomic, retain) NSString *username;
@property (nonatomic, retain) NSString *password;
@property (nonatomic, retain) NSString *token;
@end
