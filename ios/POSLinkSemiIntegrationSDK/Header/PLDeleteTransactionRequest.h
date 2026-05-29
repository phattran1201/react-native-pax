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
 Delete Transaction Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLDeleteTransactionRequest.h"

@interface PLDeleteTransactionRequest : PLRequest
/**
 EDC type. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Card type. 
 */
@property (readwrite, nonatomic, assign)enum CardType cardType;
/**
 The log index in terminal.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *recordNumber;
/**
 Retrieve the transaction record with the matching transaction number.

0 < Index <= 5000, normal data base.

5000 < Index <= 9000, stored data base for SAF.

9000 < Index <= 9999, failed data base for SAF.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *originalReferenceNumber;
/**
 Retrieve the transaction record with the matching authorization number.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCode;
/**
 Retrieve the transaction record with the ECR reference number.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *ecrReferenceNumber;
/**
 An unique ID for each transaction.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *globalUid;


@end