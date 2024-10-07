#include "encoder.h"
#include <gtest/gtest.h>

TEST(LDPC_Encoder, SimpleEncodingTest) {
    const int N = 1024;
    int input_bits[N];
    int encoded_bits[N];

    // Fill input_bits with example data
    for (int i = 0; i < N; ++i) {
        input_bits[i] = i % 2;
    }

    // Perform LDPC encoding
    ldpc_encode(input_bits, encoded_bits, N);

    // Check if the encoding result is correct (this is a placeholder check)
    for (int i = 0; i < N; ++i) {
        EXPECT_EQ(encoded_bits[i], input_bits[i] ^ 1); // Example expectation
    }
}