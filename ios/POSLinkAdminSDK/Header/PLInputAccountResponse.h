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
 Input Account Response
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLResponse.h>)
   #import <POSLinkAdmin/PLResponse.h>
#elif __has_include("PLResponse.h")
   #import "PLResponse.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLInputAccountResponse.h>)
   #import <POSLinkAdmin/PLInputAccountResponse.h>
#elif __has_include("PLInputAccountResponse.h")
   #import "PLInputAccountResponse.h"
#endif



@interface PLInputAccountResponse : PLResponse
/**
 Entry mode. Chip, ChipFallBackSwipe, FrontCamera and RearCamera is not support.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum EntryMode entryMode;
/**
 Track1 data (May be encrypted).

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track1Data;
/**
 Track2 data (May be encrypted).

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track2Data;
/**
 Track3 data (May be encrypted).

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track3Data;
/**
 Account Number for if data is available on the card or was entered manually (May be encrypted.)

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *pan;
/**
 The expiration date if data is available on the card or was entered manually, MMYY.

 Attribute : n4 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDate;
/**
 QR code from scanner in plain text.

 Attribute : ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *qrCode;
/**
 The KSN value for account encryption as DUKPT.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *ksn;
/**
 Cardholder name.

 Attribute : ans...45 
 */
@property (readwrite, nonatomic, copy)NSString *cardHolder;
/**
 Encrypted Transmission Block (ETB). Required for decrypting track data encrypted using Voltage E2EE.

Only valid when EncryptionFlag is set to VoltageE2ee.

 Attribute : ans...512 
 */
@property (readwrite, nonatomic, copy)NSString *etb;


@end