cmake_minimum_required(VERSION 3.12)
project(LDPC_CUDA)

# Enable CUDA support
find_package(CUDA REQUIRED)

# Set the CUDA architecture (modify according to your GPU)
set(CUDA_ARCHITECTURES "60")

# Include directories for headers
include_directories(include)

# Set the source files for the project
set(SRC_FILES
    src/encoder.cu
    src/decoder.cu
)

cuda_add_library(ldpc_cuda_lib STATIC ${SRC_FILES})

# Link CUDA runtime library to the static library
target_link_libraries(ldpc_cuda_lib ${CUDA_LIBRARIES})

add_subdirectory(tests)