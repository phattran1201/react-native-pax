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
 Request host gateway.
 */

#import <Foundation/Foundation.h>
#import "PLSemiConst.h"
#import "PLAdminConst.h"
#import "PLHostGateway.h"

@interface PLHostGateway : NSObject
/**
 Host reference number (Transaction UID). This field is host dependent; it can be used to run Void/Return transactions.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 Gateway ID.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *gatewayId;
/**
 Send token request indicator to host to request token.

Default is No.

Whether the token is being returned depends on whether the host returns the token. It is acceptable to return a token with this field being set to No. So is the same oppositely. 
 */
@property (readwrite, nonatomic, assign)enum TokenRequestFlag tokenRequestFlag;
/**
 Token value.

 Attribute:ans...128 
 */
@property (readwrite, nonatomic, copy)NSString *token;
/**
 The card type. Refer to the POSLink2.Const.CardType.

Required for Multi Token Pay transaction for some hosts.

 Attribute:n2 
 */
@property (readwrite, nonatomic, copy)NSString *cardType;
/**
 Passthru data. Please use SetPassThruData method to assign.

 Attribute:ans...1024 
 */
@property (readwrite, nonatomic, copy)NSString *passThruData;
/**
 Reason For Retrun. 
 */
@property (readwrite, nonatomic, assign)enum HostGatewayReturnReason returnReason;
/**
 Station number/LaneID, StationID, RegisterID.

 Attribute:ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *stationId;
/**
 An unique ID for each transaction.

 Attribute:ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *globalUid;
/**
 The customized data can be used to generate customized billing or reports etc … for the merchant.

 Attribute:ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *customizeData1;
/**
 The customized data can be used to generate customized billing or reports etc … for the merchant.

 Attribute:ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *customizeData2;
/**
 The customized data can be used to generate customized billing or reports etc … for the merchant.

 Attribute:ans...36 
 */
@property (readwrite, nonatomic, copy)NSString *customizeData3;
/**
 This is only applicable when a transaction is a eWIC type. It is used as a discount or coupon.

 Attribute:n...9 
 */
@property (readwrite, nonatomic, copy)NSString *ewicDiscountAmount;
/**
 It is used to specify the serial number for the account where the card token is stored.

 Attribute:ans...10 
 */
@property (readwrite, nonatomic, copy)NSString *tokenSerialNumber;

@end