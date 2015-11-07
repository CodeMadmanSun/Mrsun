//
//  QLCoreDataManger.h
//  CoreDataLearn
//
//  Created by Augussun on 15/11/6.
//  Copyright © 2015年 QL. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreData/CoreData.h>
#import "MJExtension.h"
#import "ArInfo.h"
#import "FirstTabelModel.h"

#define FirstTabelModelName  @"FirstTabelModel"
#define ArInfoName @"ArInfo"
typedef enum
{
    arinfo,
    firstModel,
}
FSO;//这个是枚举是区别不同的实体,我这边就写一个test;
@interface QLCoreDataManger : NSObject
@property (readonly,strong,nonatomic)NSManagedObjectContext *managedObjectContext; // 管理数据类型
@property (readonly,strong,nonatomic)NSManagedObjectModel *managedObjectModel; // 管理数据模型
@property (readonly,strong,nonatomic)NSPersistentStoreCoordinator *persistentStoreCoordinator; // 持久性数据协调器
- (void)saveContext;
- (NSURL *)applicationDocumentsDirectory;

//插入数据
- (void)insertCoreData:(NSMutableArray*)dataArray andWithWhichClasstype:(FSO)type;
//查询
- (NSMutableArray*)selectData:(int)pageSize andOffset:(int)currentPage andWithWhichClasstype:(FSO)type;
//删除
- (void)deleteDataWithWhichClasstype:(FSO)type;
//更新
- (void)updateData:(NSString*)newsId withIsLook:(NSString*)islook andWithWhichClasstype:(FSO)type;

@end
