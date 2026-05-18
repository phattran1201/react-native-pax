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
 Host Detail Report Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLHostDetailReportRequest.h"

@interface PLHostDetailReportRequest : PLRequest
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
 Retrieve the transaction record with the matching authorization number.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCode;
/**
 ECR transaction ID, unique code in ECR side.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *ecrTransactionId;
/**
 Host reference number (Transaction UID). This field is host dependent; it can be used to run Void/Return transactions.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;


@end