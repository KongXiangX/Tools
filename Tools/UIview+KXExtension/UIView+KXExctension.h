//
//  UIView+KXExctension.h
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (KXExctension)
/**
 *  快速设置控件的位置
 */
@property (nonatomic, assign) CGSize KX_size;
@property (nonatomic, assign) CGFloat KX_x;
@property (nonatomic, assign) CGFloat KX_y;
@property (nonatomic, assign) CGFloat KX_width;
@property (nonatomic, assign) CGFloat KX_height;


@property (nonatomic, assign) CGFloat KX_centerX;
@property (nonatomic, assign) CGFloat KX_centerY;

/** 判断self和view是否重叠 */
- (BOOL)KX_intersectsWithView:(UIView *)view;

@end
