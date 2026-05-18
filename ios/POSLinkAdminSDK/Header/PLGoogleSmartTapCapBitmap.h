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
 Google Smart Tap Capabilities Bitmap.
 */

#import <Foundation/Foundation.h>

#import "PLAdminConst.h"
#import "PLGoogleSmartTapCapBitmap.h"

@interface PLGoogleSmartTapCapBitmap : NSObject
/**
 Stand-alone.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL standAlone;
/**
 Semi-integrated.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL semiIntegrated;
/**
 Unattended.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL unattended;
/**
 Online.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL online;
/**
 Offline.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL offline;
/**
 MMP.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL mmp;
/**
 Zlib support.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL zlibSupport;
/**
 Printer.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL printer;
/**
 Printer graphics.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL printerGraphics;
/**
 Display.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL display;
/**
 Images.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL images;
/**
 Audio.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL audio;
/**
 Animation.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL animation;
/**
 Video.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL video;
/**
 Support payment.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL supportPayment;
/**
 Support digital receipt.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL supportDigitalReceipt;
/**
 Support service issuance.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL supportServiceIssuance;
/**
 Support OTA POS data.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL supportOtaPosData;
/**
 Online PIN.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL onlinePin;
/**
 CD PIN.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL cdPin;
/**
 Signature.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL signature;
/**
 No CVM.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL noCvm;
/**
 Device-generated code.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL deviceGeneratedCode;
/**
 SP-generated code.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL spGeneratedCode;
/**
 ID capture.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL idCapture;
/**
 Bio-metric.

true: support.

false: not support. 
 */
@property (readwrite, nonatomic, assign)BOOL bioMetric;

@end