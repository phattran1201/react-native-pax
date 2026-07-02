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


#if __has_include(<POSLinkAdmin/PLAccountResponse.h>)
   #import <POSLinkAdmin/PLAccountResponse.h>
#elif __has_include("PLAccountResponse.h")
   #import "PLAccountResponse.h"
#endif



@interface PLAccountResponse : NSObject
/**
 The account number; Can return all of the account number or just the last 4 digits. If the transaction type is "Replace", this field is the old card number. Mandatory when running transactions with cardholder data.

 Attribute : ans...65 
 */
@property (readwrite, nonatomic, copy)NSString *account;
/**
 Entry mode.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum EntryMode entryMode;
/**
 The expiration date of the account, MMYY. If ECR sends this value or it is entered from the terminal, this field will respond to ECR.

 Attribute : n4 
 */
@property (readwrite, nonatomic, copy)NSString *expireDate;
/**
 The EBT transaction type.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum EbtCountType ebtType;
/**
 The voucher number, if the EDC is EBT and the EBT type is voucher or eWIC voucher, this field is mandatory.

 Attribute : ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *voucherNumber;
/**
 The new card number, the last 4 digits or all digits.

 Attribute : ans...65 
 */
@property (readwrite, nonatomic, copy)NSString *currentAccountNumber;
/**
 Card type. Please see POSLink2.Const.CardType. 
 */
@property (readwrite, nonatomic, assign)enum CardType cardType;
/**
 The cardholder name, if the cardholder name exists, this field is mandatory.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *cardHolder;
/**
 Please refer to the host specification for the details. The terminal returns this value back to the ECR if the host returns it.

 Attribute : ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *cvdApprovalCode;
/**
 The CVD response message, if host returned message, terminal will return it back to ECR.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *cvdMessage;
/**
 Card present indicator.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum CardPresentIndicator cardPresentIndicator;
/**
 The Gift card type.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum GiftCardType giftCardType;
/**
 Debit Account Type.

 Attribute : a1 
 */
@property (readwrite, nonatomic, assign)enum DebitAccountType debitAccountType;
/**
 Returned by the host, last 4 digits of account number for transaction.

 Attribute : n4 
 */
@property (readwrite, nonatomic, copy)NSString *hostAccount;
/**
 Returned by the host, the card type used in the transaction.

 Attribute : n2 
 */
@property (readwrite, nonatomic, copy)NSString *hostCardType;
/**
 Track1 data used to return nonpayment card track data.

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track1Data;
/**
 Track2 data used to return nonpayment card track data.

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track2Data;
/**
 Track3 data used to return nonpayment card track data.

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track3Data;
/**
 The card BIN as the leading 6 or 8 digits. If the transaction type is REPLACE, this field is the old card number.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *cardBin;
/**
 The card BIN as the leading 6 or 8 digits. Field is mandatory if the transaction type is REPLACE or MERGE.

For REPLACE, this is the card which replaces the old one.

For MERGE, this is the card which the funds are merged to.

 Attribute : n...8 
 */
@property (readwrite, nonatomic, copy)NSString *updatedCardBin;
/**
 Card program type.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum CardProgramType programType;
/**
 Program specified by the host, specified for Credit.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum HostProgramType hostProgramType;
/**
 Card unique identifier.

 Attribute : n...256 
 */
@property (readwrite, nonatomic, copy)NSString *cardUniqueIdentifier;
/**
 RFU.

 Attribute : n2 
 */
@property (readwrite, nonatomic, copy)NSString *cardCategory;
/**
 Indicate whether the card is a fleet card.

 Attribute : an1 
 */
@property (readwrite, nonatomic, assign)enum FleetCardIndicate fleetCardIndicate;

@end