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
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLSdButton.h"
#import "PLSdButton.h"
#import "PLSdButton.h"
#import "PLSdButton.h"
#import "PLShowDialogRequest.h"

@interface PLShowDialogRequest : PLRequest
/**
 The display title on terminal

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 The name of button1 on terminal 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button1;
/**
 The name of button2 on terminal 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button2;
/**
 The name of button3 on terminal 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button3;
/**
 The name of button4 on terminal 
 */
@property (readwrite, nonatomic, strong)PLSdButton *button4;
/**
 Timeout in 100ms for waiting text input. Valid value should be [0, 9999].The value of “” means waiting till user canceled or confirmed.The value of “0” means non-blocking mode, only valid when no button.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end