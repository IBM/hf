from ...doc import *

cuSPARSE_level1 = [
# 6.1. cusparse<t>axpyi()
  func_decl( [ "cusparseSaxpyi", "cusparseDaxpyi", "cusparseCaxpyi", "cusparseZaxpyi" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('xVal', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('xInd', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR ], INOUT_INOUT ),
               parm_def('idxBase', PASSBYVALUE, INOUT_IN ) ] ),

# 6.2. cusparse<t>doti()
# 6.3. cusparse<t>dotci()
  func_decl( [ "cusparseSdoti", "cusparseDdoti", "cusparseCdoti", "cusparseZdoti", "cusparseCdotci", "cusparseZdotci" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('xVal', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('xInd', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('resultDevHostPtr', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_OUT ),
               parm_def('idxBase', PASSBYVALUE, INOUT_IN ) ] ),

# 6.4. cusparse<t>gthr()
# 6.5. cusparse<t>gthrz()
  func_decl( [ "cusparseSgthr", "cusparseDgthr", "cusparseCgthr", "cusparseZgthr", "cusparseSgthrz", "cusparseDgthrz", "cusparseCgthrz", "cusparseZgthrz" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('xVal', [ MEMORY_DEVICE, VECTOR ], INOUT_OUT ),
               parm_def('xInd', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('idxBase', PASSBYVALUE, INOUT_IN ) ] ),

# 6.6. cusparse<t>roti()
  func_decl( [ "cusparseSroti", "cusparseDroti" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('xVal', [ MEMORY_DEVICE, VECTOR ], INOUT_OUT ),
               parm_def('xInd', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR ], INOUT_OUT ),
               parm_def('c', [ MEMORY_DEVICE, SCALAR ], INOUT_IN ),
               parm_def('s', [ MEMORY_DEVICE, SCALAR ], INOUT_IN ),
               parm_def('idxBase', PASSBYVALUE, INOUT_IN ) ] ),

# 6.7. cusparse<t>sctr()
  func_decl( [ "cusparseSsctr", "cusparseDsctr", "cusparseCsctr", "cusparseZsctr" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('xVal', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('xInd', [ MEMORY_DEVICE, VECTOR ], INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR ], INOUT_OUT ),
               parm_def('idxBase', PASSBYVALUE, INOUT_IN ) ] ),
]
