"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.CreditTransactionType = void 0;
/**
 * Các kiểu kết nối tới terminal PAX mà SDK hỗ trợ (mirror theo demo POSLink).
 * - TCP / SSL / HTTP / HTTPS : kết nối mạng (cần `ip`, `port`).
 * - UART                     : cổng serial (cần `serialPort`, `baudRate`).
 * - USB                      : qua cổng USB của thiết bị (tuỳ chọn `deviceName`).
 * - AIDL                     : giao tiếp với BroadPOS trên cùng thiết bị.
 * - BLUETOOTH                : kết nối Bluetooth (cần `macAddr`).
 */
/** Thiết bị Bluetooth phát hiện được khi quét (dùng cho `type: 'BLUETOOTH'`). */
/**
 * Shape RAW trả về trực tiếp từ native module.
 * Không dùng trực tiếp ở UI — hãy dùng PaxResult (xem pax-error.ts) đã chuẩn hoá.
 */
let CreditTransactionType = exports.CreditTransactionType = /*#__PURE__*/function (CreditTransactionType) {
  CreditTransactionType[CreditTransactionType["Credit"] = 1] = "Credit";
  CreditTransactionType[CreditTransactionType["Debit"] = 2] = "Debit";
  CreditTransactionType[CreditTransactionType["Empty"] = 0] = "Empty";
  return CreditTransactionType;
}({});
//# sourceMappingURL=type.js.map