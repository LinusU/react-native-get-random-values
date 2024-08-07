#pragma once

#include "JSValue.h"
#include "NativeModules.h"
#include <winrt/Windows.Security.Cryptography.h>
#include <winrt/Windows.Storage.Streams.h>

using namespace winrt::Microsoft::ReactNative;
using namespace winrt::Windows::Security::Cryptography;
using namespace winrt::Windows::Storage::Streams;


namespace winrt::ReactNativeGetRandomValues
{

REACT_MODULE(ReactNativeGetRandomValues)
struct ReactNativeGetRandomValues
{
    // See https://microsoft.github.io/react-native-windows/docs/native-modules for details on writing native modules

    REACT_INIT(Initialize)
    void Initialize(ReactContext const &reactContext) noexcept
    {
        m_reactContext = reactContext;
    }
    
    REACT_METHOD(GetRandomBase64, L"getRandomBase64")
    std::string GetRandomBase64(int byteLength) noexcept
    {
        // Generate random bytes
        IBuffer buffer = CryptographicBuffer::GenerateRandom(byteLength);

        // Encode the random bytes to a base64 string
        hstring base64String = CryptographicBuffer::EncodeToBase64String(buffer);

        // Convert hstring to std::string
        std::string base64Result = winrt::to_string(base64String);

        return base64Result;
    }

    private:
        ReactContext m_reactContext{nullptr};
};

} // namespace winrt::ReactNativeGetRandomValues
