//
//  NSDate+KXExtension.m
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import "NSDate+KXExtension.h"


@implementation KXDateItem
- (NSString *)description
{
    return [NSString stringWithFormat:@"%zd天%zd小时%zd分%zd秒", self.day, self.hour, self.minute, self.second];
}
@end

@implementation NSDate (KXExtension)
- (KXDateItem *)KX_timeIntervalSinceDate:(NSDate *)anotherDate
{
    
     KXDateItem * item = [[KXDateItem alloc] init];
    
    //1.interVal:间隔  createdAtDate和nowDate之间的时间间隔
    NSTimeInterval interVal = [self timeIntervalSinceDate:anotherDate];
    
    //2.相差多少天
    int intInterval = (int)interVal;
    int secondsPerDay = 24*3600;
    item.day = intInterval / secondsPerDay;
    
    //3.相差多少小时
    int secondsPerHour = 3600;
    item.hour = (intInterval % secondsPerDay)/secondsPerHour;
    
    //4.相差多少分钟
    int secondsPerMinute = 60;
    item.minute = ((intInterval % secondsPerDay) % secondsPerHour) / secondsPerMinute;
    
    //5.相差多少秒
    item.second = ((intInterval % secondsPerDay) % secondsPerHour) % secondsPerMinute;
    
    return item;
}


- (BOOL)KX_isToday
{
    //1.日历
    NSCalendar * calendar = [NSCalendar currentCalendar];
    
    //2.日历的单元
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay;
   
    //3. 一个封装了具体年月日、时秒分、周、季度等的类 components（组件）
    NSDateComponents * selfCmps = [calendar components:unit fromDate:self];
    NSDateComponents * nowCmps = [calendar components:unit fromDate:[NSDate date]];
    // 如果selfCmps和nowCmps的所有元素都一样，就返回YES，否则返回NO
    return [selfCmps isEqual:nowCmps];
    //    return selfCmps.year == nowCmps.year
    //    && selfCmps.month == nowCmps.month
    //    && selfCmps.day == nowCmps.day;

    
}

- (BOOL)KX_isYesterday
{
    // 判断self这个日期对象是否为昨天
    
    // self 2015-12-09 22:10:01 -> 2015-12-09 00:00:00
    // now  2015-12-10 12:10:01 -> 2015-12-01 00:00:00
    // 昨天：0year 0month 1day 0hour 0minute 0second
    
    
    // NSDate * -> NSString * -> NSDate *
    //1.格式化 日期
    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    fmt.dateFormat = @"yyyyMMdd";
    
    //2.生成只有年月日的字符串对象
    NSString *selfString = [fmt stringFromDate:self];
    NSString *nowString = [fmt stringFromDate:[NSDate date]];
    
    //3.生成只有年月日的日期对象
    NSDate *selfDate = [fmt dateFromString:selfString];
    NSDate *nowDate = [fmt dateFromString:nowString];
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay;
    //4.根据指定NSCalendarUnit参数，比较两个NSDate之间的差异
    NSDateComponents *cmps = [calendar components:unit fromDate:selfDate toDate:nowDate options:NSCalendarWrapComponents];
    return cmps.year == 0
    && cmps.month == 0
    && cmps.day == 1;
}

- (BOOL)KX_isTomorrow
{
    //1.格式化日期
    NSDateFormatter *fmt = [[NSDateFormatter alloc] init];
    fmt.dateFormat = @"yyyyMMdd";
    
    //2.生成只有年月日的字符串对象
    NSString *selfString = [fmt stringFromDate:self];
    NSString *nowString = [fmt stringFromDate:[NSDate date]];
    
    //3.生成只有年月日的日期对象
    NSDate *selfDate = [fmt dateFromString:selfString];
    NSDate *nowDate = [fmt dateFromString:nowString];
    
    NSCalendar *calendar = [NSCalendar currentCalendar];
    NSCalendarUnit unit = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay;
   //4.根据指定NSCalendarUnit参数，比较两个NSDate之间的差异
    NSDateComponents *cmps = [calendar components:unit fromDate:selfDate toDate:nowDate options:NSCalendarWrapComponents];
    return cmps.year == 0
    && cmps.month == 0
    && cmps.day == -1;
}

- (BOOL)KX_isThisYear
{
    //1.判断self这个日期对象是否为今年
    NSCalendar *calendar = [NSCalendar currentCalendar];
    
    NSInteger selfYear = [calendar components:NSCalendarUnitYear fromDate:self].year;
    NSInteger nowYear = [calendar components:NSCalendarUnitYear fromDate:[NSDate date]].year;
    
    return selfYear == nowYear;
}

//获取今天周几
- (NSInteger)getNowWeekday {
    //1.
    NSCalendar *calendar = [[NSCalendar alloc] initWithCalendarIdentifier:NSCalendarIdentifierGregorian];
    
    //2.一个封装了具体年月日、时秒分、周、季度等的类 components（组件）
    NSDateComponents *comps = [[NSDateComponents alloc] init];
    NSInteger unitFlags = NSCalendarUnitYear | NSCalendarUnitMonth | NSCalendarUnitDay | NSCalendarUnitWeekday |
    NSCalendarUnitHour | NSCalendarUnitMinute | NSCalendarUnitSecond;
    NSDate *now = [NSDate date];
    //3.真机上需要设置区域，才能正确获取本地日期，天朝代码:zh_CN
    calendar.locale = [[NSLocale alloc] initWithLocaleIdentifier:@"zh_CN"];
    comps = [calendar components:unitFlags fromDate:now];
    return [comps day];
}
@end
