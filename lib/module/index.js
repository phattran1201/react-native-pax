"use strict";

import NativePaxPoslink from "./NativePaxPoslink.js";
export * from "./type.js";
const PaxPosLink = NativePaxPoslink ?? new Proxy({}, {
  get() {
    throw new Error(`The package '@haroldtran/react-native-pax' is not linked. Rebuild the app after installing.`);
  }
});

/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @param {object} [options] - Optional parameters.
 * @param {string} [options.port] - The port number of the POS device.
 * @param {number} [options.timeout] - The timeout value for the connection.
 * @returns {Promise<PaxInitModel>} A promise resolving to the initPOSLink result.
 */
export function initPOSLink(ip, options) {
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
export function makePayment(id, amount = 0, tip, paymentType, ecrRefNum, showTip) {
  return PaxPosLink.payment({
    transactionId: id,
    amount,
    tip,
    paymentType,
    ecrRefNum,
    showTip
  });
}

/**
 * Requests cancellation of the active terminal command or transaction.
 * @returns {Promise<string>} A promise resolving once the cancel request is sent.
 */
export function cancelTransaction() {
  return PaxPosLink.cancelTransaction();
}

/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the refund result.
 */
export function makeRefund(amount, ecrRefNum) {
  return PaxPosLink.refund({
    amount,
    ecrRefNum
  });
}

/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the void result.
 */
export function makeVoid(ecrRefNum) {
  return PaxPosLink.voidTransaction({
    ecrRefNum
  });
}

/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the batch closeout result.
 */

export function makeCloseBatch() {
  return PaxPosLink.batchCloseout();
}
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 */
export function checkVoidOrRefundTransaction(ecrRefNum) {
  return PaxPosLink.checkVoidOrRefundTransaction(ecrRefNum);
}
/**
 * Gets all transactions.
 * @returns {Promise<PaxBatchInformationResponseModel>} A promise resolving to the transactions list.
 */
export function getBatchInformation() {
  return PaxPosLink.getBatchInformation();
}
//# sourceMappingURL=index.js.map