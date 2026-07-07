export interface PaxInitModel {
  serialNumber?: {
    modelName: string;
    appName: string;
    serialNumber: string;
  };
  status: boolean;
}

/**
 * Các kiểu kết nối tới terminal PAX mà SDK hỗ trợ (mirror theo demo POSLink).
 * - TCP / SSL / HTTP / HTTPS : kết nối mạng (cần `ip`, `port`).
 * - UART                     : cổng serial (cần `serialPort`, `baudRate`).
 * - USB                      : qua cổng USB của thiết bị (tuỳ chọn `deviceName`).
 * - AIDL                     : giao tiếp với BroadPOS trên cùng thiết bị.
 * - BLUETOOTH                : kết nối Bluetooth (cần `macAddr`).
 */
export type PaxConnType =
  | 'TCP'
  | 'SSL'
  | 'HTTP'
  | 'HTTPS'
  | 'UART'
  | 'USB'
  | 'AIDL'
  | 'BLUETOOTH';

export interface PaxUsbDevice {
  deviceName: string;
  productName: string;
  vendorId: number;
  productId: number;
}

/** Thiết bị Bluetooth phát hiện được khi quét (dùng cho `type: 'BLUETOOTH'`). */
export interface PaxBtDevice {
  /** Tên thiết bị (có thể rỗng). */
  name: string;
  /** Địa chỉ MAC — truyền vào `initPOSLinkConn({ type: 'BLUETOOTH', macAddr })`. */
  mac: string;
  /** Cường độ tín hiệu (dBm). */
  rssi: number;
}

export interface PaxConnConfig {
  type: PaxConnType;
  /** TCP/SSL/HTTP/HTTPS: IP của terminal. */
  ip?: string;
  /** TCP/SSL/HTTP/HTTPS: cổng (mặc định 10009). */
  port?: string;
  /** UART: cổng serial, ví dụ "COM1". */
  serialPort?: string;
  /** UART: tốc độ baud, ví dụ "9600". */
  baudRate?: string;
  /** USB: tên thiết bị (tuỳ chọn). */
  deviceName?: string;
  /** BLUETOOTH: địa chỉ MAC của terminal. */
  macAddr?: string;
  /** Timeout giao tiếp tính bằng ms (mặc định 60000). */
  timeout?: number;
}

export interface PaxRequestModel {
  id?: string;
  amount?: number;
  tip?: number;
  paymentType?: number;
  ecrRefNum?: string;
  showTip?: boolean;
}

export interface PaxHistoryData {
  batchNumber?: string;
  timeStamp?: string;
  totalCount?: {
    creditCount?: string;
    debitCount?: string;
    ebtCount?: string;
    giftCount?: string;
    loyaltyCount?: string;
    cashCount?: string;
    checkCount?: string;
  };
  totalAmount?: {
    creditAmount?: string;
    debitAmount?: string;
    ebtAmount?: string;
    giftAmount?: string;
    loyaltyAmount?: string;
    cashAmount?: string;
    checkAmount?: string;
  };
}

export interface PaxBatchInformationResponseModel {
  status?: boolean;
  ecrReferenceNumber?: number;
  totalRecord?: number;
  totalAmount?: number;
  message?: string;
  data?: PaxHistoryData;
}

/**
 * Shape RAW trả về trực tiếp từ native module.
 * Không dùng trực tiếp ở UI — hãy dùng PaxResult (xem pax-error.ts) đã chuẩn hoá.
 */
export interface PaxResponseModel {
  status?: boolean;
  data?: any; // WritableMap equivalent, adjust as needed
  message?: string;
  isPaymentSuccess?: boolean;
  // --- raw codes (native báo cáo trung thực, JS tự phân loại) ---
  /** ExecutionCode tầng SDK: "OK" | "ERROR" */
  execCode?: string;
  /** message tầng SDK/giao tiếp */
  execMessage?: string;
  /** mã phản hồi POSLink (tầng terminal) */
  responseCode?: string;
  /** message tầng terminal */
  responseMessage?: string;
  /** mã phản hồi host/ngân hàng */
  hostResponseCode?: string;
  /** message tầng host */
  hostResponseMessage?: string;
  /** mã issuer (lý do decline) */
  issuerResponseCode?: string;
  id?: string;
  transactionId?: string;
  transactionNo?: string;
  ecrRefNum?: string;
  refNum?: string;
  transactionDateTime?: string;
  cardType?: string;
  cardNumber?: string;
  cardHolder?: string;
  amount?: string;
  tipAmount?: string;
  surcharge?: string;
  entryMethod?: string;
  sn?: PaxTerminalInfoModel;
}

export interface PaxTerminalInfoModel {
  serialNumber?: string;
  modelName?: string;
  appName?: string;
}

export interface PaxStatusResponseModel {
  status: boolean;
  message?: string;
  data?: {
    torInformation?: PaxTorInformation[];
  };
  serialNumber?: PaxTerminalInfoModel;
}

export interface PaxTorInformation {
  batchNumber?: string;
  gatewayTransactionId?: string;
  hostReferenceNumber?: string;
  hostResponseCode?: string;
  hostResponseMessage?: string;
  maskedPan?: string;
  originalAmount?: string;
  tipAmount?: string;
  ecrReferenceNumber?: string;
}

export enum CreditTransactionType {
  Credit = 1,
  Debit = 2,
  Empty = 0,
}
