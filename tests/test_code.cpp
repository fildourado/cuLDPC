#include "code.h"
#include <gtest/gtest.h>

TEST(LDPC_Code, SimpleCodeTest) 
{
    //make_ldpc(30, 2, 5, false, false);
    make_ldpc(10, 3, 5, true, false);
}