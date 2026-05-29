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
 Session key injection request.
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLSessionKeyInjectionRequest.h"

@interface PLSessionKeyInjectionRequest : PLRequest
/**
 Reserve. Must set to 1 (Terminal Master Key).

 Attribute:n1 
 */
@property (readwrite, nonatomic, copy)NSString *sourceKeyType;
/**
 The source key index should be [1, 99].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *sourceKeyIndex;
/**
 Destination key type. 
 */
@property (readwrite, nonatomic, assign)enum DestinationKeyType destinationKeyType;
/**
 The destination key index should be [1, 99].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *destinationKeyIndex;
/**
 The destination key is the cipher text which encrypted by the source key in the mode of DES/TDES ECB.

Valid key length is 8, 16, 24.

Key data must be in ASCII format. For example, the 8 bytes binary array "\x11\x22\x33\x44\x55\x66\x77\x88" can be converted into "1122334455667788".

 Attribute:an...48 
 */
@property (readwrite, nonatomic, copy)NSString *destinationKeyValue;
/**
 Check Mode. 
 */
@property (readwrite, nonatomic, assign)enum CheckMode checkMode;
/**
 If check mode = NoKcvCheck, PED won't check the buffer (KCV).

If check mode = DesOrTdesEncryptionAndCheckKcv, the buffer(KCV) length should be 4 bytes.

The data must be in ASCII format. For example, the 4 bytes binary array "\x11\x22\x33\x44" can be converted into "11223344".

 Attribute:an...8 
 */
@property (readwrite, nonatomic, copy)NSString *checkBuffer;


@end