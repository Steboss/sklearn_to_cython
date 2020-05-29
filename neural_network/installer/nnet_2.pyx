import scipy.io.wavfile
import matplotlib.pyplot  as plt
import sys
from libc.stdlib cimport malloc,free
from cpython cimport PyObject, Py_INCREF, array


# Numpy must be initialized. When using numpy from C or Cython you must
# _always_ do that, or you will have segfaults
np.import_array()
# Import the Python-level symbols of numpy
import numpy as np
# Import the C-level symbols of numpy
cimport numpy as np


cdef extern from "../c_code/base.h":
    double** identity(double** X, int n_samples, int n_features)
    double** logistic_sigmoid(double** X, int n_samples, int n_features)


cpdef play(a):
    r"""
    -------
    """
    cdef int i
    #return result for a

    #get signal size
    N,M = a.shape
    # Make sure the array a has the correct memory layout (here C-order)
    #alternatively we can pass a vector to the function, re build it at som epoijnt
    cdef double[:,:] a_cython= np.asarray(a,order="C")
    #Create our helper array
    #remember arning: nnet.pyx:36:38: Index should be typed for more efficient access
    #in this way the cycle with i is more efficient
    cdef double** point_to_a = <double **>malloc(N * sizeof(double*))
    if not point_to_a: raise MemoryError
    try:
        for i in range(N):
            point_to_a[i] = &a_cython[i, 0]
        #identity(&point_to_a[0], N, M)
        logistic_sigmoid(&point_to_a[0], N,M)

    finally:
        free(point_to_a)
