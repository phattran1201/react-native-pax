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

@interface PLSemiConst : NSObject

/* Consts*/


enum VehicleClassId {
    /**
     The value is not set.
     */
    VehicleClassIdNotSet = 1,
    /**
     Mini
     */
    VehicleClassIdMini = 2,
    /**
     Subcompact
     */
    VehicleClassIdSubcompact = 3,
    /**
     Economy
     */
    VehicleClassIdEconomy = 4,
    /**
     Compact
     */
    VehicleClassIdCompact = 5,
    /**
     Midsize
     */
    VehicleClassIdMidsize = 6,
    /**
     Intermediate
     */
    VehicleClassIdIntermediate = 7,
    /**
     Standard
     */
    VehicleClassIdStandard = 8,
    /**
     Full size
     */
    VehicleClassIdFullSize = 9,
    /**
     Luxury
     */
    VehicleClassIdLuxury = 10,
    /**
     Premium
     */
    VehicleClassIdPremium = 11,
    /**
     Minivan
     */
    VehicleClassIdMinivan = 12,
    /**
     12-Passenger van
     */
    VehicleClassIdTwelvePassengerVan = 13,
    /**
     Moving van
     */
    VehicleClassIdMovingVan = 14,
    /**
     15-Passing van
     */
    VehicleClassIdFifteenPassingVan = 15,
    /**
     Cargo van
     */
    VehicleClassIdCargoVan = 16,
    /**
     12-foot truck
     */
    VehicleClassIdTwelveFootTruck = 17,
    /**
     20-foot truck
     */
    VehicleClassIdTwentyFootTruck = 18,
    /**
     24-foot truck
     */
    VehicleClassIdTwentyFourFootTruck = 19,
    /**
     26-foot truck
     */
    VehicleClassIdTwentySixFootTruck = 20,
    /**
     Moped
     */
    VehicleClassIdMoped = 21,
    /**
     Stretch
     */
    VehicleClassIdStretch = 22,
    /**
     Regular
     */
    VehicleClassIdRegular = 23,
    /**
     Unique
     */
    VehicleClassIdUnique = 24,
    /**
     Exotic
     */
    VehicleClassIdExotic = 25,
    /**
     Small/medium truck
     */
    VehicleClassIdSmallOrMediumTruck = 26,
    /**
     Large truck
     */
    VehicleClassIdLargeTruck = 27,
    /**
     Small SUV
     */
    VehicleClassIdSmallSuv = 28,
    /**
     Medium SUV
     */
    VehicleClassIdMediumSuv = 29,
    /**
     Large SUV
     */
    VehicleClassIdLargeSuv = 30,
    /**
     Exotic SUV
     */
    VehicleClassIdExoticSuv = 31,
    /**
     Four wheel drive
     */
    VehicleClassIdFourWheelDrive = 32,
    /**
     Special
     */
    VehicleClassIdSpecial = 33,
    /**
     Miscellaneous
     */
    VehicleClassIdMiscellaneous = 34,
};

enum LastTransaction {
    /**
     When the value set to NotSet, it means choosing NotRetrieve.
     */
    LastTransactionNotSet = 1,
    /**
     Do not retrieve last transaction.
     */
    LastTransactionNotRetrieve = 2,
    /**
     Retrieve last transaction.
     */
    LastTransactionRetrieve = 3,
};

enum RentalProgramType {
    /**
     The value is not set.
     */
    RentalProgramTypeNotSet = 1,
    /**
     Advance Deposit.
     */
    RentalProgramTypeAdvanceDeposit = 2,
    /**
     Assured Reservation.
     */
    RentalProgramTypeAssuredReservation = 3,
    /**
     Delayed charge.
     */
    RentalProgramTypeDelayedCharge = 4,
    /**
     Express service.
     */
    RentalProgramTypeExpressService = 5,
    /**
     Normal charge.
     */
    RentalProgramTypeNormalCharge = 6,
    /**
     No show charge.
     */
    RentalProgramTypeNoShowCharge = 7,
};

enum TokenRequestFlag {
    /**
     When the value set to NotSet, it means choosing No.
     */
    TokenRequestFlagNotSet = 1,
    /**
     No.
     */
    TokenRequestFlagNo = 2,
    /**
     Yes.
     */
    TokenRequestFlagYes = 3,
};

enum MotoECommerceTransactionType {
    /**
     The value is not set.
     */
    MotoECommerceTransactionTypeNotSet = 1,
    /**
     Single transaction.
     */
    MotoECommerceTransactionTypeSingleTransaction = 2,
    /**
     Installment.
     */
    MotoECommerceTransactionTypeInstallment = 3,
    /**
     Recurring transaction.
     */
    MotoECommerceTransactionTypeRecurringTransaction = 4,
};

enum MotoECommerceMode {
    /**
     The value is not set.
     */
    MotoECommerceModeNotSet = 1,
    /**
     Mail order mode.
     */
    MotoECommerceModeMailOrderMode = 2,
    /**
     Tele order mode.
     */
    MotoECommerceModeTeleOrderMode = 3,
    /**
     E-commerce mode.
     */
    MotoECommerceModeECommerceMode = 4,
};

enum ForceCc {
    /**
     When the value set to NotSet, it means choosing No.
     */
    ForceCcNotSet = 1,
    /**
     No.
     */
    ForceCcNo = 2,
    /**
     Yes.
     */
    ForceCcYes = 3,
};

enum SafIndicator {
    /**
     The value is not set.
     */
    SafIndicatorNotSet = 1,
    /**
     New stored transaction records.
     */
    SafIndicatorNewStoredTransactionRecords = 2,
    /**
     Failed transaction records.
     */
    SafIndicatorFailedTransactionRecords = 3,
    /**
     Delete all SAF records (Failed + New records).
     */
    SafIndicatorDeleteAllSafRecords = 4,
};

enum CheckSaleType {
    /**
     The value is not set.
     */
    CheckSaleTypeNotSet = 1,
    /**
     Verification.
     */
    CheckSaleTypeVerification = 2,
    /**
     Conversion.
     */
    CheckSaleTypeConversion = 3,
    /**
     Guarantee.
     */
    CheckSaleTypeGuarantee = 4,
};

enum CofInitiator {
    /**
     When the value set to NotSet, it means not support.
     */
    CofInitiatorNotSet = 1,
    /**
     Customer Initiated, active participation of the customer.
     */
    CofInitiatorCustomer = 2,
    /**
     Merchant Initiated, is conducted without the active participation or the presence of the customer.
     */
    CofInitiatorMerchant = 3,
};

enum ReversalStatus {
    /**
     The value is not set.
     */
    ReversalStatusNotSet = 1,
    /**
     Aborted.
     */
    ReversalStatusAborted = 2,
    /**
     Timeout.
     */
    ReversalStatusTimeout = 3,
    /**
     Reversal failed.
     */
    ReversalStatusReversalFailed = 4,
    /**
     Reversal success.
     */
    ReversalStatusReversalSuccess = 5,
};

enum AdditionalChargeItemType {
    /**
     The value is not set.
     */
    AdditionalChargeItemTypeNotSet = 1,
    /**
     OtherOther.
     */
    AdditionalChargeItemTypeOther = 2,
    /**
     Gift Shop.
     */
    AdditionalChargeItemTypeGiftShop = 3,
    /**
     Laundry.
     */
    AdditionalChargeItemTypeLaundry = 4,
    /**
     Mini-Bar.
     */
    AdditionalChargeItemTypeMiniBar = 5,
    /**
     Restaurant.
     */
    AdditionalChargeItemTypeRestaurant = 6,
    /**
     Telephone.
     */
    AdditionalChargeItemTypeTelephone = 7,
};

enum CardType {
    /**
     The value is not set only appears in response.
     */
    CardTypeNotSet = 1,
    /**
     Visa
     */
    CardTypeVisa = 2,
    /**
     MasterCard
     */
    CardTypeMasterCard = 3,
    /**
     Amex
     */
    CardTypeAmex = 4,
    /**
     Discover
     */
    CardTypeDiscover = 5,
    /**
     DinerClub
     */
    CardTypeDinerClub = 6,
    /**
     EnRoute
     */
    CardTypeEnRoute = 7,
    /**
     Jcb
     */
    CardTypeJcb = 8,
    /**
     RevolutionCard
     */
    CardTypeRevolutionCard = 9,
    /**
     VisaFleet
     */
    CardTypeVisaFleet = 10,
    /**
     MasterCardFleet
     */
    CardTypeMasterCardFleet = 11,
    /**
     FleetOne
     */
    CardTypeFleetOne = 12,
    /**
     Fleetwide
     */
    CardTypeFleetwide = 13,
    /**
     Fuelman
     */
    CardTypeFuelman = 14,
    /**
     Gascard
     */
    CardTypeGascard = 15,
    /**
     Voyager
     */
    CardTypeVoyager = 16,
    /**
     WrightExpress
     */
    CardTypeWrightExpress = 17,
    /**
     Interac
     */
    CardTypeInterac = 18,
    /**
     China union pay.
     */
    CardTypeCup = 19,
    /**
     Maestro
     */
    CardTypeMaestro = 20,
    /**
     Sinclair
     */
    CardTypeSinclair = 21,
    /**
     If the card not in the range, use OTHER as the card type.
     */
    CardTypeOther = 22,
};

enum AccessibilityPinPad {
    /**
     Follow TMS settings for "Accessibility Switch" visibility and value.
     */
    AccessibilityPinPadNotSet = 1,
    /**
     Do not support A11Y pin pad; No switch..
     */
    AccessibilityPinPadNotSupport = 2,
    /**
     On(A11Y)-Display "Accessibility Switch" in "ON" position; Use A11Y pin pad.
     */
    AccessibilityPinPadOn = 3,
    /**
     Off(A11Y)-Display "Accessibility Switch" in "OFF" position; Do not use A11Y pin pad.
     */
    AccessibilityPinPadOff = 4,
};

enum CvvBypassReason {
    /**
     The value is not set.
     */
    CvvBypassReasonNotSet = 1,
    /**
     Cardholder chose to bypass the CVV Bypass Reason prompt.
     */
    CvvBypassReasonDeliberatelyBypassed = 2,
    /**
     CVV was inaccessible to the cardholder (example: not printed on the card).
     */
    CvvBypassReasonNotAvailable = 3,
    /**
     Cardholder was unable to read their card's CVV.
     */
    CvvBypassReasonIllegible = 4,
};

enum SignatureCaptureFlag {
    /**
     When the value set to NotSet, it means choosing NotCapture.
     */
    SignatureCaptureFlagNotSet = 1,
    /**
     Not capture.
     */
    SignatureCaptureFlagNotCapture = 2,
    /**
     Capture.
     */
    SignatureCaptureFlagCapture = 3,
};

enum TaxExemptIndicator {
    /**
     The value is not set.
     */
    TaxExemptIndicatorNotSet = 1,
    /**
     Not exempt.
     */
    TaxExemptIndicatorNotExempt = 2,
    /**
     Exempt.
     */
    TaxExemptIndicatorExempt = 3,
};

enum EwicGroupType {
    /**
     The value is not set.
     */
    EwicGroupTypeNotSet = 1,
    /**
     UPC data.
     */
    EwicGroupTypeUpcData = 2,
    /**
     PLU data.
     */
    EwicGroupTypePluData = 3,
};

enum ForceFsa {
    /**
     When the value set to NotSet, it means choosing No.
     */
    ForceFsaNotSet = 1,
    /**
     No.
     */
    ForceFsaNo = 2,
    /**
     Yes.
     */
    ForceFsaYes = 3,
};

enum DebitAccountType {
    /**
     The value is not set.
     */
    DebitAccountTypeNotSet = 1,
    /**
     Checking.
     */
    DebitAccountTypeChecking = 2,
    /**
     Saving.
     */
    DebitAccountTypeSaving = 3,
    /**
     Default.
     */
    DebitAccountTypeDefault = 4,
};

enum CardPresentMode {
    /**
     When the value set to NotSet, it means choosing DefaultValue.
     */
    CardPresentModeNotSet = 1,
    /**
     Default value, use terminal's card present setting..
     */
    CardPresentModeDefaultValue = 2,
    /**
     Don't prompt, assume card present..
     */
    CardPresentModeAssumeCardPresent = 3,
    /**
     Don't prompt, assume card not present.
     */
    CardPresentModeAssumeCardNotPresent = 4,
    /**
     Prompt for use to select.
     */
    CardPresentModePromptForUseToSelect = 5,
};

enum TaxType {
    /**
     The value is not set.
     */
    TaxTypeNotSet = 1,
    /**
     Unknown.
     */
    TaxTypeUnknown = 2,
    /**
     Federal/National Sales Tax (total and sub).
     */
    TaxTypeNationalSalesTax = 3,
    /**
     State sales tax.
     */
    TaxTypeStateSalesTax = 4,
    /**
     City sales tax.
     */
    TaxTypeCitySalesTax = 5,
    /**
     Local Sales Tax / Local Tax/Sales Tax(see note).
     */
    TaxTypeLocalSalesTax = 6,
    /**
     Municipal sales tax.
     */
    TaxTypeMunicipalSalesTax = 7,
    /**
     Duty tax.
     */
    TaxTypeDutyTax = 8,
    /**
     Value Added Tax (VAT) / Alternate Tax.
     */
    TaxTypeValueAddedTax = 9,
    /**
     Goods and Services Tax (GST).
     */
    TaxTypeGoodsAndServicesTax = 10,
    /**
     Provincial Sales Tax (PST).
     */
    TaxTypeProvincialSalesTax = 11,
    /**
     Room Tax.
     */
    TaxTypeRoomTax = 12,
    /**
     Occupancy Tax.
     */
    TaxTypeOccupancyTax = 13,
    /**
     Energy Tax.
     */
    TaxTypeEnergyTax = 14,
};

enum GiftTenderType {
    /**
     The value is not set.
     */
    GiftTenderTypeNotSet = 1,
    /**
     Unknown.
     */
    GiftTenderTypeUnknown = 2,
    /**
     Credit card.
     */
    GiftTenderTypeCreditCard = 3,
    /**
     Debit card.
     */
    GiftTenderTypeDebitCard = 4,
    /**
     Check.
     */
    GiftTenderTypeCheck = 5,
    /**
     Cash.
     */
    GiftTenderTypeCash = 6,
};

enum TorRecordType {
    /**
     The value is not set.
     */
    TorRecordTypeNotSet = 1,
    /**
     Reversal record.
     */
    TorRecordTypeReversalRecord = 2,
    /**
     EMV 2nd GAC Reversal.
     */
    TorRecordTypeEmvSecondGacReversal = 3,
};

enum GiftCardType {
    /**
     The value is not set only when applicable for DoGift.
     */
    GiftCardTypeNotSet = 1,
    /**
     Custom value gift card.
     */
    GiftCardTypeCustomValueGiftCard = 2,
    /**
     Predetermine value gift card.
     */
    GiftCardTypePredetermineValueGiftCard = 3,
};

enum SignatureResponseStatus {
    /**
     The value is not set.
     */
    SignatureResponseStatusNotSet = 1,
    /**
     Local captured.
     */
    SignatureResponseStatusLocalCaptured = 2,
    /**
     Aborted.
     */
    SignatureResponseStatusAborted = 3,
    /**
     Timeout.
     */
    SignatureResponseStatusTimeout = 4,
    /**
     Not available.
     */
    SignatureResponseStatusNotAvailable = 5,
    /**
     Successfully uploaded.
     */
    SignatureResponseStatusSuccessfullyUploaded = 6,
    /**
     Failed during uploading.
     */
    SignatureResponseStatusFailedDuringUploading = 7,
};

enum LodgingNoShowFlag {
    /**
     The value is not set.
     */
    LodgingNoShowFlagNotSet = 1,
    /**
     Guest did not show up for the reservation..
     */
    LodgingNoShowFlagNotShow = 2,
    /**
     Guest did show for the reservation.
     */
    LodgingNoShowFlagShow = 3,
};

enum CheckIdType {
    /**
     The value is not set.
     */
    CheckIdTypeNotSet = 1,
    /**
     Driver license.
     */
    CheckIdTypeDriverLicense = 2,
    /**
     SSN.
     */
    CheckIdTypeSsn = 3,
    /**
     Military ID.
     */
    CheckIdTypeMilitaryId = 4,
    /**
     CourtesyCard.
     */
    CheckIdTypeCourtesyCard = 5,
    /**
     Proprietary card.
     */
    CheckIdTypeProprietaryCard = 6,
    /**
     Passport number.
     */
    CheckIdTypePassportNumber = 7,
};

enum CheckType {
    /**
     The value is not set.
     */
    CheckTypeNotSet = 1,
    /**
     Personal.
     */
    CheckTypePersonal = 2,
    /**
     Business.
     */
    CheckTypeBusiness = 3,
    /**
     Government.
     */
    CheckTypeGovernment = 4,
    /**
     Two-party.
     */
    CheckTypeTwoParty = 5,
};

enum HostGatewayReturnReason {
    /**
     When the value set to NotSet, it means choosing GeneralReturn.
     */
    HostGatewayReturnReasonNotSet = 1,
    /**
     General return.
     */
    HostGatewayReturnReasonGeneralReturn = 2,
    /**
     Adjustment.
     */
    HostGatewayReturnReasonAdjustment = 3,
};

enum SafReportIndicator {
    /**
     The value is not set.
     */
    SafReportIndicatorNotSet = 1,
    /**
     New record report.
     */
    SafReportIndicatorNewRecordReport = 2,
    /**
     Failed record report.
     */
    SafReportIndicatorFailedRecordReport = 3,
    /**
     All (New + Failed report).
     */
    SafReportIndicatorAll = 4,
};

enum TransactionResultType {
    /**
     When the value set to NotSet, it means choosing SuccessfulOnly.
     */
    TransactionResultTypeNotSet = 1,
    /**
     Successful transactions only.
     */
    TransactionResultTypeSuccessfulOnly = 2,
    /**
     Failed transactions only.
     */
    TransactionResultTypeFailedOnly = 3,
    /**
     All transactions.
     */
    TransactionResultTypeAll = 4,
};

enum LodgingSpecialProgramCode {
    /**
     The value is not set.
     */
    LodgingSpecialProgramCodeNotSet = 1,
    /**
     Other.
     */
    LodgingSpecialProgramCodeOther = 2,
    /**
     Assured Reservation/Normal Charge/Purchase.
     */
    LodgingSpecialProgramCodeAssuredReservation = 3,
    /**
     Delayed charge.
     */
    LodgingSpecialProgramCodeDelayedCharge = 4,
    /**
     Advanced deposit.
     */
    LodgingSpecialProgramCodeAdvancedDeposit = 5,
    /**
     Express Check-out Service.
     */
    LodgingSpecialProgramCodeExpressCheckOutService = 6,
};

enum ExtraChargeItemType {
    /**
     The value is not set.
     */
    ExtraChargeItemTypeNotSet = 1,
    /**
     Other.
     */
    ExtraChargeItemTypeOther = 2,
    /**
     Extra mileage.
     */
    ExtraChargeItemTypeExtraMileage = 3,
    /**
     Gas.
     */
    ExtraChargeItemTypeGas = 4,
    /**
     Late return.
     */
    ExtraChargeItemTypeLateReturn = 5,
    /**
     One-Way Charge.
     */
    ExtraChargeItemTypeOneWayCharge = 6,
    /**
     Parking Violation.
     */
    ExtraChargeItemTypeParkingViolation = 7,
};

enum AdditionalResponseDataFlag {
    /**
     When the value set to NotSet, it means choosing No.
     */
    AdditionalResponseDataFlagNotSet = 1,
    /**
     No.
     */
    AdditionalResponseDataFlagNo = 2,
    /**
     Yes.
     */
    AdditionalResponseDataFlagYes = 3,
};

enum PinEntryStatus {
    /**
     The value is not set.
     */
    PinEntryStatusNotSet = 1,
    /**
     PIN Bypassed.
     */
    PinEntryStatusPinBypassed = 2,
    /**
     PIN Verified.
     */
    PinEntryStatusPinVerified = 3,
};

enum SignatureUploadFlag {
    /**
     When the value set to NotSet, it means choosing ToUpload.
     */
    SignatureUploadFlagNotSet = 1,
    /**
     Not to upload.
     */
    SignatureUploadFlagNotToUpload = 2,
    /**
     To upload.
     */
    SignatureUploadFlagToUpload = 3,
};

enum DebitNetwork {
    /**
     The value is not set.
     */
    DebitNetworkNotSet = 1,
    /**
     Star.
     */
    DebitNetworkStar = 2,
    /**
     NYCE.
     */
    DebitNetworkNyce = 3,
    /**
     Pulse.
     */
    DebitNetworkPulse = 4,
    /**
     Maestro.
     */
    DebitNetworkMaestro = 5,
    /**
     Interlink.
     */
    DebitNetworkInterlink = 6,
    /**
     Accel.
     */
    DebitNetworkAccel = 7,
};

enum CofIndicator {
    /**
     The value is not set.
     */
    CofIndicatorNotSet = 1,
    /**
     YES.
     */
    CofIndicatorYes = 2,
};

enum TipRequestFlag {
    /**
     The value is not set.
     */
    TipRequestFlagNotSet = 1,
    /**
     Not need enter tip on terminal.
     */
    TipRequestFlagNotNeedEnterTipOnTerminal = 2,
    /**
     Need enter tip on terminal.
     */
    TipRequestFlagNeedEnterTipOnTerminal = 3,
};

enum SignatureAcquireFlag {
    /**
     When the value set to NotSet, it means choosing NotRequired.
     */
    SignatureAcquireFlagNotSet = 1,
    /**
     Not required.
     */
    SignatureAcquireFlagNotRequired = 2,
    /**
     Required.
     */
    SignatureAcquireFlagRequired = 3,
};

enum MotoECommerceSecureType {
    /**
     The value is not set.
     */
    MotoECommerceSecureTypeNotSet = 1,
    /**
     Non secure.
     */
    MotoECommerceSecureTypeNonSecure = 2,
    /**
     Secure transaction.
     */
    MotoECommerceSecureTypeSecureTransaction = 3,
};

enum EbtCountType {
    /**
     When the value set to NotSet, it means terminal will prompt menu to select it.
     */
    EbtCountTypeNotSet = 1,
    /**
     Cash benefits.
     */
    EbtCountTypeCashBenefits = 2,
    /**
     Food stamp.
     */
    EbtCountTypeFoodStamp = 3,
    /**
     Voucher.
     */
    EbtCountTypeVoucher = 4,
    /**
     eWIC.
     */
    EbtCountTypeEwic = 5,
    /**
     eWIC Voucher.
     */
    EbtCountTypeEwicVoucher = 6,
};

enum HostProgramType {
    /**
     When the value set to NotSet, it means choosing Regular.
     */
    HostProgramTypeNotSet = 1,
    /**
     Regular.
     */
    HostProgramTypeRegular = 2,
    /**
     Commercial.
     */
    HostProgramTypeCommercial = 3,
    /**
     HSA card.
     */
    HostProgramTypeHsaCard = 4,
    /**
     FSA card.
     */
    HostProgramTypeFsaCard = 5,
    /**
     HRA card.
     */
    HostProgramTypeHraCard = 6,
    /**
     Fleet.
     */
    HostProgramTypeFleet = 7,
    /**
     Unknown.
     */
    HostProgramTypeUnknown = 8,
};

enum CardProgramType {
    /**
     When the value set to NotSet, it means choosing RegularCard.
     */
    CardProgramTypeNotSet = 1,
    /**
     Regular card.
     */
    CardProgramTypeRegularCard = 2,
    /**
     Commercial card.
     */
    CardProgramTypeCommercialCard = 3,
    /**
     FSA card.
     */
    CardProgramTypeFsaCard = 4,
    /**
     Fleet card.
     */
    CardProgramTypeFleetCard = 5,
};

enum FpsReceipt {
    /**
     When the value set to NotSet, it means both merchant/customer copy.
     */
    FpsReceiptNotSet = 1,
    /**
     Merchant only.
     */
    FpsReceiptMerchantOnly = 2,
    /**
     Customer only.
     */
    FpsReceiptCustomerOnly = 3,
    /**
     No receipt.
     */
    FpsReceiptNoReceipt = 4,
};

enum PrimaryChargeType {
    /**
     The value is not set.
     */
    PrimaryChargeTypeNotSet = 1,
    /**
     Other.
     */
    PrimaryChargeTypeOther = 2,
    /**
     Lodging/Hotel.
     */
    PrimaryChargeTypeLodgingOrHotel = 3,
    /**
     Restaurant.
     */
    PrimaryChargeTypeRestaurant = 4,
    /**
     Gift Shop.
     */
    PrimaryChargeTypeGiftShop = 5,
    /**
     Spa.
     */
    PrimaryChargeTypeSpa = 6,
    /**
     Beauty Services.
     */
    PrimaryChargeTypeBeautyServices = 7,
    /**
     Convention Fee.
     */
    PrimaryChargeTypeConventionFee = 8,
    /**
     Tennis.
     */
    PrimaryChargeTypeTennis = 9,
    /**
     Golf.
     */
    PrimaryChargeTypeGolf = 10,
};

enum CardPresentIndicator {
    /**
     The value is not set.
     */
    CardPresentIndicatorNotSet = 1,
    /**
     Card present.
     */
    CardPresentIndicatorCardPresent = 2,
    /**
     Card not present.
     */
    CardPresentIndicatorCardNotPresent = 3,
};

@end
