//
//  TableViewCell.h
//  离屏渲染测试
//
//  Created by pdd on 2019/4/25.
//  Copyright © 2019 pdd. All rights reserved.
//

#import <UIKit/UIKit.h>
@class Joke;

NS_ASSUME_NONNULL_BEGIN

@interface TableViewCell : UITableViewCell
@property (weak, nonatomic) IBOutlet UILabel *testLabel;

@property (nonatomic, strong)Joke *model;

- (float)getCellHeight;
@end

NS_ASSUME_NONNULL_END
