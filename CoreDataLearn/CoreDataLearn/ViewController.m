//
//  ViewController.m
//  CoreDataLearn
//
//  Created by Augussun on 15/11/6.
//  Copyright © 2015年 QL. All rights reserved.
//

#import "ViewController.h"
#import "ArInfo.h"
#import "AppDelegate.h"
#import "QLCoreDataManger.h"

@interface ViewController ()

@end

@implementation ViewController

- (BOOL) imageHasAlpha: (UIImage *) image
{
    CGImageAlphaInfo alpha = CGImageGetAlphaInfo(image.CGImage);
    return (alpha == kCGImageAlphaFirst ||
            alpha == kCGImageAlphaLast ||
            alpha == kCGImageAlphaPremultipliedFirst ||
            alpha == kCGImageAlphaPremultipliedLast);
}
- (NSString *) image2DataURL: (UIImage *) image
{
    NSData *imageData = nil;
    NSString *mimeType = nil;
    
    if ([self imageHasAlpha: image]) {
        imageData = UIImagePNGRepresentation(image);
        mimeType = @"image/png";
    } else {
        imageData = UIImageJPEGRepresentation(image, 1.0f);
        mimeType = @"image/jpeg";
    }
    
    return [NSString stringWithFormat:@"data:%@;base64,%@", mimeType,
            [imageData base64EncodedStringWithOptions: 0]];
    
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    QLCoreDataManger *apDelegate = [[QLCoreDataManger alloc]init]; // 引进自己项目的委托
    self.context = apDelegate.managedObjectContext;
    
    ArInfo * arInfo = [NSEntityDescription insertNewObjectForEntityForName:@"ArInfo" inManagedObjectContext:self.context];
    UIImage * image = [UIImage imageNamed:@"girl.png"];
    NSString * imageBase64 = [self image2DataURL:image];
    arInfo.image = imageBase64;
    arInfo.myid = @"123";
    arInfo.myname = @"";
    NSError *error = nil;
    if (![self.context save:&error]) {
        NSLog(@"%@",[error localizedDescription]);
    }
    
    NSFetchRequest * fetchRequest = [[NSFetchRequest alloc]init];
    NSEntityDescription * entity = [NSEntityDescription entityForName:@"ArInfo" inManagedObjectContext:self.context];
    [fetchRequest setEntity:entity];
    
    
//    [apDelegate deleteDataWithWhichClasstype:arinfo];
    
    NSArray * fetchObject  =[self.context executeFetchRequest:fetchRequest error:&error];
    for (NSManagedObject * info in fetchObject) {
        NSLog(@"%@--%@---%@",[info valueForKey:@"myid"],[info valueForKey:@"myname"],[info valueForKey:@"image"]);
        NSURL *url = [NSURL URLWithString: [info valueForKey:@"image"]];
        NSData *data = [NSData dataWithContentsOfURL: url];
        UIImage *image = [UIImage imageWithData: data];
        UIImageView * imageView = [[UIImageView alloc]initWithFrame:self.view.frame];
        imageView.backgroundColor = [UIColor yellowColor];
        [self.view addSubview:imageView];
        imageView.image = image;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
