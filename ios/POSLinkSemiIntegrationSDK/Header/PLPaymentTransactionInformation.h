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
 Response Payment Transaction Information.
 */

#import <Foundation/Foundation.h>
#import "PLTransactionInformation.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLEwicDetail.h"
#import "PLEwicBalance.h"
#import "PLAdditionalResponseData.h"
#import "PLPaymentTransactionInformation.h"

@interface PLPaymentTransactionInformation : PLTransactionInformation
/**
 The discount amount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *discountAmount;
/**
 The charged amount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *chargedAmount;
/**
 The signature status. 
 */
@property (readwrite, nonatomic, assign)enum SignatureResponseStatus signatureStatus;
/**
 1 means the transaction amount less that Authorization limit and trans is offline approved.

 Attribute:n1 
 */
@property (readwrite, nonatomic, copy)NSString *fps;
/**
 1 means the transaction amount less that Signature limit and no signature on receipt needed. And Signature on MT30 is also not needed.

 Attribute:n1 
 */
@property (readwrite, nonatomic, copy)NSString *fpsSignature;
/**
 FPS Receipt mode. 
 */
@property (readwrite, nonatomic, assign)enum FpsReceipt fpsReceipt;
/**
 Token.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *token;
/**
 Host reference number or (Transaction UID).

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 The serial number of the device.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *sn;
/**
 Transaction settlement date, the format is YYYYMMDD.

 Attribute:n8 
 */
@property (readwrite, nonatomic, copy)NSString *settlementDate;
/**
 Host raw response message.

 Attribute:ans...2048 
 */
@property (readwrite, nonatomic, copy)NSString *hostEchoData;
/**
 PIN entry status. 
 */
@property (readwrite, nonatomic, assign)enum PinEntryStatus pinStatusNumber;
/**
 Validation code.

 Attribute:ans...256 
 */
@property (readwrite, nonatomic, copy)NSString *validationCode;
/**
 Get the user language status. 
 */
@property (readwrite, nonatomic, assign)enum UserLanguage userLanguageStatus;
/**
 An unique ID for each transaction.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *globalUid;
/**
 The original tip amount.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *originalTipAmount;
/**
 The EDC type.

The EDC type returned for CREDIT/DEBIT prompt is on. Once DEBIT selected on terminal for Do Credit command, "DEBIT" as this field will be returned.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *edcType;
/**
 Additional response data. 
 */
@property (readwrite, nonatomic, strong)PLAdditionalResponseData *additionalResponseData;
/**
 Signature data captured by terminal for current.

 Attribute:ans...3072 
 */
@property (readwrite, nonatomic, copy)NSString *signatureData;
/**
 Additional lines for printing from host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine1;
/**
 Additional lines for printing from host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine2;
/**
 Additional lines for printing from host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine3;
/**
 Additional lines for printing from host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine4;
/**
 Additional lines for printing from host.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine5;
/**
 eWIC card expiry Date, format is YYYYMMDD.

 Attribute:n8 
 */
@property (readwrite, nonatomic, copy)NSString *ewicBenefitExpiryDate;
/**
 eWIC Balance information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLEwicBalance *> *ewicBalance;
/**
 eWIC Detail information group. 
 */
@property (readwrite, nonatomic, copy)NSArray<PLEwicDetail *> *ewicDetail;
/**
 Reverse amount, the format is $$$$CC.

 Attribute:n...12 
 */
@property (readwrite, nonatomic, copy)NSString *reverseAmount;
/**
 Reversal status. This field will be returned only when the reversal transaction is partially approved. 
 */
@property (readwrite, nonatomic, assign)enum ReversalStatus reversalStatus;
/**
 It is used to specify the serial number for the account where the card token is stored.

 Attribute:ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *tokenSerialNumber;

@end