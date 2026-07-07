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
 Do debit transaction request.
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


#if __has_include(<POSLinkAdmin/PLFsaData.h>)
   #import <POSLinkAdmin/PLFsaData.h>
#elif __has_include("PLFsaData.h")
   #import "PLFsaData.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostTraceRequest.h>)
   #import <POSLinkAdmin/PLHostTraceRequest.h>
#elif __has_include("PLHostTraceRequest.h")
   #import "PLHostTraceRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLSignatureRequest.h>)
   #import <POSLinkAdmin/PLSignatureRequest.h>
#elif __has_include("PLSignatureRequest.h")
   #import "PLSignatureRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLTaxDetail.h>)
   #import <POSLinkAdmin/PLTaxDetail.h>
#elif __has_include("PLTaxDetail.h")
   #import "PLTaxDetail.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostCredentialRequest.h>)
   #import <POSLinkAdmin/PLHostCredentialRequest.h>
#elif __has_include("PLHostCredentialRequest.h")
   #import "PLHostCredentialRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLLodgingItem.h>)
   #import <POSLinkAdmin/PLLodgingItem.h>
#elif __has_include("PLLodgingItem.h")
   #import "PLLodgingItem.h"
#endif


#if __has_include(<POSLinkAdmin/PLRoomRate.h>)
   #import <POSLinkAdmin/PLRoomRate.h>
#elif __has_include("PLRoomRate.h")
   #import "PLRoomRate.h"
#endif


#if __has_include(<POSLinkAdmin/PLLodging.h>)
   #import <POSLinkAdmin/PLLodging.h>
#elif __has_include("PLLodging.h")
   #import "PLLodging.h"
#endif


#if __has_include(<POSLinkAdmin/PLMultiMerchant.h>)
   #import <POSLinkAdmin/PLMultiMerchant.h>
#elif __has_include("PLMultiMerchant.h")
   #import "PLMultiMerchant.h"
#endif


#if __has_include(<POSLinkAdmin/PLFleetData.h>)
   #import <POSLinkAdmin/PLFleetData.h>
#elif __has_include("PLFleetData.h")
   #import "PLFleetData.h"
#endif


#if __has_include(<POSLinkAdmin/PLFleetCardRequest.h>)
   #import <POSLinkAdmin/PLFleetCardRequest.h>
#elif __has_include("PLFleetCardRequest.h")
   #import "PLFleetCardRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLOriginal.h>)
   #import <POSLinkAdmin/PLOriginal.h>
#elif __has_include("PLOriginal.h")
   #import "PLOriginal.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostInformationRequest.h>)
   #import <POSLinkAdmin/PLHostInformationRequest.h>
#elif __has_include("PLHostInformationRequest.h")
   #import "PLHostInformationRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLTransactionPromptBitmap.h>)
   #import <POSLinkAdmin/PLTransactionPromptBitmap.h>
#elif __has_include("PLTransactionPromptBitmap.h")
   #import "PLTransactionPromptBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLEntryModeBitmap.h>)
   #import <POSLinkAdmin/PLEntryModeBitmap.h>
#elif __has_include("PLEntryModeBitmap.h")
   #import "PLEntryModeBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLProgramBitmap.h>)
   #import <POSLinkAdmin/PLProgramBitmap.h>
#elif __has_include("PLProgramBitmap.h")
   #import "PLProgramBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardTypeBitmap.h>)
   #import <POSLinkAdmin/PLCardTypeBitmap.h>
#elif __has_include("PLCardTypeBitmap.h")
   #import "PLCardTypeBitmap.h"
#endif


#if __has_include(<POSLinkAdmin/PLTransactionBehaviorRequest.h>)
   #import <POSLinkAdmin/PLTransactionBehaviorRequest.h>
#elif __has_include("PLTransactionBehaviorRequest.h")
   #import "PLTransactionBehaviorRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLRestaurant.h>)
   #import <POSLinkAdmin/PLRestaurant.h>
#elif __has_include("PLRestaurant.h")
   #import "PLRestaurant.h"
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


#if __has_include(<POSLinkAdmin/PLAccountRequest.h>)
   #import <POSLinkAdmin/PLAccountRequest.h>
#elif __has_include("PLAccountRequest.h")
   #import "PLAccountRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLAmountRequest.h>)
   #import <POSLinkAdmin/PLAmountRequest.h>
#elif __has_include("PLAmountRequest.h")
   #import "PLAmountRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLDoDebitRequest.h>)
   #import <POSLinkAdmin/PLDoDebitRequest.h>
#elif __has_include("PLDoDebitRequest.h")
   #import "PLDoDebitRequest.h"
#endif



@interface PLDoDebitRequest : PLRequest
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Amount information. 
 */
@property (readwrite, nonatomic, strong)PLAmountRequest *amountInformation;
/**
 Account information. 
 */
@property (readwrite, nonatomic, strong)PLAccountRequest *accountInformation;
/**
 Trace information. 
 */
@property (readwrite, nonatomic, strong)PLTraceRequest *traceInformation;
/**
 Cashier information. 
 */
@property (readwrite, nonatomic, strong)PLCashierRequest *cashierInformation;
/**
 Restaurant information. 
 */
@property (readwrite, nonatomic, strong)PLRestaurant *restaurant;
/**
 Transaction behavior information. 
 */
@property (readwrite, nonatomic, strong)PLTransactionBehaviorRequest *transactionBehavior;
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostInformationRequest *hostInformation;
/**
 Original information.
 @deprecated Since V2.01.00. 
 */
@property (readwrite, nonatomic, strong)PLOriginal *original __attribute__((deprecated("Deprecated since V2.01.00")));
/**
 Fleet card information.
 @deprecated Since V2.02.00. 
 */
@property (readwrite, nonatomic, strong)PLFleetCardRequest *fleetCard __attribute__((deprecated("Deprecated since V2.02.00")));
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;
/**
 Lodging information. 
 */
@property (readwrite, nonatomic, strong)PLLodging *lodging;
/**
 Host credential information. 
 */
@property (readwrite, nonatomic, strong)PLHostCredentialRequest *hostCredential;
/**
 Used to report the amounts for different Tax Types in the transaction. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLTaxDetail *> *taxDetails;
/**
 Signature information. 
 */
@property (readwrite, nonatomic, strong)PLSignatureRequest *signatureInformation;
/**
 Host Trace information. 
 */
@property (readwrite, nonatomic, strong)PLHostTraceRequest *hostTraceInformation;
/**
 Original transaction type. Used for follow up transactions. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType originalTransactionType;
/**
 Program data for FSA transactions. This includes program data for HSAs and HRAs, as well. 
 */
@property (readwrite, nonatomic, strong)PLFsaData *fsaData;


@end