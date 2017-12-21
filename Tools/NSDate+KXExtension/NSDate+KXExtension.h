//
//  NSDate+KXExtension.h
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface KXDateItem : NSObject
@property (nonatomic, assign) NSInteger day;
@property (nonatomic, assign) NSInteger hour;
@property (nonatomic, assign) NSInteger minute;
@property (nonatomic, assign) NSInteger second;

@end

@interface NSDate (KXExtension)

- (KXDateItem *)KX_timeIntervalSinceDate:(NSDate *)anotherDate;



- (BOOL)KX_isToday;
- (BOOL)KX_isYesterday;
- (BOOL)KX_isTomorrow;
- (BOOL)KX_isThisYear;

/** 今天周几*/
-(NSInteger)getNowWeekday;
@end
