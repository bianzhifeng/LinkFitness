//
//  NSString+base.h
//  fitnessTest
//
//  Created by SapientiaWind on 17/3/29.
//  Copyright © 2017年 Social Capital Consulting Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (base)
+ (NSString *)textFromBase64String:(NSString *)base64;
- (NSString *)base64DecodedString;
- (NSString *)base64EncodedString;
@end
