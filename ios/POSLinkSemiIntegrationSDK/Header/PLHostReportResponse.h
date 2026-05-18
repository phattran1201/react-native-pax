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
 Host Report Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLHostReportResponse.h"

@interface PLHostReportResponse : PLResponse
/**
 The line number in this package.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *lineNumber;
/**
 Lines message.

LineMessage:line1<US>line2<US>line3<US>...<US>line64, terminal only returns the max line number is 64.

The length of each line length should be less than 32 bytes. 
 */
@property (readwrite, nonatomic, copy)NSArray<NSString *> *linesMessage;
/**
 If host supports various host report, this will be returned.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *reportType;
/**
 The date time of terminal, the format is YYYYMMDDhhmmss.

 Attribute:n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;


@end