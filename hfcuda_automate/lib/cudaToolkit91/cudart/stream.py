from ...doc import *

cudaRT_stream = [
# 4.4. Stream Management
  # cudaStreamAddCallback, cudaStreamAttachMemAsync ... well hand code!
  func_decl( [ "cudaStreamCreate" ],
             [ parm_def('pStream', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaStreamCreateWithFlags" ],
             [ parm_def('pStream', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaStreamCreateWithPriority" ],
             [ parm_def('pStream', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('priority', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaStreamDestroy" ],
             [ parm_def('stream', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaStreamGetFlags" ],
             [ parm_def('hStream', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaStreamGetPriority" ],
             [ parm_def('hStream', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('priority', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
  func_decl( [ "cudaStreamQuery" ],
             [ parm_def('stream', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaStreamSynchronize" ],
             [ parm_def('stream', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
  func_decl( [ "cudaStreamWaitEvent" ],
             [ parm_def('stream', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('event', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),
]
