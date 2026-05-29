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
#import "PLSemiTerminal.h"
#import "PLCommunicationSetting.h"
#import "PLLogSetting.h"



@interface POSLinkSemi : NSObject

+ (instancetype)getInstance;
/**
 * Get a instance of PLSemiTerminal.
 * This function will verify whether the terminal exists. It may take several minutes. If the verification fails, it will return NULL and need to be verified again.
 *
 * @parma commSetting Setting of communication mode.
*/
- (PLSemiTerminal * _Nullable)getTerminalWithCommunicationSetting:(PLCommunicationSetting *)commSetting;
/**
 * Set Log
 *
 * @parma logSetting logSetting.
*/
- (void)setLogSetting:(PLLogSetting *)logSetting;

/**
 * Remove Terminal
 *
 * @parma terminal terminal.
*/
- (void)removeTerminal:(PLSemiTerminal *)terminal;

@end

