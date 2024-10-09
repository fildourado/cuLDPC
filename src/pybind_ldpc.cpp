#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "code.h"
#include "encoder.h"
#include "decoder.h"

namespace py = pybind11;

void py_ldpc_make_code(int n_code, 
                  int d_v, 
                  int d_c, 
                  bool systematic,
                  bool sparse)
{
    make_ldpc(n_code, d_v, d_c, systematic, sparse);
}

void py_ldpc_encode(py::array_t<int> input_bits, py::array_t<int> output_bits, int N) 
{
    // Get pointers to input/output arrays
    py::buffer_info in_buf = input_bits.request();
    py::buffer_info out_buf = output_bits.request();

    int* in_ptr = static_cast<int*>(in_buf.ptr);
    int* out_ptr = static_cast<int*>(out_buf.ptr);

    // Call C++ LDPC encode function
    ldpc_encode(in_ptr, out_ptr, N);
}

void py_ldpc_decode(py::array_t<int> input_bits, py::array_t<int> output_bits, int N) {
    // Get pointers to input/output arrays
    py::buffer_info in_buf = input_bits.request();
    py::buffer_info out_buf = output_bits.request();

    int* in_ptr = static_cast<int*>(in_buf.ptr);
    int* out_ptr = static_cast<int*>(out_buf.ptr);

    // Call C++ LDPC decode function
    ldpc_decode(in_ptr, out_ptr, N);
}

PYBIND11_MODULE(ldpc_cuda_pybind, m) {
    m.doc() = "Python bindings for CUDA-based LDPC encoder and decoder";

    m.def("make_code", &py_ldpc_make_code, "Make LDPC coding and decoding matrices",
          py::arg("n_codes"), py::arg("d_v"), py::arg("d_c"),
          py::arg("systematic")=false, py::arg("sparse")=true);

    m.def("encode", &py_ldpc_encode, "Encode LDPC",
          py::arg("input_bits"), py::arg("output_bits"), py::arg("N"));

    m.def("decode", &py_ldpc_decode, "Decode LDPC",
          py::arg("input_bits"), py::arg("output_bits"), py::arg("N"));
}
