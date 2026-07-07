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
 Error code 100033
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100033.h>)
   #import <POSLinkAdmin/PLCode100033.h>
#elif __has_include("PLCode100033.h")
   #import "PLCode100033.h"
#endif



@interface PLCode100033 : NSObject
/**
 Swipe entry disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *swipeEntryDisabled;
/**
 Manual entry disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *manualEntryDisabled;

@end