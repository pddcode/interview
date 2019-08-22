//
//  CellHeightCache.h
//  离屏渲染测试
//
//  Created by pdd on 2019/5/10.
//  Copyright © 2019 pdd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef CGFloat (^CalcCellHeightBlock)(id model, UITableView *tableView);
typedef CGSize (^CalcCellSizeBlock)(id model, UICollectionView *collectionView);

@protocol CellheightCacheProtocol <NSObject>

- (NSString *)modelID;

@end

NS_ASSUME_NONNULL_BEGIN

@interface CellHeightCache : NSObject

- (CGFloat)getCellHeightForModel:(id)model withTableView:(UITableView *)tableView orCalc:(CalcCellHeightBlock)block;
- (void)setCellHeightForModel:(id)model withTableView:(UITableView *)tableView cellHeight:(CGFloat)cellHeight;
@end

NS_ASSUME_NONNULL_END
