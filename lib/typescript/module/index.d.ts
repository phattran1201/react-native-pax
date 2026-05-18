import { PaxBatchInformationResponseModel, PaxInitModel, PaxResponseModel } from './type';
export * from './type';
/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @param {object} [options] - Optional parameters.
 * @param {string} [options.port] - The port number of the POS device.
 * @param {number} [options.timeout] - The timeout value for the connection.
 * @returns {Promise<PaxInitModel>} A promise resolving to the initPOSLink result.
 */
export declare function initPOSLink(ip: string, options?: {
    port?: string;
    timeout?: number;
}): Promise<PaxInitModel>;
/**
 * Initiates a payment transaction.
 * @param {string} [id] - Transaction ID (optional).
 * @param {number} [amount] - Payment amount
 * @param {number} [tip] - Tip amount (optional).
 * @param {number} [paymentType] - Type of payment (optional).
 * @param {string} [ecrRefNum] - ECR reference number (optional).
 * @returns {Promise<PaxResponseModel>} A promise resolving to the payment result.
 */
export declare function makePayment(id?: string, amount?: number, tip?: number, paymentType?: number, ecrRefNum?: string, showTip?: boolean): Promise<PaxResponseModel>;
/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the refund result.
 */
export declare function makeRefund(amount: number, ecrRefNum: string): Promise<PaxResponseModel>;
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the void result.
 */
export declare function makeVoid(ecrRefNum: string): Promise<PaxResponseModel>;
/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the batch closeout result.
 */
export declare function makeCloseBatch(): Promise<PaxResponseModel>;
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 */
export declare function checkVoidOrRefundTransaction(ecrRefNum: string): Promise<Record<string, unknown>>;
/**
 * Gets all transactions.
 * @returns {Promise<PaxBatchInformationResponseModel>} A promise resolving to the transactions list.
 */
export declare function getBatchInformation(): Promise<PaxBatchInformationResponseModel>;
//# sourceMappingURL=index.d.ts.map