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
 Transaction behavior.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLTransactionPromptBitmap.h"
#import "PLEntryModeBitmap.h"
#import "PLProgramBitmap.h"
#import "PLCardTypeBitmap.h"
#import "PLTransactionBehavior.h"

@interface PLTransactionBehavior : NSObject
/**
 The ECR supports signature printing and terminal supports signature capture.

Default is NotCapture. 
 */
@property (readwrite, nonatomic, assign)enum SignatureCaptureFlag signatureCaptureFlag;
/**
 Tip request flag. 
 */
@property (readwrite, nonatomic, assign)enum TipRequestFlag tipRequestFlag;
/**
 Whether to upload the signature.

If this tag is not sent to POS, terminal will upload the signature by default when signature uploading is supported by host. 
 */
@property (readwrite, nonatomic, assign)enum SignatureUploadFlag signatureUploadFlag;
/**
 Whether to report status back. 
 */
@property (readwrite, nonatomic, assign)enum StatusReportFlag statusReportFlag;
/**
 The card type bitmap.

It makes POS system available to control which card types accepted for current command. and it is mandatory for fleet transaction. 
 */
@property (readwrite, nonatomic, strong)PLCardTypeBitmap *acceptedCardType;
/**
 8 digits bitmap for disabling program prompts.

The default prompt is always on and depending on the bin file.  
 */
@property (readwrite, nonatomic, strong)PLProgramBitmap *programPromptsFlag;
/**
 Whether to acquire the signature data in payment response.

Default is NotRequired. 
 */
@property (readwrite, nonatomic, assign)enum SignatureAcquireFlag signatureAcquireFlag;
/**
 The entry mode bitmap. It makes POS system available to control which entry mode accepted for current command.

It makes POS system available to control which entry mode accepted for current command. 
 */
@property (readwrite, nonatomic, strong)PLEntryModeBitmap *entryMode;
/**
 Receipt printing for current command. The default value is NoReceipt. 
 */
@property (readwrite, nonatomic, assign)enum ReceiptPrintFlag receiptPrintFlag;
/**
 Card Present mode. 
 */
@property (readwrite, nonatomic, assign)enum CardPresentMode cardPresentMode;
/**
 Indicate which debit network to use. 
 */
@property (readwrite, nonatomic, assign)enum DebitNetwork debitNetwork;
/**
 User language. 
 */
@property (readwrite, nonatomic, assign)enum UserLanguage userLanguage;
/**
 Additional response data request flag.

Default is No. 
 */
@property (readwrite, nonatomic, assign)enum AdditionalResponseDataFlag additionalResponseDataFlag;
/**
 Force terminal to do commercial transaction flag.

Default is No. 
 */
@property (readwrite, nonatomic, assign)enum ForceCc forceCc;
/**
 Force terminal to do FSA transaction flag.

Default is No. 
 */
@property (readwrite, nonatomic, assign)enum ForceFsa forceFsa;
/**
 Duplicate transaction override flag, if this flag is set to "1" the host will not check for duplicate, also it will override the local duplicate check. If the value is others, host dup check will be controlled by application parameter.

 Attribute:n1 
 */
@property (readwrite, nonatomic, copy)NSString *forceDuplicate;
/**
 The standard of accessibility to support and the status and visibility of "Accessibility Switch" on the Input Account screen. 
 */
@property (readwrite, nonatomic, assign)enum AccessibilityPinPad accessibilityPinPad;
/**
 This is a bitmap that will disable transaction prompts per transaction basis.  
 */
@property (readwrite, nonatomic, strong)PLTransactionPromptBitmap *transactionPromptBitmap;
/**
 Indicates if the transaction is Credential/Card on File (CoF) transaction. Flag will be ignored if the transaction doesn't support CoF feature. 
 */
@property (readwrite, nonatomic, assign)enum CofIndicator cofIndicator;
/**
 Indicates if the credential/card on file (CoF) transaction is customer initiated or merchant initiated. Utilized for subsequent CoF transactions (a token is used to process the transaction), otherwise it will be ignored for other transactions. 
 */
@property (readwrite, nonatomic, assign)enum CofInitiator cofInitiator;

@end