import { NativeModules, Platform } from 'react-native';
import { PaxResponseModel } from './type';
export * from './type';
// This package is Android-only. Provide clear errors on non-Android platforms
const ANDROID_ONLY_ERROR =
  "The package '@haroldtran/react-native-pax' only supports Android.";

const LINKING_ERROR =
  `The package '@haroldtran/react-native-pax' doesn't seem to be linked. Make sure:\n\n` +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

const isAndroid = Platform.OS === 'android';

const PaxPosLink = isAndroid
  ? NativeModules.PaxPoslink ??
    new Proxy(
      {},
      {
        get() {
          const err = new Error(LINKING_ERROR);
          err.stack = '';
          throw err;
        },
      }
    )
  : new Proxy(
      {},
      {
        get() {
          const err = new Error(ANDROID_ONLY_ERROR);
          err.stack = '';
          throw err;
        },
      }
    );

/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @returns {*} The result of the native initPOSLink call.
 */
export function initPOSLink(ip: string) {
  return PaxPosLink.initPOSLink(ip);
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
  ecrRefNum?: string
): Promise<PaxResponseModel> {
  return PaxPosLink.payment({ id, amount, tip, paymentType, ecrRefNum });
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
  return PaxPosLink.void({ ecrRefNum });
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
