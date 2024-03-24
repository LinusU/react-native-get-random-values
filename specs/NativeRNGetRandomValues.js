/**
 * @flow strict-local
 * @format
 */

import type { TurboModule } from 'react-native/Libraries/TurboModule/RCTExport';
import type { Int32 } from 'react-native/Libraries/Types/CodegenTypes';
import { TurboModuleRegistry } from 'react-native';

export interface Spec extends TurboModule {
  +getRandomBase64: (byteLength: Int32) => string;
}

export default (TurboModuleRegistry.get<Spec>(
  "RNGetRandomValues"
): Spec);
