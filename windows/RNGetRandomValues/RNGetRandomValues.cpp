#include "pch.h"
#include "RNGetRandomValues.h"

namespace winrt::RNGetRandomValues::implementation
{
    std::string RNGetRandomValues::getRandomBase64(int byteLength)
    {
        winrt::Windows::Storage::Streams::IBuffer buffer = winrt::Windows::Security::Cryptography::CryptographicBuffer::GenerateRandom(byteLength);
        return winrt::to_string(winrt::Windows::Security::Cryptography::CryptographicBuffer::EncodeToBase64String(buffer));
    }
}
