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
#if __has_include(<POSLinkAdmin/PLExecutionResult.h>)
   #import <POSLinkAdmin/PLExecutionResult.h>
#elif __has_include("PLExecutionResult.h")
   #import "PLExecutionResult.h"
#endif



#if __has_include(<POSLinkAdmin/PLBaseTerminal.h>)
   #import <POSLinkAdmin/PLBaseTerminal.h>
#elif __has_include("PLBaseTerminal.h")
   #import "PLBaseTerminal.h"
#endif



#if __has_include(<POSLinkAdmin/PLMifareCardRequest.h>)
   #import <POSLinkAdmin/PLMifareCardRequest.h>
#elif __has_include("PLMifareCardRequest.h")
   #import "PLMifareCardRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLCameraScanRequest.h>)
   #import <POSLinkAdmin/PLCameraScanRequest.h>
#elif __has_include("PLCameraScanRequest.h")
   #import "PLCameraScanRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLPrinterRequest.h>)
   #import <POSLinkAdmin/PLPrinterRequest.h>
#elif __has_include("PLPrinterRequest.h")
   #import "PLPrinterRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLCardInsertDetectionRequest.h>)
   #import <POSLinkAdmin/PLCardInsertDetectionRequest.h>
#elif __has_include("PLCardInsertDetectionRequest.h")
   #import "PLCardInsertDetectionRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLPrinterResponse.h>)
   #import <POSLinkAdmin/PLPrinterResponse.h>
#elif __has_include("PLPrinterResponse.h")
   #import "PLPrinterResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLMifareCardResponse.h>)
   #import <POSLinkAdmin/PLMifareCardResponse.h>
#elif __has_include("PLMifareCardResponse.h")
   #import "PLMifareCardResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLCardInsertDetectionResponse.h>)
   #import <POSLinkAdmin/PLCardInsertDetectionResponse.h>
#elif __has_include("PLCardInsertDetectionResponse.h")
   #import "PLCardInsertDetectionResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLCameraScanResponse.h>)
   #import <POSLinkAdmin/PLCameraScanResponse.h>
#elif __has_include("PLCameraScanResponse.h")
   #import "PLCameraScanResponse.h"
#endif




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

