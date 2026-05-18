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
 Additional Response Data.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLAdditionalResponseData.h"

@interface PLAdditionalResponseData : NSObject
/**
 ACI for Visa.

 Attribute:ans...1 
 */
@property (readwrite, nonatomic, copy)NSString *aci;
/**
 TransID for Visa or AmExTranID for AMEX.

 Attribute:ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *transactionId;
/**
 CardLevelResult for Visa.

 Attribute:ans...2 
 */
@property (readwrite, nonatomic, copy)NSString *cardLevelResult;
/**
 SourceReasonCode for Visa.

 Attribute:ans...1 
 */
@property (readwrite, nonatomic, copy)NSString *sourceReasonCode;
/**
 BanknetData for MasterCard.

 Attribute:ans...13 
 */
@property (readwrite, nonatomic, copy)NSString *bankNetData;
/**
 POSEntryModeChange for MasterCard.

 Attribute:ans...1 
 */
@property (readwrite, nonatomic, copy)NSString *posEntryModeChange;
/**
 TransEditErrCode for MasterCard.

 Attribute:ans...1 
 */
@property (readwrite, nonatomic, copy)NSString *transactionEditErrorCode;
/**
 DiscoverProcessCode for Discover.

 Attribute:ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *discoverProcessCode;
/**
 DiscoverPOSEntry for Discover.

 Attribute:ans...4 
 */
@property (readwrite, nonatomic, copy)NSString *discoverPosEntry;
/**
 DiscoverResponseCode for Discover.

 Attribute:ans...2 
 */
@property (readwrite, nonatomic, copy)NSString *discoverResponseCode;
/**
 MCPOSData for MarsterCard or DiscPOSData for Discover or AmExPOSData for AMEX.

 Attribute:ans...13 
 */
@property (readwrite, nonatomic, copy)NSString *posData;
/**
 DiscoverTransQualifier for Discover.

 Attribute:ans...2 
 */
@property (readwrite, nonatomic, copy)NSString *discoverTransactionQualifier;
/**
 DiscoverNRID for Discover.

 Attribute:ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *discoverNrid;
/**
 Transmission Date time date/time in GMT/UTC with YYYYMMDDHHMMSS format.

 Attribute:ans...14 
 */
@property (readwrite, nonatomic, copy)NSString *transmissionDatetime;
/**
 Original STAN for later Void/PostAuthorization transaction.

 Attribute:ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *originalStan;
/**
 CVVErrorCode for MasterCard.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *cvvErrorCode;
/**
 XCodeResponse for EMV.

 Attribute:ans...6 
 */
@property (readwrite, nonatomic, copy)NSString *xCodeResponse;
/**
 Authorizing Network ID.

 Attribute:ans...3 
 */
@property (readwrite, nonatomic, copy)NSString *authorizingNetworkId;
/**
 Term entry capable.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *termEntryCapable;
/**
 POS entry mode.

 Attribute:n...3 
 */
@property (readwrite, nonatomic, copy)NSString *posEntryMode;
/**
 ServiceCode for EMV.

 Attribute:ans...3 
 */
@property (readwrite, nonatomic, copy)NSString *serviceCode;
/**
 SpendQInd for Visa.

 Attribute:ans...1 
 */
@property (readwrite, nonatomic, copy)NSString *spendQInd;
/**
 WltID for MasterCard.

 Attribute:ans...3 
 */
@property (readwrite, nonatomic, copy)NSString *wltId;
/**
 Local Transaction Date time date/time in YYYYMMDDHHMMSS format.

 Attribute:n...14 
 */
@property (readwrite, nonatomic, copy)NSString *localDateTime;
/**
 EMV Tags form EMV cards in string format.

 Attribute:ans...512 
 */
@property (readwrite, nonatomic, copy)NSString *emvTags;

@end