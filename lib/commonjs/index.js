"use strict";

Object.defineProperty(exports, "__esModule", {
  value: true
});
exports.closeBatch = closeBatch;
exports.initPOSLink = initPOSLink;
exports.makeAdjustment = makeAdjustment;
exports.makeAuth = makeAuth;
exports.makePayment = makePayment;
exports.makePostAuth = makePostAuth;
exports.makeReturn = makeReturn;
exports.voidTransaction = voidTransaction;
var _reactNative = require("react-native");
const LINKING_ERROR = `The package '@haroldtran/react-native-pax' doesn't seem to be linked. Make sure: \n\n` + _reactNative.Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo Go\n';
const PaxPoslink = _reactNative.NativeModules.PaxPoslink ? _reactNative.NativeModules.PaxPoslink : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }
});
function initPOSLink(type, timeout, proxy, ip, port) {
  return PaxPoslink.initPOSLink(type, timeout, proxy, ip, port);
}
function makePayment(amount, _tip = '0') {
  return PaxPoslink.runPayment(amount, _tip);
}
function makeReturn(amount) {
  return PaxPoslink.runReturn(amount);
}
function makeAdjustment(amount, refNum) {
  return PaxPoslink.runAdjustment(amount, refNum);
}
function makeAuth(amount) {
  return PaxPoslink.runAuth(amount);
}
function makePostAuth(amount, refNum, autCode) {
  return PaxPoslink.runPostAuth(amount, refNum, autCode);
}
function voidTransaction(refNum, autCode) {
  return PaxPoslink.runVoid(refNum, autCode);
}
function closeBatch() {
  return PaxPoslink.closeBatch();
}
//# sourceMappingURL=index.js.map