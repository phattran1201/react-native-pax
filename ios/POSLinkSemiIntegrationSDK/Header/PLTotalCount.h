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
 Total Count. All count do not contain the voided.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTotalCount.h"

@interface PLTotalCount : NSObject
/**
 CreditCount: doesn't contain void and authorization transaction count.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *creditCount;
/**
 DebitCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *debitCount;
/**
 EbtCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *ebtCount;
/**
 GiftCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *giftCount;
/**
 LoyaltyCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *loyaltyCount;
/**
 CashCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cashCount;
/**
 CheckCount

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *checkCount;

@end