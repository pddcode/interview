//
//  UIView+CornerRadius.m
//  离屏渲染测试
//
//  Created by pdd on 2019/5/5.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "UIView+CornerRadius.h"

@implementation UIView (CornerRadius)
//使用插入子视图的方法
- (void)addCorner:(CGFloat)radius
{
    [self addCorner:radius borderWidth:1 backgroundColor:[UIColor clearColor] borderColor:[UIColor clearColor]];
}

- (void)addCorner:(CGFloat)radius borderWidth:(CGFloat)borderWidth backgroundColor:(UIColor *)backgroundColor borderColor:(UIColor *)borderColor
{
    UIImageView *imageview = [[UIImageView alloc] initWithImage:[self drawRectWithRoundedCorner:radius borderWidth:borderWidth backgroundColor:backgroundColor borderColor:borderColor]];
    [self insertSubview:imageview atIndex:0];
}

- (UIImage *)drawRectWithRoundedCorner:(CGFloat)radius borderWidth:(CGFloat)borderWidth backgroundColor:(UIColor *)backgroundColor borderColor:(UIColor *)borderColor
{
    CGSize sizeToFit = self.bounds.size;
    CGFloat halfBorderWidth = borderWidth/2.0;
    
    UIGraphicsBeginImageContextWithOptions(sizeToFit, false, [[UIScreen mainScreen] scale]);
    CGContextRef context = UIGraphicsGetCurrentContext();
    CGContextSetLineWidth(context, borderWidth);
    //通过一个粗的线条来实现borderColor
    CGContextSetStrokeColorWithColor(context, borderColor.CGColor);
    //通过填充色来实现backgroundColor
    CGContextSetFillColorWithColor(context, backgroundColor.CGColor);
    
    CGFloat width = sizeToFit.width;
    CGFloat height = sizeToFit.height;
    CGContextMoveToPoint(context, width-halfBorderWidth, radius+halfBorderWidth);
    CGContextAddArcToPoint(context, width - halfBorderWidth, height - halfBorderWidth, width - radius - halfBorderWidth, height - halfBorderWidth, radius); // 右下角角度
    CGContextAddArcToPoint(context, halfBorderWidth, height - halfBorderWidth, halfBorderWidth, height - radius - halfBorderWidth, radius); // 左下角角度
    CGContextAddArcToPoint(context, halfBorderWidth, halfBorderWidth, width - halfBorderWidth, halfBorderWidth, radius); // 左上角
    CGContextAddArcToPoint(context, width - halfBorderWidth, halfBorderWidth, width - halfBorderWidth, radius + halfBorderWidth, radius); // 右上角
    
    CGContextDrawPath(context, kCGPathFillStroke);
    UIImage *output = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return output;
}



@end
