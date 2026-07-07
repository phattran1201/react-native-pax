import { PaxBatchInformationResponseModel, PaxBtDevice, PaxConnConfig, PaxInitModel, PaxResponseModel, PaxUsbDevice } from './type';
export * from './type';
export * from './pax-error';
/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @param {object} [options] - Optional parameters.
 * @param {string} [options.port] - The port number of the POS device.
 * @param {number} [options.timeout] - The timeout value for the connection.
 * @returns {Promise<PaxInitModel>} A promise resolving to the initPOSLink result.
 */
export declare function initPOSLink(ip: string, options?: {
    port?: string;
    timeout?: number;
}): Promise<PaxInitModel>;
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
export declare function initPOSLinkConn(config: PaxConnConfig): Promise<PaxInitModel>;
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
export declare function requestUsbPermission(): Promise<boolean>;
/**
 * Liệt kê các thiết bị USB đang cắm — dùng để dựng dropdown chọn `deviceName`
 * khi kết nối {@link initPOSLinkConn} với `type: 'USB'`.
 * @returns {Promise<PaxUsbDevice[]>}
 */
export declare function listUsbDevices(): Promise<PaxUsbDevice[]>;
/**
 * Danh sách baud rate hợp lệ — dùng để dựng dropdown khi kết nối UART.
 * @returns {Promise<string[]>}
 */
export declare function getSupportedBaudRates(): Promise<string[]>;
/**
 * Quét các cổng serial hiện có trên thiết bị — dùng để dựng dropdown chọn
 * `serialPort` khi kết nối {@link initPOSLinkConn} với `type: 'UART'`.
 * @returns {Promise<string[]>} ví dụ ["/dev/ttyS0", "/dev/ttyUSB0", ...].
 */
export declare function listSerialPorts(): Promise<string[]>;
/**
 * Kiểm tra Bluetooth đã bật chưa (nên gọi trước khi {@link startBluetoothSearch}).
 * @returns {Promise<boolean>} true nếu Bluetooth đang bật.
 */
export declare function checkBluetoothEnable(): Promise<boolean>;
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
export declare function startBluetoothSearch(options?: {
    useBle?: boolean;
    timeout?: number;
}): Promise<boolean>;
/**
 * Dừng quét Bluetooth và xoá list nội bộ.
 * @returns {Promise<boolean>}
 */
export declare function stopBluetoothSearch(): Promise<boolean>;
/**
 * Lấy danh sách thiết bị Bluetooth đã phát hiện kể từ {@link startBluetoothSearch}.
 * @returns {Promise<PaxBtDevice[]>} mỗi phần tử { name, mac, rssi }.
 */
export declare function getBluetoothDeviceList(): Promise<PaxBtDevice[]>;
/**
 * Initiates a payment transaction.
 * @param {string} [id] - Transaction ID (optional).
 * @param {number} [amount] - Payment amount
 * @param {number} [tip] - Tip amount (optional).
 * @param {number} [paymentType] - Type of payment (optional).
 * @param {string} [ecrRefNum] - ECR reference number (optional).
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export declare function makePayment(id?: string, amount?: number, tip?: number, paymentType?: number, ecrRefNum?: string, showTip?: boolean): Promise<PaxResponseModel>;
/**
 * Requests cancellation of the active terminal command or transaction.
 * @returns {Promise<string>} A promise resolving once the cancel request is sent.
 */
export declare function cancelTransaction(): Promise<string>;
/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export declare function makeRefund(amount: number, ecrRefNum: string): Promise<PaxResponseModel>;
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export declare function makeVoid(ecrRefNum: string): Promise<PaxResponseModel>;
/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} Response raw từ native. Muốn phân loại lỗi, dùng toPaxResult/classifyError.
 */
export declare function makeCloseBatch(): Promise<PaxResponseModel>;
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 */
export declare function checkVoidOrRefundTransaction(ecrRefNum: string): Promise<Record<string, unknown>>;
/**
 * Gets all transactions.
 * @returns {Promise<PaxBatchInformationResponseModel>} A promise resolving to the transactions list.
 */
export declare function getBatchInformation(): Promise<PaxBatchInformationResponseModel>;
//# sourceMappingURL=index.d.ts.map