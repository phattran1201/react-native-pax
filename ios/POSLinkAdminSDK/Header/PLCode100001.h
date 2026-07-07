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
 Error code 100001
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100001.h>)
   #import <POSLinkAdmin/PLCode100001.h>
#elif __has_include("PLCode100001.h")
   #import "PLCode100001.h"
#endif



@interface PLCode100001 : NSObject
/**
 Time out. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 User doesn't swipe/tap/insert card on card input interface and application times out. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout01;
/**
 User swipe/tap/insert card on card input interface but didn't know what to do and timeout. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout02;
/**
 Timeout for card read (CTLS), but failed processing – retry requested. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout03;
/**
 Timeout for card read (EMV), but failed processing – retry requested. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout04;
/**
 Timeout on account selection. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout05;
/**
 Timeout on PIN entry. 
 */
@property (readwrite, nonatomic, copy)NSString *timeout06;

@end