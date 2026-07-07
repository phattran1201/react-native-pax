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
 Signature response information.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLSignatureResponse.h>)
   #import <POSLinkAdmin/PLSignatureResponse.h>
#elif __has_include("PLSignatureResponse.h")
   #import "PLSignatureResponse.h"
#endif



@interface PLSignatureResponse : NSObject
/**
 The signature status.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SignatureResponseStatus signatureStatus;
/**
 Signature data captured by terminal for current.

 Attribute : ans...3072 
 */
@property (readwrite, nonatomic, copy)NSString *signatureData;

@end