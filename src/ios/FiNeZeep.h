#import <Foundation/Foundation.h>
#import <Cordova/CDVPlugin.h>
#import "SSZeepArchive.h"

@interface FiNeZeep : CDVPlugin

-(void)zip:(CDVInvokedUrlCommand*)command;
-(void)unzip:(CDVInvokedUrlCommand*)command;

@end
