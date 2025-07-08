export interface PaxRequestModel {
    id?: string;
    amount?: number;
    tip?: number;
    paymentType?: number;
    ecrRefNum?: string;
}
export interface PaxResponseModel {
    status?: boolean;
    data?: any;
    message?: string;
    isPaymentSuccess?: boolean;
    id?: string;
    transactionId?: string;
    transactionNo?: string;
    refNum?: string;
    transactionDateTime?: string;
    cardType?: string;
    cardNumber?: string;
    cardHolder?: string;
    amount?: string;
    tipAmount?: string;
    surcharge?: string;
    entryMethod?: string;
    sn?: string;
}
export interface PaxTerminalInfoModel {
    serialNumber?: string;
    modelName?: string;
    appName?: string;
}
export declare enum CreditTransactionType {
    Credit = 1,
    Debit = 2,
    Empty = 0
}
//# sourceMappingURL=type.d.ts.map