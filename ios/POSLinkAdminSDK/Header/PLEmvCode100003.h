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
 Error code 100003 for EMV.
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLEmvCode100003.h>)
   #import <POSLinkAdmin/PLEmvCode100003.h>
#elif __has_include("PLEmvCode100003.h")
   #import "PLEmvCode100003.h"
#endif



@interface PLEmvCode100003 : NSObject
/**
 IC card reset failed 
 */
@property (readwrite, nonatomic, copy)NSString *icCardResetFailed;
/**
 [Depreciated]IC card reset failed. Depreciated for error code 101400 - Tap Read Failed. 
 */
@property (readwrite, nonatomic, copy)NSString *icCardResetFailedForReadError;
/**
 IC card blocked. 
 */
@property (readwrite, nonatomic, copy)NSString *icCardBlocked;
/**
 Return code of IC card command is error. 
 */
@property (readwrite, nonatomic, copy)NSString *returnCodeOfIcCardCommandError;
/**
 EMV Application is blocked. 
 */
@property (readwrite, nonatomic, copy)NSString *emvApplicationIsBlocked;
/**
 No matching EMV Application in the IC card. 
 */
@property (readwrite, nonatomic, copy)NSString *noMatchingEmvApplicationInTheIcCard;
/**
 User canceled current operation or transaction. 
 */
@property (readwrite, nonatomic, copy)NSString *userAbort;
/**
 User's operation timed out. 
 */
@property (readwrite, nonatomic, copy)NSString *userTimeout;
/**
 IC card data error. 
 */
@property (readwrite, nonatomic, copy)NSString *icCardDataError;
/**
 Transaction is not accepted 
 */
@property (readwrite, nonatomic, copy)NSString *transactionIsNotAccepted;
/**
 Transaction should be declined by devices according to spec. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionReject;
/**
 CAPK Key Expired. 
 */
@property (readwrite, nonatomic, copy)NSString *capkKeyExpired;
/**
 There's No PIN Pad or PIN Pad can't be used. 
 */
@property (readwrite, nonatomic, copy)NSString *pinPadError;
/**
 Sum of Key Verify is incorrect. 
 */
@property (readwrite, nonatomic, copy)NSString *keyVerifySumIncorrect;
/**
 Unable to find Appointed Data Element. 
 */
@property (readwrite, nonatomic, copy)NSString *unableToFindAppointedDataElement;
/**
 There is no data in the appointed Data Element. 
 */
@property (readwrite, nonatomic, copy)NSString *noDataInTheAppointedDataElement;
/**
 Memory is overflow. 
 */
@property (readwrite, nonatomic, copy)NSString *memoryIsOverflow;
/**
 No transaction log present. 
 */
@property (readwrite, nonatomic, copy)NSString *noTransactionLogPresent;
/**
 Appointed log does not exist. 
 */
@property (readwrite, nonatomic, copy)NSString *appointedLogDoesNotExist;
/**
 Appointed Label does not exist in current log record. 
 */
@property (readwrite, nonatomic, copy)NSString *appointedLabelDoesNotExist;
/**
 Receive Returned Status Code of 6985 in GPO response. 
 */
@property (readwrite, nonatomic, copy)NSString *receive6985InGpoResponse;
/**
 Prompt for card entry method other than contactless. 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessNotAccepted;
/**
 EMV File error. 
 */
@property (readwrite, nonatomic, copy)NSString *emvFileError;
/**
 Must terminate the transaction right now. 
 */
@property (readwrite, nonatomic, copy)NSString *mustTerminateTheTransaction;
/**
 Contactless failed. 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessFailed;
/**
 Transaction should be declined by devices according to spec. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionShouldBeDeclinedByDevices;
/**
 Try another card (DPAS and AMEX). 
 */
@property (readwrite, nonatomic, copy)NSString *tryAnotherCard;
/**
 Parameter error = EMV_PARAM_ERR. EMV Parameter error. 
 */
@property (readwrite, nonatomic, copy)NSString *emvParameterError;
/**
 International transaction(for VISA AP PayWave Level2 IC card use). 
 */
@property (readwrite, nonatomic, copy)NSString *internationalTransaction;
/**
 Wave2 DDA response TLV format error. 
 */
@property (readwrite, nonatomic, copy)NSString *wave2DdaResponseTLVFormatError;
/**
 US card(for VISA AP PayWave L2 IC card use) 
 */
@property (readwrite, nonatomic, copy)NSString *usCard;
/**
 Need to use IC card for the transaction(for VISA PayWave IC card use) 
 */
@property (readwrite, nonatomic, copy)NSString *needToUseIcCardForTheTransaction;
/**
 Need to redo the EMV Application Select. 
 */
@property (readwrite, nonatomic, copy)NSString *needToRedoTheEmvApplicationSelect;
/**
 Contactless IC card has expired. 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessIcCardHasExpired;
/**
 No application is supported(Select PPSE error) 
 */
@property (readwrite, nonatomic, copy)NSString *noApplicationIsSupported;
/**
 Contactless PBOC 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessPboc;
/**
 CVM result in decline for AE 
 */
@property (readwrite, nonatomic, copy)NSString *cvmResultInDeclineForAe;
/**
 Command response with 6986 
 */
@property (readwrite, nonatomic, copy)NSString *commandResponseWith6986;
/**
 The last read record command error. 
 */
@property (readwrite, nonatomic, copy)NSString *theLastReadRecordCommandError;
/**
 Wrong order API calls. 
 */
@property (readwrite, nonatomic, copy)NSString *wrongOrderApiCalls;
/**
 Try Tap Again. 
 */
@property (readwrite, nonatomic, copy)NSString *tryTapAgain;
/**
 PED Timeout. 
 */
@property (readwrite, nonatomic, copy)NSString *pinPadTimeout;
/**
 PED Failure. 
 */
@property (readwrite, nonatomic, copy)NSString *pinPadFailure;
/**
 Contactless offline declined. 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessOfflineDeclined;
/**
 Too many cards present. 
 */
@property (readwrite, nonatomic, copy)NSString *tooManyCardsPresent;
/**
 General contactless error 
 */
@property (readwrite, nonatomic, copy)NSString *generalContactlessError;

@end