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
/**
 Do QR payment request.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostTraceRequest.h>)
   #import <POSLinkAdmin/PLHostTraceRequest.h>
#elif __has_include("PLHostTraceRequest.h")
   #import "PLHostTraceRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLTaxDetail.h>)
   #import <POSLinkAdmin/PLTaxDetail.h>
#elif __has_include("PLTaxDetail.h")
   #import "PLTaxDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLLineItemDetail.h>)
   #import <POSLinkAdmin/PLLineItemDetail.h>
#elif __has_include("PLLineItemDetail.h")
   #import "PLLineItemDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLTaxDetail.h>)
   #import <POSLinkAdmin/PLTaxDetail.h>
#elif __has_include("PLTaxDetail.h")
   #import "PLTaxDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLCommercialRequest.h>)
   #import <POSLinkAdmin/PLCommercialRequest.h>
#elif __has_include("PLCommercialRequest.h")
   #import "PLCommercialRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLCashierRequest.h>)
   #import <POSLinkAdmin/PLCashierRequest.h>
#elif __has_include("PLCashierRequest.h")
   #import "PLCashierRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLTraceRequest.h>)
   #import <POSLinkAdmin/PLTraceRequest.h>
#elif __has_include("PLTraceRequest.h")
   #import "PLTraceRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLAmountRequest.h>)
   #import <POSLinkAdmin/PLAmountRequest.h>
#elif __has_include("PLAmountRequest.h")
   #import "PLAmountRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLDoQrPaymentRequest.h>)
   #import <POSLinkAdmin/PLDoQrPaymentRequest.h>
#elif __has_include("PLDoQrPaymentRequest.h")
   #import "PLDoQrPaymentRequest.h"
#endif



@interface PLDoQrPaymentRequest : PLRequest
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Amount information. 
 */
@property (readwrite, nonatomic, strong)PLAmountRequest *amountInformation;
/**
 Trace information. 
 */
@property (readwrite, nonatomic, strong)PLTraceRequest *traceInformation;
/**
 Cashier information. 
 */
@property (readwrite, nonatomic, strong)PLCashierRequest *cashierInformation;
/**
 Commercial information. 
 */
@property (readwrite, nonatomic, strong)PLCommercialRequest *commercialInformation;
/**
 Host Trace information. 
 */
@property (readwrite, nonatomic, strong)PLHostTraceRequest *hostTraceInformation;


@end