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
 Signature request information.
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


#if __has_include(<POSLinkAdmin/PLSignatureRequest.h>)
   #import <POSLinkAdmin/PLSignatureRequest.h>
#elif __has_include("PLSignatureRequest.h")
   #import "PLSignatureRequest.h"
#endif



@interface PLSignatureRequest : NSObject
/**
 The ECR supports signature printing and terminal supports signature capture.

Default is NotCapture.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SignatureCaptureFlag signatureCaptureFlag;
/**
 Whether to upload the signature.

If this tag is not sent to POS, terminal will upload the signature by default when signature uploading is supported by host.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SignatureUploadFlag signatureUploadFlag;
/**
 Whether to acquire the signature data in payment response.

Default is NotRequired.

 Attribute : n8 
 */
@property (readwrite, nonatomic, assign)enum SignatureAcquireFlag signatureAcquireFlag;

@end