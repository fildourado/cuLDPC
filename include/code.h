#ifndef LDPC_CODE_H
#define LDPC_CODE_H

std::tuple<MAT, MAT> make_ldpc(int n_code,
                               int d_v, 
                               int d_c, 
                               bool systematic,
                               bool sparse);

#endif