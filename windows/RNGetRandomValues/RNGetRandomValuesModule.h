#pragma once

#include "NativeModules.h"
#include "winrt/Windows.Security.Cryptography.h"

using winrt::Windows::Security::Cryptography::CryptographicBuffer;

namespace winrt::RNGetRandomValues
{
    REACT_MODULE(RNGetRandomValuesModule, L"RNGetRandomValues")
    struct RNGetRandomValuesModule
    {
        REACT_SYNC_METHOD(GetRandomBase64, L"getRandomBase64");
        std::string GetRandomBase64(uint32_t byteLength) noexcept;
    };
}
