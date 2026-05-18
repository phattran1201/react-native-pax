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

#import "PLAdminConst.h"
#import "PLCode100003.h"

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
 1.Length more than limit

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *amountInvalid;
/**
 1.Length more than limit

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *tipInvalid;
/**
 1.Length more than limit

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *cashBackInvalid;
/**
 1.Length more than limit

2.Not number

3.The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *merchantFeeInvalid;
/**
 1.Length more than limit

2.Not number

3. The amount has "." or "-". 
 */
@property (readwrite, nonatomic, copy)NSString *taxAmountInvalid;
/**
 1.Length more or smaller than limit

2.The month more than 12 or day more than 31

3.Not number 
 */
@property (readwrite, nonatomic, copy)NSString *expDateInvalid;
/**
 1.Length more than limit

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
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *authCodeInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *transactionInvalid;
/**
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
 The value invalid 
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
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *meModeInvalid;
/**
 Length more than limit, or MOTO/E-Commerce Type Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *meTypeInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *secureTypeInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *orderNumberInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *installmentsInvalid;
/**
 1. Length more than limit

 2.Please check the current installment value. 
 */
@property (readwrite, nonatomic, copy)NSString *currentInstInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *tableNumberInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *guestNumberInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *signInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *checkInvalid;
/**
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *ticketNumberInvalid;
/**
 MOTO/E-Commerce Transaction Type not allowed. 
 */
@property (readwrite, nonatomic, copy)NSString *meTypeNotAllowed;
/**
 E-Commerce Secure Type not allowed. 
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
 1.EDC or trans type not allowed. 2.Tip feature is disabled. 
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
 “BALANCE” and “DEACT” not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *amountNotAllowed;
/**
 Please check MOTO/E-commerce information 
 */
@property (readwrite, nonatomic, copy)NSString *installmentsNotNull;
/**
 Please check MOTO/E-commerce information 
 */
@property (readwrite, nonatomic, copy)NSString *currentInstNotNull;
/**
 Please check MOTO/E-commerce information 
 */
@property (readwrite, nonatomic, copy)NSString *motoArgumentsConflict;
/**
 Please check “CHECK” information 
 */
@property (readwrite, nonatomic, copy)NSString *checkTypeInvalid;
/**
 Please check “CHECK” information 
 */
@property (readwrite, nonatomic, copy)NSString *idTypeInvalid;
/**
 Please check “CHECK” information 
 */
@property (readwrite, nonatomic, copy)NSString *dobInvalid;
/**
 Please check “CHECK” information 
 */
@property (readwrite, nonatomic, copy)NSString *dobFormatInvalid;
/**
 Industry is not "RESTAURANT". 
 */
@property (readwrite, nonatomic, copy)NSString *tableNumberNotAllowed;
/**
 Industry is not "RESTAURANT". 
 */
@property (readwrite, nonatomic, copy)NSString *guestNumberNotAllowed;
/**
 Please check MOTO/E-commerce information 
 */
@property (readwrite, nonatomic, copy)NSString *motoEcNotAllowed;
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
 This variable cannot set. 
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
 EDC or transaction type does not support CVV. 
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
 The current transaction amount plus The total amount in terminal is more than 999999999. 
 */
@property (readwrite, nonatomic, copy)NSString *amountTooLarge;
/**
 The Dup Override Flag length is more 1 byte. 
 */
@property (readwrite, nonatomic, copy)NSString *invalidOverride;
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
 Only CHECK supports ticket number. 
 */
@property (readwrite, nonatomic, copy)NSString *ticketNumberNotAllowed;
/**
 The transaction type must exist. 
 */
@property (readwrite, nonatomic, copy)NSString *transactionTypeNull;
/**
 Unsupported secure type 
 */
@property (readwrite, nonatomic, copy)NSString *secureTypeNotSupport;
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
 When the trans Type not support MOTO/EC. 
 */
@property (readwrite, nonatomic, copy)NSString *motoEcInformationNotAllowed;
/**
 Unsupported override flag 
 */
@property (readwrite, nonatomic, copy)NSString *overrideNotAllowed;
/**
 Please check the override flag value 
 */
@property (readwrite, nonatomic, copy)NSString *dupCheckInvalid;
/**
 Please check the length 
 */
@property (readwrite, nonatomic, copy)NSString *routingNumberInvalid;
/**
 Please check the check number 
 */
@property (readwrite, nonatomic, copy)NSString *checkNumberInvalid;
/**
 Please check the check ID 
 */
@property (readwrite, nonatomic, copy)NSString *checkIdInvalid;
/**
 Please check the phone number 
 */
@property (readwrite, nonatomic, copy)NSString *phoneNumberInvalid;
/**
 Please check the check information. 
 */
@property (readwrite, nonatomic, copy)NSString *subTransactionTypeInvalid;
/**
 Please specify EBT type. 
 */
@property (readwrite, nonatomic, copy)NSString *pleaseSpecifyEbtType;
/**
 The transaction has been added tip. 
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
 Card type is disabled. 
 */
@property (readwrite, nonatomic, copy)NSString *cardTypeDisable;
/**
 Expiry date is missing. 
 */
@property (readwrite, nonatomic, copy)NSString *expDateMissing;
/**
 Moto/e-commerce mode doesn't support 
 */
@property (readwrite, nonatomic, copy)NSString *meModeNotSupport;
/**
 Account mismatch 
 */
@property (readwrite, nonatomic, copy)NSString *accountMismatch;
/**
 In demo mode it doesn't support. 
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
 FSA amount greater than total amount when using FSA card 
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
 Adjustment not applicable for certain trans.

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
 Miss necessary lodging data for lodging related transactions. 
 */
@property (readwrite, nonatomic, copy)NSString *missingLodgingData;
/**
 Host MID doesn't set. Please set it in Host Setting Menu. 
 */
@property (readwrite, nonatomic, copy)NSString *hostMidNotSet;
/**
 Host User name doesn't set. Please set it in Host Setting Menu. 
 */
@property (readwrite, nonatomic, copy)NSString *hostUsernameNotSet;
/**
 Host User password doesn't set. Please set it in Host Setting Menu. 
 */
@property (readwrite, nonatomic, copy)NSString *hostUserPasswordNotSet;
/**
 User disabled the transaction 
 */
@property (readwrite, nonatomic, copy)NSString *transactionDisabled;
/**
 1.Length more or smaller than limit

2. The Attribute error. 
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
 Adjust by refer number doesn't support 
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
 This command doesn't support 
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
 Encryption doesn't supported 
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
 Length more than limit or value is empty 
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
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *firstNameInvalid;
/**
 Fleet card bin missiong 
 */
@property (readwrite, nonatomic, copy)NSString *fleetCardBinMissing;
/**
 Fleet passThruData not allowed 
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
 FSA not support 
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
 Fuel amount not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *fuelAmountNotAllowed;
/**
 If fuel amount < Total amount, then swipes a fuel only fleet card, the app should return a error 
 */
@property (readwrite, nonatomic, copy)NSString *fuelOnly;
/**
 Length more than limit 
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
 Google Smart Tap not support 
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
 Installments not allowed 
 */
@property (readwrite, nonatomic, copy)NSString *installmentsNotAllowed;
/**
 Card type not support 
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
 Length more than limit 
 */
@property (readwrite, nonatomic, copy)NSString *lastNameInvalid;
/**
 Check last transaction flag 
 */
@property (readwrite, nonatomic, copy)NSString *lastTransactionInvalid;
/**
 Check level3 data 
 */
@property (readwrite, nonatomic, copy)NSString *level3DataInvalid;
/**
 Check level3 data format 
 */
@property (readwrite, nonatomic, copy)NSString *level3FormatInvalid;
/**
 Level3 mandatory field missing 
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
 Card type not support 
 */
@property (readwrite, nonatomic, copy)NSString *noCardTypeAvailable;
/**
 No data 
 */
@property (readwrite, nonatomic, copy)NSString *noData;
/**
 Not fleet card 
 */
@property (readwrite, nonatomic, copy)NSString *notFleetCard;
/**
 Not support scanner 
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
 Original Expiry Date doesn't support 
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
 Original PAN doesn't support 
 */
@property (readwrite, nonatomic, copy)NSString *originalPanNotSupported;
/**
 Original settlement date doesn't support 
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
 Original transaction date not support 
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
 Post auth by refer number doesn't support 
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
 Doesn't support return reason 
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
 Token doesn't support 
 */
@property (readwrite, nonatomic, copy)NSString *tokenNotSupported;
/**
 Check token request flag 
 */
@property (readwrite, nonatomic, copy)NSString *tokenRequestFlagInvalid;
/**
 Token SN doesn't support 
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
 Token request doesn't support 
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
 TransIT not support 
 */
@property (readwrite, nonatomic, copy)NSString *transitNotSupport;
/**
 Upload S&F Failed 
 */
@property (readwrite, nonatomic, copy)NSString *uploadSAndFFailed;
/**
 Upload doesn't support 
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
 Void by refer number doesn't support 
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
 Not support camera 
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
 Not support this command 
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
 Fleet prompt code invalid 
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
 The length of the value more than 3 or equal 0. 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndexInvalid;
/**
 Item index quantity invalid 
 */
@property (readwrite, nonatomic, copy)NSString *itemIndexQuantityInvalid;
/**
 Key not exist. 
 */
@property (readwrite, nonatomic, copy)NSString *keyNotExist;
/**
 1.The length of the value exceeds 3 

 2.Not integer number 
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
 Out of paper. 
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
 Out of paper. 
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
 1.The PIN bypass value range of 0~4.

2.Not integer number. 
 */
@property (readwrite, nonatomic, copy)NSString *pinBypassInvalid;
/**
 The PIN min length more than max length. 
 */
@property (readwrite, nonatomic, copy)NSString *pinMinLengthExceedPinMaxLength;
/**
 Please see your mobile phone. The transaction need to restart. 
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
 ODOMETER Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *odometerInvalid;
/**
 VEHICLENO Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNoInvalid;
/**
 JOBNO Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *jobNoInvalid;
/**
 DRIVERID Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *driverIdInvalid;
/**
 EMPLOYEENO Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNoInvalid;
/**
 LICENSENO Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *licenseNoInvalid;
/**
 JOBID Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *jobidInvalid;
/**
 DEPARTMENTNO Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNoInvalid;
/**
 CUSTOMERDATA Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *customerDataInvalid;
/**
 USERID Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *userIdInvalid;
/**
 VEHICLEID Invalid 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleIdInvalid;
/**
 CARD TYPE: Discover NOT SUPPORT LEVEL3

CARD TYPE: Diner Club NOT SUPPORT LEVEL3

CARD TYPE: enRoute NOT SUPPORT LEVEL3

CARD TYPE: JCB NOT SUPPORT LEVEL3

CARD TYPE: RevolutionCard NOT SUPPORT LEVEL3

CARD TYPE: VisaFleet NOT SUPPORT LEVEL3

CARD TYPE: MasterCardFleet NOT SUPPORT LEVEL3

CARD TYPE: FleetOne NOT SUPPORT LEVEL3

CARD TYPE: Fleetwide NOT SUPPORT LEVEL3

CARD TYPE: Fuelman NOT SUPPORT LEVEL3

CARD TYPE: Gascard NOT SUPPORT LEVEL3

CARD TYPE: Voyager NOT SUPPORT LEVEL3

CARD TYPE: WrightExpress NOT SUPPORT LEVEL3

CARD TYPE: Interac NOT SUPPORT LEVEL3

CARD TYPE: CUP NOT SUPPORT LEVEL3 
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
 ODOMETER is missing 
 */
@property (readwrite, nonatomic, copy)NSString *odometerMissing;
/**
 VEHICLENO is missing 
 */
@property (readwrite, nonatomic, copy)NSString *vehicleNoMissing;
/**
 JOBNO is missing 
 */
@property (readwrite, nonatomic, copy)NSString *jobNoMissing;
/**
 DRIVERID is missing 
 */
@property (readwrite, nonatomic, copy)NSString *driverIdMissing;
/**
 EMPLOYEENO is missing 
 */
@property (readwrite, nonatomic, copy)NSString *employeeNoMissing;
/**
 LICENSENO is missing 
 */
@property (readwrite, nonatomic, copy)NSString *licensenoMissing;
/**
 JOBID is missing 
 */
@property (readwrite, nonatomic, copy)NSString *jobidMissing;
/**
 DEPARTMENTNO is missing 
 */
@property (readwrite, nonatomic, copy)NSString *departmentNoMissing;
/**
 CUSTOMERDATA is missing 
 */
@property (readwrite, nonatomic, copy)NSString *customerDataMissing;
/**
 USERID is missing 
 */
@property (readwrite, nonatomic, copy)NSString *userIdMissing;
/**
 VEHICLEID is missing 
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
 Check Mode is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *checkModeInvalid;
/**
 Check Buffer is invalid 
 */
@property (readwrite, nonatomic, copy)NSString *checkBufferInvalid;
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
 Length exceeds limit. 
 */
@property (readwrite, nonatomic, copy)NSString *guestNameInvalid;
/**
 Length exceeds limit. 
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
 Not support this transaction type. 
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
 Barcode type must be input when barcode data exist. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeTypeMissing;
/**
 Barcode type field invalid. 
 */
@property (readwrite, nonatomic, copy)NSString *barcodeTypeInvalid;
/**
 Barcode data must be input when barcode type exist. 
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
 Only one data entry method is allowed at a time. For example, Input Text and Signature Box cannot be enabled at the same time. 
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

@end