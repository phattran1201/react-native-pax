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
 Custom DataEncryption Response
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


#if __has_include(<POSLinkAdmin/PLCustomDataEncryptionResponse.h>)
   #import <POSLinkAdmin/PLCustomDataEncryptionResponse.h>
#elif __has_include("PLCustomDataEncryptionResponse.h")
   #import "PLCustomDataEncryptionResponse.h"
#endif



@interface PLCustomDataEncryptionResponse : PLResponse
/**
 The Encryption Data out. The max length is 1024 bytes, the Hex string length is 2048.

 Attribute : ans...2048 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionResultData;


@end