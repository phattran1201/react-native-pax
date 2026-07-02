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
 CreditTotalData
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


#if __has_include(<POSLinkAdmin/PLCreditTotals.h>)
   #import <POSLinkAdmin/PLCreditTotals.h>
#elif __has_include("PLCreditTotals.h")
   #import "PLCreditTotals.h"
#endif



@interface PLCreditTotals : NSObject
/**
 SaleCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *saleCount;
/**
 Sale Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *saleAmount;
/**
 ForcedCount

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *forcedCount;
/**
 ForcedAmount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *forcedAmount;
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
/**
 Withdrawal Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *withdrawalCount;
/**
 Withdrawal Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *withdrawalAmount;
/**
 Void Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *voidCount;
/**
 Void Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *voidAmount;
/**
 Void Sale Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *voidSaleCount;
/**
 Void Sale Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *voidSaleAmount;
/**
 Void Authorization Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *voidAuthCount;
/**
 Void Authorization Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *voidAuthAmount;
/**
 Deposit Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *depositCount;
/**
 Deposit Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *depositAmount;
/**
 Payment Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *paymentCount;
/**
 Payment Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *paymentAmount;
/**
 Void Payment Count

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *voidPaymentCount;
/**
 Void Payment Amount

 Attribute : n...9 
 */
@property (readwrite, nonatomic, copy)NSString *voidPaymentAmount;

@end