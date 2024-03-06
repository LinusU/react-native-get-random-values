#include "pch.h"
#include "ReactPackageProvider.h"
#if __has_include("ReactPackageProvider.g.cpp")
#include "ReactPackageProvider.g.cpp"
#endif
#include <ModuleRegistration.h>
#include "ReactNativeGetRandomValues.h"

using namespace winrt::Microsoft::ReactNative;

namespace winrt::ReactNativeGetRandomValues::implementation
{

void ReactPackageProvider::CreatePackage(IReactPackageBuilder const &packageBuilder) noexcept
{
    AddAttributedModules(packageBuilder);
}

} // namespace winrt::ReactNativeGetRandomValues::implementation
