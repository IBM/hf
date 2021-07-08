from ...doc import *

# missing: 2.4.9 - 2.4.16
# missing: 2.4.21 - 2.4.23

cuBLAS_helper = [
# 2.4.1. cublasCreate()
  func_decl( "cublasCreate_v2",
             [ parm_def('handle', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 2.4.2. cublasDestroy()
  func_decl( "cublasDestroy_v2",
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ) ] ),

# 2.4.3. cublasGetVersion()
  func_decl( "cublasGetVersion_v2",
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('version', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 2.4.4. cublasGetProperty()
  func_decl( "cublasGetProperty",
             [ parm_def('type', PASSBYVALUE, INOUT_IN ),
               parm_def('value', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 2.4.5. cublasSetStream()
  func_decl( "cublasSetStream_v2",
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('streamId', PASSBYVALUE, INOUT_IN ) ] ),

# 2.4.6. cublasGetStream()
  func_decl( "cublasGetStream_v2",
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('streamId', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


## 2.4.7. cublasGetPointerMode()
#  func_decl( "cublasGetPointerMode_v2",
#             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
#               parm_def('mode', [ MEMORY_HOST, SCALAR ], INOUT_OUT ) ] ),

# This function sets the pointer mode used by the cuBLAS library. The default is for the values to be passed by reference on the host.
## 2.4.8. cublasSetPointerMode()
#  func_decl( "cublasSetPointerMode_v2",
#             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
#               parm_def('mode', PASSBYVALUE, INOUT_IN ) ] ),

# ... most of these aspects are more or less memcpy

# 2.4.17. cublasSetAtomicsMode(), 2.4.19. cublasSetMathMode()
  func_decl( [ "cublasSetAtomicsMode", "cublasSetMathMode" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ) ] ),

# 2.4.18. cublasGetAtomicsMode(), 2.4.20. cublasGetMathMode()
  func_decl( [ "cublasGetAtomicsMode", "cublasGetMathMode" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] )

# ... these functions handle the callback user function -> in my eyes not at all handable with either rCUDA/hfCUDA

]
