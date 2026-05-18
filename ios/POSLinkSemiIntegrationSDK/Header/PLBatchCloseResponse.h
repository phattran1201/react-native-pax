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
 Batch Close Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTorResponse.h"
#import "PLMultiMerchant.h"
#import "PLTotalAmount.h"
#import "PLTotalCount.h"
#import "PLHostResponse.h"
#import "PLBatchCloseResponse.h"

@interface PLBatchCloseResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostResponse *hostInformation;
/**
 Total Count. 
 */
@property (readwrite, nonatomic, strong)PLTotalCount *totalCount;
/**
 Total Amount. 
 */
@property (readwrite, nonatomic, strong)PLTotalAmount *totalAmount;
/**
 The date time, YYYYMMDDhhmmss,	If ECR doesn't send time stamp to terminal, this field is mandatory.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 Terminal ID, If terminal id exists, this field is mandatory.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *tid;
/**
 Merchant ID, if merchant id exists, this field is mandatory.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *mid;
/**
 Multiple merchant information. 
 */
@property (readwrite, nonatomic, strong)PLMultiMerchant *multiMerchant;
/**
 Transaction number for failed transaction in terminal database during the BATCH uploading process for NON SAF transaction.

Batch process is blocked and failed transaction is still in normal database.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *failedTransactionNumber;
/**
 Number of failed records during the BATCH uploading process for NON SAF transaction.

Batch process has not been blocked for failed uploading while failed transaction has been moved to failed database.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *failedCount;
/**
 Number of failed records during the SAF uploading process.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safFailedCount;
/**
 Number of total records in SAF failed Database after the SAF uploading process.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safFailedTotal;
/**
 TOR Information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;


@end