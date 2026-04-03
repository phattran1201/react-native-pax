export interface PaxInitModel {
  serialNumber?: {
    modelName: string;
    appName: string;
    serialNumber: string;
  };
  status: boolean;
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

export interface PaxResponseModel {
  status?: boolean;
  data?: any; // WritableMap equivalent, adjust as needed
  message?: string;
  isPaymentSuccess?: boolean;
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
  sn: PaxTerminalInfoModel;
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
