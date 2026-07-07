# react-native-pax — Connection & Integration Guide

This guide walks you through integrating `@haroldtran/react-native-pax` into your React Native app: connecting to PAX terminals using various transport types, building a connection selection UI, and executing transactions (payment / refund / void / batch).

> Native SDK Version: **POSLink Semi-Integration V2.02.00 (2025-11-26)** — Android.

---

## 1. Installation

```bash
yarn add @haroldtran/react-native-pax
# or: npm i @haroldtran/react-native-pax
cd ios && pod install   # if building for iOS
```

Rebuild your app after installation (this is a native module and cannot run on Expo Go).

---

## 2. Supported Connection Types

| `type`        | Description                             | Required Fields           | Optional Fields |
|---------------|-----------------------------------------|---------------------------|-----------------|
| `TCP`         | LAN/Wi-Fi network (most common)         | `ip`, `port`              | `timeout`      |
| `SSL`         | Network with TLS encryption             | `ip`, `port`              | `timeout`      |
| `HTTP`        | Network via HTTP                        | `ip`, `port`              | `timeout`      |
| `HTTPS`       | Network via HTTPS                       | `ip`, `port`              | `timeout`      |
| `UART`        | Serial port (rarely used on Android)    | `serialPort`, `baudRate`  | `timeout`      |
| `USB`         | USB cable connection to terminal        | —                         | `deviceName`, `timeout` |
| `AIDL`        | BroadPOS running on the same device     | —                         | —              |
| `BLUETOOTH`   | Bluetooth / BLE                         | `macAddr`                 | `timeout`      |

- `port` defaults to `10009`, `timeout` defaults to `60000` ms.
- Most integrations use **TCP** (terminal on the same network) or **AIDL** (app running directly on the PAX Android device).

---

## 3. API Reference

### 3.1 Connection

```ts
import {
  initPOSLink,          // TCP (legacy, still supported)
  initPOSLinkConn,      // ⭐ General initializer for all connection types
  requestUsbPermission,
  listUsbDevices,
  getSupportedBaudRates,
  type PaxConnConfig,
  type PaxInitModel,
  type PaxUsbDevice,
} from '@haroldtran/react-native-pax';

// General approach — recommended
await initPOSLinkConn({ type: 'TCP',  ip: '192.168.1.10', port: '10009' });
await initPOSLinkConn({ type: 'SSL',  ip: '192.168.1.10', port: '10009' });
await initPOSLinkConn({ type: 'UART', serialPort: 'COM1', baudRate: '9600' });
await initPOSLinkConn({ type: 'USB' });                      // auto-requests USB permission
await initPOSLinkConn({ type: 'AIDL' });                     // BroadPOS on same device
await initPOSLinkConn({ type: 'BLUETOOTH', macAddr: 'AA:BB:CC:DD:EE:FF' });

// Legacy approach for TCP (kept for backward-compatibility)
await initPOSLink('192.168.1.10', { port: '10009', timeout: 60000 });
```

Returned connection result (`PaxInitModel`):

```ts
{
  status: boolean,
  serialNumber?: { modelName: string; appName: string; serialNumber: string }
}
```

> ⚠️ Connection must be successful (`status === true`) **before** invoking transactions.

### 3.2 UI Helpers (Device listing / scanning)

```ts
// ── USB ───────────────────────────────────────────────
const usb: PaxUsbDevice[] = await listUsbDevices();
// [{ deviceName, productName, vendorId, productId }, ...]

// (OPTIONAL) Request USB permission beforehand. Not required: initPOSLinkConn({type:'USB'})
// automatically prompts for permission when needed. This function AWAITS user selection.
// ⚠️ DO NOT use during the scan/listing step — scanning only requires listUsbDevices().
// (resolves false immediately if no USB devices are connected, so it never blocks)
const granted: boolean = await requestUsbPermission(); // true = granted, false = denied/no device

// ── UART (serial) ─────────────────────────────────────
const bauds: string[] = await getSupportedBaudRates();  // ['9600','19200','115200',...]
const ports: string[] = await listSerialPorts();        // ['/dev/ttyS0','/dev/ttyUSB0',...]

// ── Bluetooth (dynamic scanning → pick from list) ──────
const on: boolean = await checkBluetoothEnable();       // check if BT is enabled
await startBluetoothSearch();                           // start scan; ({ useBle?, timeout? })
const found: PaxBtDevice[] = await getBluetoothDeviceList(); // [{ name, mac, rssi }] — poll every ~1s
await stopBluetoothSearch();                            // stop scan when closing screen / selected
```

> 📡 Pass `{ useBle: true }` to `startBluetoothSearch` to scan for **BLE** devices; defaults to classic Bluetooth.
> Remember to request **runtime permissions** for Bluetooth/Location before scanning (see Section 6).

### 3.3 Transactions

```ts
import {
  makePayment,
  makeRefund,
  makeVoid,
  makeCloseBatch,
  getBatchInformation,
  checkVoidOrRefundTransaction,
  cancelTransaction,
} from '@haroldtran/react-native-pax';

// Process payment. paymentType: 1 = Credit (default), 2 = Debit. amount in CENTS.
await makePayment(
  id,            // string?  transaction id (optional)
  amount,        // number   amount (cents), e.g., 1000 = $10.00
  tip,           // number?  tip amount (cents)
  paymentType,   // number?  1=Credit, 2=Debit
  ecrRefNum,     // string?  ECR reference number (strongly recommended, used for void/refund)
  showTip        // boolean? true = prompt customer for tip on terminal
);

await makeRefund(amount, ecrRefNum);   // Refund / return operation
await makeVoid(ecrRefNum);             // Void transaction
await makeCloseBatch();                // Settlement / close batch
await getBatchInformation();           // Active batch details
await checkVoidOrRefundTransaction(ecrRefNum);
await cancelTransaction();             // Request terminal to cancel running command
```

---

## 4. Error Handling (Optional)

The library returns **raw codes directly from the native module** without automatic classification. If you wish to classify errors (e.g., connection issue vs. decline vs. cancel), you can use the provided JS helper:

```ts
import { toPaxResult, classifyError, PaxErrorType } from '@haroldtran/react-native-pax';

try {
  const raw = await makePayment(undefined, 1000, undefined, 1, 'ECR-001', false);
  const result = toPaxResult(raw);
  if (result.ok) {
    // transaction success → result.data
  } else {
    // result.error.type ∈ PaxErrorType (Communication, Declined, Cancelled, ...)
  }
} catch (e) {
  // native exceptions
}
```

Key raw fields in the response include: `execCode`, `responseCode`, `hostResponseCode`, `issuerResponseCode`, `responseMessage`, and `hostResponseMessage`.

---

## 5. Building Connection UI (React Native)

The typical implementation flow mirrors the official PAX demo: **select a connection `type`** → render only corresponding configuration fields → click connect.

```tsx
import { useEffect, useRef, useState } from 'react';
import { View, Text, TextInput, Button } from 'react-native';
import {
  initPOSLinkConn,
  listUsbDevices,
  getSupportedBaudRates,
  listSerialPorts,
  checkBluetoothEnable,
  startBluetoothSearch,
  getBluetoothDeviceList,
  stopBluetoothSearch,
  type PaxConnType,
  type PaxUsbDevice,
  type PaxBtDevice,
} from '@haroldtran/react-native-pax';

const TYPES: PaxConnType[] = ['TCP', 'SSL', 'HTTP', 'HTTPS', 'UART', 'USB', 'AIDL', 'BLUETOOTH'];
const isNet = (t: PaxConnType) => ['TCP', 'SSL', 'HTTP', 'HTTPS'].includes(t);

export function ConnectScreen() {
  const [type, setType] = useState<PaxConnType>('TCP');
  const [ip, setIp] = useState('192.168.1.10');
  const [port, setPort] = useState('10009');
  const [serialPort, setSerialPort] = useState('');
  const [baudRate, setBaudRate] = useState('9600');
  const [macAddr, setMacAddr] = useState('');
  const [deviceName, setDeviceName] = useState<string | undefined>();
  const [timeoutMs, setTimeoutMs] = useState('60000');

  const [usbDevices, setUsbDevices] = useState<PaxUsbDevice[]>([]);
  const [bauds, setBauds] = useState<string[]>([]);
  const [ports, setPorts] = useState<string[]>([]);
  const [btDevices, setBtDevices] = useState<PaxBtDevice[]>([]);
  const btPoll = useRef<ReturnType<typeof setInterval> | null>(null);

  // Load auxiliary data depending on connection type
  useEffect(() => {
    // USB: requestUsbPermission() is optional. initPOSLinkConn automatically prompts when connecting.
    if (type === 'USB') listUsbDevices().then(setUsbDevices);

    if (type === 'UART') {
      getSupportedBaudRates().then(setBauds);
      listSerialPorts().then(setPorts);   // scan serial ports → populates dropdown
    }

    // BLUETOOTH: start scan + poll the device list every 1s (make sure runtime permissions are granted — see Section 6)
    if (type === 'BLUETOOTH') {
      (async () => {
        if (!(await checkBluetoothEnable())) return; // Alert user to enable BT
        await startBluetoothSearch();                // Pass ({ useBle: true }) for BLE scanning
        btPoll.current = setInterval(
          () => getBluetoothDeviceList().then(setBtDevices),
          1000
        );
      })();
    }
    // cleanup: component unmount / type change → stop scan
    return () => {
      if (btPoll.current) { clearInterval(btPoll.current); btPoll.current = null; }
      stopBluetoothSearch().catch(() => {});
    };
  }, [type]);

  const onConnect = async () => {
    try {
      const res = await initPOSLinkConn({
        type,
        ip,
        port,
        serialPort,
        baudRate,
        macAddr,
        deviceName,
        timeout: Number(timeoutMs),
      });
      if (res.status) {
        console.log('✅ Connected:', res.serialNumber);
      } else {
        console.warn('❌ Connect failed');
      }
    } catch (e) {
      console.error('Connect error', e);
    }
  };

  return (
    <View style={{ padding: 16, gap: 8 }}>
      {/* 1. Connection Type Picker — use @react-native-picker/picker or radio buttons */}
      <Text>Connection Type:</Text>
      <View style={{ flexDirection: 'row', flexWrap: 'wrap', gap: 8 }}>
        {TYPES.map((t) => (
          <Button key={t} title={t} onPress={() => setType(t)}
            color={t === type ? '#0a84ff' : '#888'} />
        ))}
      </View>

      {/* 2. Dynamic fields based on type */}
      {isNet(type) && (
        <>
          <TextInput placeholder="IP" value={ip} onChangeText={setIp} />
          <TextInput placeholder="Port" value={port} onChangeText={setPort}
            keyboardType="number-pad" />
        </>
      )}

      {type === 'UART' && (
        <>
          {/* Dropdown for serial ports populated from listSerialPorts(); allow text input fallback */}
          <Text>Serial Port:</Text>
          {ports.map((p) => (
            <Button key={p} title={p}
              color={p === serialPort ? '#0a84ff' : '#888'}
              onPress={() => setSerialPort(p)} />
          ))}
          <TextInput placeholder="Or type COM port (COM1)" value={serialPort}
            onChangeText={setSerialPort} />
          {/* Baud rate dropdown from bauds */}
          <TextInput placeholder="Baud rate" value={baudRate} onChangeText={setBaudRate} />
        </>
      )}

      {type === 'USB' && (
        <>
          <Text>USB Devices:</Text>
          {usbDevices.map((d) => (
            <Button key={d.deviceName}
              title={`${d.productName || d.deviceName}`}
              color={d.deviceName === deviceName ? '#0a84ff' : '#888'}
              onPress={() => setDeviceName(d.deviceName)} />
          ))}
          {/* Keep deviceName empty if there is only 1 device → SDK will auto-select.
              No manual permission step required: clicking "Connect" automatically pops up the permission dialog. */}
        </>
      )}

      {type === 'BLUETOOTH' && (
        <>
          {/* Real-time scanned Bluetooth devices; tap to choose MAC address */}
          <Text>Bluetooth Devices (scanning...):</Text>
          {btDevices.map((d) => (
            <Button key={d.mac}
              title={`${d.name || 'Unknown'} — ${d.mac} (${d.rssi})`}
              color={d.mac === macAddr ? '#0a84ff' : '#888'}
              onPress={() => setMacAddr(d.mac)} />
          ))}
          <TextInput placeholder="Or enter MAC Address (AA:BB:CC:DD:EE:FF)" value={macAddr}
            onChangeText={setMacAddr} autoCapitalize="characters" />
        </>
      )}

      {/* AIDL: No parameters required */}

      {/* 3. Timeout field is always visible */}
      <TextInput placeholder="Timeout (ms)" value={timeoutMs}
        onChangeText={setTimeoutMs} keyboardType="number-pad" />

      <Button title="Connect" onPress={onConnect} />
    </View>
  );
}
```

**Field Visibility Guidelines by Type:**

| `type`        | Fields Shown on UI                       | Helper Scan / Discovery API |
|---------------|------------------------------------------|-----------------------------|
| TCP/SSL/HTTP/HTTPS | IP + Port                           | —                           |
| UART          | Serial Port (dropdown) + Baud (dropdown) | `listSerialPorts`, `getSupportedBaudRates` |
| USB           | Device Selection dropdown                | `listUsbDevices` (auto-permissions on connect) |
| AIDL          | *(none)*                                 | —                           |
| BLUETOOTH     | Scan list (MAC selection) or manual input | `startBluetoothSearch` + `getBluetoothDeviceList` + `stopBluetoothSearch` |
| *(all types)* | Timeout                                  | —                           |

---

## 6. Permissions Configuration (Android & iOS)

### Android (AndroidManifest.xml)

The library declarations **already include**: `INTERNET`, `android.hardware.usb.host` (`required=false`), and `<queries>` for AIDL.

However, your app **must declare** the following permissions in `android/app/src/main/AndroidManifest.xml` if using **Bluetooth**:

```xml
<uses-permission android:name="android.permission.BLUETOOTH" />
<uses-permission android:name="android.permission.BLUETOOTH_ADMIN" />
<!-- targetSdk >= 31 -->
<uses-permission android:name="android.permission.BLUETOOTH_SCAN" />
<uses-permission android:name="android.permission.BLUETOOTH_CONNECT" />
<!-- Required for scanning on Android <= 11 -->
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" />
<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
```

For dangerous permissions, **you must request runtime permissions BEFORE calling `startBluetoothSearch`** (otherwise, the scan will return empty results):

```ts
import { PermissionsAndroid, Platform } from 'react-native';

async function ensureBtPermission() {
  if (Platform.OS !== 'android') return true;
  const perms =
    Platform.Version >= 31
      ? [
          PermissionsAndroid.PERMISSIONS.BLUETOOTH_SCAN,
          PermissionsAndroid.PERMISSIONS.BLUETOOTH_CONNECT,
        ]
      : [PermissionsAndroid.PERMISSIONS.ACCESS_FINE_LOCATION];
  const res = await PermissionsAndroid.requestMultiple(perms);
  return Object.values(res).every((v) => v === 'granted');
}
```

> USB **does not** require runtime permission checks: `initPOSLinkConn({type:'USB'})` takes care of the dialog (or you can request it early via `requestUsbPermission()`).

### iOS (Info.plist)

If your app uses a **Bluetooth** connection, you **must** declare Bluetooth usage descriptions in `ios/YourProjectName/Info.plist` (the app will crash at runtime on module initialization if this key is missing):

```xml
<key>NSBluetoothAlwaysUsageDescription</key>
<string>This app requires Bluetooth access to connect to PAX payment terminals.</string>
```

---

## 7. Fast Integration Tips

- `amount`/`tip` values must be in **cents** (e.g. 1000 = $10.00).
- Always supply a unique `ecrRefNum` when calling `makePayment` to reference for subsequent `makeVoid`/`makeRefund` actions.
- Wrap all calls in `try/catch` blocks since connection and transaction methods return `Promise`.
- **USB**: `initPOSLinkConn({type:'USB'})` automatically prompts for permission. If rejected, it rejects with `USB_PERMISSION_DENIED`. Calling `requestUsbPermission()` early is optional but lets you await the result.
- **Bluetooth**: Requires executing `startBluetoothSearch` → polling `getBluetoothDeviceList` → calling `stopBluetoothSearch`. Make sure runtime permissions are granted (Android) and `NSBluetoothAlwaysUsageDescription` is in `Info.plist` (iOS) beforehand.
- PAX terminals must have Semi-Integration mode enabled and IP/Port configured correctly.
- AIDL connection is only functional when the app is installed **directly on the PAX Android terminal** hosting BroadPOS.
- ⚠️ `initPOSLinkUsb` has been removed — use `initPOSLinkConn({ type: 'USB', timeout })` instead.
