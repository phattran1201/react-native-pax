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
 Do EBT transaction response.
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLHostCredentialResponse.h"
#import "PLTorResponse.h"
#import "PLVasResponse.h"
#import "PLFleetCardResponse.h"
#import "PLPaymentEmvTag.h"
#import "PLMultiMerchant.h"
#import "PLCardInformation.h"
#import "PLEwicDetail.h"
#import "PLEwicBalance.h"
#import "PLAdditionalResponseData.h"
#import "PLPaymentTransactionInformation.h"
#import "PLRestaurant.h"
#import "PLTraceResponse.h"
#import "PLAccountResponse.h"
#import "PLAmountResponse.h"
#import "PLHostResponse.h"
#import "PLDoEbtResponse.h"

@interface PLDoEbtResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostResponse *hostInformation;
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
 */
@property (readwrite, nonatomic, strong)PLPaymentTransactionInformation *paymentTransactionInformation;
/**
 Card information. 
 */
@property (readwrite, nonatomic, strong)PLCardInformation *cardInformation;
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
 */
@property (readwrite, nonatomic, strong)PLFleetCardResponse *fleetCard;
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


@end