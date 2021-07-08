from ...doc import *

# 5.4. Version Management
cudriverapi_version = [
  func_decl( [ "cuDriverGetVersion" ],
             [ parm_def('driverVersion', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),
]
