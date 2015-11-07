//
//  ArInfo+CoreDataProperties.h
//  CoreDataLearn
//
//  Created by Augussun on 15/11/6.
//  Copyright © 2015年 QL. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "ArInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface ArInfo (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *myid;
@property (nullable, nonatomic, retain) NSString *myname;
@property (nullable, nonatomic, retain) NSString *image;

@end

NS_ASSUME_NONNULL_END
