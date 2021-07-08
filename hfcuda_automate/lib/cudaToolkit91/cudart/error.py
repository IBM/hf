from ...doc import *

cudaRT_error = [
# 4.3. Error Handling
  # cudaGetErrorName and cudaGetErrorString can be run locally.
  # there is no need to trap them.
  func_decl( [ "cudaGetLastError" ] ),
  func_decl( [ "cudaPeekAtLastError" ] ),
]
