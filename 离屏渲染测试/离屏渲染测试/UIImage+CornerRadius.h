//
//  UIImage+CornerRadius.h
//  离屏渲染测试
//
//  Created by pdd on 2019/5/5.
//  Copyright © 2019 pdd. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (CornerRadius)

- (UIImage *)imageAddCornerWithRadius:(CGFloat)radius size:(CGSize)size;

@end

NS_ASSUME_NONNULL_END
