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
 Tip Count.
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


#if __has_include(<POSLinkAdmin/PLTipCount.h>)
   #import <POSLinkAdmin/PLTipCount.h>
#elif __has_include("PLTipCount.h")
   #import "PLTipCount.h"
#endif



@interface PLTipCount : NSObject
/**
 Credit Tip Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *creditTipCount;
/**
 Debit Tip Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *debitTipCount;
/**
 Gift Tip Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *giftTipCount;
/**
 Loyalty Tip Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *loyaltyTipCount;
/**
 Cash Tip Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cashTipCount;
/**
 QR Code Tip Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *qrCodeTipCount;

@end