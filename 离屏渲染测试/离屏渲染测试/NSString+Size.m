//
//  NSString+Size.m
//  离屏渲染测试
//
//  Created by pdd on 2019/5/9.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "NSString+Size.h"
#import <UIKit/UIKit.h>

@implementation NSString (Size)

+ (CGSize)sizeWithString:(NSString *)str font:(UIFont *)font maxSize:(CGSize)size
{
    NSAttributedString *attrStr = [[NSAttributedString alloc] initWithString:str attributes:@{NSFontAttributeName: font}];
    return [attrStr boundingRectWithSize:size options:NSStringDrawingUsesLineFragmentOrigin context:nil].size;
    
}

- (CGSize)sizeWithFont:(UIFont *)font maxSize:(CGSize)size
{
    NSAttributedString *attrStr = [[NSAttributedString alloc] initWithString:self attributes:@{NSFontAttributeName: font}];
    return [attrStr boundingRectWithSize:size options:NSStringDrawingUsesLineFragmentOrigin context:nil].size;
}

@end
