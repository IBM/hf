from ...doc import *

# 2.6. Scaling parameters alpha and beta
# The storage data type for alpha[0], beta[0] is float for HALF and FLOAT tensors, and double for DOUBLE tensors. These parameters are passed using a host memory pointer.

# *** most often the following param depicts that tensor descriptors need to be the same as of the dataType
#     CUDNN_STATUS_BAD_PARAM
#     The dataType of the two tensor descriptors are different.


cuDNN_api = [
# 4.1. cudnnActivationBackward
  func_decl( [ "cudnnActivationBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('activationDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dxDesc" } ) ] ),

# 4.2. cudnnActivationForward
  func_decl( [ "cudnnActivationForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('activationDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ) ] ),

# 4.3. cudnnAddTensor
  func_decl( [ "cudnnAddTensor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('aDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('A', MEMORY_DEVICE, INOUT_IN, { "typedep" : "aDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('cDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('C', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "cDesc" } ) ] ),

# 4.4. cudnnBatchNormalizationBackward
  func_decl( [ "cudnnBatchNormalizationBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alphaDataDiff', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('betaDataDiff', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('alphaParamDiff', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('betaParamDiff', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dxDesc" } ),
               parm_def('dBnScaleBiasDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('bnScale', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dBnScaleBiasDesc" } ),
               parm_def('dBnScaleResult', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dBnScaleBiasDesc" } ),
               parm_def('dBnBiasResult', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dBnScaleBiasDesc" } ),
               parm_def('epsilon', PASSBYVALUE, INOUT_IN ),
               parm_def('savedMean', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dBnScaleBiasDesc" } ), # FixME: DEVICE??
               parm_def('savedInvVariance', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dBnScaleBiasDesc" } ) ] ), # FixME: DEVICE??

# 4.5. cudnnBatchNormalizationForwardInference
  func_decl( [ "cudnnBatchNormalizationForwardInference" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('bnScaleBiasMeanVarDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('bnScale', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bnScaleBiasMeanVarDesc" } ),
               parm_def('bnBias', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bnScaleBiasMeanVarDesc" } ),
               parm_def('estimatedMean', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bnScaleBiasMeanVarDesc" } ),
               parm_def('estimatedVariance', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bnScaleBiasMeanVarDesc" } ),
               parm_def('epsilon', PASSBYVALUE, INOUT_IN ) ] ), # FixME: DEVICE??

# 4.6. cudnnBatchNormalizationForwardTraining
  func_decl( [ "cudnnBatchNormalizationForwardTraining" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('bnScaleBiasMeanVarDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('bnScale', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bnScaleBiasMeanVarDesc" } ),
               parm_def('bnBias', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bnScaleBiasMeanVarDesc" } ),
			   parm_def('exponentialAverageFactor', PASSBYVALUE, INOUT_IN ),
               parm_def('resultRunningMean', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "bnScaleBiasMeanVarDesc" } ),  # FixME: DEVICE??, typedep??
               parm_def('resultRunningVariance', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "bnScaleBiasMeanVarDesc" } ),  # FixME: DEVICE??, typedep??
               parm_def('epsilon', PASSBYVALUE, INOUT_IN ),
               parm_def('resultSaveMean', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "bnScaleBiasMeanVarDesc" } ),  # FixME: DEVICE??, typedep??
			   parm_def('resultSaveInvVariance', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "bnScaleBiasMeanVarDesc" } ) ] ), # FixME: DEVICE??, typedep??

# 4.6. cudnnCTCLoss
# ToDo

# 4.8. cudnnConvolutionBackwardBias
  func_decl( [ "cudnnConvolutionBackwardBias" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "dyDesc" } ), # ***
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "dyDesc" } ), # ***
               parm_def('dbDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('db', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dbDesc" } ) ] ),

# 4.9. cudnnConvolutionBackwardData
  func_decl( [ "cudnnConvolutionBackwardData" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "dyDesc" } ), # ***
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),  # cudnnFilterDescriptor_t
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('workSpace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "dyDesc" } ), # ***
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "dxDesc" } ) ] ),

# 4.10. cudnnConvolutionBackwardFilter
  func_decl( [ "cudnnConvolutionBackwardFilter" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('workSpace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('dwDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dw', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "dwDesc" } ) ] ),

# 4.11. cudnnConvolutionBiasActivationForward
  func_decl( [ "cudnnConvolutionBiasActivationForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha1', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('workSpace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('alpha2', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('zDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('z', MEMORY_DEVICE, INOUT_IN, { "typedep" : "zDesc" } ),
               parm_def('biasDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('bias', MEMORY_DEVICE, INOUT_IN, { "typedep" : "biasDesc" } ),
               parm_def('activationDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "yDesc" } ) ] ),

# 4.12. cudnnConvolutionForward
  func_decl( [ "cudnnConvolutionForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),  # cudnnFilterDescriptor_t
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('workSpace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "yDesc" } ) ] ),

# 4.13. cudnnCreate
  func_decl( [ "cudnnCreate" ],
             [ parm_def('handle', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.14. cudnnCreateActivationDescriptor
  func_decl( [ "cudnnCreateActivationDescriptor" ],
             [ parm_def('activationDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.15. cudnnCreateAlgorithmDescriptor    # (New for 7.1)
  func_decl( [ "cudnnCreateAlgorithmDescriptor" ],
             [ parm_def('algoDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.16. cudnnCreateAlgorithmPerformance   # (New for 7.1)
  func_decl( [ "cudnnCreateAlgorithmPerformance" ],
             [ parm_def('algoPerf', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('numberToCreate', PASSBYVALUE, INOUT_IN ) ] ),

# 4.17. cudnnCreateCTCLossDescriptor
  func_decl( [ "cudnnCreateCTCLossDescriptor" ],
             [ parm_def('ctcLossDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.18. cudnnCreateConvolutionDescriptor
  func_decl( [ "cudnnCreateConvolutionDescriptor" ],
             [ parm_def('convDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.19. cudnnCreateDropoutDescriptor
  func_decl( [ "cudnnCreateDropoutDescriptor" ],
             [ parm_def('dropoutDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.20. cudnnCreateFilterDescriptor
  func_decl( [ "cudnnCreateFilterDescriptor" ],
             [ parm_def('filterDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.21. cudnnCreateLRNDescriptor
  func_decl( [ "cudnnCreateLRNDescriptor" ],
             [ parm_def('normDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.22. cudnnCreateOpTensorDescriptor
  func_decl( [ "cudnnCreateOpTensorDescriptor" ],
             [ parm_def('opTensorDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.23. cudnnCreatePersistentRNNPlan
  func_decl( [ "cudnnCreatePersistentRNNPlan" ],
             [ parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('minibatch', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ),
               parm_def('opTensorDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.24. cudnnCreatePoolingDescriptor
  func_decl( [ "cudnnCreatePoolingDescriptor" ],
             [ parm_def('poolingDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.25. cudnnCreateRNNDescriptor
  func_decl( [ "cudnnCreateRNNDescriptor" ],
             [ parm_def('rnnDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.26. cudnnCreateReduceTensorDescriptor
  func_decl( [ "cudnnCreateReduceTensorDescriptor" ],
             [ parm_def('reduceTensorDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.27. cudnnCreateSpatialTransformerDescriptor
  func_decl( [ "cudnnCreateSpatialTransformerDescriptor" ],
             [ parm_def('stDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.28. cudnnCreateTensorDescriptor
  func_decl( [ "cudnnCreateTensorDescriptor" ],
             [ parm_def('tensorDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.29. cudnnDeriveBNTensorDescriptor
  func_decl( [ "cudnnDeriveBNTensorDescriptor" ],
             [ parm_def('derivedBnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ) ] ),

# 4.30. cudnnDestroy
  func_decl( [ "cudnnDestroy" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ) ] ),

# 4.31. cudnnDestroyActivationDescriptor
  func_decl( [ "cudnnDestroyActivationDescriptor" ],
             [ parm_def('activationDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.32. cudnnDestroyAlgorithmDescriptor
  func_decl( [ "cudnnDestroyAlgorithmDescriptor" ],
             [ parm_def('algorithmDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.33. cudnnDestroyAlgorithmPerformance
  func_decl( [ "cudnnDestroyAlgorithmPerformance" ],
             [ parm_def('algoPerf', PASSBYVALUE, INOUT_IN ) ] ),

# 4.34. cudnnDestroyCTCLossDescriptor
  func_decl( [ "cudnnDestroyCTCLossDescriptor" ],
             [ parm_def('ctcLossDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.35. cudnnDestroyConvolutionDescriptor
  func_decl( [ "cudnnDestroyConvolutionDescriptor" ],
             [ parm_def('convDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.36. cudnnDestroyDropoutDescriptor
  func_decl( [ "cudnnDestroyDropoutDescriptor" ],
             [ parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.37. cudnnDestroyFilterDescriptor
  func_decl( [ "cudnnDestroyFilterDescriptor" ],
             [ parm_def('filterDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.38. cudnnDestroyLRNDescriptor
  func_decl( [ "cudnnDestroyLRNDescriptor" ],
             [ parm_def('lrnDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.39. cudnnDestroyOpTensorDescriptor
  func_decl( [ "cudnnDestroyOpTensorDescriptor" ],
             [ parm_def('opTensorDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.40. cudnnDestroyPersistentRNNPlan
  func_decl( [ "cudnnDestroyPersistentRNNPlan" ],
             [ parm_def('plan', PASSBYVALUE, INOUT_IN ) ] ),

# 4.41. cudnnDestroyPoolingDescriptor
  func_decl( [ "cudnnDestroyPoolingDescriptor" ],
             [ parm_def('poolingDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.42. cudnnDestroyRNNDescriptor
  func_decl( [ "cudnnDestroyRNNDescriptor" ],
             [ parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.43. cudnnDestroyReduceTensorDescriptor
  func_decl( [ "cudnnDestroyReduceTensorDescriptor" ],
             [ parm_def('tensorDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.44. cudnnDestroySpatialTransformerDescriptor
  func_decl( [ "cudnnDestroySpatialTransformerDescriptor" ],
             [ parm_def('stDesc', PASSBYVALUE, INOUT_IN ) ] ),

# 4.45. cudnnDestroyTensorDescriptor
  func_decl( [ "cudnnDestroyTensorDescriptor" ],
             [ parm_def('tensorDesc', PASSBYVALUE, INOUT_IN, { "del_cudnnDataType" : True } ) ] ),

# 4.46. cudnnDivisiveNormalizationBackward
  func_decl( [ "cudnnDivisiveNormalizationBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('normDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('means', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('temp', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('temp2', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('dXdMeansDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dXdMeansDesc" } ),
               parm_def('dMeans', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dXdMeansDesc" } ) ] ),

# 4.47. cudnnDivisiveNormalizationForward
  func_decl( [ "cudnnDivisiveNormalizationForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('normDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('means', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('temp', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('temp2', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ) ] ),

# 4.48. cudnnDropoutBackward
  func_decl( [ "cudnnDropoutBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dydesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dydesc" } ),
               parm_def('dxdesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dxdesc" } ),
               parm_def('reserveSpace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('reserveSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),

# 4.49. cudnnDropoutForward
  func_decl( [ "cudnnDropoutForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('xdesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xdesc" } ),
               parm_def('ydesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "ydesc" } ),
               parm_def('reserveSpace', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('reserveSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),

# 4.50. cudnnDropoutGetReserveSpaceSize
  func_decl( [ "cudnnDropoutGetReserveSpaceSize" ],
             [ parm_def('xdesc', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" }  ) ] ),

# 4.51. cudnnDropoutGetStatesSize
  func_decl( [ "cudnnDropoutGetStatesSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" }  ) ] ),


# [...]


# 4.54. cudnnFindConvolutionBackwardFilterAlgorithm
#  func_decl( [ "cudnnFindConvolutionBackwardFilterAlgorithm" ],
#             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
#               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
#               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
#               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
#               parm_def('dwDesc', PASSBYVALUE, INOUT_IN ),
#               parm_def('requestedAlgoCount', MEMORY_DEVICE, INOUT_IN ),
#               parm_def('returnedAlgoCount', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
#               parm_def('perfResults', [ MEMORY_HOST, VECTOR ], INOUT_OUT, { "typepatch" : "size_t", "sizedep" : 'returnedAlgoCount' } ) ] ),



# [...]


# 4.62. cudnnGetActivationDescriptor
  func_decl( [ "cudnnGetActivationDescriptor" ],
             [ parm_def('activationDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('reluNanOpt', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('reluCeiling', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ), # coef in CUDA 9.2

# 4.63. cudnnGetAlgorithmDescriptor  # (New for 7.1)
  func_decl( [ "cudnnGetAlgorithmDescriptor" ],
             [ parm_def('algoDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algorithm', [MEMORY_HOST, SCALAR], INOUT_IN ) ] ),

# 4.64. cudnnGetAlgorithmPerformance  # (New for 7.1)
  func_decl( [ "cudnnGetAlgorithmPerformance" ],
             [ parm_def('algoPerf', [MEMORY_HOST, SCALAR], INOUT_INOUT ),
               parm_def('algoDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('status', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('time', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('memory', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.65. cudnnGetAlgorithmSpaceSize  # (New for 7.1)
  func_decl( [ "cudnnGetAlgorithmSpaceSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('algoDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algoSpaceSizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.66. cudnnGetCTCLossDescriptor
  func_decl( [ "cudnnGetCTCLossDescriptor" ],
             [ parm_def('ctcLossDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('compType', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.67. cudnnGetCTCLossWorkspaceSize
  func_decl( [ "cudnnGetCTCLossWorkspaceSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('probsDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('gradientsDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('labels', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('labelLengths', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('inputLengths', [MEMORY_HOST, SCALAR], INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('cudnnCTCLossDescriptor_t', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),


# [...]

# 4.69. cudnnGetConvolution2dDescriptor
  func_decl( [ "cudnnGetConvolution2dDescriptor" ],
             [ parm_def('convDesc', [MEMORY_HOST, SCALAR], INOUT_INOUT ),
               parm_def('pad_h', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('pad_w', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('u', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('v', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('upscalex', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('upscaley', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('mode', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('computeType', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.70. cudnnGetConvolution2dForwardOutputDim
  func_decl( [ "cudnnGetConvolution2dForwardOutputDim" ],
             [ parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('inputTensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('filterDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('n', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('c', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('h', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('w', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.71. cudnnGetConvolutionBackwardDataAlgorithm
  func_decl( [ "cudnnGetConvolutionBackwardDataAlgorithm" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('preference', PASSBYVALUE, INOUT_IN ),
               parm_def('memoryLimitInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('algo', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.72. cudnnGetConvolutionBackwardDataAlgorithmMaxCount
  func_decl( [ "cudnnGetConvolutionBackwardDataAlgorithmMaxCount" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('count', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# [...]


# 4.74. cudnnGetConvolutionBackwardDataWorkspaceSize
  func_decl( [ "cudnnGetConvolutionBackwardDataWorkspaceSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.75. cudnnGetConvolutionBackwardFilterAlgorithm
  func_decl( [ "cudnnGetConvolutionBackwardFilterAlgorithm" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dwDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('preference', PASSBYVALUE, INOUT_IN ),
               parm_def('memoryLimitInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('algo', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.76. cudnnGetConvolutionBackwardFilterAlgorithmMaxCount
  func_decl( [ "cudnnGetConvolutionBackwardFilterAlgorithmMaxCount" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('count', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# [...]


# 4.78. cudnnGetConvolutionBackwardFilterWorkspaceSize
  func_decl( [ "cudnnGetConvolutionBackwardFilterWorkspaceSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('gradDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.79. cudnnGetConvolutionForwardAlgorithm
  func_decl( [ "cudnnGetConvolutionForwardAlgorithm" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('preference', PASSBYVALUE, INOUT_IN ),
               parm_def('memoryLimitInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('algo', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.80. cudnnGetConvolutionForwardAlgorithmMaxCount
  func_decl( [ "cudnnGetConvolutionForwardAlgorithmMaxCount" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('count', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# [...]


# 4.82. cudnnGetConvolutionForwardWorkspaceSize
  func_decl( [ "cudnnGetConvolutionForwardWorkspaceSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.83. cudnnGetConvolutionGroupCount
  func_decl( [ "cudnnGetConvolutionGroupCount" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('count', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.84. cudnnGetConvolutionMathType
  func_decl( [ "cudnnGetConvolutionMathType" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('mathType', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# 4.87. cudnnGetCudartVersion
# in theory we could run this also locally (to speed-up), but let's call it on the other side
  func_decl( [ "cudnnGetCudartVersion" ],
             [ ret_def( { "typepatch" : "size_t" } ) ] ),

# 4.88. cudnnGetDropoutDescriptor
  func_decl( [ "cudnnGetDropoutDescriptor" ],
             [ parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dropout', [MEMORY_HOST, SCALAR], INOUT_OUT ), # FixME: HOST??
               parm_def('states', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('seed', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ), # FixME: HOST??

# 4.89. cudnnGetErrorString
# no need to implement -> can be run locally

# 4.90. cudnnGetFilter4dDescriptor
  func_decl( [ "cudnnGetFilter4dDescriptor" ],
             [ parm_def('filterDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('format', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('k', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('c', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('h', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('w', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# [...]

# 4.92. cudnnGetLRNDescriptor
  func_decl( [ "cudnnGetLRNDescriptor" ],
             [ parm_def('normDesc', PASSBYVALUE, INOUT_INOUT ), # FixME
               parm_def('lrnN', [MEMORY_HOST, SCALAR], INOUT_OUT ), # ToDo: -can- be null
               parm_def('lrnAlpha', [MEMORY_HOST, SCALAR], INOUT_OUT ), # ToDo: -can- be null
               parm_def('lrnBeta', [MEMORY_HOST, SCALAR], INOUT_OUT ), # ToDo: -can- be null
               parm_def('lrnK', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ), # ToDo: -can- be null

# 4.93. cudnnGetOpTensorDescriptor
  func_decl( [ "cudnnGetOpTensorDescriptor" ],
             [ parm_def('opTensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('opTensorOp', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('opTensorCompType', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('opTensorNanOpt', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.94. cudnnGetPooling2dDescriptor
  func_decl( [ "cudnnGetPooling2dDescriptor" ],
             [ parm_def('poolingDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('maxpoolingNanOpt', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('windowHeight', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('windowWidth', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('verticalPadding', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('horizontalPadding', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('verticalStride', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('horizontalStride', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.95. cudnnGetPooling2dForwardOutputDim
  func_decl( [ "cudnnGetPooling2dForwardOutputDim" ],
             [ parm_def('poolingDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('inputTensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('n', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('c', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('h', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('w', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# [...]


# 4.98. cudnnGetProperty
  func_decl( [ "cudnnGetProperty" ],
             [ parm_def('type', PASSBYVALUE, INOUT_IN ),
               parm_def('value', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.99. cudnnGetRNNDescriptor
  func_decl( [ "cudnnGetRNNDescriptor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hiddenSize', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('numLayers', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('dropoutDesc', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('inputMode', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('direction', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('mode', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('algo', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('dataType', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# 4.100. cudnnGetRNNLinLayerBiasParams
  func_decl( [ "cudnnGetRNNLinLayerBiasParams" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('layer', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('linLayerID', PASSBYVALUE, INOUT_IN ),
               parm_def('linLayerBiasDesc', PASSBYVALUE, INOUT_OUT ),
               parm_def('linLayerBias', MEMORY_DEVICE, INOUT_OUT ) ] ),

# 4.101. cudnnGetRNNLinLayerMatrixParams
  func_decl( [ "cudnnGetRNNLinLayerMatrixParams" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('layer', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('linLayerID', PASSBYVALUE, INOUT_IN ),
               parm_def('linLayerMatDesc', PASSBYVALUE, INOUT_OUT ),
               parm_def('linLayerMat', MEMORY_DEVICE, INOUT_OUT ) ] ),

# 4.102. cudnnGetRNNParamsSize
  func_decl( [ "cudnnGetRNNParamsSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.103. cudnnGetRNNProjectionLayers
  func_decl( [ "cudnnGetRNNProjectionLayers" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('recProjSize', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('outProjSize', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.104. cudnnGetRNNTrainingReserveSize
# 4.105. cudnnGetRNNWorkspaceSize
#  func_decl( [ "cudnnGetRNNTrainingReserveSize", "cudnnGetRNNWorkspaceSize" ],
#             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
#               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
#               parm_def('seqLength', PASSBYVALUE, INOUT_IN ),
#               parm_def('xDesc', [MEMORY_HOST, SCALAR], INOUT_IN ), # like batched ToDo
#               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.106. cudnnGetReduceTensorDescriptor
  func_decl( [ "cudnnGetReduceTensorDescriptor" ],
             [ parm_def('reduceTensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceTensorOp', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('reduceTensorCompType', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('reduceTensorNanOpt', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('reduceTensorIndices', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('reduceTensorIndicesType', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.107. cudnnGetReductionIndicesSize
# 4.108. cudnnGetReductionWorkspaceSize
  func_decl( [ "cudnnGetReductionIndicesSize", "cudnnGetReductionWorkspaceSize" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('aDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('cDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('sizeInBytes', [MEMORY_HOST, SCALAR], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.109. cudnnGetStream
  func_decl( [ "cudnnGetStream" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('streamId', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),

# 4.110. cudnnGetTensor4dDescriptor
  func_decl( [ "cudnnGetTensor4dDescriptor" ],
             [ parm_def('tensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('n', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('c', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('h', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('w', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('nStride', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('cStride', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('hStride', [MEMORY_HOST, SCALAR], INOUT_OUT ),
               parm_def('wStride', [MEMORY_HOST, SCALAR], INOUT_OUT ) ] ),


# [...]


# 4.112. cudnnGetTensorSizeInBytes
  func_decl( [ "cudnnGetTensorSizeInBytes" ],
             [ parm_def('tensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('size', [ MEMORY_HOST, SCALAR ], INOUT_OUT, { "typepatch" : "size_t *" } ) ] ),

# 4.113. cudnnGetVersion
  func_decl( [ "cudnnGetVersion" ],
             [ ret_def( { "typepatch" : "size_t" } ) ] ),

# 4.114. cudnnIm2Col
  func_decl( [ "cudnnIm2Col" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('convDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('colBuffer', MEMORY_DEVICE, INOUT_OUT ) ] ),

# 4.115. cudnnLRNCrossChannelBackward
  func_decl( [ "cudnnLRNCrossChannelBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('normDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('lrnMode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('dxDesc', PASSBYVALUE, INOUT_OUT ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dxDesc" } ) ] ),

# 4.116. cudnnLRNCrossChannelForward
  func_decl( [ "cudnnLRNCrossChannelForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('normDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('lrnMode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ) ] ),

# 4.117. cudnnOpTensor
  func_decl( [ "cudnnOpTensor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('opTensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha1', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('aDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('A', MEMORY_DEVICE, INOUT_IN, { "typedep" : "aDesc" } ),
               parm_def('alpha2', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('bDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('B', MEMORY_DEVICE, INOUT_IN, { "typedep" : "bDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('cDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('C', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "cDesc" } ) ] ),

# 4.118. cudnnPoolingBackward
  func_decl( [ "cudnnPoolingBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('poolingDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dxDesc" } ) ] ),

# 4.119. cudnnPoolingForward
  func_decl( [ "cudnnPoolingForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('poolingDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ) ] ),

# 4.120. cudnnQueryRuntimeError
  func_decl( [ "cudnnQueryRuntimeError" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rstatus', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('tag', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ) ] ),  #FixME: parm should be NULL!
	
# 4.121. cudnnRNNBackwardData
  func_decl( [ "cudnnRNNBackwardData" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('seqLength', PASSBYVALUE, INOUT_IN ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('dhyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dhy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dhyDesc" } ),
               parm_def('dcyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dcy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dcyDesc" } ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('hxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "hxDesc" } ),
               parm_def('cxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('cx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "cxDesc" } ),
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dxDesc" } ),
               parm_def('dhxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dhx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dhxDesc" } ),
               parm_def('dcxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dcx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dcxDesc" } ),
               parm_def('workspace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('reserveSpace', MEMORY_DEVICE, INOUT_INOUT ),
               parm_def('reserveSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),
	
# 4.122. cudnnRNNBackwardWeights
  func_decl( [ "cudnnRNNBackwardWeights" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('seqLength', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('hxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "hxDesc" } ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_IN, { "typedep" : "yDesc" } ),
               parm_def('workspace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('dwDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dw', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "dwDesc" } ),
               parm_def('reserveSpace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('reserveSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),
	
# 4.123. cudnnRNNForwardInference
  func_decl( [ "cudnnRNNForwardInference" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('seqLength', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('hxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "hxDesc" } ),
               parm_def('cxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('cx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "cxDesc" } ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ),
               parm_def('hyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hy', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "hyDesc" } ),
               parm_def('cyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('cy', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "cyDesc" } ),
               parm_def('workspace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),
	
# 4.124. cudnnRNNForwardTraining
  func_decl( [ "cudnnRNNForwardTraining" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('seqLength', PASSBYVALUE, INOUT_IN ),
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('hxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "hxDesc" } ),
               parm_def('cxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('cx', MEMORY_DEVICE, INOUT_IN, { "typedep" : "cxDesc" } ),
               parm_def('wDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('w', MEMORY_DEVICE, INOUT_IN, { "typedep" : "wDesc" } ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ),
               parm_def('hyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('hy', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "hyDesc" } ),
               parm_def('cyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('cy', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "cyDesc" } ),
               parm_def('workspace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('reserveSpace', MEMORY_DEVICE, INOUT_INOUT ),
               parm_def('reserveSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ) ] ),

# 4.125. cudnnReduceTensor
  func_decl( [ "cudnnReduceTensor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceTensorDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('indices', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('indicesSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('workspace', MEMORY_DEVICE, INOUT_IN ),
               parm_def('workSpaceSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('aDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('A', MEMORY_DEVICE, INOUT_IN, { "typedep" : "aDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "aDesc" } ), # ***
               parm_def('cDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('C', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "cDesc" } ) ] ),



# [...]


# 4.127. cudnnRestoreDropoutDescriptor
  func_decl( [ "cudnnRestoreDropoutDescriptor" ],
             [ parm_def('dropoutDesc', PASSBYVALUE, INOUT_INOUT ),
               parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('states', MEMORY_DEVICE, INOUT_IN ),
               parm_def('stateSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('seed', PASSBYVALUE, INOUT_IN ) ] ),


# [...]


# 4.129. cudnnScaleTensor
  func_decl( [ "cudnnScaleTensor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "yDesc" } ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ) ] ), # ***

# 4.130. cudnnSetActivationDescriptor
  func_decl( [ "cudnnSetActivationDescriptor" ],
             [ parm_def('activationDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('reluNanOpt', PASSBYVALUE, INOUT_IN ),
               parm_def('reluCeiling', PASSBYVALUE, INOUT_IN ) ] ),

# 4.131. cudnnSetAlgorithmDescriptor
  func_decl( [ "cudnnSetAlgorithmDescriptor" ],
             [ parm_def('algorithmDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('algorithm', PASSBYVALUE, INOUT_IN ) ] ),

# 4.133. cudnnSetCTCLossDescriptor
  func_decl( [ "cudnnSetCTCLossDescriptor" ],
             [ parm_def('ctcLossDesc', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('compType', PASSBYVALUE, INOUT_IN ) ] ),

			   
# [...]


# 4.135. cudnnSetConvolution2dDescriptor
  func_decl( [ "cudnnSetConvolution2dDescriptor" ],
             [ parm_def('convDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('pad_h', PASSBYVALUE, INOUT_IN ),
               parm_def('pad_w', PASSBYVALUE, INOUT_IN ),
               parm_def('u', PASSBYVALUE, INOUT_IN ),
               parm_def('v', PASSBYVALUE, INOUT_IN ),
               parm_def('upscalex', PASSBYVALUE, INOUT_IN ),
               parm_def('upscaley', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('computeType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.136. cudnnSetConvolutionGroupCount
  func_decl( [ "cudnnSetConvolutionGroupCount" ],
             [ parm_def('convDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ), # FixMe
               parm_def('groupCount', PASSBYVALUE, INOUT_IN ) ] ),

# 4.137. cudnnSetConvolutionMathType
  func_decl( [ "cudnnSetConvolutionMathType" ],
             [ parm_def('convDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ), # FixMe
               parm_def('mathType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.138. cudnnSetConvolutionNdDescriptor
  func_decl( [ "cudnnSetConvolutionNdDescriptor" ],
             [ parm_def('convDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('arrayLength', PASSBYVALUE, INOUT_IN ),
               parm_def('padA', [ MEMORY_HOST, VECTOR, 'arrayLength' ], INOUT_IN ),
               parm_def('filterStrideA', [ MEMORY_HOST, VECTOR, 'arrayLength' ], INOUT_IN ),
               parm_def('upscaleA', [ MEMORY_HOST, VECTOR, 'arrayLength' ], INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.139. cudnnSetDropoutDescriptor
  func_decl( [ "cudnnSetDropoutDescriptor" ],
             [ parm_def('dropoutDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('dropout', PASSBYVALUE, INOUT_IN ),
               parm_def('states', MEMORY_DEVICE, INOUT_OUT ),
               parm_def('stateSizeInBytes', PASSBYVALUE, INOUT_IN, { "typepatch" : "size_t" } ),
               parm_def('seed', PASSBYVALUE, INOUT_IN ) ] ),

# 4.140. cudnnSetFilter4dDescriptor
  func_decl( [ "cudnnSetFilter4dDescriptor" ],
             [ parm_def('filterDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ),
               parm_def('format', PASSBYVALUE, INOUT_IN ),
               parm_def('k', PASSBYVALUE, INOUT_IN ),
               parm_def('c', PASSBYVALUE, INOUT_IN ),
               parm_def('h', PASSBYVALUE, INOUT_IN ),
               parm_def('w', PASSBYVALUE, INOUT_IN ) ] ),

# 4.141. cudnnSetFilterNdDescriptor
  func_decl( [ "cudnnSetFilterNdDescriptor" ],
             [ parm_def('filterDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ),
               parm_def('format', PASSBYVALUE, INOUT_IN ),
               parm_def('nbDims', PASSBYVALUE, INOUT_IN ),
               parm_def('filterDimA', [ MEMORY_HOST, VECTOR, 'nbDims' ], INOUT_IN ) ] ),

# 4.142. cudnnSetLRNDescriptor
  func_decl( [ "cudnnSetLRNDescriptor" ],
             [ parm_def('normDesc', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('lrnN', PASSBYVALUE, INOUT_IN ),
               parm_def('lrnAlpha', PASSBYVALUE, INOUT_IN ),
               parm_def('lrnBeta', PASSBYVALUE, INOUT_IN ),
               parm_def('lrnK', PASSBYVALUE, INOUT_IN ) ] ),

# 4.143. cudnnSetOpTensorDescriptor
  func_decl( [ "cudnnSetOpTensorDescriptor" ],
             [ parm_def('opTensorDesc', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('opTensorOp', PASSBYVALUE, INOUT_IN ),
               parm_def('opTensorCompType', PASSBYVALUE, INOUT_IN ),
               parm_def('opTensorNanOpt', PASSBYVALUE, INOUT_IN ) ] ),

# 4.144. cudnnSetPersistentRNNPlan
  func_decl( [ "cudnnSetPersistentRNNPlan" ],
             [ parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ), # FixME
               parm_def('plan', PASSBYVALUE, INOUT_IN ) ] ),  #FixME

# 4.145. cudnnSetPooling2dDescriptor
  func_decl( [ "cudnnSetPooling2dDescriptor" ],
             [ parm_def('poolingDesc', [ MEMORY_HOST, SCALAR ], INOUT_OUT ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('maxpoolingNanOpt', PASSBYVALUE, INOUT_IN ),
               parm_def('windowHeight', PASSBYVALUE, INOUT_IN ),
               parm_def('windowWidth', PASSBYVALUE, INOUT_IN ),
               parm_def('verticalPadding', PASSBYVALUE, INOUT_IN ),
               parm_def('horizontalPadding', PASSBYVALUE, INOUT_IN ),
               parm_def('verticalStride', PASSBYVALUE, INOUT_IN ),
               parm_def('horizontalStride', PASSBYVALUE, INOUT_IN ) ] ),


# [...]


# 4.147. cudnnSetRNNDescriptor
  func_decl( [ "cudnnSetRNNDescriptor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('hiddenSize', PASSBYVALUE, INOUT_IN ),
               parm_def('numLayers', PASSBYVALUE, INOUT_IN ),
               parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('inputMode', PASSBYVALUE, INOUT_IN ),
               parm_def('direction', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.148. cudnnSetRNNDescriptor_v5
  func_decl( [ "cudnnSetRNNDescriptor_v5" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('hiddenSize', PASSBYVALUE, INOUT_IN ),
               parm_def('numLayers', PASSBYVALUE, INOUT_IN ),
               parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('inputMode', PASSBYVALUE, INOUT_IN ),
               parm_def('direction', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.149. cudnnSetRNNDescriptor_v6
  func_decl( [ "cudnnSetRNNDescriptor_v6" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('hiddenSize', PASSBYVALUE, INOUT_IN ),
               parm_def('numLayers', PASSBYVALUE, INOUT_IN ),
               parm_def('dropoutDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('inputMode', PASSBYVALUE, INOUT_IN ),
               parm_def('direction', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.150. cudnnSetRNNMatrixMathType
  func_decl( [ "cudnnSetRNNMatrixMathType" ],
             [ parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('mType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.151. cudnnSetRNNProjectionLayers
  func_decl( [ "cudnnSetRNNProjectionLayers" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('rnnDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('recProjSize', PASSBYVALUE, INOUT_IN ),
               parm_def('outProjSize', PASSBYVALUE, INOUT_IN ) ] ),

# 4.152. cudnnSetReduceTensorDescriptor
  func_decl( [ "cudnnSetReduceTensorDescriptor" ],
             [ parm_def('reduceTensorDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('reduceTensorOp', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceTensorCompType', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceTensorNanOpt', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceTensorIndices', PASSBYVALUE, INOUT_IN ),
               parm_def('reduceTensorIndicesType', PASSBYVALUE, INOUT_IN ) ] ),

# 4.153. cudnnSetSpatialTransformerNdDescriptor
  func_decl( [ "cudnnSetSpatialTransformerNdDescriptor" ],
             [ parm_def('stDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT ),
               parm_def('samplerType', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN ),
               parm_def('nbDims', PASSBYVALUE, INOUT_IN ),
               parm_def('dimA', [ MEMORY_HOST, VECTOR, 'nbDims' ], INOUT_IN ) ] ),

# 4.154. cudnnSetStream
  func_decl( [ "cudnnSetStream" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('streamId', PASSBYVALUE, INOUT_IN ) ] ),

# 4.155. cudnnSetTensor
  func_decl( [ "cudnnSetTensor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "yDesc" } ),
               parm_def('valuePtr', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ) ] ),

# 4.156. cudnnSetTensor4dDescriptor
# cudnnCreateTensorDescriptor_t is a pointer to an opaque structure holding the description of a
# generic n-D dataset. cudnnCreateTensorDescriptor() is used to create one instance, and one of
# the routrines cudnnSetTensorNdDescriptor(), cudnnSetTensor4dDescriptor() or
# cudnnSetTensor4dDescriptorEx() must be used to initialize this instance. 
  func_decl( [ "cudnnSetTensor4dDescriptor" ],
             [ parm_def('tensorDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT, { "set_cudnnDataType" : "DESCR" } ),
               parm_def('format', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN, { "set_cudnnDataType" : "DATATYPE" } ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('c', PASSBYVALUE, INOUT_IN ),
               parm_def('h', PASSBYVALUE, INOUT_IN ),
               parm_def('w', PASSBYVALUE, INOUT_IN ) ] ),

# 4.157. cudnnSetTensor4dDescriptorEx
# cudnnCreateTensorDescriptor_t is a pointer to an opaque structure holding the description of a
# generic n-D dataset. cudnnCreateTensorDescriptor() is used to create one instance, and one of
# the routrines cudnnSetTensorNdDescriptor(), cudnnSetTensor4dDescriptor() or
# cudnnSetTensor4dDescriptorEx() must be used to initialize this instance. 
  func_decl( [ "cudnnSetTensor4dDescriptorEx" ],
             [ parm_def('tensorDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT, { "set_cudnnDataType" : "DESCR" } ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN, { "set_cudnnDataType" : "DATATYPE" } ),
               parm_def('n', PASSBYVALUE, INOUT_IN ),
               parm_def('c', PASSBYVALUE, INOUT_IN ),
               parm_def('h', PASSBYVALUE, INOUT_IN ),
               parm_def('w', PASSBYVALUE, INOUT_IN ),
               parm_def('nStride', PASSBYVALUE, INOUT_IN ),
               parm_def('cStride', PASSBYVALUE, INOUT_IN ),
               parm_def('hStride', PASSBYVALUE, INOUT_IN ),
               parm_def('wStride', PASSBYVALUE, INOUT_IN ) ] ),

# 4.158. cudnnSetTensorNdDescriptor
# cudnnCreateTensorDescriptor_t is a pointer to an opaque structure holding the description of a
# generic n-D dataset. cudnnCreateTensorDescriptor() is used to create one instance, and one of
# the routrines cudnnSetTensorNdDescriptor(), cudnnSetTensor4dDescriptor() or
# cudnnSetTensor4dDescriptorEx() must be used to initialize this instance. 
  func_decl( [ "cudnnSetTensorNdDescriptor" ],
             [ parm_def('tensorDesc', [ MEMORY_HOST, SCALAR ], INOUT_INOUT, { "set_cudnnDataType" : "DESCR" } ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN, { "set_cudnnDataType" : "DATATYPE" } ),
               parm_def('nbDims', PASSBYVALUE, INOUT_IN ),
               parm_def('dimA', [ MEMORY_HOST, VECTOR, 'nbDims' ], INOUT_IN ),
               parm_def('strideA', [ MEMORY_HOST, VECTOR, 'nbDims' ], INOUT_IN ) ] ),

# 4.159. cudnnSetTensorNdDescriptorEx
# cudnnCreateTensorDescriptor_t is a pointer to an opaque structure holding the description of a
# generic n-D dataset. cudnnCreateTensorDescriptor() is used to create one instance, and one of
# the routrines cudnnSetTensorNdDescriptor(), cudnnSetTensor4dDescriptor() or
# cudnnSetTensor4dDescriptorEx() must be used to initialize this instance. 
  func_decl( [ "cudnnSetTensorNdDescriptorEx" ],
             [ parm_def('tensorDesc', [ MEMORY_HOST, SCALAR ], INOUT_OUT, { "set_cudnnDataType" : "DESCR" } ),
               parm_def('format', PASSBYVALUE, INOUT_IN ),
               parm_def('dataType', PASSBYVALUE, INOUT_IN, { "set_cudnnDataType" : "DATATYPE" } ),
               parm_def('nbDims', PASSBYVALUE, INOUT_IN ),
               parm_def('dimA', [ MEMORY_HOST, VECTOR, 'nbDims' ], INOUT_IN ) ] ),

# 4.160. cudnnSoftmaxBackward
  func_decl( [ "cudnnSoftmaxBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "yDesc" } ),
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "dyDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "yDesc" } ), # ***
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "dxDesc" } ) ] ),

# 4.161. cudnnSoftmaxForward
  func_decl( [ "cudnnSoftmaxForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('algo', PASSBYVALUE, INOUT_IN ),
               parm_def('mode', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "yDesc" } ) ] ),

# 4.162. cudnnSpatialTfGridGeneratorBackward
  func_decl( [ "cudnnSpatialTfGridGeneratorBackward" ],
             [ parm_def('handle', [ MEMORY_HOST, SCALAR ], INOUT_IN ),
               parm_def('stDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dgrid', MEMORY_DEVICE, INOUT_IN ),
               parm_def('dtheta', MEMORY_DEVICE, INOUT_OUT ) ] ),


# [...]


# 4.164. cudnnSpatialTfSamplerBackward
  func_decl( [ "cudnnSpatialTfSamplerBackward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('stDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_INOUT, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('dxDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dx', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "dxDesc" } ),
               parm_def('alphaDgrid', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('dyDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('dy', MEMORY_DEVICE, INOUT_IN, { "typedep" : "dyDesc" } ),
               parm_def('grid', MEMORY_DEVICE, INOUT_IN ), # FixME: DEVICE?
               parm_def('betaDgrid', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('dgrid', MEMORY_DEVICE, INOUT_OUT ) ] ), # FixME: DEVICE?

# 4.165. cudnnSpatialTfSamplerForward
  func_decl( [ "cudnnSpatialTfSamplerForward" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('stDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('grid', MEMORY_DEVICE, INOUT_IN ), # FixME: DEVICE?
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ) ] ),

# 4.166. cudnnTransformTensor
  func_decl( [ "cudnnTransformTensor" ],
             [ parm_def('handle', PASSBYVALUE, INOUT_IN ),
               parm_def('alpha', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('xDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('x', MEMORY_DEVICE, INOUT_IN, { "typedep" : "xDesc" } ),
               parm_def('beta', [ MEMORY_HOST, SCALAR ], INOUT_IN, { "typedep" : "xDesc" } ), # ***
               parm_def('yDesc', PASSBYVALUE, INOUT_IN ),
               parm_def('y', MEMORY_DEVICE, INOUT_OUT, { "typedep" : "yDesc" } ) ] ),

]
