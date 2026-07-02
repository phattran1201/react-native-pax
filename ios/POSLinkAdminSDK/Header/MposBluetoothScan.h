//
//  MposBluetoothScan.h
//  MposComm
//
//  Created by kevintu@paxsz.com on 5/4/15.
//  Copyright (c) 2015 pax. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @abstract the bluetooth device type enumeration
 @constant BT_TYPE_EA       the external accessory (under version 4.0)
 @constant BT_TYPE_BLE      the BLE (version 4.0 or above)
 */
typedef enum {
    BT_TYPE_EA  = 1 << 0,
    BT_TYPE_BLE = 1 << 1
} BtType;

/*!
 @abstract the bluetooth device
 */
@interface BtDevice : NSObject

/*!
 @abstract init with parameters
 @param type    device type
 @param name    name
 @param address address(MAC address for BT_TYPE_EA, UUID string for BT_TYPE_BLE)
 */
- (id)initWithType:(BtType)type name:(NSString *)name address:(NSString *)address;

/*!
 @abstract the bluetooth device type
 */
@property BtType type;
/*!
 @abstract name
 */
@property (copy) NSString *name;
/*!
 @abstract address(MAC address for BT_TYPE_EA, UUID string for BT_TYPE_BLE)
 */
@property (copy) NSString *address;
/*!
 @abstract The current RSSI of peripheral, in dBm. A value of 127 is reserved and indicates the RSSI
 	was not available.
 */
@property int RSSI;

@end

/*!
 @abstract a block called when discovered a bluetooth device
 @param device
    the discovered bluetooth device
 */
typedef void (^didDiscoveredBlock)(BtDevice *device);

/*!
 @abstract a blocked called when bluetooth device scanning is finished
 */
typedef void (^didFinishedBlock)();

/*!
 @abstract the class provides methods to start or stop scanning bluetooth devices
 */
@interface MposBluetoothScan : NSObject

/*!
 @abstract get a shared instance of MposBluetoothScan
 @return the shared instance of MposBluetoothScan
 */
+ (id) sharedInstance;

/*!
 @abstract start scanning bluetooth devices, can be called in main thread
 @param timeout Scan timeout value, in seconds.
 @param didDiscovered This block is called in the main thread when a device is discovered.
 @param didFinished This block is called in the main thread when the scanning process is finished.
 @param needUpdateRSSI A flag to indicate if RSSI updates are required. This is only appliable for BT_TYPE_BLE.\n
 Note: If the flag is set to YES, didDiscoveredBlock may return the same peripheral multiple
 times.
 */
- (void)startWithTimeout:(NSInteger)timeout
          didDiscovered:(didDiscoveredBlock)didDiscovered
            didFinished:(didFinishedBlock)didFinished
            needUpdateRSSI:(BOOL)needUpdateRSSI;

/*!
 @abstract stop scanning
 */
- (void)stop;

@end
