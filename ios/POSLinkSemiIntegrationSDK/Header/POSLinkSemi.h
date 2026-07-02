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

#if __has_include(<POSLinkSemiIntegration/PLSemiTerminal.h>)
    // If xcframework is available
    #import <POSLinkSemiIntegration/PLSemiTerminal.h>
#elif __has_include("PLSemiTerminal.h")
    // If .a static library header file is available
    #import "PLSemiTerminal.h"
#endif

#if __has_include(<POSLinkSemiIntegration/PLCommunicationSetting.h>)
    // If xcframework is available
    #import <POSLinkSemiIntegration/PLCommunicationSetting.h>
#elif __has_include("PLCommunicationSetting.h")
    // If .a static library header file is available
    #import "PLCommunicationSetting.h"
#endif

#if __has_include(<POSLinkAdmin/PLLogSetting.h>)
    // If xcframework is available
    #import <POSLinkAdmin/PLLogSetting.h>
#elif __has_include("PLLogSetting.h")
    // If .a static library header file is available
    #import "PLLogSetting.h"
#endif


@interface POSLinkSemi : NSObject

+ (instancetype)getInstance;
/**
 * Get a instance of PLSemiTerminal.
 * This function will verify whether the terminal exists. It may take several minutes. If the verification fails, it will return NULL and need to be verified again.
 *
 * @param commSetting Setting of communication mode.
*/
- (PLSemiTerminal * _Nullable)getTerminalWithCommunicationSetting:(PLCommunicationSetting *)commSetting;
/**
 * Set Log
 *
 * @param logSetting logSetting.
*/
- (void)setLogSetting:(PLLogSetting *)logSetting;

/**
 * Remove Terminal
 *
 * @param terminal terminal.
*/
- (void)removeTerminal:(PLSemiTerminal *)terminal;

@end

