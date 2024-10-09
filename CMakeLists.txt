cmake_minimum_required(VERSION 3.12)
project(LDPC_CUDA)

find_package(CUDA REQUIRED)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

# Set the CUDA architecture (modify according to your GPU)
set(CUDA_ARCHITECTURES "60")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fpic")

# Include directories for headers
include_directories(include)

# Set the source files for the project
set(SRC_FILES
    src/code.cpp
    src/encoder.cu
    src/decoder.cu
)

cuda_add_library(ldpc_cuda_lib STATIC ${SRC_FILES})

# Link CUDA runtime library to the static library
target_link_libraries(ldpc_cuda_lib ${CUDA_LIBRARIES})

add_subdirectory(tests)

# --- Python Bindings ---

# Find PyBind11
set(pybind11_DIR ~/miniconda3/envs/cuLDPC/lib/python3.12/site-packages/pybind11/share/cmake/pybind11)
find_package(pybind11 REQUIRED)

# Python bindings source file
set(PYBIND_SRC src/pybind_ldpc.cpp)

# Create a shared library for the Python module
pybind11_add_module(ldpc_cuda_pybind MODULE ${PYBIND_SRC})

# Link the Python module to the static LDPC library and CUDA
target_link_libraries(ldpc_cuda_pybind PRIVATE ldpc_cuda_lib ${CUDA_LIBRARIES})

#install(TARGETS ldpc_cuda_pybind DESTINATION .)
install(TARGETS ldpc_cuda_pybind LIBRARY DESTINATION ~/miniconda3/envs/cuLDPC/lib/python3.12/site-packages/)