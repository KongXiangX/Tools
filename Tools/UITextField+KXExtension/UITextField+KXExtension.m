
//
//  UITextField+KXExtension.m
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import "UITextField+KXExtension.h"

@implementation UITextField (KXExtension)
/** 通过这个属性名，就可以修改textField内部的占位文字颜色 */
static NSString * const KXPlaceholderColorKeyPath = @"placeholderLabel.textColor";

/**
 *  设置占位文字颜色
 */
-(void)setPlaceHolderColor:(UIColor *)placeHolderColor
{
    // 这3行代码的作用：1> 保证创建出placeholderLabel，2> 保留曾经设置过的占位文字
    NSString *placeholder = self.placeholder;
    self.placeholder = @" ";
    self.placeholder = placeholder;
    
    // 处理xmg_placeholderColor为nil的情况：如果是nil，恢复成默认的占位文字颜色
    if (placeHolderColor == nil) {
        placeHolderColor = [UIColor colorWithRed:0 green:0 blue:0.0980392 alpha:0.22];
    }
    
    // 设置占位文字颜色
    [self setValue:placeHolderColor forKeyPath:KXPlaceholderColorKeyPath];
}


/**
 *  获得占位文字颜色
 */
- (UIColor *)placeHolderColor
{
    return [self valueForKeyPath:KXPlaceholderColorKeyPath];
}
@end
