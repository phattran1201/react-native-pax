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
 Input Account Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLInputAccountRequest.h"

@interface PLInputAccountRequest : PLRequest
/**
 Whether magnetic card swipe is allowed. 
 */
@property (readwrite, nonatomic, assign)enum PinpadEnableFlag magneticSwipePinpadEnableFlag;
/**
 Whether manual entry is allowed. 
 */
@property (readwrite, nonatomic, assign)enum PinpadEnableFlag manualPinpadEnableFlag;
/**
 Whether contactless entry is allowed. 
 */
@property (readwrite, nonatomic, assign)enum PinpadEnableFlag contactlessPinpadEnableFlag;
/**
 Whether scanner entry is allowed. 
 */
@property (readwrite, nonatomic, assign)enum PinpadEnableFlag scannerPinpadEnableFlag;
/**
 Whether expiry date needs to be prompted during manual entry.

Default is NotNeeded. 
 */
@property (readwrite, nonatomic, assign)enum ExpiryDatePrompt expiryDatePrompt;
/**
 Timeout in 100ms for waiting account entry. Valid value should be [200, 9999].

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;
/**
 Encryption flag.

Default is NotEncrypted. 
 */
@property (readwrite, nonatomic, assign)enum EncryptionFlag encryptionFlag;
/**
 Encryption key slot number.

Monitor(S80,S300,S500,SP30,D210): 1-40.

Prolin(D200,D220, S920,Q20,Q30,Px5,Px7): 1-99.

PayDroid(A60, A80, A920, A930, Aries Series): 1-99.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *keySlot;
/**
 MIN account length. Default to 10. Valid value [1, 32].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *minAccountLength;
/**
 MAX account length. Default to 19. Valid value [1, 32].

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *maxAccountLength;
/**
 EDC type. 
 */
@property (readwrite, nonatomic, assign)enum EdcType edcType;
/**
 Transaction type. 
 */
@property (readwrite, nonatomic, assign)enum TransactionType transactionType;
/**
 Continuous screen. 
 */
@property (readwrite, nonatomic, assign)enum ContinuousScreen continuousScreen;


@end