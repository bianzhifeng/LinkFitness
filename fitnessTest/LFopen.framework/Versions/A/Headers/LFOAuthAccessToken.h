//
//  LFOAuthAccessToken.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 14/9/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface LFOAuthAccessToken : NSObject<NSCoding>
{
    NSString *accessToken;;
    NSString *refreshToken;
    NSDate *expiresAt;
    
    NSDictionary *dicTokenData;
}

@property (nonatomic, retain) NSString *accessToken;
@property (nonatomic, retain) NSString *refreshToken;
@property (nonatomic, retain) NSDate *expiresAt;


- (NSString *)description;
- (BOOL)hasExpired;
- (id)initWithAuthorizResponse:(NSDictionary *)data;

@end
