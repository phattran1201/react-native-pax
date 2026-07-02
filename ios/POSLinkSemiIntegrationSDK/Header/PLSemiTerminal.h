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

#if __has_include(<POSLinkAdmin/PLBaseTerminal.h>)
    // If xcframework is available
    #import <POSLinkAdmin/PLBaseTerminal.h>
#elif __has_include("PLBaseTerminal.h")
    // If .a static library header file is available
    #import "PLBaseTerminal.h"
#endif

#if __has_include(<POSLinkSemiIntegration/PLTransaction.h>)
    // If xcframework is available
    #import <POSLinkSemiIntegration/PLTransaction.h>
#elif __has_include("PLTransaction.h")
    // If .a static library header file is available
    #import "PLTransaction.h"
#endif

#if __has_include(<POSLinkSemiIntegration/PLReport.h>)
    // If xcframework is available
    #import <POSLinkSemiIntegration/PLReport.h>
#elif __has_include("PLReport.h")
    // If .a static library header file is available
    #import "PLReport.h"
#endif

#if __has_include(<POSLinkSemiIntegration/PLBatch.h>)
    // If xcframework is available
    #import <POSLinkSemiIntegration/PLBatch.h>
#elif __has_include("PLBatch.h")
    // If .a static library header file is available
    #import "PLBatch.h"
#endif

//#import "PLSemiMultiCommand.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLSemiTerminal : PLBaseTerminal
/**
 * Get an instance of PLTransaction
*/
- (PLTransaction *)getTransaction;
/**
 * Get an instance of PLBatch
*/
- (PLBatch *)getBatch;
/**
 * Get an instance of PLReport
*/
- (PLReport *)getReport;
///**
// * Get an instance of PLSemiMultiCommand
//*/
//- (PLSemiMultiCommand *)getMultiCommand;

@end

NS_ASSUME_NONNULL_END
