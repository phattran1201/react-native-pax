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
 Error code 100004
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100004.h>)
   #import <POSLinkAdmin/PLCode100004.h>
#elif __has_include("PLCode100004.h")
   #import "PLCode100004.h"
#endif



@interface PLCode100004 : NSObject
/**
 The transaction type is not supported by the Host. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportTransaction;
/**
 The Original Transaction Type is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportOriginalTransactionType;
/**
 The transaction type is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportTransactionType;

@end