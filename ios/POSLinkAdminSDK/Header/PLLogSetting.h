/*
 * ============================================================================
 * = COPYRIGHT
 *          PAX Computer Technology(Shenzhen) Co., Ltd. PROPRIETARY INFORMATION
 *   This software is supplied under the terms of a license agreement or nondisclosure
 *   agreement with PAX Computer Technology(Shenzhen) Co., Ltd. and may not be copied or
 *   disclosed except in accordance with the terms in that agreement.
 *     Copyright (C) 2023 PAX Computer Technology(Shenzhen) Co., Ltd. All rights reserved.
 * ============================================================================
 */

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, LoggerLevel) {
    LoggerLevelOff = 0,
    LoggerLevelError,
    LoggerLevelWarning,
    LoggerLevelDebug,
    LoggerLevelInfo,
};

NS_ASSUME_NONNULL_BEGIN

@interface PLLogSetting : NSObject
@property (nonatomic, assign)int keepDays;
@property (nonatomic, assign)LoggerLevel level;
@property (nonatomic, strong)NSString *dirName;
@end

NS_ASSUME_NONNULL_END
