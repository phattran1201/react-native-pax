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
 Camera Scan Request
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


#if __has_include(<POSLinkAdmin/PLCameraScanRequest.h>)
   #import <POSLinkAdmin/PLCameraScanRequest.h>
#elif __has_include("PLCameraScanRequest.h")
   #import "PLCameraScanRequest.h"
#endif



@interface PLCameraScanRequest : PLRequest
/**
 Reader. Default is Rear camera.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ReaderType reader;
/**
 Scan Timeout in 100ms. Valid value should be [100, 9999] minimum 10 seconds.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;


@end