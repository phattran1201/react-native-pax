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
 Custom Data Encryption Request
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


#if __has_include(<POSLinkAdmin/PLCustomDataEncryptionRequest.h>)
   #import <POSLinkAdmin/PLCustomDataEncryptionRequest.h>
#elif __has_include("PLCustomDataEncryptionRequest.h")
   #import "PLCustomDataEncryptionRequest.h"
#endif



@interface PLCustomDataEncryptionRequest : PLRequest
/**
 The Encryption Type. 
 */
@property (readwrite, nonatomic, assign)enum CustomDataEncryptionType dataEncryptionType;
/**
 Key Calculation Work Mode. 
 */
@property (readwrite, nonatomic, assign)enum CustomDataWorkMode workMode;
/**
 Key Index of key in PED: If the type is DES/TDES, it means TDK index, the range is [1,99].

 Attribute : n...3 
 */
@property (readwrite, nonatomic, copy)NSString *keyIndex;
/**
 The data needs Encryption: the length is less than 1024 bytes and hex string is 2048. The data should be divisible by 8.

 Attribute : ans...2048 
 */
@property (readwrite, nonatomic, copy)NSString *userData;
/**
 Initial vector for CBC mode: it should be 8 bytes and the default is "0000000000000000".

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *iVector;


@end