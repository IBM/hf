from ...doc import *

cudriverapi_context = [
# 5.8. Context Management
  func_decl( [ "cuCtxCreate_v2" ],
             [ parm_def('pctx', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ),
               parm_def('dev', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxDestroy_v2" ],
             [ parm_def('ctx', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxGetApiVersion" ],
             [ parm_def('ctx', PASSBYVALUE, INOUT_IN ),
               parm_def('version', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxGetCacheConfig" ],
             [ parm_def('pconfig', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxGetCurrent" ],
             [ parm_def('pctx', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxGetDevice" ],
             [ parm_def('device', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxGetFlags" ],
             [ parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxGetLimit" ],
             [ parm_def('pvalue', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('limit', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxGetSharedMemConfig" ],
             [ parm_def('pConfig', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxGetStreamPriorityRange" ],
             [ parm_def('leastPriority', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('greatestPriority', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxPopCurrent" ],
             [ parm_def('pctx', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuCtxPushCurrent" ],
             [ parm_def('ctx', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxSetCacheConfig" ],
             [ parm_def('config', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxSetCurrent" ],
             [ parm_def('ctx', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxSetLimit" ],
             [ parm_def('limit', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxSetSharedMemConfig" ],
             [ parm_def('config', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxSynchronize" ] ),


# 5.9. Context Management
  func_decl( [ "cuCtxAttach" ],
             [ parm_def('pctx', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuCtxDetach" ],
             [ parm_def('ctx', PASSBYVALUE, INOUT_IN ) ] ),

]
