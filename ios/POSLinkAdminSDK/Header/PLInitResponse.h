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
 Init Response
 */

#import <Foundation/Foundation.h>
#import "PLResponse.h"

#import "PLAdminConst.h"
#import "PLHardwareConfigurationBitmap.h"
#import "PLInitResponse.h"

@interface PLInitResponse : PLResponse
/**
 The serial number of the device.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *sn;
/**
 Model Name.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *modelName;
/**
 OS Version.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *osVersion;
/**
 MAC address for LAN module in text.

 Attribute:ans12 
 */
@property (readwrite, nonatomic, copy)NSString *macAddress;
/**
 Number of lines per screen for ShowMessage command.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *linesPerScreen;
/**
 Number of characters per line for ShowMessage command.

2 types of Numbers:

1: Fix value for terminal models with Matrix Font Lib.

2: Changeable value for terminal models with Vector Font value since the size is depending on the text, so terminal is always taking "W" in capital as the sample text and calculate the numbers.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *charsPerLine;
/**
 Application name.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *appName;
/**
 Application version.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *appVersion;
/**
 WIFI mac address for wifi modules in text.

 Attribute:ans12 
 */
@property (readwrite, nonatomic, copy)NSString *wifiMac;
/**
 Indicates whether terminal use a touchscreen. 
 */
@property (readwrite, nonatomic, assign)enum TouchscreenStatus touchscreen;
/**
 Determines what hardware is supported on the device. 
 */
@property (readwrite, nonatomic, strong)PLHardwareConfigurationBitmap *hardwareConfigurationBitmap;
/**
 Whether the application is activated. If value is Empty, not support. 
 */
@property (readwrite, nonatomic, assign)enum AppActivated appActivated;
/**
 The application license expiration time. MMDDYYYY format.

 Attribute:n...8 
 */
@property (readwrite, nonatomic, copy)NSString *licenseExpiry;
/**
 Protocol Flag. 
 */
@property (readwrite, nonatomic, assign)enum ProtocolFlag protocolFlag;


@end