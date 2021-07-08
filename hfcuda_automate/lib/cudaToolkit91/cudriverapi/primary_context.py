from ...doc import *

# 5.7. Primary Context Management
cudriverapi_primary_context = [
  func_decl( [ "cuDevicePrimaryCtxGetState" ],
             [ parm_def('dev', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('active', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

  func_decl( [ "cuDevicePrimaryCtxRelease" ],
             [ parm_def('dev', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuDevicePrimaryCtxReset" ],
             [ parm_def('dev', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuDevicePrimaryCtxRetain" ],
             [ parm_def('pctx', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('dev', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuDevicePrimaryCtxSetFlags" ],
             [ parm_def('dev', PASSBYVALUE, INOUT_IN ),
               parm_def('flags', PASSBYVALUE, INOUT_IN ) ] )
]
