#pragma once

#include <tuple>
#include "utils.h"

std::tuple<MAT, MAT> make_ldpc(int n_code,
                               int d_v, 
                               int d_c, 
                               bool systematic,
                               bool sparse);

std::tuple<MAT,MAT> make_ldpc(MAT H, 
                              bool systematic, 
                              bool sparse);
