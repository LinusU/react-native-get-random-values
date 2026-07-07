#pragma once

#include "pch.h"
#include "resource.h"

#include "codegen/NativeRNGetRandomValuesSpec.g.h"

#include "NativeModules.h"

namespace winrt::ReactNativeGetRandomValues
{

REACT_MODULE(RNGetRandomValues)
struct RNGetRandomValues
{
  using ModuleSpec = ReactNativeGetRandomValuesCodegen::RNGetRandomValuesSpec;

  REACT_SYNC_METHOD(getRandomBase64)
  std::string getRandomBase64(double byteLength) noexcept;
};

} // namespace winrt::ReactNativeGetRandomValues