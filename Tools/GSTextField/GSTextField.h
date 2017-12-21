//
//  GSTextField.h
//  NormalProject
//
//  Created by apple on 2017/12/20.
//  Copyright © 2017年 GS. All rights reserved.
//
// 参考 https://github.com/chinesemanbobo/PPTextField
// 底部添加了几个 自己的方法

#import <UIKit/UIKit.h>

@interface GSTextField : UITextField

/**
  01.是否当编辑的时候显示clearButton 默认为yes
 */
@property(nonatomic,assign)BOOL isClearWhileEditing;
/**
  02.是否可以输入特殊字符 （默认YES，即可以输入）
 */
@property(nonatomic,assign)BOOL isSpecialCharacter;
/**
 03.可以输入的字符串数组 【控制不可以输入特殊字符，但是某个或者某些特殊字符又是可以输入的】
 ☠☠只有当isSpecialCharacter为NO时，有效☠☠
 */
@property(nonatomic,strong)NSArray<NSString *> *canInputCharacters;
/**
 04.不可以输入的字符串数组 【全局限制，没有前提条件】
 */
@property(nonatomic,strong)NSArray<NSString *> *canotInputCharacters;
/**
 05.是否只能输入数字,默认为NO，
 */
@property(nonatomic,assign)BOOL isOnlyNumber;
/**
 06.最多纯数字个数，比如手机11位，商品条码13位等 【
 ☠☠设置了maxNumberCount,就默认 isOnlyNumber = YES☠☠
 */
@property(nonatomic,assign)NSInteger maxNumberCount;
/**
 07.是否是手机号码
 ☠☠设置了isPhoneNumber,就默认 isOnlyNumber = YES && maxNumberCount == 11 ,此时maxTextLength和maxCharactersLength无效☠☠
 */
@property(nonatomic,assign)BOOL isPhoneNumber;

/**
 08.价格(只有一个"."，小数点后保留2位小数)
 
 ◥◤首位不能输入.◥◤
 ◥◤首位输入0，第二位不是.，会自动补充.◥◤
 
 ☠☠如果isPrice==YES,则isOnlyNumber=No,即使isOnlyNumber设置为YES也没用,此时canotInputCharacters无效☠☠
 */
@property(nonatomic,assign)BOOL isPrice;
/**
 09.价格是否允许以“.”开头，默认是不允许，如果允许，请设置为YES
 ☠☠设置了isPriceHeaderPoint,则isPrice = YES,此时canotInputCharacters无效☠☠
 */
@property(nonatomic,assign)BOOL isPriceHeaderPoint;
/**
 10.是不是密码 （默认只能字母和数字）
 */
@property(nonatomic,assign)BOOL isPassword;
/**
 11.密码可以输入的字符串数组  【只有当isPassword为YES时，有效 】
 【控制不可以输入特殊字符，但是某个或者某些特殊字符又是可以输入的】
 */
@property(nonatomic,strong)NSArray<NSString *> *canInputPasswords;
/**
 12.tf.text最大长度（不考虑中英文）
 */
@property(nonatomic,assign)NSInteger maxTextLength;
/**
 13.字符串最大长度（一个中文2个字符，一个英文1个字符【中文输入法下的都算中文】）
 */
@property(nonatomic,assign)NSInteger maxCharactersLength;



////❷❷❷❷❷❷❷❷---☮☮☮PPTextField Block回调☮☮☮---❷❷❷❷❷❷❷❷
//
///**
// 【2-001】文本框字符变动，回调block【实时监测tf的文字】
// */
//@property(nonatomic,copy)void(^gsTextfieldTextChangedBlock)(GSTextField *tf);
///**
// 【2-002】结束编辑or失去第一响应，回调block
// */
//@property(nonatomic,copy)void(^gsTextFieldEndEditBlock)(GSTextField *tf);
///**
// 【2-003】键盘右下角returnType点击
// */
//@property(nonatomic,copy)void(^gsTextFieldReturnTypeBlock)(GSTextField *tf);
//

//------------------------------------------------------
//自己添加
//21.内间距
/**
 21.内间距 （默认是10pt）
 */
@property(nonatomic,assign)NSInteger leftViewMargin;

//22.自定义 清除按钮
/**
 22.自定义 清除按钮 （默认为NO ）
 */
@property(nonatomic,assign)BOOL isCustomClearBtn;
//23.复制 粘贴
/**
 23.复制 粘贴 (默认YES)
 */
@property(nonatomic,assign)BOOL canCopyPaste;

@end
