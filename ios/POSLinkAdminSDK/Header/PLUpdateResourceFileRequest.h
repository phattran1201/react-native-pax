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
 Update Resource File Request
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


#if __has_include(<POSLinkAdmin/PLUpdateResourceFileRequest.h>)
   #import <POSLinkAdmin/PLUpdateResourceFileRequest.h>
#elif __has_include("PLUpdateResourceFileRequest.h")
   #import "PLUpdateResourceFileRequest.h"
#endif



@interface PLUpdateResourceFileRequest : PLRequest
/**
 Path of resource zip file. Zip includes images with suffix ".r".

Idle image file's name should be:

1. The Prolin idle image file's name must be "mt30_ad0.r" /"mt30_ad1.r"/"mt30_ad2.r".

2. The Android idle image file's name must be "mt30_ad0.png" /"mt30_ad1.png"/"mt30_ad2.png" (Except the external Android device).

3. The external Android device idle image file's name must be "exdev_idle.png".

The detailed information for uploading an Background/Icon image please refer to Terminal Image Formats in Reference. 
 */
@property (readwrite, nonatomic, copy)NSString *fileUrl;
/**
 File Type. 
 */
@property (readwrite, nonatomic, assign)enum FileType fileType;
/**
 Used to update the firmware of the specified device.

Default is Terminal.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum TargetDevice targetDevice;


@end