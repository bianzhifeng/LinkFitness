
//  NSString+base.m
//  fitnessTest
//
//  Created by SapientiaWind on 17/3/29.
//  Copyright © 2017年 Social Capital Consulting Limited. All rights reserved.
//

#import "NSString+base.h"
#define    LocalStr_None          @""
static const char encodingTable[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
@implementation NSString (base)
+ (NSString *)textFromBase64String:(NSString *)base64

{
    
    if (base64 && ![base64 isEqualToString:LocalStr_None]) {
        
        //取项目的bundleIdentifier作为KEY  改动了此处
        
        //NSString *key = [[NSBundle mainBundle] bundleIdentifier];
        
        NSData *data = [self dataWithBase64EncodedString:base64];
        
        //IOS 自带DES解密 Begin    改动了此处
        
        //data = [self DESDecrypt:data WithKey:key];
        
        //IOS 自带DES加密 End
        
        return [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        
    }
    
    else {
        
        return LocalStr_None;
        
    }
    
}

- (NSString *)base64DecodedString
{
    NSData *data = [[NSData alloc]initWithBase64EncodedString:self options:0];
    
    return [[NSString alloc]initWithData:data encoding:NSUTF8StringEncoding];
}

- (NSString *)base64EncodedString;
{
    NSData *data = [self dataUsingEncoding:NSUTF8StringEncoding];
    return [data base64EncodedStringWithOptions:0];
}


+ (NSData *)dataWithBase64EncodedString:(NSString *)string

{
    
    if (string == nil)
        
        [NSException raise:NSInvalidArgumentException format:NULL];
    
    if ([string length] == 0)
        
        return [NSData data];
    
    static char *decodingTable = NULL;
    
    if (decodingTable == NULL)
        
    {
        
        decodingTable = malloc(256);
        
        if (decodingTable == NULL)
            
            return nil;
        
        memset(decodingTable, CHAR_MAX, 256);
        
        NSUInteger i;
        
        for (i = 0; i < 64; i++)
            
            decodingTable[(short)encodingTable[i]] = i;
        
    }
    
    const char *characters = [string cStringUsingEncoding:NSASCIIStringEncoding];
    
    if (characters == NULL)    //  Not an ASCII string!
        
        return nil;
    
    char *bytes = malloc((([string length] + 3) / 4) * 3);
    
    if (bytes == NULL)
        
        return nil;
    
    NSUInteger length = 0;
    
    NSUInteger i = 0;
    
    while (YES)
        
    {
        
        char buffer[4];
        
        short bufferLength;
        
        for (bufferLength = 0; bufferLength < 4; i++)
            
        {
            
            if (characters[i] == '\0')
                
                break;
            
            if (isspace(characters[i]) || characters[i] == '=')
                
                continue;
            
            buffer[bufferLength] = decodingTable[(short)characters[i]];
            
            if (buffer[bufferLength++] == CHAR_MAX)      //  Illegal character!
                
            {
                
                free(bytes);
                
                return nil;
                
            }
            
        }
        
        if (bufferLength == 0)
            
            break;
        
        if (bufferLength == 1)      //  At least two characters are needed to produce one byte!
            
        {
            
            free(bytes);
            
            return nil;
            
        }
        
        //  Decode the characters in the buffer to bytes.
        
        bytes[length++] = (buffer[0] << 2) | (buffer[1] >> 4);
        
        if (bufferLength > 2)
            
            bytes[length++] = (buffer[1] << 4) | (buffer[2] >> 2);
        
        if (bufferLength > 3)
            
            bytes[length++] = (buffer[2] << 6) | buffer[3];
        
    }
    
    bytes = realloc(bytes, length);
    
    return [NSData dataWithBytesNoCopy:bytes length:length];
    
}
@end
