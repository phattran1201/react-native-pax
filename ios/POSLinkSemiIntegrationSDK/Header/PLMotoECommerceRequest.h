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
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLMotoECommerceRequest.h"

@interface PLMotoECommerceRequest : NSObject
/**
 The value of MOTO/e-Commerce mode.

ECommerceMode is not support at now. 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceMode mode;
/**
 MOTO/e-Commerce transaction type.

Note: this field doesn't support at now. 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceTransactionType transactionType;
/**
 E-Commerce secure type

Not valid when Moto/e-Commerce mode is MailOrderMode or TeleOrderMode. 
 */
@property (readwrite, nonatomic, assign)enum MotoECommerceSecureType secureType;
/**
 Order number for MOTO/e-Commerce.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *orderNumber;
/**
 Total installments number.

 Attribute:n...3 
 */
@property (readwrite, nonatomic, copy)NSString *installments;
/**
 Current installment number.

 Attribute:n...3 
 */
@property (readwrite, nonatomic, copy)NSString *currentInstallment;

@end