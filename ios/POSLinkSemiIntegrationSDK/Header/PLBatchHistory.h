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
 Batch History.
 */

#import <Foundation/Foundation.h>
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



@interface PLBatchHistory : NSObject
/**
 The batch number.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;
/**
 Settlement date. The format is YYYYMMDDhhmmss.

 Attribute : n14 
 */
@property (readwrite, nonatomic, copy)NSString *settlementDate;

@end