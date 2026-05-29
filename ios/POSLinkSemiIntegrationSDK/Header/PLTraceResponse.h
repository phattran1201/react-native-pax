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
 Response Trace Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTraceResponse.h"

@interface PLTraceResponse : NSObject
/**
 The transaction record number in the terminal, suggest printing this on receipt.

0 < Index <= 5000, normal data base.

5000 < Index <= 9000, stored data base for SAF.

9000 < Index <= 9999, failed data base for SAF.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *referenceNumber;
/**
 The ECR reference number, echo back.

 Attribute:an...16 
 */
@property (readwrite, nonatomic, copy)NSString *ecrReferenceNumber;
/**
 The date time, YYYYMMDDhhmmss.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 POS system invoice/tracking number.

 Attribute:ans...35 
 */
@property (readwrite, nonatomic, copy)NSString *invoiceNumber;
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
/**
 ECR transaction ID, unique code in ECR side. Please check POSLink-Reference-Host Specific Remarks for details about field attributes. This field is returned by the host.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *ecrTransactionId;
/**
 Returned by the host, the date and time the transaction occurred in YYYYMMDDHHMMSS format.

 Attribute:n...14 
 */
@property (readwrite, nonatomic, copy)NSString *hostTimeStamp;

@end