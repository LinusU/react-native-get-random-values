#pragma once
#include "pch.h"
#include "NativeModules.h"

namespace winrt::RNGetRandomValues::implementation
{
    REACT_MODULE(RNGetRandomValues, L"RNGetRandomValues");
    struct RNGetRandomValues
    {
        std::string getRandomBase64(int byteLength);
    };
}
