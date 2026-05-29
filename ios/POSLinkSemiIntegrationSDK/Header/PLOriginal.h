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
 Response Original Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLOriginal.h"

@interface PLOriginal : NSObject
/**
 Original Transaction Date in YYYYMMDD format.

Conditional for some hosts for subsequent transactions after Sale, i.e. Return…

If the Host requires this mandatory field, the current date on terminal will be send.

 Attribute:n8 
 */
@property (readwrite, nonatomic, copy)NSString *transactionDate;
/**
 Last 4 digits of account number for original transaction.

Conditional for matching card on terminal in subsequent transactions after Sale, i.e. Return…

 Attribute:n4 
 */
@property (readwrite, nonatomic, copy)NSString *pan;
/**
 Expiry date in MMYY of account number for original transaction.

Conditional for matching card on terminal in subsequent transactions after Sale, i.e. Return…

 Attribute:n4 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDate;
/**
 Original Transaction Time in HHMMSS format.

Conditional for some hosts for subsequent transactions after Sale, i.e. Return…

If the Host requires this mandatory field, the current time on terminal will be send.

 Attribute:n6 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTime;
/**
 Original transaction settlement date, the format is YYYYMMDD.

 Attribute:n8 
 */
@property (readwrite, nonatomic, copy)NSString *settlementDate;
/**
 Original transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 The Original Amount, $$$$$$$CC.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *amount;
/**
 The original batch Number.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;
/**
 Original Payment Service 2000.

Data returned as part of the original authorization response from the issuer, used in follow up transactions (token/card-on-file, reversals, incremental). Format varies by card scheme.

 Attribute:an...22 
 */
@property (readwrite, nonatomic, copy)NSString *paymentService2000;
/**
 Original authorization data used in follow up transactions.

 Attribute:an...66 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationResponse;

@end