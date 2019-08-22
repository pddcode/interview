//
//  UIView+CornerRadius.h
//  离屏渲染测试
//
//  Created by pdd on 2019/5/5.
//  Copyright © 2019 pdd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CornerRadius)

- (void)addCorner:(CGFloat)radius;

- (void)addCorner:(CGFloat)radius borderWidth:(CGFloat)borderWidth backgroundColor:(UIColor *)backgroundColor borderColor:(UIColor *)borderColor;

- (UIImage *)drawRectWithRoundedCorner:(CGFloat)radius borderWidth:(CGFloat)borderWidth backgroundColor:(UIColor *)backgroundColor borderColor:(UIColor *)borderColor;

@end

NS_ASSUME_NONNULL_END
