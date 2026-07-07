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
 Get Batch History List Response
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


#if __has_include(<POSLinkAdmin/PLBatchHistory.h>)
   #import <POSLinkAdmin/PLBatchHistory.h>
#elif __has_include("PLBatchHistory.h")
   #import "PLBatchHistory.h"
#endif


#if __has_include(<POSLinkAdmin/PLGetBatchHistoryListResponse.h>)
   #import <POSLinkAdmin/PLGetBatchHistoryListResponse.h>
#elif __has_include("PLGetBatchHistoryListResponse.h")
   #import "PLGetBatchHistoryListResponse.h"
#endif



@interface PLGetBatchHistoryListResponse : PLResponse
/**
 The array of latest batch report data (up to last 7 batchs). 
 */
@property (readwrite, nonatomic, copy)NSArray<PLBatchHistory *> *batchHistoryList;


@end