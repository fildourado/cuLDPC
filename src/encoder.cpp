#include "utils.h"
#include "encoder.h"

/**
 * @brief  Encodes a binary message and adds Gaussian noise using Eigen, not cuda
 * 
 * @param p_tG Transposed coding matrix (n, k)
 * @param p_v (k, n_messages) binary messages to be encoded
 * @param snr Signal-to-Noise ration. SNR = 10*log10(1/variance) in dB
 * @return MAT (n, n_messages) coded messages + noise
 */
MATf ldpc_encode(MAT *p_tG, MAT *p_v, float snr) 
{
    MAT d = *p_tG * *p_v;   
    MATf x = d.unaryExpr([](const int x) { return std::pow((float)-1, (float)(x%2)); });
    float sigma = std::pow(10, -snr/20.0);
    MATf e = randn<float>(x.rows(), x.cols(), 0.0, sigma);
    return (x + e).transpose();
}