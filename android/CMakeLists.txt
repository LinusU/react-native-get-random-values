cmake_minimum_required(VERSION 3.9.0)

add_library(
  reactnativegetrandomvalues
  SHARED
  ../../react-native/ReactCommon/jsi/jsi/jsi.cpp
  ../cpp/react-native-get-random-values.cpp
  ../cpp/base64.cpp
  ./cpp-adapter.cpp
)

include_directories(
  ../../react-native/React
  ../../react-native/React/Base
  ../../react-native/ReactCommon/jsi
  ../cpp
)

set_target_properties(
  reactnativegetrandomvalues PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(
  reactnativegetrandomvalues
  android
)
