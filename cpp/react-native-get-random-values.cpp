#include "react-native-get-random-values.h"
#include "base64.h"
#include <jsi/jsi.h>
#include <vector>
#include <stdlib.h>

using namespace facebook::jsi;
using namespace std;

namespace reactnativegetrandomvalues
{
  void install(Runtime &jsiRuntime)
  {
    auto getRandomBase64 = Function::createFromHostFunction(jsiRuntime,
                                                            PropNameID::forAscii(jsiRuntime,
                                                                                 "getRandomBase64"),
                                                            0,
                                                            [](Runtime &runtime,
                                                               const Value &thisValue,
                                                               const Value *arguments,
                                                               size_t count) -> Value
                                                            {
                                                              int byteLength = arguments[0].getNumber();
                                                              vector<uint8_t> buffer(byteLength, 0);
                                                              arc4random_buf(&buffer[0],
                                                                             buffer.size());

                                                              string encodedData = base64_encode(&buffer[0],
                                                                                                 buffer.size());

                                                              return Value(runtime,
                                                                           String::createFromUtf8(runtime,
                                                                                                  encodedData));
                                                            });

    Object RNGetRandomValues = Object(jsiRuntime);
    RNGetRandomValues.setProperty(jsiRuntime, "getRandomBase64", move(getRandomBase64));
    jsiRuntime.global().setProperty(jsiRuntime, "RNGetRandomValues", move(RNGetRandomValues));
  }
}
