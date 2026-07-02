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
 Error code 100023
 */

#import <Foundation/Foundation.h>

#if __has_include(<POSLinkAdmin/PLAdminConst.h>)
   #import <POSLinkAdmin/PLAdminConst.h>
#elif __has_include("PLAdminConst.h")
   #import "PLAdminConst.h"
#endif


#if __has_include(<POSLinkAdmin/PLCode100023.h>)
   #import <POSLinkAdmin/PLCode100023.h>
#elif __has_include("PLCode100023.h")
   #import "PLCode100023.h"
#endif



@interface PLCode100023 : NSObject
/**
 Unknown error. 
 */
@property (readwrite, nonatomic, copy)NSString *unknownError;
/**
 When cancelling host connection, terminal will return "USER ABORTED" to ECR. 
 */
@property (readwrite, nonatomic, copy)NSString *userAborted;
/**
 Only partially approved transactions can do REVERSAL for Apriva. 
 */
@property (readwrite, nonatomic, copy)NSString *cannotReversal;
/**
 The transaction cannot do void transaction 
 */
@property (readwrite, nonatomic, copy)NSString *cannotVoid;
/**
 Delete transaction failed 
 */
@property (readwrite, nonatomic, copy)NSString *deleteTransactionFailed;
/**
 Multiple records found 
 */
@property (readwrite, nonatomic, copy)NSString *multipleRecordsFound;
/**
 The transaction is not found 
 */
@property (readwrite, nonatomic, copy)NSString *notFound;

@end