import os 

from cudart.device import *
from cudart.error import *
from cudart.thread import *
from cudart.stream import *
from cudart.event import *
from cudart.execution import *
from cudart.memory import *
from cudart.version import *

from cublas.helper import *
from cublas.level1 import *
from cublas.level2 import *
from cublas.level3 import *
from cublas.extension import *

from cusparse.helper import *
from cusparse.level1 import *
from cusparse.level2 import *
from cusparse.level3 import *
from cusparse.extra import *
from cusparse.reordering import *
from cusparse.format import *

from cuDNN.api import *

from cudriverapi.version import *
from cudriverapi.device import *
from cudriverapi.primary_context import *
from cudriverapi.context import *
from cudriverapi.stream import *
from cudriverapi.event import *
from cudriverapi.execution import *


cudaRT_API = cudaRT_device + cudaRT_error + cudaRT_thread + cudaRT_stream + cudaRT_event + cudaRT_memory + cudaRT_version + cudaRT_execution

# cublasGetPointerMode() / cublasSetPointerMode()
# This function sets the pointer mode used by the cuBLAS library. The default is for the values to be passed by reference on the host.

# 2.1.5. A.5. Scalar Parameters
# There are two categories of the functions that use scalar parameters :
#  functions that take alpha and/or beta parameters by reference on the host or the device as scaling factors, such as gemm
#  functions that return a scalar result on the host or the device such as amax(), amin, asum(), rotg(), rotmg(), dot() and nrm2().
#For the functions of the first category, when the pointer mode is set to CUBLAS_POINTER_MODE_HOST, the scalar parameters alpha and/or beta can be on the stack or allocated on the heap. Underneath the CUDA kernels related to that functions will be launched with the value of alpha and/or beta. Therefore if they were allocated on the heap, they can be freed just after the return of the call even though the kernel launch is asynchronous. When the pointer mode is set to CUBLAS_POINTER_MODE_DEVICE, alpha and/or beta must be accessible on the device and their values should not be modified until the kernel is done. Note that since cudaFree() does an implicit cudaDeviceSynchronize(), cudaFree() can still be called on alpha and/or beta just after the call but it would defeat the purpose of using this pointer mode in that case.
#For the functions of the second category, when the pointer mode is set to CUBLAS_POINTER_MODE_HOST, these functions blocks the CPU, until the GPU has completed its computation and the results has been copied back to the Host. When the pointer mode is set to CUBLAS_POINTER_MODE_DEVICE, these functions return immediately. In this case, similarly to matrix and vector results, the scalar result is ready only when execution of the routine on the GPU has completed. This requires proper synchronization in order to read the result from the host.
#In either case, the pointer mode CUBLAS_POINTER_MODE_DEVICE allows the library functions to execute completely asynchronously from the Host even when alpha and/or beta are generated by a previous kernel. For example, this situation can arise when iterative methods for solution of linear systems and eigenvalue problems are implemented using the cuBLAS library.

cuBLAS_API = cuBLAS_helper + cuBLAS_level_1 + cuBLAS_level_2 + cuBLAS_level_3 + cuBLAS_extension

# CHAPTER 1 Introduction
# The cuSPARSE API assumes that input and output data reside in GPU
# (device) memory, unless it is explicitly indicated otherwise by the string DevHostPtr in
# a function parameter's name (for example, the parameter *resultDevHostPtr in the function cusparse<t>doti()).
cuSPARSE_API = cuSPARSE_helper + cuSPARSE_level1 + cuSPARSE_level2 + cuSPARSE_level3 + cuSPARSE_extra + cuSPARSE_reordering + cuSPARSE_format

cuDNN_API = cuDNN_api

cuDRIVER_API = cudriverapi_version + cudriverapi_device + cudriverapi_primary_context + cudriverapi_context + cudriverapi_event + cudriverapi_stream + cudriverapi_execution

def dmerge(x, y):
    z = x.copy()
    z.update(y)
    return z

def get_defs( cuda_root ):
  cudaRT_header = os.path.join(cuda_root, "include/cuda_runtime_api.h")
  cudaRT_defs = gen_func_decl(cudaRT_header, cudaRT_API)

  cuBLAS_header = os.path.join(cuda_root, "include/cublas_v2.h")
  cuBLAS_defs = gen_func_decl(cuBLAS_header, cuBLAS_API)

  cuSPARSE_header = os.path.join(cuda_root, "include/cusparse_v2.h")
  cuSPARSE_defs = gen_func_decl(cuSPARSE_header, cuSPARSE_API)

  cuDNN_header = os.path.join(cuda_root, "include/cudnn.h")
  cuDNN_defs = gen_func_decl(cuDNN_header, cuDNN_API)

  cuDRIVERAPI_header = os.path.join(cuda_root, "include/cuda.h")
  cuDRIVERAPI_defs = gen_func_decl(cuDRIVERAPI_header, cuDRIVER_API)

  return dmerge(cuDRIVERAPI_defs, dmerge(cudaRT_defs, dmerge(cuBLAS_defs, dmerge(cuSPARSE_defs, cuDNN_defs))))