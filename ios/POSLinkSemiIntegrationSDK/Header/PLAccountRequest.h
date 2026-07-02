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


#if __has_include(<POSLinkAdmin/PLAccountRequest.h>)
   #import <POSLinkAdmin/PLAccountRequest.h>
#elif __has_include("PLAccountRequest.h")
   #import "PLAccountRequest.h"
#endif



@interface PLAccountRequest : NSObject
/**
 The account number, if this field is NULL, terminal will prompt menu to enter it.

 Attribute : n...65 
 */
@property (readwrite, nonatomic, copy)NSString *account;
/**
 The card expiration date in MMYY format. If this field is null and the transaction needs expiration date, the terminal will prompt a dialog asking the user to enter it. If the ECR sets this field, but the host does not need it for a transaction, it will not be passed in the host request message.

 Attribute : n4 
 */
@property (readwrite, nonatomic, copy)NSString *cardExpireDate;
/**
 The CVV code can be present or NULL, but if CVV is disabled, it must be NULL. Only CREDIT/GIFT supports it.

Each card brand may name the CVV differently, below is the definition:

Visa: CVV2, Length: 3

MasterCard: CVC2, Length: 3

American Express: CID, Length: 4

Discover: CID, Length: 3

JCB: CAV2, Length: 3

Diners: CVV2, Length: 3

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *cvvCode;
/**
 EBT count type.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum EbtCountType ebtType;
/**
 The voucher number, if this field is NULL, terminal will prompt dialog to enter it.

 Attribute : an...16 
 */
@property (readwrite, nonatomic, copy)NSString *voucherNumber;
/**
 First Name of cardholder.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *firstName;
/**
 Last Name of cardholder.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *lastName;
/**
 Two-character ISO 3166 country codes for cardholder.

 Attribute : ans2 
 */
@property (readwrite, nonatomic, copy)NSString *countryCode;
/**
 State/province of customer address. USA/CANADA state/province code.

 Attribute : ans2 
 */
@property (readwrite, nonatomic, copy)NSString *stateCode;
/**
 City of cardholder address.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *cityName;
/**
 Email address of cardholder.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *emailAddress;
/**
 The Gift card type.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum GiftCardType giftCardType;
/**
 The reason why the CVV (for credit) or Gift Card PIN was not entered.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum CvvBypassReason cvvBypassReason;
/**
 The tender type of the account used to activate or reload the gift card.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum GiftTenderType giftTenderType;
/**
 Last 4 digits of account number for original transaction.

Conditional for matching card on terminal in subsequent transactions after Sale, i.e. Return…

 Attribute : n4 
 */
@property (readwrite, nonatomic, copy)NSString *originalPan;
/**
 Expiry date in MMYY of account number for original transaction.

Conditional for matching card on terminal in subsequent transactions after Sale, i.e. Return…

 Attribute : n4 
 */
@property (readwrite, nonatomic, copy)NSString *originalExpiryDate;
/**
 The card type. Required for Multi Token Pay trans for some hosts for Credit/Debit transactions. 
 */
@property (readwrite, nonatomic, assign)enum CardType cardType;
/**
 Enable obtaining unique card identifier.

 Attribute : an...3 
 */
@property (readwrite, nonatomic, assign)enum EnableCardUniqueIdentifier enableCardUniqueIdentifier;

@end