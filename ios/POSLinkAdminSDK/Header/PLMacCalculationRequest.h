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
 MAC calculation request.
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLMacCalculationRequest.h"

@interface PLMacCalculationRequest : PLRequest
/**
 The data used for MAC Calculation.

The data can be divided into several parts by vertical bar('|'). Use 'Encryption Bitmap' to indicate which parts is encrypted.

Terminal will remove the vertical bars ('|') and decrypt the cipher text, then MAC will be calculated using the decrypted data.

The data is represented in hexadecimal. For example: 3031|4a4b|6061.

 Attribute:ans...4000 
 */
@property (readwrite, nonatomic, copy)NSString *inputData;
/**
 Indicate which parts of input data are encrypted.

0: Plaintext

1: Ciphertext

For example: if input data contain 5 parts. 00101 means the third and the fifth part are ciphertext. Default is 0, means this part is plaintext.

 Attribute:var 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionBitmap;
/**
 Key Index in PED: range is [1, 99].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *macKeySlot;
/**
 MAC calculation mode. SHA1 and SHA256 is not support now. 
 */
@property (readwrite, nonatomic, assign)enum MacWorkMode macWorkMode;
/**
 The key slot used to encrypt input data parts. The key can't be DUKPT key.

 Attribute:n...3 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionKeySlot;
/**
 This is used to indicate what value had been padded on data when encryption. Terminal will remove the padding chars first when calculate MAC.

0: padding 0x00.

F: padding 0xFF.

If this field is empty, terminal won't remove the padding chars.

 Attribute:an1 
 */
@property (readwrite, nonatomic, copy)NSString *paddingChar;
/**
 The type of the key which is used to calculate MAC value. AesDukptKey and HMAC is not support. 
 */
@property (readwrite, nonatomic, assign)enum MacKeyType macKeyType;
/**
 Indicate whether to increase KSN, when MAC key type is 1(DUKPT Key).

Default is NotIncrease. 
 */
@property (readwrite, nonatomic, assign)enum KsnFlag ksnFlag;


@end