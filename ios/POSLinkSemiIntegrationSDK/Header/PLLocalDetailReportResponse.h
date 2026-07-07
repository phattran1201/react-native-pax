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
 Local Detail Report Response
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


#if __has_include(<POSLinkAdmin/PLFpsResponse.h>)
   #import <POSLinkAdmin/PLFpsResponse.h>
#elif __has_include("PLFpsResponse.h")
   #import "PLFpsResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLTransactionBehaviorResponse.h>)
   #import <POSLinkAdmin/PLTransactionBehaviorResponse.h>
#elif __has_include("PLTransactionBehaviorResponse.h")
   #import "PLTransactionBehaviorResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostTraceResponse.h>)
   #import <POSLinkAdmin/PLHostTraceResponse.h>
#elif __has_include("PLHostTraceResponse.h")
   #import "PLHostTraceResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLTorResponse.h>)
   #import <POSLinkAdmin/PLTorResponse.h>
#elif __has_include("PLTorResponse.h")
   #import "PLTorResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLFleetData.h>)
   #import <POSLinkAdmin/PLFleetData.h>
#elif __has_include("PLFleetData.h")
   #import "PLFleetData.h"
#endif


#if __has_include(<POSLinkAdmin/PLFleetCardResponse.h>)
   #import <POSLinkAdmin/PLFleetCardResponse.h>
#elif __has_include("PLFleetCardResponse.h")
   #import "PLFleetCardResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLReportEmvTag.h>)
   #import <POSLinkAdmin/PLReportEmvTag.h>
#elif __has_include("PLReportEmvTag.h")
   #import "PLReportEmvTag.h"
#endif


#if __has_include(<POSLinkAdmin/PLMultiMerchant.h>)
   #import <POSLinkAdmin/PLMultiMerchant.h>
#elif __has_include("PLMultiMerchant.h")
   #import "PLMultiMerchant.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardInformation.h>)
   #import <POSLinkAdmin/PLCardInformation.h>
#elif __has_include("PLCardInformation.h")
   #import "PLCardInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLReportTransactionInformation.h>)
   #import <POSLinkAdmin/PLReportTransactionInformation.h>
#elif __has_include("PLReportTransactionInformation.h")
   #import "PLReportTransactionInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLRestaurant.h>)
   #import <POSLinkAdmin/PLRestaurant.h>
#elif __has_include("PLRestaurant.h")
   #import "PLRestaurant.h"
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


#if __has_include(<POSLinkAdmin/PLLocalDetailReportResponse.h>)
   #import <POSLinkAdmin/PLLocalDetailReportResponse.h>
#elif __has_include("PLLocalDetailReportResponse.h")
   #import "PLLocalDetailReportResponse.h"
#endif



@interface PLLocalDetailReportResponse : PLResponse
/**
 The total number of matching records.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *totalRecord;
/**
 The current reporting record number.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *recordNumber;
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
 Restaurant information. 
 */
@property (readwrite, nonatomic, strong)PLRestaurant *restaurant;
/**
 Report transaction information.
 @deprecated Since V2.01.00. 
 */
@property (readwrite, nonatomic, strong)PLReportTransactionInformation *reportTransactionInformation __attribute__((deprecated("Deprecated since V2.01.00")));
/**
 Card information.
 @deprecated Since V2.01.00. See AccountResponse. 
 */
@property (readwrite, nonatomic, strong)PLCardInformation *cardInformation __attribute__((deprecated("Deprecated since V2.01.00. See AccountResponse")));
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;
/**
 EMV Tag information. 
 */
@property (readwrite, nonatomic, strong)PLReportEmvTag *reportEmvTag;
/**
 Fleet card information. 
 */
@property (readwrite, nonatomic, strong)PLFleetCardResponse *fleetCard;
/**
 TOR information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;
/**
 Host Trace information. 
 */
@property (readwrite, nonatomic, strong)PLHostTraceResponse *hostTraceInformation;
/**
 Transaction Behavior. 
 */
@property (readwrite, nonatomic, strong)PLTransactionBehaviorResponse *transactionBehavior;
/**
 FPS Response Information. 
 */
@property (readwrite, nonatomic, strong)PLFpsResponse *fpsInformation;


@end