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
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLUpdateResourceFileRequest.h"

@interface PLUpdateResourceFileRequest : PLRequest
/**
 Path of resource zip file. Zip includes images with suffix ".r".

Idle image file's name should be:

1. The Prolin idle image file's name must be "mt30_ad0.r" /"mt30_ad1.r"/"mt30_ad2.r".

2. The Android idle image file's name must be "mt30_ad0.png" /"mt30_ad1.png"/"mt30_ad2.png" (Except the extern Android device).

3. The extern Android device idle image file's name must be "exdev_idle.png".

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
 */
@property (readwrite, nonatomic, assign)enum TargetDevice targetDevice;


@end