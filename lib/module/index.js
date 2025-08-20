"use strict";

import { NativeModules, Platform } from 'react-native';
// This package is Android-only. Provide clear errors on non-Android platforms
const ANDROID_ONLY_ERROR = "The package '@haroldtran/react-native-pax' only supports Android.";
const LINKING_ERROR = `The package '@haroldtran/react-native-pax' doesn't seem to be linked. Make sure:\n\n` + '- You rebuilt the app after installing the package\n' + '- You are not using Expo Go\n';
const isAndroid = Platform.OS === 'android';
const PaxPosLink = isAndroid ? NativeModules.PaxPoslink ?? new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }
}) : new Proxy({}, {
  get() {
    throw new Error(ANDROID_ONLY_ERROR);
  }
});

/**
 * Initializes the POSLink connection.
 * @param {string} [ip] - The IP address of the POS device.
 * @returns {*} The result of the native initPOSLink call.
 */
export function initPOSLink(ip) {
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
export function makePayment(id, amount = 0, tip, paymentType, ecrRefNum) {
  return PaxPosLink.payment({
    id,
    amount,
    tip,
    paymentType,
    ecrRefNum
  });
}

/**
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the refund result.
 */
export function makeRefund(amount) {
  return PaxPosLink.refund({
    amount
  });
}

/**
 * Voids a transaction for the given amount.
 * @param {string} amount - The amount to void.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the void result.
 */
export function makeVoid(amount) {
  return PaxPosLink.void({
    amount
  });
}

/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the batch closeout result.
 */
export function makeCloseBatch() {
  return PaxPosLink.batchCloseout();
}
//# sourceMappingURL=index.js.map