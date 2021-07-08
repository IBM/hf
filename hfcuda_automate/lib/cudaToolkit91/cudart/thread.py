from ...doc import *

cudaRT_thread = [
# 4.2. Thread Management [DEPRECATED]
  func_decl( [ "cudaThreadExit" ] ),
  func_decl( [ "cudaThreadGetCacheConfig" ],
             [ parm_def('pCacheConfig', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaThreadGetLimit" ],
             [ parm_def('pValue', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" }  ),
               parm_def('limit', PASSBYVALUE, INOUT_IN ) ] ),
  func_decl( [ "cudaThreadSetCacheConfig" ],
             [ parm_def('cacheConfig', PASSBYVALUE, INOUT_IN ) ] ),
  func_decl( [ "cudaThreadSetLimit" ],
             [ parm_def('limit', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),
  func_decl( [ "cudaThreadSynchronize" ] ),
]
