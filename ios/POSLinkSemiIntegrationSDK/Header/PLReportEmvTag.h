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
 Response Report EMV Tag.
 */

#import <Foundation/Foundation.h>
#import "PLEmvTag.h"
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLReportEmvTag.h"

@interface PLReportEmvTag : PLEmvTag
/**
 Transaction Certificate, tag 9F26. Cryptogram returned by the ICC in response of the GENERATE AC command.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *tc;
/**
 Terminal Verification Results, tag 95. Status of the different functions as seen from the terminal.

 Attribute:ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *tvr;
/**
 Application Dedicated File (ADF) Name, tag 4F. Identifies the application as described in ISO/IEC 7816-5.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *aid;
/**
 Transaction Status Information, tag 9B. Indicates the functions performed in a transaction.

 Attribute:ans...4 
 */
@property (readwrite, nonatomic, copy)NSString *tsi;
/**
 Application Transaction Counter, tag 9F36. Counter maintained by the application in the ICC (incrementing the ATC is managed by the ICC).

 Attribute:ans...4 
 */
@property (readwrite, nonatomic, copy)NSString *atc;
/**
 Application Label, tag 50. Mnemonic associated with the AID according to ISO/IEC 7816-5.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *appLabel;
/**
 Application Preferred Name, tag 9F12. Preferred mnemonic associated with the AID.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *appPreferName;
/**
 Issuer Application Data, tag 9F10. Contains proprietary application data for transmission to the issuer in an online transaction.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *iad;
/**
 Authorization Response Code, tag 8A. Code that defines the disposition of a message. i.e. Contact tag 8A:

Y1: Offline approved.

Y3: Unable to go online, offline approved.

Z1: Offline declined.

Z3: Unable to go online, offline declined.

Other: Online approved or declined.

 Attribute:ans...2 
 */
@property (readwrite, nonatomic, copy)NSString *arc;
/**
 Cryptogram Information Data, tag 9F27. Indicates the type of cryptogram and the actions to be performed by the terminal.

 Attribute:ans...2 
 */
@property (readwrite, nonatomic, copy)NSString *cid;
/**
 Cardholder Verification Method (CVM) Codes. 
 */
@property (readwrite, nonatomic, assign)enum CardholderVerificationMethod cvm;
/**
 Authorisation Request Cryptogram, tag 9F26. Cryptogram returned by the ICC in response of the GENERATE AC command.

 Attribute:ans...16 
 */
@property (readwrite, nonatomic, copy)NSString *arqc;
/**
 Application Primary Account Number (PAN) Sequence Number, tag 5F34. Identifies and differentiates cards with the same PAN.

 Attribute:n2 
 */
@property (readwrite, nonatomic, copy)NSString *panSequenceNumber;

@end