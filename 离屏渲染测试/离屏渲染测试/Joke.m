//
//  Joke.m
//  离屏渲染测试
//
//  Created by pdd on 2019/5/10.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "Joke.h"
#import "NSString+Size.h"

@implementation Joke

+ (instancetype)jokeWithContent:(NSString *)content
{
    Joke *joke = [Joke new];
    joke.content = content;
    joke.repeatCount = 1;
    joke.imageName = [NSString stringWithFormat:@"images%@", @([Joke randomInt:7])];
    joke.cellHeight = [joke getCellHeight];
    return joke;
}

+ (NSArray *)loadJokeFromPlist
{
    NSURL *url = [[NSBundle mainBundle] URLForResource:@"duanzi" withExtension:@"plist"];
    NSArray *rawJokes = [[NSArray alloc] initWithContentsOfURL:url];
    NSMutableArray *jokes = [NSMutableArray array];
    [rawJokes enumerateObjectsUsingBlock:^(id  _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
        NSDictionary *dict = obj;
        NSString *content = dict[@"text"];
        content = [content stringByReplacingOccurrencesOfString:@"\\n" withString:@"\n"];
        content = [content stringByAppendingString:@"\n"];
        Joke *joke = [Joke jokeWithContent:content];
        [jokes addObject:joke];
    }];
    return jokes;
}

- (NSString *)modelID
{
    return [NSString stringWithFormat:@"%lu", (unsigned long)[self.content hash]];
}

+(NSUInteger)randomInt:(NSUInteger)toInt
{
    return arc4random_uniform((u_int32_t)toInt)+1;
}

- (CGFloat)getCellHeight
{
//    CGSize labelSize = [@"网上聊了一个妹子，今天见面，问老妈要了二百块钱，老妈问我干嘛用，我说约会，她高高兴兴的就给了。刚出家门，老爸就把我拽到一遍说“小子，二百块给我一百，半个月不知道烟的滋味了。”" sizeWithFont:[UIFont systemFontOfSize:17] maxSize:CGSizeMake([UIScreen mainScreen].bounds.size.width-60, CGFLOAT_MAX)];
//    return labelSize.height + 20;
    NSString *string = @"网上聊了一个妹子，今天见面，问老妈要了二百块钱，老妈问我干嘛用，我说约会，她高高兴兴的就给了。刚出家门，老爸就把我拽到一遍说“小子，二百块给我一百，半个月不知道烟的滋味了。”";
    CGRect rect = [string boundingRectWithSize:CGSizeMake([UIScreen mainScreen].bounds.size.width-60, MAXFLOAT) options:NSStringDrawingUsesLineFragmentOrigin attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:20]} context:nil];
    return rect.size.height + 20;
}

@end
