package org.linusu;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

public class RNGetRandomValuesModule extends ReactContextBaseJavaModule {
  private native void nativeInstall(long jsiPtr, String docDir);

  public RNGetRandomValuesModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public String getName() {
    return "RNGetRandomValues";
  }

  @ReactMethod(isBlockingSynchronousMethod = true)
  public boolean install() {
    try {
      System.loadLibrary("reactnativegetrandomvalues");

      ReactApplicationContext context = getReactApplicationContext();
      nativeInstall(
        context.getJavaScriptContextHolder().get(),
        context.getFilesDir().getAbsolutePath()
      );
      return true;
    } catch (Exception exception) {
      return false;
    }
  }
}
