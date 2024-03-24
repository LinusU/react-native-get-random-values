package org.linusu;

import com.facebook.proguard.annotations.DoNotStrip;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.turbomodule.core.interfaces.TurboModule;
import javax.annotation.Nonnull;

public abstract class NativeRNGetRandomValuesSpec extends ReactContextBaseJavaModule implements TurboModule {
  public static final String NAME = "RNGetRandomValues";

  public NativeRNGetRandomValuesSpec(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public @Nonnull String getName() {
    return NAME;
  }

  @ReactMethod(isBlockingSynchronousMethod = true)
  @DoNotStrip
  public abstract String getRandomBase64(double byteLength);
}
