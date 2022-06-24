package org.linusu;

import android.util.Base64;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;

import java.security.NoSuchAlgorithmException;
import java.security.SecureRandom;

public class RNGetRandomValuesModule extends ReactContextBaseJavaModule {
  public static final String NAME = "RNGetRandomValues";

  public RNGetRandomValuesModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  @ReactMethod(isBlockingSynchronousMethod = true)
  @NonNull
  public String getRandomBase64(int byteLength) throws NoSuchAlgorithmException {
    byte[] data = new byte[byteLength];
    SecureRandom random = new SecureRandom();

    random.nextBytes(data);

    return Base64.encodeToString(data, Base64.NO_WRAP);
  }
}
