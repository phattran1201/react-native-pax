import {
  PaxBatchInformationResponseModel,
  PaxInitModel,
  PaxResponseModel,
} from './type';
import NativePaxPoslink from './NativePaxPoslink';
export * from './type';

const PaxPosLink =
  NativePaxPoslink ??
  new Proxy(
    {},
    {
      get() {
        throw new Error(
          `The package '@haroldtran/react-native-pax' is not linked. Rebuild the app after installing.`
        );
      },
    }
  );

/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @param {object} [options] - Optional parameters.
 * @param {string} [options.port] - The port number of the POS device.
 * @param {number} [options.timeout] - The timeout value for the connection.
 * @returns {Promise<PaxInitModel>} A promise resolving to the initPOSLink result.
 */
export function initPOSLink(
  ip: string,
  options?: { port?: string; timeout?: number }
): Promise<PaxInitModel> {
  return PaxPosLink.initPOSLink(ip, options?.port, options?.timeout);
}

/**
 * Initiates a payment transaction.
 * @param {string} [id] - Transaction ID (optional).
 * @param {number} [amount] - Payment amount
 * @param {number} [tip] - Tip amount (optional).
 * @param {number} [paymentType] - Type of payment (optional).
 * @param {string} [ecrRefNum] - ECR reference number (optional).
 * @returns {Promise<PaxResponseModel>} A promise resolving to the payment result.
 */
export function makePayment(
  id?: string,
  amount: number = 0,
  tip?: number,
  paymentType?: number,
  ecrRefNum?: string,
  showTip?: boolean
): Promise<PaxResponseModel> {
  return PaxPosLink.payment({
    transactionId: id,
    amount,
    tip,
    paymentType,
    ecrRefNum,
    showTip,
  });
}

/**
 * Requests cancellation of the active terminal command or transaction.
 * @returns {Promise<string>} A promise resolving once the cancel request is sent.
 */
export function cancelTransaction(): Promise<string> {
  return PaxPosLink.cancelTransaction();
}

/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the refund result.
 */
export function makeRefund(
  amount: number,
  ecrRefNum: string
): Promise<PaxResponseModel> {
  return PaxPosLink.refund({ amount, ecrRefNum });
}

/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the void result.
 */
export function makeVoid(ecrRefNum: string): Promise<PaxResponseModel> {
  return PaxPosLink.voidTransaction({ ecrRefNum });
}

/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the batch closeout result.
 */

export function makeCloseBatch(): Promise<PaxResponseModel> {
  return PaxPosLink.batchCloseout();
}
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 */
export function checkVoidOrRefundTransaction(ecrRefNum: string) {
  return PaxPosLink.checkVoidOrRefundTransaction(ecrRefNum);
}
/**
 * Gets all transactions.
 * @returns {Promise<PaxBatchInformationResponseModel>} A promise resolving to the transactions list.
 */
export function getBatchInformation(): Promise<PaxBatchInformationResponseModel> {
  return PaxPosLink.getBatchInformation();
}
