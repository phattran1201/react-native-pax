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
 Do credit transaction request.
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLHostCredential.h"
#import "PLExtraChargeItem.h"
#import "PLAutoRental.h"
#import "PLLodgingItem.h"
#import "PLRoomRate.h"
#import "PLLodging.h"
#import "PLMultiMerchant.h"
#import "PLFleetCardRequest.h"
#import "PLOriginal.h"
#import "PLHostGateway.h"
#import "PLTransactionPromptBitmap.h"
#import "PLEntryModeBitmap.h"
#import "PLProgramBitmap.h"
#import "PLCardTypeBitmap.h"
#import "PLTransactionBehavior.h"
#import "PLRestaurant.h"
#import "PLMotoECommerceRequest.h"
#import "PLTaxDetail.h"
#import "PLLineItemDetail.h"
#import "PLTaxDetail.h"
#import "PLCommercialRequest.h"
#import "PLCashierRequest.h"
#import "PLAvsRequest.h"
#import "PLTraceRequest.h"
#import "PLAccountRequest.h"
#import "PLAmountRequest.h"
#import "PLDoCreditRequest.h"

@interface PLDoCreditRequest : PLRequest
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
 AVS Information. 
 */
@property (readwrite, nonatomic, strong)PLAvsRequest *avsInformation;
/**
 Cashier information. 
 */
@property (readwrite, nonatomic, strong)PLCashierRequest *cashierInformation;
/**
 Commercial information. 
 */
@property (readwrite, nonatomic, strong)PLCommercialRequest *commercialInformation;
/**
 MOTOECommerce information. 
 */
@property (readwrite, nonatomic, strong)PLMotoECommerceRequest *motoECommerceInformation;
/**
 Restaurant information. 
 */
@property (readwrite, nonatomic, strong)PLRestaurant *restaurant;
/**
 Transaction behavior information. 
 */
@property (readwrite, nonatomic, strong)PLTransactionBehavior *transactionBehavior;
/**
 Host gateway information. 
 */
@property (readwrite, nonatomic, strong)PLHostGateway *hostGateway;
/**
 Original information. 
 */
@property (readwrite, nonatomic, strong)PLOriginal *original;
/**
 Fleet card information. 
 */
@property (readwrite, nonatomic, strong)PLFleetCardRequest *fleetCard;
/**
 Multi merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;
/**
 This is the self-definition data for POS developer as long as 2048 bytes. If this field is been set, the PAX terminal won't store and parse the content of this field,and will just follow the host relate specification or POS developer requirement to put it to the request message.

 Attribute:ans...2048 
 */
@property (readwrite, nonatomic, copy)NSString *posEchoData;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;
/**
 Lodging information. 
 */
@property (readwrite, nonatomic, strong)PLLodging *lodging;
/**
 Auto rental information. 
 */
@property (readwrite, nonatomic, strong)PLAutoRental *autoRental;
/**
 Host credential information. 
 */
@property (readwrite, nonatomic, strong)PLHostCredential *hostCredential;


@end