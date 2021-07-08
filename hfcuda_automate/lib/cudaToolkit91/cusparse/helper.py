from ...doc import *

# missing 5.11.  -- 5.16. GetPointerMode!!! and 5.22.

cuSPARSE_helper = [
# 5.1. cusparseCreate()
  func_decl( [ "cusparseCreate" ],
             [ parm_def('handle', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.2. cusparseCreateSolveAnalysisInfo()
  func_decl( [ "cusparseCreateSolveAnalysisInfo" ],
             [ parm_def('info', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.3. cusparseCreateHybMat()
  func_decl( [ "cusparseCreateHybMat" ],
             [ parm_def('hybA', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.4. cusparseCreateMatDescr()
  func_decl( [ "cusparseCreateMatDescr" ],
             [ parm_def('descrA', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.5 cusparseCreateSolveAnalysisInfo()
  func_decl( [ "cusparseCreateSolveAnalysisInfo" ],
             [ parm_def('info', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.6. cusparseDestroy()
  func_decl( [ "cusparseDestroy" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ) ] ),

# 5.7. cusparseDestroySolveAnalysisInfo()
  func_decl( [ "cusparseDestroySolveAnalysisInfo" ],
             [ parm_def('info', PASSBYVALUE, INOUT_IN ) ] ),

# 5.8. cusparseDestroyHybMat()
  func_decl( [ "cusparseDestroyHybMat" ],
             [ parm_def('hybA', PASSBYVALUE, INOUT_IN ) ] ),

# 5.9. cusparseDestroyMatDescr()
  func_decl( [ "cusparseDestroyMatDescr" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ) ] ),

# definition twice in spec ... 
## 5.10. cusparseDestroySolveAnalysisInfo()
#  func_decl( [ "cusparseDestroySolveAnalysisInfo" ],
#             [ parm_def('info', PASSBYVALUE, INOUT_IN ) ] ),

# .. ToDo: 5.11 really requires hand implementing ...

# 5.12. cusparseGetMatDiagType()
  func_decl( [ "cusparseGetMatDiagType" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ) ] ),

# 5.13. cusparseGetMatFillMode()
  func_decl( [ "cusparseGetMatFillMode" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ) ] ),

# 5.14. cusparseGetMatIndexBase()
  func_decl( [ "cusparseGetMatIndexBase" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ) ] ),

# 5.15. cusparseGetMatType()
  func_decl( [ "cusparseGetMatType" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ) ] ),

# ... getpointer!

# 5.17. cusparseGetVersion()
  func_decl( [ "cusparseGetVersion" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('version', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.18. cusparseSetMatDiagType()
  func_decl( [ "cusparseSetMatDiagType" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('diagType', PASSBYVALUE, INOUT_IN ) ] ),

# 5.19. cusparseSetMatFillMode()
  func_decl( [ "cusparseSetMatFillMode" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('fillMode', PASSBYVALUE, INOUT_IN ) ] ),

# 5.20. cusparseSetMatIndexBase()
  func_decl( [ "cusparseSetMatIndexBase" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('base', PASSBYVALUE, INOUT_IN ) ] ),

# 5.21. cusparseSetMatType()
  func_decl( [ "cusparseSetMatType" ],
             [ parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('type', PASSBYVALUE, INOUT_IN ) ] ),

# 5.22. cusparseSetPointerMode()   --- ToDo: hand-code!
  func_decl( [ "cusparseSetPointerMode" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ) ] ),

# 5.23. cusparseSetStream()
  func_decl( [ "cusparseSetStream" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('streamId', PASSBYVALUE, INOUT_IN ) ] ),

# 5.24. cusparseGetStream()
  func_decl( [ "cusparseGetStream" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('streamId', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.25. cusparseCreateCsrsv2Info()
# 5.27. cusparseCreateCsrsm2Info()
# 5.29. cusparseCreateCsric02Info()
# 5.31. cusparseCreateCsrilu02Info()
# 5.33. cusparseCreateBsrsv2Info()
# 5.35. cusparseCreateBsrsm2Info()
# 5.37. cusparseCreateBsric02Info()
# 5.39. cusparseCreateBsrilu02Info()
# 5.41. cusparseCreateCsrgemm2Info()
# 5.43. cusparseCreatePruneInfo()
  func_decl( [ "cusparseCreateCsrsv2Info", "cusparseCreateCsrsm2Info", "cusparseCreateCsric02Info", "cusparseCreateCsrilu02Info", "cusparseCreateBsrsv2Info", "cusparseCreateBsrsm2Info", "cusparseCreateBsric02Info", "cusparseCreateBsrilu02Info", "cusparseCreateCsrgemm2Info", "cusparseCreatePruneInfo" ],
             [ parm_def('info', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 5.26. cusparseDestroyCsrsv2Info()
# 5.28. cusparseDestroyCsrsm2Info()
# 5.30. cusparseDestroyCsric02Info()
# 5.32. cusparseDestroyCsrilu02Info()
# 5.34. cusparseDestroyBsrsv2Info()
# 5.36. cusparseDestroyBsrsm2Info()
# 5.38. cusparseDestroyBsric02Info()
# 5.40. cusparseDestroyBsrilu02Info()
# 5.42. cusparseDestroyCsrgemm2Info()
# 5.44. cusparseDestroyPruneInfo()
  func_decl( [ "cusparseDestroyCsrsv2Info", "cusparseDestroyCsrsm2Info", "cusparseDestroyCsric02Info", "cusparseDestroyCsrilu02Info", "cusparseDestroyBsrsv2Info", "cusparseDestroyBsrsm2Info", "cusparseDestroyBsric02Info", "cusparseDestroyBsrilu02Info", "cusparseDestroyCsrgemm2Info", "cusparseDestroyPruneInfo" ],
             [ parm_def('info', PASSBYVALUE, INOUT_IN ) ] ),

]
