# @haroldtran/react-native-pax

[![npm version](https://badge.fury.io/js/%40haroldtran%2Freact-native-pax.svg)](https://badge.fury.io/js/%40haroldtran%2Freact-native-pax)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

React Native library to integrate with PAX payment devices using the POSLink SDK. This library provides a bridge between React Native applications and PAX payment terminals for processing various payment transactions.

**Maintained and enhanced by [@phattran1201](https://github.com/phattran1201)**

## Features

- 🔄 Initialize PAX device connection
- 💳 Process credit card payments (Sale, Auth, Post-Auth)
- 🔄 Handle transaction adjustments and voids
- 📊 Batch operations and settlement
- 🔙 Process returns and refunds
- 📱 Support for both iOS and Android platforms

## Installation

```sh
npm install @haroldtran/react-native-pax
```

or with yarn:

```sh
yarn add @haroldtran/react-native-pax
```

### iOS Setup

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
  makePayment,
  makeAuth,
  makePostAuth,
  makeReturn,
  makeAdjustment,
  voidTransaction,
  closeBatch
} from '@haroldtran/react-native-pax';
```

### Initialize Connection

First, initialize the connection to your PAX device:

```js
try {
  const success = await initPOSLink(
    'TCP',        // Connection type: 'UART', 'TCP', 'SSL', 'HTTP', 'HTTPS', 'BLUETOOTH', 'USB', 'AIDL'
    '30000',      // Timeout in milliseconds
    false,        // Use proxy
    '192.168.1.100', // Device IP (for TCP/IP connections)
    '10009'       // Port number
  );

  if (success) {
    console.log('PAX device initialized successfully');
  }
} catch (error) {
  console.error('Failed to initialize PAX device:', error);
}
```

### Process a Payment

```js
try {
  const result = await makePayment('10.00', '1.50'); // amount, tip
  console.log('Payment result:', result);

  // Result contains transaction details like:
  // - AuthCode
  // - RefNum
  // - ApprovedAmount
  // - CardType
  // - MaskedPAN
  // etc.
} catch (error) {
  console.error('Payment failed:', error);
}
```

### Authorization Only

```js
try {
  const result = await makeAuth('25.00');
  console.log('Authorization result:', result);
} catch (error) {
  console.error('Authorization failed:', error);
}
```

### Post Authorization (Capture)

```js
try {
  const result = await makePostAuth(
    '25.00',           // amount
    'REF123456',       // original reference number
    'AUTH123'          // authorization code
  );
  console.log('Post-auth result:', result);
} catch (error) {
  console.error('Post-auth failed:', error);
}
```

### Process a Return

```js
try {
  const result = await makeReturn('15.00');
  console.log('Return result:', result);
} catch (error) {
  console.error('Return failed:', error);
}
```

### Void a Transaction

```js
try {
  const result = await voidTransaction(
    'REF123456',       // original reference number
    'AUTH123'          // authorization code
  );
  console.log('Void result:', result);
} catch (error) {
  console.error('Void failed:', error);
}
```

### Adjust a Transaction

```js
try {
  const result = await makeAdjustment(
    '12.50',           // new amount
    'REF123456'        // original reference number
  );
  console.log('Adjustment result:', result);
} catch (error) {
  console.error('Adjustment failed:', error);
}
```

### Close Batch

```js
try {
  const result = await closeBatch();
  console.log('Batch close result:', result);

  // Result contains batch summary:
  // - BatchNum
  // - CreditCount, CreditAmount
  // - DebitCount, DebitAmount
  // etc.
} catch (error) {
  console.error('Batch close failed:', error);
}
```

## API Reference

### initPOSLink(type, timeout, proxy, ip?, port?)

Initializes the connection to the PAX device.

**Parameters:**
- `type` (string): Connection type - 'UART', 'TCP', 'SSL', 'HTTP', 'HTTPS', 'BLUETOOTH', 'USB', 'AIDL'
- `timeout` (string): Timeout in milliseconds
- `proxy` (boolean): Whether to use proxy
- `ip` (string, optional): Device IP address (for network connections)
- `port` (string, optional): Port number (for network connections)

**Returns:** `Promise<boolean>`

### makePayment(amount, tip?)

Processes a sale transaction.

**Parameters:**
- `amount` (string): Transaction amount
- `tip` (string, optional): Tip amount (default: "0")

**Returns:** `Promise<PaymentResponse>`

### makeAuth(amount)

Processes an authorization-only transaction.

**Parameters:**
- `amount` (string): Authorization amount

**Returns:** `Promise<PaymentResponse>`

### makePostAuth(amount, refNum, authCode)

Captures a previously authorized transaction.

**Parameters:**
- `amount` (string): Capture amount
- `refNum` (string): Original reference number
- `authCode` (string): Authorization code

**Returns:** `Promise<PaymentResponse>`

### makeReturn(amount)

Processes a return transaction.

**Parameters:**
- `amount` (string): Return amount

**Returns:** `Promise<PaymentResponse>`

### makeAdjustment(amount, refNum)

Adjusts a previous transaction amount.

**Parameters:**
- `amount` (string): New amount
- `refNum` (string): Original reference number

**Returns:** `Promise<PaymentResponse>`

### voidTransaction(refNum, authCode)

Voids a previous transaction.

**Parameters:**
- `refNum` (string): Original reference number
- `authCode` (string): Authorization code

**Returns:** `Promise<PaymentResponse>`

### closeBatch()

Closes the current batch and settles transactions.

**Returns:** `Promise<BatchResponse>`

## Response Objects

### PaymentResponse

Contains transaction details including:
- `AuthCode`: Authorization code
- `RefNum`: Reference number
- `ApprovedAmount`: Approved amount
- `CardType`: Type of card used
- `MaskedPAN`: Masked card number
- `ResultCode`: Transaction result code
- `ResultTxt`: Result description
- And many more fields...

### BatchResponse

Contains batch settlement details including:
- `BatchNum`: Batch number
- `CreditCount` / `CreditAmount`: Credit transaction totals
- `DebitCount` / `DebitAmount`: Debit transaction totals
- `ResultCode`: Batch result code
- And more batch summary fields...

## Requirements

- React Native 0.63+
- iOS 11.0+
- Android API level 21+
- PAX payment terminal with POSLink SDK support

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

## Support

For PAX device documentation and support, visit [PAX Developer Portal](https://developer.pax.us).

---

Made with [create-react-native-library](https://github.com/callstack/react-native-builder-bob)