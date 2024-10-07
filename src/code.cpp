#include <Eigen/Dense>

#include "utils.h"
#include "code.h"


MAT parity_check_matrix(int n_code, int d_v, int d_c)
{
    int n_equations = (n_code * d_v) / d_c;

    return MAT(2,2);
}

void coding_matrix()
{

}

void make_ldpc(int n_code, 
               int d_v, 
               int d_c, 
               bool systematic, 
               bool sparse)
{
    MAT H = parity_check_matrix(n_code, d_v, d_c);
}

