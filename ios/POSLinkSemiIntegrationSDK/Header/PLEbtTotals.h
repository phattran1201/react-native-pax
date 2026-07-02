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
 EbtTotalData
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


#if __has_include(<POSLinkAdmin/PLEbtTotals.h>)
   #import <POSLinkAdmin/PLEbtTotals.h>
#elif __has_include("PLEbtTotals.h")
   #import "PLEbtTotals.h"
#endif



@interface PLEbtTotals : NSObject
/**
 SaleCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *saleCount;
/**
 SaleAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *saleAmount;
/**
 ReturnCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *returnCount;
/**
 ReturnAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *returnAmount;
/**
 WithdrawalCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *withdrawalCount;
/**
 WithdrawalAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *withdrawalAmount;
/**
 Authorization Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCount;
/**
 Authorization Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationAmount;
/**
 Post Authorization Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *postAuthorizationCount;
/**
 Post Authorization Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *postAuthorizationAmount;

@end