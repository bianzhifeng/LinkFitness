//
//  LFProgress.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 3/7/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LFProgress : NSObject
{
    /*
     caloriesThisMonth (long)	1/1	 Sum of workout calories for this month. Default value is 0 (zero).
     caloriesThisWeek (long)	1/1	 Sum of workout calories for this week. Default value is 0 (zero).
     caloriesThisYear (long)	1/1	 Sum of workout calories for this year. Default value is 0 (zero).
     distanceThisMonth (long)	1/1	 Sum of workout distance for this month. Default value is 0 (zero).
     distanceThisWeek (long)	1/1	 Sum of workout distance for this week. Default value is 0 (zero).
     distanceThisYear (long)	1/1	 Sum of workout distance for this year. Default value is 0 (zero).
     durationThisMonth (long)	1/1	 Sum of workout duration for this year. Default value is 0 (zero).
     durationThisWeek (long)	1/1	 Sum of workout duration for this week. Default value is 0 (zero).
     durationThisYear (long)	1/1	 Sum of workout duration for this year. Default value is 0 (zero).
     workoutDaysThisMonth (long)	1/1	 Sum of workout days for this month. Default value is 0 (zero).
     workoutDaysThisWeek (long)	1/1	 Sum of workout days for this week. Default value is 0 (zero).
     workoutDaysThisYear (long)	1/1	 Sum of workout days for this year. Default value is 0 (zero).
     weightLiftedThisMonth (long)	1/1	 Sum of weight lifted for this year. Default value is 0 (zero).
     weightLiftedThisWeek (long)	1/1	 Sum of weight lifted for this year. Default value is 0 (zero).
     weightLiftedThisYear (long)
     */
    /**
     Sum of workout calories for this month. Default value is 0 (zero).
     */
    double caloriesThisMonth;
    /**
     Sum of workout calories for this week. Default value is 0 (zero).
     */
    double caloriesThisWeek;
    /**
     Sum of workout calories for this year. Default value is 0 (zero).
     */
    double caloriesThisYear;
    /**
     Sum of workout distance for this month. Default value is 0 (zero).
     */
    double distanceThisMonth;
    /**
     Sum of workout distance for this week. Default value is 0 (zero).
     */
    double distanceThisWeek;
    /**
     Sum of workout distance for this year. Default value is 0 (zero).
     */
    double distanceThisYear;
    /**
     Sum of workout duration for this month. Default value is 0 (zero).
     */
    double durationThisMonth;
    /**
     Sum of workout duration for this week. Default value is 0 (zero).
     */
    double durationThisWeek;
    /**
     Sum of workout duration for this year. Default value is 0 (zero).
     */
    double durationThisYear;
    /**
     Sum of weight lifted for this month. Default value is 0 (zero).
     */
    double weightLiftedThisMonth;
    /**
     Sum of weight lifted for this week. Default value is 0 (zero).
     */
    double weightLiftedThisWeek;
    /**
     Sum of weight lifted for this year. Default value is 0 (zero).
     */
    double weightLiftedThisYear;
    /**
     Sum of workout days for this month. Default value is 0 (zero).
     */
    double workoutDaysThisMonth;
    /**
     Sum of workout days for this week. Default value is 0 (zero).
     */
    double workoutDaysThisWeek;
    /**
     Sum of workout days for this year. Default value is 0 (zero).
     */
    double workoutDaysThisYear;

}

@property double caloriesThisMonth;
@property double caloriesThisWeek;
@property double caloriesThisYear;
@property double distanceThisMonth;
@property double distanceThisWeek;
@property double distanceThisYear;
@property double durationThisMonth;
@property double durationThisWeek;
@property double durationThisYear;
@property double weightLiftedThisMonth;
@property double weightLiftedThisWeek;
@property double weightLiftedThisYear;
@property double workoutDaysThisMonth;
@property double workoutDaysThisWeek;
@property double workoutDaysThisYear;

@end
