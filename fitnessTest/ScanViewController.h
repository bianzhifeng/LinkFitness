//
//  ScanViewController.h
//  fitnessTest
//
//  Created by SapientiaWind on 17/3/21.
//  Copyright © 2017年 Social Capital Consulting Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
@protocol ScanCompletionDelegate <NSObject>

@optional

- (void)connectTocponsoleWithMacAddress:(NSString*)mac;

@end
@interface ScanViewController : UIViewController
@property(nonatomic,assign) id<ScanCompletionDelegate> delegate;
@end
