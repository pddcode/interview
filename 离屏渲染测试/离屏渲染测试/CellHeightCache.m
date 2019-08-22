//
//  CellHeightCache.m
//  离屏渲染测试
//
//  Created by pdd on 2019/5/10.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "CellHeightCache.h"

const CGSize NilCacheSize = {-1, -1};

@interface CellHeightCache ()

@property (nonatomic, strong)NSCache *cacheLandscape;
@property (nonatomic, strong)NSCache *cacheportrait;

@end

@implementation CellHeightCache

- (NSCache *)cacheLandscape
{
    if (!_cacheLandscape) {
        _cacheLandscape = [NSCache new];
    }
    return _cacheLandscape;
}

- (NSCache *)cacheportrait
{
    if (!_cacheportrait) {
        _cacheportrait = [NSCache new];
    }
    return _cacheportrait;
}

- (CGFloat)getCellHeightForModel:(id)model withTableView:(UITableView *)tableView orCalc:(CalcCellHeightBlock)block
{
    CGSize cellSize = [self getCacheSizeForModel:model];
    if (CGSizeEqualToSize(cellSize, NilCacheSize)) {
        cellSize.height = block(model, tableView);
        [self setOrientationSize:cellSize forModel:model];
        NSLog(@"计算行高:%@", @(cellSize.height));
    }
    return cellSize.height;
}

- (void)setCellHeightForModel:(id)model withTableView:(UITableView *)tableView cellHeight:(CGFloat)cellHeight
{
    CGSize cacheSize = NilCacheSize;
    cacheSize.height = cellHeight;
    [self setOrientationSize:cacheSize forModel:model];
}

- (CGSize)getCacheSizeForModel:(id<CellheightCacheProtocol>)model
{
    CGSize cacheSize = NilCacheSize;
    NSValue *cacheSizeValue = [self sizeByOrientationForKey:[model modelID]];
    if (cacheSizeValue) {
        NSLog(@"从缓存中读取行高：%@", cacheSizeValue);
        cacheSize = cacheSizeValue.CGSizeValue;
    }
    return cacheSize;
}

//从缓存中取值
- (NSValue *)sizeByOrientationForKey:(NSString *)key
{
    if (UIDeviceOrientationIsLandscape([UIDevice currentDevice].orientation)) {
        return [self.cacheLandscape objectForKey:key];
    }else {
        return [self.cacheportrait objectForKey:key];
    }
}

//将值设到缓存中
- (void)setOrientationSize:(CGSize)size forModel:(id<CellheightCacheProtocol>)model
{
    if (UIDeviceOrientationIsLandscape([UIDevice currentDevice].orientation)) {
        [self.cacheLandscape setObject:[NSValue valueWithCGSize:size] forKey:[model modelID]];
    }else{
        [self.cacheportrait setObject:[NSValue valueWithCGSize:size] forKey:[model modelID]];
    }
}

@end
