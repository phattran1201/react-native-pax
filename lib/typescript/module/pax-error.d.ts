import type { PaxResponseModel } from './type';
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
export declare enum PaxErrorType {
    /** Không lỗi (giao dịch thành công) */
    None = "NONE",
    /** Mất kết nối / timeout / terminal chưa init -> có thể retry */
    Communication = "COMMUNICATION",
    /** Người dùng huỷ trên terminal */
    UserCanceled = "USER_CANCELED",
    /** Terminal (POSLink) từ chối */
    TerminalDeclined = "TERMINAL_DECLINED",
    /** Host / ngân hàng từ chối (hết tiền, khoá thẻ...) */
    HostDeclined = "HOST_DECLINED",
    /** Giao dịch trùng */
    Duplicate = "DUPLICATE",
    /** Không xác định được */
    Unknown = "UNKNOWN"
}
/** Các mã gốc lấy trực tiếp từ native, giữ lại để log/debug. */
export interface PaxRawCodes {
    execCode: string;
    execMessage: string;
    responseCode: string;
    responseMessage: string;
    hostResponseCode: string;
    hostResponseMessage: string;
    issuerResponseCode: string;
}
export interface PaxError {
    /** Loại lỗi đã phân loại — switch trên field này để xử lý */
    type: PaxErrorType;
    /** Mã đáng tin nhất để hiển thị/log */
    code: string;
    /** Message cho người dùng đọc */
    message: string;
    /** Gợi ý có nên cho retry không (vd lỗi giao tiếp) */
    retryable: boolean;
    /** Toàn bộ mã gốc để debug */
    raw: PaxRawCodes;
}
/** Kiểu trả về chuẩn hoá — discriminated union để TypeScript tự narrow. */
export type PaxResult<T = PaxResponseModel> = {
    ok: true;
    data: T;
} | {
    ok: false;
    error: PaxError;
};
/** Map raw codes -> PaxError. Đây là toàn bộ "bộ não" phân loại. */
export declare function classifyError(raw: PaxRawCodes): PaxError;
/**
 * Chuyển 1 exception (do promise.reject từ native) thành PaxResult lỗi.
 * Native reject với code như "NO_TERMINAL", "PAYMENT_ERROR"... ở field `.code`.
 */
export declare function fromThrown(e: unknown): PaxResult<never>;
/**
 * Chuẩn hoá response native phẳng -> PaxResult.
 * Quyết định ok/lỗi dựa trên cờ success của native (giữ nguyên hành vi cũ);
 * nếu lỗi thì phân loại bằng classifyError.
 */
export declare function toPaxResult<T = PaxResponseModel>(raw: PaxResponseModel | null | undefined): PaxResult<T>;
//# sourceMappingURL=pax-error.d.ts.map