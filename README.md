# @haroldtran/react-native-pax

[![npm version](https://badge.fury.io/js/%40haroldtran%2Freact-native-pax.svg)](https://badge.fury.io/js/%40haroldtran%2Freact-native-pax)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

React Native library to integrate with PAX payment devices using the POSLink SDK. This library provides a bridge between React Native applications and PAX payment terminals for processing various payment transactions.

**Maintained and enhanced by [@phattran1201](https://github.com/phattran1201)**

## Features

- 🔌 Connect over **any POSLink transport**: `TCP`, `SSL`, `HTTP`, `HTTPS`, `UART`, `USB`, `AIDL`, `BLUETOOTH` (via `initPOSLinkConn`)
- 🔎 Device discovery helpers for building a connect UI (USB / serial / Bluetooth scanning)
- 💳 Process credit and debit card payments (Sale)
- 🔄 Handle voids (Void Sale)
- 📊 Batch operations and settlement
- 🔙 Process refunds (Return)
- 📱 Android (full) + iOS (network & Bluetooth) support

> 📖 For the complete, step-by-step integration walkthrough — every connection type, device-picker UI, permissions, and error handling — see **[CONNECTION_GUIDE.md](CONNECTION_GUIDE.md)**.

## Installation

```sh
yarn add @haroldtran/react-native-pax
```

### iOS Setup

> iOS is supported. As of **v1.1.0** the iOS native module is at feature parity with Android for the transaction and connection APIs (`TCP`/`SSL`/`HTTP`/`HTTPS`/`BLUETOOTH`). `UART`/`USB`/`AIDL` are Android-only and are rejected on iOS with `UNSUPPORTED_CONN_TYPE`.

#### Fixing Symbol Conflicts (Required)

This library bundles `libPOSLinkAdmin.a`, which exports the same `unz*`/`zip*` symbols as `SSZipArchive`. Without the fix, the linker will throw duplicate symbol errors at build time.

To resolve this, use the provided helper `react_native_pax_pods.rb`:

**1. Require the helper at the top of your `Podfile`:**

```ruby
require_relative '../node_modules/@haroldtran/react-native-pax/react_native_pax_pods'
```

**2. Call it inside your `post_install` block:**

```ruby
post_install do |installer|
  react_native_pax_pods(installer) # <== add this
  # ... other post_install steps
end
```

What this does: it prefixes all conflicting `unz*`/`zip*` symbols in `SSZipArchive` with `ssz_` via `GCC_PREPROCESSOR_DEFINITIONS`, so the linker sees distinct names and the conflict is resolved.

#### iOS Simulator on Apple Silicon (Required if you build for the Simulator)

The bundled PAX static libraries (`libPOSLinkAdmin.a`, `libPOSLinkSemiIntegration.a`) are **fat libs containing `x86_64` + `arm64`, but the `arm64` slice is built for iOS *device* only** — the vendor does not ship an `arm64` *simulator* slice.

On an Apple Silicon Mac (M1/M2/M3) the Simulator is `arm64`, so the linker picks the device `arm64` slice and fails with:

```
Building for 'iOS-simulator', but linking in object file
(.../libPOSLinkAdmin.a[arm64][...](...o)) built for 'iOS'
Linker command failed with exit code 1
```

You have two options:

- **Recommended — build on a real device.** The `arm64` device slice matches and links fine. (A card terminal SDK has to be tested on a real device anyway.)
- **To run on the Simulator**, force it to use the `x86_64` slice by excluding `arm64` for the simulator SDK. Add to your `Podfile` `post_install`:

  ```ruby
  post_install do |installer|
    react_native_pax_pods(installer)
    installer.pods_project.build_configurations.each do |config|
      config.build_settings['EXCLUDED_ARCHS[sdk=iphonesimulator*]'] = 'arm64'
    end
    # ... other post_install steps
  end
  ```

  Also set the same `EXCLUDED_ARCHS[sdk=iphonesimulator*] = arm64` on your **app target**, and run Xcode/Simulator under Rosetta.

> The proper long-term fix is for PAX to ship an `.xcframework` (which can hold a separate `arm64` simulator slice). Until then, the workaround above is required for Simulator builds.

#### General iOS Setup

1. Navigate to your iOS project directory and install pods:

```sh
cd ios && pod install
```

2. Make sure your iOS deployment target is 11.0 or higher in your `Podfile`:

```ruby
platform :ios, '11.0'
```

### Android Setup

The Android setup is automatic. The library will be linked automatically when you rebuild your project.

## Usage

### Import the library

```js
import {
  initPOSLink,
  initPOSLinkConn,
  makePayment,
  makeRefund,
  makeVoid,
  makeCloseBatch,
} from '@haroldtran/react-native-pax';
```

### Initialize Connection

#### The general way (recommended) — `initPOSLinkConn(config)`

`initPOSLinkConn` connects over any transport the SDK supports. Pass a config object whose `type` selects the transport; only the fields relevant to that type are used.

```js
// Network (most common) — TCP / SSL / HTTP / HTTPS
await initPOSLinkConn({ type: 'TCP', ip: '192.168.1.100', port: '10009' });
await initPOSLinkConn({ type: 'SSL', ip: '192.168.1.100', port: '10009' });

// Serial (Android)
await initPOSLinkConn({ type: 'UART', serialPort: 'COM1', baudRate: '9600' });

// USB (Android) — auto-requests USB permission on connect
await initPOSLinkConn({ type: 'USB' });                 // optional: { deviceName }

// AIDL (Android) — app running on the PAX device itself (BroadPOS)
await initPOSLinkConn({ type: 'AIDL' });

// Bluetooth / BLE
await initPOSLinkConn({ type: 'BLUETOOTH', macAddr: 'AA:BB:CC:DD:EE:FF' });
```

| `type`               | Required fields          | Optional fields         | Platform      |
| -------------------- | ------------------------ | ----------------------- | ------------- |
| `TCP`/`SSL`/`HTTP`/`HTTPS` | `ip`, `port`       | `timeout`               | Android + iOS |
| `UART`               | `serialPort`, `baudRate` | `timeout`               | Android       |
| `USB`                | —                        | `deviceName`, `timeout` | Android       |
| `AIDL`               | —                        | —                       | Android       |
| `BLUETOOTH`          | `macAddr`                | `timeout`               | Android + iOS |

- `port` defaults to `10009`, `timeout` defaults to `60000` ms.
- On iOS, `UART`/`USB`/`AIDL` are rejected with `UNSUPPORTED_CONN_TYPE`.
- Returns a `PaxInitModel`: `{ status: boolean, serialNumber?: { modelName, appName, serialNumber } }`. **Only proceed to transactions when `status === true`.**

To build a UI that lets the user pick/scan a device (USB list, serial ports, Bluetooth scan) and to handle runtime permissions, see **[CONNECTION_GUIDE.md](CONNECTION_GUIDE.md)** — it includes a full `ConnectScreen` example and the helper APIs (`listUsbDevices`, `getSupportedBaudRates`, `listSerialPorts`, `checkBluetoothEnable`, `startBluetoothSearch`, `getBluetoothDeviceList`, `stopBluetoothSearch`, `requestUsbPermission`).

#### The legacy way (TCP only) — `initPOSLink(ip)`

Kept for backward compatibility; equivalent to `initPOSLinkConn({ type: 'TCP', ip, port })`.

```js
try {
  const result = await initPOSLink('192.168.1.100'); // IP of the POS device
  // or: await initPOSLink('192.168.1.100', { port: '10009', timeout: 60000 });
  console.log('PAX device initialized:', result);
} catch (error) {
  console.error('Failed to initialize PAX device:', error);
}
```

### Process a Payment

`makePayment(id?, amount, tip?, paymentType?, ecrRefNum?, showTip?)` — **positional** arguments. Pass `undefined` for any optional argument you want to skip. **All money values are in cents** (`1000` = `$10.00`).

```js
import { makePayment, CreditTransactionType } from '@haroldtran/react-native-pax';

try {
  const paymentResult = await makePayment(
    'txn-123', // 1. id?         — your transaction id (optional; pass undefined to skip)
    1000, // 2. amount      — REQUIRED, in cents. 1000 = $10.00
    150, // 3. tip?        — tip in cents (optional). 150 = $1.50; use 0/undefined for none
    CreditTransactionType.Credit, // 4. paymentType? — 1 = Credit (default), 2 = Debit
    'ECR123', // 5. ecrRefNum?  — YOUR reference. STRONGLY recommended: you need it later to void/refund
    true // 6. showTip?    — true = let the customer enter a tip on the terminal
  );

  console.log('Payment result:', paymentResult);
  // paymentResult (PaxResponseModel) contains:
  // - status: boolean            — overall success
  // - isPaymentSuccess: boolean  — payment-specific success
  // - cardHolder / cardNumber (masked) / cardType / entryMethod
  // - refNum / transactionId / transactionNo / transactionDateTime
  // - amount / tipAmount / surcharge
  // - message, data (raw detail), sn ...
} catch (error) {
  console.error('Payment failed:', error);
}
```

**Minimal call** (just charge $10.00, no tip UI):

```js
await makePayment(undefined, 1000, undefined, CreditTransactionType.Credit, 'ECR123', false);
```

> ⚠️ Always pass a unique `ecrRefNum` — it is the key you use to `makeVoid`/`makeRefund`/`checkVoidOrRefundTransaction` that same transaction later.

### Process a Refund

`makeRefund(amount, ecrRefNum)` — both **required**.

```js
try {
  const refundResult = await makeRefund(
    1500, // amount to refund, in cents. 1500 = $15.00
    'ECR123' // ecrRefNum of the ORIGINAL transaction being refunded
  );
  console.log('Refund result:', refundResult); // PaxResponseModel
} catch (error) {
  console.error('Refund failed:', error);
}
```

### Void a Transaction

`makeVoid(ecrRefNum)` — voids the transaction by its ECR reference (no amount needed).

```js
try {
  const voidResult = await makeVoid('ECR123'); // ecrRefNum of the transaction to void
  console.log('Void result:', voidResult); // PaxResponseModel
} catch (error) {
  console.error('Void failed:', error);
}
```

### Close Batch

`makeCloseBatch()` — takes no arguments; settles the current batch.

```js
try {
  const batchResult = await makeCloseBatch();
  console.log('Batch close result:', batchResult); // PaxResponseModel
} catch (error) {
  console.error('Batch close failed:', error);
}
```

### Other operations

```js
import {
  cancelTransaction,
  checkVoidOrRefundTransaction,
  getBatchInformation,
} from '@haroldtran/react-native-pax';

// Cancel the command currently running on the terminal (no args)
await cancelTransaction();

// Check whether a given ECR ref can be voided/refunded (pass the ecrRefNum)
const info = await checkVoidOrRefundTransaction('ECR123');

// Read the current batch totals (no args) → PaxBatchInformationResponseModel
const batch = await getBatchInformation();
```

### Full flow example (connect → pay → void)

```js
import {
  initPOSLinkConn,
  makePayment,
  makeVoid,
  CreditTransactionType,
} from '@haroldtran/react-native-pax';

async function run() {
  // 1. Connect (TCP here; swap `type` for USB/Bluetooth/etc.)
  const conn = await initPOSLinkConn({
    type: 'TCP',
    ip: '192.168.1.100',
    port: '10009',
    timeout: 60000,
  });
  if (!conn.status) throw new Error('Not connected');

  // 2. Charge $10.00 as Credit, allow tip on terminal, keep our ref
  const ecrRefNum = `ECR-${Date.now()}`;
  const pay = await makePayment(
    undefined, // id
    1000, // amount (cents)
    undefined, // tip
    CreditTransactionType.Credit,
    ecrRefNum,
    true // showTip
  );
  if (!pay.isPaymentSuccess) throw new Error(pay.message);

  // 3. Later, void that same transaction using its ecrRefNum
  await makeVoid(ecrRefNum);
}
```

## API Reference

#### initPOSLinkConn(config)

Initializes the connection to the PAX device over any supported transport.

**Parameters:**

- `config` (PaxConnConfig): `{ type, ip?, port?, serialPort?, baudRate?, deviceName?, macAddr?, timeout? }` — see the connection-types table above.

**Returns:** `Promise<PaxInitModel>` — `{ status, serialNumber? }`

#### initPOSLink(ip, options?)

Legacy TCP-only initializer (equivalent to `initPOSLinkConn({ type: 'TCP', ... })`).

**Parameters:**

- `ip` (string): Device IP address
- `options` (object, optional): `{ port?: string; timeout?: number }`

**Returns:** `Promise<PaxInitModel>`

#### makePayment(id?, amount, tip?, paymentType?, ecrRefNum?, showTip?)

Initiates a payment transaction.

**Parameters:**

- `id` (string, optional): Transaction ID
- `amount` (number): Payment amount in cents (e.g., 1000 = $10.00)
- `tip` (number, optional): Tip amount in cents (e.g., 150 = $1.50)
- `paymentType` (number, optional): Type of payment (1 = Credit, 2 = Debit, see `CreditTransactionType` enum)
- `ecrRefNum` (string, optional): ECR reference number (recommended — required to void/refund later)
- `showTip` (boolean, optional): `true` to let the customer enter a tip on the terminal

**Returns:** `Promise<PaxResponseModel>`

#### makeRefund(amount, ecrRefNum)

Initiates a refund transaction.

**Parameters:**

- `amount` (number): The amount to refund in cents
- `ecrRefNum` (string): ECR reference number of the original transaction

**Returns:** `Promise<PaxResponseModel>`

#### makeVoid(ecrRefNum)

Voids the transaction with the given ECR reference number.

**Parameters:**

- `ecrRefNum` (string): ECR reference number of the transaction to void

**Returns:** `Promise<PaxResponseModel>`

#### makeCloseBatch()

Closes the current batch of transactions.

**Returns:** `Promise<PaxResponseModel>`

## Response Objects

### PaxResponseModel

The response object returned by all transaction functions. Key fields include:

**Status & Result:**

- `status` (boolean): Overall operation success status
- `isPaymentSuccess` (boolean): Payment-specific success flag
- `message` (string): Response message or error description

**Transaction Details:**

- `id` (string): Transaction ID
- `transactionId` (string): Global unique transaction identifier
- `transactionNo` (string): Transaction sequence number
- `refNum` (string): Reference number
- `transactionDateTime` (string): Date/time of transaction

**Card & Payment Info:**

- `cardType` (string): Card type/brand (e.g., VISA, MASTERCARD)
- `cardNumber` (string): Masked card number
- `cardHolder` (string): Card holder name
- `entryMethod` (string): How card was entered (SWIPED_MSD, CONTACT_CHIP, CONTACTLESS_CHIP, etc.)

**Amount Details:**

- `amount` (string): Transaction amount
- `tipAmount` (string): Tip amount
- `surcharge` (string): Additional fees/surcharge

**Additional Data:**

- `data` (object): Detailed response data including account info, trace info, AVS info, etc.
- `sn` (string): Serial number

### CreditTransactionType Enum

Available payment types:

- `CreditTransactionType.Credit` (1): Credit card transaction
- `CreditTransactionType.Debit` (2): Debit card transaction
- `CreditTransactionType.Empty` (0): Not set/default

See `src/type.ts` for the complete interface definition.

## Requirements

- React Native 0.63+
- **Android API level 21+ (Full support)**
- **iOS 11.0+ (Limited support - implementation pending)**
- PAX payment terminal with POSLink SDK support
- TCP/IP network connection to PAX terminal

## Current Platform Support

| Feature               | Android | iOS |
| --------------------- | ------- | --- |
| Initialize Connection | ✅      | ✅  |
| Payment Processing    | ✅      | ✅  |
| Refunds               | ✅      | ✅  |
| Voids                 | ✅      | ✅  |
| Batch Operations      | ✅      | ✅  |

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

## Support

For PAX device documentation and support, visit [PAX Developer Portal](https://developer.pax.us).
