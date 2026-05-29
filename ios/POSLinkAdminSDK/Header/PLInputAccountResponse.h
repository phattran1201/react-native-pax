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
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLInputAccountResponse.h"

@interface PLInputAccountResponse : PLResponse
/**
 Entry mode. Chip, ChipFallBackSwipe, FrontCamera and RearCamera is not support. 
 */
@property (readwrite, nonatomic, assign)enum EntryMode entryMode;
/**
 Track1 data (May be encrypted).

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track1Data;
/**
 Track2 data (May be encrypted).

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track2Data;
/**
 Track3 data (May be encrypted).

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *track3Data;
/**
 Account Number for manual entry (May be encrypted).

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *pan;
/**
 The expiration date for manual entry, MMYY.

 Attribute:n4 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDate;
/**
 QR code from scanner in plain text.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *qrCode;
/**
 The KSN value for account encryption as DUKPT.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *ksn;
/**
 Card holder name.

 Attribute:ans...45 
 */
@property (readwrite, nonatomic, copy)NSString *cardHolder;


@end