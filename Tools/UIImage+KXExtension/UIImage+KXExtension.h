//
//  UIImage+KXExtension.h
//  Tools
//
//  Created by apple on 17/3/15.
//  Copyright © 2017年 KXX. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (KXExtension)
#pragma mark - 图像拉伸
/*!
 按照图片的中心点拉伸图片
 @result 拉伸后的图片
 */
- (UIImage *)stretchableImageWithCenter;

#pragma mark - 图像创建
/**
 创建一个 1x1 大小的纯色图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color;

/**
 创建一张纯色图片
 */
+ (UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/**
 用QuartZ画出一个图片
 */
+ (UIImage *)imageWithSize:(CGSize)size drawBlock:(void (^)(CGContextRef context))drawBlock;

#pragma mark - 图片信息
/**
 获取图片上某一点的颜色
 
 @param point  图片内的一个点。范围是 [0, image.width-1],[0, image.height-1]
 超出图片范围则返回nil
 */
- (UIColor *)colorAtPoint:(CGPoint)point;

#pragma mark - 修改图片
/** 调整图片大小 (内容可能会被拉伸) */
- (UIImage *)imageByResizeToSize:(CGSize)size;

/** 调整图片大小 (内容会根据contentMode来调整)*/
- (UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

/** 从内部裁剪出一块。*/
- (UIImage *)imageByCropToRect:(CGRect)rect;

/**
 为图片裁剪出圆角
 @param radius  圆角的半径(如果超出图片宽高，内部会调整以适应图片)
 */
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius;

/**
 为图片裁剪出圆角
 @param radius  圆角的半径(如果超出图片宽高，内部会调整以适应图片)
 @param corners  裁剪哪几个角
 @param borderWidth  可以加一个border
 */
- (UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                 corners:(UIRectCorner)corners
                             borderWidth:(CGFloat)borderWidth;

/**
 旋转图片 (中心旋转)
 @param radians   旋转弧度 (逆时针).⟲
 @param fitSize   YES: 旋转后，图片大小会扩大以包含全部内容
 NO: 旋转后，图片大小不变，某些内容会被裁剪
 */
- (UIImage *)imageByRotate:(CGFloat)radians fitSize:(BOOL)fitSize;


/** 向左旋转90° ⤺ (图片宽高会对调)*/
- (UIImage *)imageByRotateLeft90;

/** 向右旋转90° ⤺ (图片宽高会对调)*/
- (UIImage *)imageByRotateRight90;

/** 旋转180°*/
- (UIImage *)imageByRotate180;

/** 上下翻转 ⥯*/
- (UIImage *)imageByFlipVertical;

/** 左右翻转 ⇋*/
- (UIImage *)imageByFlipHorizontal;

#pragma mark - 图片效果
///=============================================================================
/// @name 图片效果
///=============================================================================

/// 给图片染色(Tint Color) (就像用有色眼镜看图片)
- (UIImage *)imageByTintColor:(UIColor *)color;

/// 黑白化
- (UIImage *)imageByGrayscale;

/// 灰毛玻璃效果 (适合在里面显示任何内容)
- (UIImage *)imageByBlurSoft;

/// 白色毛玻璃效果 (苹果内置)(适合在里面显示任何内容，除了纯白色文本) 和上拉控制中心、桌面文件夹效果一样
- (UIImage *)imageByBlurLight;

/// 亮白色毛玻璃效果 (苹果内置)(适合在里面显示深色文字)
- (UIImage *)imageByBlurExtraLight;

/// 黑色色毛玻璃效果 (苹果内置)(适合在里面显示浅色文字) 和下拉通知中心的效果一样
- (UIImage *)imageByBlurDark;

/// 模糊一张图片，并添加tintColor
- (UIImage *)imageByBlurWithTint:(UIColor *)tintColor;

/**
 这是苹果官方提供的一个方法，用于调整图片的模糊、饱和度、蒙板等方法。
 
 Applies a blur, tint color, and saturation adjustment to this image,
 optionally within the area specified by @a maskImage.
 
 @param blurRadius     The radius of the blur in points, 0 means no blur effect.
 
 @param tintColor      An optional UIColor object that is uniformly blended with
 the result of the blur and saturation operations. The
 alpha channel of this color determines how strong the
 tint is. nil means no tint.
 
 @param tintBlendMode  The @a tintColor blend mode. Default is kCGBlendModeNormal (0).
 
 @param saturation     A value of 1.0 produces no change in the resulting image.
 Values less than 1.0 will desaturation the resulting image
 while values greater than 1.0 will have the opposite effect.
 0 means gray scale.
 
 @param maskImage      If specified, @a inputImage is only modified in the area(s)
 defined by this mask.  This must be an image mask or it
 must meet the requirements of the mask parameter of
 CGContextClipToMask.
 
 @return               image with effect, or nil if an error occurs (e.g. no
 enough memory).
 */
- (UIImage *)imageByBlurRadius:(CGFloat)blurRadius
                        tintColor:(UIColor *)tintColor
                         tintMode:(CGBlendMode)tintBlendMode
                       saturation:(CGFloat)saturation
                        maskImage:(UIImage *)maskImage;


/**
 * 模糊一张图片 (只模糊，不调整颜色)
 *
 * @param radius           模糊半径(力度) iOS7模糊大约是40
 */
- (UIImage *)blurredImageWithRadius:(CGFloat)radius;

/**
 * 模糊一张图片
 *
 * @param radius           模糊半径(力度) iOS7模糊大约是40
 * @param iterations       模糊迭代次数 (次数越多、计算量越大、模糊越平滑，通常3就足够了)
 * @param tintColor        模糊后着色 (如果该值为nil,则不会进行着色)
 * @param tintColorPercent 着色的百分比 (0.0~1.0)
 * @param blendMode        着色的混合模式
 */
- (UIImage *)blurredImageWithRadius:(CGFloat)radius
                            iterations:(NSUInteger)iterations
                             tintColor:(UIColor *)tintColor
                      tintColorPercent:(CGFloat)tintColorPercent
                             blendMode:(CGBlendMode)blendMode;


#pragma mark - 图像的一些常用处理
/**
 *  压缩图片
 *
 *  @param img        原来的图片
 *  @param targetSize 要压缩的尺寸
 *
 *  @return 压缩后的图片
 */
+ (UIImage *)imageCompress:(UIImage *)img targetSize:(CGSize)targetSize;

/**
 *  给一张图片添加文字描述
 *
 *  @param img   图片
 *  @param mark  文字
 *  @param rect  文字所在范围
 *  @param font  文字字体
 *  @param color 文字颜色
 *
 *  @return 图片
 */
+ (UIImage *)addTextOnImage:(UIImage *)img mark:(NSString *)mark rect:(CGRect)rect font:(UIFont *)font color:(UIColor *)color;

/**
 *  将图片裁剪为带边框圆形
 *
 *  @param name        图片名
 *  @param borderWidth 边框宽度
 *  @param borderColor 边框颜色
 *
 *  @return 被裁剪后的图片
 */
+ (UIImage *)circleImageWithName:(NSString *)name borderWidth:(CGFloat)borderWidth borderColor:(UIColor *)borderColor;

@end
