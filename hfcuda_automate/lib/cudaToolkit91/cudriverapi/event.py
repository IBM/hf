from ...doc import *

# 5.14. Event Management
cudriverapi_event = [
  func_decl( [ "cuEventCreate" ],
             [ parm_def('phEvent', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('Flags', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),

  func_decl( [ "cuEventDestroy_v2" ],
             [ parm_def('hEvent', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),

  func_decl( [ "cuEventElapsedTime" ],
             [ parm_def('pMilliseconds', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('hStart', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('hEnd', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),

  func_decl( [ "cuEventQuery" ],
             [ parm_def('hEvent', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),

  func_decl( [ "cuEventRecord" ],
             [ parm_def('hEvent', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('hStream', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),

  func_decl( [ "cuEventSynchronize" ],
             [ parm_def('hEvent', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
]
