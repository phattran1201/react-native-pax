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
 Mifare Card Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLMifareCardRequest.h"

@interface PLMifareCardRequest : PLRequest
/**
 M1 Command type. 
 */
@property (readwrite, nonatomic, assign)enum M1CommandType m1Command;
/**
 Block number indicator.

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *blockNumber;
/**
 Password to authority. The field is mandatory when M1CommandType is "Read", "Write", "OperateWithIncreaseValue", "OperateWithDecreaseValue", and "OperateWithBackupValue".

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *password;
/**
 Password type. The field is mandatory when M1CommandType is "Read", "Write", "OperateWithIncreaseValue", "OperateWithDecreaseValue", and "OperateWithBackupValue" 
 */
@property (readwrite, nonatomic, assign)enum PasswordType passwordType;
/**
 Only valid when M1 Command type is:

Write: The format is HEX and the length must be 32. For example, "01234567890123ABCDEF" means "\x01\x23\x45\x67\x89\x01\x23\xAB\xCD\xEF".

OperateWithIncreaseValue: The format is decimal and the max length is 9.

OperateWithDecreaseValue: The format is decimal and the max length is 9.

 Attribute:ans...32 
 */
@property (readwrite, nonatomic, copy)NSString *blockValue;
/**
 Specify the block number which is used to write the operation result. Only valid when M1 Command type is:

OperateWithIncreaseValue: operate with increase value

OperateWithDecreaseValue: operate with decrease value

OperateWithBackupValue: operate with backup value

 Attribute:n...2 
 */
@property (readwrite, nonatomic, copy)NSString *updateBlockNumber;
/**
 Timeout in 100ms for detecting card. The valid value should be [0, 9999]. If value is null, it means no timeout and waiting for user cancelation or detecting card.

 Attribute:n...4 
 */
@property (readwrite, nonatomic, copy)NSString *timeout;


@end