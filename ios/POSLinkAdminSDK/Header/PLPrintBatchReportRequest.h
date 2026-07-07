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
 Print Batch Report Request
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLPrintBatchReportRequest.h>)
   #import <POSLinkAdmin/PLPrintBatchReportRequest.h>
#elif __has_include("PLPrintBatchReportRequest.h")
   #import "PLPrintBatchReportRequest.h"
#endif



@interface PLPrintBatchReportRequest : PLRequest
/**
 The batch number from batch history list. If this value is empty, terminal will return current batch report.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;
/**
 Print flag. 
 */
@property (readwrite, nonatomic, assign)enum BatchReportPrintFlag printFlag;


@end