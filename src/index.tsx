import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package '@haroldtran/react-native-pax' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

const PaxPosLink = NativeModules.PaxPoslink
  ? NativeModules.PaxPoslink
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
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
 * @returns {Promise<string>} A promise resolving to the payment result.
 */
export function makePayment(
  id?: string,
  amount: number = 0,
  tip?: number,
  paymentType?: number,
  ecrRefNum?: string
): Promise<string> {
  return PaxPosLink.payment({ id, amount, tip, paymentType, ecrRefNum });
}

/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @returns {Promise<string>} A promise resolving to the refund result.
 */
export function makeRefund(amount: string): Promise<string> {
  return PaxPosLink.refund({ amount });
}

/**
 * Voids a transaction for the given amount.
 * @param {string} amount - The amount to void.
 * @returns {Promise<string>} A promise resolving to the void result.
 */
export function makeVoid(amount: string): Promise<string> {
  return PaxPosLink.void({ amount });
}

/**
 * Closes the current batch of transactions.
 * @returns {Promise<string>} A promise resolving to the batch closeout result.
 */
export function makeCloseBatch(): Promise<string> {
  return PaxPosLink.batchCloseout();
}
