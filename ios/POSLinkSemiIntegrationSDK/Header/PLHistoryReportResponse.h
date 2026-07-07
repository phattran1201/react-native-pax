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
 History Report Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif


#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLEdcTotalAmount.h>)
   #import <POSLinkAdmin/PLEdcTotalAmount.h>
#elif __has_include("PLEdcTotalAmount.h")
   #import "PLEdcTotalAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLEdcTotalCount.h>)
   #import <POSLinkAdmin/PLEdcTotalCount.h>
#elif __has_include("PLEdcTotalCount.h")
   #import "PLEdcTotalCount.h"
#endif


#if __has_include(<POSLinkAdmin/PLHistoryReportResponse.h>)
   #import <POSLinkAdmin/PLHistoryReportResponse.h>
#elif __has_include("PLHistoryReportResponse.h")
   #import "PLHistoryReportResponse.h"
#endif



@interface PLHistoryReportResponse : PLResponse
/**
 EDCTotal count 
 */
@property (readwrite, nonatomic, strong)PLEdcTotalCount *edcTotalCount;
/**
 EDC Total amount 
 */
@property (readwrite, nonatomic, strong)PLEdcTotalAmount *edcTotalAmount;
/**
 The date time, YYYYMMDDhhmmss.

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *timeStamp;
/**
 The batch number of last batch.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;


@end