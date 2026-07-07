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
 Host Detail Report Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
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


#if __has_include(<POSLinkAdmin/PLMotoECommerceResponse.h>)
   #import <POSLinkAdmin/PLMotoECommerceResponse.h>
#elif __has_include("PLMotoECommerceResponse.h")
   #import "PLMotoECommerceResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLAvsResponse.h>)
   #import <POSLinkAdmin/PLAvsResponse.h>
#elif __has_include("PLAvsResponse.h")
   #import "PLAvsResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLTorResponse.h>)
   #import <POSLinkAdmin/PLTorResponse.h>
#elif __has_include("PLTorResponse.h")
   #import "PLTorResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLCommercialResponse.h>)
   #import <POSLinkAdmin/PLCommercialResponse.h>
#elif __has_include("PLCommercialResponse.h")
   #import "PLCommercialResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLCashierResponse.h>)
   #import <POSLinkAdmin/PLCashierResponse.h>
#elif __has_include("PLCashierResponse.h")
   #import "PLCashierResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLTraceResponse.h>)
   #import <POSLinkAdmin/PLTraceResponse.h>
#elif __has_include("PLTraceResponse.h")
   #import "PLTraceResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLAccountResponse.h>)
   #import <POSLinkAdmin/PLAccountResponse.h>
#elif __has_include("PLAccountResponse.h")
   #import "PLAccountResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLAmountResponse.h>)
   #import <POSLinkAdmin/PLAmountResponse.h>
#elif __has_include("PLAmountResponse.h")
   #import "PLAmountResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdditionalResponseData.h>)
   #import <POSLinkAdmin/PLAdditionalResponseData.h>
#elif __has_include("PLAdditionalResponseData.h")
   #import "PLAdditionalResponseData.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostInformationResponse.h>)
   #import <POSLinkAdmin/PLHostInformationResponse.h>
#elif __has_include("PLHostInformationResponse.h")
   #import "PLHostInformationResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostDetailReportResponse.h>)
   #import <POSLinkAdmin/PLHostDetailReportResponse.h>
#elif __has_include("PLHostDetailReportResponse.h")
   #import "PLHostDetailReportResponse.h"
#endif



@interface PLHostDetailReportResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostInformationResponse *hostInformation;
/**
 EDC type. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Original transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType originalTransactionType;
/**
 Amount information. 
 */
@property (readwrite, nonatomic, strong)PLAmountResponse *amountInformation;
/**
 Account information. 
 */
@property (readwrite, nonatomic, strong)PLAccountResponse *accountInformation;
/**
 Trace information. 
 */
@property (readwrite, nonatomic, strong)PLTraceResponse *traceInformation;
/**
 Cashier information. 
 */
@property (readwrite, nonatomic, strong)PLCashierResponse *cashierInformation;
/**
 Commercial information. 
 */
@property (readwrite, nonatomic, strong)PLCommercialResponse *commercialInformation;
/**
 TOR information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;
/**
 Avs information. 
 */
@property (readwrite, nonatomic, strong)PLAvsResponse *avsInformation;
/**
 MOTOECommerce information. 
 */
@property (readwrite, nonatomic, strong)PLMotoECommerceResponse *motoECommerceInformation;


@end