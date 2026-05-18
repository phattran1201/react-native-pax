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
 Saf Upload Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTorResponse.h"
#import "PLSafUploadResponse.h"

@interface PLSafUploadResponse : PLResponse
/**
 Total number of new SAF records (exclude old records).

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safTotalCount;
/**
 Total amount for all the new SAF records (exclude old records).

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *safTotalAmount;
/**
 The date time, YYYYMMDDhhmmss, If ECR doesn't send time stamp to terminal, this field is mandatory.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 Number of successful approved uploaded records.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safUploadedCount;
/**
 Amount of successful approved uploaded records.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *safUploadedAmount;
/**
 Number of failed records during the uploading process.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safFailedCount;
/**
 Number of total records in failed Database after the uploading process.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *safFailedTotal;
/**
 TOR information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;


@end