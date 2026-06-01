

## [1.0.21](https://github.com/phattran1201/react-native-pax/compare/v1.0.20...v1.0.21) (2026-05-29)

### Features

* **iOS Support & SDK Integration**: Integrated the PAX POSLink Semi-Integration iOS SDK (`POSLinkSemiIntegrationSDK` static library and header files) enabling native POS integration on iOS devices. ([87818d5](https://github.com/phattran1201/react-native-pax/commit/87818d5a05d2ce8dc59556e7820214f9c1beae1d), [a0afa7f](https://github.com/phattran1201/react-native-pax/commit/a0afa7f8742004df4adec29a2e8526e990515485))
* **Unified TurboModule Architecture**: Migrated the package architecture to a unified TurboModule structure (`NativePaxPoslink.ts`) with modern codegen support while maintaining backward compatibility with the legacy React Native bridge.
* **Exposed iOS Native Methods**:
  * `initPOSLink(ip, port, timeout)`: Initializes TCP communication with PAX terminals, supporting customizable port and timeout configurations.
  * `makePayment(id, amount, tip, paymentType, ecrRefNum, showTip)`: Supports credit/debit transaction sales with optional tips and terminal-side tip prompts.
  * `makeRefund(amount, ecrRefNum)`: Supports credit refund/return operations.
  * `makeVoid(ecrRefNum)`: Voids specified credit transactions.
  * `makeCloseBatch()`: Triggers batch closeouts and processes batch counts/totals.
  * `getBatchInformation()`: Retrieves history and total details of the active batch.
  * `checkVoidOrRefundTransaction(ecrRefNum)`: Queries local report database to check transaction status.
  * `cancelTransaction()`: Requests terminal cancellation and cleans up the active connection object.
* **Response Mapping Optimization**:
  * Unified transaction response shapes with full parsing of authorization, host information, reference numbers, entry mode translations (e.g., contactless chip, contact chip, fallback swipe), card brand labels, and tip/surcharge fees.

### Build & Toolchain

* **NPM & Bob Config**: Configured `react-native-builder-bob` to automatically build ESM (`lib/module`), CommonJS (`lib/commonjs`), and TypeScript type declarations (`lib/typescript`).
* **Package Scripts**: Added `"build": "bob build"` and integrated automatic compilation into the `prebuild` phase for better safety and DX.

## [1.0.20](https://github.com/phattran1201/react-native-pax/compare/v1.0.19...v1.0.20) (2026-05-22)

### Refactors & Maintenance

* **Android PAX JAR Updates**: Updated Android dependencies inside `android/libs/` to the latest stable versions: ([84e66b3](https://github.com/phattran1201/react-native-pax/commit/84e66b38e4fbc4800c6be475b68cbbe59a4201f4))
  * `POSLink_Admin_Android_Plugin_V2.00.00_20230828.jar`
  * `POSLink_Core_Android_V2.00.03_20230828.jar`
* **Repository Cleanup**: Added `.omc/` caching directories to `.gitignore` to keep repository changes clean and focused.

## [1.0.19](https://github.com/phattran1201/react-native-pax/compare/v1.0.18...v1.0.19) (2026-04-03)

### Features

* **Batch Information Querying**: Introduced `getBatchInformation()` support on Android, allowing clients to query current batch status, record counts, and totals. ([cbf2cbe](https://github.com/phattran1201/react-native-pax/commit/cbf2cbec2b978aa4b451b2aa8e5771df543e00a8))
* **Model Extensions**: Expanded TypeScript models (`src/type.ts`) with robust structures to represent full batch history:
  * `PaxHistoryData`: Detailed total amount and counts maps across multiple card networks and payment modes (Credit, Debit, EBT, Gift, Loyalty, Cash, Check).
  * `PaxBatchInformationResponseModel`: Complete structure containing success state, ECR ref numbers, total records/amounts, and nested history datasets.
  * `PaxStatusResponseModel` & `PaxTorInformation`: Models for retrieving transaction offline reversal information, including gateway/host details, masked PANs, and authorization codes.
* **Bug Fixes**: Avoid potential crash on Android when checking `showTip` by providing a default fallback value.

## [1.0.18](https://github.com/phattran1201/react-native-pax/compare/v1.0.16...v1.0.18) (2026-03-13)

## [1.0.16](https://github.com/phattran1201/react-native-pax/compare/v1.0.15...v1.0.16) (2026-01-06)

## [1.0.15](https://github.com/phattran1201/react-native-pax/compare/v1.0.14...v1.0.15) (2025-12-09)

## [1.0.14](https://github.com/phattran1201/react-native-pax/compare/v1.0.13...v1.0.14) (2025-12-08)

## [1.0.13](https://github.com/phattran1201/react-native-pax/compare/v1.0.12...v1.0.13) (2025-12-03)

## [1.0.9](https://github.com/phattran1201/react-native-pax/compare/v1.0.8...v1.0.9) (2025-10-02)

## [1.0.8](https://github.com/phattran1201/react-native-pax/compare/v1.0.7...v1.0.8) (2025-09-12)

## [1.0.7](https://github.com/phattran1201/react-native-pax/compare/v1.0.6...v1.0.7) (2025-08-20)

## [1.0.6](https://github.com/phattran1201/react-native-pax/compare/v1.0.4...v1.0.6) (2025-07-11)

## [1.0.5](https://github.com/phattran1201/react-native-pax/compare/v1.0.4...v1.0.5) (2025-07-11)

## [1.0.4](https://github.com/phattran1201/react-native-pax/compare/v1.0.3...v1.0.4) (2025-07-11)

## [1.0.3](https://github.com/phattran1201/react-native-pax/compare/v1.0.2...v1.0.3) (2025-07-11)

## [1.0.2](https://github.com/phattran1201/react-native-pax/compare/v1.0.1...v1.0.2) (2025-07-10)

## [1.0.1](https://github.com/phattran1201/react-native-pax/compare/v1.0.0...v1.0.1) (2025-07-08)

# [1.0.0](https://github.com/phattran1201/react-native-pax/compare/v0.1.8...v1.0.0) (2025-07-08)


### Features

* refactor POSLink API and enhance type definitions ([1a7155c](https://github.com/phattran1201/react-native-pax/commit/1a7155c2ae65c90b8825bbbeb5178eccd621bfd4))

## [0.1.8](https://github.com/phattran1201/react-native-pax/compare/v0.1.7...v0.1.8) (2025-07-04)