#include "pch.h"
#include "RNGetRandomValuesModule.h"

namespace winrt::RNGetRandomValues
{
    std::string RNGetRandomValuesModule::GetRandomBase64(uint32_t byteLength) noexcept
    {
        return winrt::to_string(CryptographicBuffer::EncodeToBase64String(CryptographicBuffer::GenerateRandom(byteLength)));
    }
}
