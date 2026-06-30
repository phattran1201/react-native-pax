"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.PaxErrorType = void 0;
exports.classifyError = classifyError;
exports.fromThrown = fromThrown;
exports.toPaxResult = toPaxResult;
/**
 * Phân loại lỗi giao dịch ở tầng JS.
 *
 * Vì sao đặt ở đây mà không đặt trong native (Kotlin/Swift)?
 *  - Quy tắc "mã nào = lỗi gì" là business logic, thay đổi theo từng host/processor.
 *  - Sửa ở JS không cần rebuild + release lại native.
 *  - Dễ viết unit test cho từng case.
 *
 * Native chỉ trả RAW codes trung thực (xem PaxResponseModel), việc map sang
 * PaxErrorType nằm trọn trong file này.
 */
let PaxErrorType = exports.PaxErrorType = /*#__PURE__*/function (PaxErrorType) {
  /** Không lỗi (giao dịch thành công) */
  PaxErrorType["None"] = "NONE";
  /** Mất kết nối / timeout / terminal chưa init -> có thể retry */
  PaxErrorType["Communication"] = "COMMUNICATION";
  /** Người dùng huỷ trên terminal */
  PaxErrorType["UserCanceled"] = "USER_CANCELED";
  /** Terminal (POSLink) từ chối */
  PaxErrorType["TerminalDeclined"] = "TERMINAL_DECLINED";
  /** Host / ngân hàng từ chối (hết tiền, khoá thẻ...) */
  PaxErrorType["HostDeclined"] = "HOST_DECLINED";
  /** Giao dịch trùng */
  PaxErrorType["Duplicate"] = "DUPLICATE";
  /** Không xác định được */
  PaxErrorType["Unknown"] = "UNKNOWN";
  return PaxErrorType;
}({});
/** Các mã gốc lấy trực tiếp từ native, giữ lại để log/debug. */
/** Kiểu trả về chuẩn hoá — discriminated union để TypeScript tự narrow. */
// ---------------------------------------------------------------------------
// BẢNG PHÂN LOẠI — chỉ cần sửa khu vực này khi gặp mã mới của processor.
// Lưu ý: các mã số dưới đây là GỢI Ý theo chuẩn ISO 8583 phổ biến, BẠN NÊN
// đối chiếu với log thật rồi chỉnh lại cho khớp host đang dùng.
// ---------------------------------------------------------------------------

/** Mã coi như "đã duyệt" (không phải lỗi). */
const APPROVED_CODES = new Set(['', '00', '000', '0000', '000000']);

/** Mã host/terminal báo giao dịch trùng. */
const DUPLICATE_CODES = new Set(['94']);
const includesAny = (text, keywords) => keywords.some(k => text.includes(k));

/** Map raw codes -> PaxError. Đây là toàn bộ "bộ não" phân loại. */
function classifyError(raw) {
  const msg = `${raw.responseMessage} ${raw.hostResponseMessage} ${raw.execMessage}`.toUpperCase();
  const make = (type, retryable) => ({
    type,
    retryable,
    code: raw.hostResponseCode || raw.responseCode || raw.execCode || 'UNKNOWN',
    message: raw.responseMessage || raw.hostResponseMessage || raw.execMessage || 'Giao dịch thất bại',
    raw
  });

  // 1) Trùng giao dịch
  if (msg.includes('DUPLICATE') || DUPLICATE_CODES.has(raw.hostResponseCode) || DUPLICATE_CODES.has(raw.responseCode)) {
    return make(PaxErrorType.Duplicate, false);
  }

  // 2) Người dùng huỷ
  if (includesAny(msg, ['CANCEL', 'ABORT', 'USER'])) {
    return make(PaxErrorType.UserCanceled, false);
  }

  // 3) Lỗi giao tiếp / timeout -> nên cho retry
  if (raw.execCode === 'ERROR' || includesAny(msg, ['TIMEOUT', 'NO RESPONSE', 'CONNECT', 'COMM'])) {
    return make(PaxErrorType.Communication, true);
  }

  // 4) Host / ngân hàng từ chối
  if (raw.hostResponseCode && !APPROVED_CODES.has(raw.hostResponseCode)) {
    return make(PaxErrorType.HostDeclined, false);
  }

  // 5) Terminal từ chối
  if (raw.responseCode && !APPROVED_CODES.has(raw.responseCode)) {
    return make(PaxErrorType.TerminalDeclined, false);
  }
  return make(PaxErrorType.Unknown, false);
}

/**
 * Trích raw codes từ response native.
 * Dùng `||` (không phải `??`) vì native gửi chuỗi rỗng "" cho field chưa set,
 * nên cần fallback cả trên "" lẫn undefined.
 */
function extractRaw(r) {
  return {
    execCode: r.execCode || 'ERROR',
    execMessage: r.execMessage || '',
    responseCode: r.responseCode || '',
    responseMessage: r.responseMessage || r.message || '',
    hostResponseCode: r.hostResponseCode || '',
    hostResponseMessage: r.hostResponseMessage || '',
    issuerResponseCode: r.issuerResponseCode || ''
  };
}

/**
 * Chuyển 1 exception (do promise.reject từ native) thành PaxResult lỗi.
 * Native reject với code như "NO_TERMINAL", "PAYMENT_ERROR"... ở field `.code`.
 */
function fromThrown(e) {
  const err = e;
  const code = err?.code ?? 'UNKNOWN';
  const message = err?.message || code || 'Giao dịch thất bại';
  // Terminal chưa kết nối => coi là lỗi giao tiếp, cho phép retry
  const type = code === 'NO_TERMINAL' ? PaxErrorType.Communication : PaxErrorType.Unknown;
  return {
    ok: false,
    error: {
      type,
      code,
      message,
      retryable: type === PaxErrorType.Communication,
      raw: {
        execCode: 'ERROR',
        execMessage: message,
        responseCode: '',
        responseMessage: '',
        hostResponseCode: '',
        hostResponseMessage: '',
        issuerResponseCode: ''
      }
    }
  };
}

/**
 * Chuẩn hoá response native phẳng -> PaxResult.
 * Quyết định ok/lỗi dựa trên cờ success của native (giữ nguyên hành vi cũ);
 * nếu lỗi thì phân loại bằng classifyError.
 */
function toPaxResult(raw) {
  if (!raw) {
    return {
      ok: false,
      error: classifyError({
        execCode: 'ERROR',
        execMessage: 'No response from native module',
        responseCode: '',
        responseMessage: '',
        hostResponseCode: '',
        hostResponseMessage: '',
        issuerResponseCode: ''
      })
    };
  }
  if (raw.status === true && raw.isPaymentSuccess === true) {
    return {
      ok: true,
      data: raw
    };
  }
  return {
    ok: false,
    error: classifyError(extractRaw(raw))
  };
}
//# sourceMappingURL=pax-error.js.map