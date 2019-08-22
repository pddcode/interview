//
//  NSString+Size.h
//  离屏渲染测试
//
//  Created by pdd on 2019/5/9.
//  Copyright © 2019 pdd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (Size)

+ (CGSize)sizeWithString:(NSString *)str font:(UIFont *)font maxSize:(CGSize)size;
- (CGSize)sizeWithFont:(UIFont *)font maxSize:(CGSize)size;
@end

NS_ASSUME_NONNULL_END
