import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package '@haroldtran/react-native-pax' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

const PaxPoslink = NativeModules.PaxPoslink
  ? NativeModules.PaxPoslink
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

export function initPOSLink(
  type:
    | 'UART'
    | 'TCP'
    | 'SSL'
    | 'HTTP'
    | 'HTTPS'
    | 'BLUETOOTH'
    | 'USB'
    | 'AIDL',
  timeout: string,
  proxy: boolean,
  ip?: any,
  port?: any
): Promise<boolean> {
  return PaxPoslink.initPOSLink(type, timeout, proxy, ip, port);
}

export function makePayment(
  amount: string,
  _tip: string = '0'
): Promise<string> {
  return PaxPoslink.runPayment(amount, _tip);
}

export function makeReturn(amount: string): Promise<string> {
  return PaxPoslink.runReturn(amount);
}

export function makeAdjustment(
  amount: string,
  refNum: string
): Promise<string> {
  return PaxPoslink.runAdjustment(amount, refNum);
}

export function makeAuth(amount: string): Promise<string> {
  return PaxPoslink.runAuth(amount);
}

export function makePostAuth(
  amount: string,
  refNum: string,
  autCode: string
): Promise<string> {
  return PaxPoslink.runPostAuth(amount, refNum, autCode);
}

export function voidTransaction(
  refNum: string,
  autCode: string
): Promise<string> {
  return PaxPoslink.runVoid(refNum, autCode);
}

export function closeBatch(): Promise<string> {
  return PaxPoslink.closeBatch();
}
