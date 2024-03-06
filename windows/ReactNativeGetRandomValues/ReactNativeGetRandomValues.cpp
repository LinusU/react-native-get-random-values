#include "pch.h"
#include "ReactNativeGetRandomValues.h"

namespace winrt::ReactNativeGetRandomValues
{
    std::string ReactNativeGetRandomValues::getRandomBase64(int byteLength) noexcept
    {
        winrt::Windows::Storage::Streams::IBuffer buffer = winrt::Windows::Security::Cryptography::CryptographicBuffer::GenerateRandom(byteLength);
        return winrt::to_string(winrt::Windows::Security::Cryptography::CryptographicBuffer::EncodeToBase64String(buffer));
    }
}
