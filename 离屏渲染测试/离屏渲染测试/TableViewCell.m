//
//  TableViewCell.m
//  离屏渲染测试
//
//  Created by pdd on 2019/4/25.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "TableViewCell.h"
#import "NSString+Size.h"
#import "Joke.h"

@interface TableViewCell ()

@end

@implementation TableViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
//    self.testLabel.text = @"哈哈这真的只是一条测试，我们只是测试一个约束";
    
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated {
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)setModel:(Joke *)model
{
    self.testLabel.text = model.content;
    self.testLabel.text = @"网上聊了一个妹子，今天见面，问老妈要了二百块钱，老妈问我干嘛用，我说约会，她高高兴兴的就给了。刚出家门，老爸就把我拽到一遍说“小子，二百块给我一百，半个月不知道烟的滋味了。”";
}

- (float)getCellHeight
{
    CGSize labelSize = [self.testLabel.text sizeWithFont:[UIFont systemFontOfSize:17] maxSize:CGSizeMake(self.bounds.size.width-60, CGFLOAT_MAX)];
    return labelSize.height + 20;
}

@end
