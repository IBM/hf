from ...doc import *

cudaRT_version = [
# 4.27. Version Management
  func_decl( [ "cudaDriverGetVersion" ],
             [ parm_def('driverVersion', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaRuntimeGetVersion" ],
             [ parm_def('runtimeVersion', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
]
