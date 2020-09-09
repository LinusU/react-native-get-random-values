// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once
#include "pch.h"
#include "NativeModules.h"

namespace winrt::RNGetRandomValues::implementation
{
    REACT_MODULE(RNGetRandomValues, L"RNGetRandomValues");
    struct RNGetRandomValues
    {
    public:
        hstring getRandomBase64(int byteLength);
    };
}