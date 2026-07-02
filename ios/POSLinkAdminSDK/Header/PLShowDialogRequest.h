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
 Show Dialog Request
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


#if __has_include(<POSLinkAdmin/PLSdButton.h>)
   #import <POSLinkAdmin/PLSdButton.h>
#elif __has_include("PLSdButton.h")
   #import "PLSdButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLSdButton.h>)
   #import <POSLinkAdmin/PLSdButton.h>
#elif __has_include("PLSdButton.h")
   #import "PLSdButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLSdButton.h>)
   #import <POSLinkAdmin/PLSdButton.h>
#elif __has_include("PLSdButton.h")
   #import "PLSdButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLSdButton.h>)
   #import <POSLinkAdmin/PLSdButton.h>
#elif __has_include("PLSdButton.h")
   #import "PLSdButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLShowDialogRequest.h>)
   #import <POSLinkAdmin/PLShowDialogRequest.h>
#elif __has_include("PLShowDialogRequest.h")
   #import "PLShowDialogRequest.h"
#endif



@interface PLShowDialogRequest : PLRequest
/**
 The display title on terminal

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 The name of button1 on terminal

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button1;
/**
 The name of button2 on terminal

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button2;
/**
 The name of button3 on terminal

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button3;
/**
 The name of button4 on terminal

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button4;
/**
 Timeout in 100ms for waiting text input. Valid value should be [0, 9999]. The value of "" means waiting till user canceled or confirmed.The value of "0" means non-blocking mode, only valid when no button.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end