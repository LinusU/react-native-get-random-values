#pragma once
#include "pch.h"
#include "NativeModules.h"

namespace winrt::RNGetRandomValues::implementation
{
    REACT_MODULE(RNGetRandomValues, L"RNGetRandomValues");
    struct RNGetRandomValues
    {
        REACT_METHOD(getRandomBase64)
        hstring getRandomBase64(int byteLength);
    };
}
