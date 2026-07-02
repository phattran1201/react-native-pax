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
 Tip Amount.
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


#if __has_include(<POSLinkAdmin/PLTipAmount.h>)
   #import <POSLinkAdmin/PLTipAmount.h>
#elif __has_include("PLTipAmount.h")
   #import "PLTipAmount.h"
#endif



@interface PLTipAmount : NSObject
/**
 Credit Tip Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *creditTipAmount;
/**
 Debit Tip Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *debitTipAmount;
/**
 Gift Tip Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *giftTipAmount;
/**
 Loyalty Tip Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *loyaltyTipAmount;
/**
 Cash Tip Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *cashTipAmount;
/**
 QR Code Tip Amount.

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *qrCodeTipAmount;

@end