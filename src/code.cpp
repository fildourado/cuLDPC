#include "utils.h"
#include "code.h"

#include "spdlog/spdlog.h"


/**
 * @brief Build a regular parity-check matrix H following Callager's algorithm
 * 
 * @param n_code 
 * @param d_v 
 * @param d_c 
 * @return MAT 
 */
MAT parity_check_matrix(int n_code, int d_v, int d_c)
{
    
    THROW_IF(d_v <= 1, std::runtime_error, "d_v must be at least 2");
    THROW_IF(d_c <= d_v, std::runtime_error, "d_c must be greater than d_v");
    THROW_IF(n_code % d_c, std::runtime_error, "d_c must divide n for a regular LDPC matrix H");

    spdlog::info("test");
    
    int n_equations = (n_code * d_v) / d_c;
    
    int block_size = n_equations / d_v;
    MAT block = MAT::Zero(block_size, n_code);
    MAT H(n_equations, n_code);

    // Fill the first block with consecutive ones in each row of the block

    return MAT::Zero(2,2);
}

/**
 * @brief Returns the generating coding matrix G given the LDPC matrix H
 * 
 * @param H 
 * @param sparse 
 * @return MAT 
 */
MAT coding_matrix(MAT H, bool sparse)
{
    return MAT::Zero(2,2);
}

/**
 * @brief Compute the coding matrix G in systematic format with an identity block
 * 
 * @param H parity-check matrix
 * @param sparse 
 * @return std::tuple<MAT, MAT> 
 */
std::tuple<MAT, MAT> coding_matrix_systematic(MAT H, bool sparse)
{
    return std::make_tuple(MAT::Zero(2,2), MAT::Zero(2,2));
}

/**
 * @brief Create LDPC coding and decoding matrices H and G
 * 
 * @param n_code Length of the codewords
 * @param d_v Number of partiy-check equations including a certain bit
 * @param d_c Number of bits in the same parity-check equation. 
 *  d_c Must be greater or equal to d_v and must divide n.
 * @param systematic if True, constructs a systematic coding matrix G.
 * @param sparse 
 * @return std::tuple<MAT, MAT> (H, G) 
 */
std::tuple<MAT, MAT> make_ldpc(int n_code, 
                               int d_v, 
                               int d_c, 
                               bool systematic, 
                               bool sparse)
{
    MAT H = parity_check_matrix(n_code, d_v, d_c);
    if (systematic)
    {
        return coding_matrix_systematic(H, sparse);
    }
    else
    {
        MAT G = coding_matrix(H, sparse);
        return std::make_tuple(H, G);
    }
}

