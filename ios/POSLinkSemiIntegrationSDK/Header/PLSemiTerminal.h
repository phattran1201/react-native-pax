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

#import "PLBaseTerminal.h"
#import "PLTransaction.h"
#import "PLReport.h"
#import "PLBatch.h"
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
