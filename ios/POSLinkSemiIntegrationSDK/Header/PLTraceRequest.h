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
 Request trace information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTraceRequest.h"

@interface PLTraceRequest : NSObject
/**
 The ECR reference number which is an unique code in ECR side.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *ecrReferenceNumber;
/**
 The ECR invoice number.

 Attribute:ans...35 
 */
@property (readwrite, nonatomic, copy)NSString *invoiceNumber;
/**
 The host authorization code, the transaction type is "Forced", this field is NULL, terminal will prompt dialog to enter it.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCode;
/**
 The transaction record number in the terminal, required for follow up transactions after Sale/ Authorization/ Return..., i.e. Void/PostAuthorization, terminal will prompt user to enter this if this field is NULL.

0 < Index <= 5000, normal data base.

5000 < Index <= 9000, stored data base for SAF.

9000 < Index <= 9999, failed data base for SAF.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *originalReferenceNumber;
/**
 The date time, YYYYMMDDhhmmss, if this field is NULL, terminal will use local time.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 ECR transaction ID, unique code in ECR side. Please check POSLink-Reference-Host Specific Remarks for details about field attributes.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *ecrTransactionId;
/**
 Original ECR reference number from POS system.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *originalEcrReferenceNumber;
/**
 Original trace number which is returned in response host information.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *originalTraceNumber;
/**
 Transaction Identifier of the previous or original transaction. It's used for Credential/Card on File (CoF) transactions.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionIdentifier;

@end