//
//  XMLReader.h
//  LFServiceLib
//
//  Created by Dulip Gayan Dasanayaka on 8/10/12.
//  Copyright (c) 2012 Life Fitness, Singapore. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LFWorkout.h"

@protocol LFXmlParseDelegate <NSObject>
-(void) didFinishedParse:(LFWorkout*) workout  xmlFile:(NSString*) xmlString;
-(void) didFailedWhileParsing:(NSError*)error workout:(LFWorkout*) workout;
@end

@interface LFXMLReader : NSObject <NSXMLParserDelegate>
{
    NSString *xmlString;
    
    NSString *elementNameVal;
    NSMutableString *element;
    
    LFWorkout *workout;
}

@property (nonatomic, retain) NSString *xmlString;
@property (nonatomic, retain) LFWorkout *workout;
@property (nonatomic, assign) id<LFXmlParseDelegate> delegate;

-(id) initWithString:(NSString*) xmlFileData  delegate:(id<LFXmlParseDelegate>) delegateVal;
-(id) initWithString:(NSString*) xmlFileData workout:(LFWorkout*)workoutObj delegate:(id<LFXmlParseDelegate>) delegateVal;

@end
