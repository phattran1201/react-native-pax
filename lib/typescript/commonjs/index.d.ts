import { PaxResponseModel } from './type';
/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @returns {*} The result of the native initPOSLink call.
 */
export declare function initPOSLink(ip: string): any;
/**
 * Initiates a payment transaction.
 * @param {string} [id] - Transaction ID (optional).
 * @param {number} [amount] - Payment amount
 * @param {number} [tip] - Tip amount (optional).
 * @param {number} [paymentType] - Type of payment (optional).
 * @param {string} [ecrRefNum] - ECR reference number (optional).
 * @returns {Promise<PaxResponseModel>} A promise resolving to the payment result.
 */
export declare function makePayment(id?: string, amount?: number, tip?: number, paymentType?: number, ecrRefNum?: string): Promise<PaxResponseModel>;
/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the refund result.
 */
export declare function makeRefund(amount: string): Promise<PaxResponseModel>;
/**
 * Voids a transaction for the given amount.
 * @param {string} amount - The amount to void.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the void result.
 */
export declare function makeVoid(amount: string): Promise<PaxResponseModel>;
/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the batch closeout result.
 */
export declare function makeCloseBatch(): Promise<PaxResponseModel>;
//# sourceMappingURL=index.d.ts.map