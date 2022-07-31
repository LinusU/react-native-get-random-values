#include <jni.h>
#include "react-native-get-random-values.h"

extern "C" JNIEXPORT void JNICALL
Java_org_linusu_RNGetRandomValuesModule_nativeInstall(JNIEnv *env, jobject thiz, jlong jsi)
{
  auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi);

  if (runtime)
  {
    reactnativegetrandomvalues::install(*runtime);
  }
}
