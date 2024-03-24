package org.linusu;

import android.util.Base64;

import com.facebook.react.bridge.ReactApplicationContext;

import java.security.SecureRandom;

public class RNGetRandomValuesModule extends NativeRNGetRandomValuesSpec {
  public RNGetRandomValuesModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  public String getRandomBase64(double byteLength) {
    byte[] data = new byte[(int)byteLength];
    SecureRandom random = new SecureRandom();

    random.nextBytes(data);

    return Base64.encodeToString(data, Base64.NO_WRAP);
  }
}
