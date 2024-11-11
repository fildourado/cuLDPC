enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_code test_code.cpp)
add_executable(test_encode test_encoder.cpp)
add_executable(test_decode test_decoder.cpp)

target_link_libraries(
    test_code
    ${CULDPC_LIB_NAME}
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    ${CUDA_LIBRARIES})

target_link_libraries(
    test_encode
    ${CULDPC_LIB_NAME}
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    ${CUDA_LIBRARIES})

target_link_libraries(
    test_decode
    ${CULDPC_LIB_NAME}
    ${GTEST_LIBRARIES} 
    ${GTEST_MAIN_LIBRARIES} 
    ${CUDA_LIBRARIES})

#cuda_add_cublas_to_target(test_encode)
#cuda_add_cublas_to_target(test_decode)

add_test(NAME test_code COMMAND test_code)
add_test(NAME test_encode COMMAND test_encode)
add_test(NAME test_decode COMMAND test_decode)