
/*
 * This file is auto-generated from a NativeModule spec file in js.
 *
 * This is a C++ Spec class that should be used with MakeTurboModuleProvider to register native modules
 * in a way that also verifies at compile time that the native module matches the interface required
 * by the TurboModule JS spec.
 */
#pragma once
// clang-format off


#include <NativeModules.h>
#include <tuple>

namespace ReactNativeGetRandomValuesCodegen {

struct RNGetRandomValuesSpec : winrt::Microsoft::ReactNative::TurboModuleSpec {
  static constexpr auto methods = std::tuple{
      SyncMethod<std::string(double) noexcept>{0, L"getRandomBase64"},
  };

  template <class TModule>
  static constexpr void ValidateModule() noexcept {
    constexpr auto methodCheckResults = CheckMethods<TModule, RNGetRandomValuesSpec>();

    REACT_SHOW_METHOD_SPEC_ERRORS(
          0,
          "getRandomBase64",
          "    REACT_SYNC_METHOD(getRandomBase64) std::string getRandomBase64(double byteLength) noexcept { /* implementation */ }\n"
          "    REACT_SYNC_METHOD(getRandomBase64) static std::string getRandomBase64(double byteLength) noexcept { /* implementation */ }\n");
  }
};

} // namespace ReactNativeGetRandomValuesCodegen
