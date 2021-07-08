from ...doc import *

# 5.6. Device Management
cudriverapi_device = [
  func_decl( [ "cuDeviceComputeCapability" ],
             [ parm_def('major', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('minor', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('dev', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuDeviceGetProperties" ],
             [ parm_def('prop', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('dev', PASSBYVALUE, INOUT_IN ) ] ),
]
