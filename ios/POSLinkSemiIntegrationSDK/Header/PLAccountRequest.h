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
 Request account information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLAccountRequest.h"

@interface PLAccountRequest : NSObject
/**
 The account number, if this field is NULL, terminal will prompt menu to enter it.

 Attribute:n...65 
 */
@property (readwrite, nonatomic, copy)NSString *account;
/**
 Card expire date, MMYY format. If this field is NULL, and host needs expiry date, terminal will prompt dialog to enter it. if ECR send this field, but host doesn't need it, terminal will ignore it.

 Attribute:n4 
 */
@property (readwrite, nonatomic, copy)NSString *cardExpireDate;
/**
 The CVV code, if the switch in terminal turns on, this field can exist or NULL, else it must be NULL. Only CREDIT/GIFT supports it.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cvvCode;
/**
 EBT count type. 
 */
@property (readwrite, nonatomic, assign)enum EbtCountType ebtType;
/**
 The voucher number, if this field is NULL, terminal will prompt dialog to enter it.

 Attribute:an...16 
 */
@property (readwrite, nonatomic, copy)NSString *voucherNumber;
/**
 First Name of cardholder.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *firstName;
/**
 Last Name of cardholder.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *lastName;
/**
 Two-character ISO 3166 country codes for cardholder.

 Attribute:ans2 
 */
@property (readwrite, nonatomic, copy)NSString *countryCode;
/**
 State/province of customer address. USA/CANADA state/province code.

 Attribute:ans2 
 */
@property (readwrite, nonatomic, copy)NSString *stateCode;
/**
 City of cardholder address.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *cityName;
/**
 Email address of cardholder.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *emailAddress;
/**
 The Gift card type. 
 */
@property (readwrite, nonatomic, assign)enum GiftCardType giftCardType;
/**
 The reason why the CVV (for credit) or Gift Card PIN was not entered. 
 */
@property (readwrite, nonatomic, assign)enum CvvBypassReason cvvBypassReason;
/**
 The tender type of the account used to activate or reload the gift card. 
 */
@property (readwrite, nonatomic, assign)enum GiftTenderType giftTenderType;

@end