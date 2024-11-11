#pragma once

#include <iostream>

#include <Eigen/Dense>

#define MAT Eigen::MatrixXi

#define THROW_IF(condition, exceptionType, message) \
    do { \
        if (condition) { \
            throw exceptionType(message); \
        } \
    } while(0)

static void print_mat(std::string desc, MAT m)
{
    std::cout << desc << "\n" << m << std::endl;
}

template <typename T>
MAT gaussJordan(MAT mat)
{
    int rows = mat.rows();
    int cols = mat.cols();
    
    for (int col = 0; col < rows; ++col) {
        // Step 1: Pivoting (make sure diagonal element is non-zero)
        if (mat(col, col) == 0) {
            // Find a row below to swap with
            for (int row = col + 1; row < rows; ++row) {
                if (mat(row, col) != 0) {
                    mat.row(col).swap(mat.row(row));
                    break;
                }
            }
        }

        // Step 2: Normalize the pivot row
        T pivot = mat(col, col);
        if (pivot != 0) {
            mat.row(col) /= pivot;
        }

        // Step 3: Eliminate other entries in the current column
        for (int row = 0; row < rows; ++row) {
            if (row != col) {
                T factor = mat(row, col);
                mat.row(row) -= factor * mat.row(col);
            }
        }
    }

    return mat;
}