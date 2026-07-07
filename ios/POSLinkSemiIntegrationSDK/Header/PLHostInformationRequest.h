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


#if __has_include(<POSLinkAdmin/PLHostInformationRequest.h>)
   #import <POSLinkAdmin/PLHostInformationRequest.h>
#elif __has_include("PLHostInformationRequest.h")
   #import "PLHostInformationRequest.h"
#endif



@interface PLHostInformationRequest : NSObject
/**
 Reason For Return.

 Attribute : n1 
 */
@property (readwrite, nonatomic, assign)enum HostGatewayReturnReason returnReason;
/**
 The customized data can be used to generate customized billing or reports etc … for the merchant.

 Attribute : ans...800 
 */
@property (readwrite, nonatomic, copy)NSString *customizeData1;
/**
 The customized data can be used to generate customized billing or reports etc … for the merchant.

 Attribute : ans...800 
 */
@property (readwrite, nonatomic, copy)NSString *customizeData2;
/**
 The customized data can be used to generate customized billing or reports etc … for the merchant.

 Attribute : ans...800 
 */
@property (readwrite, nonatomic, copy)NSString *customizeData3;
/**
 The host authorization code, the transaction type is "Forced", this field is NULL, terminal will prompt dialog to enter it.

 Attribute : ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *authorizationCode;
/**
 This data is defined by the POS developer and must be within 4096 bytes. If this field has been set, the PAX terminal won't store and parse the content of this field; It will follow the host related specification or POS developer requirement and send it in the request message.

 Attribute : ans...4096 
 */
@property (readwrite, nonatomic, copy)NSString *posEchoData;
/**
 Allows merchants to add a dynamic suffix value to a shortened version of the merchant DBA (Doing Business As) name for each transaction. This can help explain charges on the cardholder's bank statements by specifying details about the product, service, or payment causing a reduction in chargebacks and disputes by providing a clear understanding of purchases on customer's statements. Example: If this field is set to "Store #1234" then it may appear on the statement as MerchantDBA*Store #1234.

 Attribute : ans...15 
 */
@property (readwrite, nonatomic, copy)NSString *statementDescriptor;

@end