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
 Show Msg Center Aligned Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLShowMessageCenterRequest.h"

@interface PLShowMessageCenterRequest : PLRequest
/**
 Title which defaults to "Thank you for shopping with us!".

 Attribute:ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 Message Line 1 which defaults to "Successful Transaction Authorization".

 Attribute:ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *message1;
/**
 Message Line 2 which defaults to "Please take your receipt".

 Attribute:ans...60 
 */
@property (readwrite, nonatomic, copy)NSString *message2;
/**
 Timeout in 100ms. Valid value should be [0, 9999]. The value of "0" means non-blocking mode.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Pinpad type. Defalut is "InternalPinpad". "ExternalPinpad" and "ExternalPinpadFirst" is A80 only, if use other device will return param error. 
 */
@property (readwrite, nonatomic, assign)enum PinpadType pinpadType;
/**
 ""(empty): No Icon displayed (Default).

pic_smc1: Display's the icon titled pic_smc1 in the terminal. 

pic_smc2: Display's the icon titled pic_smc2 in the terminal.

Please Note:

1. Uploading Show Message Icon Images: This can be done using the UpdateResourceFile command or using TMS. In TMS the parameter will be in the MISC tab in the Image Display Settings section under the Show Message Center Icon "1" or "2". 

2. The icon image file name must be renamed to "pic_smc1" or "pic_smc2" to upload the icon image to TMS or UpdateResource.

3. The icon image's file extension must be .r or .png when uploading it in TMS.

4. When uploading the Icon Image with UpdateResource the file extension will vary based on the terminal.

    1)Android terminals support .png files.

    2)Traditional terminals support .r files.

Please see Terminal Image Formats, Icon Image column for the image's original format required in Reference.

 Attribute:ans...9 
 */
@property (readwrite, nonatomic, copy)NSString *iconName;


@end