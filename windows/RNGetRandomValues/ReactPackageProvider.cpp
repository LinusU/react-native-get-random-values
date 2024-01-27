#include "pch.h"
#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif

#include "RNGetRandomValuesModule.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::RNGetRandomValues::implementation
{
    void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
    {
        AddAttributedModules(packageBuilder, false);
    }
}