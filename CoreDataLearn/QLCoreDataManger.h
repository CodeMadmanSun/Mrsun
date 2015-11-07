//
//  QLCoreDataManger.h
//  CoreDataLearn
//
//  Created by Augussun on 15/11/6.
//  Copyright © 2015年 QL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>

#define TableName @"News"

@interface QLCoreDataManger : NSObject
@property (readonly,strong,nonatomic)NSManagedObjectContext *managedObjectContext; // 管理数据类型
@property (readonly,strong,nonatomic)NSManagedObjectModel *managedObjectModel; // 管理数据模型
@property (readonly,strong,nonatomic)NSPersistentStoreCoordinator *persistentStoreCoordinator; // 持久性数据协调器
- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;
//插入数据
- (void)insertCoreData:(NSMutableArray*)dataArray;
//查询
- (NSMutableArray*)selectData:(int)pageSize andOffset:(int)currentPage;
//删除
- (void)deleteData;
//更新
- (void)updateData:(NSString*)newsId withIsLook:(NSString*)islook;

@end
