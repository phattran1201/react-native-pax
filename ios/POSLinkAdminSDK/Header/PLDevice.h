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
#import "PLExecutionResult.h"
#import "PLBaseTerminal.h"
#import "PLMifareCardRequest.h"
#import "PLCameraScanRequest.h"
#import "PLPrinterRequest.h"
#import "PLCardInsertDetectionRequest.h"
#import "PLPrinterResponse.h"
#import "PLMifareCardResponse.h"
#import "PLCardInsertDetectionResponse.h"
#import "PLCameraScanResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface PLDevice : NSObject

/**
 * Constructor
 *
 * @param terminal terminal.
*/
- (instancetype)initWithTerminal:(PLBaseTerminal *)terminal;

/**
 * Mifare Card Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)mifareCardWithRequest:(PLMifareCardRequest *)request completion:(void(^)(PLMifareCardResponse *response,PLExecutionResult *result))completion;

/**
 * Camera Scan Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)cameraScanWithRequest:(PLCameraScanRequest *)request completion:(void(^)(PLCameraScanResponse *response,PLExecutionResult *result))completion;

/**
 * Printer Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)printerWithRequest:(PLPrinterRequest *)request completion:(void(^)(PLPrinterResponse *response,PLExecutionResult *result))completion;

/**
 * Card Insert Detection Request
 *
 * @param request Request data.
 * @param completion Callback of response data.
*/
- (void)cardInsertDetectionWithRequest:(PLCardInsertDetectionRequest *)request completion:(void(^)(PLCardInsertDetectionResponse *response,PLExecutionResult *result))completion;


@end

NS_ASSUME_NONNULL_END

