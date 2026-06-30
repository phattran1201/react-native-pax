import type { TurboModule } from 'react-native';
export interface Spec extends TurboModule {
    initPOSLink(ip: string, port?: string, timeout?: number): Promise<{
        serialNumber?: {
            modelName: string;
            appName: string;
            serialNumber: string;
        };
        status: boolean;
    }>;
    /**
     * Kết nối tới terminal theo bất kỳ kiểu giao tiếp nào SDK hỗ trợ.
     * config.type: "TCP" | "SSL" | "HTTP" | "HTTPS" | "UART" | "USB" | "AIDL" | "BLUETOOTH"
     */
    initPOSLinkConn(config: {
        type: string;
        ip?: string;
        port?: string;
        serialPort?: string;
        baudRate?: string;
        deviceName?: string;
        macAddr?: string;
        timeout?: number;
    }): Promise<{
        serialNumber?: {
            modelName: string;
            appName: string;
            serialNumber: string;
        };
        status: boolean;
    }>;
    requestUsbPermission(): Promise<boolean>;
    /** Liệt kê thiết bị USB đang cắm (dùng để chọn deviceName cho type: 'USB'). */
    listUsbDevices(): Promise<Array<{
        deviceName: string;
        productName: string;
        vendorId: number;
        productId: number;
    }>>;
    /** Danh sách baud rate hợp lệ cho kết nối UART. */
    getSupportedBaudRates(): Promise<string[]>;
    /** Quét các cổng serial hiện có (dùng để chọn `serialPort` cho type: 'UART'). */
    listSerialPorts(): Promise<string[]>;
    /** Kiểm tra Bluetooth đã bật chưa. */
    checkBluetoothEnable(): Promise<boolean>;
    /**
     * Bắt đầu quét thiết bị Bluetooth (gom vào list nội bộ, UI poll getBluetoothDeviceList).
     * @param useBle true = quét BLE, false = Bluetooth classic.
     * @param timeout thời lượng quét truyền cho scanner (vd 1000).
     */
    startBluetoothSearch(useBle: boolean, timeout: number): Promise<boolean>;
    /** Dừng quét Bluetooth và xoá list nội bộ. */
    stopBluetoothSearch(): Promise<boolean>;
    /** Lấy list thiết bị Bluetooth đã phát hiện: [{ name, mac, rssi }]. */
    getBluetoothDeviceList(): Promise<Array<{
        name: string;
        mac: string;
        rssi: number;
    }>>;
    payment(data: {
        transactionId?: string;
        amount?: number;
        tip?: number;
        paymentType?: number;
        ecrRefNum?: string;
        showTip?: boolean;
    }): Promise<Record<string, unknown>>;
    refund(data: {
        amount: number;
        ecrRefNum: string;
    }): Promise<Record<string, unknown>>;
    voidTransaction(data: {
        ecrRefNum: string;
    }): Promise<Record<string, unknown>>;
    batchCloseout(): Promise<Record<string, unknown>>;
    getBatchInformation(): Promise<Record<string, unknown>>;
    checkVoidOrRefundTransaction(ecrRefNum: string): Promise<Record<string, unknown>>;
    cancelTransaction(): Promise<string>;
}
declare const _default: Spec;
export default _default;
//# sourceMappingURL=NativePaxPoslink.d.ts.map