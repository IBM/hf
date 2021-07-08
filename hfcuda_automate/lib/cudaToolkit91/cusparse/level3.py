from ...doc import *

cuSPARSE_level3 = [
# 8.1. cusparse<t>csrmm()
  func_decl( [ "cusparseScsrmm", "cusparseDcsrmm", "cusparseCcsrmm", "cusparseZcsrmm" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('k', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldb', PASSBYVALUE, INOUT_IN ),
               parm_def('beta', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('C', [ MEMORY_DEVICE, VECTOR], INOUT_INOUT ),
               parm_def('ldc', PASSBYVALUE, INOUT_IN ) ] ),

# 8.2. cusparse<t>csrmm2()
  func_decl( [ "cusparseScsrmm2", "cusparseDcsrmm2", "cusparseCcsrmm2", "cusparseZcsrmm2" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transB', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('k', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldb', PASSBYVALUE, INOUT_IN ),
               parm_def('beta', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('C', [ MEMORY_DEVICE, VECTOR], INOUT_INOUT ),
               parm_def('ldc', PASSBYVALUE, INOUT_IN ) ] ),

# 8.3. cusparse<t>csrsm_analysis()
  func_decl( [ "cusparseScsrsm_analysis", "cusparseDcsrsm_analysis", "cusparseCcsrsm_analysis", "cusparseZcsrsm_analysis" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('info', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ) ] ),

# 8.4. cusparse<t>csrsm_solve()
  func_decl( [ "cusparseScsrsm_solve", "cusparseDcsrsm_solve", "cusparseCcsrsm_solve", "cusparseZcsrsm_solve" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('info', PASSBYVALUE, INOUT_IN ),
               parm_def('F', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldf', PASSBYVALUE, INOUT_IN ),
               parm_def('X', [ MEMORY_DEVICE, VECTOR ], INOUT_OUT ),
               parm_def('ldx', PASSBYVALUE, INOUT_IN ) ] ),

# 8.5. cusparse<t>csrsm2_bufferSizeExt()
  func_decl( [ "cusparseScsrsm2_bufferSizeExt", "cusparseDcsrsm2_bufferSizeExt", "cusparseCcsrsm2_bufferSizeExt", "cusparseZcsrsm2_bufferSizeExt" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transB', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('nrhs', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldb', PASSBYVALUE, INOUT_IN ),
               parm_def('info', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('policy', PASSBYVALUE, INOUT_IN ),
               parm_def('pBufferSize', [ MEMORY_HOST, SCALAR ], INOUT_OUT ) ] ),

# 8.6. cusparse<t>csrsm2_analysis()
  func_decl( [ "cusparseScsrsm2_analysis", "cusparseDcsrsm2_analysis", "cusparseCcsrsm2_analysis", "cusparseZcsrsm2_analysis" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transB', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('nrhs', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldb', PASSBYVALUE, INOUT_IN ),
               parm_def('info', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('policy', PASSBYVALUE, INOUT_IN ),
               parm_def('pBuffer', MEMORY_DEVICE, INOUT_IN ) ] ),

# 8.7. cusparse<t>csrsm2_solve()
  func_decl( [ "cusparseScsrsm2_solve", "cusparseDcsrsm2_solve", "cusparseCcsrsm2_solve", "cusparseZcsrsm2_solve" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transB', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('nrhs', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('csrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('csrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('ldb', PASSBYVALUE, INOUT_IN ),
               parm_def('info', PASSBYVALUE, INOUT_IN ),
               parm_def('policy', PASSBYVALUE, INOUT_IN ),
               parm_def('pBuffer', MEMORY_DEVICE, INOUT_IN ) ] ),

# 8.8. cusparseXcsrsm2_zeroPivot()
  func_decl( [ "cusparseXcsrsm2_zeroPivot" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('info', PASSBYVALUE, INOUT_IN ),
               parm_def('position', [ MEMORY_HOST, SCALAR ], INOUT_OUT ) ] ),

# 8.9. cusparse<t>bsrmm()
  func_decl( [ "cusparseSbsrmm", "cusparseDbsrmm", "cusparseCbsrmm", "cusparseZbsrmm" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dirA', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transB', PASSBYVALUE, INOUT_IN ),
               parm_def('mb', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('kb', PASSBYVALUE, INOUT_IN ),
               parm_def('nnzb', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('bsrSortedValA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedRowPtrA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedColIndA', MEMORY_DEVICE, INOUT_IN ),
               parm_def('blockSize', PASSBYVALUE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldb', PASSBYVALUE, INOUT_IN ),
               parm_def('beta', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('C', [ MEMORY_DEVICE, VECTOR], INOUT_INOUT ),
               parm_def('ldc', PASSBYVALUE, INOUT_IN ) ] ),

# 8.10. cusparse<t>bsrsm2_bufferSize()
  func_decl( [ "cusparseSbsrsm2_bufferSize", "cusparseDbsrsm2_bufferSize", "cusparseCbsrsm2_bufferSize", "cusparseZbsrsm2_bufferSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dirA', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transXY', PASSBYVALUE, INOUT_IN ),
               parm_def('mb', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('nnzb', PASSBYVALUE, INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('bsrSortedVal', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedRowPtr', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedColInd', MEMORY_DEVICE, INOUT_IN ),
               parm_def('blockSize', PASSBYVALUE, INOUT_IN ),
               parm_def('info', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('pBufferSizeInBytes', [ MEMORY_HOST, SCALAR ], INOUT_OUT ) ] ),

# 8.11. cusparse<t>bsrsm2_analysis()
  func_decl( [ "cusparseSbsrsm2_analysis", "cusparseDbsrsm2_analysis", "cusparseCbsrsm2_analysis", "cusparseZbsrsm2_analysis" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dirA', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transXY', PASSBYVALUE, INOUT_IN ),
               parm_def('mb', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('nnzb', PASSBYVALUE, INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('bsrSortedVal', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedRowPtr', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedColInd', MEMORY_DEVICE, INOUT_IN ),
               parm_def('blockSize', PASSBYVALUE, INOUT_IN ),
               parm_def('info', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('policy', PASSBYVALUE, INOUT_IN ),
               parm_def('pBuffer', MEMORY_DEVICE, INOUT_IN ) ] ),

# 8.12. cusparse<t>bsrsm2_solve()
  func_decl( [ "cusparseSbsrsm2_solve", "cusparseDbsrsm2_solve", "cusparseCbsrsm2_solve", "cusparseZbsrsm2_solve" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dirA', PASSBYVALUE, INOUT_IN ),
               parm_def('transA', PASSBYVALUE, INOUT_IN ),
               parm_def('transXY', PASSBYVALUE, INOUT_IN ),
               parm_def('mb', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('nnzb', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('descrA', PASSBYVALUE, INOUT_IN ),
               parm_def('bsrSortedVal', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedRowPtr', MEMORY_DEVICE, INOUT_IN ),
               parm_def('bsrSortedColInd', MEMORY_DEVICE, INOUT_IN ),
               parm_def('blockSize', PASSBYVALUE, INOUT_IN ),
               parm_def('info', PASSBYVALUE, INOUT_IN ),
               parm_def('F', MEMORY_DEVICE, INOUT_IN ),
               parm_def('ldf', PASSBYVALUE, INOUT_IN ),
               parm_def('X', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('ldx', PASSBYVALUE, INOUT_IN ),
               parm_def('policy', PASSBYVALUE, INOUT_IN ),
               parm_def('pBuffer', MEMORY_DEVICE, INOUT_IN ) ] ),

# 8.13. cusparseXbsrsm2_zeroPivot()
  func_decl( [ "cusparseXbsrsm2_zeroPivot" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('info', PASSBYVALUE, INOUT_IN ),
               parm_def('position', [ MEMORY_HOST, SCALAR ], INOUT_OUT ) ] ),

# 8.14. cusparse<t>gemmi()
  func_decl( [ "cusparseSgemmi", "cusparseDgemmi", "cusparseCgemmi", "cusparseZgemmi" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('m', PASSBYVALUE, INOUT_IN ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('k', PASSBYVALUE, INOUT_IN ),
               parm_def('nnz', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('A', MEMORY_DEVICE, INOUT_IN ),
               parm_def('lda', PASSBYVALUE, INOUT_IN ),
               parm_def('cscValB', MEMORY_DEVICE, INOUT_IN ),
               parm_def('cscColPtrB', MEMORY_DEVICE, INOUT_IN ),
               parm_def('cscRowIndB', MEMORY_DEVICE, INOUT_IN ),
               parm_def('beta', [ MEMORY_HoD_CUSPARSEPOINTERMODE, SCALAR ], INOUT_IN ),
               parm_def('C', [ MEMORY_DEVICE, VECTOR], INOUT_INOUT ),
               parm_def('ldc', PASSBYVALUE, INOUT_IN ) ] )
]
