

# [1.1.0](https://github.com/phattran1201/react-native-pax/compare/v1.0.22...v1.1.0) (2026-07-07)

## [1.1.0](https://github.com/phattran1201/react-native-pax/compare/v1.0.22...v1.1.0) (2026-06-29)

### Features

* **All POSLink connection types** (mirror theo demo `ParameterManager.getCommSetting`): added `initPOSLinkConn(config)` supporting `TCP`, `SSL`, `HTTP`, `HTTPS`, `UART`, `USB`, `AIDL`, and `BLUETOOTH`. Exposed `PaxConnType` / `PaxConnConfig` types. `initPOSLink` (TCP) is kept for backward compatibility; every type — including USB — shares a single `finalizeTerminal` path. USB accepts an optional `deviceName` and **auto-requests USB permission** on connect (rejects `USB_PERMISSION_DENIED` if the user declines).
* **UI helpers for picking/scanning a device**:
  * `listUsbDevices()` → `PaxUsbDevice[]` — USB device picker.
  * `getSupportedBaudRates()` → `string[]` and `listSerialPorts()` → `string[]` — UART baud + serial-port pickers (serial scan via `SerialPortFinderPax`).
  * `checkBluetoothEnable()`, `startBluetoothSearch({ useBle?, timeout? })`, `getBluetoothDeviceList()` → `PaxBtDevice[]` `{ name, mac, rssi }`, `stopBluetoothSearch()` — Bluetooth/BLE scanning (poll model, via `PaxGLComm.getBtScanner()`/`getBleScanner()`).
  * `requestUsbPermission()` now **awaits** the grant result (`true` granted / `false` declined) instead of returning immediately.
* **AndroidManifest**: library now declares `INTERNET`, the `android.hardware.usb.host` feature (`required=false`), and the `com.pax.us.std.poslink.aidl` `<queries>` entry (required for AIDL on targetSdk ≥ 30). Bluetooth (dangerous) permissions are documented for the consuming app to declare.
* **Pre-shaded PAX jars** to avoid `checkDebugDuplicateClasses` collisions with the Sunmi SDK (`L3AndRemoteOuterSDK`). The obfuscated default-package classes were relocated with jarjar: `a.**` → `pax.shaded.a.**` and `b.**` → `pax.shaded.b.**` in `POSLink_Core`, `POSLink_Admin`, and `POSLink_Semi`. The public `com.pax.*` API is unchanged. Consuming apps no longer need a runtime jarjar/shading Gradle task.

* **Android PAX SDK upgrade to POSLink Semi-Integration V2.02.00 (2025-11-26)**: Replaced the Android `libs/` jars with the 2025 release:
  * `POSLink_Core_Android_V2.00.03_20230828.jar` → `POSLink_Core_Android_V2.00.11_20251126.jar`
  * `POSLink_Semi_Android_Plugin_V2.00.00_20230828.jar` → `POSLink_Semi_Android_Plugin_V2.02.00_20251126.jar`
  * `POSLink_Admin_Android_Plugin_V2.00.00_20230828.jar` → `POSLink_Admin_Android_Plugin_V2.02.00_20251126.jar`
  * `PaxLog_1.0.11_20220921.jar` → `PaxLog_1.0.13_20241118.jar`
  * `GLComm_V1.12.01_20230515.jar` (unchanged)

### Breaking SDK API migrations (`PaxPosLinkModule.kt`)

* `HostGateway` (request) → `HostInformationRequest`; the `hostGateway` field on `DoCreditRequest`/`DoDebitRequest` is now `hostInformation`. Most legacy gateway/token fields were dropped by the SDK.
* `HostResponse` → `HostInformationResponse` (response host info).
* `TransactionBehavior` → `TransactionBehaviorRequest`. Removed fields: signature flags (capture/upload/acquire), `forceCc`, `forceFsa`, `cofIndicator`, `cofInitiator`.
* `posEchoData` moved from the request to `HostInformationRequest`; `continuousScreen` moved from the request to `TransactionBehaviorRequest`.
* Removed the unused `CheckRequest` builder (e-check classes removed from the SDK).

### Breaking JS API changes

* Removed `initPOSLinkUsb()` — use `initPOSLinkConn({ type: 'USB', timeout })` instead (it auto-requests USB permission).
* `requestUsbPermission()` semantics changed: it now resolves only **after** the user answers the permission dialog (`true` = granted, `false` = declined), instead of resolving immediately when the dialog is shown.

### iOS — feature parity + SDK upgrade

* **iOS PAX SDK upgrade to POSLink Semi-Integration V2.02.00 (2025-12-09)**: replaced the bundled iOS SDK (`ios/POSLinkSemiIntegrationSDK`, `ios/POSLinkAdminSDK` — `.a` + `Header/`) with the V2.02.00 release from the official demo, matching the Android jars. The existing static-lib packaging and import style are kept unchanged — `vendored_libraries` + `HEADER_SEARCH_PATHS` to the `Header/` dirs; fat libs remain `x86_64 + arm64`, so the `EXCLUDED_ARCHS[sdk=iphonesimulator*] = arm64` workaround still applies (no arm64 simulator slice is shipped).
* **iOS native module brought to parity with Android** (`ios/PaxPoslink.mm`) — implemented every method already declared in the shared TurboModule spec but previously missing on iOS (they would crash at runtime under the New Architecture):
  * `initPOSLinkConn(config)` — connect over any type the iOS SDK supports: `TCP`, `SSL`, `HTTP`, `HTTPS`, `BLUETOOTH`. `UART`/`USB`/`AIDL` are not available on iOS and are rejected with `UNSUPPORTED_CONN_TYPE`. Shares one `connectWithCommSetting:` path with `initPOSLink`.
  * `checkBluetoothEnable()` — CoreBluetooth power-state via a persistent `CBCentralManager` (async, 4 s safety timeout).
  * `startBluetoothSearch(useBle, timeout)` / `stopBluetoothSearch()` / `getBluetoothDeviceList()` → `{ name, mac, rssi }` — Bluetooth scan via the SDK's `MposBluetoothScan` (same import the demo's `POSLinkPluginBtSearch` uses), poll model with MAC-deduped results. `timeout` is interpreted as ms (Android-compatible) and converted to seconds.
  * `requestUsbPermission()` → `false`, and `listUsbDevices()` / `getSupportedBaudRates()` / `listSerialPorts()` → `[]` — graceful no-ops, since USB/UART/serial do not exist on iOS.

### iOS — breaking SDK API migrations (`PaxPoslink.mm`)

* `PLTransactionBehavior` → `PLTransactionBehaviorRequest`; `continuousScreen` moved from `PLDoCreditRequest` onto the transaction behavior (mirrors the Android V2.02.00 change).
* `PLHostResponse` → `PLHostInformationResponse`; dropped `traceNumber` / `transactionIdentifier` (removed from the SDK).
* `PLTraceResponse.authorizationResponse` removed → authorization code now read from `hostInformation.authorizationCode`.
* `transactionId` now sourced from `traceInformation.globalUid` (replacing the deprecated `paymentTransactionInformation.globalUid`).
* `PLTotalCount`/`PLTotalAmount` and `PLEdcTotalCount`/`PLEdcTotalAmount` dropped `checkCount`/`checkAmount` (the SDK now exposes `qrCode*` instead).

> **Host-app requirement**: `checkBluetoothEnable` instantiates `CBCentralManager`, so the consuming app must declare `NSBluetoothAlwaysUsageDescription` in its `Info.plist` (iOS will crash otherwise).

> **iOS Simulator (Apple Silicon)**: the bundled PAX `.a` libs ship an `arm64` slice built for *device* only (no `arm64` simulator slice), so linking for the Simulator on an M-series Mac fails with `Building for 'iOS-simulator', but linking in object file ... built for 'iOS'`. Build on a real device, or set `EXCLUDED_ARCHS[sdk=iphonesimulator*] = arm64` (on both the Pods and the app target) and run under Rosetta. See the README "iOS Simulator on Apple Silicon" section.

## [1.0.22](https://github.com/phattran1201/react-native-pax/compare/v1.0.21...v1.0.22) (2026-06-08)


### Features

* add Podfile helper to resolve SSZipArchive symbol conflicts with libPOSLinkAdmin ([#2](https://github.com/phattran1201/react-native-pax/issues/2)) ([16bf0f8](https://github.com/phattran1201/react-native-pax/commit/16bf0f8352a24d48e5b853d35439ed2304d9fd22))

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