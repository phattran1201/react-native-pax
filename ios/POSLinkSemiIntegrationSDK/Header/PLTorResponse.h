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
 "Response TOR Information" is the information returned when a reversal is sent. Reversals are sent after a transaction fails due to errors such as a host receive error, "100009 RECEIVE ERROR" or "100003 11-Chip Reject". This information will return in the next Transaction command.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTorResponse.h"

@interface PLTorResponse : NSObject
/**
 Record type. 
 */
@property (readwrite, nonatomic, assign)enum TorRecordType recordType;
/**
 Reversal Transaction timestamp "YYMMDDHHMMSS".

 Attribute:n12 
 */
@property (readwrite, nonatomic, copy)NSString *reversalTimeStamp;
/**
 Host/gateway response code.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *hostResponseCode;
/**
 Host/gateway response Message.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *hostResponseMessage;
/**
 The transaction reference number is returned from a host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 The transaction reference number is returned from a gateway directly.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *gatewayTransactionId;
/**
 Original total amount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *originalAmount;
/**
 The Masked PAN of the card.

Examples:

XXXXXX******XXXX

XXXXXXXX****XXXX

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *maskedPan;
/**
 Batch number.

 Attribute:ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;
/**
 Reversal authorization code.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *reversalAuthorizationCode;
/**
 Original transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType originalTransactionType;
/**
 Original transaction date and time "YYMMDDHHMMSS".

 Attribute:n12 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionDateTime;
/**
 Original transaction authorization code.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionAuthorizationCode;

@end