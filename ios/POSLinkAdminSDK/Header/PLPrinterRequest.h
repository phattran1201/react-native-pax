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
 Printer Request
 */

#import <Foundation/Foundation.h>
#import "PLRequest.h"

#import "PLAdminConst.h"
#import "PLPrinterRequest.h"

@interface PLPrinterRequest : PLRequest
/**
 How many receipts want to print. Default is 1.

 Attribute:n1 
 */
@property (readwrite, nonatomic, copy)NSString *printCopy;
/**
 Variable length up to 4000.Refer to the section of PrintData for how to format the print data.The ASCII characters which from 0x40 to 0x7F can be printable.

 Attribute:ans...4000 
 */
@property (readwrite, nonatomic, copy)NSString *printData;


@end