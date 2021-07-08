from ...doc import *

cudriverapi_execution = [
# 5.17. Execution Control
  func_decl( [ "cuFuncGetAttribute" ],
             [ parm_def('pi', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('attrib', PASSBYVALUE, INOUT_IN ),
               parm_def('hfunc', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuFuncSetAttribute" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('attrib', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuFuncSetCacheConfig", "cuFuncSetSharedMemConfig" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('config', PASSBYVALUE, INOUT_IN ) ] ),

  # missing: cuLaunchCooperativeKernel, cuLaunchCooperativeKernelMultiDevice, cuLaunchHostFunc, cuLaunchKernel

# 5.18. Execution Control
  func_decl( [ "cuFuncSetBlockShape" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', PASSBYVALUE, INOUT_IN ),
               parm_def('y', PASSBYVALUE, INOUT_IN ),
               parm_def('z', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuFuncSetSharedSize" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('bytes', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuLaunch" ],
             [ parm_def('f', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuLaunchGrid" ],
             [ parm_def('f', PASSBYVALUE, INOUT_IN ),
               parm_def('grid_width', PASSBYVALUE, INOUT_IN ),
               parm_def('grid_height', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuLaunchGridAsync" ],
             [ parm_def('f', PASSBYVALUE, INOUT_IN ),
               parm_def('grid_width', PASSBYVALUE, INOUT_IN ),
               parm_def('grid_height', PASSBYVALUE, INOUT_IN ),
               parm_def('hStream', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuParamSetSize" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('numbytes', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuParamSetTexRef" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('texunit', PASSBYVALUE, INOUT_IN ),
               parm_def('hTexRef', PASSBYVALUE, INOUT_IN ) ] ),

  func_decl( [ "cuParamSetf", "cuParamSeti" ],
             [ parm_def('hfunc', PASSBYVALUE, INOUT_IN ),
               parm_def('offset', PASSBYVALUE, INOUT_IN ),
               parm_def('value', PASSBYVALUE, INOUT_IN ) ] ),

  # missing: cuParamSetv

]
