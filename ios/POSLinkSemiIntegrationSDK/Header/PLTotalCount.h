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
 Total Count. All counts do not contain the voided.
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


#if __has_include(<POSLinkAdmin/PLTotalCount.h>)
   #import <POSLinkAdmin/PLTotalCount.h>
#elif __has_include("PLTotalCount.h")
   #import "PLTotalCount.h"
#endif



@interface PLTotalCount : NSObject
/**
 CreditCount: doesn't contain void and authorization transaction count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *creditCount;
/**
 DebitCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *debitCount;
/**
 EbtCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *ebtCount;
/**
 GiftCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *giftCount;
/**
 LoyaltyCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *loyaltyCount;
/**
 CashCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cashCount;
/**
 QR Code Count.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *qrCodeCount;

@end