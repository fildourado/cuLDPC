#ifndef LDPC_DECODER_H
#define LDPC_DECODER_H

void ldpc_decode(const int *received_bits, int *decoded_bits, int N);

#endif // LDPC_DECODER_H
