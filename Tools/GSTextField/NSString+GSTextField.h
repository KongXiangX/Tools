//
//  NSString+GSTextField.h
//  NormalProject
//
//  Created by aGSle on 2017/12/21.
//  Copyright © 2017年 GS. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef NS_ENUM(NSInteger,GSTextFieldStringType) {
    GSTextFieldStringTypeNumber,         //数字
    GSTextFieldStringTypeLetter,         //字母
    GSTextFieldStringTypeChinese         //汉字
};

@interface NSString (GSTextField)

/**
 某个字符串是不是数字、字母、汉字。
 */
-(BOOL)GS_is:(GSTextFieldStringType)stringType;


/**
 字符串是不是特殊字符，此时的特殊字符就是：出数字、字母、汉字以外的。
 */
-(BOOL)GS_isSpecialLetter;

/**
 获取字符串长度 【一个汉字算2个字符串，一个英文算1个字符串】
 */
-(int)GS_getStrLengthWithCh2En1;


/**
 移除字符串中除exceptLetters外的所有特殊字符
 */
-(NSString *)GS_removeSpecialLettersExceptLetters:(NSArray<NSString *> *)exceptLetters;

@end
