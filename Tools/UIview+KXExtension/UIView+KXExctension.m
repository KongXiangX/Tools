//
//  UIView+KXExctension.m
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import "UIView+KXExctension.h"

@implementation UIView (KXExctension)

/** 判断self和view是否重叠 */
-(BOOL)KX_intersectsWithView:(UIView *)view
{
    CGRect selfRect = [self convertRect:self.bounds  toView:nil];
    CGRect viewRect = [view convertRect:view.bounds toView:nil];
    return  CGRectIntersectsRect(selfRect, viewRect);
}

-(void)setKX_size:(CGSize)KX_size
{
    CGRect frame = self.frame;
    frame.size = KX_size;
    self.frame = frame;
}
- (CGSize)KX_size
{
   return  self.frame.size;
}

- (void)setKX_x:(CGFloat)KX_x
{
    CGRect frame = self.frame;
    frame.origin.x = KX_x;
    self.frame = frame;
}


- (void)setKX_y:(CGFloat)KX_y{
    CGRect frame = self.frame;
    frame.origin.y = KX_y;
    self.frame = frame;
}

- (void)setKX_width:(CGFloat)KX_width
{
    CGRect frame = self.frame;
    frame.size.width = KX_width;
    self.frame = frame;
}

- (void)setKX_height:(CGFloat)KX_height
{
    CGRect frame = self.frame;
    frame.size.height = KX_height;
    self.frame = frame;
}

- (CGFloat)KX_x
{
    return self.frame.origin.x;
}

- (CGFloat)KX_y
{
    return self.frame.origin.y;
}

- (CGFloat)KX_width
{
    return self.frame.size.width;
}

- (CGFloat)KX_height
{
    return self.frame.size.height;
}

- (void)setKX_centerX:(CGFloat)KX_centerX
{
    CGPoint center = self.center;
    center.x = KX_centerX;
    self.center = center;
}

- (void)setKX_centerY:(CGFloat)KX_centerY
{
    CGPoint center = self.center;
    center.y = KX_centerY;
    self.center = center;
}

- (CGFloat)KX_centerX
{
    return self.center.x;
}

- (CGFloat)KX_centerY
{
    return self.center.y;
}




@end
