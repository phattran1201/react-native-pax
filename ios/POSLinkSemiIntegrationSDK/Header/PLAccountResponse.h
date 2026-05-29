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
 Response Account Information.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLAccountResponse.h"

@interface PLAccountResponse : NSObject
/**
 The account number, it can return all account number or last 4 digits. If the transaction type is "REPLACE", this field is the old card number. Mandatory when run trans with card holder data.

 Attribute:n...65 
 */
@property (readwrite, nonatomic, copy)NSString *account;
/**
 Entry mode. 
 */
@property (readwrite, nonatomic, assign)enum EntryMode entryMode;
/**
 The expiration date of the account, MMYY, if ECR sends this value or enter from terminal, this field will response to ECR.

 Attribute:n4 
 */
@property (readwrite, nonatomic, copy)NSString *expireDate;
/**
 The EBT transaction type. 
 */
@property (readwrite, nonatomic, assign)enum EbtCountType ebtType;
/**
 The voucher number, if the EDC is EBT and the EBT type is voucher or eWIC voucher, this field is mandatory.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *voucherNumber;
/**
 The new card number, the last 4 digits or all digits.

 Attribute:n...65 
 */
@property (readwrite, nonatomic, copy)NSString *currentAccountNumber;
/**
 Card type. Please see POSLink2.Const.CardType. 
 */
@property (readwrite, nonatomic, assign)enum CardType cardType;
/**
 The card holder name, if the card holder name exists, this field is mandatory.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *cardHolder;
/**
 Please see the host specification for the details, if host returned the value, terminal will response it to ECR.

 Attribute:n...65 
 */
@property (readwrite, nonatomic, copy)NSString *cvdApprovalCode;
/**
 The CVD response message, if host returned message, terminal will return it back to ECR.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *cvdMessage;
/**
 Card present indicator. 
 */
@property (readwrite, nonatomic, assign)enum CardPresentIndicator cardPresentIndicator;
/**
 The Gift card type. 
 */
@property (readwrite, nonatomic, assign)enum GiftCardType giftCardType;
/**
 Debit Account Type. 
 */
@property (readwrite, nonatomic, assign)enum DebitAccountType debitAccountType;
/**
 Returned by the host, last 4 digits of account number for transaction.

 Attribute:n4 
 */
@property (readwrite, nonatomic, copy)NSString *hostAccount;
/**
 Returned by the host, the card type used in the transaction.

 Attribute:n2 
 */
@property (readwrite, nonatomic, copy)NSString *hostCardType;
/**
 Track1 data used to return nonpayment card track data.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track1Data;
/**
 Track2 data used to return nonpayment card track data.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track2Data;
/**
 Track3 data used to return nonpayment card track data.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track3Data;

@end