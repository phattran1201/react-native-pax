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
 Configure Pin Response
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


#if __has_include(<POSLinkAdmin/PLConfigurePinResponse.h>)
   #import <POSLinkAdmin/PLConfigurePinResponse.h>
#elif __has_include("PLConfigurePinResponse.h")
   #import "PLConfigurePinResponse.h"
#endif



@interface PLConfigurePinResponse : PLResponse
/**
 Host returned the result code, if declined display host error on the ECR's screen.

 Attribute : ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *hostResponseCode;
/**
 Host returned error message. If host returns error message, this field is mandatory.

 Attribute : ans...255 
 */
@property (readwrite, nonatomic, copy)NSString *hostResponseMessage;
/**
 Additional detailed message or code returned from the host.

 Attribute : ans...400 
 */
@property (readwrite, nonatomic, copy)NSString *hostDetailedMessage;


@end