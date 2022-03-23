#pragma once
#include "pch.h"
#include "NativeModules.h"

namespace winrt::ReactNativeGetRandomValues
{
    REACT_MODULE(ReactNativeGetRandomValues, L"RNGetRandomValues");
    struct ReactNativeGetRandomValues
    {
        REACT_METHOD(getRandomBase64)
        std::string getRandomBase64(int byteLength) noexcept;
    };
}
