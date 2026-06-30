"use strict";

import NativePaxPoslink from "./NativePaxPoslink.js";
export * from "./type.js";
// Tiện ích phân loại lỗi (classifyError, toPaxResult, PaxErrorType...) được
// export để app nào cần thì tự dùng. Thư viện KHÔNG tự phân loại — chỉ trả raw.
export * from "./pax-error.js";
const PaxPosLink = NativePaxPoslink ?? new Proxy({}, {
  get() {
    throw new Error(`The package '@haroldtran/react-native-pax' is not linked. Rebuild the app after installing.`);
  }
});

/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @param {object} [options] - Optional parameters.
 * @param {string} [options.port] - The port number of the POS device.
 * @param {number} [options.timeout] - The timeout value for the connection.
 * @returns {Promise<PaxInitModel>} A promise resolving to the initPOSLink result.
 */
export function initPOSLink(ip, options) {
  return PaxPosLink.initPOSLink(ip, options?.port, options?.timeout);
}

/**
 * Khởi tạo kết nối tới terminal cho mọi kiểu giao tiếp mà SDK hỗ trợ
 * (mirror theo demo POSLink): TCP, SSL, HTTP, HTTPS, UART, USB, AIDL, BLUETOOTH.
 *
 * Ví dụ:
 *  - TCP:       initPOSLinkConn({ type: 'TCP', ip: '192.168.1.10', port: '10009' })
 *  - SSL:       initPOSLinkConn({ type: 'SSL', ip: '192.168.1.10', port: '10009' })
 *  - UART:      initPOSLinkConn({ type: 'UART', serialPort: 'COM1', baudRate: '9600' })
 *  - USB:       initPOSLinkConn({ type: 'USB' })            // tự xử lý xin quyền USB
 *  - AIDL:      initPOSLinkConn({ type: 'AIDL' })           // BroadPOS cùng thiết bị
 *  - Bluetooth: initPOSLinkConn({ type: 'BLUETOOTH', macAddr: 'AA:BB:CC:DD:EE:FF' })
 *
 * @param {PaxConnConfig} config - Cấu hình kết nối, xem {@link PaxConnConfig}.
 * @returns {Promise<PaxInitModel>} A promise resolving to the connection result.
 */
export function initPOSLinkConn(config) {
  return PaxPosLink.initPOSLinkConn({
    type: config.type,
    ip: config.ip,
    port: config.port,
    serialPort: config.serialPort,
    baudRate: config.baudRate,
    deviceName: config.deviceName,
    macAddr: config.macAddr,
    timeout: config.timeout
  });
}

/**
 * Xin quyền USB và **chờ** kết quả: nếu đã có quyền sẵn thì trả về ngay,
 * nếu chưa thì bật dialog hệ thống và chỉ resolve khi người dùng trả lời.
 *
 * Không bắt buộc gọi: {@link initPOSLinkConn} với `type: 'USB'` đã **tự động** bật
 * dialog xin quyền khi cần rồi mới kết nối. Hàm này dùng khi muốn xin quyền trước
 * (ví dụ ngay lúc user chọn chế độ USB) để lúc connect khỏi phải đợi dialog.
 *
 * Không bao giờ treo: nếu không có thiết bị USB đang cắm thì resolve `false` ngay.
 * **Đừng** dùng hàm này trong bước "scan/liệt kê" — scan chỉ cần {@link listUsbDevices}.
 *
 * @returns {Promise<boolean>} true nếu đã/được cấp quyền; false nếu user từ chối hoặc không có thiết bị.
 */
export function requestUsbPermission() {
  return PaxPosLink.requestUsbPermission();
}

/**
 * Liệt kê các thiết bị USB đang cắm — dùng để dựng dropdown chọn `deviceName`
 * khi kết nối {@link initPOSLinkConn} với `type: 'USB'`.
 * @returns {Promise<PaxUsbDevice[]>}
 */
export function listUsbDevices() {
  return PaxPosLink.listUsbDevices();
}

/**
 * Danh sách baud rate hợp lệ — dùng để dựng dropdown khi kết nối UART.
 * @returns {Promise<string[]>}
 */
export function getSupportedBaudRates() {
  return PaxPosLink.getSupportedBaudRates();
}

/**
 * Quét các cổng serial hiện có trên thiết bị — dùng để dựng dropdown chọn
 * `serialPort` khi kết nối {@link initPOSLinkConn} với `type: 'UART'`.
 * @returns {Promise<string[]>} ví dụ ["/dev/ttyS0", "/dev/ttyUSB0", ...].
 */
export function listSerialPorts() {
  return PaxPosLink.listSerialPorts();
}

/**
 * Kiểm tra Bluetooth đã bật chưa (nên gọi trước khi {@link startBluetoothSearch}).
 * @returns {Promise<boolean>} true nếu Bluetooth đang bật.
 */
export function checkBluetoothEnable() {
  return PaxPosLink.checkBluetoothEnable();
}

/**
 * Bắt đầu quét thiết bị Bluetooth. Kết quả gom vào list nội bộ (dedupe theo MAC);
 * UI poll {@link getBluetoothDeviceList} định kỳ (vd mỗi 1s) để hiển thị realtime,
 * rồi gọi {@link stopBluetoothSearch} khi đóng màn hình.
 *
 * Nhớ xin runtime permission (BLUETOOTH_SCAN/BLUETOOTH_CONNECT trên API≥31,
 * ACCESS_FINE_LOCATION trên API≤30) trước khi gọi.
 *
 * @param {object} [options]
 * @param {boolean} [options.useBle=false] true = quét BLE, false = Bluetooth classic.
 * @param {number} [options.timeout=1000] thời lượng quét truyền cho scanner.
 * @returns {Promise<boolean>}
 */
export function startBluetoothSearch(options) {
  return PaxPosLink.startBluetoothSearch(options?.useBle ?? false, options?.timeout ?? 1000);
}

/**
 * Dừng quét Bluetooth và xoá list nội bộ.
 * @returns {Promise<boolean>}
 */
export function stopBluetoothSearch() {
  return PaxPosLink.stopBluetoothSearch();
}

/**
 * Lấy danh sách thiết bị Bluetooth đã phát hiện kể từ {@link startBluetoothSearch}.
 * @returns {Promise<PaxBtDevice[]>} mỗi phần tử { name, mac, rssi }.
 */
export function getBluetoothDeviceList() {
  return PaxPosLink.getBluetoothDeviceList();
}

/**
 * Initiates a payment transaction.
 * @param {string} [id] - Transaction ID (optional).
 * @param {number} [amount] - Payment amount
 * @param {number} [tip] - Tip amount (optional).
 * @param {number} [paymentType] - Type of payment (optional).
 * @param {string} [ecrRefNum] - ECR reference number (optional).
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export function makePayment(id, amount = 0, tip, paymentType, ecrRefNum, showTip) {
  return PaxPosLink.payment({
    transactionId: id,
    amount,
    tip,
    paymentType,
    ecrRefNum,
    showTip
  });
}

/**
 * Requests cancellation of the active terminal command or transaction.
 * @returns {Promise<string>} A promise resolving once the cancel request is sent.
 */
export function cancelTransaction() {
  return PaxPosLink.cancelTransaction();
}

/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export function makeRefund(amount, ecrRefNum) {
  return PaxPosLink.refund({
    amount,
    ecrRefNum
  });
}

/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export function makeVoid(ecrRefNum) {
  return PaxPosLink.voidTransaction({
    ecrRefNum
  });
}

/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */

export function makeCloseBatch() {
  return PaxPosLink.batchCloseout();
}
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 */
export function checkVoidOrRefundTransaction(ecrRefNum) {
  return PaxPosLink.checkVoidOrRefundTransaction(ecrRefNum);
}
/**
 * Gets all transactions.
 * @returns {Promise<PaxBatchInformationResponseModel>} A promise resolving to the transactions list.
 */
export function getBatchInformation() {
  return PaxPosLink.getBatchInformation();
}
//# sourceMappingURL=index.js.map