const base64Decode = require('fast-base64-decode')
const { TurboModuleRegistry } = require('react-native')

class TypeMismatchError extends Error {}
class QuotaExceededError extends Error {}

let module = null
/**
 * @param {number} byteLength
 * @returns {string}
 */
function getRandomBase64 (byteLength) {
  if (module == null) {
    module = TurboModuleRegistry.getEnforcing('RNGetRandomValues')
  }

  return module.getRandomBase64(byteLength)
}

/**
 * @param {Int8Array|Uint8Array|Int16Array|Uint16Array|Int32Array|Uint32Array|Uint8ClampedArray} array
 */
function getRandomValues (array) {
  if (!(array instanceof Int8Array || array instanceof Uint8Array || array instanceof Int16Array || array instanceof Uint16Array || array instanceof Int32Array || array instanceof Uint32Array || array instanceof Uint8ClampedArray)) {
    throw new TypeMismatchError('Expected an integer array')
  }

  if (array.byteLength > 65536) {
    throw new QuotaExceededError('Can only request a maximum of 65536 bytes')
  }

  // Expo SDK 48+
  if (global.expo?.modules?.ExpoCrypto?.getRandomValues) {
    // ExpoCrypto.getRandomValues doesn't return the array
    global.expo.modules.ExpoCrypto.getRandomValues(array)
    return array
  }

  base64Decode(getRandomBase64(array.byteLength), new Uint8Array(array.buffer, array.byteOffset, array.byteLength))

  return array
}

if (typeof global.crypto !== 'object') {
  global.crypto = {}
}

if (typeof global.crypto.getRandomValues !== 'function') {
  global.crypto.getRandomValues = getRandomValues
}
