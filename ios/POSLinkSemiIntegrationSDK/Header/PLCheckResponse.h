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
 Response Check Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLCheckResponse.h"

@interface PLCheckResponse : NSObject
/**
 The check sale type.

If the transaction type is "Void" and "Adjust", this field only is Conversion. 
 */
@property (readwrite, nonatomic, assign)enum CheckSaleType saleType;
/**
 Check routing number.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *routingNumber;
/**
 The account number.

 Attribute:n...16 
 */
@property (readwrite, nonatomic, copy)NSString *accountNumber;
/**
 The check number.

 Attribute:n...7 
 */
@property (readwrite, nonatomic, copy)NSString *checkNumber;
/**
 Check type. 
 */
@property (readwrite, nonatomic, assign)enum CheckType checkType;
/**
 ID type. 
 */
@property (readwrite, nonatomic, assign)enum CheckIdType idType;
/**
 ID value.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *idValue;
/**
 Date of birth. MMDDYYYY format.

 Attribute:n8 
 */
@property (readwrite, nonatomic, copy)NSString *birth;
/**
 Phone number.

 Attribute:n...32 
 */
@property (readwrite, nonatomic, copy)NSString *phoneNumber;
/**
 The zip code.

 Attribute:ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *zipCode;

@end