//
//  UIBarButtonItem+KXExtension.h
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIBarButtonItem (KXExtension)
/**
 *  @brief    一个带有图片的且有事件响应的UIBarButtonItem
 *  @param img      默认图片名字（normal）
 *  @param hightImg 高亮图片名字（heighted）
 *  @param target   目标
 *  @param action   事件
 *  @return 实例化UIBarButtonItem
 */
+ (instancetype)itemWithImage:(NSString *)img heightImage:(NSString *)hightImg target:(id)target action:(SEL)action;
@end
