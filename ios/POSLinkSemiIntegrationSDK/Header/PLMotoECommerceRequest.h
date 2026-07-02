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
 Request MOTO/E-commerce information.
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


#if __has_include(<POSLinkAdmin/PLMotoECommerceRequest.h>)
   #import <POSLinkAdmin/PLMotoECommerceRequest.h>
#elif __has_include("PLMotoECommerceRequest.h")
   #import "PLMotoECommerceRequest.h"
#endif



@interface PLMotoECommerceRequest : NSObject
/**
 The MOTO order type for a transaction.

ECommerceMode is not currently supported.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceMode mode;
/**
 The MOTO/e-commerce transaction period type.

This field is not currently supported.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceTransactionType transactionType;
/**
 The e-commerce transaction secure type. This field is not currently supported.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceSecureType secureType;
/**
 The MOTO order number for a transaction.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *orderNumber;
/**
 Total installments number. This field is not currently supported.

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *installments;
/**
 Current installment number. This field is not currently supported.

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *currentInstallment;

@end