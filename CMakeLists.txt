cmake_minimum_required(VERSION 3.12)
project(cuLDPC)

set(CULDPC_LIB_NAME "cuLDPC")

#enable_language(CUDA)
find_package(CUDA REQUIRED)
set(CUDA_ARCHITECTURES "60")

#find_package(python3)
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

find_package(spdlog REQUIRED)


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

cuda_add_library(${CULDPC_LIB_NAME} STATIC ${SRC_FILES})

# Link CUDA runtime library to the static library
target_link_libraries(${CULDPC_LIB_NAME} ${CUDA_LIBRARIES})

add_subdirectory(tests)

# --- Python Bindings ---

# Find PyBind11
set(PYTHON_PATH "~/venv/")
set(pybind11_DIR ${PYTHON_PATH}/lib/python3.12/site-packages/pybind11/share/cmake/pybind11)

find_package(pybind11 REQUIRED)

# Python bindings source file
set(PYBIND_SRC src/pybind_ldpc.cpp)

# Create a shared library for the Python module
pybind11_add_module(${CULDPC_LIB_NAME}_pybind MODULE ${PYBIND_SRC})

# Link the Python module to the static LDPC library and CUDA
target_link_libraries(${CULDPC_LIB_NAME}_pybind PRIVATE ${CULDPC_LIB_NAME} ${CUDA_LIBRARIES})

#install(TARGETS ldpc_cuda_pybind DESTINATION .)
install(TARGETS ${CULDPC_LIB_NAME}_pybind LIBRARY DESTINATION ${PYTHON_PATH}/lib/python3.12/site-packages/)