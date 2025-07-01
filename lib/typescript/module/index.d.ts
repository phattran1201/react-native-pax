export declare function initPOSLink(type: 'UART' | 'TCP' | 'SSL' | 'HTTP' | 'HTTPS' | 'BLUETOOTH' | 'USB' | 'AIDL', timeout: string, proxy: boolean, ip?: any, port?: any): Promise<boolean>;
export declare function makePayment(amount: string, _tip?: string): Promise<string>;
export declare function makeReturn(amount: string): Promise<string>;
export declare function makeAdjustment(amount: string, refNum: string): Promise<string>;
export declare function makeAuth(amount: string): Promise<string>;
export declare function makePostAuth(amount: string, refNum: string, autCode: string): Promise<string>;
export declare function voidTransaction(refNum: string, autCode: string): Promise<string>;
export declare function closeBatch(): Promise<string>;
//# sourceMappingURL=index.d.ts.map