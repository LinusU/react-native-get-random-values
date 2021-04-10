const { NativeModules } = require('react-native')

if (NativeModules.RNGetRandomValues) {
  module.exports = NativeModules.RNGetRandomValues.getRandomBase64;
} else if (NativeModules.ExpoRandom) {
  module.exports = NativeModules.ExpoRandom.getRandomBase64String
}