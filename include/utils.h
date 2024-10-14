#ifndef LDPC_UTILS_H
#define LDPC_UTILS_H

#include <Eigen/Dense>

#define MAT Eigen::MatrixXi

#define THROW_IF(condition, exceptionType, message) \
    do { \
        if (condition) { \
            throw exceptionType(message); \
        } \
    } while(0)

#endif