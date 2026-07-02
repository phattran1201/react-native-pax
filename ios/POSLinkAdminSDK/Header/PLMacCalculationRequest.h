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
#if __has_include(<POSLinkAdmin/PLRequest.h>)
   #import <POSLinkAdmin/PLRequest.h>
#elif __has_include("PLRequest.h")
   #import "PLRequest.h"
#endif



#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLMacCalculationRequest.h>)
   #import <POSLinkAdmin/PLMacCalculationRequest.h>
#elif __has_include("PLMacCalculationRequest.h")
   #import "PLMacCalculationRequest.h"
#endif



@interface PLMacCalculationRequest : PLRequest
/**
 The data used for MAC Calculation.

The data can be divided into several parts by vertical bar('|'). Use 'Encryption Bitmap' to indicate which parts are encrypted.

Terminal will remove the vertical bars ('|') and decrypt the cipher text, then MAC will be calculated using the decrypted data.

The data is represented in hexadecimal. For example: 3031|4a4b|6061.

 Attribute : ans...4000 
 */
@property (readwrite, nonatomic, copy)NSString *inputData;
/**
 Indicate which parts of input data are encrypted.

0: Plaintext

1: Ciphertext

For example: if input data contain 5 parts. 00101 means the third and the fifth part are ciphertext. Default is 0, means this part is plaintext.

 Attribute : var 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionBitmap;
/**
 Key Index in PED. For DES Key(MAC Key Type is Tak or DesDukptKey), the range is [1,99]. For AES Key(MAC Key Type from AesDukptKey to Aes256DukptKey), the range is [1,40]

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *macKeySlot;
/**
 The MAC calculation mode. SHA1 and SHA256 hash functions are currently not supported.

 Attribute : var 
 */
@property (readwrite, nonatomic, assign)enum MacWorkMode macWorkMode;
/**
 The key slot used to encrypt input data parts. The key can't be DUKPT key.

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionKeySlot;
/**
 This is used to indicate what value has padded data when encrypting. Terminal will remove the padding chars first when calculating the MAC.

0: padding 0x00.

F: padding 0xFF.

If this field is empty, terminal won't remove the padding chars.

 Attribute : an1 
 */
@property (readwrite, nonatomic, copy)NSString *paddingChar;
/**
 The type of the key which is used to calculate MAC value.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum MacCalculationKeyType macKeyType;
/**
 Indicate whether to increase KSN, when MAC key type is 1(DUKPT Key).

Default is NotIncrease.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum KsnFlag ksnFlag;


@end