"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
var _exportNames = {
  initPOSLink: true,
  makePayment: true,
  makeRefund: true,
  makeVoid: true,
  makeCloseBatch: true,
  checkVoidOrRefundTransaction: true,
  getBatchInformation: true
};
exports.checkVoidOrRefundTransaction = checkVoidOrRefundTransaction;
exports.getBatchInformation = getBatchInformation;
exports.initPOSLink = initPOSLink;
exports.makeCloseBatch = makeCloseBatch;
exports.makePayment = makePayment;
exports.makeRefund = makeRefund;
exports.makeVoid = makeVoid;
var _NativePaxPoslink = _interopRequireDefault(require("./NativePaxPoslink.js"));
var _type = require("./type.js");
Object.keys(_type).forEach(function (key) {
  if (key === "default" || key === "__esModule") return;
  if (Object.prototype.hasOwnProperty.call(_exportNames, key)) return;
  if (key in exports && exports[key] === _type[key]) return;
  Object.defineProperty(exports, key, {
    enumerable: true,
    get: function () {
      return _type[key];
    }
  });
});
function _interopRequireDefault(e) { return e && e.__esModule ? e : { default: e }; }
const PaxPosLink = _NativePaxPoslink.default ?? new Proxy({}, {
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
function initPOSLink(ip, options) {
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
function makePayment(id, amount = 0, tip, paymentType, ecrRefNum, showTip) {
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
 * Initiates a refund transaction.
 * @param {string} amount - The amount to refund.
 * @param {string} ecrRefNum - The ECR reference number.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the refund result.
 */
function makeRefund(amount, ecrRefNum) {
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
function makeVoid(ecrRefNum) {
  return PaxPosLink.voidTransaction({
    ecrRefNum
  });
}

/**
 * Closes the current batch of transactions.
 * @returns {Promise<PaxResponseModel>} A promise resolving to the batch closeout result.
 */

function makeCloseBatch() {
  return PaxPosLink.batchCloseout();
}
/**
 * Voids a transaction for the given amount.
 * @param {string} ecrRefNum - The ECR reference number.
 */
function checkVoidOrRefundTransaction(ecrRefNum) {
  return PaxPosLink.checkVoidOrRefundTransaction(ecrRefNum);
}
/**
 * Gets all transactions.
 * @returns {Promise<PaxBatchInformationResponseModel>} A promise resolving to the transactions list.
 */
function getBatchInformation() {
  return PaxPosLink.getBatchInformation();
}
//# sourceMappingURL=index.js.map