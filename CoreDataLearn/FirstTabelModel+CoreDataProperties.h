//
//  FirstTabelModel+CoreDataProperties.h
//  CoreDataLearn
//
//  Created by Augussun on 15/11/7.
//  Copyright © 2015年 QL. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "FirstTabelModel.h"

NS_ASSUME_NONNULL_BEGIN

@interface FirstTabelModel (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *newname;
@property (nullable, nonatomic, retain) NSString *newmark;
@property (nullable, nonatomic, retain) NSString *newid;

@end

NS_ASSUME_NONNULL_END
