//
//  LFFacilite.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 29/6/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LFFacility : NSObject
{
    long facilityId;
    NSString *locationName;
    NSString *address;
    NSString *branchName;
    NSString *state;
    NSString *city;
    NSString *country;
}

@property long facilityId;
@property (nonatomic, retain) NSString *locationName;
@property (nonatomic, retain) NSString *address;
@property (nonatomic, retain) NSString *branchName;
@property (nonatomic, retain) NSString *state;
@property (nonatomic, retain) NSString *city;
@property (nonatomic, retain) NSString *country;

@end
