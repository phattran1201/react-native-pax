"use strict";

import { NativeModules, Platform } from 'react-native';
const LINKING_ERROR = `The package '@haroldtran/react-native-pax' doesn't seem to be linked. Make sure: \n\n` + Platform.select({
  ios: "- You have run 'pod install'\n",
  default: ''
}) + '- You rebuilt the app after installing the package\n' + '- You are not using Expo Go\n';
const PaxPoslink = NativeModules.PaxPoslink ? NativeModules.PaxPoslink : new Proxy({}, {
  get() {
    throw new Error(LINKING_ERROR);
  }
});
export function initPOSLink(type, timeout, proxy, ip, port) {
  return PaxPoslink.initPOSLink(type, timeout, proxy, ip, port);
}
export function makePayment(amount, _tip = '0') {
  return PaxPoslink.runPayment(amount, _tip);
}
export function makeReturn(amount) {
  return PaxPoslink.runReturn(amount);
}
export function makeAdjustment(amount, refNum) {
  return PaxPoslink.runAdjustment(amount, refNum);
}
export function makeAuth(amount) {
  return PaxPoslink.runAuth(amount);
}
export function makePostAuth(amount, refNum, autCode) {
  return PaxPoslink.runPostAuth(amount, refNum, autCode);
}
export function voidTransaction(refNum, autCode) {
  return PaxPoslink.runVoid(refNum, autCode);
}
export function closeBatch() {
  return PaxPoslink.closeBatch();
}
//# sourceMappingURL=index.js.map