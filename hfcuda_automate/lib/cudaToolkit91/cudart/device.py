from ...doc import *

cudaRT_device = [
# 4.1. Device Management
  # there are more .. but most of them require hand-porting
  func_decl( [ "cudaDeviceGetAttribute" ],
             [ parm_def('value', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('attr', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('device', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaDeviceGetCacheConfig" ],
             [ parm_def('pCacheConfig', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaDeviceGetLimit" ],
             [ parm_def('pValue', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ),
               parm_def('limit', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaDeviceGetSharedMemConfig" ],
             [ parm_def('pConfig', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaDeviceGetStreamPriorityRange" ],
             [ parm_def('leastPriority', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('greatestPriority', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaDeviceReset" ] ),
  func_decl( [ "cudaDeviceSetCacheConfig" ],
             [ parm_def('cacheConfig', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaDeviceSetLimit" ],
             [ parm_def('limit', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('value', [MEMORY_HOST, SCALAR], INOUT_IN, { "typepatch" : "size_t" } ) ] ),
  func_decl( [ "cudaDeviceSetSharedMemConfig" ],
             [ parm_def('config', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaDeviceSynchronize" ] ),
  func_decl( [ "cudaGetDeviceFlags" ],
             [ parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaSetDeviceFlags" ],
             [ parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ), # potentially needs hand-written code  
]
