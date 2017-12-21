//
//  ViewController.m
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import "ViewController.h"
#import "UIView+KXExctension.h"
#import "NSDate+KXExtension.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    //1. uiview
    UIView * view = [[UIView alloc] init];
    view.frame = CGRectMake(10, 20, 30, 40);
    view.backgroundColor = [UIColor redColor];
    [self.view addSubview:view];
    
    NSLog(@"X----%lf,Y----%lf,width----%lf,Height----%lf",view.KX_x,view.KX_y,view.KX_width,view.KX_height);
    
    

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
