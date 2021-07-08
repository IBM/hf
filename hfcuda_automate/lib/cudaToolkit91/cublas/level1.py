from ...doc import *

# missing: 2.5.9
# missing: 2.5.11

cuBLAS_level_1 = [
# 2.5.1. cublasI<t>amax()
# 2.5.2. cublasI<t>amin()
# 2.5.3. cublas<t>asum()
# 2.5.7. cublas<t>nrm2()
  func_decl( [ "cublasIsamax_v2", "cublasIdamax_v2", "cublasIcamax_v2", "cublasIzamax_v2", "cublasIsamin_v2", "cublasIdamin_v2", "cublasIcamin_v2", "cublasIzamin_v2", "cublasSasum_v2", "cublasDasum_v2", "cublasScasum_v2", "cublasDzasum_v2", "cublasSnrm2_v2", "cublasDnrm2_v2", "cublasScnrm2_v2", "cublasDznrm2_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_IN ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('result', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_OUT ) ] ),

# 2.5.4. cublas<t>axpy()
  func_decl( [ "cublasSaxpy_v2", "cublasDaxpy_v2", "cublasCaxpy_v2", "cublasZaxpy_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_IN ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR, 'n', 'incy' ], INOUT_INOUT ),
               parm_def('incy', PASSBYVALUE, INOUT_IN ) ] ),

# 2.5.5. cublas<t>copy()
  func_decl( [ "cublasScopy_v2", "cublasDcopy_v2", "cublasCcopy_v2", "cublasZcopy_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_IN ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR, 'n', 'incy'], INOUT_OUT ),
               parm_def('incy', PASSBYVALUE, INOUT_IN ) ] ),

# 2.5.6. cublas<t>dot()
  func_decl( [ "cublasSdot_v2", "cublasDdot_v2", "cublasCdotu_v2", "cublasCdotc_v2", "cublasZdotu_v2", "cublasZdotc_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_IN ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR, 'n', 'incy'], INOUT_IN ),
               parm_def('incy', PASSBYVALUE, INOUT_IN ),
               parm_def('result', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_OUT ) ] ),

# 2.5.8. cublas<t>rot()
  func_decl( [ "cublasSrot_v2", "cublasDrot_v2", "cublasCrot_v2", "cublasCsrot_v2", "cublasZrot_v2", "cublasZdrot_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_INOUT ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR, 'n', 'incy'], INOUT_INOUT ),
               parm_def('incy', PASSBYVALUE, INOUT_IN ),
               parm_def('c', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('s', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_IN ) ] ),

# 2.5.9. cublas<t>rotg()
  func_decl( [ "cublasSrotg_v2", "cublasDrotg_v2", "cublasCrotg_v2", "cublasZrotg_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('a', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_INOUT ),
               parm_def('b', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_INOUT ),
               parm_def('c', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_OUT ),
               parm_def('s', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_OUT ) ] ),

# 2.5.10. cublas<t>rotm()
  func_decl( [ "cublasSrotm_v2", "cublasDrotm_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_INOUT ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR, 'n', 'incy'], INOUT_INOUT ),
               parm_def('incy', PASSBYVALUE, INOUT_IN ),
               parm_def('param', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_IN ) ] ),

# 2.5.11. cublas<t>rotmg() requires host/dev in/out and const vector!
  func_decl( [ "cublasSrotmg_v2", "cublasDrotmg_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('d1', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_INOUT ),
               parm_def('d2', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_INOUT ),
               parm_def('x1', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_INOUT ),
               parm_def('y1', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('param', [ MEMORY_HoD_CUBLASPOINTERMODE, CONST_VECTOR, 5 ], INOUT_OUT ) ] ),

# 2.5.12. cublas<t>scal()
  func_decl( [ "cublasSscal_v2", "cublasDscal_v2", "cublasCscal_v2", "cublasCsscal_v2", "cublasZscal_v2", "cublasZdscal_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUBLASPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_INOUT ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ) ] ),

# 2.5.13. cublas<t>swap()
  func_decl( [ "cublasSswap_v2", "cublasDswap_v2", "cublasCswap_v2", "cublasZswap_v2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('x', [ MEMORY_DEVICE, VECTOR, 'n', 'incx'], INOUT_INOUT ),
               parm_def('incx', PASSBYVALUE, INOUT_IN ),
               parm_def('y', [ MEMORY_DEVICE, VECTOR, 'n', 'incy'], INOUT_INOUT ),
               parm_def('incy', PASSBYVALUE, INOUT_IN ) ] )
]
