from ...doc import *

cudriverapi_stream = [
# 5.13. Stream management
  # cuStreamAddCallback (missing)

  func_decl( [ "cuStreamAttachMemAsync" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('dptr', PASSBYVALUE, INOUT_IN ),
               parm_def('length', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamBeginCapture" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamCreate" ],
             [ parm_def('phStream', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('Flags', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamCreateWithPriority" ],
             [ parm_def('phStream', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ),
               parm_def('priority', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamDestroy_v2" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamEndCapture" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('phGraph', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuStreamGetCtx" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('pctx', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuStreamGetFlags" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuStreamGetPriority" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('priority', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuStreamIsCapturing" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('captureStatus', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuStreamQuery" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamSynchronize" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamWaitEvent" ],
             [ parm_def('hStream', PASSBYVALUE, INOUT_IN ),
               parm_def('hEvent', PASSBYVALUE, INOUT_IN ),
               parm_def('Flags', PASSBYVALUE, INOUT_IN ) ] ),



# 5.16. Stream memory operations
  # cuStreamBatchMemOp (missing)

  func_decl( [ "cuStreamWaitValue32" ],
             [ parm_def('stream', PASSBYVALUE, INOUT_IN ),
               parm_def('addr', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamWaitValue64" ],
             [ parm_def('stream', PASSBYVALUE, INOUT_IN ),
               parm_def('addr', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamWriteValue32" ],
             [ parm_def('stream', PASSBYVALUE, INOUT_IN ),
               parm_def('addr', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuStreamWriteValue64" ],
             [ parm_def('stream', PASSBYVALUE, INOUT_IN ),
               parm_def('addr', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] ),

]
