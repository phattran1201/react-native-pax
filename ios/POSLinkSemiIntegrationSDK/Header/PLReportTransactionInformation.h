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
 Response Report Transaction Information.
 */

#import <Foundation/Foundation.h>
#import "PLTransactionInformation.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLAdditionalResponseData.h"
#import "PLReportTransactionInformation.h"

@interface PLReportTransactionInformation : PLTransactionInformation
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
 Additional response data. 
 */
@property (readwrite, nonatomic, strong)PLAdditionalResponseData *additionalResponseData;

@end