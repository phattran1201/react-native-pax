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
 Transaction Behavior Response.
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


#if __has_include(<POSLinkAdmin/PLTransactionBehaviorResponse.h>)
   #import <POSLinkAdmin/PLTransactionBehaviorResponse.h>
#elif __has_include("PLTransactionBehaviorResponse.h")
   #import "PLTransactionBehaviorResponse.h"
#endif



@interface PLTransactionBehaviorResponse : NSObject
/**
 PIN entry status.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum PinEntryStatus pinStatusNumber;
/**
 Get the user language status.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum UserLanguage userLanguageStatus;

@end