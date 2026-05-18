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
#import "PLCommunicationSetting.h"
#import "PLLogSetting.h"
#import "PLUploadLogResult.h"


typedef void (^ReportStatusBlock) (int value);


NS_ASSUME_NONNULL_BEGIN

@class PLManage;
@class PLForm;
@class PLDevice;
@class PLPed;
@class PLPayload;
@interface PLBaseTerminal : NSObject

@property (nonatomic, readonly, strong)PLCommunicationSetting *communicationSetting;

@property (nonatomic, readonly, copy)ReportStatusBlock reportStatusChangeBlock;

/**
 * Get an instance of PLManage
*/
- (PLManage *)getManage;
/**
 * Get an instance of PLForm
*/
- (PLForm *)getForm;
/**
 * Get an instance of PLDevice
*/
- (PLDevice *)getDevice;
/**
 * Get an instance of PLPed
*/
- (PLPed *)getPed;
/**
 * Get an instance of PLPayload
*/
- (PLPayload *)getPayload;
/**
 * Cancel
 * @param error NSError
 */
- (void)cancelWithError:(NSError **)error;
/**
 * Constructor
 * @param communicationSetting PLCommunicationSetting
 */
- (instancetype)initWithCommunicationSetting:(PLCommunicationSetting *)communicationSetting;
/**
 * Regist report status
 * @param reportStatusBlock ReportStatusBlock
 */
- (void)registReportStatus:(ReportStatusBlock)reportStatusBlock;
/**
 *Call POSLink to tell terminal to upload terminal logs and then POSLink upload POSLink log itself. Terminal logs and POSLink logs will be uploaded to the server specified by the terminal.\n
 *Need to set CommSetting to communicate with the terminal. \n
 *Note:\n
 *1.When terminal upload log, the log which is uploaded successful will be delete from terminal.\n
 *2.The terminal log is saved in only one log file, won't be split into many files by date, so whenever you use upload log command the terminal will only upload one file.\n
 *3.Only some necessary information or exceptions occur or errors occur, the log will be generated.\n
 *The disclaimers: https://www.pax.us/privacy-policy/.\n
 */
- (void)uploadLogWithCompletion:(void(^)(PLUploadLogResult *uploadResult))completion;

@end


NS_ASSUME_NONNULL_END
