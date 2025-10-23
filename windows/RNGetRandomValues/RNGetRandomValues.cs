using System;
using Microsoft.ReactNative.Managed;
using Windows.Security.Cryptography;
using Windows.Storage.Streams;

namespace RNGetRandomValuesModule
{
    [ReactModule]
    class RNGetRandomValues
    {
        [ReactSyncMethod]
        public string getRandomBase64(int byteLength)
        {
            IBuffer buffer = CryptographicBuffer.GenerateRandom((uint)byteLength);
            return CryptographicBuffer.EncodeToBase64String(buffer);
        }
    }
}
