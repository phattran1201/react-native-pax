import type { TurboModule } from 'react-native';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  initPOSLink(
    ip: string,
    port?: string,
    timeout?: number
  ): Promise<{
    serialNumber?: {
      modelName: string;
      appName: string;
      serialNumber: string;
    };
    status: boolean;
  }>;
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
  checkVoidOrRefundTransaction(
    ecrRefNum: string
  ): Promise<Record<string, unknown>>;
  cancelTransaction(): Promise<string>;
}

export default TurboModuleRegistry.getEnforcing<Spec>('PaxPoslink');
