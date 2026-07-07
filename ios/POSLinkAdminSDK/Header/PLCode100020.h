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
 Error code 100020
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100020.h>)
   #import <POSLinkAdmin/PLCode100020.h>
#elif __has_include("PLCode100020.h")
   #import "PLCode100020.h"
#endif



@interface PLCode100020 : NSObject
/**
 Swipe error 
 */
@property (readwrite, nonatomic, copy)NSString *swipeError;
/**
 Can't adjust tip 
 */
@property (readwrite, nonatomic, copy)NSString *cannotAdjust;

@end