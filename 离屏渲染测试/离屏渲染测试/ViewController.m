//
//  ViewController.m
//  离屏渲染测试
//
//  Created by pdd on 2019/4/25.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "ViewController.h"
#import "TableViewCell.h"
#import "UIView+CornerRadius.h"
#import "TestView.h"
#import "Joke.h"
#import "CellHeightCache.h"

#define WIDTH [UIScreen mainScreen].bounds.size.width;
#define HEIGHT [UIScreen mainScreen].bounds.size.height;

@interface ViewController ()<UITableViewDelegate, UITableViewDataSource>

@property (nonatomic, strong)UITableView *tableView;

@property (nonatomic, strong)NSArray *modelArray;

@property (nonatomic, strong)CellHeightCache *cellHeightCache;
@property (nonatomic, strong)TableViewCell *prototypeCell;

@end

@implementation ViewController

- (CellHeightCache *)cellHeightCache
{
    if (!_cellHeightCache) {
        _cellHeightCache = [CellHeightCache new];
    }
    
    return _cellHeightCache;
}

- (TableViewCell *)prototypeCell
{
    if (!_prototypeCell) {
        _prototypeCell = [self.tableView dequeueReusableCellWithIdentifier:NSStringFromClass([TableViewCell class])];
    }
    return _prototypeCell;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Do any additional setup after loading the view, typically from a nib.
    self.tableView = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height)];
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.tableView registerNib:[UINib nibWithNibName:@"TableViewCell" bundle:[NSBundle mainBundle]] forCellReuseIdentifier:NSStringFromClass([TableViewCell class])];
    [self.view addSubview:self.tableView];
    
    self.modelArray = [Joke loadJokeFromPlist];
    //在后台计算布局，然后缓存下来
    //这是在从网络端拉取完了数据后x直接在后台计算cell高度
//    dispatch_async(dispatch_queue_create("mytest", DISPATCH_QUEUE_CONCURRENT), ^{
//        for (Joke *model in self.modelArray) {
//            self.prototypeCell.model = model;
//            [self.cellHeightCache setCellHeightForModel:model withTableView:self.tableView cellHeight:[self.prototypeCell getCellHeight]];
//        }
//    });
    
    self.tableView.estimatedRowHeight = 44;
    
    
    
}

#pragma mark - <UITableViewDelegate>
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{

    NSLog(@"==============%ld", (long)indexPath.row);
    //首先从缓存中取，缓存中取不到再通过cell的.m文件的方法去获取，然后缓存下来
//    return [self.cellHeightCache getCellHeightForModel:self.modelArray[indexPath.row] withTableView:tableView orCalc:^CGFloat(id model, UITableView *tableView) {
//        self.prototypeCell.model = model;
//        return [self.prototypeCell getCellHeight];
//    }];

    //这里是先尝试从缓存中去获取cell的高度，如果缓存中获取不到，那么就要自己计算
    return [self.cellHeightCache getCellHeightForModel:self.modelArray[indexPath.row] withTableView:tableView orCalc:^CGFloat(id model, UITableView *tableView) {
        //给cell的model赋值
        self.prototypeCell.model = self.modelArray[indexPath.row];
        //强制进行布局
        [self.prototypeCell layoutIfNeeded];
        //在布局完成后通过Label的位置来确定cell的高度
        return self.prototypeCell.testLabel.frame.origin.y + self.prototypeCell.testLabel.frame.size.height + 10;
    }];

//    return ((Joke *)self.modelArray[indexPath.row]).cellHeight;
}

- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 0;
}

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section
{
    return 0;
}

#pragma mark -<UITableViewDataSource>
- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 50;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    
    TableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:NSStringFromClass([TableViewCell class])];
    cell.model = self.modelArray[indexPath.row];
    return cell;
    
}




@end
