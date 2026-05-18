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
 Purge Batch Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTorResponse.h"
#import "PLHostResponse.h"
#import "PLPurgeBatchResponse.h"

@interface PLPurgeBatchResponse : PLResponse
/**
 Host information. 
 */
@property (readwrite, nonatomic, strong)PLHostResponse *hostInformation;
/**
 The line number in this package.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *lineNumber;
/**
 Lines message.

LineMessage:line1<US>line2<US>line3<US>...<US>line64, terminal only returns the max line number is 64.

The length of each line length should be less than 32 bytes.

 Attribute:ans...2112 
 */
@property (readwrite, nonatomic, copy)NSString *linesMessage;
/**
 The date time, YYYYMMDDhhmmss, If ECR doesn't send time stamp to terminal, this field is mandatory.

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
 TOR information. 
 */
@property (readwrite, nonatomic, strong)PLTorResponse *torInformation;


@end