import pyldpc
import cuLDPC_pybind as cuLDPC

import pytest
import numpy as np

@pytest.mark.parametrize("n, d_v, d_c, systematic",
                         [[30, 2, 5, False], [20, 2, 4, False]])
def test_encode(n, d_v, d_c, systematic):
    H, G = pyldpc.make_ldpc(n, d_v, d_c, systematic=systematic)
    assert not pyldpc.binaryproduct(H, G).any()

    snr = np.inf
    n,k = G.shape
    v = np.random.randint(0, 2, size=k)     
    y_py = pyldpc.encode(G, v, snr)    
    y_cu = cuLDPC.encode(G, v, snr)

    np.testing.assert_equal([y_py], y_cu)
