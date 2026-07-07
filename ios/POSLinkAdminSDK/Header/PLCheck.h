//
//  PLCheck.h
//  POSLinkSemiIntegrationLib
//
//  Created by amoswang on 2024/4/11.
//

#import <Foundation/Foundation.h>
NS_ASSUME_NONNULL_BEGIN

@interface PLCheck : NSObject

+ (NSError * _Nullable)checkCmd:(NSString *)cmdStr;

@end

NS_ASSUME_NONNULL_END
