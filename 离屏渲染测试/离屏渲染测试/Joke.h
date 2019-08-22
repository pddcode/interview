//
//  Joke.h
//  离屏渲染测试
//
//  Created by pdd on 2019/5/10.
//  Copyright © 2019 pdd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CellHeightCache.h"

NS_ASSUME_NONNULL_BEGIN

@interface Joke : NSObject<CellheightCacheProtocol>

@property (nonatomic, copy)NSString *objectID;
@property (nonatomic, copy)NSString *content;
@property (nonatomic, copy)NSString *imageName;
@property (nonatomic, assign)NSInteger repeatCount;

@property (nonatomic, assign)CGFloat cellHeight;

+ (instancetype)jokeWithContent:(NSString *)content;
+ (NSArray *)loadJokeFromPlist;

@end

NS_ASSUME_NONNULL_END
