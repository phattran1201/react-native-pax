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
 Error code 100003
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100003.h>)
   #import <POSLinkAdmin/PLCode100003.h>
#elif __has_include("PLCode100003.h")
   #import "PLCode100003.h"
#endif



@interface PLCode100003 : NSObject
/**
 Message format error 
 */
@property (readwrite, nonatomic, copy)NSString *formatError;
/**
 The protocol version shall be input 
 */
@property (readwrite, nonatomic, copy)NSString *noProtocolVersion;
/**
 Wrong integration mode. 
 */
@property (readwrite, nonatomic, copy)NSString *fullIntegrationOnly;
/**
 Wrong integration mode. 
 */
@property (readwrite, nonatomic, copy)NSString *semiIntegrationOnly;
/**
 Amount invalid.

1.Amount exceeds limit.

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *amountInvalid;
/**
 Tip invalid.

1.Length more than limit

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *tipInvalid;
/**
 Cash back invalid.

1.Cash back amount exceeds limit.

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *cashBackInvalid;
/**
 Merchant fee invalid.

1.Length more than limit

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *merchantFeeInvalid;
/**
 Tax amount invalid.

1.Length more than limit

2.Not number

3. The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *taxAmountInvalid;
/**
 Expiry date invalid.

1.Expiry date length exceeds or is smaller than limit.

2.The month more than 12 or day more than 31

3.Not number 
 */
@property (readwrite, nonatomic, copy)NSString *expDateInvalid;
/**
 EBT type invalid.

1.EBT type length exceeds limit.

2. Not "F" "C" "V" "E" or "W".

3. EBT doesn't support current EBT type. 
 */
@property (readwrite, nonatomic, copy)NSString *ebtTypeInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *voucherInvalid;
/**
 Length more than 16 
 */
@property (readwrite, nonatomic, copy)NSString *referenceInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *invoiceInvalid;
/**
 Auth code length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *authCodeInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *transactionInvalid;
/**
 Timestamp invalid.

1.Length more than limit

2.Not number 

3.Year month day hour minute and second is wrong 
 */
@property (readwrite, nonatomic, copy)NSString *timestampInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *clerkInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *shiftIdInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *poNumberInvalid;
/**
 Customer Code value is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *customerCodeInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *taxReasonInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *taxExemptIdInvalid;
/**
 The MOTO/E-Commerce Mode is not "M" (Mail Order) or "T" (Telephone Order). 
 */
@property (readwrite, nonatomic, copy)NSString *meModeInvalid;
/**
 [Deprecated]Length more than limit, or MOTO/E-Commerce Type Invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *meTypeInvalid;
/**
 [Deprecated]Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *secureTypeInvalid;
/**
 The MOTO Order Number exceeds the maximum specified length. 
 */
@property (readwrite, nonatomic, copy)NSString *orderNumberInvalid;
/**
 [Deprecated]Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *installmentsInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *tableNumberInvalid;
/**
 Guest number exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *guestNumberInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *signInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *ticketNumberInvalid;
/**
 The MOTO/E-Commerce Transaction Type field is not currently supported. 
 */
@property (readwrite, nonatomic, copy)NSString *meTypeNotAllowed;
/**
 The E-Commerce Secure Type field is not currently supported. 
 */
@property (readwrite, nonatomic, copy)NSString *secureTypeNotAllowed;
/**
 EDC or transaction type does not support cashback. 
 */
@property (readwrite, nonatomic, copy)NSString *cashBackNotAllowed;
/**
 The merchant fee parameter is disabled for this EDC or transaction type. 
 */
@property (readwrite, nonatomic, copy)NSString *merchantFeeNotAllowed;
/**
 The commercial card support parameter is disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *commercialNotAllowed;
/**
 Please check the EBT type and the transaction type 
 */
@property (readwrite, nonatomic, copy)NSString *ebtTypeNotAllowed;
/**
 EDC or trans type not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *taxNotAllowed;
/**
 Tip not allowed.

1.EDC or trans type not allowed. 

2.Tip feature is disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *tipNotAllowed;
/**
 Auth code not allowed. 
 */
@property (readwrite, nonatomic, copy)NSString *authCodeNotAllowed;
/**
 EDC or Trans type not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *transactionNotAllowed;
/**
 Amount not allowed for this transaction type. 
 */
@property (readwrite, nonatomic, copy)NSString *amountNotAllowed;
/**
 Industry is not "RESTAURANT". 
 */
@property (readwrite, nonatomic, copy)NSString *tableNumberNotAllowed;
/**
 Guest number not allowed, industry should be "RESTAURANT". 
 */
@property (readwrite, nonatomic, copy)NSString *guestNumberNotAllowed;
/**
 Only retail support 
 */
@property (readwrite, nonatomic, copy)NSString *onlyRetailSupport;
/**
 Merchant fee is only enabled for cashback. 
 */
@property (readwrite, nonatomic, copy)NSString *merchantFeeOnlyForCashback;
/**
 Do “A14”, arguments wrong 
 */
@property (readwrite, nonatomic, copy)NSString *regionArgumentsError;
/**
 EDC or Card type must exist 
 */
@property (readwrite, nonatomic, copy)NSString *edcOrCardTypeMustExist;
/**
 The ECR reference number is missing. 
 */
@property (readwrite, nonatomic, copy)NSString *referenceNoMissing;
/**
 Card type should be empty when EDC type is not Credit 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeOnlyForCredit;
/**
 Card type is not support 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportCardType;
/**
 The length is more than 4 or not number 
 */
@property (readwrite, nonatomic, copy)NSString *indexInvalid;
/**
 No transaction can select. 
 */
@property (readwrite, nonatomic, copy)NSString *noTransactionAvailable;
/**
 EDC type is not EBT. 
 */
@property (readwrite, nonatomic, copy)NSString *ebtInformationInvalid;
/**
 Variable value cannot be “NULL” when calling SETVAR command. 
 */
@property (readwrite, nonatomic, copy)NSString *pleaseSetVar;
/**
 This variable cannot be set. 
 */
@property (readwrite, nonatomic, copy)NSString *hostDenied;
/**
 This length of CVV is invalid or Attribution error 
 */
@property (readwrite, nonatomic, copy)NSString *cvvPromptInvalid;
/**
 The length of zip code is invalid or Attribution error 
 */
@property (readwrite, nonatomic, copy)NSString *zipCodeInvalid;
/**
 The length of address is invalid or Attribution error 
 */
@property (readwrite, nonatomic, copy)NSString *addressInvalid;
/**
 Unsupported CVV or CVV disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *cvvNotAllowed;
/**
 EDC or transaction type does not support zip code. 
 */
@property (readwrite, nonatomic, copy)NSString *zipCodeNotAllowed;
/**
 EDC or transaction type does not support address. 
 */
@property (readwrite, nonatomic, copy)NSString *addressNotAllowed;
/**
 The EDC type must exist. 
 */
@property (readwrite, nonatomic, copy)NSString *edcMissing;
/**
 Unsupported signature. 
 */
@property (readwrite, nonatomic, copy)NSString *signNotAllowed;
/**
 The current transaction amount plus the total amount stored in the terminal exceeds $999,999,999. 
 */
@property (readwrite, nonatomic, copy)NSString *amountTooLarge;
/**
 Unsupported purchase order number. 
 */
@property (readwrite, nonatomic, copy)NSString *poNumberNotSupport;
/**
 Unsupported tax exempt ID 
 */
@property (readwrite, nonatomic, copy)NSString *taxExemptIdNotAllowed;
/**
 Unsupported customer code 
 */
@property (readwrite, nonatomic, copy)NSString *customerCodeNotAllowed;
/**
 Unsupported tax reason 
 */
@property (readwrite, nonatomic, copy)NSString *taxReasonNotAllowed;
/**
 The transaction type must exist. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTypeNull;
/**
 Signature file not found. 
 */
@property (readwrite, nonatomic, copy)NSString *signatureFileNotExist;
/**
 Please check the request length attribute. 
 */
@property (readwrite, nonatomic, copy)NSString *requestLengthInvalid;
/**
 Offset invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *offSizeInvalid;
/**
 Please check the sign flag field. 
 */
@property (readwrite, nonatomic, copy)NSString *signFlagInvalid;
/**
 The EDC unsupported signature. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportSignature;
/**
 Clerk ID invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *clerkIdInvalid;
/**
 Unsupported override flag 
 */
@property (readwrite, nonatomic, copy)NSString *overrideNotAllowed;
/**
 The sent Dup Override Flag is not 1: Enabled. 
 */
@property (readwrite, nonatomic, copy)NSString *dupCheckInvalid;
/**
 Please check the length 
 */
@property (readwrite, nonatomic, copy)NSString *routingNumberInvalid;
/**
 Please check the phone number 
 */
@property (readwrite, nonatomic, copy)NSString *phoneNumberInvalid;
/**
 Please specify EBT type. 
 */
@property (readwrite, nonatomic, copy)NSString *pleaseSpecifyEbtType;
/**
 The transaction tip has already been added. 
 */
@property (readwrite, nonatomic, copy)NSString *alreadyAdded;
/**
 Please do failed report 
 */
@property (readwrite, nonatomic, copy)NSString *pleaseDoFailedReport;
/**
 Please check the “Offset” parameter 
 */
@property (readwrite, nonatomic, copy)NSString *offsetInvalid;
/**
 Please check the “Flag” parameter 
 */
@property (readwrite, nonatomic, copy)NSString *flagInvalid;
/**
 Please check the “Upload flag” parameter 
 */
@property (readwrite, nonatomic, copy)NSString *uploadFlagInvalid;
/**
 Please check the “host reference number” parameter 
 */
@property (readwrite, nonatomic, copy)NSString *referenceNumberInvalid;
/**
 Please check the “host reference number” parameter 
 */
@property (readwrite, nonatomic, copy)NSString *noReferenceNumber;
/**
 Please check the “Timeout” parameter. 
 */
@property (readwrite, nonatomic, copy)NSString *timeoutInvalid;
/**
 Please check the “Image Name” parameter. 
 */
@property (readwrite, nonatomic, copy)NSString *imageNameInvalid;
/**
 Please check the image name. 
 */
@property (readwrite, nonatomic, copy)NSString *noImageName;
/**
 Delete image failed. 
 */
@property (readwrite, nonatomic, copy)NSString *deleteFailed;
/**
 Please check “timeout” parameter. 
 */
@property (readwrite, nonatomic, copy)NSString *noTimeout;
/**
 Please check EDC type field. 
 */
@property (readwrite, nonatomic, copy)NSString *noEdcType;
/**
 Please check EDC type field. 
 */
@property (readwrite, nonatomic, copy)NSString *edcTypeInvalid;
/**
 Please check upload flag field 
 */
@property (readwrite, nonatomic, copy)NSString *noUploadFlag;
/**
 Please check data field. 
 */
@property (readwrite, nonatomic, copy)NSString *dataInvalid;
/**
 Please check the offset field. 
 */
@property (readwrite, nonatomic, copy)NSString *noOffset;
/**
 Install failed. 
 */
@property (readwrite, nonatomic, copy)NSString *installFailed;
/**
 Image not found. 
 */
@property (readwrite, nonatomic, copy)NSString *imageNotFound;
/**
 Please check flag parameter. 
 */
@property (readwrite, nonatomic, copy)NSString *noFlag;
/**
 The tip request flag invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *tipRequestFlagInvalid;
/**
 [Deprecated]Card type is disabled. Deprecated for cardTypeDisabled. 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeDisable;
/**
 Expiry date is missing. 
 */
@property (readwrite, nonatomic, copy)NSString *expDateMissing;
/**
 [Deprecated]Moto/e-commerce mode doesn't support. 
 */
@property (readwrite, nonatomic, copy)NSString *meModeNotSupport;
/**
 Account mismatch 
 */
@property (readwrite, nonatomic, copy)NSString *accountMismatch;
/**
 The command is not supported in demo mode. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportInDemo;
/**
 Expiry date is not allowed. 
 */
@property (readwrite, nonatomic, copy)NSString *expDateNotAllowed;
/**
 Check encryption type. 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionTypeInvalid;
/**
 Check PIN MIN LEN. 
 */
@property (readwrite, nonatomic, copy)NSString *pinMinLengthInvalid;
/**
 Check PIN MAX LEN. 
 */
@property (readwrite, nonatomic, copy)NSString *pinMaxLengthInvalid;
/**
 Check NULL PIN. 
 */
@property (readwrite, nonatomic, copy)NSString *nullPinInvalid;
/**
 Check PIN ALGORITHM. 
 */
@property (readwrite, nonatomic, copy)NSString *pinAlgorithmInvalid;
/**
 Check encryption flag. 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionFlagInvalid;
/**
 Key slot missing. 
 */
@property (readwrite, nonatomic, copy)NSString *keySlotMissing;
/**
 Check length attribute. 
 */
@property (readwrite, nonatomic, copy)NSString *minLengthExceedMaxlen;
/**
 1 entry allowed at least. 
 */
@property (readwrite, nonatomic, copy)NSString *noEntryAllowed;
/**
 The specified card reader cannot be found. 
 */
@property (readwrite, nonatomic, copy)NSString *extCardReaderNotFound;
/**
 Scanner not found. 
 */
@property (readwrite, nonatomic, copy)NSString *scannerNotFound;
/**
 Encryption error. 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionError;
/**
 Title string not defined in title list. 
 */
@property (readwrite, nonatomic, copy)NSString *titleStringNotDefined;
/**
 It needs to void “add tip” transaction first. 
 */
@property (readwrite, nonatomic, copy)NSString *plzVoidAddTip;
/**
 EMV kernel configuration error. 
 */
@property (readwrite, nonatomic, copy)NSString *emvKernelInvalid;
/**
 SAF parameters may be invalid. Check validation of parameters 
 */
@property (readwrite, nonatomic, copy)NSString *safModeValueInvalid;
/**
 Transaction not supported in offline mode. 
 */
@property (readwrite, nonatomic, copy)NSString *notSupportedInOfflineMode;
/**
 More than 1 filter received from POS, like both HRef/OrigRefNum received.

The following cases trigger this error:

1. Receives both HREF and OrigRefNum, and do not match. 

2. In void, adjust, postauth trans, receives both OrigRefNum and AuthCode, and do not match. 

3. When performing REPRINT command, ECRRefNum/RefNum/Authorization Code do not match. 
 */
@property (readwrite, nonatomic, copy)NSString *filterParameterCollision;
/**
 The FSA amount is greater than the total amount when using an FSA card 
 */
@property (readwrite, nonatomic, copy)NSString *fsaAmountExceedLimit;
/**
 No FSA data in PassThruData when using FSA card or FSA amount= 0 when using FSA card 
 */
@property (readwrite, nonatomic, copy)NSString *notAcceptFsaCard;
/**
 Please remove card from the card slot at first 
 */
@property (readwrite, nonatomic, copy)NSString *removeCardFirst;
/**
 The PassThrudata length longer than expected. 
 */
@property (readwrite, nonatomic, copy)NSString *passThrudataInvalid;
/**
 Adjustment not applicable for certain transactions.

1. Partial transactions.

2. FPS transactions.

3. SAF offline mode transactions.

4. PIN less debit transactions approved as credit.

5. Transaction types that don't support tip adjust.

6. When Auto EDC is on, adjustment is not allowed for Debit transactions. 
 */
@property (readwrite, nonatomic, copy)NSString *adjustNotAllowed;
/**
 Host response message's length exceed the application's receive buffer. 
 */
@property (readwrite, nonatomic, copy)NSString *responseLengthExceeded;
/**
 Missing necessary lodging data for lodging related transactions. 
 */
@property (readwrite, nonatomic, copy)NSString *missingLodgingData;
/**
 Host MID is not set. Please set it in Host Setting Menu. 
 */
@property (readwrite, nonatomic, copy)NSString *hostMidNotSet;
/**
 Host User name is not set. Please set it in Host Setting Menu. 
 */
@property (readwrite, nonatomic, copy)NSString *hostUsernameNotSet;
/**
 Host User password is not set. Please set it in Host Setting Menu. 
 */
@property (readwrite, nonatomic, copy)NSString *hostUserPasswordNotSet;
/**
 Transaction is disabled in application. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionDisabled;
/**
 The account number is invalid or could not be parsed. An account number may be invalid due to being non-numeric or being an illegal length. For credit or debit accounts, the account number may possess an invalid Luhn check digit or an unrecognized BIN. 
 */
@property (readwrite, nonatomic, copy)NSString *accountInvalid;
/**
 Account not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *accountNotAllowed;
/**
 Additional item format invalid 
 */
@property (readwrite, nonatomic, copy)NSString *additionalInvalid;
/**
 Check additional response data request 
 */
@property (readwrite, nonatomic, copy)NSString *additionalResponseDataRequestValueInvalid;
/**
 Adjustment by reference number is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *adjustByReferenceNotSupported;
/**
 Check alternate tax amount 
 */
@property (readwrite, nonatomic, copy)NSString *alternateTaxAmountInvalid;
/**
 Check alternate tax ID 
 */
@property (readwrite, nonatomic, copy)NSString *alternateTaxIdInvalid;
/**
 Card expired 
 */
@property (readwrite, nonatomic, copy)NSString *cardExpired;
/**
 Card reader not found 
 */
@property (readwrite, nonatomic, copy)NSString *cardReaderNotFound;
/**
 Check card present mode 
 */
@property (readwrite, nonatomic, copy)NSString *cardPresentModeValueInvalid;
/**
 Card type for credit token only 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeForCreditTokenOnly;
/**
 Card type bitmap for credit only 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeBitmapNotSupported;
/**
 Check card type bitmap 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeBitmapValueInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *cityInvalid;
/**
 [Deprecated]Command is not supported. Deprecated for commandNotSupported. 
 */
@property (readwrite, nonatomic, copy)NSString *commandNotSupport;
/**
 Check continues screen flag 
 */
@property (readwrite, nonatomic, copy)NSString *continuesScreenInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *countryCodeInvalid;
/**
 Credit only, try another tender 
 */
@property (readwrite, nonatomic, copy)NSString *creditOnlyTryAnotherTender;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *customerTaxIdInvalid;
/**
 Debit only, try another tender 
 */
@property (readwrite, nonatomic, copy)NSString *debitOnlyTryAnotherTender;
/**
 Check debit network 
 */
@property (readwrite, nonatomic, copy)NSString *debitNetworkValueInvalid;
/**
 Check default value 
 */
@property (readwrite, nonatomic, copy)NSString *defaultValueInvalid;
/**
 Check destination ZIP code 
 */
@property (readwrite, nonatomic, copy)NSString *destinationZipCodeInvalid;
/**
 Check discount amount 
 */
@property (readwrite, nonatomic, copy)NSString *discountAmountInvalid;
/**
 Check DisProgPrompts 
 */
@property (readwrite, nonatomic, copy)NSString *disProgPromptsValueInvalid;
/**
 Check duty amount 
 */
@property (readwrite, nonatomic, copy)NSString *dutyAmountInvalid;
/**
 Check ECR transaction ID 
 */
@property (readwrite, nonatomic, copy)NSString *ecrTransactionIdInvalid;
/**
 Check Email 
 */
@property (readwrite, nonatomic, copy)NSString *emailInvalid;
/**
 Encryption is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionNotSupported;
/**
 Check entry mode bitmap 
 */
@property (readwrite, nonatomic, copy)NSString *entryModeBitmapValueInvalid;
/**
 Clear SAF failed 
 */
@property (readwrite, nonatomic, copy)NSString *failedDeleted;
/**
 Fallback to swipe 
 */
@property (readwrite, nonatomic, copy)NSString *fallback;
/**
 Fallback to swipe not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *fallbackToSwipeNotAllowed;
/**
 File name exceeds limit or empty. 
 */
@property (readwrite, nonatomic, copy)NSString *fileNameInvalid;
/**
 File not found 
 */
@property (readwrite, nonatomic, copy)NSString *fileNotFound;
/**
 ECRRef and globalUID have conflict 
 */
@property (readwrite, nonatomic, copy)NSString *filterParameterCollisionGlobalUid;
/**
 First name length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *firstNameInvalid;
/**
 [deprecated]The fleet card BIN file is no longer exposed via PAXSTORE TMS. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetCardBinMissing;
/**
 [deprecated]Replaced by 100003 FLEET PRODUCT DATA NOT ALLOWED. PassThru Data is deprecated in POSLink 2. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPassThruDataNotAllowed;
/**
 Check force CC 
 */
@property (readwrite, nonatomic, copy)NSString *forceCcValueInvalid;
/**
 Check force FSA 
 */
@property (readwrite, nonatomic, copy)NSString *forceFsaValueInvalid;
/**
 Check freight amount 
 */
@property (readwrite, nonatomic, copy)NSString *freightAmountInvalid;
/**
 FSA is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *fsaNotSupport;
/**
 Check FSA passThruData 
 */
@property (readwrite, nonatomic, copy)NSString *fsaPassThruDataInvalid;
/**
 FSA passThruData missing 
 */
@property (readwrite, nonatomic, copy)NSString *fsaPassThruDataMissing;
/**
 [deprecated]When BroadPOS receives Fuel Amount during a non-fleet transaction, BroadPOS shall ignore the received value. 
 */
@property (readwrite, nonatomic, copy)NSString *fuelAmountNotAllowed;
/**
 [deprecated]Replaced by 101501 FUEL ONLY. Error code is now unique to match new, similar responses in the same range, such as 101500 PURCHASE RESTRICTED and 101502 FUEL AND MAINTENANCE ONLY. 
 */
@property (readwrite, nonatomic, copy)NSString *fuelOnly;
/**
 Gateway ID length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *gatewayIdInvalid;
/**
 Check get sign 
 */
@property (readwrite, nonatomic, copy)NSString *getSignInvalid;
/**
 Length more than limit or value is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *globalUidInvalid;
/**
 Google Smart Tap is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *googleSmartTapNotSupported;
/**
 Check date format 
 */
@property (readwrite, nonatomic, copy)NSString *indateDateFormatInvalid;
/**
 Check input type 
 */
@property (readwrite, nonatomic, copy)NSString *inputTypeInvalid;
/**
 Install error 
 */
@property (readwrite, nonatomic, copy)NSString *installError;
/**
 The MOTO/E-Commerce Installments field is not currently supported. 
 */
@property (readwrite, nonatomic, copy)NSString *installmentsNotAllowed;
/**
 Card type is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *invalidCardType;
/**
 Check PIN algorithm 
 */
@property (readwrite, nonatomic, copy)NSString *invalidPinAlgorithm;
/**
 Check SAF indicator 
 */
@property (readwrite, nonatomic, copy)NSString *invalidValue;
/**
 Check var value 
 */
@property (readwrite, nonatomic, copy)NSString *invalidVarValue;
/**
 Key slot invalid 
 */
@property (readwrite, nonatomic, copy)NSString *keySlotNotAllowed;
/**
 Last name length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *lastNameInvalid;
/**
 Check last transaction flag 
 */
@property (readwrite, nonatomic, copy)NSString *lastTransactionInvalid;
/**
 Check level 3 data 
 */
@property (readwrite, nonatomic, copy)NSString *level3DataInvalid;
/**
 Check level 3 data format 
 */
@property (readwrite, nonatomic, copy)NSString *level3FormatInvalid;
/**
 Level 3 mandatory field missing 
 */
@property (readwrite, nonatomic, copy)NSString *level3MandatoryFieldMissing;
/**
 Check local tax 
 */
@property (readwrite, nonatomic, copy)NSString *localTaxInvalid;
/**
 There are not enough data items. 
 */
@property (readwrite, nonatomic, copy)NSString *lodgingFormatInvalid;
/**
 Manual entry disabled 
 */
@property (readwrite, nonatomic, copy)NSString *manualEntryDisabled;
/**
 Value more than limit or not integer 
 */
@property (readwrite, nonatomic, copy)NSString *maxLengthInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *posEchoDataSizeExceeded;
/**
 Check merchant decision 
 */
@property (readwrite, nonatomic, copy)NSString *merchantDecisionInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *merchantTaxIdInvalid;
/**
 Check min and max value 
 */
@property (readwrite, nonatomic, copy)NSString *minExceedMax;
/**
 Value more than limit or not integer 
 */
@property (readwrite, nonatomic, copy)NSString *minLengthInvalid;
/**
 Check national tax 
 */
@property (readwrite, nonatomic, copy)NSString *nationalTaxInvalid;
/**
 Card type is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *noCardTypeAvailable;
/**
 No data 
 */
@property (readwrite, nonatomic, copy)NSString *noData;
/**
 Scanner not supported 
 */
@property (readwrite, nonatomic, copy)NSString *notSupportScanner;
/**
 Check PIN bypass flag 
 */
@property (readwrite, nonatomic, copy)NSString *nullPinFlagInvalid;
/**
 Offset more than total size 
 */
@property (readwrite, nonatomic, copy)NSString *offsizeOverlength;
/**
 Online result invalid 
 */
@property (readwrite, nonatomic, copy)NSString *onlineResultInvalid;
/**
 Check order date 
 */
@property (readwrite, nonatomic, copy)NSString *orderDateInvalid;
/**
 Check Original Expiry Date 
 */
@property (readwrite, nonatomic, copy)NSString *originalExpiryDateInvalid;
/**
 Original expiration date entry is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *originalExpiryDateNotSupported;
/**
 Original transaction type missing 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionTypeMissing;
/**
 Check original PAN 
 */
@property (readwrite, nonatomic, copy)NSString *originalPanInvalid;
/**
 Original account number entry is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *originalPanNotSupported;
/**
 Original settlement date entry is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *originalSettlementDateNotSupported;
/**
 Check original settlement date 
 */
@property (readwrite, nonatomic, copy)NSString *originalSettlementDateValueInvalid;
/**
 Check original transaction date 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionDateInvalid;
/**
 Original transaction date is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionDateNotSupported;
/**
 Check original transaction time 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionTimeInvalid;
/**
 Original transaction time not support 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionTimeNotSupported;
/**
 Original transaction type not support 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionTypeNotSupported;
/**
 Check date format 
 */
@property (readwrite, nonatomic, copy)NSString *outdateDateFormatInvalid;
/**
 Out date is less than in date 
 */
@property (readwrite, nonatomic, copy)NSString *outdateIsLessThanIndate;
/**
 Over card type max amount 
 */
@property (readwrite, nonatomic, copy)NSString *overCardtypeMaxAmount;
/**
 Over card type total amount 
 */
@property (readwrite, nonatomic, copy)NSString *overCardtypeTotalAmount;
/**
 Over total amount 
 */
@property (readwrite, nonatomic, copy)NSString *overTotalAmount;
/**
 Over total count 
 */
@property (readwrite, nonatomic, copy)NSString *overTotalCount;
/**
 PAN mismatch 
 */
@property (readwrite, nonatomic, copy)NSString *panMismatch;
/**
 Running Post Auth transaction using reference number is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *postAuthByReferenceNotSupported;
/**
 Check report status flag 
 */
@property (readwrite, nonatomic, copy)NSString *reportStatusFlagInvalid;
/**
 Check return reason 
 */
@property (readwrite, nonatomic, copy)NSString *returnReasonInvalid;
/**
 Return reason entry is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *returnReasonNotSupported;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *roomNoInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *roomRateInvalid;
/**
 SAF not valid 
 */
@property (readwrite, nonatomic, copy)NSString *safNotValid;
/**
 Open scanner failed 
 */
@property (readwrite, nonatomic, copy)NSString *scannerNotOpen;
/**
 Scanner property wrong 
 */
@property (readwrite, nonatomic, copy)NSString *scannerPropWrong;
/**
 Set TLV data failed 
 */
@property (readwrite, nonatomic, copy)NSString *setTlvDataFailed;
/**
 Check ship from ZIP code invalid 
 */
@property (readwrite, nonatomic, copy)NSString *shipFromZipCodeInvalid;
/**
 Check sign upload 
 */
@property (readwrite, nonatomic, copy)NSString *signUploadInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *stateCodeInvalid;
/**
 The length exceeds the maximum or is below the minimum. 
 */
@property (readwrite, nonatomic, copy)NSString *stationNoInvalid;
/**
 Sub healthcare amount exceed limit 
 */
@property (readwrite, nonatomic, copy)NSString *subHealthcareAmountExceedLimit;
/**
 Check sub healthcare amount 
 */
@property (readwrite, nonatomic, copy)NSString *subHealthcareAmountInvalid;
/**
 Check summary commodity code 
 */
@property (readwrite, nonatomic, copy)NSString *summaryCommodityCodeInvalid;
/**
 Surcharge fee not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *surchargeFeeNotAllowed;
/**
 Check tag data 
 */
@property (readwrite, nonatomic, copy)NSString *tagDataError;
/**
 Length more than limit or value not integer 
 */
@property (readwrite, nonatomic, copy)NSString *taxInvalid;
/**
 Check TLV data 
 */
@property (readwrite, nonatomic, copy)NSString *tlvDataError;
/**
 Check TLV data 
 */
@property (readwrite, nonatomic, copy)NSString *tlvTypeError;
/**
 Check token command 
 */
@property (readwrite, nonatomic, copy)NSString *tokenCommandInvalid;
/**
 Token is missing 
 */
@property (readwrite, nonatomic, copy)NSString *tokenIsMissing;
/**
 Tokens are not supported for this transaction. 
 */
@property (readwrite, nonatomic, copy)NSString *tokenNotSupported;
/**
 Check token request flag 
 */
@property (readwrite, nonatomic, copy)NSString *tokenRequestFlagInvalid;
/**
 Token SN entry is not supported for this transaction. 
 */
@property (readwrite, nonatomic, copy)NSString *tokenSnNotSupported;
/**
 Token SN too long 
 */
@property (readwrite, nonatomic, copy)NSString *tokenSnTooLong;
/**
 Token too long 
 */
@property (readwrite, nonatomic, copy)NSString *tokenTooLong;
/**
 Token Request flag is not supported for this transaction. 
 */
@property (readwrite, nonatomic, copy)NSString *tokenRequestNotSupported;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *tooMuchData;
/**
 Track2 missing 
 */
@property (readwrite, nonatomic, copy)NSString *track2Missing;
/**
 Transaction fail 
 */
@property (readwrite, nonatomic, copy)NSString *transactionFail;
/**
 Transit is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *transitNotSupport;
/**
 Upload S&F Failed 
 */
@property (readwrite, nonatomic, copy)NSString *uploadSAndFFailed;
/**
 Upload is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *uploadUnsupport;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *vatInvoiceInvalid;
/**
 Check VAT tax amount 
 */
@property (readwrite, nonatomic, copy)NSString *vatTaxAmountInvalid;
/**
 Check VAT tax rate 
 */
@property (readwrite, nonatomic, copy)NSString *vatTaxRateInvalid;
/**
 Visa card only 
 */
@property (readwrite, nonatomic, copy)NSString *visaCardOnly;
/**
 Visa/MasterCard only 
 */
@property (readwrite, nonatomic, copy)NSString *visaMastercardOnly;
/**
 Void transaction using Host Reference Number is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *voidByReferenceNotSupported;
/**
 Voucher not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *voucherNotAllowed;
/**
 Write file error 
 */
@property (readwrite, nonatomic, copy)NSString *writeFileError;
/**
 The response from host can't be parsed 
 */
@property (readwrite, nonatomic, copy)NSString *messageError;
/**
 Transaction date invalid 
 */
@property (readwrite, nonatomic, copy)NSString *transactionDateInvalid;
/**
 Transaction time invalid 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTimeInvalid;
/**
 Button null 
 */
@property (readwrite, nonatomic, copy)NSString *buttonNull;
/**
 Button type invalid 
 */
@property (readwrite, nonatomic, copy)NSString *buttonTypeInvalid;
/**
 Camera not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *cameraNotSupport;
/**
 The card type is disabled 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeDisabled;
/**
 The card type is missing 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeMissing;
/**
 The card type is only for token 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeForTokenOnly;
/**
 Command is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *commandNotSupported;
/**
 Currency code invalid 
 */
@property (readwrite, nonatomic, copy)NSString *currencyCodeInvalid;
/**
 Currency exponent invalid 
 */
@property (readwrite, nonatomic, copy)NSString *currencyExponentInvalid;
/**
 Date invalid 
 */
@property (readwrite, nonatomic, copy)NSString *dateInvalid;
/**
 Date format invalid 
 */
@property (readwrite, nonatomic, copy)NSString *dateFormatInvalid;
/**
 Days format invalid 
 */
@property (readwrite, nonatomic, copy)NSString *daysFormatInvalid;
/**
 DB error 
 */
@property (readwrite, nonatomic, copy)NSString *dbError;
/**
 Debit only 
 */
@property (readwrite, nonatomic, copy)NSString *debitOnly;
/**
 EMV data encryption error 
 */
@property (readwrite, nonatomic, copy)NSString *emvDataEncryptionError;
/**
 Encryption for INT.PED only 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionForIntPedOnly;
/**
 The Fleet Prompt Code field is non-numeric or is not the expected length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPromptCodeInvalid;
/**
 Form error 
 */
@property (readwrite, nonatomic, copy)NSString *formError;
/**
 Form not found 
 */
@property (readwrite, nonatomic, copy)NSString *formNotFound;
/**
 FSA amount too large 
 */
@property (readwrite, nonatomic, copy)NSString *fsaAmountTooLarge;
/**
 The length of the value is more than 3 or equal to 0. 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndexInvalid;
/**
 Item index quantity invalid 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndexQuantityInvalid;
/**
 Key does not exist. 
 */
@property (readwrite, nonatomic, copy)NSString *keyNotExist;
/**
 Length error.

1.The length of the value exceeds 3.

2.Not integer number. 
 */
@property (readwrite, nonatomic, copy)NSString *lengthError;
/**
 The length of the value should be 4. 
 */
@property (readwrite, nonatomic, copy)NSString *merchantCategoryInvalid;
/**
 The number of items is less than 9. 
 */
@property (readwrite, nonatomic, copy)NSString *messageFormatInvalid;
/**
 MerchantID or MerchantName invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *mmIdOrMmNameInvalid;
/**
 Need remove card first. 
 */
@property (readwrite, nonatomic, copy)NSString *needRemoveCardFirst;
/**
 Label1 is required. 
 */
@property (readwrite, nonatomic, copy)NSString *noLabel;
/**
 [Deprecated]Out of paper. Deprecated for error code 100032 OUT OF PAPER. 
 */
@property (readwrite, nonatomic, copy)NSString *noPaper;
/**
 No internal printer module. 
 */
@property (readwrite, nonatomic, copy)NSString *noPrinter;
/**
 No transaction in database. 
 */
@property (readwrite, nonatomic, copy)NSString *noTransactionInDatabase;
/**
 Need to follow the command order. 
 */
@property (readwrite, nonatomic, copy)NSString *operationNotAllowed;
/**
 [Deprecated]Out of paper. Deprecated for error code 100032 OUT OF PAPER. 
 */
@property (readwrite, nonatomic, copy)NSString *outOfPaper;
/**
 The padding char value only can be “0” or “F”. 
 */
@property (readwrite, nonatomic, copy)NSString *paddingCharInvalid;
/**
 PCI violation. 
 */
@property (readwrite, nonatomic, copy)NSString *pciViolation;
/**
 PIN bypass invalid.

1.The PIN bypass value range of 0~4.

2.Not integer number. 
 */
@property (readwrite, nonatomic, copy)NSString *pinBypassInvalid;
/**
 The PIN min length more than max length. 
 */
@property (readwrite, nonatomic, copy)NSString *pinMinLengthExceedPinMaxLength;
/**
 Please see your mobile phone. The transaction needs to be restarted. 
 */
@property (readwrite, nonatomic, copy)NSString *pleaseSeePhone;
/**
 Print bar code error. 
 */
@property (readwrite, nonatomic, copy)NSString *printBarError;
/**
 Printer data is null. 
 */
@property (readwrite, nonatomic, copy)NSString *printDataInvalid;
/**
 Print error. 
 */
@property (readwrite, nonatomic, copy)NSString *printError;
/**
 Print signature error. 
 */
@property (readwrite, nonatomic, copy)NSString *printEsigError;
/**
 Print logo error. 
 */
@property (readwrite, nonatomic, copy)NSString *printLogoError;
/**
 Printer is disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *printerDisabled;
/**
 Failed to open printer. 
 */
@property (readwrite, nonatomic, copy)NSString *printerError;
/**
 ReceiptPrintType is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *receiptPrintInvalid;
/**
 The show command value out of range. 
 */
@property (readwrite, nonatomic, copy)NSString *showCommandInvalid;
/**
 The tag list is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *tagListInvalid;
/**
 The length of the value more than 32. 
 */
@property (readwrite, nonatomic, copy)NSString *tokenInvalid;
/**
 The value only can be “0” or “1”. 
 */
@property (readwrite, nonatomic, copy)NSString *trackDataSentinelInvalid;
/**
 This command is not supported for full integration. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportCommand;
/**
 This EDC is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportEdc;
/**
 The Odometer field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *odometerInvalid;
/**
 [deprecated]Replaced by 100003 VEHICLENUMBER INVALID. VISA1 field name changed to VEHICLENUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNoInvalid;
/**
 [deprecated]Replaced by 100003 JOBNUMBER INVALID. VISA1 field name changed to JOBNUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *jobNoInvalid;
/**
 The Driver ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *driverIdInvalid;
/**
 [deprecated]Replaced by 100003 EMPLOYEENUMBER INVALID. VISA1 field name changed to EMPLOYEENUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNoInvalid;
/**
 [deprecated]Replaced by 100003 LICENSENUMBER INVALID. VISA1 field name changed to LICENSENUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *licenseNoInvalid;
/**
 The Job ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *jobidInvalid;
/**
 [deprecated]Replaced by 100003 DEPARTMENTNUMBER INVALID. VISA1 field name changed to DEPARTMENTNUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNoInvalid;
/**
 The Customer Data field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *customerDataInvalid;
/**
 The User ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *userIdInvalid;
/**
 The Vehicle ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleIdInvalid;
/**
 CARD TYPE: Discover DOES NOT SUPPORT LEVEL 3

CARD TYPE: Diner Club DOES NOT SUPPORT LEVEL 3

CARD TYPE: enRoute DOES NOT SUPPORT LEVEL 3

CARD TYPE: JCB DOES NOT SUPPORT LEVEL 3

CARD TYPE: RevolutionCard DOES NOT SUPPORT LEVEL 3

CARD TYPE: VisaFleet DOES NOT SUPPORT LEVEL 3

CARD TYPE: MasterCardFleet DOES NOT SUPPORT LEVEL 3

CARD TYPE: FleetOne DOES NOT SUPPORT LEVEL 3

CARD TYPE: Fleetwide DOES NOT SUPPORT LEVEL 3

CARD TYPE: Fuelman DOES NOT SUPPORT LEVEL 3

CARD TYPE: Gascard DOES NOT SUPPORT LEVEL 3

CARD TYPE: Voyager DOES NOT SUPPORT LEVEL 3

CARD TYPE: WrightExpress DOES NOT SUPPORT LEVEL 3

CARD TYPE: Interac DOES NOT SUPPORT LEVEL 3

CARD TYPE: CUP DOES NOT SUPPORT LEVEL 3 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeNotSupportLevel3;
/**
 Can not find index 
 */
@property (readwrite, nonatomic, copy)NSString *cannotFindIndexSingleIndex;
/**
 Swipe entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *swipeEntryFlagInvalid;
/**
 Manual entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *manualEntryFlagInvalid;
/**
 Contactless entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessEntryFlagInvalid;
/**
 Contact entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *contactEntryFlagInvalid;
/**
 Scanner entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *scannerEntryFlagInvalid;
/**
 Fallback entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *fallbackSwipeEntryFlagInvalid;
/**
 Front camera entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *frontCameraEntryFlagInvalid;
/**
 Rear Camera entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *rearCameraEntryFlagInvalid;
/**
 This length of ZIP prompt is invalid or Attribution error 
 */
@property (readwrite, nonatomic, copy)NSString *zipCodePromptInvalid;
/**
 This length of CVV prompt is invalid or Attribution error 
 */
@property (readwrite, nonatomic, copy)NSString *expiryDatePromptInvalid;
/**
 Original amount value invalid 
 */
@property (readwrite, nonatomic, copy)NSString *originalAmountValueInvalid;
/**
 Incremental by reference number is not supported 
 */
@property (readwrite, nonatomic, copy)NSString *incrementalByReferenceNotSupported;
/**
 Print data is too large 
 */
@property (readwrite, nonatomic, copy)NSString *printDataTooLarge;
/**
 Original amount is missing 
 */
@property (readwrite, nonatomic, copy)NSString *originalAmountMissing;
/**
 The entered fleet card requires the Odometer field set. Please set Odometer and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *odometerMissing;
/**
 [deprecated]Replaced by 100003 VEHICLENUMBER MISSING. VISA1 field name changed to VEHICLENUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNoMissing;
/**
 [deprecated]No fleet card type requires Job Number. 
 */
@property (readwrite, nonatomic, copy)NSString *jobNoMissing;
/**
 The entered fleet card requires the Driver ID field set. Please set Driver ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *driverIdMissing;
/**
 [deprecated]Replaced by 100003 EMPLOYEENUMBER MISSING. VISA1 field name changed to EMPLOYEENUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNoMissing;
/**
 [deprecated]Replaced by 100003 LICENSENUMBER MISSING. VISA1 field name changed to LICENSENUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *licensenoMissing;
/**
 The entered fleet card requires the Job ID field set. Please set Job ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *jobidMissing;
/**
 [deprecated]Replaced by 100003 DEPARTMENTNUMBER MISSING. VISA1 field name changed to DEPARTMENTNUMBER. 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNoMissing;
/**
 The entered fleet card requires the Customer Data field set. Please set Customer Data and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *customerDataMissing;
/**
 The entered fleet card requires the User ID field set. Please set User ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *userIdMissing;
/**
 The entered fleet card requires the Vehicle ID field set. Please set Vehicle ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleIdMissing;
/**
 The host does not support transaction adjustment By HRefNum 
 */
@property (readwrite, nonatomic, copy)NSString *transactionAdjustmentByReferenceNotSupported;
/**
 Pinpad type is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *pinpadTypeInvalid;
/**
 The device does not support using an external pin pad 
 */
@property (readwrite, nonatomic, copy)NSString *extPinPadNotSupported;
/**
 Original batch number is not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *originalBatchNumberNotAllowed;
/**
 Original transaction ID is not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransIdNotAllowed;
/**
 Fallback to insert not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *fallbackToInsertNotAllowed;
/**
 Fallback insert entry flag invalid 
 */
@property (readwrite, nonatomic, copy)NSString *fallbackInsertEntryFlagInvalid;
/**
 Gift card type is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *giftCardTypeInvalid;
/**
 Log type is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *logTypeInvalid;
/**
 Source Key Type is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *sourceKeyTypeInvalid;
/**
 Source Key Index is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *sourceKeyIndexInvalid;
/**
 Destination Key Type is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *destinationKeyTypeInvalid;
/**
 Destination Key Index is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *destinationKeyIndexInvalid;
/**
 Destination Key Value is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *destinationKeyValueInvalid;
/**
 Input Data is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *inputDataInvalid;
/**
 Encryption Bitmap is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionBitmapInvalid;
/**
 MAC Key Slot is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *macKeySlotInvalid;
/**
 MAC Work Mode is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *macWorkModeInvalid;
/**
 Encryption Key Slot is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *encryptionKeySlotInvalid;
/**
 Guest name length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *guestNameInvalid;
/**
 Guest number exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *guestNumInvalid;
/**
 The value only can be " ", "1", "2" or "3". 
 */
@property (readwrite, nonatomic, copy)NSString *specialProgramIndicatorInvalid;
/**
 The 'key type' field is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *keyTypeInvalid;
/**
 Please specify the key type first when you want to specify the key slot. 
 */
@property (readwrite, nonatomic, copy)NSString *keyTypeMissing;
/**
 The 'key slot' field is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *keySlotInvalid;
/**
 The 'file type' field is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *fileTypeInvalid;
/**
 The 'Contactless CVM Limit' field is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *contactlessCvmLimitInvalid;
/**
 This transaction type is not supported. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTypeNotSupported;
/**
 Check SAF indicator. 
 */
@property (readwrite, nonatomic, copy)NSString *safIndicatorInvalid;
/**
 Contact EMV entry flag invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *contactEmvEntryFlagInvalid;
/**
 Barcode type must be input when barcode data exists. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeTypeMissing;
/**
 Barcode type field invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeTypeInvalid;
/**
 Barcode data must be input when barcode type exists. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeDataMissing;
/**
 Barcode data field invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeDataInvalid;
/**
 Barcode data length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeDataLengthExceedsLimit;
/**
 Item index missing for A10 and A62. 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndexMissing;
/**
 Please check the transaction number 
 */
@property (readwrite, nonatomic, copy)NSString *transactionMissing;
/**
 The BroadPOS Manager version is too low. Please install the latest version. 
 */
@property (readwrite, nonatomic, copy)NSString *managerVersionTooLow;
/**
 Agreement number format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *agreementNumberInvalid;
/**
 Daily rate format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *dailyRateInvalid;
/**
 Rental duration format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *rentalDurationInvalid;
/**
 Insurance amount invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *insuranceAmountInvalid;
/**
 Allocated miles format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *milesAllocatedInvalid;
/**
 Mile rate format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *mileRateInvalid;
/**
 Driver name format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *driverNameInvalid;
/**
 Driver license number invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *licenseNumberInvalid;
/**
 Rental program type invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *rentalProgramTypeInvalid;
/**
 Pick up location invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *pickupLocationInvalid;
/**
 Pick up city invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *pickupCityInvalid;
/**
 Pick up state invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *pickupStateInvalid;
/**
 Pick up country code invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *pickupCountryInvalid;
/**
 Pick up date/time format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *pickupDateInvalid;
/**
 Return location invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *returnLocationInvalid;
/**
 Return city invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *returnCityInvalid;
/**
 Return state invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *returnStateInvalid;
/**
 Return country code invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *returnCountryInvalid;
/**
 Return date/time format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *returnDateInvalid;
/**
 Return total miles invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *returnMilesInvalid;
/**
 Vehicle class id invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleClassIdInvalid;
/**
 The extra charge items format is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *extraChargeItemsInvalid;
/**
 Extra charge amount invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *extraChargeAmountInvalid;
/**
 The room number is invalid format or missing. 
 */
@property (readwrite, nonatomic, copy)NSString *roomInvalid;
/**
 The folio number is invalid format or missing. 
 */
@property (readwrite, nonatomic, copy)NSString *folioInvalid;
/**
 Charge Type missing or invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *chargeTypeInvalid;
/**
 Check-in date/time format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *checkInDateInvalid;
/**
 Check-out date/time format invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *checkOutDateInvalid;
/**
 Special program code invalid or missing. 
 */
@property (readwrite, nonatomic, copy)NSString *specialProgramInvalid;
/**
 Departure adjusted amount invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *departureAmountInvalid;
/**
 Stay duration invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *stayDurationInvalid;
/**
 Room rate amount invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *roomAmountInvalid;
/**
 Room tax amount invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *roomTaxInvalid;
/**
 Item type invalid or missing. 
 */
@property (readwrite, nonatomic, copy)NSString *itemTypeInvalid;
/**
 Item amount invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *itemAmountInvalid;
/**
 Item code invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *itemCodeInvalid;
/**
 No show flag is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *noShowFlagInvalid;
/**
 The value only can be "0" or "1". 
 */
@property (readwrite, nonatomic, copy)NSString *scannerReaderInvalid;
/**
 The number of eWIC items exceeds the limit.

Please check POSLink-Reference-Host Specific Remarks section for the item limits. 
 */
@property (readwrite, nonatomic, copy)NSString *ewicItemLimitExceeded;
/**
 Only one data entry method is allowed at a time (e.g. Buttons, Signature box, input text). For example, Input Text and Signature Box cannot be enabled at the same time.

If two or more are set, then this error will be returned. 
 */
@property (readwrite, nonatomic, copy)NSString *multipleEntryFieldsNotAllowed;
/**
 Input text title only allowed when input text is set to 1. 
 */
@property (readwrite, nonatomic, copy)NSString *inputTextTitleNotAllowed;
/**
 Min Length only allowed when input text is set to 1. 
 */
@property (readwrite, nonatomic, copy)NSString *minLengthNotAllowed;
/**
 Max Length only allowed when input text is set to 1. 
 */
@property (readwrite, nonatomic, copy)NSString *maxLengthNotAllowed;
/**
 Input type only allowed when input text is set to 1. 
 */
@property (readwrite, nonatomic, copy)NSString *inputTypeNotAllowed;
/**
 The Encryption mode for HMAC is invalid or missing. 
 */
@property (readwrite, nonatomic, copy)NSString *hmacEncryptionModeInvalid;
/**
 Fallback to manual entry flag is invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *fallbackToManualEntryFlagInvalid;
/**
 Swipe Entry Flag is disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *swipeFlagDisabled;
/**
 The transaction type or tender type selected should be credit only. 
 */
@property (readwrite, nonatomic, copy)NSString *creditOnlyTryAnotherTenderOrTransactionType;
/**
 The transaction type or tender type selected should be debit only. 
 */
@property (readwrite, nonatomic, copy)NSString *debitOnlyTryAnotherTenderOrTransactionType;
/**
 The current transaction only support credit or debit card. Please try another tender type to process. 
 */
@property (readwrite, nonatomic, copy)NSString *creditOrDebitOnlyTryAnotherTender;
/**
 The following cases trigger this error:

1.Charge Type field and Special Program Indicator field have conflicting field values and do not comply with the host spec. 
 */
@property (readwrite, nonatomic, copy)NSString *lodgingDataMismatch;
/**
 Will be returned if the CoF indicator is set to a value that it does not support. 
 */
@property (readwrite, nonatomic, copy)NSString *cofIndicatorInvalid;
/**
 The Original Transaction Identifier is missing. This will be returned if the CoF indicator is YES, the Card on File prompt parameter is disabled, and the Original Transaction Identifier is not sent in the request. 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionIdentifierMissing;
/**
 Will be returned if the Original Transaction Identifier is set to a value that it does not support. 
 */
@property (readwrite, nonatomic, copy)NSString *originalTransactionIdentifierInvalid;
/**
 The CoF Initiator is missing. This will be returned if the CoF indicator is set to  YES, the Card on File prompt parameter is disabled, and the CoF initiator not sent in the request. 
 */
@property (readwrite, nonatomic, copy)NSString *cofInitiatorMissing;
/**
 The CoF Initiator flag is invalid. Will be returned if the COF INITIATOR flag is set to a value that it does not accept. 
 */
@property (readwrite, nonatomic, copy)NSString *cofInitiatorInvalid;
/**
 Will be returned if the gift card indicator is set to a value that it does not support. 
 */
@property (readwrite, nonatomic, copy)NSString *giftCardIndicatorInvalid;
/**
 The MOTO/E-Commerce Current Installment field is not currently supported. 
 */
@property (readwrite, nonatomic, copy)NSString *currentInstallmentNotAllowed;
/**
 Length more than 15. 
 */
@property (readwrite, nonatomic, copy)NSString *statementDescriptorInvalid;
/**
 Empty batch report list. 
 */
@property (readwrite, nonatomic, copy)NSString *emptyBatchReportList;
/**
 Invalid batch number. 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumberInvalid;
/**
 Printer malfunction. 
 */
@property (readwrite, nonatomic, copy)NSString *printerMalfunction;
/**
 Batch number does not exist. 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumberNotExist;
/**
 Only support batch number from R15. 
 */
@property (readwrite, nonatomic, copy)NSString *unsupportedBatchNumber;
/**
 Invalid configuration type. 
 */
@property (readwrite, nonatomic, copy)NSString *configurationTypeInvalid;
/**
 The Fuel Amount field exceeds the value of the Transaction Amount field. The value of Transaction Amount includes the Fuel Amount. Please ensure Fuel Amount is equal to or less than Transaction Amount and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *fuelAmountTooLarge;
/**
 The current transaction, host, or industry does not support receiving fleet product data. Fleet Product Data is not allowed for non-fleet transactions outside of the petroleum industry. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetProductDataNotAllowed;
/**
 The Vehicle Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *vehiclenumberInvalid;
/**
 The Job Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *jobnumberInvalid;
/**
 The Employee Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *employeenumberInvalid;
/**
 The License Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *licensenumberInvalid;
/**
 The Department Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *departmentnumberInvalid;
/**
 The Hubometer field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *hubometerInvalid;
/**
 The Maintenance ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *maintenanceIdInvalid;
/**
 The Fleet PO Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPoNumberInvalid;
/**
 The Reefer Hours field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *reeferHoursInvalid;
/**
 The Restriction Code field is non-numeric or is not the expected length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *restrictionCodeInvalid;
/**
 The Trailer ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *trailerIdInvalid;
/**
 The Trip Number field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *tripNumberInvalid;
/**
 The Unit ID field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *unitIdInvalid;
/**
 The Additional Fleet Data 1 field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData1Invalid;
/**
 The Additional Fleet Data 2 field exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData2Invalid;
/**
 The Product Amount field is non-numeric or exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *productAmountInvalid;
/**
 The Product Code field is non-numeric or exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *productCodeInvalid;
/**
 The Quantity field is non-numeric or exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *quantityInvalid;
/**
 The Unit of Measure field is set to an unexpected value. Please retry using one of the predefined values. 
 */
@property (readwrite, nonatomic, copy)NSString *unitOfMeasureInvalid;
/**
 The Unit Price field is non-numeric or exceeds its maximum specified length. Please retry using a valid value. 
 */
@property (readwrite, nonatomic, copy)NSString *unitPriceInvalid;
/**
 The entered fleet card requires the Vehicle Number field set. Please set Vehicle Number and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *vehiclenumberMissing;
/**
 The entered fleet card requires the Employee Number field set. Please set Employee Number and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *employeenumberMissing;
/**
 The entered fleet card requires the License Number field set. Please set License Number and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *licensenumberMissing;
/**
 The entered fleet card requires the Department Number field set. Please set Department Number and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *departmentnumberMissing;
/**
 This transaction requires Fleet Product Data, but BroadPOS did not receive Fleet Product Data from POSLink. This may occur for some fleet transactions or transactions in the petroleum industry. Please set Fleet Product Data and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetProductDataMissing;
/**
 BroadPOS received Fleet Product Data containing incomplete data. Please set Product Amount and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *productAmountMissing;
/**
 BroadPOS received Fleet Product Data containing incomplete data. Please set Product Code and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *productCodeMissing;
/**
 BroadPOS received Fleet Product Data containing incomplete data. Please set Quantity and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *quantityMissing;
/**
 BroadPOS received Fleet Product Data containing incomplete data. Please set Unit of Measure and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *unitOfMeasureMissing;
/**
 BroadPOS received Fleet Product Data containing incomplete data. Please set Unit Price and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *unitPriceMissing;
/**
 The entered fleet card requires the Hubometer field set. Please set Hubometer and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *hubometerMissing;
/**
 The entered fleet card requires the Maintenance ID field set. Please set Maintenance ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *maintenanceIdMissing;
/**
 The entered fleet card requires the Fleet PO Number field set. Please set Fleet PO Number and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *fleetPoNumberMissing;
/**
 The entered fleet card requires the Reefer Hours field set. Please set Reefer Hours and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *reeferHoursMissing;
/**
 The entered fleet card requires the Trailer ID field set. Please set Trailer ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *trailerIdMissing;
/**
 The entered fleet card requires the Trip Number field set. Please set Trip Number and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *tripNumberMissing;
/**
 The entered fleet card requires the Unit ID field set. Please set Unit ID and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *unitIdMissing;
/**
 The entered fleet card requires the Additional Fleet Data 1 field set. Please set Additional Fleet Data 1 and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData1Missing;
/**
 The entered fleet card requires the Additional Fleet Data 2 field set. Please set Additional Fleet Data 2 and try again. 
 */
@property (readwrite, nonatomic, copy)NSString *additionalFleetData2Missing;

@end