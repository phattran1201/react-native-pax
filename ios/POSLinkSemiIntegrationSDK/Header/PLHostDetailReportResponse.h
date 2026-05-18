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
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLMotoECommerceResponse.h"
#import "PLAvsResponse.h"
#import "PLTorResponse.h"
#import "PLCheckResponse.h"
#import "PLCommercialResponse.h"
#import "PLCashierResponse.h"
#import "PLTraceResponse.h"
#import "PLAccountResponse.h"
#import "PLAmountResponse.h"
#import "PLHostResponse.h"
#import "PLHostDetailReportResponse.h"

@interface PLHostDetailReportResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostResponse *hostInformation;
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
 Check information. 
 */
@property (readwrite, nonatomic, strong)PLCheckResponse *checkInformation;
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