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
 Mifare Card Rseponse
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLMifareCardResponse.h"

@interface PLMifareCardResponse : PLResponse
/**
 Only valid when M1 command is "Read" and "ReadTheSerialNumber". The format is HEX and the length is 32.

For example, "01234567890123ABCDEF" means "\x01\x23\x45\x67\x89\x01\x23\xAB\xCD\xEF".

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *blockValue;


@end