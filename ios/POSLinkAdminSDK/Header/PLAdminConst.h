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

#import <Foundation/Foundation.h>

@interface PLAdminConst : NSObject

/* Consts*/


enum MacKeyType {
    /**
     When the value set to NotSet, it means choosing Tak.
     */
    MacKeyTypeNotSet = 1,
    /**
     TAK.
     */
    MacKeyTypeTak = 2,
    /**
     DES DUKPT key.
     */
    MacKeyTypeDesDukptKey = 3,
    /**
     AES DUKPT key.
     */
    MacKeyTypeAesDukptKey = 4,
    /**
     HMAC.
     */
    MacKeyTypeHmac = 5,
};

enum LineItemAction {
    /**
     When the value set to NotSet, it means choosing Add.
     */
    LineItemActionNotSet = 1,
    /**
     Add
     */
    LineItemActionAdd = 2,
    /**
     Update.
     */
    LineItemActionUpdate = 3,
    /**
     Delete.
     */
    LineItemActionDelete = 4,
};

enum KsnFlag {
    /**
     When the value set to NotSet, it means choosing Increase.
     */
    KsnFlagNotSet = 1,
    /**
     Not increase.
     */
    KsnFlagNotIncrease = 2,
    /**
     Increase.
     */
    KsnFlagIncrease = 3,
};

enum UserLanguage {
    /**
     The value is not set.
     */
    UserLanguageNotSet = 1,
    /**
     English US.
     */
    UserLanguageEnglishUs = 2,
    /**
     French.
     */
    UserLanguageFrench = 3,
    /**
     Chinese.
     */
    UserLanguageChinese = 4,
    /**
     Lithuanian.
     */
    UserLanguageLithuanian = 5,
    /**
     English UK.
     */
    UserLanguageEnglishUk = 6,
};

enum CardholderVerificationMethod {
    /**
     The value is not set.
     */
    CardholderVerificationMethodNotSet = 1,
    /**
     Fail CVM processing.
     */
    CardholderVerificationMethodFailCvmProcessing = 2,
    /**
     Plaintext Offline PIN Verification.
     */
    CardholderVerificationMethodPlaintextOfflinePinVerification = 3,
    /**
     Online PIN.
     */
    CardholderVerificationMethodOnlinePin = 4,
    /**
     Plaintext Offline PIN and Signature.
     */
    CardholderVerificationMethodPlaintextOfflinePinAndSignature = 5,
    /**
     Enciphered Offline PIN Verification.
     */
    CardholderVerificationMethodEncipheredOfflinePinVerification = 6,
    /**
     Enciphered Offline PIN Verification and Signature.
     */
    CardholderVerificationMethodEncipheredOfflinePinVerificationAndSignature = 7,
    /**
     Signature.
     */
    CardholderVerificationMethodSignature = 8,
    /**
     No CVM Required.
     */
    CardholderVerificationMethodNoCvmRequired = 9,
    /**
     On Device CVM.
     */
    CardholderVerificationMethodOnDeviceCvm = 10,
};

enum NewServiceType {
    /**
     The value is not set.
     */
    NewServiceTypeNotSet = 1,
    /**
     Unspecified.
     */
    NewServiceTypeUnspecified = 2,
    /**
     Valuable.
     */
    NewServiceTypeValuable = 3,
    /**
     Receipt.
     */
    NewServiceTypeReceipt = 4,
    /**
     Survey.
     */
    NewServiceTypeSurvey = 5,
    /**
     Goods.
     */
    NewServiceTypeGoods = 6,
    /**
     Signup.
     */
    NewServiceTypeSignup = 7,
};

enum CardInsertStatus {
    /**
     The value is not set.
     */
    CardInsertStatusNotSet = 1,
    /**
     No card inserted.
     */
    CardInsertStatusNoCardInserted = 2,
    /**
     Has EMV Card inserted.
     */
    CardInsertStatusEmvCardInserted = 3,
    /**
     Has card inserted, but this is not the EMV card. (Prolin Only)
     */
    CardInsertStatusCardInserted = 4,
};

enum ReaderType {
    /**
     When the value set to NotSet, it means choosing RearCamera.
     */
    ReaderTypeNotSet = 1,
    /**
     Rear camera.
     */
    ReaderTypeRearCamera = 2,
    /**
     Front camera.
     */
    ReaderTypeFrontCamera = 3,
};

enum PasswordType {
    /**
     The value is not set.
     */
    PasswordTypeNotSet = 1,
    /**
     Password A type.
     */
    PasswordTypeAType = 2,
    /**
     Password B type.
     */
    PasswordTypeBType = 3,
};

enum SafMode {
    /**
     The value is not set.
     */
    SafModeNotSet = 1,
    /**
     Stay Online.
     */
    SafModeStayOnline = 2,
    /**
     Stay Offline.
     */
    SafModeStayOffline = 3,
    /**
     Offline Till batch.
     */
    SafModeOfflineTillBatch = 4,
    /**
     Offline On Demand/Auto.
     */
    SafModeOfflineOnDemandOrAuto = 5,
};

enum StatusReportFlag {
    /**
     The value is not set.
     */
    StatusReportFlagNotSet = 1,
    /**
     Not to report.
     */
    StatusReportFlagNotToReport = 2,
    /**
     To report.
     */
    StatusReportFlagToReport = 3,
};

enum EnableKeyType {
    /**
     When the value set to NotSet, it means choosing EnableVirtualButtonAndHardKeys.
     */
    EnableKeyTypeNotSet = 1,
    /**
     Enable both virtual button and hard keys.
     */
    EnableKeyTypeEnableVirtualButtonAndHardKeys = 2,
    /**
     Enable Hard Key only.
     */
    EnableKeyTypeEnableHardKeyOnly = 3,
};

enum InputTextPrompt {
    /**
     The value is not set.
     */
    InputTextPromptNotSet = 1,
    /**
     Enter Amount
     */
    InputTextPromptEnterAmount = 2,
    /**
     Enter Points
     */
    InputTextPromptEnterPoints = 3,
    /**
     Enter Table Number
     */
    InputTextPromptEnterTableNumber = 4,
    /**
     Enter the Number of Guests
     */
    InputTextPromptEnterTheNumberOfGuests = 5,
    /**
     Enter Order Number
     */
    InputTextPromptEnterOrderNumber = 6,
    /**
     Enter Ticket Number
     */
    InputTextPromptEnterTicketNumber = 7,
    /**
     Enter Voucher Number
     */
    InputTextPromptEnterVoucherNumber = 8,
    /**
     Enter Auth Code
     */
    InputTextPromptEnterAuthCode = 9,
    /**
     Enter Tip
     */
    InputTextPromptEnterTip = 10,
    /**
     Enter Cash Back
     */
    InputTextPromptEnterCashBack = 11,
    /**
     Enter Merchant Fee
     */
    InputTextPromptEnterMerchantFee = 12,
    /**
     Enter Surcharge Fee
     */
    InputTextPromptEnterSurchargeFee = 13,
    /**
     Enter Your Address
     */
    InputTextPromptEnterYourAddress = 14,
    /**
     Enter Your Zip Code
     */
    InputTextPromptEnterYourZipCode = 15,
    /**
     Enter Customer Code
     */
    InputTextPromptEnterCustomerCode = 16,
    /**
     Enter P.O. Number
     */
    InputTextPromptEnterPoNumber = 17,
    /**
     Enter Destination Zip
     */
    InputTextPromptEnterDestinationZip = 18,
    /**
     Enter Product Description
     */
    InputTextPromptEnterProductDescription = 19,
    /**
     Enter Merchant Tax ID
     */
    InputTextPromptEnterMerchantTaxId = 20,
    /**
     Enter TAX Amount
     */
    InputTextPromptEnterTaxAmount = 21,
    /**
     Enter TAX Exempt ID
     */
    InputTextPromptEnterTaxExemptId = 22,
    /**
     Enter Reference Number
     */
    InputTextPromptEnterReferenceNumber = 23,
    /**
     Enter Phone Number
     */
    InputTextPromptEnterPhoneNumber = 24,
    /**
     Enter Social Security #
     */
    InputTextPromptEnterSocialSecurity = 25,
    /**
     Enter User Name
     */
    InputTextPromptEnterUserName = 26,
    /**
     Enter Customer Service Phone
     */
    InputTextPromptEnterCustomerServicePhone = 27,
    /**
     Enter Original Trans. Date
     */
    InputTextPromptEnterOriginalTransactionDate = 28,
    /**
     Enter Original Trans. Time
     */
    InputTextPromptEnterOriginalTransactionTime = 29,
    /**
     Enter Date
     */
    InputTextPromptEnterDate = 30,
    /**
     Enter Time
     */
    InputTextPromptEnterTime = 31,
    /**
     Enter Password
     */
    InputTextPromptEnterPassword = 32,
};

enum InputTextType {
    /**
     When the value set to NotSet, it means choosing NoInputText.
     */
    InputTextTypeNotSet = 1,
    /**
     No Input Text.
     */
    InputTextTypeNoInputText = 2,
    /**
     Show Input Text.
     */
    InputTextTypeShowInputText = 3,
};

enum ReceiptPrintFlag {
    /**
     The value is not set.
     */
    ReceiptPrintFlagNotSet = 1,
    /**
     No receipt.
     */
    ReceiptPrintFlagNoReceipt = 2,
    /**
     Merchant only.
     */
    ReceiptPrintFlagMerchantOnly = 3,
    /**
     Customer only.
     */
    ReceiptPrintFlagCustomerOnly = 4,
    /**
     Both merchant /customer copy.
     */
    ReceiptPrintFlagBothCopy = 5,
};

enum VasResponseCode {
    /**
     The value is not set.
     */
    VasResponseCodeNotSet = 1,
    /**
     VAS OK.
     */
    VasResponseCodeVasOk = 2,
    /**
     VAS OSE error.
     */
    VasResponseCodeVasOseError = 3,
    /**
     VAS get data command error.
     */
    VasResponseCodeVasGetDataCommandError = 4,
    /**
     VAS issue, need to start payment.
     */
    VasResponseCodeVasIssueNeedToStartPayment = 5,
    /**
     The app version of mobile is too low.
     */
    VasResponseCodeAppVersionTooLow = 6,
    /**
     In VAS mode, mobile capabilities: Skip Loyalty Protocol.
     */
    VasResponseCodeSkipProtocolInVasMode = 7,
    /**
     In dual mode, mobile capabilities: Skip Loyalty Protocol and No Payment Data Forthcoming.
     */
    VasResponseCodeSkipProtocolAndNoDataForthcomingInDualMode = 8,
    /**
     In single mode, Mobile Capabilities: Skip Loyalty Protocol and No Payment Data Forthcoming.
     */
    VasResponseCodeSkipProtocolAndNoDataForthcomingInSingleMode = 9,
    /**
     6A83-VAS Data not found (iPhone without the pkpass).
     */
    VasResponseCodeVasDataNotFound = 10,
    /**
     6287-VAS Data not active (without fingerprint authorization).
     */
    VasResponseCodeVasDataNotActive = 11,
    /**
     6984-User Intervention Required on mobile device (a special iOS version will trigger this issue, maybe is without authorization, too).
     */
    VasResponseCodeUserInterventionRequiredOnMobileDevice = 12,
    /**
     VAS parameter error, The merchant ID is null.
     */
    VasResponseCodeTheMerchantIdIsNull = 13,
    /**
     VAS get key error, Error when get key from key file.
     */
    VasResponseCodeVasGetKeyError = 14,
    /**
     VAS Data Decryption Error. Data can't be decrypted by the current key.
     */
    VasResponseCodeVasDataDecryptionError = 15,
    /**
     Unknown error.
     */
    VasResponseCodeUnknownError = 16,
};

enum AppActivated {
    /**
     When the value set to NotSet, it means not support.
     */
    AppActivatedNotSet = 1,
    /**
     Activated.
     */
    AppActivatedActivated = 2,
    /**
     Not activated.
     */
    AppActivatedNotActivated = 3,
};

enum PinpadEnableFlag {
    /**
     When the value set to NotSet, it means choosing NotAllowed.
     */
    PinpadEnableFlagNotSet = 1,
    /**
     Not allowed.
     */
    PinpadEnableFlagNotAllowed = 2,
    /**
     Allowed.
     */
    PinpadEnableFlagAllowed = 3,
};

enum UrlMode {
    /**
     The value is not set.
     */
    UrlModeNotSet = 1,
    /**
     Full VAS Mode.
     */
    UrlModeFullVasMode = 2,
    /**
     URL mode.
     */
    UrlModeUrlMode = 3,
};

enum EndTap {
    /**
     The value is not set.
     */
    EndTapNotSet = 1,
    /**
     Normal flow.
     */
    EndTapNormalFlow = 2,
    /**
     Stop tap session.
     */
    EndTapStopTapSession = 3,
};

enum SignatureBoxType {
    /**
     When the value set to NotSet, it means choosing NoSignatureBox.
     */
    SignatureBoxTypeNotSet = 1,
    /**
     No signature box.
     */
    SignatureBoxTypeNoSignatureBox = 2,
    /**
     Terminal preference.
     */
    SignatureBoxTypeTerminalPreference = 3,
    /**
     Display signature box horizontally.
     */
    SignatureBoxTypeHorizontalDisplay = 4,
    /**
     Display signature box vertically.
     */
    SignatureBoxTypeVerticalDisplay = 5,
};

enum PinpadType {
    /**
     When the value set to NotSet, it means choosing InternalPinpad.
     */
    PinpadTypeNotSet = 1,
    /**
     Internal Pinpad.
     */
    PinpadTypeInternalPinpad = 2,
    /**
     External Pinpad.
     */
    PinpadTypeExternalPinpad = 3,
    /**
     RNIB Pinpad.
     */
    PinpadTypeRnibPinpad = 4,
    /**
     External Pinpad first. If external pinpad is present, use external pinpad. If not, use internal pinpad.
     */
    PinpadTypeExternalPinpadFirst = 5,
};

enum BarcodeName {
    /**
     The value is not set.
     */
    BarcodeNameNotSet = 1,
    /**
     CODE39
     */
    BarcodeNameCode39 = 2,
    /**
     CODE128
     */
    BarcodeNameCode128 = 3,
    /**
     EAN13
     */
    BarcodeNameEan13 = 4,
    /**
     EAN128
     */
    BarcodeNameEan128 = 5,
    /**
     PDF417
     */
    BarcodeNamePdf417 = 6,
    /**
     GRIDMATRIX
     */
    BarcodeNameGridMatrix = 7,
    /**
     QRCODE
     */
    BarcodeNameQrCode = 8,
};

enum ServiceState {
    /**
     The value is not set.
     */
    ServiceStateNotSet = 1,
    /**
     Unspecified.
     */
    ServiceStateUnspecified = 2,
    /**
     Success.
     */
    ServiceStateSuccess = 3,
    /**
     Invalid format.
     */
    ServiceStateInvalidFormat = 4,
    /**
     Invalid value.
     */
    ServiceStateInvalidValue = 5,
};

enum PinpadTypeFlag {
    /**
     When the value set to NotSet, it means choosing InternalPinpad.
     */
    PinpadTypeFlagNotSet = 1,
    /**
     Use the device's internal pinpad.
     */
    PinpadTypeFlagInternalPinpad = 2,
    /**
     External Pinpad.

     On A80 only, use the connected external pinpad. 

     On all other devices, returns response 100003 EXT PIN PAD NOT SUPPORTED.
     */
    PinpadTypeFlagExternalPinpad = 3,
    /**
     External Pinpad first.

     On A80 only, use the connected external pinpad if one is detected. Otherwise, use the device's internal pinpad.

     On all other devices, returns response 100003 EXT PIN PAD NOT SUPPORTED.
     */
    PinpadTypeFlagExternalPinpadFirst = 4,
};

enum ItemDetailUnit {
    /**
     When the value set to NotSet, it means choosing PerItem.
     */
    ItemDetailUnitNotSet = 1,
    /**
     Per item.
     */
    ItemDetailUnitPerItem = 2,
    /**
     Per pound.
     */
    ItemDetailUnitPerPound = 3,
    /**
     Per foot.
     */
    ItemDetailUnitPerFoot = 4,
};

enum TokenCommand {
    /**
     When the value set to NotSet, it means choosing Lookup.
     */
    TokenCommandNotSet = 1,
    /**
     Query host for card information using token.
     */
    TokenCommandLookup = 2,
    /**
     Delete token from token vault.
     */
    TokenCommandDelete = 3,
    /**
     Generate duplicate token value.
     */
    TokenCommandDuplicate = 4,
    /**
     Update the value of the token or update information.
     */
    TokenCommandUpdate = 5,
};

enum HardKey {
    /**
     The value is not set.
     */
    HardKeyNotSet = 1,
    /**
     KEY0.
     */
    HardKeyKey0 = 2,
    /**
     KEY1.
     */
    HardKeyKey1 = 3,
    /**
     KEY2.
     */
    HardKeyKey2 = 4,
    /**
     KEY3.
     */
    HardKeyKey3 = 5,
    /**
     KEY4.
     */
    HardKeyKey4 = 6,
    /**
     KEY5.
     */
    HardKeyKey5 = 7,
    /**
     KEY6.
     */
    HardKeyKey6 = 8,
    /**
     KEY7.
     */
    HardKeyKey7 = 9,
    /**
     KEY8.
     */
    HardKeyKey8 = 10,
    /**
     KEY9.
     */
    HardKeyKey9 = 11,
    /**
     Clear.
     */
    HardKeyClear = 12,
    /**
     Cancel.
     */
    HardKeyCancel = 13,
    /**
     Key enter.
     */
    HardKeyOk = 14,
};

enum CheckMode {
    /**
     The value is not set.
     */
    CheckModeNotSet = 1,
    /**
     No KCV check.
     */
    CheckModeNoKcvCheck = 2,
    /**
     Perform DES/TDES encryption on 8 bytes 0x00, and use first 4 bytes as KCV.
     */
    CheckModeDesOrTdesEncryptionAndCheckKcv = 3,
};

enum LabelProperty {
    /**
     When the value set to NotSet, it means choosing Unchecked.
     */
    LabelPropertyNotSet = 1,
    /**
     Unchecked.
     */
    LabelPropertyUnchecked = 2,
    /**
     Checked.
     */
    LabelPropertyChecked = 3,
};

enum MacWorkMode {
    /**
     When the value set to NotSet, it means choosing AnsiX99.
     */
    MacWorkModeNotSet = 1,
    /**
     ANSI X9.9.
     */
    MacWorkModeAnsiX99 = 2,
    /**
     Hypercom Fast Mode.
     */
    MacWorkModeHypercomFastMode = 3,
    /**
     ANSI X9.19.
     */
    MacWorkModeAnsiX919 = 4,
    /**
     SHA1.
     */
    MacWorkModeSha1 = 5,
    /**
     SHA256.
     */
    MacWorkModeSha256 = 6,
};

enum BarcodeType {
    /**
     The value is not set.
     */
    BarcodeTypeNotSet = 1,
    /**
     QR Code.
     */
    BarcodeTypeQrCode = 2,
    /**
     2D-barcode.
     */
    BarcodeTypeTwoDimensionalBarcode = 3,
    /**
     3D-barcode.
     */
    BarcodeTypeThreeDimensionalBarcode = 4,
};

enum SignatureStatus {
    /**
     The value is not set.
     */
    SignatureStatusNotSet = 1,
    /**
     Not done the signature.
     */
    SignatureStatusNotDoneTheSignature = 2,
    /**
     Done the signature.
     */
    SignatureStatusDoneTheSignature = 3,
};

enum DeleteSafConfirmation {
    /**
     When the value set to NotSet, it means choosing WithPrompt.
     */
    DeleteSafConfirmationNotSet = 1,
    /**
     With Prompt.
     */
    DeleteSafConfirmationWithPrompt = 2,
    /**
     Without Prompt.
     */
    DeleteSafConfirmationWithoutPrompt = 3,
};

enum UpdateOperation {
    /**
     The value is not set.
     */
    UpdateOperationNotSet = 1,
    /**
     No operation.
     */
    UpdateOperationNoOperation = 2,
    /**
     Remove service object.
     */
    UpdateOperationRemoveServiceObject = 3,
    /**
     Set balance.
     */
    UpdateOperationSetBalance = 4,
    /**
     Add balance.
     */
    UpdateOperationAddBalance = 5,
    /**
     Subtract balance.
     */
    UpdateOperationSubtractBalance = 6,
    /**
     Free.
     */
    UpdateOperationFree = 7,
};

enum EdcType {
    /**
     The value is not set when appears in response.
     */
    EdcTypeNotSet = 1,
    /**
     All EDC type
     */
    EdcTypeAll = 2,
    /**
     Credit card
     */
    EdcTypeCredit = 3,
    /**
     Debit card
     */
    EdcTypeDebit = 4,
    /**
     EBT card
     */
    EdcTypeEbt = 5,
    /**
     Gift card
     */
    EdcTypeGift = 6,
    /**
     Loyalty card
     */
    EdcTypeLoyalty = 7,
    /**
     Cash
     */
    EdcTypeCash = 8,
    /**
     Check card
     */
    EdcTypeCheck = 9,
};

enum VasMode {
    /**
     The value is not set.
     */
    VasModeNotSet = 1,
    /**
     VAS Only.
     */
    VasModeVasOnly = 2,
    /**
     Vas and payment.
     */
    VasModeVasAndPayment = 3,
    /**
     Vas or payment.
     */
    VasModeVasOrPayment = 4,
    /**
     Payment only.
     */
    VasModePaymentOnly = 5,
};

enum ProtocolFlag {
    /**
     The value is not set.
     */
    ProtocolFlagNotSet = 1,
    /**
     Means terminal support VISA1 protocol.
     */
    ProtocolFlagVisa1 = 2,
    /**
     Means terminal support JSON protocol.
     */
    ProtocolFlagJson = 3,
};

enum M1CommandType {
    /**
     The value is not set.
     */
    M1CommandTypeNotSet = 1,
    /**
     Read
     */
    M1CommandTypeRead = 2,
    /**
     Write
     */
    M1CommandTypeWrite = 3,
    /**
     Operate with increase value.
     */
    M1CommandTypeOperateWithIncreaseValue = 4,
    /**
     Operate with decrease value.
     */
    M1CommandTypeOperateWithDecreaseValue = 5,
    /**
     Operate with backup value.
     */
    M1CommandTypeOperateWithBackupValue = 6,
    /**
     Read the serial number.
     */
    M1CommandTypeReadTheSerialNumber = 7,
};

enum ExpiryDatePrompt {
    /**
     When the value set to NotSet, it means choosing NotNeeded.
     */
    ExpiryDatePromptNotSet = 1,
    /**
     Not needed.
     */
    ExpiryDatePromptNotNeeded = 2,
    /**
     Prompt for manual entry only.
     */
    ExpiryDatePromptPromptForManualEntryOnly = 3,
};

enum OseToPpse {
    /**
     The value is not set.
     */
    OseToPpseNotSet = 1,
    /**
     Normal flow.
     */
    OseToPpseNormalFlow = 2,
    /**
     Stop VAS and do payment directly.
     */
    OseToPpseStopVasAndDoPaymentDirectly = 3,
};

enum TransactionType {
    /**
     The value is not set only appears in response.
     */
    TransactionTypeNotSet = 1,
    /**
     Ask user to select transaction type. It appears in request.
     */
    TransactionTypeUnknown = 2,
    /**
     Authorizes the funds on the card and flags the transaction to be captured for settlement at the next settlement time. Please use Sale when using Redeem.
     */
    TransactionTypeSale = 3,
    /**
     Returns funds to the card open to buy.
     */
    TransactionTypeReturn = 4,
    /**
     Verify/Authorize a payment.
     */
    TransactionTypeAuthorization = 5,
    /**
     Completes an Authorization Only transaction.
     */
    TransactionTypePostAuthorization = 6,
    /**
     Forces a transaction into an open batch. Typically used for voice authorizations.
     */
    TransactionTypeForceAuthorization = 7,
    /**
     Used for additional charges or gratuity. Typically used for tip adjustment.
     */
    TransactionTypeAdjust = 8,
    /**
     Used to take money from bank.
     */
    TransactionTypeWithdrawal = 9,
    /**
     Activates a payment card. Typically used for gift card activation.
     */
    TransactionTypeActivate = 10,
    /**
     Used to add value to an account, if the card is in inventory (new or recycle) then it will activate the card and add a new account. Typically used for gift cards.
     */
    TransactionTypeIssue = 11,
    /**
     Adds value to a card account. Typically used for gift cards.
     */
    TransactionTypeReload = 12,
    /**
     Used to remove the remaining balance from the Card. And the account balance will be zero. Typically used for gift cards.
     */
    TransactionTypeCashout = 13,
    /**
     Deactivates an active card account. Typically used for gift cards.
     */
    TransactionTypeDeactivate = 14,
    /**
     Used to transfer balance from one stored value account to another, this is typically to replace a lost or stolen account with a new one or to consolidate two or more accounts into a single account. After a transfer has completed, the source account is closed/deactivated and can no longer be used. Typically used for gift cards.
     */
    TransactionTypeReplace = 15,
    /**
     The same usage as Replace.
     */
    TransactionTypeMerge = 16,
    /**
     Used to change the status of an active gift card that has been reported lost or stolen. Typically used for gift cards.
     */
    TransactionTypeReportLost = 17,
    /**
     Used to cancel a prior authorization in the current open batch. The original transaction must be a Sale, Return, Authorization, PostAuthorization, Forced and Withdrawal.
     */
    TransactionTypeVoid = 18,
    /**
     Void sale.
     */
    TransactionTypeVoidSale = 19,
    /**
     Void return.
     */
    TransactionTypeVoidReturn = 20,
    /**
     Void authorization.
     */
    TransactionTypeVoidAuthorization = 21,
    /**
     Void post authorization.
     */
    TransactionTypeVoidPostAuthorization = 22,
    /**
     Void force authorization.
     */
    TransactionTypeVoidForceAuthorization = 23,
    /**
     Void withdrawal.
     */
    TransactionTypeVoidWithdrawal = 24,
    /**
     Used to retrieve the balance on the card. Typically used to obtain the balance on a food stamp card or gift card.
     */
    TransactionTypeInquiry = 25,
    /**
     Used to determine if an account is available to use or to verify cardholder information.
     */
    TransactionTypeVerify = 26,
    /**
     Used to activate a card that has been deactivated. Typically used for gift cards.
     */
    TransactionTypeReactivate = 27,
    /**
     Used to issue a card when the approved code was received from the processor via a phone call or other means. Typically used for gift cards.
     */
    TransactionTypeForcedIssue = 28,
    /**
     Used to add value to card when the approved code was received from the processor via a phone call or other means. Typically used for gift cards.
     */
    TransactionTypeForcedAdd = 29,
    /**
     Used to decrease value to a card account, and we should put the amount we want to decrease in the amount field. Typically used for gift cards.
     */
    TransactionTypeUnload = 30,
    /**
     The same usage as Reactivate.
     */
    TransactionTypeRenew = 31,
    /**
     Used to get balance from other gift system by this command. Typically used for gift cards.
     */
    TransactionTypeGetConvertDetail = 32,
    /**
     Used to transfer the balance get by GetConvertDetail to the new card. So before call this transaction type, the GetConvertDetail must be called first. Typically used for gift cards.
     */
    TransactionTypeConvert = 33,
    /**
     Used to request a token which represents a card number, the token is generated randomly by the host.
     */
    TransactionTypeTokenize = 34,
    /**
     This is used to increase the authorization amount.
     */
    TransactionTypeIncrementalAuthorization = 35,
    /**
     Used to lock the requested amount up to the current available balance for a period time. One or more locks can be active on a Prepaid Closed Loop card at one time. Typically used for gift cards.
     */
    TransactionTypeBalanceWithLock = 36,
    /**
     This transaction is performed after a Balance Lock transaction to complete the purchase on a Prepaid Closed Loop card and unlock any remaining balance from the Balance transaction. Typically used for gift cards.
     */
    TransactionTypeRedemptionWithUnlock = 37,
    /**
     Used when an account holder makes a payment using a payment from other than a stored value account, the account holder may present their stored value account to earn points or other loyalty rewards, which would be added to their account. Typically used for gift cards.
     */
    TransactionTypeRewards = 38,
    /**
     Used when a debit/EBT was deleted out of the terminal, the merchant can use this transaction type to get paid again. Now for TSYS only.
     */
    TransactionTypeReenter = 39,
    /**
     Used to enables a merchant to modify a transaction amount and mark the transaction for settlement. Now for TransIT only.
     */
    TransactionTypeTransactionAdjustment = 40,
    /**
     To transfer or disburse funds from one account to another.
     */
    TransactionTypeTransfer = 41,
    /**
     Used to be implemented for dual message host sytem only. After the terminal receives an approved authorization response and the user wants to complete the transaction, they need send a Finalize command to the terminal. Terminal will send out a Finalization Advice message to the host upon receiving the command. Typically used for credit cards.
     */
    TransactionTypeFinalize = 42,
    /**
     Used when a customer makes a cash deposit on a merchant's POS terminal.
     */
    TransactionTypeDeposit = 43,
    /**
     Used when a customer wants to pay into a credit account. Most commonly applied by RCS.
     */
    TransactionTypeAccountPayment = 44,
    /**
     Used for partial authorization reversal, not all the hosts support this feature.
     */
    TransactionTypeReversal = 45,
};

enum TextPushedMode {
    /**
     When the value set to NotSet, it means choosing Topdown.
     */
    TextPushedModeNotSet = 1,
    /**
     Topdown.
     */
    TextPushedModeTopdown = 2,
    /**
     Bottom-up.
     */
    TextPushedModeBottomUp = 3,
};

enum UploadFlag {
    /**
     Doesn't need upload to host.
     */
    UploadFlagNotUploadToHost = 1,
    /**
     Need upload to host.
     */
    UploadFlagUploadToHost = 2,
};

enum TargetDevice {
    /**
     When the value set to NotSet, it means choosing Terminal.
     */
    TargetDeviceNotSet = 1,
    /**
     Terminal.
     */
    TargetDeviceTerminal = 2,
    /**
     External Pinpad.
     */
    TargetDeviceExternalPinpad = 3,
};

enum DestinationKeyType {
    /**
     The value is not set.
     */
    DestinationKeyTypeNotSet = 1,
    /**
     TPK(Terminal PIN Key).
     */
    DestinationKeyTypeTpk = 2,
    /**
     TAK(Terminal MAC Key).
     */
    DestinationKeyTypeTak = 3,
    /**
     TDK(Terminal DES Key).
     */
    DestinationKeyTypeTdk = 4,
};

enum KeyType {
    /**
     When the value set to NotSet, it means all key information
     */
    KeyTypeNotSet = 1,
    /**
     Master Key.
     */
    KeyTypeMasterKey = 2,
    /**
     Session Key.
     */
    KeyTypeSessionKey = 3,
    /**
     DES DUKPT Key.
     */
    KeyTypeDesDukptKey = 4,
    /**
     AES DUKPT Key.
     */
    KeyTypeAesDukptKey = 5,
};

enum ButtonType {
    /**
     When the value set to NotSet, it means choosing RadioButton.
     */
    ButtonTypeNotSet = 1,
    /**
     Radio Button. It allows the user to choose only one of a predefined set of mutually exclusive options, and the API returns right after selection.
     */
    ButtonTypeRadioButton = 2,
    /**
     CheckBox. It allows the user to choose multiple entities of a predefined set of options, and the API is returned upon key press.
     */
    ButtonTypeCheckBox = 3,
};

enum EntryMode {
    /**
     The value is not set.
     */
    EntryModeNotSet = 1,
    /**
     Manual.
     */
    EntryModeManual = 2,
    /**
     Swipe.
     */
    EntryModeSwipe = 3,
    /**
     Contactless.
     */
    EntryModeContactless = 4,
    /**
     Laser scanner.
     */
    EntryModeLaserScanner = 5,
    /**
     Chip.
     */
    EntryModeChip = 6,
    /**
     Chip Fall Back Swipe.
     */
    EntryModeChipFallBackSwipe = 7,
    /**
     Front camera.
     */
    EntryModeFrontCamera = 8,
    /**
     Rear camera.
     */
    EntryModeRearCamera = 9,
};

enum EncryptionFlag {
    /**
     When the value set to NotSet, it means choosing NotEncrypted.
     */
    EncryptionFlagNotSet = 1,
    /**
     Not encrypted.
     */
    EncryptionFlagNotEncrypted = 2,
    /**
     DUKPT DES with PIN method.
     */
    EncryptionFlagDukptDesWithPinMethod = 3,
    /**
     DES/TDES method (Depends on the Key length: TDES for 24 bytes key, DES for 8/16 bytes key).
     */
    EncryptionFlagDesOrTdesMethod = 4,
    /**
     Voltage E2EE.
     */
    EncryptionFlagVoltageE2ee = 5,
};

enum Security {
    /**
     The value is not set.
     */
    SecurityNotSet = 1,
    /**
     Normal.
     */
    SecurityNormal = 2,
    /**
     Securely.
     */
    SecuritySecurely = 3,
    /**
     Pre_signature.
     */
    SecurityPreSignature = 4,
    /**
     Need not a right auth.
     */
    SecurityNeedNotARightAuth = 5,
};

enum FileType {
    /**
     The value is not set.
     */
    FileTypeNotSet = 1,
    /**
     A zip package contains multiple files. Terminal will replace the files according to the file names.
     */
    FileTypeResourceFile = 2,
    /**
     A zip package contains the file used to inject offline RKI key.
     */
    FileTypeOfflineRkiKeyFile = 3,
    /**
     Update the OS and App through the installation package.
     */
    FileTypeInstallationPackageFile = 4,
    /**
     The license file is used to activate the app.
     */
    FileTypelicenseFile = 5,
};

enum InputType {
    /**
     When the value set to NotSet, it means choosing AlphaNumeric.
     */
    InputTypeNotSet = 1,
    /**
     Alpha-Numeric string.
     */
    InputTypeAlphaNumeric = 2,
    /**
     Numeric string.
     */
    InputTypeNumeric = 3,
    /**
     Date in MMDDYYYY format.
     */
    InputTypeDate = 4,
    /**
     Time in HHMMSS format.
     */
    InputTypeTime = 5,
    /**
     Currency in XXXXXX.XX format.
     */
    InputTypeCurrency = 6,
    /**
     Password format.
     */
    InputTypePassword = 7,
    /**
     Phone number as "(xxx) xxx-xxxx".
     */
    InputTypePhoneNumber = 8,
    /**
     social security as "xxx-xx-xxxx".
     */
    InputTypeSocialSecurity = 9,
};

enum SafUploadMode {
    /**
     The value is not set.
     */
    SafUploadModeNotSet = 1,
    /**
     Upload before batch.
     */
    SafUploadModeUploadBeforeBatch = 2,
    /**
     Silent Auto Upload.
     */
    SafUploadModeSilentAutoUpload = 3,
};

enum TouchscreenStatus {
    /**
     The value is not set.
     */
    TouchscreenStatusNotSet = 1,
    /**
     Use.
     */
    TouchscreenStatusUse = 2,
    /**
     Not use.
     */
    TouchscreenStatusNotUse = 3,
};

enum ContinuousScreen {
    /**
     When the value set to NotSet, it means choosing Default.
     */
    ContinuousScreenNotSet = 1,
    /**
     Default.
     */
    ContinuousScreenDefault = 2,
    /**
     Indicate the terminal not go to idle screen but waiting for the next command.
     */
    ContinuousScreenNotGoToIdleScreen = 3,
};

@end

