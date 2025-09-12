# @haroldtran/react-native-pax

[![npm version](https://badge.fury.io/js/%40haroldtran%2Freact-native-pax.svg)](https://badge.fury.io/js/%40haroldtran%2Freact-native-pax)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

React Native library to integrate with PAX payment devices using the POSLink SDK. This library provides a bridge between React Native applications and PAX payment terminals for processing various payment transactions.

**Maintained and enhanced by [@phattran1201](https://github.com/phattran1201)**

## Features

- 🔄 Initialize PAX device connection via TCP/IP
- 💳 Process credit and debit card payments (Sale)
- 🔄 Handle voids (Void Sale)
- 📊 Batch operations and settlement
- 🔙 Process refunds (Return)
- 📱 Android platform support (iOS implementation pending)

## Installation

```sh
yarn add @haroldtran/react-native-pax
```

### iOS Setup

⚠️ **Note: iOS implementation is currently not complete. Only Android is fully supported at this time.**

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
  makeRefund,
  makeVoid,
  makeCloseBatch
} from '@haroldtran/react-native-pax';
```

### Initialize Connection

First, initialize the connection to your PAX device:

```js
try {
  const result = await initPOSLink('192.168.1.100'); // Pass the IP address of the POS device
  console.log('PAX device initialized:', result);
} catch (error) {
  console.error('Failed to initialize PAX device:', error);
}
```

### Process a Payment

```js
import { CreditTransactionType } from '@haroldtran/react-native-pax/lib/typescript/module/type';

try {
  const paymentResult = await makePayment(
    'txn-123',                    // id (optional)
    1000,                         // amount in cents (e.g., 1000 = $10.00)
    150,                          // tip in cents (optional, e.g., 150 = $1.50)
    CreditTransactionType.Credit, // paymentType (1 = Credit, 2 = Debit)
    'ECR123'                      // ecrRefNum (optional)
  );

  console.log('Payment result:', paymentResult);
  // paymentResult contains:
  // - status: boolean
  // - isPaymentSuccess: boolean
  // - cardHolder: string
  // - cardNumber: string (masked)
  // - refNum: string
  // - transactionId: string
  // - amount: string
  // - tipAmount: string
  // - cardType: string
  // - entryMethod: string
  // - and more transaction details
} catch (error) {
  console.error('Payment failed:', error);
}
```

### Process a Refund

```js
try {
  const refundResult = await makeRefund({
    amount: 1500  // amount in cents (e.g., 1500 = $15.00)
  });
  console.log('Refund result:', refundResult);
  // refundResult is a PaxResponseModel object
} catch (error) {
  console.error('Refund failed:', error);
}
```

### Void a Transaction

```js
try {
  const voidResult = await makeVoid({
    amount: 1500  // amount in cents (e.g., 1500 = $15.00)
  });
  console.log('Void result:', voidResult);
  // voidResult is a PaxResponseModel object
} catch (error) {
  console.error('Void failed:', error);
}
```

### Close Batch

```js
try {
  const batchResult = await makeCloseBatch();
  console.log('Batch close result:', batchResult);
  // batchResult is a PaxResponseModel object
} catch (error) {
  console.error('Batch close failed:', error);
}
```

## API Reference

#### initPOSLink(ip)

Initializes the connection to the PAX device.

**Parameters:**

- `ip` (string): Device IP address

**Returns:** `Promise<any>`

#### makePayment(id?, amount, tip?, paymentType?, ecrRefNum?)

Initiates a payment transaction.

**Parameters:**

- `id` (string, optional): Transaction ID
- `amount` (number): Payment amount in cents (e.g., 1000 = $10.00)
- `tip` (number, optional): Tip amount in cents (e.g., 150 = $1.50)
- `paymentType` (number, optional): Type of payment (1 = Credit, 2 = Debit, see `CreditTransactionType` enum)
- `ecrRefNum` (string, optional): ECR reference number

**Returns:** `Promise<PaxResponseModel>`

#### makeRefund(data)

Initiates a refund transaction.

**Parameters:**

- `data` (object): Object containing:
  - `amount` (number): The amount to refund in cents

**Returns:** `Promise<PaxResponseModel>`

#### makeVoid(data)

Voids a transaction for the given amount.

**Parameters:**

- `data` (object): Object containing:
  - `amount` (number): The amount to void in cents

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
| Initialize Connection | ✅       | ❌   |
| Payment Processing    | ✅       | ❌   |
| Refunds               | ❌       | ❌   |
| Voids                 | ❌       | ❌   |
| Batch Operations      | ❌       | ❌   |

## Contributing

See the [contributing guide](CONTRIBUTING.md) to learn how to contribute to the repository and the development workflow.

## License

MIT

## Support

For PAX device documentation and support, visit [PAX Developer Portal](https://developer.pax.us).
