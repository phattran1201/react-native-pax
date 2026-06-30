# react-native-pax — Hướng dẫn kết nối & tích hợp

Tài liệu này hướng dẫn tích hợp `@haroldtran/react-native-pax` vào app React Native:
kết nối tới terminal PAX theo mọi kiểu giao tiếp, dựng UI chọn kết nối, và gọi
giao dịch (payment / refund / void / batch).

> SDK native: **POSLink Semi-Integration V2.02.00 (2025-11-26)** — Android.

---

## 1. Cài đặt

```bash
yarn add @haroldtran/react-native-pax
# hoặc: npm i @haroldtran/react-native-pax
cd ios && pod install   # nếu build iOS
```

Rebuild app sau khi cài (đây là native module, không chạy được trên Expo Go).

---

## 2. Các kiểu kết nối hỗ trợ

| `type`        | Mô tả                                   | Field bắt buộc            | Field tuỳ chọn |
|---------------|-----------------------------------------|---------------------------|----------------|
| `TCP`         | Mạng LAN/Wi-Fi (phổ biến nhất)          | `ip`, `port`              | `timeout`      |
| `SSL`         | Mạng có mã hoá TLS                      | `ip`, `port`              | `timeout`      |
| `HTTP`        | Mạng qua HTTP                            | `ip`, `port`              | `timeout`      |
| `HTTPS`       | Mạng qua HTTPS                           | `ip`, `port`              | `timeout`      |
| `UART`        | Cổng serial (hiếm dùng trên Android)    | `serialPort`, `baudRate`  | `timeout`      |
| `USB`         | Cáp USB tới terminal                     | —                         | `deviceName`, `timeout` |
| `AIDL`        | BroadPOS chạy cùng thiết bị (Android POS)| —                        | —              |
| `BLUETOOTH`   | Bluetooth / BLE                          | `macAddr`                 | `timeout`      |

- `port` mặc định `10009`, `timeout` mặc định `60000` ms.
- Phần lớn tích hợp dùng **TCP** (terminal cùng mạng) hoặc **AIDL** (app chạy ngay trên máy PAX Android).

---

## 3. API

### 3.1 Kết nối

```ts
import {
  initPOSLink,          // TCP (cách cũ, vẫn dùng được)
  initPOSLinkConn,      // ⭐ tổng quát cho mọi kiểu
  requestUsbPermission,
  listUsbDevices,
  getSupportedBaudRates,
  type PaxConnConfig,
  type PaxInitModel,
  type PaxUsbDevice,
} from '@haroldtran/react-native-pax';

// Cách tổng quát — khuyến nghị
await initPOSLinkConn({ type: 'TCP',  ip: '192.168.1.10', port: '10009' });
await initPOSLinkConn({ type: 'SSL',  ip: '192.168.1.10', port: '10009' });
await initPOSLinkConn({ type: 'UART', serialPort: 'COM1', baudRate: '9600' });
await initPOSLinkConn({ type: 'USB' });                      // tự bật dialog xin quyền USB
await initPOSLinkConn({ type: 'AIDL' });                     // BroadPOS cùng máy
await initPOSLinkConn({ type: 'BLUETOOTH', macAddr: 'AA:BB:CC:DD:EE:FF' });

// Tương đương cách cũ cho TCP (giữ để backward-compatible)
await initPOSLink('192.168.1.10', { port: '10009', timeout: 60000 });
```

Kết quả trả về (`PaxInitModel`):

```ts
{
  status: boolean,
  serialNumber?: { modelName: string; appName: string; serialNumber: string }
}
```

> ⚠️ Phải kết nối thành công (`status === true`) **trước khi** gọi giao dịch.

### 3.2 Helper dựng UI (liệt kê / quét thiết bị)

```ts
// ── USB ───────────────────────────────────────────────
const usb: PaxUsbDevice[] = await listUsbDevices();
// [{ deviceName, productName, vendorId, productId }, ...]

// (TUỲ CHỌN) Xin quyền USB trước. KHÔNG bắt buộc: initPOSLinkConn({type:'USB'})
// đã tự bật dialog xin quyền khi cần. Hàm này CHỜ user trả lời.
// ⚠️ ĐỪNG dùng trong bước scan/liệt kê — scan chỉ cần listUsbDevices().
// (resolve false ngay nếu không có thiết bị USB, nên không bao giờ treo)
const granted: boolean = await requestUsbPermission(); // true = được cấp, false = từ chối/không có thiết bị

// ── UART (serial) ─────────────────────────────────────
const bauds: string[] = await getSupportedBaudRates();  // ['9600','19200','115200',...]
const ports: string[] = await listSerialPorts();        // ['/dev/ttyS0','/dev/ttyUSB0',...]

// ── Bluetooth (quét động → chọn từ list) ──────────────
const on: boolean = await checkBluetoothEnable();       // BT đã bật chưa
await startBluetoothSearch();                           // bắt đầu quét; ({ useBle?, timeout? })
const found: PaxBtDevice[] = await getBluetoothDeviceList(); // [{ name, mac, rssi }] — poll mỗi ~1s
await stopBluetoothSearch();                            // dừng quét khi đóng màn / đã chọn xong
```

> 📡 `startBluetoothSearch({ useBle: true })` để quét **BLE**; mặc định quét Bluetooth classic.
> Nhớ xin **runtime permission** Bluetooth/Location trước khi quét (xem §6).

### 3.3 Giao dịch

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

// Thanh toán. paymentType: 1 = Credit (mặc định), 2 = Debit. amount tính theo CENT.
await makePayment(
  id,            // string?  transaction id (tuỳ chọn)
  amount,        // number   số tiền (cent), vd 1000 = $10.00
  tip,           // number?  tiền tip (cent)
  paymentType,   // number?  1=Credit, 2=Debit
  ecrRefNum,     // string?  mã tham chiếu ECR (nên truyền, dùng để void/refund sau)
  showTip        // boolean? true = cho nhập tip trên terminal
);

await makeRefund(amount, ecrRefNum);   // hoàn tiền
await makeVoid(ecrRefNum);             // huỷ giao dịch
await makeCloseBatch();                // chốt batch
await getBatchInformation();           // thông tin batch hiện tại
await checkVoidOrRefundTransaction(ecrRefNum);
await cancelTransaction();             // huỷ lệnh đang chạy trên terminal
```

---

## 4. Xử lý lỗi (tuỳ chọn)

Thư viện **trả raw code trung thực**, không tự phân loại. Nếu muốn phân loại
(lỗi mạng / decline / cancel…), dùng helper kèm theo:

```ts
import { toPaxResult, classifyError, PaxErrorType } from '@haroldtran/react-native-pax';

try {
  const raw = await makePayment(undefined, 1000, undefined, 1, 'ECR-001', false);
  const result = toPaxResult(raw);
  if (result.ok) {
    // giao dịch thành công → result.data
  } else {
    // result.error.type ∈ PaxErrorType (Communication, Declined, Cancelled, ...)
  }
} catch (e) {
  // ngoại lệ native
}
```

Các trường raw quan trọng trong response: `execCode`, `responseCode`,
`hostResponseCode`, `issuerResponseCode`, `responseMessage`, `hostResponseMessage`.

---

## 5. Dựng UI chọn kết nối (React Native)

Logic giống demo chính hãng: **chọn 1 `type`** → chỉ hiện field tương ứng → connect.

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

  // Nạp dữ liệu phụ thuộc type
  useEffect(() => {
    // USB: không cần requestUsbPermission() — initPOSLinkConn type:'USB' tự xin quyền.
    if (type === 'USB') listUsbDevices().then(setUsbDevices);

    if (type === 'UART') {
      getSupportedBaudRates().then(setBauds);
      listSerialPorts().then(setPorts);   // quét cổng serial → dropdown
    }

    // BLUETOOTH: bật quét + poll list mỗi 1s (nhớ xin runtime permission trước — xem §6)
    if (type === 'BLUETOOTH') {
      (async () => {
        if (!(await checkBluetoothEnable())) return; // nhắc user bật BT
        await startBluetoothSearch();                // ({ useBle: true }) nếu muốn BLE
        btPoll.current = setInterval(
          () => getBluetoothDeviceList().then(setBtDevices),
          1000
        );
      })();
    }
    // cleanup: rời màn / đổi type → dừng quét
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
      {/* 1. Picker chọn type — thay bằng @react-native-picker/picker hoặc nút radio */}
      <Text>Kiểu kết nối:</Text>
      <View style={{ flexDirection: 'row', flexWrap: 'wrap', gap: 8 }}>
        {TYPES.map((t) => (
          <Button key={t} title={t} onPress={() => setType(t)}
            color={t === type ? '#0a84ff' : '#888'} />
        ))}
      </View>

      {/* 2. Field theo type */}
      {isNet(type) && (
        <>
          <TextInput placeholder="IP" value={ip} onChangeText={setIp} />
          <TextInput placeholder="Port" value={port} onChangeText={setPort}
            keyboardType="number-pad" />
        </>
      )}

      {type === 'UART' && (
        <>
          {/* Dropdown cổng serial từ listSerialPorts(); rỗng thì cho gõ tay */}
          <Text>Cổng serial:</Text>
          {ports.map((p) => (
            <Button key={p} title={p}
              color={p === serialPort ? '#0a84ff' : '#888'}
              onPress={() => setSerialPort(p)} />
          ))}
          <TextInput placeholder="Hoặc gõ tay (COM1)" value={serialPort}
            onChangeText={setSerialPort} />
          {/* dropdown baud từ {bauds} */}
          <TextInput placeholder="Baud rate" value={baudRate} onChangeText={setBaudRate} />
        </>
      )}

      {type === 'USB' && (
        <>
          <Text>Thiết bị USB:</Text>
          {usbDevices.map((d) => (
            <Button key={d.deviceName}
              title={`${d.productName || d.deviceName}`}
              color={d.deviceName === deviceName ? '#0a84ff' : '#888'}
              onPress={() => setDeviceName(d.deviceName)} />
          ))}
          {/* Để trống deviceName nếu chỉ có 1 thiết bị → SDK tự chọn.
              Không cần xin quyền tay: bấm "Kết nối" sẽ tự bật dialog xin quyền. */}
        </>
      )}

      {type === 'BLUETOOTH' && (
        <>
          {/* List thiết bị quét được (poll realtime); tap để chọn MAC */}
          <Text>Thiết bị Bluetooth (đang quét…):</Text>
          {btDevices.map((d) => (
            <Button key={d.mac}
              title={`${d.name || 'Unknown'} — ${d.mac} (${d.rssi})`}
              color={d.mac === macAddr ? '#0a84ff' : '#888'}
              onPress={() => setMacAddr(d.mac)} />
          ))}
          <TextInput placeholder="Hoặc gõ MAC (AA:BB:CC:DD:EE:FF)" value={macAddr}
            onChangeText={setMacAddr} autoCapitalize="characters" />
        </>
      )}

      {/* AIDL: không cần field nào */}

      {/* 3. Timeout luôn hiện */}
      <TextInput placeholder="Timeout (ms)" value={timeoutMs}
        onChangeText={setTimeoutMs} keyboardType="number-pad" />

      <Button title="Kết nối" onPress={onConnect} />
    </View>
  );
}
```

**Quy tắc hiển thị field theo `type`:**

| `type`        | Field hiện trên UI                       | Helper quét/liệt kê |
|---------------|------------------------------------------|---------------------|
| TCP/SSL/HTTP/HTTPS | IP + Port                           | —                   |
| UART          | Cổng serial (dropdown) + Baud (dropdown) | `listSerialPorts`, `getSupportedBaudRates` |
| USB           | Dropdown thiết bị                        | `listUsbDevices` (quyền tự xin lúc connect) |
| AIDL          | *(không có)*                             | —                   |
| BLUETOOTH     | List quét được (chọn MAC) hoặc gõ tay    | `startBluetoothSearch` + `getBluetoothDeviceList` + `stopBluetoothSearch` |
| *(mọi loại)*  | Timeout                                  | —                   |

---

## 6. Quyền (AndroidManifest)

Thư viện **đã khai sẵn**: `INTERNET`, `android.hardware.usb.host` (`required=false`),
và `<queries>` cho AIDL.

App **phải tự khai** nếu dùng **Bluetooth** (quyền dangerous-level) — thêm vào
`android/app/src/main/AndroidManifest.xml`:

```xml
<uses-permission android:name="android.permission.BLUETOOTH" />
<uses-permission android:name="android.permission.BLUETOOTH_ADMIN" />
<!-- targetSdk >= 31 -->
<uses-permission android:name="android.permission.BLUETOOTH_SCAN" />
<uses-permission android:name="android.permission.BLUETOOTH_CONNECT" />
<!-- cần cho quét trên Android <= 11 -->
<uses-permission android:name="android.permission.ACCESS_COARSE_LOCATION" />
<uses-permission android:name="android.permission.ACCESS_FINE_LOCATION" />
```

Với các quyền dangerous, **phải request runtime permission TRƯỚC khi
`startBluetoothSearch`** (nếu không sẽ không quét ra thiết bị nào):

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

> USB **không cần** đoạn này — quyền USB do `initPOSLinkConn({type:'USB'})` tự xin
> (hoặc gọi `requestUsbPermission()` để xin trước).

---

## 7. Lưu ý nhanh

- `amount`/`tip` tính theo **cent** (1000 = $10.00).
- Luôn truyền `ecrRefNum` khi `makePayment` để sau này `makeVoid`/`makeRefund` tham chiếu được.
- Mọi hàm đều là `Promise` — bọc `try/catch`.
- **USB**: `initPOSLinkConn({type:'USB'})` tự bật dialog xin quyền; user từ chối → reject `USB_PERMISSION_DENIED`. `requestUsbPermission()` là tuỳ chọn (xin trước, có chờ kết quả).
- **Bluetooth**: phải `startBluetoothSearch` → poll `getBluetoothDeviceList` → `stopBluetoothSearch`; xin runtime permission trước, không thì quét ra rỗng.
- Một số terminal cần bật chế độ Semi-Integration / cấu hình IP-Port phía máy PAX trước.
- AIDL chỉ chạy khi app cài **trên chính máy PAX Android** (có BroadPOS).
- ⚠️ `initPOSLinkUsb` đã bị bỏ — dùng `initPOSLinkConn({ type: 'USB', timeout })` thay thế.
