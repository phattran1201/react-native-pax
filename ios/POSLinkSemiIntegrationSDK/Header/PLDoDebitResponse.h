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
 Do debit transaction response.
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


#if __has_include(<POSLinkAdmin/PLTaxDetail.h>)
   #import <POSLinkAdmin/PLTaxDetail.h>
#elif __has_include("PLTaxDetail.h")
   #import "PLTaxDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostCredentialResponse.h>)
   #import <POSLinkAdmin/PLHostCredentialResponse.h>
#elif __has_include("PLHostCredentialResponse.h")
   #import "PLHostCredentialResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLTorResponse.h>)
   #import <POSLinkAdmin/PLTorResponse.h>
#elif __has_include("PLTorResponse.h")
   #import "PLTorResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLVasResponse.h>)
   #import <POSLinkAdmin/PLVasResponse.h>
#elif __has_include("PLVasResponse.h")
   #import "PLVasResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLSignatureResponse.h>)
   #import <POSLinkAdmin/PLSignatureResponse.h>
#elif __has_include("PLSignatureResponse.h")
   #import "PLSignatureResponse.h"
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


#if __has_include(<POSLinkAdmin/PLPaymentEmvTag.h>)
   #import <POSLinkAdmin/PLPaymentEmvTag.h>
#elif __has_include("PLPaymentEmvTag.h")
   #import "PLPaymentEmvTag.h"
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


#if __has_include(<POSLinkAdmin/PLPaymentTransactionInformation.h>)
   #import <POSLinkAdmin/PLPaymentTransactionInformation.h>
#elif __has_include("PLPaymentTransactionInformation.h")
   #import "PLPaymentTransactionInformation.h"
#endif


#if __has_include(<POSLinkAdmin/PLRestaurant.h>)
   #import <POSLinkAdmin/PLRestaurant.h>
#elif __has_include("PLRestaurant.h")
   #import "PLRestaurant.h"
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


#if __has_include(<POSLinkAdmin/PLDoDebitResponse.h>)
   #import <POSLinkAdmin/PLDoDebitResponse.h>
#elif __has_include("PLDoDebitResponse.h")
   #import "PLDoDebitResponse.h"
#endif



@interface PLDoDebitResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostInformationResponse *hostInformation;
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
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
 Restaurant information. 
 */
@property (readwrite, nonatomic, strong)PLRestaurant *restaurant;
/**
 Transaction information.
 @deprecated Since V2.01.00. 
 */
@property (readwrite, nonatomic, strong)PLPaymentTransactionInformation *paymentTransactionInformation __attribute__((deprecated("Deprecated since V2.01.00")));
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
@property (readwrite, nonatomic, strong)PLPaymentEmvTag *paymentEmvTag;
/**
 Fleet card information.
 @deprecated Since V2.02.00. 
 */
@property (readwrite, nonatomic, strong)PLFleetCardResponse *fleetCard __attribute__((deprecated("Deprecated since V2.02.00")));
/**
 Signature response information. 
 */
@property (readwrite, nonatomic, strong)PLSignatureResponse *signatureInformation;
/**
 VAS information. 
 */
@property (readwrite, nonatomic, strong)PLVasResponse *vasInformation;
/**
 TOR information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;
/**
 Response Host Credential Information. 
 */
@property (readwrite, nonatomic, strong)PLHostCredentialResponse *hostCredentialInformation;
/**
 Returns the approved tax amounts to be printed on the receipt. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLTaxDetail *> *taxDetails;
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