from ...doc import *

cudaRT_memory = [
# 4.9. Memory Management
  # there are more .. but most of them require hand-porting
  func_decl( [ "cudaMemset" ],
             [ parm_def('devPtr', [MEMORY_DEVICE, VECTOR, 'count'], INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('count', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),
  func_decl( [ "cudaMemset2D" ],
             [ parm_def('devPtr', [MEMORY_DEVICE, VECTOR, '#ToDo'], INOUT_IN ),
               parm_def('pitch', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('width', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('height', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),
  func_decl( [ "cudaMemset3D" ],
             [ parm_def('pitchedDevPtr', [MEMORY_DEVICE, VECTOR, 'ToDo'], INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ),
               parm_def('extent', PASSBYVALUE, INOUT_IN ) ] ),
]
