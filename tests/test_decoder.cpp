#include "decoder.h"
#include <gtest/gtest.h>

TEST(LDPC_Decoder, SimpleDecodingTest) {
    const int N = 1024;
    int encoded_bits[N];
    int decoded_bits[N];

    // Fill encoded_bits with example data
    for (int i = 0; i < N; ++i) {
        encoded_bits[i] = i % 2;
    }

    // Perform LDPC decoding
    ldpc_decode(encoded_bits, decoded_bits, N);

    // Check if the decoding result is correct (this is a placeholder check)
    for (int i = 0; i < N; ++i) {
        EXPECT_EQ(decoded_bits[i], encoded_bits[i]); // Example expectation
    }
}
