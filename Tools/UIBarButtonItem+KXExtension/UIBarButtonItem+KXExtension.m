
//
//  UIBarButtonItem+KXExtension.m
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import "UIBarButtonItem+KXExtension.h"

@implementation UIBarButtonItem (KXExtension)
//本质上是 放了一个button 到 UIBarButtonItem 里面

+ (instancetype)itemWithImage:(NSString *)img  heightImage:(NSString *)hightImg target:(id)target action:(SEL)action
{
    UIButton * button = [UIButton buttonWithType:UIButtonTypeCustom];
    [button setImage:[UIImage imageNamed:img] forState:UIControlStateNormal];
    [button setImage:[UIImage imageNamed:hightImg] forState:UIControlStateHighlighted];
    [button sizeToFit];
    [button addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    return  [[self alloc] initWithCustomView:button];
}
@end
