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
 Show Text Box Request
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


#if __has_include(<POSLinkAdmin/PLStbButton.h>)
   #import <POSLinkAdmin/PLStbButton.h>
#elif __has_include("PLStbButton.h")
   #import "PLStbButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLStbButton.h>)
   #import <POSLinkAdmin/PLStbButton.h>
#elif __has_include("PLStbButton.h")
   #import "PLStbButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLStbButton.h>)
   #import <POSLinkAdmin/PLStbButton.h>
#elif __has_include("PLStbButton.h")
   #import "PLStbButton.h"
#endif


#if __has_include(<POSLinkAdmin/PLShowTextBoxRequest.h>)
   #import <POSLinkAdmin/PLShowTextBoxRequest.h>
#elif __has_include("PLShowTextBoxRequest.h")
   #import "PLShowTextBoxRequest.h"
#endif



@interface PLShowTextBoxRequest : PLRequest
/**
 The title on terminal.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *title;
/**
 The text to be displayed. Limitation depends on terminal screen size and font size, generally as many as 10 pages can be displayed on terminal.

 Attribute : ans...3072 
 */
@property (readwrite, nonatomic, copy)NSString *text;
/**
 Button1 properties.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLStbButton *button1;
/**
 Button2 properties.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLStbButton *button2;
/**
 Button3 properties.

 Attribute : var 
 */
@property (readwrite, nonatomic, strong)PLStbButton *button3;
/**
 Timeout in 100ms for waiting text input. Valid value should be [0, 9999]. The value of "" means waiting till user canceled or confirmed. The value of "0" means non-blocking mode, only valid when no button or signature box.

 Attribute : n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Whether to disable virtual button displaying. Default is EnableVirtualButtonAndHardKeys.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum EnableKeyType enableKeyType;
/**
 Hard keys list in an array. All hard keys are enabled if this array is empty from POS. 
 */
@property (readwrite, nonatomic, copy)NSArray<NSNumber *> *hardKeyList;
/**
 Signature box. Default is NoSignatureBox.

The signature box should be displayed in the last page before the Button Key display.

If the signature box is displayed, the three buttons will be automatically assigned to "Cancel", "Clear" and "Accept" state.

Signature Box cannot be used with Input Text.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum SignatureBoxType signatureBox;
/**
 Continuous screen.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;
/**
 Barcode name.

It can be Empty or QrCode.

If you specify Barcode Data, currently this field must be QrCode. Otherwise this field should be Empty.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum BarcodeName barcodeName;
/**
 Barcode data.

If you specify Barcode Name, you must specify Barcode Data.

For QrCode, the recommended data length scope is [1, 126].

 Attribute : var 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeData;
/**
 The title in which to be displayed. Default value is empty. Must contain a value if using InputText.

 Attribute : ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *inputTextTitle;
/**
 Input Text. Default is NoInputText.

If the input text is displayed, the three button will be automatically assigned to "Cancel", "Clear" and "Accept" state.

Input Text cannot be used with Signature Box.

Input Text needs an Input Text Title value to be used.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum InputTextType inputText;
/**
 Input type. Default is AlphaNumeric.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum InputType inputType;
/**
 MIN length. Default to 0. Valid value [0, 32].

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *minLength;
/**
 MAX length. Default to 32. Valid value [1, 32].

 Attribute : n...2 
 */
@property (readwrite, nonatomic, copy)NSString *maxLength;


@end