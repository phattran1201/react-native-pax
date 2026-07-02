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
 Get card information request.
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


#if __has_include(<POSLinkAdmin/PLAmountRequest.h>)
   #import <POSLinkAdmin/PLAmountRequest.h>
#elif __has_include("PLAmountRequest.h")
   #import "PLAmountRequest.h"
#endif


#if __has_include(<POSLinkAdmin/PLGetCardInformationRequest.h>)
   #import <POSLinkAdmin/PLGetCardInformationRequest.h>
#elif __has_include("PLGetCardInformationRequest.h")
   #import "PLGetCardInformationRequest.h"
#endif



@interface PLGetCardInformationRequest : PLRequest
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Amount information. 
 */
@property (readwrite, nonatomic, strong)PLAmountRequest *amountInformation;
/**
 Enable obtaining unique card identifier.

 Attribute : an...3 
 */
@property (readwrite, nonatomic, assign)enum EnableCardUniqueIdentifier enableCardUniqueIdentifier;


@end