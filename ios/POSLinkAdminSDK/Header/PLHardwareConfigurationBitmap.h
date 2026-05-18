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
 Determines what hardware is supported on the device.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLHardwareConfigurationBitmap.h"

@interface PLHardwareConfigurationBitmap : NSObject
/**
 Magstripe.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL magstripe;
/**
 EMV Chip.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL emvChip;
/**
 EMV Contactless/NFC.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL emvContactless;
/**
 Camera-Front.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL cameraFront;
/**
 Laser Scanner.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL laserScanner;
/**
 Camera-Rear.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL cameraRear;
/**
 Printer.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL printer;
/**
 Touchscreen.

true: is present and supported by the application.

false: is not supported or present. 
 */
@property (readwrite, nonatomic, assign)BOOL touchscreen;

@end