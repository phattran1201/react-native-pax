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

#pragma GCC diagnostic ignored "-Wundeclared-selector"
#define POSLinkPAXLogger(fmt, ...) \
[[POSLinkPAXLogTool sharedInstance] performSelector:@selector(writeLog:) withObject: \
[NSString stringWithFormat:@"%s %@\n",\
[[[[POSLinkPAXLogTool sharedInstance] performSelector:@selector(millisecond)] description] UTF8String], \
[NSString stringWithFormat:(fmt), ##__VA_ARGS__]\
]];

/*
 
 #pragma GCC diagnostic ignored "-Wundeclared-selector"
 #define POSLinkPAXLogger(fmt, ...) \
 [[POSLinkPAXLogTool sharedInstance] performSelector:@selector(writeLog:) withObject: \
 [NSString stringWithFormat:@"%s %s [Line %d] %@\n",\
 [[[[POSLinkPAXLogTool sharedInstance] performSelector:@selector(millisecond)] description] UTF8String], \
 __PRETTY_FUNCTION__, __LINE__,[NSString stringWithFormat:(fmt), ##__VA_ARGS__]\
 ]];
 */

/// Flags accompany each log. They are used together with levels to filter out logs.
typedef NS_OPTIONS(NSUInteger, POSLinkPAXLogFlag){
    POSLinkPAXLogFlagError      = (1 << 0),
    POSLinkPAXLogFlagWarning    = (1 << 1),
    POSLinkPAXLogFlagDebug      = (1 << 2),
    POSLinkPAXLogFlagInfo       = (1 << 3)
};

/// Log levels are used to filter out logs. Used together with flags.
typedef NS_ENUM(NSUInteger, POSLinkPAXLogLevel){
    POSLinkPAXLogLevelOff       = 0,
    POSLinkPAXLogLevelError     = (POSLinkPAXLogFlagError),
    POSLinkPAXLogLevelWarning   = (POSLinkPAXLogLevelError   | POSLinkPAXLogFlagWarning),
    POSLinkPAXLogLevelDebug     = (POSLinkPAXLogLevelWarning | POSLinkPAXLogFlagDebug),
    POSLinkPAXLogLevelInfo      = (POSLinkPAXLogLevelDebug   | POSLinkPAXLogFlagInfo)
};

#define LogLevel [POSLinkPAXLogToolSetting getLogLevel]

#define POSLinkPAXLogError(fmt, ...)    \
if (LogLevel & POSLinkPAXLogFlagError){POSLinkPAXLogger(fmt, ##__VA_ARGS__);}

#define POSLinkPAXLogWarn(fmt, ...)    \
if (LogLevel & POSLinkPAXLogFlagWarning){POSLinkPAXLogger(fmt, ##__VA_ARGS__);}

#define POSLinkPAXLogDebug(fmt, ...)    \
if (LogLevel & POSLinkPAXLogFlagDebug){POSLinkPAXLogger(fmt, ##__VA_ARGS__);}

#define POSLinkPAXLogInfo(fmt, ...)    \
if (LogLevel & POSLinkPAXLogFlagInfo){POSLinkPAXLogger(fmt, ##__VA_ARGS__);}

@interface POSLinkPAXLogToolSetting : NSObject
/// The name of log folder under Library/Caches, the default name is POSLinkPAXLogs.
@property (nonatomic, copy)NSString *folderName;
/// Sign of your sdk
@property (nonatomic, copy)NSString *sdkSign;
/// Is output to the console
@property (nonatomic, assign)BOOL isOutputToConsole;
/// Is used to filter out logs, default is POSLinkPAXLogLevelOff.
@property (nonatomic, assign)POSLinkPAXLogLevel logLevel;
/// keep days
@property (nonatomic, assign)int days;

/// Get log level.
+ (POSLinkPAXLogLevel)getLogLevel;
@end

@interface POSLinkPAXLogTool : NSObject
/// setting
@property (nonatomic, strong)POSLinkPAXLogToolSetting *setting;
@property (nonatomic, strong)NSString *prefix;
/// The singleton.
+ (instancetype)sharedInstance;
/// Share log.
- (void)shareLog;
- (NSArray<NSString *> *)getLogPaths;
@end


