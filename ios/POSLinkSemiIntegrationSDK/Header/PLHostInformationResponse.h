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
 Response Host Information.
 */

#import <Foundation/Foundation.h>
#if __has_include(<POSLinkAdmin/PLSemiConst.h>)
   #import <POSLinkAdmin/PLSemiConst.h>
#elif __has_include("PLSemiConst.h")
   #import "PLSemiConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLAdditionalResponseData.h>)
   #import <POSLinkAdmin/PLAdditionalResponseData.h>
#elif __has_include("PLAdditionalResponseData.h")
   #import "PLAdditionalResponseData.h"
#endif


#if __has_include(<POSLinkAdmin/PLHostInformationResponse.h>)
   #import <POSLinkAdmin/PLHostInformationResponse.h>
#elif __has_include("PLHostInformationResponse.h")
   #import "PLHostInformationResponse.h"
#endif



@interface PLHostInformationResponse : NSObject
/**
 Host returned the result code, if declined display host error on the ECR's screen.

 Attribute : ans...8 
 */
@property (readwrite, nonatomic, copy)NSString *hostResponseCode;
/**
 Host returned error message. If host returns error message, this field is mandatory.

 Attribute : ans...255 
 */
@property (readwrite, nonatomic, copy)NSString *hostResponseMessage;
/**
 Host returned authorization code, if host returns it, this field is mandatory and suggest printing this on receipt.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCode;
/**
 The transaction reference number returned from a host.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *hostReferenceNumber;
/**
 Host returned batch number, if host returns it, this field is mandatory.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *batchNumber;
/**
 The transaction reference number returned from a gateway directly.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *gatewayTransactionId;
/**
 Additional detailed message or code returned from the host.

 Attribute : ans...400 
 */
@property (readwrite, nonatomic, copy)NSString *hostDetailedMessage;
/**
 Transaction Integrity Class is assigned by MasterCard for a U.S. merchant in an authorization response message.

 Attribute : an...10 
 */
@property (readwrite, nonatomic, copy)NSString *transactionIntegrityClass;
/**
 Assigned by the host and used to track a transaction until settlement.

 Attribute : n12 
 */
@property (readwrite, nonatomic, copy)NSString *retrievalReferenceNumber;
/**
 This information is stored for the integrator for receipts, additional details on a transaction decline, reporting, etc.

 Attribute : an2 
 */
@property (readwrite, nonatomic, copy)NSString *issuerResponseCode;
/**
 The unique identifier is associated with a specific cardholder PAN. Non-sensitive value that can be stored/managed in place of a PAN or Token. Typically used for card-brand loyalty benefits.

 Attribute : ans...64 
 */
@property (readwrite, nonatomic, copy)NSString *paymentAccountReferenceId;
/**
 Value returned by the host to identify each transaction with a portion of sales and use tax.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *controlNumber;
/**
 Host raw response message.

 Attribute : ans...2048 
 */
@property (readwrite, nonatomic, copy)NSString *hostEchoData;
/**
 Additional lines for printing from host.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine1;
/**
 Additional lines for printing from host.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine2;
/**
 Additional lines for printing from host.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine3;
/**
 Additional lines for printing from host.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine4;
/**
 Additional lines for printing from host.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *printLine5;
/**
 Additional response data. 
 */
@property (readwrite, nonatomic, strong)PLAdditionalResponseData *additionalResponseData;
/**
 Payment method user selected. It can be Alipay, WeChat Pay.

 Attribute : ans...20 
 */
@property (readwrite, nonatomic, copy)NSString *paymentMethod;

@end