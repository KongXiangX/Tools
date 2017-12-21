//
//  NSString+GSTextField.m
//  NormalProject
//
//  Created by aGSle on 2017/12/21.
//  Copyright © 2017年 GS. All rights reserved.
//

#import "NSString+GSTextField.h"

@implementation NSString (GSTextField)
-(BOOL)GS_is:(GSTextFieldStringType)stringType
{
    return [self matchRegularWith:stringType];
}
-(BOOL)GS_isSpecialLetter
{
    if ([self GS_is:GSTextFieldStringTypeNumber] || [self GS_is:GSTextFieldStringTypeLetter] || [self GS_is:GSTextFieldStringTypeChinese]) {
        return NO;
    }
    return YES;
}
#pragma mark --- 用正则判断条件
-(BOOL)matchRegularWith:(GSTextFieldStringType)type
{
    NSString *regularStr = @"";
    switch (type) {
        case GSTextFieldStringTypeNumber:      //数字
            regularStr = @"^[0-9]*$";
            break;
        case GSTextFieldStringTypeLetter:      //字母
            regularStr = @"^[A-Za-z]+$";
            break;
        case GSTextFieldStringTypeChinese:     //汉字
            regularStr = @"^[\u4e00-\u9fa5]{0,}$";
            break;
        default:
            break;
    }
    NSPredicate *regextestA = [NSPredicate predicateWithFormat:@"SELF MATCHES %@", regularStr];
    
    if ([regextestA evaluateWithObject:self] == YES){
        return YES;
    }
    return NO;
}
-(int)GS_getStrLengthWithCh2En1
{
    int strLength = 0;
    char* p = (char*)[self cStringUsingEncoding:NSUnicodeStringEncoding];
    for (int i=0 ; i<[self lengthOfBytesUsingEncoding:NSUnicodeStringEncoding] ;i++) {
        if (*p) {
            p++;
            strLength++;
        }else {
            p++;
        }
    }
    return strLength;
}

-(NSString *)GS_removeSpecialLettersExceptLetters:(NSArray<NSString *> *)exceptLetters
{
    if (self.length > 0) {
        NSMutableString *resultStr = [[NSMutableString alloc]init];
        for (int i = 0; i<self.length; i++) {
            NSString *indexStr = [self substringWithRange:NSMakeRange(i, 1)];
            
            if (![indexStr GS_isSpecialLetter] || (exceptLetters && [exceptLetters containsObject:indexStr])) {
                [resultStr appendString:indexStr];
            }
        }
        if (resultStr.length > 0) {
            return resultStr;
        }else{
            return @"";
        }
    }else{
        return @"";
    }
}
@end
