# Setup

sudo apt install cmake
sudo apt-get install libgtest-dev



# Set compilation flags
set(CMAKE_CXX_STANDARD 11)
set(CUDA_NVCC_FLAGS "${CUDA_NVCC_FLAGS} -O3 -arch=sm_${CUDA_ARCHITECTURES}")

# Add GoogleTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the test executable
add_executable(test_encode tests/test_encoder.cpp)
add_executable(test_decode tests/test_decoder.cpp)

# Link the tests with GoogleTest and CUDA
target_link_libraries(
    test_encode 
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    ${CUDA_LIBRARIES})

target_link_libraries(
    test_decode
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    ${CUDA_LIBRARIES})
    
cuda_add_cublas_to_target(test_encode)
cuda_add_cublas_to_target(test_decode)

# Enable unit testing with CTest
add_test(NAME test_encode COMMAND test_encode)
add_test(NAME test_decode COMMAND test_decode)
