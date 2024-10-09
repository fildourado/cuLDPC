#ifndef LDPC_CODE_H
#define LDPC_CODE_H

void make_ldpc(int n_code, 
               int d_v, 
               int d_c, 
               bool systematic, 
               bool sparse,
               MAT &H,
               MAT &G);

#endif