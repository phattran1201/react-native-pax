export interface PaxRequestModel {
  id?: string;
  amount?: number;
  tip?: number;
  paymentType?: number;
  ecrRefNum?: string;
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
  sn?: string;
}

export interface PaxTerminalInfoModel {
  serialNumber?: string;
  modelName?: string;
  appName?: string;
}

export enum CreditTransactionType {
  Credit = 1,
  Debit = 2,
  Empty = 0,
}
