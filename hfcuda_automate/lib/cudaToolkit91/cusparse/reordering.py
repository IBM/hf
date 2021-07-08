from ...doc import *

# https://devtalk.nvidia.com/default/topic/898135/gpu-accelerated-libraries/segfault-when-using-csrcolor-in-cusparse/

cuSPARSE_reordering = [
# 11.1. cusparse<t>csrcolor()
  func_decl( [ "cusparseScsrcolor", "cusparseDcsrcolor", "cusparseCcsrcolor", "cusparseZcsrcolor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('fractionToColor', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ncolors', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('coloring', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('reordering', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('info', PASSBYVALUE, INOUT_IN ) ] ),
]
