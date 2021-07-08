from ...doc import *

cudaRT_event = [
# 4.5. Event Management
  func_decl( [ "cudaEventCreate" ],
             [ parm_def('event', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaEventCreateWithFlags" ],
             [ parm_def('event', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaEventDestroy" ],
             [ parm_def('event', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaEventElapsedTime" ],
             [ parm_def('ms', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('start', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('end', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaEventQuery" ],
             [ parm_def('event', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaEventRecord" ],
             [ parm_def('event', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('stream', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaEventSynchronize" ],
             [ parm_def('event', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
]
