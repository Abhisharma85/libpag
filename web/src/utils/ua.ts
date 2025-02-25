const nav = navigator?.userAgent || '';
export const ANDROID = /android|adr/i.test(nav);
export const MOBILE = /(mobile)/i.test(nav) && ANDROID;
export const MACOS = !(/(mobile)/i.test(nav) || MOBILE) && /Mac OS X/i.test(nav);
export const IPHONE = /(iphone|ipad|ipod)/i.test(nav);
export const WECHAT = /MicroMessenger/i.test(nav);
export const SAFARI = /^((?!chrome|android).)*safari/i.test(nav);
export const WORKER = typeof globalThis.importScripts === 'function';
