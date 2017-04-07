//
//  LFGPSLocation.h
//  GPSReplay
//
//  Created by Dulip Gayan Dasanayaka on 18/2/14.
//  Copyright (c) 2014 Life Fitness. All rights reserved.
//

//xx

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MapKit/MapKit.h>

@interface LFGPSLocation : NSObject <MKAnnotation>
{
   // CLLocation * location;
    CLLocationCoordinate2D coordinate;
    CLLocationDistance altitude;
    NSDate* timestamp;
}

@property (nonatomic, assign) CLLocationCoordinate2D coordinate;
//@property (nonatomic, assign) CLLocation * location;
@property CLLocationDistance altitude;
@property (nonatomic, retain) NSDate* timestamp;

- (id)initWith:(CLLocationCoordinate2D)codinate altitude:(CLLocationDistance)alti time:(NSDate*)date;

@end
