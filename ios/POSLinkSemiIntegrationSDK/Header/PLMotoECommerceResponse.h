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
 Response MOTO/E-commerce Information.
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


#if __has_include(<POSLinkAdmin/PLMotoECommerceResponse.h>)
   #import <POSLinkAdmin/PLMotoECommerceResponse.h>
#elif __has_include("PLMotoECommerceResponse.h")
   #import "PLMotoECommerceResponse.h"
#endif



@interface PLMotoECommerceResponse : NSObject
/**
 The value of MOTO/e-Commerce mode.

ECommerceMode is not currently supported.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceMode mode;
/**
 MOTO/e-Commerce transaction type.

This field is not currently supported.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceTransactionType transactionType;
/**
 E-Commerce secure type.

This field is not currently supported.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceSecureType secureType;
/**
 Order number for MOTO/e-Commerce.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *orderNumber;
/**
 Total installments number.

This field is not currently supported.

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *installments;
/**
 Current installment number.

This field is not currently supported.

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *currentInstallment;

@end