#include "pch.h"

#include "ReactNativeGetRandomValues.h"

#include <winrt/Windows.Security.Cryptography.h>

namespace winrt::ReactNativeGetRandomValues
{

std::string RNGetRandomValues::getRandomBase64(double byteLength) noexcept {
  auto buffer = Windows::Security::Cryptography::CryptographicBuffer::GenerateRandom(
      static_cast<uint32_t>(byteLength));

  return winrt::to_string(
      Windows::Security::Cryptography::CryptographicBuffer::EncodeToBase64String(buffer));
}

} // namespace winrt::ReactNativeGetRandomValues