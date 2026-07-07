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
 SAF Summary Report Response
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


#if __has_include(<POSLinkAdmin/PLCardTotalAmount.h>)
   #import <POSLinkAdmin/PLCardTotalAmount.h>
#elif __has_include("PLCardTotalAmount.h")
   #import "PLCardTotalAmount.h"
#endif


#if __has_include(<POSLinkAdmin/PLCardTotalCount.h>)
   #import <POSLinkAdmin/PLCardTotalCount.h>
#elif __has_include("PLCardTotalCount.h")
   #import "PLCardTotalCount.h"
#endif


#if __has_include(<POSLinkAdmin/PLSafSummaryReportResponse.h>)
   #import <POSLinkAdmin/PLSafSummaryReportResponse.h>
#elif __has_include("PLSafSummaryReportResponse.h")
   #import "PLSafSummaryReportResponse.h"
#endif



@interface PLSafSummaryReportResponse : PLResponse
/**
 Total count separated by card type. 
 */
@property (readwrite, nonatomic, strong)PLCardTotalCount *cardTotalCount;
/**
 Total Amount separated by card type. 
 */
@property (readwrite, nonatomic, strong)PLCardTotalAmount *cardTotalAmount;


@end