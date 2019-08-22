//
//  ViewController.m
//  AFN学习
//
//  Created by pdd on 2019/5/21.
//  Copyright © 2019 pdd. All rights reserved.
//

#import "ViewController.h"
#import <AFNetworking.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    AFHTTPSessionManager *manager = [AFHTTPSessionManager manager];
    manager.requestSerializer = [AFJSONRequestSerializer serializer];
    manager.requestSerializer.allowsCellularAccess = YES;
    NSString *url = @"http://120.25.226.186.32812";
    id parameters = @{@"name" : @"pdd",
                      @"sex" : @"man",
                      @"friends" : @{@"name" : @"xioaming", @"sex" : @"man"}
                      };
    id parameters2 = @[@"pdd", @"man"];
    [manager GET:url parameters:parameters progress:^(NSProgress * _Nonnull downloadProgress) {

    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {

    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {

    }];
    
    
    [[AFNetworkReachabilityManager sharedManager] setReachabilityStatusChangeBlock:^(AFNetworkReachabilityStatus status) {
        switch (status) {
            case AFNetworkReachabilityStatusUnknown:
                NSLog(@"未知网络");
                break;
            case AFNetworkReachabilityStatusNotReachable:
                NSLog(@"无网络连接");
                break;
            case AFNetworkReachabilityStatusReachableViaWWAN:
                NSLog(@"蜂窝网络");
                break;
            case AFNetworkReachabilityStatusReachableViaWiFi:
                NSLog(@"WiFi网络");
                break;
            default:
                break;
        }
    }];
    [[AFNetworkReachabilityManager sharedManager] startMonitoring];
//    BOOL isReachable = [AFNetworkReachabilityManager sharedManager].isReachable;
    
    /***
    //创建Configuration对象，并设置各种属性
    NSURLSessionConfiguration *configuration = [NSURLSessionConfiguration defaultSessionConfiguration];
    configuration.timeoutIntervalForRequest = 10.0;
    configuration.allowsCellularAccess = YES;
    
    //通过Configuration创建session，一个session可以管理多个task
    NSURLSession *session = [NSURLSession sessionWithConfiguration:configuration];
    NSURL *url = [NSURL URLWithString:@"http://120.25.226.186.32812/login"];
    
    //通过URL创建request
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    //设置request的请求方法和请求体
    request.HTTPMethod = @"POST";
    request.HTTPBody = [@"username=520it&pwd=520it&type=JSON" dataUsingEncoding:NSUTF8StringEncoding];
    
    //通过session和request来创建task
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        
    }];
    
    [dataTask resume];
    ***/
}

/***
 AFSSLPinningModeNone:不做LSSL pinning,只跟浏览器一样在系统的e信任机构列表里验证服务器端返回的证书。若证书是信任机构签发的就会通过，若是自己服务器生成的证书，则不会通过。
 AFSSLPinningModeCertificate:这种验证方式需要客户端保存服务器端的证书拷贝，这里验证分两步，第一步验证证书的域名/有效期等信息，第二步是对比服务端返回的证书跟客户端返回的是否一致
 AFSSLPiningModePublicKey:客户端要有服务端的证书拷贝，只是验证时只验证证书里的公钥，不验证证书的有效期等信息。
 
 + (instancetype)defaultPolicy
 返回一个默认的安全策略：不允许使用x无效的证书，验证域名，不验证绑定的证书和公钥
 ***/



@end
