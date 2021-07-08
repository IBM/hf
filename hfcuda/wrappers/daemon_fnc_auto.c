/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxAttach ( void )
{
  hfinf( "[daemon] cuCtxAttach() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUcontext pctx;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxAttach( &d2t_msg.pctx, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxAttach() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxCreate_v2 ( void )
{
  hfinf( "[daemon] cuCtxCreate_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUcontext pctx;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxCreate_v2( &d2t_msg.pctx, t2d_msg_data.flags, t2d_msg_data.dev );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxCreate_v2() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxDestroy_v2 ( void )
{
  hfinf( "[daemon] cuCtxDestroy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUcontext ctx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxDestroy_v2( t2d_msg_data.ctx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxDestroy_v2() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxDetach ( void )
{
  hfinf( "[daemon] cuCtxDetach() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUcontext ctx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxDetach( t2d_msg_data.ctx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxDetach() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetApiVersion ( void )
{
  hfinf( "[daemon] cuCtxGetApiVersion() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUcontext ctx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    unsigned int version;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetApiVersion( t2d_msg_data.ctx, &d2t_msg.version );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetApiVersion() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetCacheConfig ( void )
{
  hfinf( "[daemon] cuCtxGetCacheConfig() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    CUfunc_cache pconfig;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetCacheConfig( &d2t_msg.pconfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetCacheConfig() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetCurrent ( void )
{
  hfinf( "[daemon] cuCtxGetCurrent() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    CUcontext pctx;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetCurrent( &d2t_msg.pctx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetCurrent() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetDevice ( void )
{
  hfinf( "[daemon] cuCtxGetDevice() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    CUdevice device;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetDevice( &d2t_msg.device );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetDevice() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetFlags ( void )
{
  hfinf( "[daemon] cuCtxGetFlags() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    unsigned int flags;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetFlags( &d2t_msg.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetFlags() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetLimit ( void )
{
  hfinf( "[daemon] cuCtxGetLimit() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUlimit limit;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    size_t pvalue;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetLimit( &d2t_msg.pvalue, t2d_msg_data.limit );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetLimit() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetSharedMemConfig ( void )
{
  hfinf( "[daemon] cuCtxGetSharedMemConfig() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    CUsharedconfig pConfig;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetSharedMemConfig( &d2t_msg.pConfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetSharedMemConfig() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxGetStreamPriorityRange ( void )
{
  hfinf( "[daemon] cuCtxGetStreamPriorityRange() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    int leastPriority;
    int greatestPriority;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxGetStreamPriorityRange( &d2t_msg.leastPriority, &d2t_msg.greatestPriority );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxGetStreamPriorityRange() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxSetCacheConfig ( void )
{
  hfinf( "[daemon] cuCtxSetCacheConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunc_cache config;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxSetCacheConfig( t2d_msg_data.config );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxSetCacheConfig() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxSetCurrent ( void )
{
  hfinf( "[daemon] cuCtxSetCurrent() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUcontext ctx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxSetCurrent( t2d_msg_data.ctx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxSetCurrent() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxSetLimit ( void )
{
  hfinf( "[daemon] cuCtxSetLimit() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUlimit limit;
    size_t value;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxSetLimit( t2d_msg_data.limit, t2d_msg_data.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxSetLimit() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxSetSharedMemConfig ( void )
{
  hfinf( "[daemon] cuCtxSetSharedMemConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUsharedconfig config;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxSetSharedMemConfig( t2d_msg_data.config );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxSetSharedMemConfig() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuCtxSynchronize ( void )
{
  hfinf( "[daemon] cuCtxSynchronize() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuCtxSynchronize(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuCtxSynchronize() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDeviceComputeCapability ( void )
{
  hfinf( "[daemon] cuDeviceComputeCapability() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    int major;
    int minor;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDeviceComputeCapability( &d2t_msg.major, &d2t_msg.minor, t2d_msg_data.dev );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDeviceComputeCapability() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDeviceGetProperties ( void )
{
  hfinf( "[daemon] cuDeviceGetProperties() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUdevprop prop;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDeviceGetProperties( &d2t_msg.prop, t2d_msg_data.dev );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDeviceGetProperties() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDevicePrimaryCtxGetState ( void )
{
  hfinf( "[daemon] cuDevicePrimaryCtxGetState() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    unsigned int flags;
    int active;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDevicePrimaryCtxGetState( t2d_msg_data.dev, &d2t_msg.flags, &d2t_msg.active );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDevicePrimaryCtxGetState() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDevicePrimaryCtxRelease ( void )
{
  hfinf( "[daemon] cuDevicePrimaryCtxRelease() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDevicePrimaryCtxRelease( t2d_msg_data.dev );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDevicePrimaryCtxRelease() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDevicePrimaryCtxReset ( void )
{
  hfinf( "[daemon] cuDevicePrimaryCtxReset() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDevicePrimaryCtxReset( t2d_msg_data.dev );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDevicePrimaryCtxReset() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDevicePrimaryCtxRetain ( void )
{
  hfinf( "[daemon] cuDevicePrimaryCtxRetain() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUcontext pctx;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDevicePrimaryCtxRetain( &d2t_msg.pctx, t2d_msg_data.dev );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDevicePrimaryCtxRetain() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDevicePrimaryCtxSetFlags ( void )
{
  hfinf( "[daemon] cuDevicePrimaryCtxSetFlags() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUdevice dev;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDevicePrimaryCtxSetFlags( t2d_msg_data.dev, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDevicePrimaryCtxSetFlags() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuDriverGetVersion ( void )
{
  hfinf( "[daemon] cuDriverGetVersion() [CALL]\n" );
  
  struct {
    CUresult ____RETVAL;
    int driverVersion;
  } d2t_msg;
  d2t_msg.____RETVAL = cuDriverGetVersion( &d2t_msg.driverVersion );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuDriverGetVersion() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuEventCreate ( void )
{
  hfinf( "[daemon] cuEventCreate() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int Flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUevent phEvent;
  } d2t_msg;
  d2t_msg.____RETVAL = cuEventCreate( &d2t_msg.phEvent, t2d_msg_data.Flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuEventCreate() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuEventDestroy_v2 ( void )
{
  hfinf( "[daemon] cuEventDestroy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUevent hEvent;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuEventDestroy_v2( t2d_msg_data.hEvent );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuEventDestroy_v2() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuEventElapsedTime ( void )
{
  hfinf( "[daemon] cuEventElapsedTime() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUevent hStart;
    CUevent hEnd;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    float pMilliseconds;
  } d2t_msg;
  d2t_msg.____RETVAL = cuEventElapsedTime( &d2t_msg.pMilliseconds, t2d_msg_data.hStart, t2d_msg_data.hEnd );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuEventElapsedTime() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuEventQuery ( void )
{
  hfinf( "[daemon] cuEventQuery() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUevent hEvent;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuEventQuery( t2d_msg_data.hEvent );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuEventQuery() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuEventRecord ( void )
{
  hfinf( "[daemon] cuEventRecord() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUevent hEvent;
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuEventRecord( t2d_msg_data.hEvent, t2d_msg_data.hStream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuEventRecord() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuEventSynchronize ( void )
{
  hfinf( "[daemon] cuEventSynchronize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUevent hEvent;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuEventSynchronize( t2d_msg_data.hEvent );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuEventSynchronize() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuFuncGetAttribute ( void )
{
  hfinf( "[daemon] cuFuncGetAttribute() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction_attribute attrib;
    CUfunction hfunc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    int pi;
  } d2t_msg;
  d2t_msg.____RETVAL = cuFuncGetAttribute( &d2t_msg.pi, t2d_msg_data.attrib, t2d_msg_data.hfunc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuFuncGetAttribute() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuFuncSetAttribute ( void )
{
  hfinf( "[daemon] cuFuncSetAttribute() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    CUfunction_attribute attrib;
    int value;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuFuncSetAttribute( t2d_msg_data.hfunc, t2d_msg_data.attrib, t2d_msg_data.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuFuncSetAttribute() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuFuncSetBlockShape ( void )
{
  hfinf( "[daemon] cuFuncSetBlockShape() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    int x;
    int y;
    int z;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuFuncSetBlockShape( t2d_msg_data.hfunc, t2d_msg_data.x, t2d_msg_data.y, t2d_msg_data.z );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuFuncSetBlockShape() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuFuncSetCacheConfig ( void )
{
  hfinf( "[daemon] cuFuncSetCacheConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    CUfunc_cache config;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuFuncSetCacheConfig( t2d_msg_data.hfunc, t2d_msg_data.config );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuFuncSetCacheConfig() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuFuncSetSharedMemConfig ( void )
{
  hfinf( "[daemon] cuFuncSetSharedMemConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    CUsharedconfig config;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuFuncSetSharedMemConfig( t2d_msg_data.hfunc, t2d_msg_data.config );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuFuncSetSharedMemConfig() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuFuncSetSharedSize ( void )
{
  hfinf( "[daemon] cuFuncSetSharedSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    unsigned int bytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuFuncSetSharedSize( t2d_msg_data.hfunc, t2d_msg_data.bytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuFuncSetSharedSize() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuLaunch ( void )
{
  hfinf( "[daemon] cuLaunch() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction f;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuLaunch( t2d_msg_data.f );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuLaunch() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuLaunchGrid ( void )
{
  hfinf( "[daemon] cuLaunchGrid() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction f;
    int grid_width;
    int grid_height;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuLaunchGrid( t2d_msg_data.f, t2d_msg_data.grid_width, t2d_msg_data.grid_height );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuLaunchGrid() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuLaunchGridAsync ( void )
{
  hfinf( "[daemon] cuLaunchGridAsync() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction f;
    int grid_width;
    int grid_height;
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuLaunchGridAsync( t2d_msg_data.f, t2d_msg_data.grid_width, t2d_msg_data.grid_height, t2d_msg_data.hStream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuLaunchGridAsync() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuParamSetSize ( void )
{
  hfinf( "[daemon] cuParamSetSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    unsigned int numbytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuParamSetSize( t2d_msg_data.hfunc, t2d_msg_data.numbytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuParamSetSize() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuParamSetTexRef ( void )
{
  hfinf( "[daemon] cuParamSetTexRef() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    int texunit;
    CUtexref hTexRef;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuParamSetTexRef( t2d_msg_data.hfunc, t2d_msg_data.texunit, t2d_msg_data.hTexRef );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuParamSetTexRef() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuParamSetf ( void )
{
  hfinf( "[daemon] cuParamSetf() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    int offset;
    float value;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuParamSetf( t2d_msg_data.hfunc, t2d_msg_data.offset, t2d_msg_data.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuParamSetf() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuParamSeti ( void )
{
  hfinf( "[daemon] cuParamSeti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUfunction hfunc;
    int offset;
    unsigned int value;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuParamSeti( t2d_msg_data.hfunc, t2d_msg_data.offset, t2d_msg_data.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuParamSeti() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamAttachMemAsync ( void )
{
  hfinf( "[daemon] cuStreamAttachMemAsync() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
    CUdeviceptr dptr;
    size_t length;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamAttachMemAsync( t2d_msg_data.hStream, t2d_msg_data.dptr, t2d_msg_data.length, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamAttachMemAsync() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamCreate ( void )
{
  hfinf( "[daemon] cuStreamCreate() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int Flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUstream phStream;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamCreate( &d2t_msg.phStream, t2d_msg_data.Flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamCreate() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamCreateWithPriority ( void )
{
  hfinf( "[daemon] cuStreamCreateWithPriority() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
    int priority;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    CUstream phStream;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamCreateWithPriority( &d2t_msg.phStream, t2d_msg_data.flags, t2d_msg_data.priority );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamCreateWithPriority() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamDestroy_v2 ( void )
{
  hfinf( "[daemon] cuStreamDestroy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamDestroy_v2( t2d_msg_data.hStream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamDestroy_v2() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamGetFlags ( void )
{
  hfinf( "[daemon] cuStreamGetFlags() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    unsigned int flags;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamGetFlags( t2d_msg_data.hStream, &d2t_msg.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamGetFlags() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamGetPriority ( void )
{
  hfinf( "[daemon] cuStreamGetPriority() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
    int priority;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamGetPriority( t2d_msg_data.hStream, &d2t_msg.priority );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamGetPriority() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamQuery ( void )
{
  hfinf( "[daemon] cuStreamQuery() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamQuery( t2d_msg_data.hStream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamQuery() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamSynchronize ( void )
{
  hfinf( "[daemon] cuStreamSynchronize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamSynchronize( t2d_msg_data.hStream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamSynchronize() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamWaitEvent ( void )
{
  hfinf( "[daemon] cuStreamWaitEvent() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream hStream;
    CUevent hEvent;
    unsigned int Flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamWaitEvent( t2d_msg_data.hStream, t2d_msg_data.hEvent, t2d_msg_data.Flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamWaitEvent() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamWaitValue32 ( void )
{
  hfinf( "[daemon] cuStreamWaitValue32() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream stream;
    CUdeviceptr addr;
    cuuint32_t value;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamWaitValue32( t2d_msg_data.stream, t2d_msg_data.addr, t2d_msg_data.value, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamWaitValue32() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamWaitValue64 ( void )
{
  hfinf( "[daemon] cuStreamWaitValue64() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream stream;
    CUdeviceptr addr;
    cuuint64_t value;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamWaitValue64( t2d_msg_data.stream, t2d_msg_data.addr, t2d_msg_data.value, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamWaitValue64() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamWriteValue32 ( void )
{
  hfinf( "[daemon] cuStreamWriteValue32() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream stream;
    CUdeviceptr addr;
    cuuint32_t value;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamWriteValue32( t2d_msg_data.stream, t2d_msg_data.addr, t2d_msg_data.value, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamWriteValue32() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cuStreamWriteValue64 ( void )
{
  hfinf( "[daemon] cuStreamWriteValue64() [CALL]\n" );
  
  struct __attribute__((packed)) {
    CUstream stream;
    CUdeviceptr addr;
    cuuint64_t value;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    CUresult ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cuStreamWriteValue64( t2d_msg_data.stream, t2d_msg_data.addr, t2d_msg_data.value, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cuStreamWriteValue64() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasAxpyEx ( void )
{
  hfinf( "[daemon] cublasAxpyEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    cudaDataType alphaType;
    const void * x;
    cudaDataType xType;
    int incx;
    void * y;
    cudaDataType yType;
    int incy;
    cudaDataType executiontype;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasAxpyEx( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.alphaType, t2d_msg_data.x, t2d_msg_data.xType, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.yType, t2d_msg_data.incy, t2d_msg_data.executiontype );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasAxpyEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCaxpy_v2 ( void )
{
  hfinf( "[daemon] cublasCaxpy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCaxpy_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCaxpy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCcopy_v2 ( void )
{
  hfinf( "[daemon] cublasCcopy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCcopy_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCcopy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCdgmm ( void )
{
  hfinf( "[daemon] cublasCdgmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasSideMode_t mode;
    int m;
    int n;
    const cuComplex * A;
    int lda;
    const cuComplex * x;
    int incx;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCdgmm( t2d_msg_data.handle, t2d_msg_data.mode, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCdgmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCdotc_v2 ( void )
{
  hfinf( "[daemon] cublasCdotc_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cuComplex result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCdotc_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCdotc_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCdotu_v2 ( void )
{
  hfinf( "[daemon] cublasCdotu_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cuComplex result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCdotu_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCdotu_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgbmv_v2 ( void )
{
  hfinf( "[daemon] cublasCgbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int kl;
    int ku;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgbmv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.kl, t2d_msg_data.ku, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgeam ( void )
{
  hfinf( "[daemon] cublasCgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    const cuComplex * B;
    int ldb;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgeam( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgelsBatched ( void )
{
  hfinf( "[daemon] cublasCgelsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int nrhs;
    cuComplex ** Aarray ;
    int lda;
    cuComplex ** Carray ;
    int ldc;
    int * devInfoArray;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgelsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Carray, t2d_msg_data.ldc, &d2t_msg.info, t2d_msg_data.devInfoArray, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgelsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgemm3mStridedBatched ( void )
{
  hfinf( "[daemon] cublasCgemm3mStridedBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    long long strideA;
    const cuComplex * B;
    int ldb;
    long long strideB;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
    long long strideC;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgemm3mStridedBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.strideA, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.strideB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.strideC, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgemm3mStridedBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgemmBatched ( void )
{
  hfinf( "[daemon] cublasCgemmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex ** Aarray ;
    int lda;
    const cuComplex ** Barray ;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex ** Carray ;
    int ldc;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgemmBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Barray, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.Carray, t2d_msg_data.ldc, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgemmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgemmEx ( void )
{
  hfinf( "[daemon] cublasCgemmEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    const void * B;
    cudaDataType Btype;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgemmEx( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.Btype, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgemmEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgemmStridedBatched ( void )
{
  hfinf( "[daemon] cublasCgemmStridedBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    long long strideA;
    const cuComplex * B;
    int ldb;
    long long strideB;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
    long long strideC;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgemmStridedBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.strideA, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.strideB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.strideC, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgemmStridedBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgemm_v2 ( void )
{
  hfinf( "[daemon] cublasCgemm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgemm_v2( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgemm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgemv_v2 ( void )
{
  hfinf( "[daemon] cublasCgemv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgemv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgemv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgeqrfBatched ( void )
{
  hfinf( "[daemon] cublasCgeqrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int m;
    int n;
    cuComplex ** Aarray ;
    int lda;
    cuComplex ** TauArray ;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgeqrfBatched( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.TauArray, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgeqrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgerc_v2 ( void )
{
  hfinf( "[daemon] cublasCgerc_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgerc_v2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgerc_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgeru_v2 ( void )
{
  hfinf( "[daemon] cublasCgeru_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgeru_v2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgeru_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgetrfBatched ( void )
{
  hfinf( "[daemon] cublasCgetrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    cuComplex ** A ;
    int lda;
    int * P;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgetrfBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgetrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgetriBatched ( void )
{
  hfinf( "[daemon] cublasCgetriBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const cuComplex ** A ;
    int lda;
    const int * P;
    cuComplex ** C ;
    int ldc;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgetriBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgetriBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCgetrsBatched ( void )
{
  hfinf( "[daemon] cublasCgetrsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int n;
    int nrhs;
    const cuComplex ** Aarray ;
    int lda;
    const int * devIpiv;
    cuComplex ** Barray ;
    int ldb;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCgetrsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.devIpiv, t2d_msg_data.Barray, t2d_msg_data.ldb, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCgetrsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasChbmv_v2 ( void )
{
  hfinf( "[daemon] cublasChbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasChbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasChbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasChemm_v2 ( void )
{
  hfinf( "[daemon] cublasChemm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasChemm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasChemm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasChemv_v2 ( void )
{
  hfinf( "[daemon] cublasChemv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasChemv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasChemv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCher2_v2 ( void )
{
  hfinf( "[daemon] cublasCher2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCher2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCher2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCher2k_v2 ( void )
{
  hfinf( "[daemon] cublasCher2k_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCher2k_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCher2k_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCher_v2 ( void )
{
  hfinf( "[daemon] cublasCher_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCher_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCher_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCherk3mEx ( void )
{
  hfinf( "[daemon] cublasCherk3mEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCherk3mEx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCherk3mEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCherkEx ( void )
{
  hfinf( "[daemon] cublasCherkEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCherkEx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCherkEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCherk_v2 ( void )
{
  hfinf( "[daemon] cublasCherk_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCherk_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCherk_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCherkx ( void )
{
  hfinf( "[daemon] cublasCherkx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCherkx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCherkx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasChpmv_v2 ( void )
{
  hfinf( "[daemon] cublasChpmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * AP;
    const cuComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasChpmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasChpmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasChpr2_v2 ( void )
{
  hfinf( "[daemon] cublasChpr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasChpr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasChpr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasChpr_v2 ( void )
{
  hfinf( "[daemon] cublasChpr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    cuComplex * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasChpr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasChpr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCmatinvBatched ( void )
{
  hfinf( "[daemon] cublasCmatinvBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const cuComplex ** A ;
    int lda;
    cuComplex ** Ainv ;
    int lda_inv;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCmatinvBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.Ainv, t2d_msg_data.lda_inv, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCmatinvBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCreate_v2 ( void )
{
  hfinf( "[daemon] cublasCreate_v2() [CALL]\n" );
  
  struct {
    cublasStatus_t ____RETVAL;
    cublasHandle_t handle;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCreate_v2( &d2t_msg.handle );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCreate_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCrot_v2 ( void )
{
  hfinf( "[daemon] cublasCrot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    cuComplex * x;
    int incx;
    cuComplex * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } c;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCrot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.c.val : t2d_msg_data.c.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.s.val : t2d_msg_data.s.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCrot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCrotg_v2 ( void )
{
  hfinf( "[daemon] cublasCrotg_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(cuComplex *) : 0];
        cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(cuComplex *) > sizeof(cuComplex) ? sizeof(cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } a;
    union {
      struct {
        char ___dummy0[sizeof(cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(cuComplex *) : 0];
        cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(cuComplex *) > sizeof(cuComplex) ? sizeof(cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } b;
    float * c;
    cuComplex * s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cuComplex a;
    cuComplex b;
    float c;
    cuComplex s;
  } d2t_msg;
  d2t_msg.a = t2d_msg_data.a.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.b = t2d_msg_data.b.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.____RETVAL = cublasCrotg_v2( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.a : t2d_msg_data.a.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.b : t2d_msg_data.b.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &d2t_msg.c : t2d_msg_data.c), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &d2t_msg.s : t2d_msg_data.s) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCrotg_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCscal_v2 ( void )
{
  hfinf( "[daemon] cublasCscal_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCscal_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCscal_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsrot_v2 ( void )
{
  hfinf( "[daemon] cublasCsrot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    cuComplex * x;
    int incx;
    cuComplex * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } c;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsrot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.c.val : t2d_msg_data.c.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.s.val : t2d_msg_data.s.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsrot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsscal_v2 ( void )
{
  hfinf( "[daemon] cublasCsscal_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsscal_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsscal_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCswap_v2 ( void )
{
  hfinf( "[daemon] cublasCswap_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    cuComplex * x;
    int incx;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCswap_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCswap_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsymm_v2 ( void )
{
  hfinf( "[daemon] cublasCsymm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsymm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsymm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsymv_v2 ( void )
{
  hfinf( "[daemon] cublasCsymv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsymv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsymv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyr2_v2 ( void )
{
  hfinf( "[daemon] cublasCsyr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    const cuComplex * y;
    int incy;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyr2k_v2 ( void )
{
  hfinf( "[daemon] cublasCsyr2k_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyr2k_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyr2k_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyr_v2 ( void )
{
  hfinf( "[daemon] cublasCsyr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * x;
    int incx;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyrk3mEx ( void )
{
  hfinf( "[daemon] cublasCsyrk3mEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyrk3mEx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyrk3mEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyrkEx ( void )
{
  hfinf( "[daemon] cublasCsyrkEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyrkEx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyrkEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyrk_v2 ( void )
{
  hfinf( "[daemon] cublasCsyrk_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyrk_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyrk_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCsyrkx ( void )
{
  hfinf( "[daemon] cublasCsyrkx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCsyrkx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCsyrkx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtbmv_v2 ( void )
{
  hfinf( "[daemon] cublasCtbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const cuComplex * A;
    int lda;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtbsv_v2 ( void )
{
  hfinf( "[daemon] cublasCtbsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const cuComplex * A;
    int lda;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtbsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtbsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtpmv_v2 ( void )
{
  hfinf( "[daemon] cublasCtpmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuComplex * AP;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtpmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtpmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtpsv_v2 ( void )
{
  hfinf( "[daemon] cublasCtpsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuComplex * AP;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtpsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtpsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtpttr ( void )
{
  hfinf( "[daemon] cublasCtpttr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const cuComplex * AP;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtpttr( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtpttr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtrmm_v2 ( void )
{
  hfinf( "[daemon] cublasCtrmm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * B;
    int ldb;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtrmm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtrmm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtrmv_v2 ( void )
{
  hfinf( "[daemon] cublasCtrmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuComplex * A;
    int lda;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtrmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtrmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtrsmBatched ( void )
{
  hfinf( "[daemon] cublasCtrsmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex ** A ;
    int lda;
    cuComplex ** B ;
    int ldb;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtrsmBatched( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtrsmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtrsm_v2 ( void )
{
  hfinf( "[daemon] cublasCtrsm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    cuComplex * B;
    int ldb;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtrsm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtrsm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtrsv_v2 ( void )
{
  hfinf( "[daemon] cublasCtrsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuComplex * A;
    int lda;
    cuComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtrsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtrsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasCtrttp ( void )
{
  hfinf( "[daemon] cublasCtrttp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const cuComplex * A;
    int lda;
    cuComplex * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasCtrttp( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasCtrttp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDasum_v2 ( void )
{
  hfinf( "[daemon] cublasDasum_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const double * x;
    int incx;
    double * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDasum_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDasum_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDaxpy_v2 ( void )
{
  hfinf( "[daemon] cublasDaxpy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * x;
    int incx;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDaxpy_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDaxpy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDcopy_v2 ( void )
{
  hfinf( "[daemon] cublasDcopy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const double * x;
    int incx;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDcopy_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDcopy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDdgmm ( void )
{
  hfinf( "[daemon] cublasDdgmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasSideMode_t mode;
    int m;
    int n;
    const double * A;
    int lda;
    const double * x;
    int incx;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDdgmm( t2d_msg_data.handle, t2d_msg_data.mode, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDdgmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDdot_v2 ( void )
{
  hfinf( "[daemon] cublasDdot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const double * x;
    int incx;
    const double * y;
    int incy;
    double * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDdot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDdot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDestroy_v2 ( void )
{
  hfinf( "[daemon] cublasDestroy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDestroy_v2( t2d_msg_data.handle );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDestroy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgbmv_v2 ( void )
{
  hfinf( "[daemon] cublasDgbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int kl;
    int ku;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgbmv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.kl, t2d_msg_data.ku, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgeam ( void )
{
  hfinf( "[daemon] cublasDgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    const double * B;
    int ldb;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgeam( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgelsBatched ( void )
{
  hfinf( "[daemon] cublasDgelsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int nrhs;
    double ** Aarray ;
    int lda;
    double ** Carray ;
    int ldc;
    int * devInfoArray;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgelsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Carray, t2d_msg_data.ldc, &d2t_msg.info, t2d_msg_data.devInfoArray, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgelsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgemmBatched ( void )
{
  hfinf( "[daemon] cublasDgemmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double ** Aarray ;
    int lda;
    const double ** Barray ;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double ** Carray ;
    int ldc;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgemmBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Barray, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.Carray, t2d_msg_data.ldc, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgemmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgemmStridedBatched ( void )
{
  hfinf( "[daemon] cublasDgemmStridedBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    long long strideA;
    const double * B;
    int ldb;
    long long strideB;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
    long long strideC;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgemmStridedBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.strideA, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.strideB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.strideC, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgemmStridedBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgemm_v2 ( void )
{
  hfinf( "[daemon] cublasDgemm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgemm_v2( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgemm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgemv_v2 ( void )
{
  hfinf( "[daemon] cublasDgemv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgemv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgemv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgeqrfBatched ( void )
{
  hfinf( "[daemon] cublasDgeqrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int m;
    int n;
    double ** Aarray ;
    int lda;
    double ** TauArray ;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgeqrfBatched( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.TauArray, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgeqrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDger_v2 ( void )
{
  hfinf( "[daemon] cublasDger_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * x;
    int incx;
    const double * y;
    int incy;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDger_v2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDger_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgetrfBatched ( void )
{
  hfinf( "[daemon] cublasDgetrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    double ** A ;
    int lda;
    int * P;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgetrfBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgetrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgetriBatched ( void )
{
  hfinf( "[daemon] cublasDgetriBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const double ** A ;
    int lda;
    const int * P;
    double ** C ;
    int ldc;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgetriBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgetriBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDgetrsBatched ( void )
{
  hfinf( "[daemon] cublasDgetrsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int n;
    int nrhs;
    const double ** Aarray ;
    int lda;
    const int * devIpiv;
    double ** Barray ;
    int ldb;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDgetrsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.devIpiv, t2d_msg_data.Barray, t2d_msg_data.ldb, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDgetrsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDmatinvBatched ( void )
{
  hfinf( "[daemon] cublasDmatinvBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const double ** A ;
    int lda;
    double ** Ainv ;
    int lda_inv;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDmatinvBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.Ainv, t2d_msg_data.lda_inv, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDmatinvBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDnrm2_v2 ( void )
{
  hfinf( "[daemon] cublasDnrm2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const double * x;
    int incx;
    double * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDnrm2_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDnrm2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDrot_v2 ( void )
{
  hfinf( "[daemon] cublasDrot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    double * x;
    int incx;
    double * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } c;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDrot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.c.val : t2d_msg_data.c.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.s.val : t2d_msg_data.s.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDrot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDrotg_v2 ( void )
{
  hfinf( "[daemon] cublasDrotg_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(double *) < sizeof(double) ? sizeof(double)-sizeof(double *) : 0];
        double * ptr;
      };
      struct {
        char ___dummy1[sizeof(double *) > sizeof(double) ? sizeof(double *)-sizeof(double) : 0];
        double val;
      };
    } a;
    union {
      struct {
        char ___dummy0[sizeof(double *) < sizeof(double) ? sizeof(double)-sizeof(double *) : 0];
        double * ptr;
      };
      struct {
        char ___dummy1[sizeof(double *) > sizeof(double) ? sizeof(double *)-sizeof(double) : 0];
        double val;
      };
    } b;
    double * c;
    double * s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double a;
    double b;
    double c;
    double s;
  } d2t_msg;
  d2t_msg.a = t2d_msg_data.a.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.b = t2d_msg_data.b.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.____RETVAL = cublasDrotg_v2( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.a : t2d_msg_data.a.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.b : t2d_msg_data.b.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &d2t_msg.c : t2d_msg_data.c), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &d2t_msg.s : t2d_msg_data.s) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDrotg_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDrotm_v2 ( void )
{
  hfinf( "[daemon] cublasDrotm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    double * x;
    int incx;
    double * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } param;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDrotm_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.param.val : t2d_msg_data.param.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDrotm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDrotmg_v2 ( void )
{
  hfinf( "[daemon] cublasDrotmg_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(double *) < sizeof(double) ? sizeof(double)-sizeof(double *) : 0];
        double * ptr;
      };
      struct {
        char ___dummy1[sizeof(double *) > sizeof(double) ? sizeof(double *)-sizeof(double) : 0];
        double val;
      };
    } d1;
    union {
      struct {
        char ___dummy0[sizeof(double *) < sizeof(double) ? sizeof(double)-sizeof(double *) : 0];
        double * ptr;
      };
      struct {
        char ___dummy1[sizeof(double *) > sizeof(double) ? sizeof(double *)-sizeof(double) : 0];
        double val;
      };
    } d2;
    union {
      struct {
        char ___dummy0[sizeof(double *) < sizeof(double) ? sizeof(double)-sizeof(double *) : 0];
        double * ptr;
      };
      struct {
        char ___dummy1[sizeof(double *) > sizeof(double) ? sizeof(double *)-sizeof(double) : 0];
        double val;
      };
    } x1;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } y1;
    double * param;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double d1;
    double d2;
    double x1;
    double param[5];
  } d2t_msg;
  d2t_msg.d1 = t2d_msg_data.d1.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.d2 = t2d_msg_data.d2.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.x1 = t2d_msg_data.x1.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.____RETVAL = cublasDrotmg_v2( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.d1 : t2d_msg_data.d1.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.d2 : t2d_msg_data.d2.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &d2t_msg.x1 : t2d_msg_data.x1.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &t2d_msg_data.y1.val : t2d_msg_data.y1.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 4) & 0x1) ? d2t_msg.param : t2d_msg_data.param) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDrotmg_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsbmv_v2 ( void )
{
  hfinf( "[daemon] cublasDsbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDscal_v2 ( void )
{
  hfinf( "[daemon] cublasDscal_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDscal_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDscal_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDspmv_v2 ( void )
{
  hfinf( "[daemon] cublasDspmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * AP;
    const double * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDspmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDspmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDspr2_v2 ( void )
{
  hfinf( "[daemon] cublasDspr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * x;
    int incx;
    const double * y;
    int incy;
    double * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDspr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDspr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDspr_v2 ( void )
{
  hfinf( "[daemon] cublasDspr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * x;
    int incx;
    double * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDspr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDspr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDswap_v2 ( void )
{
  hfinf( "[daemon] cublasDswap_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    double * x;
    int incx;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDswap_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDswap_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsymm_v2 ( void )
{
  hfinf( "[daemon] cublasDsymm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsymm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsymm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsymv_v2 ( void )
{
  hfinf( "[daemon] cublasDsymv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsymv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsymv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsyr2_v2 ( void )
{
  hfinf( "[daemon] cublasDsyr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * x;
    int incx;
    const double * y;
    int incy;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsyr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsyr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsyr2k_v2 ( void )
{
  hfinf( "[daemon] cublasDsyr2k_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsyr2k_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsyr2k_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsyr_v2 ( void )
{
  hfinf( "[daemon] cublasDsyr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * x;
    int incx;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsyr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsyr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsyrk_v2 ( void )
{
  hfinf( "[daemon] cublasDsyrk_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsyrk_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsyrk_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDsyrkx ( void )
{
  hfinf( "[daemon] cublasDsyrkx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDsyrkx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDsyrkx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtbmv_v2 ( void )
{
  hfinf( "[daemon] cublasDtbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const double * A;
    int lda;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtbsv_v2 ( void )
{
  hfinf( "[daemon] cublasDtbsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const double * A;
    int lda;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtbsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtbsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtpmv_v2 ( void )
{
  hfinf( "[daemon] cublasDtpmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const double * AP;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtpmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtpmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtpsv_v2 ( void )
{
  hfinf( "[daemon] cublasDtpsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const double * AP;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtpsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtpsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtpttr ( void )
{
  hfinf( "[daemon] cublasDtpttr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const double * AP;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtpttr( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtpttr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtrmm_v2 ( void )
{
  hfinf( "[daemon] cublasDtrmm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * B;
    int ldb;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtrmm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtrmm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtrmv_v2 ( void )
{
  hfinf( "[daemon] cublasDtrmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const double * A;
    int lda;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtrmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtrmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtrsmBatched ( void )
{
  hfinf( "[daemon] cublasDtrsmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double ** A ;
    int lda;
    double ** B ;
    int ldb;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtrsmBatched( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtrsmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtrsm_v2 ( void )
{
  hfinf( "[daemon] cublasDtrsm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    double * B;
    int ldb;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtrsm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtrsm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtrsv_v2 ( void )
{
  hfinf( "[daemon] cublasDtrsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const double * A;
    int lda;
    double * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtrsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtrsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDtrttp ( void )
{
  hfinf( "[daemon] cublasDtrttp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const double * A;
    int lda;
    double * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDtrttp( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDtrttp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDzasum_v2 ( void )
{
  hfinf( "[daemon] cublasDzasum_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    double * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDzasum_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDzasum_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasDznrm2_v2 ( void )
{
  hfinf( "[daemon] cublasDznrm2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    double * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    double result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasDznrm2_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasDznrm2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGemmBatchedEx ( void )
{
  hfinf( "[daemon] cublasGemmBatchedEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    const void ** Aarray ;
    cudaDataType Atype;
    int lda;
    const void ** Barray ;
    cudaDataType Btype;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } beta;
    void ** Carray ;
    cudaDataType Ctype;
    int ldc;
    int batchCount;
    cudaDataType computeType;
    cublasGemmAlgo_t algo;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGemmBatchedEx( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.Aarray, t2d_msg_data.Atype, t2d_msg_data.lda, t2d_msg_data.Barray, t2d_msg_data.Btype, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val[0] : t2d_msg_data.beta.ptr), t2d_msg_data.Carray, t2d_msg_data.Ctype, t2d_msg_data.ldc, t2d_msg_data.batchCount, t2d_msg_data.computeType, t2d_msg_data.algo );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGemmBatchedEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGemmEx ( void )
{
  hfinf( "[daemon] cublasGemmEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    const void * B;
    cudaDataType Btype;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
    cudaDataType computeType;
    cublasGemmAlgo_t algo;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGemmEx( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.Btype, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val[0] : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc, t2d_msg_data.computeType, t2d_msg_data.algo );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGemmEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGemmStridedBatchedEx ( void )
{
  hfinf( "[daemon] cublasGemmStridedBatchedEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    long long strideA;
    const void * B;
    cudaDataType Btype;
    int ldb;
    long long strideB;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
    long long strideC;
    int batchCount;
    cudaDataType computeType;
    cublasGemmAlgo_t algo;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGemmStridedBatchedEx( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, t2d_msg_data.strideA, t2d_msg_data.B, t2d_msg_data.Btype, t2d_msg_data.ldb, t2d_msg_data.strideB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val[0] : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc, t2d_msg_data.strideC, t2d_msg_data.batchCount, t2d_msg_data.computeType, t2d_msg_data.algo );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGemmStridedBatchedEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGetAtomicsMode ( void )
{
  hfinf( "[daemon] cublasGetAtomicsMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cublasAtomicsMode_t mode;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGetAtomicsMode( t2d_msg_data.handle, &d2t_msg.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGetAtomicsMode() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGetMathMode ( void )
{
  hfinf( "[daemon] cublasGetMathMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cublasMath_t mode;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGetMathMode( t2d_msg_data.handle, &d2t_msg.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGetMathMode() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGetProperty ( void )
{
  hfinf( "[daemon] cublasGetProperty() [CALL]\n" );
  
  struct __attribute__((packed)) {
    libraryPropertyType type;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int value;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGetProperty( t2d_msg_data.type, &d2t_msg.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGetProperty() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGetStream_v2 ( void )
{
  hfinf( "[daemon] cublasGetStream_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cudaStream_t streamId;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGetStream_v2( t2d_msg_data.handle, &d2t_msg.streamId );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGetStream_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasGetVersion_v2 ( void )
{
  hfinf( "[daemon] cublasGetVersion_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int version;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasGetVersion_v2( t2d_msg_data.handle, &d2t_msg.version );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasGetVersion_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIcamax_v2 ( void )
{
  hfinf( "[daemon] cublasIcamax_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIcamax_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIcamax_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIcamin_v2 ( void )
{
  hfinf( "[daemon] cublasIcamin_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIcamin_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIcamin_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIdamax_v2 ( void )
{
  hfinf( "[daemon] cublasIdamax_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const double * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIdamax_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIdamax_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIdamin_v2 ( void )
{
  hfinf( "[daemon] cublasIdamin_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const double * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIdamin_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIdamin_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIsamax_v2 ( void )
{
  hfinf( "[daemon] cublasIsamax_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const float * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIsamax_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIsamax_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIsamin_v2 ( void )
{
  hfinf( "[daemon] cublasIsamin_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const float * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIsamin_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIsamin_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIzamax_v2 ( void )
{
  hfinf( "[daemon] cublasIzamax_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIzamax_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIzamax_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasIzamin_v2 ( void )
{
  hfinf( "[daemon] cublasIzamin_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    int * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasIzamin_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasIzamin_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSasum_v2 ( void )
{
  hfinf( "[daemon] cublasSasum_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const float * x;
    int incx;
    float * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSasum_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSasum_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSaxpy_v2 ( void )
{
  hfinf( "[daemon] cublasSaxpy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * x;
    int incx;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSaxpy_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSaxpy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasScalEx ( void )
{
  hfinf( "[daemon] cublasScalEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    cudaDataType alphaType;
    void * x;
    cudaDataType xType;
    int incx;
    cudaDataType executionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasScalEx( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.alphaType, t2d_msg_data.x, t2d_msg_data.xType, t2d_msg_data.incx, t2d_msg_data.executionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasScalEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasScasum_v2 ( void )
{
  hfinf( "[daemon] cublasScasum_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    float * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasScasum_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasScasum_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasScnrm2_v2 ( void )
{
  hfinf( "[daemon] cublasScnrm2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuComplex * x;
    int incx;
    float * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasScnrm2_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasScnrm2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasScopy_v2 ( void )
{
  hfinf( "[daemon] cublasScopy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const float * x;
    int incx;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasScopy_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasScopy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSdgmm ( void )
{
  hfinf( "[daemon] cublasSdgmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasSideMode_t mode;
    int m;
    int n;
    const float * A;
    int lda;
    const float * x;
    int incx;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSdgmm( t2d_msg_data.handle, t2d_msg_data.mode, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSdgmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSdot_v2 ( void )
{
  hfinf( "[daemon] cublasSdot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const float * x;
    int incx;
    const float * y;
    int incy;
    float * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSdot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSdot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSetAtomicsMode ( void )
{
  hfinf( "[daemon] cublasSetAtomicsMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasAtomicsMode_t mode;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSetAtomicsMode( t2d_msg_data.handle, t2d_msg_data.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSetAtomicsMode() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSetMathMode ( void )
{
  hfinf( "[daemon] cublasSetMathMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasMath_t mode;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSetMathMode( t2d_msg_data.handle, t2d_msg_data.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSetMathMode() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSetStream_v2 ( void )
{
  hfinf( "[daemon] cublasSetStream_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cudaStream_t streamId;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSetStream_v2( t2d_msg_data.handle, t2d_msg_data.streamId );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSetStream_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgbmv_v2 ( void )
{
  hfinf( "[daemon] cublasSgbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int kl;
    int ku;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgbmv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.kl, t2d_msg_data.ku, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgeam ( void )
{
  hfinf( "[daemon] cublasSgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    const float * B;
    int ldb;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgeam( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgelsBatched ( void )
{
  hfinf( "[daemon] cublasSgelsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int nrhs;
    float ** Aarray ;
    int lda;
    float ** Carray ;
    int ldc;
    int * devInfoArray;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgelsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Carray, t2d_msg_data.ldc, &d2t_msg.info, t2d_msg_data.devInfoArray, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgelsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgemmBatched ( void )
{
  hfinf( "[daemon] cublasSgemmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float ** Aarray ;
    int lda;
    const float ** Barray ;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float ** Carray ;
    int ldc;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgemmBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Barray, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.Carray, t2d_msg_data.ldc, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgemmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgemmEx ( void )
{
  hfinf( "[daemon] cublasSgemmEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const void * A;
    cudaDataType Atype;
    int lda;
    const void * B;
    cudaDataType Btype;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    void * C;
    cudaDataType Ctype;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgemmEx( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.Atype, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.Btype, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.Ctype, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgemmEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgemmStridedBatched ( void )
{
  hfinf( "[daemon] cublasSgemmStridedBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    long long strideA;
    const float * B;
    int ldb;
    long long strideB;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
    long long strideC;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgemmStridedBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.strideA, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.strideB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.strideC, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgemmStridedBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgemm_v2 ( void )
{
  hfinf( "[daemon] cublasSgemm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgemm_v2( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgemm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgemv_v2 ( void )
{
  hfinf( "[daemon] cublasSgemv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgemv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgemv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgeqrfBatched ( void )
{
  hfinf( "[daemon] cublasSgeqrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int m;
    int n;
    float ** Aarray ;
    int lda;
    float ** TauArray ;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgeqrfBatched( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.TauArray, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgeqrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSger_v2 ( void )
{
  hfinf( "[daemon] cublasSger_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * x;
    int incx;
    const float * y;
    int incy;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSger_v2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSger_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgetrfBatched ( void )
{
  hfinf( "[daemon] cublasSgetrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    float ** A ;
    int lda;
    int * P;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgetrfBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgetrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgetriBatched ( void )
{
  hfinf( "[daemon] cublasSgetriBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const float ** A ;
    int lda;
    const int * P;
    float ** C ;
    int ldc;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgetriBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgetriBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSgetrsBatched ( void )
{
  hfinf( "[daemon] cublasSgetrsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int n;
    int nrhs;
    const float ** Aarray ;
    int lda;
    const int * devIpiv;
    float ** Barray ;
    int ldb;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSgetrsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.devIpiv, t2d_msg_data.Barray, t2d_msg_data.ldb, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSgetrsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSmatinvBatched ( void )
{
  hfinf( "[daemon] cublasSmatinvBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const float ** A ;
    int lda;
    float ** Ainv ;
    int lda_inv;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSmatinvBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.Ainv, t2d_msg_data.lda_inv, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSmatinvBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSnrm2_v2 ( void )
{
  hfinf( "[daemon] cublasSnrm2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const float * x;
    int incx;
    float * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSnrm2_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSnrm2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSrot_v2 ( void )
{
  hfinf( "[daemon] cublasSrot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    float * x;
    int incx;
    float * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } c;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSrot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.c.val : t2d_msg_data.c.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.s.val : t2d_msg_data.s.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSrot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSrotg_v2 ( void )
{
  hfinf( "[daemon] cublasSrotg_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(float *) < sizeof(float) ? sizeof(float)-sizeof(float *) : 0];
        float * ptr;
      };
      struct {
        char ___dummy1[sizeof(float *) > sizeof(float) ? sizeof(float *)-sizeof(float) : 0];
        float val;
      };
    } a;
    union {
      struct {
        char ___dummy0[sizeof(float *) < sizeof(float) ? sizeof(float)-sizeof(float *) : 0];
        float * ptr;
      };
      struct {
        char ___dummy1[sizeof(float *) > sizeof(float) ? sizeof(float *)-sizeof(float) : 0];
        float val;
      };
    } b;
    float * c;
    float * s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float a;
    float b;
    float c;
    float s;
  } d2t_msg;
  d2t_msg.a = t2d_msg_data.a.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.b = t2d_msg_data.b.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.____RETVAL = cublasSrotg_v2( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.a : t2d_msg_data.a.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.b : t2d_msg_data.b.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &d2t_msg.c : t2d_msg_data.c), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &d2t_msg.s : t2d_msg_data.s) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSrotg_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSrotm_v2 ( void )
{
  hfinf( "[daemon] cublasSrotm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    float * x;
    int incx;
    float * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } param;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSrotm_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.param.val : t2d_msg_data.param.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSrotm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSrotmg_v2 ( void )
{
  hfinf( "[daemon] cublasSrotmg_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(float *) < sizeof(float) ? sizeof(float)-sizeof(float *) : 0];
        float * ptr;
      };
      struct {
        char ___dummy1[sizeof(float *) > sizeof(float) ? sizeof(float *)-sizeof(float) : 0];
        float val;
      };
    } d1;
    union {
      struct {
        char ___dummy0[sizeof(float *) < sizeof(float) ? sizeof(float)-sizeof(float *) : 0];
        float * ptr;
      };
      struct {
        char ___dummy1[sizeof(float *) > sizeof(float) ? sizeof(float *)-sizeof(float) : 0];
        float val;
      };
    } d2;
    union {
      struct {
        char ___dummy0[sizeof(float *) < sizeof(float) ? sizeof(float)-sizeof(float *) : 0];
        float * ptr;
      };
      struct {
        char ___dummy1[sizeof(float *) > sizeof(float) ? sizeof(float *)-sizeof(float) : 0];
        float val;
      };
    } x1;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } y1;
    float * param;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    float d1;
    float d2;
    float x1;
    float param[5];
  } d2t_msg;
  d2t_msg.d1 = t2d_msg_data.d1.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.d2 = t2d_msg_data.d2.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.x1 = t2d_msg_data.x1.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.____RETVAL = cublasSrotmg_v2( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.d1 : t2d_msg_data.d1.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.d2 : t2d_msg_data.d2.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &d2t_msg.x1 : t2d_msg_data.x1.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &t2d_msg_data.y1.val : t2d_msg_data.y1.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 4) & 0x1) ? d2t_msg.param : t2d_msg_data.param) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSrotmg_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsbmv_v2 ( void )
{
  hfinf( "[daemon] cublasSsbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSscal_v2 ( void )
{
  hfinf( "[daemon] cublasSscal_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSscal_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSscal_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSspmv_v2 ( void )
{
  hfinf( "[daemon] cublasSspmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * AP;
    const float * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSspmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSspmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSspr2_v2 ( void )
{
  hfinf( "[daemon] cublasSspr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * x;
    int incx;
    const float * y;
    int incy;
    float * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSspr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSspr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSspr_v2 ( void )
{
  hfinf( "[daemon] cublasSspr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * x;
    int incx;
    float * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSspr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSspr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSswap_v2 ( void )
{
  hfinf( "[daemon] cublasSswap_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    float * x;
    int incx;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSswap_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSswap_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsymm_v2 ( void )
{
  hfinf( "[daemon] cublasSsymm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsymm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsymm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsymv_v2 ( void )
{
  hfinf( "[daemon] cublasSsymv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsymv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsymv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsyr2_v2 ( void )
{
  hfinf( "[daemon] cublasSsyr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * x;
    int incx;
    const float * y;
    int incy;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsyr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsyr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsyr2k_v2 ( void )
{
  hfinf( "[daemon] cublasSsyr2k_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsyr2k_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsyr2k_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsyr_v2 ( void )
{
  hfinf( "[daemon] cublasSsyr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * x;
    int incx;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsyr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsyr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsyrk_v2 ( void )
{
  hfinf( "[daemon] cublasSsyrk_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsyrk_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsyrk_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasSsyrkx ( void )
{
  hfinf( "[daemon] cublasSsyrkx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasSsyrkx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasSsyrkx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStbmv_v2 ( void )
{
  hfinf( "[daemon] cublasStbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const float * A;
    int lda;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStbsv_v2 ( void )
{
  hfinf( "[daemon] cublasStbsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const float * A;
    int lda;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStbsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStbsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStpmv_v2 ( void )
{
  hfinf( "[daemon] cublasStpmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const float * AP;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStpmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStpmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStpsv_v2 ( void )
{
  hfinf( "[daemon] cublasStpsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const float * AP;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStpsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStpsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStpttr ( void )
{
  hfinf( "[daemon] cublasStpttr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const float * AP;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStpttr( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStpttr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStrmm_v2 ( void )
{
  hfinf( "[daemon] cublasStrmm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * B;
    int ldb;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStrmm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStrmm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStrmv_v2 ( void )
{
  hfinf( "[daemon] cublasStrmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const float * A;
    int lda;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStrmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStrmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStrsmBatched ( void )
{
  hfinf( "[daemon] cublasStrsmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float ** A ;
    int lda;
    float ** B ;
    int ldb;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStrsmBatched( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStrsmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStrsm_v2 ( void )
{
  hfinf( "[daemon] cublasStrsm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    float * B;
    int ldb;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStrsm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStrsm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStrsv_v2 ( void )
{
  hfinf( "[daemon] cublasStrsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const float * A;
    int lda;
    float * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStrsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStrsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasStrttp ( void )
{
  hfinf( "[daemon] cublasStrttp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const float * A;
    int lda;
    float * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasStrttp( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasStrttp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZaxpy_v2 ( void )
{
  hfinf( "[daemon] cublasZaxpy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZaxpy_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZaxpy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZcopy_v2 ( void )
{
  hfinf( "[daemon] cublasZcopy_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZcopy_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZcopy_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZdgmm ( void )
{
  hfinf( "[daemon] cublasZdgmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasSideMode_t mode;
    int m;
    int n;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZdgmm( t2d_msg_data.handle, t2d_msg_data.mode, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZdgmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZdotc_v2 ( void )
{
  hfinf( "[daemon] cublasZdotc_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cuDoubleComplex result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZdotc_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZdotc_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZdotu_v2 ( void )
{
  hfinf( "[daemon] cublasZdotu_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * result;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cuDoubleComplex result;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZdotu_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.result : t2d_msg_data.result) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZdotu_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZdrot_v2 ( void )
{
  hfinf( "[daemon] cublasZdrot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } c;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZdrot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.c.val : t2d_msg_data.c.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.s.val : t2d_msg_data.s.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZdrot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZdscal_v2 ( void )
{
  hfinf( "[daemon] cublasZdscal_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZdscal_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZdscal_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgbmv_v2 ( void )
{
  hfinf( "[daemon] cublasZgbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int kl;
    int ku;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgbmv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.kl, t2d_msg_data.ku, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgeam ( void )
{
  hfinf( "[daemon] cublasZgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    const cuDoubleComplex * B;
    int ldb;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgeam( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgelsBatched ( void )
{
  hfinf( "[daemon] cublasZgelsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    int nrhs;
    cuDoubleComplex ** Aarray ;
    int lda;
    cuDoubleComplex ** Carray ;
    int ldc;
    int * devInfoArray;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgelsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Carray, t2d_msg_data.ldc, &d2t_msg.info, t2d_msg_data.devInfoArray, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgelsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgemmBatched ( void )
{
  hfinf( "[daemon] cublasZgemmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex ** Aarray ;
    int lda;
    const cuDoubleComplex ** Barray ;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex ** Carray ;
    int ldc;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgemmBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.Barray, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.Carray, t2d_msg_data.ldc, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgemmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgemmStridedBatched ( void )
{
  hfinf( "[daemon] cublasZgemmStridedBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    long long strideA;
    const cuDoubleComplex * B;
    int ldb;
    long long strideB;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
    long long strideC;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgemmStridedBatched( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.strideA, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.strideB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.strideC, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgemmStridedBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgemm_v2 ( void )
{
  hfinf( "[daemon] cublasZgemm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t transa;
    cublasOperation_t transb;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgemm_v2( t2d_msg_data.handle, t2d_msg_data.transa, t2d_msg_data.transb, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgemm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgemv_v2 ( void )
{
  hfinf( "[daemon] cublasZgemv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasOperation_t trans;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgemv_v2( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgemv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgeqrfBatched ( void )
{
  hfinf( "[daemon] cublasZgeqrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int m;
    int n;
    cuDoubleComplex ** Aarray ;
    int lda;
    cuDoubleComplex ** TauArray ;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgeqrfBatched( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.TauArray, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgeqrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgerc_v2 ( void )
{
  hfinf( "[daemon] cublasZgerc_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgerc_v2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgerc_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgeru_v2 ( void )
{
  hfinf( "[daemon] cublasZgeru_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgeru_v2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgeru_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgetrfBatched ( void )
{
  hfinf( "[daemon] cublasZgetrfBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    cuDoubleComplex ** A ;
    int lda;
    int * P;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgetrfBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgetrfBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgetriBatched ( void )
{
  hfinf( "[daemon] cublasZgetriBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex ** A ;
    int lda;
    const int * P;
    cuDoubleComplex ** C ;
    int ldc;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgetriBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.P, t2d_msg_data.C, t2d_msg_data.ldc, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgetriBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZgetrsBatched ( void )
{
  hfinf( "[daemon] cublasZgetrsBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasOperation_t trans;
    int n;
    int nrhs;
    const cuDoubleComplex ** Aarray ;
    int lda;
    const int * devIpiv;
    cuDoubleComplex ** Barray ;
    int ldb;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    int info;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZgetrsBatched( t2d_msg_data.handle, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.nrhs, t2d_msg_data.Aarray, t2d_msg_data.lda, t2d_msg_data.devIpiv, t2d_msg_data.Barray, t2d_msg_data.ldb, &d2t_msg.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZgetrsBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZhbmv_v2 ( void )
{
  hfinf( "[daemon] cublasZhbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZhbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZhbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZhemm_v2 ( void )
{
  hfinf( "[daemon] cublasZhemm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZhemm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZhemm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZhemv_v2 ( void )
{
  hfinf( "[daemon] cublasZhemv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZhemv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZhemv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZher2_v2 ( void )
{
  hfinf( "[daemon] cublasZher2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZher2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZher2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZher2k_v2 ( void )
{
  hfinf( "[daemon] cublasZher2k_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZher2k_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZher2k_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZher_v2 ( void )
{
  hfinf( "[daemon] cublasZher_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZher_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZher_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZherk_v2 ( void )
{
  hfinf( "[daemon] cublasZherk_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZherk_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZherk_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZherkx ( void )
{
  hfinf( "[daemon] cublasZherkx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZherkx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZherkx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZhpmv_v2 ( void )
{
  hfinf( "[daemon] cublasZhpmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * AP;
    const cuDoubleComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZhpmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZhpmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZhpr2_v2 ( void )
{
  hfinf( "[daemon] cublasZhpr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZhpr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZhpr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZhpr_v2 ( void )
{
  hfinf( "[daemon] cublasZhpr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZhpr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZhpr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZmatinvBatched ( void )
{
  hfinf( "[daemon] cublasZmatinvBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    const cuDoubleComplex ** A ;
    int lda;
    cuDoubleComplex ** Ainv ;
    int lda_inv;
    int * info;
    int batchSize;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZmatinvBatched( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.Ainv, t2d_msg_data.lda_inv, t2d_msg_data.info, t2d_msg_data.batchSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZmatinvBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZrot_v2 ( void )
{
  hfinf( "[daemon] cublasZrot_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * y;
    int incy;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } c;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZrot_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.c.val : t2d_msg_data.c.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.s.val : t2d_msg_data.s.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZrot_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZrotg_v2 ( void )
{
  hfinf( "[daemon] cublasZrotg_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(cuDoubleComplex *) : 0];
        cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } a;
    union {
      struct {
        char ___dummy0[sizeof(cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(cuDoubleComplex *) : 0];
        cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } b;
    double * c;
    cuDoubleComplex * s;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
    cuDoubleComplex a;
    cuDoubleComplex b;
    double c;
    cuDoubleComplex s;
  } d2t_msg;
  d2t_msg.a = t2d_msg_data.a.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.b = t2d_msg_data.b.val; /* need copy in case host-ptr in & out required! */
  d2t_msg.____RETVAL = cublasZrotg_v2( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.a : t2d_msg_data.a.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.b : t2d_msg_data.b.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &d2t_msg.c : t2d_msg_data.c), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &d2t_msg.s : t2d_msg_data.s) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZrotg_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZscal_v2 ( void )
{
  hfinf( "[daemon] cublasZscal_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZscal_v2( t2d_msg_data.handle, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZscal_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZswap_v2 ( void )
{
  hfinf( "[daemon] cublasZswap_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    int n;
    cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZswap_v2( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZswap_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsymm_v2 ( void )
{
  hfinf( "[daemon] cublasZsymm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsymm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsymm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsymv_v2 ( void )
{
  hfinf( "[daemon] cublasZsymv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * x;
    int incx;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    int incy;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsymv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.incy );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsymv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsyr2_v2 ( void )
{
  hfinf( "[daemon] cublasZsyr2_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    const cuDoubleComplex * y;
    int incy;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsyr2_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.y, t2d_msg_data.incy, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsyr2_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsyr2k_v2 ( void )
{
  hfinf( "[daemon] cublasZsyr2k_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsyr2k_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsyr2k_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsyr_v2 ( void )
{
  hfinf( "[daemon] cublasZsyr_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * x;
    int incx;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsyr_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.x, t2d_msg_data.incx, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsyr_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsyrk_v2 ( void )
{
  hfinf( "[daemon] cublasZsyrk_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsyrk_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsyrk_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZsyrkx ( void )
{
  hfinf( "[daemon] cublasZsyrkx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZsyrkx( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZsyrkx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtbmv_v2 ( void )
{
  hfinf( "[daemon] cublasZtbmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const cuDoubleComplex * A;
    int lda;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtbmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtbmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtbsv_v2 ( void )
{
  hfinf( "[daemon] cublasZtbsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    int k;
    const cuDoubleComplex * A;
    int lda;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtbsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtbsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtpmv_v2 ( void )
{
  hfinf( "[daemon] cublasZtpmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuDoubleComplex * AP;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtpmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtpmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtpsv_v2 ( void )
{
  hfinf( "[daemon] cublasZtpsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuDoubleComplex * AP;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtpsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtpsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtpttr ( void )
{
  hfinf( "[daemon] cublasZtpttr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const cuDoubleComplex * AP;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtpttr( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.AP, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtpttr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtrmm_v2 ( void )
{
  hfinf( "[daemon] cublasZtrmm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * B;
    int ldb;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtrmm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtrmm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtrmv_v2 ( void )
{
  hfinf( "[daemon] cublasZtrmv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuDoubleComplex * A;
    int lda;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtrmv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtrmv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtrsmBatched ( void )
{
  hfinf( "[daemon] cublasZtrsmBatched() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex ** A ;
    int lda;
    cuDoubleComplex ** B ;
    int ldb;
    int batchCount;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtrsmBatched( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb, t2d_msg_data.batchCount );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtrsmBatched() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtrsm_v2 ( void )
{
  hfinf( "[daemon] cublasZtrsm_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cublasHandle_t handle;
    cublasSideMode_t side;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    cuDoubleComplex * B;
    int ldb;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtrsm_v2( t2d_msg_data.handle, t2d_msg_data.side, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.B, t2d_msg_data.ldb );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtrsm_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtrsv_v2 ( void )
{
  hfinf( "[daemon] cublasZtrsv_v2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    cublasOperation_t trans;
    cublasDiagType_t diag;
    int n;
    const cuDoubleComplex * A;
    int lda;
    cuDoubleComplex * x;
    int incx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtrsv_v2( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.trans, t2d_msg_data.diag, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.x, t2d_msg_data.incx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtrsv_v2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cublasZtrttp ( void )
{
  hfinf( "[daemon] cublasZtrttp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cublasHandle_t handle;
    cublasFillMode_t uplo;
    int n;
    const cuDoubleComplex * A;
    int lda;
    cuDoubleComplex * AP;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cublasStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cublasZtrttp( t2d_msg_data.handle, t2d_msg_data.uplo, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.AP );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cublasZtrttp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceGetAttribute ( void )
{
  hfinf( "[daemon] cudaDeviceGetAttribute() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaDeviceAttr attr;
    int device;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    int value;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceGetAttribute( &d2t_msg.value, t2d_msg_data.attr, t2d_msg_data.device );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceGetAttribute() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceGetCacheConfig ( void )
{
  hfinf( "[daemon] cudaDeviceGetCacheConfig() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    enum cudaFuncCache pCacheConfig;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceGetCacheConfig( &d2t_msg.pCacheConfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceGetCacheConfig() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceGetLimit ( void )
{
  hfinf( "[daemon] cudaDeviceGetLimit() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaLimit limit;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    size_t pValue;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceGetLimit( &d2t_msg.pValue, t2d_msg_data.limit );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceGetLimit() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceGetSharedMemConfig ( void )
{
  hfinf( "[daemon] cudaDeviceGetSharedMemConfig() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    enum cudaSharedMemConfig pConfig;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceGetSharedMemConfig( &d2t_msg.pConfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceGetSharedMemConfig() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceGetStreamPriorityRange ( void )
{
  hfinf( "[daemon] cudaDeviceGetStreamPriorityRange() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    union {
      struct {
        char ___dummy0[sizeof(int *) < sizeof(int) ? sizeof(int)-sizeof(int *) : 0];
        int * ptr;
      };
      struct {
        char ___dummy1[sizeof(int *) > sizeof(int) ? sizeof(int *)-sizeof(int) : 0];
        int val;
      };
    } greatestPriority;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    int leastPriority;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceGetStreamPriorityRange( &d2t_msg.leastPriority, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.greatestPriority.val : t2d_msg_data.greatestPriority.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceGetStreamPriorityRange() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceReset ( void )
{
  hfinf( "[daemon] cudaDeviceReset() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceReset(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceReset() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceSetCacheConfig ( void )
{
  hfinf( "[daemon] cudaDeviceSetCacheConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaFuncCache cacheConfig;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceSetCacheConfig( t2d_msg_data.cacheConfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceSetCacheConfig() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceSetLimit ( void )
{
  hfinf( "[daemon] cudaDeviceSetLimit() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaLimit limit;
    size_t value;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceSetLimit( t2d_msg_data.limit, t2d_msg_data.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceSetLimit() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceSetSharedMemConfig ( void )
{
  hfinf( "[daemon] cudaDeviceSetSharedMemConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaSharedMemConfig config;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceSetSharedMemConfig( t2d_msg_data.config );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceSetSharedMemConfig() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDeviceSynchronize ( void )
{
  hfinf( "[daemon] cudaDeviceSynchronize() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDeviceSynchronize(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDeviceSynchronize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaDriverGetVersion ( void )
{
  hfinf( "[daemon] cudaDriverGetVersion() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    int driverVersion;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaDriverGetVersion( &d2t_msg.driverVersion );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaDriverGetVersion() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventCreate ( void )
{
  hfinf( "[daemon] cudaEventCreate() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    cudaEvent_t event;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventCreate( &d2t_msg.event );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventCreate() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventCreateWithFlags ( void )
{
  hfinf( "[daemon] cudaEventCreateWithFlags() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    cudaEvent_t event;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventCreateWithFlags( &d2t_msg.event, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventCreateWithFlags() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventDestroy ( void )
{
  hfinf( "[daemon] cudaEventDestroy() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaEvent_t event;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventDestroy( t2d_msg_data.event );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventDestroy() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventElapsedTime ( void )
{
  hfinf( "[daemon] cudaEventElapsedTime() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaEvent_t start;
    cudaEvent_t end;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    float ms;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventElapsedTime( &d2t_msg.ms, t2d_msg_data.start, t2d_msg_data.end );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventElapsedTime() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventQuery ( void )
{
  hfinf( "[daemon] cudaEventQuery() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaEvent_t event;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventQuery( t2d_msg_data.event );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventQuery() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventRecord ( void )
{
  hfinf( "[daemon] cudaEventRecord() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaEvent_t event;
    cudaStream_t stream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventRecord( t2d_msg_data.event, t2d_msg_data.stream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventRecord() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaEventSynchronize ( void )
{
  hfinf( "[daemon] cudaEventSynchronize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaEvent_t event;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaEventSynchronize( t2d_msg_data.event );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaEventSynchronize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaGetDeviceFlags ( void )
{
  hfinf( "[daemon] cudaGetDeviceFlags() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    unsigned int flags;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaGetDeviceFlags( &d2t_msg.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaGetDeviceFlags() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaGetLastError ( void )
{
  hfinf( "[daemon] cudaGetLastError() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaGetLastError(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaGetLastError() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaMemset ( void )
{
  hfinf( "[daemon] cudaMemset() [CALL]\n" );
  
  struct __attribute__((packed)) {
    void * devPtr;
    int value;
    size_t count;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaMemset( t2d_msg_data.devPtr, t2d_msg_data.value, t2d_msg_data.count );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaMemset() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaMemset2D ( void )
{
  hfinf( "[daemon] cudaMemset2D() [CALL]\n" );
  
  struct __attribute__((packed)) {
    void * devPtr;
    size_t pitch;
    int value;
    size_t width;
    size_t height;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaMemset2D( t2d_msg_data.devPtr, t2d_msg_data.pitch, t2d_msg_data.value, t2d_msg_data.width, t2d_msg_data.height );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaMemset2D() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaMemset3D ( void )
{
  hfinf( "[daemon] cudaMemset3D() [CALL]\n" );
  
  struct __attribute__((packed)) {
    struct cudaPitchedPtr pitchedDevPtr;
    int value;
    struct cudaExtent extent;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaMemset3D( t2d_msg_data.pitchedDevPtr, t2d_msg_data.value, t2d_msg_data.extent );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaMemset3D() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaPeekAtLastError ( void )
{
  hfinf( "[daemon] cudaPeekAtLastError() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaPeekAtLastError(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaPeekAtLastError() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaRuntimeGetVersion ( void )
{
  hfinf( "[daemon] cudaRuntimeGetVersion() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    int runtimeVersion;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaRuntimeGetVersion( &d2t_msg.runtimeVersion );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaRuntimeGetVersion() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaSetDeviceFlags ( void )
{
  hfinf( "[daemon] cudaSetDeviceFlags() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaSetDeviceFlags( t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaSetDeviceFlags() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamCreate ( void )
{
  hfinf( "[daemon] cudaStreamCreate() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    cudaStream_t pStream;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamCreate( &d2t_msg.pStream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamCreate() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamCreateWithFlags ( void )
{
  hfinf( "[daemon] cudaStreamCreateWithFlags() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    cudaStream_t pStream;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamCreateWithFlags( &d2t_msg.pStream, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamCreateWithFlags() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamCreateWithPriority ( void )
{
  hfinf( "[daemon] cudaStreamCreateWithPriority() [CALL]\n" );
  
  struct __attribute__((packed)) {
    unsigned int flags;
    int priority;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    cudaStream_t pStream;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamCreateWithPriority( &d2t_msg.pStream, t2d_msg_data.flags, t2d_msg_data.priority );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamCreateWithPriority() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamDestroy ( void )
{
  hfinf( "[daemon] cudaStreamDestroy() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaStream_t stream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamDestroy( t2d_msg_data.stream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamDestroy() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamGetFlags ( void )
{
  hfinf( "[daemon] cudaStreamGetFlags() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaStream_t hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    unsigned int flags;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamGetFlags( t2d_msg_data.hStream, &d2t_msg.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamGetFlags() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamGetPriority ( void )
{
  hfinf( "[daemon] cudaStreamGetPriority() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaStream_t hStream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    int priority;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamGetPriority( t2d_msg_data.hStream, &d2t_msg.priority );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamGetPriority() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamQuery ( void )
{
  hfinf( "[daemon] cudaStreamQuery() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaStream_t stream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamQuery( t2d_msg_data.stream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamQuery() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamSynchronize ( void )
{
  hfinf( "[daemon] cudaStreamSynchronize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaStream_t stream;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamSynchronize( t2d_msg_data.stream );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamSynchronize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaStreamWaitEvent ( void )
{
  hfinf( "[daemon] cudaStreamWaitEvent() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudaStream_t stream;
    cudaEvent_t event;
    unsigned int flags;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaStreamWaitEvent( t2d_msg_data.stream, t2d_msg_data.event, t2d_msg_data.flags );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaStreamWaitEvent() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaThreadExit ( void )
{
  hfinf( "[daemon] cudaThreadExit() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaThreadExit(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaThreadExit() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaThreadGetCacheConfig ( void )
{
  hfinf( "[daemon] cudaThreadGetCacheConfig() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
    enum cudaFuncCache pCacheConfig;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaThreadGetCacheConfig( &d2t_msg.pCacheConfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaThreadGetCacheConfig() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaThreadGetLimit ( void )
{
  hfinf( "[daemon] cudaThreadGetLimit() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaLimit limit;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
    size_t pValue;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaThreadGetLimit( &d2t_msg.pValue, t2d_msg_data.limit );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaThreadGetLimit() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaThreadSetCacheConfig ( void )
{
  hfinf( "[daemon] cudaThreadSetCacheConfig() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaFuncCache cacheConfig;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaThreadSetCacheConfig( t2d_msg_data.cacheConfig );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaThreadSetCacheConfig() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaThreadSetLimit ( void )
{
  hfinf( "[daemon] cudaThreadSetLimit() [CALL]\n" );
  
  struct __attribute__((packed)) {
    enum cudaLimit limit;
    size_t value;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaThreadSetLimit( t2d_msg_data.limit, t2d_msg_data.value );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaThreadSetLimit() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudaThreadSynchronize ( void )
{
  hfinf( "[daemon] cudaThreadSynchronize() [CALL]\n" );
  
  struct {
    cudaError_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudaThreadSynchronize(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudaThreadSynchronize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnActivationBackward ( void )
{
  hfinf( "[daemon] cudnnActivationBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnActivationDescriptor_t activationDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t yDesc;
    const void * y;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnActivationBackward( t2d_msg_data.handle, t2d_msg_data.activationDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dxDesc, t2d_msg_data.dx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnActivationBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnActivationForward ( void )
{
  hfinf( "[daemon] cudnnActivationForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnActivationDescriptor_t activationDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnActivationForward( t2d_msg_data.handle, t2d_msg_data.activationDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnActivationForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnAddTensor ( void )
{
  hfinf( "[daemon] cudnnAddTensor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t aDesc;
    const void * A;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t cDesc;
    void * C;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnAddTensor( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.aDesc, t2d_msg_data.A, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.cDesc, t2d_msg_data.C );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnAddTensor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnBatchNormalizationBackward ( void )
{
  hfinf( "[daemon] cudnnBatchNormalizationBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnBatchNormMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alphaDataDiff;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } betaDataDiff;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alphaParamDiff;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } betaParamDiff;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
    cudnnTensorDescriptor_t dBnScaleBiasDesc;
    const void * bnScale;
    void * dBnScaleResult;
    void * dBnBiasResult;
    double epsilon;
    const void * savedMean;
    const void * savedInvVariance;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnBatchNormalizationBackward( t2d_msg_data.handle, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alphaDataDiff.val : t2d_msg_data.alphaDataDiff.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.betaDataDiff.val : t2d_msg_data.betaDataDiff.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &t2d_msg_data.alphaParamDiff.val : t2d_msg_data.alphaParamDiff.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &t2d_msg_data.betaParamDiff.val : t2d_msg_data.betaParamDiff.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.dxDesc, t2d_msg_data.dx, t2d_msg_data.dBnScaleBiasDesc, t2d_msg_data.bnScale, t2d_msg_data.dBnScaleResult, t2d_msg_data.dBnBiasResult, t2d_msg_data.epsilon, t2d_msg_data.savedMean, t2d_msg_data.savedInvVariance );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnBatchNormalizationBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnBatchNormalizationForwardInference ( void )
{
  hfinf( "[daemon] cudnnBatchNormalizationForwardInference() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnBatchNormMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    cudnnTensorDescriptor_t yDesc;
    void * y;
    cudnnTensorDescriptor_t bnScaleBiasMeanVarDesc;
    const void * bnScale;
    const void * bnBias;
    const void * estimatedMean;
    const void * estimatedVariance;
    double epsilon;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnBatchNormalizationForwardInference( t2d_msg_data.handle, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.bnScaleBiasMeanVarDesc, t2d_msg_data.bnScale, t2d_msg_data.bnBias, t2d_msg_data.estimatedMean, t2d_msg_data.estimatedVariance, t2d_msg_data.epsilon );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnBatchNormalizationForwardInference() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnBatchNormalizationForwardTraining ( void )
{
  hfinf( "[daemon] cudnnBatchNormalizationForwardTraining() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnBatchNormMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    cudnnTensorDescriptor_t yDesc;
    void * y;
    cudnnTensorDescriptor_t bnScaleBiasMeanVarDesc;
    const void * bnScale;
    const void * bnBias;
    double exponentialAverageFactor;
    void * resultRunningMean;
    void * resultRunningVariance;
    double epsilon;
    void * resultSaveMean;
    void * resultSaveInvVariance;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnBatchNormalizationForwardTraining( t2d_msg_data.handle, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.bnScaleBiasMeanVarDesc, t2d_msg_data.bnScale, t2d_msg_data.bnBias, t2d_msg_data.exponentialAverageFactor, t2d_msg_data.resultRunningMean, t2d_msg_data.resultRunningVariance, t2d_msg_data.epsilon, t2d_msg_data.resultSaveMean, t2d_msg_data.resultSaveInvVariance );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnBatchNormalizationForwardTraining() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnConvolutionBackwardBias ( void )
{
  hfinf( "[daemon] cudnnConvolutionBackwardBias() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dbDesc;
    void * db;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnConvolutionBackwardBias( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.dyDesc, t2d_msg_data.dy, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dbDesc, t2d_msg_data.db );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnConvolutionBackwardBias() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnConvolutionBackwardData ( void )
{
  hfinf( "[daemon] cudnnConvolutionBackwardData() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnConvolutionBwdDataAlgo_t algo;
    void * workSpace;
    size_t workSpaceSizeInBytes;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnConvolutionBackwardData( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.convDesc, t2d_msg_data.algo, t2d_msg_data.workSpace, t2d_msg_data.workSpaceSizeInBytes, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dxDesc, t2d_msg_data.dx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnConvolutionBackwardData() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnConvolutionBackwardFilter ( void )
{
  hfinf( "[daemon] cudnnConvolutionBackwardFilter() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnConvolutionBwdFilterAlgo_t algo;
    void * workSpace;
    size_t workSpaceSizeInBytes;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnFilterDescriptor_t dwDesc;
    void * dw;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnConvolutionBackwardFilter( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.convDesc, t2d_msg_data.algo, t2d_msg_data.workSpace, t2d_msg_data.workSpaceSizeInBytes, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dwDesc, t2d_msg_data.dw );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnConvolutionBackwardFilter() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnConvolutionForward ( void )
{
  hfinf( "[daemon] cudnnConvolutionForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnConvolutionFwdAlgo_t algo;
    void * workSpace;
    size_t workSpaceSizeInBytes;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnConvolutionForward( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.convDesc, t2d_msg_data.algo, t2d_msg_data.workSpace, t2d_msg_data.workSpaceSizeInBytes, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnConvolutionForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreate ( void )
{
  hfinf( "[daemon] cudnnCreate() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnHandle_t handle;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreate( &d2t_msg.handle );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreate() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateActivationDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateActivationDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnActivationDescriptor_t activationDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateActivationDescriptor( &d2t_msg.activationDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateActivationDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateConvolutionDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateConvolutionDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnConvolutionDescriptor_t convDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateConvolutionDescriptor( &d2t_msg.convDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateConvolutionDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateDropoutDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateDropoutDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnDropoutDescriptor_t dropoutDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateDropoutDescriptor( &d2t_msg.dropoutDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateDropoutDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateFilterDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateFilterDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnFilterDescriptor_t filterDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateFilterDescriptor( &d2t_msg.filterDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateFilterDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateLRNDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateLRNDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnLRNDescriptor_t normDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateLRNDescriptor( &d2t_msg.normDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateLRNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateOpTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateOpTensorDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnOpTensorDescriptor_t opTensorDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateOpTensorDescriptor( &d2t_msg.opTensorDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateOpTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreatePoolingDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreatePoolingDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnPoolingDescriptor_t poolingDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreatePoolingDescriptor( &d2t_msg.poolingDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreatePoolingDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateRNNDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateRNNDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnRNNDescriptor_t rnnDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateRNNDescriptor( &d2t_msg.rnnDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateRNNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateSpatialTransformerDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateSpatialTransformerDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnSpatialTransformerDescriptor_t stDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateSpatialTransformerDescriptor( &d2t_msg.stDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateSpatialTransformerDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnCreateTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnCreateTensorDescriptor() [CALL]\n" );
  
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnTensorDescriptor_t tensorDesc;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnCreateTensorDescriptor( &d2t_msg.tensorDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnCreateTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDeriveBNTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnDeriveBNTensorDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnTensorDescriptor_t derivedBnDesc;
    cudnnTensorDescriptor_t xDesc;
    cudnnBatchNormMode_t mode;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDeriveBNTensorDescriptor( t2d_msg_data.derivedBnDesc, t2d_msg_data.xDesc, t2d_msg_data.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDeriveBNTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroy ( void )
{
  hfinf( "[daemon] cudnnDestroy() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroy( t2d_msg_data.handle );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroy() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyActivationDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyActivationDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnActivationDescriptor_t activationDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyActivationDescriptor( t2d_msg_data.activationDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyActivationDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyConvolutionDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyConvolutionDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnConvolutionDescriptor_t convDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyConvolutionDescriptor( t2d_msg_data.convDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyConvolutionDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyDropoutDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyDropoutDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnDropoutDescriptor_t dropoutDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyDropoutDescriptor( t2d_msg_data.dropoutDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyDropoutDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyFilterDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyFilterDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnFilterDescriptor_t filterDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyFilterDescriptor( t2d_msg_data.filterDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyFilterDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyLRNDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyLRNDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnLRNDescriptor_t lrnDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyLRNDescriptor( t2d_msg_data.lrnDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyLRNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyOpTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyOpTensorDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnOpTensorDescriptor_t opTensorDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyOpTensorDescriptor( t2d_msg_data.opTensorDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyOpTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyPoolingDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyPoolingDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnPoolingDescriptor_t poolingDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyPoolingDescriptor( t2d_msg_data.poolingDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyPoolingDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyRNNDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyRNNDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnRNNDescriptor_t rnnDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyRNNDescriptor( t2d_msg_data.rnnDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyRNNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroySpatialTransformerDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroySpatialTransformerDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnSpatialTransformerDescriptor_t stDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroySpatialTransformerDescriptor( t2d_msg_data.stDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroySpatialTransformerDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDestroyTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnDestroyTensorDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnTensorDescriptor_t tensorDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDestroyTensorDescriptor( t2d_msg_data.tensorDesc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDestroyTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDivisiveNormalizationBackward ( void )
{
  hfinf( "[daemon] cudnnDivisiveNormalizationBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnLRNDescriptor_t normDesc;
    cudnnDivNormMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    const void * means;
    const void * dy;
    void * temp;
    void * temp2;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dXdMeansDesc;
    void * dx;
    void * dMeans;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDivisiveNormalizationBackward( t2d_msg_data.handle, t2d_msg_data.normDesc, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.means, t2d_msg_data.dy, t2d_msg_data.temp, t2d_msg_data.temp2, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dXdMeansDesc, t2d_msg_data.dx, t2d_msg_data.dMeans );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDivisiveNormalizationBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDivisiveNormalizationForward ( void )
{
  hfinf( "[daemon] cudnnDivisiveNormalizationForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnLRNDescriptor_t normDesc;
    cudnnDivNormMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    const void * means;
    void * temp;
    void * temp2;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDivisiveNormalizationForward( t2d_msg_data.handle, t2d_msg_data.normDesc, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.means, t2d_msg_data.temp, t2d_msg_data.temp2, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDivisiveNormalizationForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDropoutBackward ( void )
{
  hfinf( "[daemon] cudnnDropoutBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnDropoutDescriptor_t dropoutDesc;
    cudnnTensorDescriptor_t dydesc;
    const void * dy;
    cudnnTensorDescriptor_t dxdesc;
    void * dx;
    void * reserveSpace;
    size_t reserveSpaceSizeInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDropoutBackward( t2d_msg_data.handle, t2d_msg_data.dropoutDesc, t2d_msg_data.dydesc, t2d_msg_data.dy, t2d_msg_data.dxdesc, t2d_msg_data.dx, t2d_msg_data.reserveSpace, t2d_msg_data.reserveSpaceSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDropoutBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDropoutForward ( void )
{
  hfinf( "[daemon] cudnnDropoutForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnDropoutDescriptor_t dropoutDesc;
    cudnnTensorDescriptor_t xdesc;
    const void * x;
    cudnnTensorDescriptor_t ydesc;
    void * y;
    void * reserveSpace;
    size_t reserveSpaceSizeInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDropoutForward( t2d_msg_data.handle, t2d_msg_data.dropoutDesc, t2d_msg_data.xdesc, t2d_msg_data.x, t2d_msg_data.ydesc, t2d_msg_data.y, t2d_msg_data.reserveSpace, t2d_msg_data.reserveSpaceSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDropoutForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDropoutGetReserveSpaceSize ( void )
{
  hfinf( "[daemon] cudnnDropoutGetReserveSpaceSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnTensorDescriptor_t xdesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    size_t sizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDropoutGetReserveSpaceSize( t2d_msg_data.xdesc, &d2t_msg.sizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDropoutGetReserveSpaceSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnDropoutGetStatesSize ( void )
{
  hfinf( "[daemon] cudnnDropoutGetStatesSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    size_t sizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnDropoutGetStatesSize( t2d_msg_data.handle, &d2t_msg.sizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnDropoutGetStatesSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetActivationDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetActivationDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnActivationDescriptor_t activationDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnActivationMode_t mode;
    cudnnNanPropagation_t reluNanOpt;
    double reluCeiling;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetActivationDescriptor( t2d_msg_data.activationDesc, &d2t_msg.mode, &d2t_msg.reluNanOpt, &d2t_msg.reluCeiling );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetActivationDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolution2dDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetConvolution2dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnConvolutionDescriptor_t convDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    int pad_h;
    int pad_w;
    int u;
    int v;
    int upscalex;
    int upscaley;
    cudnnConvolutionMode_t mode;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolution2dDescriptor( t2d_msg_data.convDesc, &d2t_msg.pad_h, &d2t_msg.pad_w, &d2t_msg.u, &d2t_msg.v, &d2t_msg.upscalex, &d2t_msg.upscaley, &d2t_msg.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolution2dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolution2dForwardOutputDim ( void )
{
  hfinf( "[daemon] cudnnGetConvolution2dForwardOutputDim() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnConvolutionDescriptor_t convDesc;
    cudnnTensorDescriptor_t inputTensorDesc;
    cudnnFilterDescriptor_t filterDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    int n;
    int c;
    int h;
    int w;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolution2dForwardOutputDim( t2d_msg_data.convDesc, t2d_msg_data.inputTensorDesc, t2d_msg_data.filterDesc, &d2t_msg.n, &d2t_msg.c, &d2t_msg.h, &d2t_msg.w );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolution2dForwardOutputDim() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolutionBackwardDataAlgorithm ( void )
{
  hfinf( "[daemon] cudnnGetConvolutionBackwardDataAlgorithm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnFilterDescriptor_t wDesc;
    cudnnTensorDescriptor_t dyDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnTensorDescriptor_t dxDesc;
    cudnnConvolutionBwdDataPreference_t preference;
    size_t memoryLimitInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnConvolutionBwdDataAlgo_t algo;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolutionBackwardDataAlgorithm( t2d_msg_data.handle, t2d_msg_data.wDesc, t2d_msg_data.dyDesc, t2d_msg_data.convDesc, t2d_msg_data.dxDesc, t2d_msg_data.preference, t2d_msg_data.memoryLimitInBytes, &d2t_msg.algo );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolutionBackwardDataAlgorithm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolutionBackwardDataWorkspaceSize ( void )
{
  hfinf( "[daemon] cudnnGetConvolutionBackwardDataWorkspaceSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnFilterDescriptor_t wDesc;
    cudnnTensorDescriptor_t dyDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnTensorDescriptor_t dxDesc;
    cudnnConvolutionBwdDataAlgo_t algo;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    size_t sizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolutionBackwardDataWorkspaceSize( t2d_msg_data.handle, t2d_msg_data.wDesc, t2d_msg_data.dyDesc, t2d_msg_data.convDesc, t2d_msg_data.dxDesc, t2d_msg_data.algo, &d2t_msg.sizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolutionBackwardDataWorkspaceSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolutionBackwardFilterAlgorithm ( void )
{
  hfinf( "[daemon] cudnnGetConvolutionBackwardFilterAlgorithm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t xDesc;
    cudnnTensorDescriptor_t dyDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnFilterDescriptor_t dwDesc;
    cudnnConvolutionBwdFilterPreference_t preference;
    size_t memoryLimitInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnConvolutionBwdFilterAlgo_t algo;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolutionBackwardFilterAlgorithm( t2d_msg_data.handle, t2d_msg_data.xDesc, t2d_msg_data.dyDesc, t2d_msg_data.convDesc, t2d_msg_data.dwDesc, t2d_msg_data.preference, t2d_msg_data.memoryLimitInBytes, &d2t_msg.algo );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolutionBackwardFilterAlgorithm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolutionBackwardFilterWorkspaceSize ( void )
{
  hfinf( "[daemon] cudnnGetConvolutionBackwardFilterWorkspaceSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t xDesc;
    cudnnTensorDescriptor_t dyDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnFilterDescriptor_t gradDesc;
    cudnnConvolutionBwdFilterAlgo_t algo;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    size_t sizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolutionBackwardFilterWorkspaceSize( t2d_msg_data.handle, t2d_msg_data.xDesc, t2d_msg_data.dyDesc, t2d_msg_data.convDesc, t2d_msg_data.gradDesc, t2d_msg_data.algo, &d2t_msg.sizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolutionBackwardFilterWorkspaceSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolutionForwardAlgorithm ( void )
{
  hfinf( "[daemon] cudnnGetConvolutionForwardAlgorithm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t xDesc;
    cudnnFilterDescriptor_t wDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnTensorDescriptor_t yDesc;
    cudnnConvolutionFwdPreference_t preference;
    size_t memoryLimitInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnConvolutionFwdAlgo_t algo;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolutionForwardAlgorithm( t2d_msg_data.handle, t2d_msg_data.xDesc, t2d_msg_data.wDesc, t2d_msg_data.convDesc, t2d_msg_data.yDesc, t2d_msg_data.preference, t2d_msg_data.memoryLimitInBytes, &d2t_msg.algo );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolutionForwardAlgorithm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetConvolutionForwardWorkspaceSize ( void )
{
  hfinf( "[daemon] cudnnGetConvolutionForwardWorkspaceSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t xDesc;
    cudnnFilterDescriptor_t wDesc;
    cudnnConvolutionDescriptor_t convDesc;
    cudnnTensorDescriptor_t yDesc;
    cudnnConvolutionFwdAlgo_t algo;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    size_t sizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetConvolutionForwardWorkspaceSize( t2d_msg_data.handle, t2d_msg_data.xDesc, t2d_msg_data.wDesc, t2d_msg_data.convDesc, t2d_msg_data.yDesc, t2d_msg_data.algo, &d2t_msg.sizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetConvolutionForwardWorkspaceSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetFilter4dDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetFilter4dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnFilterDescriptor_t filterDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnDataType_t dataType;
    cudnnTensorFormat_t format;
    int k;
    int c;
    int h;
    int w;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetFilter4dDescriptor( t2d_msg_data.filterDesc, &d2t_msg.dataType, &d2t_msg.format, &d2t_msg.k, &d2t_msg.c, &d2t_msg.h, &d2t_msg.w );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetFilter4dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetLRNDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetLRNDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnLRNDescriptor_t normDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    unsigned int lrnN;
    double lrnAlpha;
    double lrnBeta;
    double lrnK;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetLRNDescriptor( t2d_msg_data.normDesc, &d2t_msg.lrnN, &d2t_msg.lrnAlpha, &d2t_msg.lrnBeta, &d2t_msg.lrnK );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetLRNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetOpTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetOpTensorDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnOpTensorDescriptor_t opTensorDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnOpTensorOp_t opTensorOp;
    cudnnDataType_t opTensorCompType;
    cudnnNanPropagation_t opTensorNanOpt;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetOpTensorDescriptor( t2d_msg_data.opTensorDesc, &d2t_msg.opTensorOp, &d2t_msg.opTensorCompType, &d2t_msg.opTensorNanOpt );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetOpTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetPooling2dDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetPooling2dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnPoolingDescriptor_t poolingDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnPoolingMode_t mode;
    cudnnNanPropagation_t maxpoolingNanOpt;
    int windowHeight;
    int windowWidth;
    int verticalPadding;
    int horizontalPadding;
    int verticalStride;
    int horizontalStride;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetPooling2dDescriptor( t2d_msg_data.poolingDesc, &d2t_msg.mode, &d2t_msg.maxpoolingNanOpt, &d2t_msg.windowHeight, &d2t_msg.windowWidth, &d2t_msg.verticalPadding, &d2t_msg.horizontalPadding, &d2t_msg.verticalStride, &d2t_msg.horizontalStride );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetPooling2dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetPooling2dForwardOutputDim ( void )
{
  hfinf( "[daemon] cudnnGetPooling2dForwardOutputDim() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnPoolingDescriptor_t poolingDesc;
    cudnnTensorDescriptor_t inputTensorDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    int n;
    int c;
    int h;
    int w;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetPooling2dForwardOutputDim( t2d_msg_data.poolingDesc, t2d_msg_data.inputTensorDesc, &d2t_msg.n, &d2t_msg.c, &d2t_msg.h, &d2t_msg.w );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetPooling2dForwardOutputDim() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetRNNLinLayerBiasParams ( void )
{
  hfinf( "[daemon] cudnnGetRNNLinLayerBiasParams() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    int layer;
    cudnnTensorDescriptor_t xDesc;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    int linLayerID;
    cudnnFilterDescriptor_t linLayerBiasDesc;
    void ** linLayerBias;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetRNNLinLayerBiasParams( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.layer, t2d_msg_data.xDesc, t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.linLayerID, t2d_msg_data.linLayerBiasDesc, t2d_msg_data.linLayerBias );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetRNNLinLayerBiasParams() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetRNNLinLayerMatrixParams ( void )
{
  hfinf( "[daemon] cudnnGetRNNLinLayerMatrixParams() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    int layer;
    cudnnTensorDescriptor_t xDesc;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    int linLayerID;
    cudnnFilterDescriptor_t linLayerMatDesc;
    void ** linLayerMat;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetRNNLinLayerMatrixParams( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.layer, t2d_msg_data.xDesc, t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.linLayerID, t2d_msg_data.linLayerMatDesc, t2d_msg_data.linLayerMat );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetRNNLinLayerMatrixParams() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetRNNParamsSize ( void )
{
  hfinf( "[daemon] cudnnGetRNNParamsSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    cudnnTensorDescriptor_t xDesc;
    cudnnDataType_t dataType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    size_t sizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetRNNParamsSize( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.xDesc, &d2t_msg.sizeInBytes, t2d_msg_data.dataType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetRNNParamsSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetStream ( void )
{
  hfinf( "[daemon] cudnnGetStream() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudaStream_t streamId;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetStream( t2d_msg_data.handle, &d2t_msg.streamId );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetStream() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetTensor4dDescriptor ( void )
{
  hfinf( "[daemon] cudnnGetTensor4dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnTensorDescriptor_t tensorDesc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
    cudnnDataType_t dataType;
    int n;
    int c;
    int h;
    int w;
    int nStride;
    int cStride;
    int hStride;
    int wStride;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetTensor4dDescriptor( t2d_msg_data.tensorDesc, &d2t_msg.dataType, &d2t_msg.n, &d2t_msg.c, &d2t_msg.h, &d2t_msg.w, &d2t_msg.nStride, &d2t_msg.cStride, &d2t_msg.hStride, &d2t_msg.wStride );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetTensor4dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnGetVersion ( void )
{
  hfinf( "[daemon] cudnnGetVersion() [CALL]\n" );
  
  struct {
    size_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnGetVersion(  );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnGetVersion() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnIm2Col ( void )
{
  hfinf( "[daemon] cudnnIm2Col() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    cudnnFilterDescriptor_t wDesc;
    cudnnConvolutionDescriptor_t convDesc;
    void * colBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnIm2Col( t2d_msg_data.handle, t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.wDesc, t2d_msg_data.convDesc, t2d_msg_data.colBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnIm2Col() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnLRNCrossChannelBackward ( void )
{
  hfinf( "[daemon] cudnnLRNCrossChannelBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnLRNDescriptor_t normDesc;
    cudnnLRNMode_t lrnMode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t yDesc;
    const void * y;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnLRNCrossChannelBackward( t2d_msg_data.handle, t2d_msg_data.normDesc, t2d_msg_data.lrnMode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dxDesc, t2d_msg_data.dx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnLRNCrossChannelBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnLRNCrossChannelForward ( void )
{
  hfinf( "[daemon] cudnnLRNCrossChannelForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnLRNDescriptor_t normDesc;
    cudnnLRNMode_t lrnMode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnLRNCrossChannelForward( t2d_msg_data.handle, t2d_msg_data.normDesc, t2d_msg_data.lrnMode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnLRNCrossChannelForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnOpTensor ( void )
{
  hfinf( "[daemon] cudnnOpTensor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnOpTensorDescriptor_t opTensorDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha1;
    cudnnTensorDescriptor_t aDesc;
    const void * A;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha2;
    cudnnTensorDescriptor_t bDesc;
    const void * B;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t cDesc;
    void * C;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnOpTensor( t2d_msg_data.handle, t2d_msg_data.opTensorDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha1.val : t2d_msg_data.alpha1.ptr), t2d_msg_data.aDesc, t2d_msg_data.A, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.alpha2.val : t2d_msg_data.alpha2.ptr), t2d_msg_data.bDesc, t2d_msg_data.B, (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.cDesc, t2d_msg_data.C );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnOpTensor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnPoolingBackward ( void )
{
  hfinf( "[daemon] cudnnPoolingBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnPoolingDescriptor_t poolingDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t yDesc;
    const void * y;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnPoolingBackward( t2d_msg_data.handle, t2d_msg_data.poolingDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dxDesc, t2d_msg_data.dx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnPoolingBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnPoolingForward ( void )
{
  hfinf( "[daemon] cudnnPoolingForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnPoolingDescriptor_t poolingDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnPoolingForward( t2d_msg_data.handle, t2d_msg_data.poolingDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnPoolingForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnRNNBackwardData ( void )
{
  hfinf( "[daemon] cudnnRNNBackwardData() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    int seqLength;
    const cudnnTensorDescriptor_t * yDesc;
    const void * y;
    const cudnnTensorDescriptor_t * dyDesc;
    const void * dy;
    cudnnTensorDescriptor_t dhyDesc;
    const void * dhy;
    cudnnTensorDescriptor_t dcyDesc;
    const void * dcy;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    cudnnTensorDescriptor_t hxDesc;
    const void * hx;
    cudnnTensorDescriptor_t cxDesc;
    const void * cx;
    const cudnnTensorDescriptor_t * dxDesc;
    void * dx;
    cudnnTensorDescriptor_t dhxDesc;
    void * dhx;
    cudnnTensorDescriptor_t dcxDesc;
    void * dcx;
    void * workspace;
    size_t workSpaceSizeInBytes;
    const void * reserveSpace;
    size_t reserveSpaceSizeInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnRNNBackwardData( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.seqLength, t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.dhyDesc, t2d_msg_data.dhy, t2d_msg_data.dcyDesc, t2d_msg_data.dcy, t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.hxDesc, t2d_msg_data.hx, t2d_msg_data.cxDesc, t2d_msg_data.cx, t2d_msg_data.dxDesc, t2d_msg_data.dx, t2d_msg_data.dhxDesc, t2d_msg_data.dhx, t2d_msg_data.dcxDesc, t2d_msg_data.dcx, t2d_msg_data.workspace, t2d_msg_data.workSpaceSizeInBytes, t2d_msg_data.reserveSpace, t2d_msg_data.reserveSpaceSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnRNNBackwardData() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnRNNBackwardWeights ( void )
{
  hfinf( "[daemon] cudnnRNNBackwardWeights() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    int seqLength;
    const cudnnTensorDescriptor_t * xDesc;
    const void * x;
    cudnnTensorDescriptor_t hxDesc;
    const void * hx;
    const cudnnTensorDescriptor_t * yDesc;
    const void * y;
    const void * workspace;
    size_t workSpaceSizeInBytes;
    cudnnFilterDescriptor_t dwDesc;
    void * dw;
    const void * reserveSpace;
    size_t reserveSpaceSizeInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnRNNBackwardWeights( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.seqLength, t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.hxDesc, t2d_msg_data.hx, t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.workspace, t2d_msg_data.workSpaceSizeInBytes, t2d_msg_data.dwDesc, t2d_msg_data.dw, t2d_msg_data.reserveSpace, t2d_msg_data.reserveSpaceSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnRNNBackwardWeights() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnRNNForwardInference ( void )
{
  hfinf( "[daemon] cudnnRNNForwardInference() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    int seqLength;
    const cudnnTensorDescriptor_t * xDesc;
    const void * x;
    cudnnTensorDescriptor_t hxDesc;
    const void * hx;
    cudnnTensorDescriptor_t cxDesc;
    const void * cx;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    const cudnnTensorDescriptor_t * yDesc;
    void * y;
    cudnnTensorDescriptor_t hyDesc;
    void * hy;
    cudnnTensorDescriptor_t cyDesc;
    void * cy;
    void * workspace;
    size_t workSpaceSizeInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnRNNForwardInference( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.seqLength, t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.hxDesc, t2d_msg_data.hx, t2d_msg_data.cxDesc, t2d_msg_data.cx, t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.hyDesc, t2d_msg_data.hy, t2d_msg_data.cyDesc, t2d_msg_data.cy, t2d_msg_data.workspace, t2d_msg_data.workSpaceSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnRNNForwardInference() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnRNNForwardTraining ( void )
{
  hfinf( "[daemon] cudnnRNNForwardTraining() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnRNNDescriptor_t rnnDesc;
    int seqLength;
    const cudnnTensorDescriptor_t * xDesc;
    const void * x;
    cudnnTensorDescriptor_t hxDesc;
    const void * hx;
    cudnnTensorDescriptor_t cxDesc;
    const void * cx;
    cudnnFilterDescriptor_t wDesc;
    const void * w;
    const cudnnTensorDescriptor_t * yDesc;
    void * y;
    cudnnTensorDescriptor_t hyDesc;
    void * hy;
    cudnnTensorDescriptor_t cyDesc;
    void * cy;
    void * workspace;
    size_t workSpaceSizeInBytes;
    void * reserveSpace;
    size_t reserveSpaceSizeInBytes;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnRNNForwardTraining( t2d_msg_data.handle, t2d_msg_data.rnnDesc, t2d_msg_data.seqLength, t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.hxDesc, t2d_msg_data.hx, t2d_msg_data.cxDesc, t2d_msg_data.cx, t2d_msg_data.wDesc, t2d_msg_data.w, t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.hyDesc, t2d_msg_data.hy, t2d_msg_data.cyDesc, t2d_msg_data.cy, t2d_msg_data.workspace, t2d_msg_data.workSpaceSizeInBytes, t2d_msg_data.reserveSpace, t2d_msg_data.reserveSpaceSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnRNNForwardTraining() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnScaleTensor ( void )
{
  hfinf( "[daemon] cudnnScaleTensor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t yDesc;
    void * y;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnScaleTensor( t2d_msg_data.handle, t2d_msg_data.yDesc, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnScaleTensor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetActivationDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetActivationDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnActivationDescriptor_t activationDesc;
    cudnnActivationMode_t mode;
    cudnnNanPropagation_t reluNanOpt;
    double reluCeiling;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetActivationDescriptor( t2d_msg_data.activationDesc, t2d_msg_data.mode, t2d_msg_data.reluNanOpt, t2d_msg_data.reluCeiling );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetActivationDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetConvolution2dDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetConvolution2dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnConvolutionDescriptor_t convDesc;
    int pad_h;
    int pad_w;
    int u;
    int v;
    int upscalex;
    int upscaley;
    cudnnConvolutionMode_t mode;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetConvolution2dDescriptor( t2d_msg_data.convDesc, t2d_msg_data.pad_h, t2d_msg_data.pad_w, t2d_msg_data.u, t2d_msg_data.v, t2d_msg_data.upscalex, t2d_msg_data.upscaley, t2d_msg_data.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetConvolution2dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetConvolutionNdDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetConvolutionNdDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnConvolutionDescriptor_t convDesc;
    int arrayLength;
    const int * padA ;
    const int * filterStrideA ;
    const int * upscaleA ;
    cudnnConvolutionMode_t mode;
    cudnnDataType_t dataType;
    char ____buf[];
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  char *____buf = (char*) malloc ( t2d_msg_data.arrayLength * sizeof(const int) + t2d_msg_data.arrayLength * sizeof(const int) + t2d_msg_data.arrayLength * sizeof(const int) );
  if( (t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1 ) {
    t2d_msg_data.padA = (const int *) &____buf[ 0 ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.padA, t2d_msg_data.arrayLength * sizeof(const int) ));
  }
  if( (t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1 ) {
    t2d_msg_data.filterStrideA = (const int *) &____buf[ t2d_msg_data.arrayLength * sizeof(const int) ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.filterStrideA, t2d_msg_data.arrayLength * sizeof(const int) ));
  }
  if( (t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1 ) {
    t2d_msg_data.upscaleA = (const int *) &____buf[ t2d_msg_data.arrayLength * sizeof(const int) + t2d_msg_data.arrayLength * sizeof(const int) ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.upscaleA, t2d_msg_data.arrayLength * sizeof(const int) ));
  }
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetConvolutionNdDescriptor( t2d_msg_data.convDesc, t2d_msg_data.arrayLength, t2d_msg_data.padA, t2d_msg_data.filterStrideA, t2d_msg_data.upscaleA, t2d_msg_data.mode, t2d_msg_data.dataType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetConvolutionNdDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  free( ____buf );
  
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetDropoutDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetDropoutDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnDropoutDescriptor_t dropoutDesc;
    cudnnHandle_t handle;
    float dropout;
    void * states;
    size_t stateSizeInBytes;
    unsigned long long seed;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetDropoutDescriptor( t2d_msg_data.dropoutDesc, t2d_msg_data.handle, t2d_msg_data.dropout, t2d_msg_data.states, t2d_msg_data.stateSizeInBytes, t2d_msg_data.seed );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetDropoutDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetFilter4dDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetFilter4dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnFilterDescriptor_t filterDesc;
    cudnnDataType_t dataType;
    cudnnTensorFormat_t format;
    int k;
    int c;
    int h;
    int w;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetFilter4dDescriptor( t2d_msg_data.filterDesc, t2d_msg_data.dataType, t2d_msg_data.format, t2d_msg_data.k, t2d_msg_data.c, t2d_msg_data.h, t2d_msg_data.w );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetFilter4dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetFilterNdDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetFilterNdDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnFilterDescriptor_t filterDesc;
    cudnnDataType_t dataType;
    cudnnTensorFormat_t format;
    int nbDims;
    const int * filterDimA ;
    char ____buf[];
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  char *____buf = (char*) malloc ( t2d_msg_data.nbDims * sizeof(const int) );
  if( (t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1 ) {
    t2d_msg_data.filterDimA = (const int *) &____buf[ 0 ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.filterDimA, t2d_msg_data.nbDims * sizeof(const int) ));
  }
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetFilterNdDescriptor( t2d_msg_data.filterDesc, t2d_msg_data.dataType, t2d_msg_data.format, t2d_msg_data.nbDims, t2d_msg_data.filterDimA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetFilterNdDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  free( ____buf );
  
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetLRNDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetLRNDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnLRNDescriptor_t normDesc;
    unsigned int lrnN;
    double lrnAlpha;
    double lrnBeta;
    double lrnK;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetLRNDescriptor( t2d_msg_data.normDesc, t2d_msg_data.lrnN, t2d_msg_data.lrnAlpha, t2d_msg_data.lrnBeta, t2d_msg_data.lrnK );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetLRNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetOpTensorDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetOpTensorDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnOpTensorDescriptor_t opTensorDesc;
    cudnnOpTensorOp_t opTensorOp;
    cudnnDataType_t opTensorCompType;
    cudnnNanPropagation_t opTensorNanOpt;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetOpTensorDescriptor( t2d_msg_data.opTensorDesc, t2d_msg_data.opTensorOp, t2d_msg_data.opTensorCompType, t2d_msg_data.opTensorNanOpt );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetOpTensorDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetPooling2dDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetPooling2dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnPoolingDescriptor_t poolingDesc;
    cudnnPoolingMode_t mode;
    cudnnNanPropagation_t maxpoolingNanOpt;
    int windowHeight;
    int windowWidth;
    int verticalPadding;
    int horizontalPadding;
    int verticalStride;
    int horizontalStride;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetPooling2dDescriptor( t2d_msg_data.poolingDesc, t2d_msg_data.mode, t2d_msg_data.maxpoolingNanOpt, t2d_msg_data.windowHeight, t2d_msg_data.windowWidth, t2d_msg_data.verticalPadding, t2d_msg_data.horizontalPadding, t2d_msg_data.verticalStride, t2d_msg_data.horizontalStride );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetPooling2dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetRNNDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetRNNDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnRNNDescriptor_t rnnDesc;
    int hiddenSize;
    int numLayers;
    cudnnDropoutDescriptor_t dropoutDesc;
    cudnnRNNInputMode_t inputMode;
    cudnnDirectionMode_t direction;
    cudnnRNNMode_t mode;
    cudnnDataType_t dataType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetRNNDescriptor( t2d_msg_data.rnnDesc, t2d_msg_data.hiddenSize, t2d_msg_data.numLayers, t2d_msg_data.dropoutDesc, t2d_msg_data.inputMode, t2d_msg_data.direction, t2d_msg_data.mode, t2d_msg_data.dataType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetRNNDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetSpatialTransformerNdDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetSpatialTransformerNdDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnSpatialTransformerDescriptor_t stDesc;
    cudnnSamplerType_t samplerType;
    cudnnDataType_t dataType;
    int nbDims;
    const int * dimA ;
    char ____buf[];
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  char *____buf = (char*) malloc ( t2d_msg_data.nbDims * sizeof(const int) );
  if( (t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1 ) {
    t2d_msg_data.dimA = (const int *) &____buf[ 0 ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.dimA, t2d_msg_data.nbDims * sizeof(const int) ));
  }
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetSpatialTransformerNdDescriptor( t2d_msg_data.stDesc, t2d_msg_data.samplerType, t2d_msg_data.dataType, t2d_msg_data.nbDims, t2d_msg_data.dimA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetSpatialTransformerNdDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  free( ____buf );
  
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetStream ( void )
{
  hfinf( "[daemon] cudnnSetStream() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudaStream_t streamId;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetStream( t2d_msg_data.handle, t2d_msg_data.streamId );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetStream() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetTensor ( void )
{
  hfinf( "[daemon] cudnnSetTensor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnTensorDescriptor_t yDesc;
    void * y;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } valuePtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetTensor( t2d_msg_data.handle, t2d_msg_data.yDesc, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.valuePtr.val : t2d_msg_data.valuePtr.ptr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetTensor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetTensor4dDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetTensor4dDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnTensorDescriptor_t tensorDesc;
    cudnnTensorFormat_t format;
    cudnnDataType_t dataType;
    int n;
    int c;
    int h;
    int w;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetTensor4dDescriptor( t2d_msg_data.tensorDesc, t2d_msg_data.format, t2d_msg_data.dataType, t2d_msg_data.n, t2d_msg_data.c, t2d_msg_data.h, t2d_msg_data.w );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetTensor4dDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetTensor4dDescriptorEx ( void )
{
  hfinf( "[daemon] cudnnSetTensor4dDescriptorEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnTensorDescriptor_t tensorDesc;
    cudnnDataType_t dataType;
    int n;
    int c;
    int h;
    int w;
    int nStride;
    int cStride;
    int hStride;
    int wStride;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetTensor4dDescriptorEx( t2d_msg_data.tensorDesc, t2d_msg_data.dataType, t2d_msg_data.n, t2d_msg_data.c, t2d_msg_data.h, t2d_msg_data.w, t2d_msg_data.nStride, t2d_msg_data.cStride, t2d_msg_data.hStride, t2d_msg_data.wStride );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetTensor4dDescriptorEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSetTensorNdDescriptor ( void )
{
  hfinf( "[daemon] cudnnSetTensorNdDescriptor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnTensorDescriptor_t tensorDesc;
    cudnnDataType_t dataType;
    int nbDims;
    const int * dimA ;
    const int * strideA ;
    char ____buf[];
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  char *____buf = (char*) malloc ( t2d_msg_data.nbDims * sizeof(const int) + t2d_msg_data.nbDims * sizeof(const int) );
  if( (t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1 ) {
    t2d_msg_data.dimA = (const int *) &____buf[ 0 ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.dimA, t2d_msg_data.nbDims * sizeof(const int) ));
  }
  if( (t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1 ) {
    t2d_msg_data.strideA = (const int *) &____buf[ t2d_msg_data.nbDims * sizeof(const int) ];
    hfcheck( hfcuda_comm_recv( (int *) t2d_msg_data.strideA, t2d_msg_data.nbDims * sizeof(const int) ));
  }
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSetTensorNdDescriptor( t2d_msg_data.tensorDesc, t2d_msg_data.dataType, t2d_msg_data.nbDims, t2d_msg_data.dimA, t2d_msg_data.strideA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSetTensorNdDescriptor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  free( ____buf );
  
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSoftmaxBackward ( void )
{
  hfinf( "[daemon] cudnnSoftmaxBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnSoftmaxAlgorithm_t algo;
    cudnnSoftmaxMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t yDesc;
    const void * y;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSoftmaxBackward( t2d_msg_data.handle, t2d_msg_data.algo, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.yDesc, t2d_msg_data.y, t2d_msg_data.dyDesc, t2d_msg_data.dy, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dxDesc, t2d_msg_data.dx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSoftmaxBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSoftmaxForward ( void )
{
  hfinf( "[daemon] cudnnSoftmaxForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnSoftmaxAlgorithm_t algo;
    cudnnSoftmaxMode_t mode;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSoftmaxForward( t2d_msg_data.handle, t2d_msg_data.algo, t2d_msg_data.mode, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSoftmaxForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSpatialTfGridGeneratorBackward ( void )
{
  hfinf( "[daemon] cudnnSpatialTfGridGeneratorBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cudnnHandle_t handle;
    cudnnSpatialTransformerDescriptor_t stDesc;
    const void * dgrid;
    void * dtheta;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSpatialTfGridGeneratorBackward( t2d_msg_data.handle, t2d_msg_data.stDesc, t2d_msg_data.dgrid, t2d_msg_data.dtheta );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSpatialTfGridGeneratorBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSpatialTfSamplerBackward ( void )
{
  hfinf( "[daemon] cudnnSpatialTfSamplerBackward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnSpatialTransformerDescriptor_t stDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t dxDesc;
    void * dx;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alphaDgrid;
    cudnnTensorDescriptor_t dyDesc;
    const void * dy;
    const void * grid;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } betaDgrid;
    void * dgrid;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSpatialTfSamplerBackward( t2d_msg_data.handle, t2d_msg_data.stDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.dxDesc, t2d_msg_data.dx, (((t2d_msg_data.____CAT2_BITMAP >> 2) & 0x1) ? &t2d_msg_data.alphaDgrid.val : t2d_msg_data.alphaDgrid.ptr), t2d_msg_data.dyDesc, t2d_msg_data.dy, t2d_msg_data.grid, (((t2d_msg_data.____CAT2_BITMAP >> 3) & 0x1) ? &t2d_msg_data.betaDgrid.val : t2d_msg_data.betaDgrid.ptr), t2d_msg_data.dgrid );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSpatialTfSamplerBackward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnSpatialTfSamplerForward ( void )
{
  hfinf( "[daemon] cudnnSpatialTfSamplerForward() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    cudnnSpatialTransformerDescriptor_t stDesc;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    const void * grid;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnSpatialTfSamplerForward( t2d_msg_data.handle, t2d_msg_data.stDesc, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, t2d_msg_data.grid, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnSpatialTfSamplerForward() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cudnnTransformTensor ( void )
{
  hfinf( "[daemon] cudnnTransformTensor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cudnnHandle_t handle;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cudnnTensorDescriptor_t xDesc;
    const void * x;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(double) ? sizeof(double)-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(double) ? sizeof(const void *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cudnnTensorDescriptor_t yDesc;
    void * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cudnnStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cudnnTransformTensor( t2d_msg_data.handle, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xDesc, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.yDesc, t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cudnnTransformTensor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCaxpyi ( void )
{
  hfinf( "[daemon] cusparseCaxpyi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * xVal;
    const int * xInd;
    cuComplex * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCaxpyi( t2d_msg_data.handle, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCaxpyi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsr2csr ( void )
{
  hfinf( "[daemon] cusparseCbsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    cuComplex * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrmm ( void )
{
  hfinf( "[daemon] cusparseCbsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int mb;
    int n;
    int kb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockSize;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrmm( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.kb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockSize, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrmv ( void )
{
  hfinf( "[daemon] cusparseCbsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const cuComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrsm2_analysis ( void )
{
  hfinf( "[daemon] cusparseCbsrsm2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrsm2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrsm2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrsm2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCbsrsm2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    cuComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrsm2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrsm2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrsm2_solve ( void )
{
  hfinf( "[daemon] cusparseCbsrsm2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    const cuComplex * F;
    int ldf;
    cuComplex * X;
    int ldx;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrsm2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrsm2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseCbsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCbsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseCbsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    const cuComplex * f;
    cuComplex * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCbsrxmv ( void )
{
  hfinf( "[daemon] cusparseCbsrxmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int sizeOfMask;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedMaskPtrA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedEndPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const cuComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCbsrxmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.sizeOfMask, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedMaskPtrA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedEndPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCbsrxmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsc2dense ( void )
{
  hfinf( "[daemon] cusparseCcsc2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsc2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsc2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsc2hyb ( void )
{
  hfinf( "[daemon] cusparseCcsc2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsc2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsc2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2bsr ( void )
{
  hfinf( "[daemon] cusparseCcsr2bsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    cuComplex * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2bsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2bsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2csc ( void )
{
  hfinf( "[daemon] cusparseCcsr2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const cuComplex * csrSortedVal;
    const int * csrSortedRowPtr;
    const int * csrSortedColInd;
    cuComplex * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrSortedVal, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.csrSortedColInd, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr, t2d_msg_data.copyValues, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2csr_compress ( void )
{
  hfinf( "[daemon] cusparseCcsr2csr_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descra;
    const cuComplex * csrValA;
    const int * csrColIndA;
    const int * csrRowPtrA;
    int nnzA;
    const int * nnzPerRow;
    cuComplex * csrValC;
    int * csrColIndC;
    int * csrRowPtrC;
    cuComplex tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2csr_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descra, t2d_msg_data.csrValA, t2d_msg_data.csrColIndA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzA, t2d_msg_data.nnzPerRow, t2d_msg_data.csrValC, t2d_msg_data.csrColIndC, t2d_msg_data.csrRowPtrC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2csr_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2csru ( void )
{
  hfinf( "[daemon] cusparseCcsr2csru() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    cuComplex * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2csru( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2csru() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2dense ( void )
{
  hfinf( "[daemon] cusparseCcsr2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseCcsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrC;
    cuComplex * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDim;
    int colBlockDim;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCcsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsr2hyb ( void )
{
  hfinf( "[daemon] cusparseCcsr2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsr2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsr2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrcolor ( void )
{
  hfinf( "[daemon] cusparseCcsrcolor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const float * fractionToColor;
    int * coloring;
    int * reordering;
    cusparseColorInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int ncolors;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrcolor( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.fractionToColor, &d2t_msg.ncolors, t2d_msg_data.coloring, t2d_msg_data.reordering, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrcolor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrgeam ( void )
{
  hfinf( "[daemon] cusparseCcsrgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cusparseMatDescr_t descrB;
    int nnzB;
    const cuComplex * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    cuComplex * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrgeam( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrgemm ( void )
{
  hfinf( "[daemon] cusparseCcsrgemm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    cusparseMatDescr_t descrA;
    int nnzA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const cuComplex * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    cuComplex * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrgemm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrgemm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrgemm2 ( void )
{
  hfinf( "[daemon] cusparseCcsrgemm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const cuComplex * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const cuComplex * csrSortedValD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    cusparseMatDescr_t descrC;
    cuComplex * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
    csrgemm2Info_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrgemm2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedValD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrgemm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrgemm2_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseCcsrgemm2_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    csrgemm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrgemm2_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrgemm2_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrmm ( void )
{
  hfinf( "[daemon] cusparseCcsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrmm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrmm2 ( void )
{
  hfinf( "[daemon] cusparseCcsrmm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrmm2( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrmm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrmv ( void )
{
  hfinf( "[daemon] cusparseCcsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrmv( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrmv_mp ( void )
{
  hfinf( "[daemon] cusparseCcsrmv_mp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrmv_mp( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrmv_mp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsm_analysis ( void )
{
  hfinf( "[daemon] cusparseCcsrsm_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsm_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsm_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsm_solve ( void )
{
  hfinf( "[daemon] cusparseCcsrsm_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const cuComplex * F;
    int ldf;
    cuComplex * X;
    int ldx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsm_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsm_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseCcsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCcsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseCcsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    const cuComplex * f;
    cuComplex * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsv_analysis ( void )
{
  hfinf( "[daemon] cusparseCcsrsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsrsv_solve ( void )
{
  hfinf( "[daemon] cusparseCcsrsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const cuComplex * f;
    cuComplex * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsrsv_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsrsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsru2csr ( void )
{
  hfinf( "[daemon] cusparseCcsru2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    cuComplex * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsru2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsru2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCcsru2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseCcsru2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cuComplex * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCcsru2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCcsru2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCdense2csc ( void )
{
  hfinf( "[daemon] cusparseCdense2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * A;
    int lda;
    const int * nnzPerCol;
    cuComplex * cscSortedValA;
    int * cscSortedRowIndA;
    int * cscSortedColPtrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCdense2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerCol, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCdense2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCdense2csr ( void )
{
  hfinf( "[daemon] cusparseCdense2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * A;
    int lda;
    const int * nnzPerRow;
    cuComplex * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCdense2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCdense2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCdense2hyb ( void )
{
  hfinf( "[daemon] cusparseCdense2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * A;
    int lda;
    const int * nnzPerRow;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCdense2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCdense2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCdotci ( void )
{
  hfinf( "[daemon] cusparseCdotci() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    const cuComplex * xVal;
    const int * xInd;
    const cuComplex * y;
    cuComplex * resultDevHostPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    cuComplex resultDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCdotci( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.resultDevHostPtr : t2d_msg_data.resultDevHostPtr), t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCdotci() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCdoti ( void )
{
  hfinf( "[daemon] cusparseCdoti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    const cuComplex * xVal;
    const int * xInd;
    const cuComplex * y;
    cuComplex * resultDevHostPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    cuComplex resultDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCdoti( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.resultDevHostPtr : t2d_msg_data.resultDevHostPtr), t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCdoti() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgebsr2csr ( void )
{
  hfinf( "[daemon] cusparseCgebsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
    cusparseMatDescr_t descrC;
    cuComplex * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgebsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgebsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgebsr2gebsc ( void )
{
  hfinf( "[daemon] cusparseCgebsr2gebsc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const cuComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
    cuComplex * bscVal;
    int * bscRowInd;
    int * bscColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t baseIdx;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgebsr2gebsc( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.bscVal, t2d_msg_data.bscRowInd, t2d_msg_data.bscColPtr, t2d_msg_data.copyValues, t2d_msg_data.baseIdx, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgebsr2gebsc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgebsr2gebsc_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCgebsr2gebsc_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const cuComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgebsr2gebsc_bufferSize( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgebsr2gebsc_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgebsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseCgebsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    cusparseMatDescr_t descrC;
    cuComplex * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDimC;
    int colBlockDimC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgebsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgebsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgebsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCgebsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    int rowBlockDimC;
    int colBlockDimC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgebsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgebsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgemmi ( void )
{
  hfinf( "[daemon] cusparseCgemmi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    const cuComplex * cscValB;
    const int * cscColPtrB;
    const int * cscRowIndB;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgemmi( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.cscValB, t2d_msg_data.cscColPtrB, t2d_msg_data.cscRowIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgemmi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgemvi ( void )
{
  hfinf( "[daemon] cusparseCgemvi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    const cuComplex * A;
    int lda;
    int nnz;
    const cuComplex * xVal;
    const int * xInd;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
    cusparseIndexBase_t idxBase;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgemvi( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.idxBase, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgemvi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgemvi_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCgemvi_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSize;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgemvi_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, &d2t_msg.pBufferSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgemvi_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgthr ( void )
{
  hfinf( "[daemon] cusparseCgthr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const cuComplex * y;
    cuComplex * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgthr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgthr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCgthrz ( void )
{
  hfinf( "[daemon] cusparseCgthrz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    cuComplex * y;
    cuComplex * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCgthrz( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCgthrz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseChyb2csc ( void )
{
  hfinf( "[daemon] cusparseChyb2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cuComplex * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseChyb2csc( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseChyb2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseChyb2csr ( void )
{
  hfinf( "[daemon] cusparseChyb2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cuComplex * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseChyb2csr( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseChyb2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseChyb2dense ( void )
{
  hfinf( "[daemon] cusparseChyb2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cuComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseChyb2dense( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseChyb2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseChybmv ( void )
{
  hfinf( "[daemon] cusparseChybmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    const cuComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } beta;
    cuComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseChybmv( t2d_msg_data.handle, t2d_msg_data.transA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseChybmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseChybsv_analysis ( void )
{
  hfinf( "[daemon] cusparseChybsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseChybsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseChybsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseChybsv_solve ( void )
{
  hfinf( "[daemon] cusparseChybsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t trans;
    union {
      struct {
        char ___dummy0[sizeof(const cuComplex *) < sizeof(cuComplex) ? sizeof(cuComplex)-sizeof(const cuComplex *) : 0];
        const cuComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuComplex *) > sizeof(cuComplex) ? sizeof(const cuComplex *)-sizeof(cuComplex) : 0];
        cuComplex val;
      };
    } alpha;
    cusparseMatDescr_t descra;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
    const cuComplex * f;
    cuComplex * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseChybsv_solve( t2d_msg_data.handle, t2d_msg_data.trans, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descra, t2d_msg_data.hybA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseChybsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCnnz ( void )
{
  hfinf( "[daemon] cusparseCnnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuComplex * A;
    int lda;
    int * nnzPerRowCol;
    int * nnzTotalDevHostPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCnnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRowCol, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCnnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCnnz_compress ( void )
{
  hfinf( "[daemon] cusparseCnnz_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    cusparseMatDescr_t descr;
    const cuComplex * csrValA;
    const int * csrRowPtrA;
    int * nnzPerRow;
    int * nnzC;
    cuComplex tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCnnz_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.descr, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzPerRow, t2d_msg_data.nnzC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCnnz_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreate ( void )
{
  hfinf( "[daemon] cusparseCreate() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    cusparseHandle_t handle;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreate( &d2t_msg.handle );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreate() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateBsric02Info ( void )
{
  hfinf( "[daemon] cusparseCreateBsric02Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    bsric02Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateBsric02Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateBsric02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateBsrilu02Info ( void )
{
  hfinf( "[daemon] cusparseCreateBsrilu02Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    bsrilu02Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateBsrilu02Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateBsrilu02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateBsrsm2Info ( void )
{
  hfinf( "[daemon] cusparseCreateBsrsm2Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    bsrsm2Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateBsrsm2Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateBsrsm2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateBsrsv2Info ( void )
{
  hfinf( "[daemon] cusparseCreateBsrsv2Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    bsrsv2Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateBsrsv2Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateBsrsv2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateCsrgemm2Info ( void )
{
  hfinf( "[daemon] cusparseCreateCsrgemm2Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    csrgemm2Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateCsrgemm2Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateCsrgemm2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateCsric02Info ( void )
{
  hfinf( "[daemon] cusparseCreateCsric02Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    csric02Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateCsric02Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateCsric02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateCsrilu02Info ( void )
{
  hfinf( "[daemon] cusparseCreateCsrilu02Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    csrilu02Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateCsrilu02Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateCsrilu02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateCsrsv2Info ( void )
{
  hfinf( "[daemon] cusparseCreateCsrsv2Info() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    csrsv2Info_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateCsrsv2Info( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateCsrsv2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateCsru2csrInfo ( void )
{
  hfinf( "[daemon] cusparseCreateCsru2csrInfo() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    csru2csrInfo_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateCsru2csrInfo( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateCsru2csrInfo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateHybMat ( void )
{
  hfinf( "[daemon] cusparseCreateHybMat() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    cusparseHybMat_t hybA;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateHybMat( &d2t_msg.hybA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateHybMat() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateIdentityPermutation ( void )
{
  hfinf( "[daemon] cusparseCreateIdentityPermutation() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int n;
    int * p;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateIdentityPermutation( t2d_msg_data.handle, t2d_msg_data.n, t2d_msg_data.p );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateIdentityPermutation() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateMatDescr ( void )
{
  hfinf( "[daemon] cusparseCreateMatDescr() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    cusparseMatDescr_t descrA;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateMatDescr( &d2t_msg.descrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateMatDescr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreatePruneInfo ( void )
{
  hfinf( "[daemon] cusparseCreatePruneInfo() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    pruneInfo_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreatePruneInfo( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreatePruneInfo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCreateSolveAnalysisInfo ( void )
{
  hfinf( "[daemon] cusparseCreateSolveAnalysisInfo() [CALL]\n" );
  
  struct {
    cusparseStatus_t ____RETVAL;
    cusparseSolveAnalysisInfo_t info;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCreateSolveAnalysisInfo( &d2t_msg.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCreateSolveAnalysisInfo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCsctr ( void )
{
  hfinf( "[daemon] cusparseCsctr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const cuComplex * xVal;
    const int * xInd;
    cuComplex * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCsctr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCsctr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCsr2cscEx ( void )
{
  hfinf( "[daemon] cusparseCsr2cscEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const void * csrSortedVal;
    cudaDataType csrSortedValtype;
    const int * csrSortedRowPtr;
    const int * csrSortedColInd;
    void * cscSortedVal;
    cudaDataType cscSortedValtype;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t idxBase;
    cudaDataType executiontype;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCsr2cscEx( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrSortedVal, t2d_msg_data.csrSortedValtype, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.csrSortedColInd, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedValtype, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr, t2d_msg_data.copyValues, t2d_msg_data.idxBase, t2d_msg_data.executiontype );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCsr2cscEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCsrmvEx ( void )
{
  hfinf( "[daemon] cusparseCsrmvEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseAlgMode_t alg;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    cudaDataType alphatype;
    cusparseMatDescr_t descrA;
    const void * csrValA;
    cudaDataType csrValAtype;
    const int * csrRowPtrA;
    const int * csrColIndA;
    const void * x;
    cudaDataType xtype;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } beta;
    cudaDataType betatype;
    void * y;
    cudaDataType ytype;
    cudaDataType executiontype;
    void * buffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCsrmvEx( t2d_msg_data.handle, t2d_msg_data.alg, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.alphatype, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrValAtype, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.x, t2d_msg_data.xtype, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val[0] : t2d_msg_data.beta.ptr), t2d_msg_data.betatype, t2d_msg_data.y, t2d_msg_data.ytype, t2d_msg_data.executiontype, t2d_msg_data.buffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCsrmvEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCsrmvEx_bufferSize ( void )
{
  hfinf( "[daemon] cusparseCsrmvEx_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseAlgMode_t alg;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    cudaDataType alphatype;
    cusparseMatDescr_t descrA;
    const void * csrValA;
    cudaDataType csrValAtype;
    const int * csrRowPtrA;
    const int * csrColIndA;
    const void * x;
    cudaDataType xtype;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } beta;
    cudaDataType betatype;
    void * y;
    cudaDataType ytype;
    cudaDataType executiontype;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t bufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCsrmvEx_bufferSize( t2d_msg_data.handle, t2d_msg_data.alg, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.alphatype, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrValAtype, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.x, t2d_msg_data.xtype, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val[0] : t2d_msg_data.beta.ptr), t2d_msg_data.betatype, t2d_msg_data.y, t2d_msg_data.ytype, t2d_msg_data.executiontype, &d2t_msg.bufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCsrmvEx_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCsrsv_analysisEx ( void )
{
  hfinf( "[daemon] cusparseCsrsv_analysisEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const void * csrSortedValA;
    cudaDataType csrSortedValAtype;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    cudaDataType executiontype;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCsrsv_analysisEx( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedValAtype, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.executiontype );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCsrsv_analysisEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseCsrsv_solveEx ( void )
{
  hfinf( "[daemon] cusparseCsrsv_solveEx() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    union {
      struct {
        char ___dummy0[sizeof(const void *) < sizeof(uint64_t) * 2 ? sizeof(uint64_t) * 2-sizeof(const void *) : 0];
        const void * ptr;
      };
      struct {
        char ___dummy1[sizeof(const void *) > sizeof(uint64_t) * 2 ? sizeof(const void *)-sizeof(uint64_t) * 2 : 0];
        char val[sizeof(uint64_t) * 2] /* support for 64bit complex */;
      };
    } alpha;
    cudaDataType alphatype;
    cusparseMatDescr_t descrA;
    const void * csrSortedValA;
    cudaDataType csrSortedValAtype;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const void * f;
    cudaDataType ftype;
    void * x;
    cudaDataType xtype;
    cudaDataType executiontype;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseCsrsv_solveEx( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val[0] : t2d_msg_data.alpha.ptr), t2d_msg_data.alphatype, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedValAtype, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.ftype, t2d_msg_data.x, t2d_msg_data.xtype, t2d_msg_data.executiontype );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseCsrsv_solveEx() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDaxpyi ( void )
{
  hfinf( "[daemon] cusparseDaxpyi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * xVal;
    const int * xInd;
    double * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDaxpyi( t2d_msg_data.handle, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDaxpyi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsr2csr ( void )
{
  hfinf( "[daemon] cusparseDbsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    double * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrmm ( void )
{
  hfinf( "[daemon] cusparseDbsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int mb;
    int n;
    int kb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockSize;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrmm( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.kb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockSize, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrmv ( void )
{
  hfinf( "[daemon] cusparseDbsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const double * x;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrsm2_analysis ( void )
{
  hfinf( "[daemon] cusparseDbsrsm2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    const double * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrsm2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrsm2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrsm2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDbsrsm2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    double * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrsm2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrsm2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrsm2_solve ( void )
{
  hfinf( "[daemon] cusparseDbsrsm2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    const double * F;
    int ldf;
    double * X;
    int ldx;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrsm2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrsm2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseDbsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDbsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseDbsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    const double * f;
    double * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDbsrxmv ( void )
{
  hfinf( "[daemon] cusparseDbsrxmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int sizeOfMask;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedMaskPtrA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedEndPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const double * x;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDbsrxmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.sizeOfMask, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedMaskPtrA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedEndPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDbsrxmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsc2dense ( void )
{
  hfinf( "[daemon] cusparseDcsc2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsc2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsc2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsc2hyb ( void )
{
  hfinf( "[daemon] cusparseDcsc2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsc2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsc2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2bsr ( void )
{
  hfinf( "[daemon] cusparseDcsr2bsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    double * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2bsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2bsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2csc ( void )
{
  hfinf( "[daemon] cusparseDcsr2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const double * csrSortedVal;
    const int * csrSortedRowPtr;
    const int * csrSortedColInd;
    double * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrSortedVal, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.csrSortedColInd, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr, t2d_msg_data.copyValues, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2csr_compress ( void )
{
  hfinf( "[daemon] cusparseDcsr2csr_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descra;
    const double * csrValA;
    const int * csrColIndA;
    const int * csrRowPtrA;
    int nnzA;
    const int * nnzPerRow;
    double * csrValC;
    int * csrColIndC;
    int * csrRowPtrC;
    double tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2csr_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descra, t2d_msg_data.csrValA, t2d_msg_data.csrColIndA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzA, t2d_msg_data.nnzPerRow, t2d_msg_data.csrValC, t2d_msg_data.csrColIndC, t2d_msg_data.csrRowPtrC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2csr_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2csru ( void )
{
  hfinf( "[daemon] cusparseDcsr2csru() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    double * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2csru( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2csru() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2dense ( void )
{
  hfinf( "[daemon] cusparseDcsr2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseDcsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrC;
    double * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDim;
    int colBlockDim;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDcsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsr2hyb ( void )
{
  hfinf( "[daemon] cusparseDcsr2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsr2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsr2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrcolor ( void )
{
  hfinf( "[daemon] cusparseDcsrcolor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const double * fractionToColor;
    int * coloring;
    int * reordering;
    cusparseColorInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int ncolors;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrcolor( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.fractionToColor, &d2t_msg.ncolors, t2d_msg_data.coloring, t2d_msg_data.reordering, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrcolor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrgeam ( void )
{
  hfinf( "[daemon] cusparseDcsrgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cusparseMatDescr_t descrB;
    int nnzB;
    const double * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    double * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrgeam( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrgemm ( void )
{
  hfinf( "[daemon] cusparseDcsrgemm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    cusparseMatDescr_t descrA;
    int nnzA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const double * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    double * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrgemm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrgemm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrgemm2 ( void )
{
  hfinf( "[daemon] cusparseDcsrgemm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const double * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const double * csrSortedValD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    cusparseMatDescr_t descrC;
    double * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
    csrgemm2Info_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrgemm2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedValD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrgemm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrgemm2_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseDcsrgemm2_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    csrgemm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrgemm2_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrgemm2_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrmm ( void )
{
  hfinf( "[daemon] cusparseDcsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrmm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrmm2 ( void )
{
  hfinf( "[daemon] cusparseDcsrmm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const double * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrmm2( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrmm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrmv ( void )
{
  hfinf( "[daemon] cusparseDcsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const double * x;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrmv( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrmv_mp ( void )
{
  hfinf( "[daemon] cusparseDcsrmv_mp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const double * x;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrmv_mp( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrmv_mp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsm_analysis ( void )
{
  hfinf( "[daemon] cusparseDcsrsm_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsm_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsm_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsm_solve ( void )
{
  hfinf( "[daemon] cusparseDcsrsm_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const double * F;
    int ldf;
    double * X;
    int ldx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsm_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsm_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseDcsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDcsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseDcsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    const double * f;
    double * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsv_analysis ( void )
{
  hfinf( "[daemon] cusparseDcsrsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsrsv_solve ( void )
{
  hfinf( "[daemon] cusparseDcsrsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const double * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const double * f;
    double * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsrsv_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsrsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsru2csr ( void )
{
  hfinf( "[daemon] cusparseDcsru2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    double * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsru2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsru2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDcsru2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseDcsru2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    double * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDcsru2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDcsru2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDdense2csc ( void )
{
  hfinf( "[daemon] cusparseDdense2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * A;
    int lda;
    const int * nnzPerCol;
    double * cscSortedValA;
    int * cscSortedRowIndA;
    int * cscSortedColPtrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDdense2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerCol, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDdense2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDdense2csr ( void )
{
  hfinf( "[daemon] cusparseDdense2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * A;
    int lda;
    const int * nnzPerRow;
    double * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDdense2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDdense2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDdense2hyb ( void )
{
  hfinf( "[daemon] cusparseDdense2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * A;
    int lda;
    const int * nnzPerRow;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDdense2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDdense2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDdoti ( void )
{
  hfinf( "[daemon] cusparseDdoti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    const double * xVal;
    const int * xInd;
    const double * y;
    double * resultDevHostPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    double resultDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDdoti( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.resultDevHostPtr : t2d_msg_data.resultDevHostPtr), t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDdoti() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroy ( void )
{
  hfinf( "[daemon] cusparseDestroy() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroy( t2d_msg_data.handle );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroy() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyBsric02Info ( void )
{
  hfinf( "[daemon] cusparseDestroyBsric02Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    bsric02Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyBsric02Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyBsric02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyBsrilu02Info ( void )
{
  hfinf( "[daemon] cusparseDestroyBsrilu02Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    bsrilu02Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyBsrilu02Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyBsrilu02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyBsrsm2Info ( void )
{
  hfinf( "[daemon] cusparseDestroyBsrsm2Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    bsrsm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyBsrsm2Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyBsrsm2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyBsrsv2Info ( void )
{
  hfinf( "[daemon] cusparseDestroyBsrsv2Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    bsrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyBsrsv2Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyBsrsv2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyCsrgemm2Info ( void )
{
  hfinf( "[daemon] cusparseDestroyCsrgemm2Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    csrgemm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyCsrgemm2Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyCsrgemm2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyCsric02Info ( void )
{
  hfinf( "[daemon] cusparseDestroyCsric02Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    csric02Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyCsric02Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyCsric02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyCsrilu02Info ( void )
{
  hfinf( "[daemon] cusparseDestroyCsrilu02Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    csrilu02Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyCsrilu02Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyCsrilu02Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyCsrsv2Info ( void )
{
  hfinf( "[daemon] cusparseDestroyCsrsv2Info() [CALL]\n" );
  
  struct __attribute__((packed)) {
    csrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyCsrsv2Info( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyCsrsv2Info() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyCsru2csrInfo ( void )
{
  hfinf( "[daemon] cusparseDestroyCsru2csrInfo() [CALL]\n" );
  
  struct __attribute__((packed)) {
    csru2csrInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyCsru2csrInfo( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyCsru2csrInfo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyHybMat ( void )
{
  hfinf( "[daemon] cusparseDestroyHybMat() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHybMat_t hybA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyHybMat( t2d_msg_data.hybA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyHybMat() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyMatDescr ( void )
{
  hfinf( "[daemon] cusparseDestroyMatDescr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyMatDescr( t2d_msg_data.descrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyMatDescr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroyPruneInfo ( void )
{
  hfinf( "[daemon] cusparseDestroyPruneInfo() [CALL]\n" );
  
  struct __attribute__((packed)) {
    pruneInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroyPruneInfo( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroyPruneInfo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDestroySolveAnalysisInfo ( void )
{
  hfinf( "[daemon] cusparseDestroySolveAnalysisInfo() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDestroySolveAnalysisInfo( t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDestroySolveAnalysisInfo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgebsr2csr ( void )
{
  hfinf( "[daemon] cusparseDgebsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
    cusparseMatDescr_t descrC;
    double * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgebsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgebsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgebsr2gebsc ( void )
{
  hfinf( "[daemon] cusparseDgebsr2gebsc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const double * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
    double * bscVal;
    int * bscRowInd;
    int * bscColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t baseIdx;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgebsr2gebsc( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.bscVal, t2d_msg_data.bscRowInd, t2d_msg_data.bscColPtr, t2d_msg_data.copyValues, t2d_msg_data.baseIdx, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgebsr2gebsc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgebsr2gebsc_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDgebsr2gebsc_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const double * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgebsr2gebsc_bufferSize( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgebsr2gebsc_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgebsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseDgebsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    cusparseMatDescr_t descrC;
    double * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDimC;
    int colBlockDimC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgebsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgebsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgebsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDgebsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const double * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    int rowBlockDimC;
    int colBlockDimC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgebsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgebsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgemmi ( void )
{
  hfinf( "[daemon] cusparseDgemmi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    const double * cscValB;
    const int * cscColPtrB;
    const int * cscRowIndB;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgemmi( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.cscValB, t2d_msg_data.cscColPtrB, t2d_msg_data.cscRowIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgemmi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgemvi ( void )
{
  hfinf( "[daemon] cusparseDgemvi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    const double * A;
    int lda;
    int nnz;
    const double * xVal;
    const int * xInd;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
    cusparseIndexBase_t idxBase;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgemvi( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.idxBase, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgemvi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgemvi_bufferSize ( void )
{
  hfinf( "[daemon] cusparseDgemvi_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSize;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgemvi_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, &d2t_msg.pBufferSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgemvi_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgthr ( void )
{
  hfinf( "[daemon] cusparseDgthr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const double * y;
    double * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgthr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgthr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDgthrz ( void )
{
  hfinf( "[daemon] cusparseDgthrz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    double * y;
    double * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDgthrz( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDgthrz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDhyb2csc ( void )
{
  hfinf( "[daemon] cusparseDhyb2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    double * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDhyb2csc( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDhyb2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDhyb2csr ( void )
{
  hfinf( "[daemon] cusparseDhyb2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    double * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDhyb2csr( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDhyb2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDhyb2dense ( void )
{
  hfinf( "[daemon] cusparseDhyb2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    double * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDhyb2dense( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDhyb2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDhybmv ( void )
{
  hfinf( "[daemon] cusparseDhybmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    const double * x;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } beta;
    double * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDhybmv( t2d_msg_data.handle, t2d_msg_data.transA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDhybmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDhybsv_analysis ( void )
{
  hfinf( "[daemon] cusparseDhybsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDhybsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDhybsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDhybsv_solve ( void )
{
  hfinf( "[daemon] cusparseDhybsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t trans;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } alpha;
    cusparseMatDescr_t descra;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
    const double * f;
    double * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDhybsv_solve( t2d_msg_data.handle, t2d_msg_data.trans, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descra, t2d_msg_data.hybA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDhybsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDnnz ( void )
{
  hfinf( "[daemon] cusparseDnnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const double * A;
    int lda;
    int * nnzPerRowCol;
    int * nnzTotalDevHostPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDnnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRowCol, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDnnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDnnz_compress ( void )
{
  hfinf( "[daemon] cusparseDnnz_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    cusparseMatDescr_t descr;
    const double * csrValA;
    const int * csrRowPtrA;
    int * nnzPerRow;
    int * nnzC;
    double tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDnnz_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.descr, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzPerRow, t2d_msg_data.nnzC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDnnz_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneCsr2csr ( void )
{
  hfinf( "[daemon] cusparseDpruneCsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const double * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    double * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneCsr2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneCsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneCsr2csrByPercentage ( void )
{
  hfinf( "[daemon] cusparseDpruneCsr2csrByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const double * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    float percentage;
    cusparseMatDescr_t descrC;
    double * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneCsr2csrByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneCsr2csrByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneCsr2csrByPercentage_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseDpruneCsr2csrByPercentage_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const double * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    float percentage;
    cusparseMatDescr_t descrC;
    const double * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
    pruneInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneCsr2csrByPercentage_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneCsr2csrByPercentage_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneCsr2csrNnz ( void )
{
  hfinf( "[daemon] cusparseDpruneCsr2csrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const double * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneCsr2csrNnz( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneCsr2csrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneCsr2csrNnzByPercentage ( void )
{
  hfinf( "[daemon] cusparseDpruneCsr2csrNnzByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const double * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    float percentage;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneCsr2csrNnzByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneCsr2csrNnzByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneCsr2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseDpruneCsr2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const double * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    const double * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneCsr2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneCsr2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneDense2csr ( void )
{
  hfinf( "[daemon] cusparseDpruneDense2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const double * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    double * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneDense2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneDense2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneDense2csrByPercentage ( void )
{
  hfinf( "[daemon] cusparseDpruneDense2csrByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    const double * A;
    int lda;
    float percentage;
    cusparseMatDescr_t descrC;
    double * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneDense2csrByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneDense2csrByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneDense2csrByPercentage_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseDpruneDense2csrByPercentage_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    const double * A;
    int lda;
    float percentage;
    cusparseMatDescr_t descrC;
    const double * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
    pruneInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneDense2csrByPercentage_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneDense2csrByPercentage_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneDense2csrNnz ( void )
{
  hfinf( "[daemon] cusparseDpruneDense2csrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const double * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneDense2csrNnz( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneDense2csrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneDense2csrNnzByPercentage ( void )
{
  hfinf( "[daemon] cusparseDpruneDense2csrNnzByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const double * A;
    int lda;
    float percentage;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneDense2csrNnzByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneDense2csrNnzByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDpruneDense2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseDpruneDense2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const double * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const double *) < sizeof(double) ? sizeof(double)-sizeof(const double *) : 0];
        const double * ptr;
      };
      struct {
        char ___dummy1[sizeof(const double *) > sizeof(double) ? sizeof(const double *)-sizeof(double) : 0];
        double val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    const double * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDpruneDense2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDpruneDense2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDroti ( void )
{
  hfinf( "[daemon] cusparseDroti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    double * xVal;
    const int * xInd;
    double * y;
    const double * c;
    const double * s;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDroti( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.c, t2d_msg_data.s, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDroti() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseDsctr ( void )
{
  hfinf( "[daemon] cusparseDsctr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const double * xVal;
    const int * xInd;
    double * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseDsctr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseDsctr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseGetMatDiagType ( void )
{
  hfinf( "[daemon] cusparseGetMatDiagType() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseDiagType_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseGetMatDiagType( t2d_msg_data.descrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseGetMatDiagType() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseGetMatFillMode ( void )
{
  hfinf( "[daemon] cusparseGetMatFillMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseFillMode_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseGetMatFillMode( t2d_msg_data.descrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseGetMatFillMode() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseGetMatIndexBase ( void )
{
  hfinf( "[daemon] cusparseGetMatIndexBase() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseIndexBase_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseGetMatIndexBase( t2d_msg_data.descrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseGetMatIndexBase() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseGetMatType ( void )
{
  hfinf( "[daemon] cusparseGetMatType() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseMatrixType_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseGetMatType( t2d_msg_data.descrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseGetMatType() [DONE]\n" );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseGetStream ( void )
{
  hfinf( "[daemon] cusparseGetStream() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    cudaStream_t streamId;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseGetStream( t2d_msg_data.handle, &d2t_msg.streamId );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseGetStream() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseGetVersion ( void )
{
  hfinf( "[daemon] cusparseGetVersion() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int version;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseGetVersion( t2d_msg_data.handle, &d2t_msg.version );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseGetVersion() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSaxpyi ( void )
{
  hfinf( "[daemon] cusparseSaxpyi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * xVal;
    const int * xInd;
    float * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSaxpyi( t2d_msg_data.handle, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSaxpyi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsr2csr ( void )
{
  hfinf( "[daemon] cusparseSbsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    float * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrmm ( void )
{
  hfinf( "[daemon] cusparseSbsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int mb;
    int n;
    int kb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockSize;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrmm( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.kb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockSize, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrmv ( void )
{
  hfinf( "[daemon] cusparseSbsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const float * x;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrsm2_analysis ( void )
{
  hfinf( "[daemon] cusparseSbsrsm2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    const float * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrsm2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrsm2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrsm2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseSbsrsm2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    float * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrsm2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrsm2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrsm2_solve ( void )
{
  hfinf( "[daemon] cusparseSbsrsm2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    const float * F;
    int ldf;
    float * X;
    int ldx;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrsm2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrsm2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseSbsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseSbsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseSbsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    const float * f;
    float * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSbsrxmv ( void )
{
  hfinf( "[daemon] cusparseSbsrxmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int sizeOfMask;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedMaskPtrA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedEndPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const float * x;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSbsrxmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.sizeOfMask, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedMaskPtrA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedEndPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSbsrxmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsc2dense ( void )
{
  hfinf( "[daemon] cusparseScsc2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsc2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsc2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsc2hyb ( void )
{
  hfinf( "[daemon] cusparseScsc2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsc2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsc2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2bsr ( void )
{
  hfinf( "[daemon] cusparseScsr2bsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    float * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2bsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2bsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2csc ( void )
{
  hfinf( "[daemon] cusparseScsr2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const float * csrSortedVal;
    const int * csrSortedRowPtr;
    const int * csrSortedColInd;
    float * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrSortedVal, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.csrSortedColInd, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr, t2d_msg_data.copyValues, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2csr_compress ( void )
{
  hfinf( "[daemon] cusparseScsr2csr_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descra;
    const float * csrValA;
    const int * csrColIndA;
    const int * csrRowPtrA;
    int nnzA;
    const int * nnzPerRow;
    float * csrValC;
    int * csrColIndC;
    int * csrRowPtrC;
    float tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2csr_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descra, t2d_msg_data.csrValA, t2d_msg_data.csrColIndA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzA, t2d_msg_data.nnzPerRow, t2d_msg_data.csrValC, t2d_msg_data.csrColIndC, t2d_msg_data.csrRowPtrC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2csr_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2csru ( void )
{
  hfinf( "[daemon] cusparseScsr2csru() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    float * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2csru( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2csru() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2dense ( void )
{
  hfinf( "[daemon] cusparseScsr2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseScsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrC;
    float * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDim;
    int colBlockDim;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseScsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsr2hyb ( void )
{
  hfinf( "[daemon] cusparseScsr2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsr2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsr2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrcolor ( void )
{
  hfinf( "[daemon] cusparseScsrcolor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const float * fractionToColor;
    int * coloring;
    int * reordering;
    cusparseColorInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int ncolors;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrcolor( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.fractionToColor, &d2t_msg.ncolors, t2d_msg_data.coloring, t2d_msg_data.reordering, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrcolor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrgeam ( void )
{
  hfinf( "[daemon] cusparseScsrgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    cusparseMatDescr_t descrB;
    int nnzB;
    const float * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    float * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrgeam( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrgemm ( void )
{
  hfinf( "[daemon] cusparseScsrgemm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    cusparseMatDescr_t descrA;
    int nnzA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const float * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    float * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrgemm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrgemm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrgemm2 ( void )
{
  hfinf( "[daemon] cusparseScsrgemm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const float * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const float * csrSortedValD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    cusparseMatDescr_t descrC;
    float * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
    csrgemm2Info_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrgemm2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedValD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrgemm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrgemm2_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseScsrgemm2_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    csrgemm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrgemm2_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrgemm2_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrmm ( void )
{
  hfinf( "[daemon] cusparseScsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrmm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrmm2 ( void )
{
  hfinf( "[daemon] cusparseScsrmm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const float * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrmm2( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrmm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrmv ( void )
{
  hfinf( "[daemon] cusparseScsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const float * x;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrmv( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrmv_mp ( void )
{
  hfinf( "[daemon] cusparseScsrmv_mp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const float * x;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrmv_mp( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrmv_mp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsm_analysis ( void )
{
  hfinf( "[daemon] cusparseScsrsm_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsm_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsm_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsm_solve ( void )
{
  hfinf( "[daemon] cusparseScsrsm_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const float * F;
    int ldf;
    float * X;
    int ldx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsm_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsm_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseScsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseScsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseScsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    const float * f;
    float * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsv_analysis ( void )
{
  hfinf( "[daemon] cusparseScsrsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsrsv_solve ( void )
{
  hfinf( "[daemon] cusparseScsrsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const float * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const float * f;
    float * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsrsv_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsrsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsru2csr ( void )
{
  hfinf( "[daemon] cusparseScsru2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    float * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsru2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsru2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseScsru2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseScsru2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    float * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseScsru2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseScsru2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSdense2csc ( void )
{
  hfinf( "[daemon] cusparseSdense2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * A;
    int lda;
    const int * nnzPerCol;
    float * cscSortedValA;
    int * cscSortedRowIndA;
    int * cscSortedColPtrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSdense2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerCol, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSdense2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSdense2csr ( void )
{
  hfinf( "[daemon] cusparseSdense2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * A;
    int lda;
    const int * nnzPerRow;
    float * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSdense2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSdense2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSdense2hyb ( void )
{
  hfinf( "[daemon] cusparseSdense2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * A;
    int lda;
    const int * nnzPerRow;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSdense2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSdense2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSdoti ( void )
{
  hfinf( "[daemon] cusparseSdoti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    const float * xVal;
    const int * xInd;
    const float * y;
    float * resultDevHostPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    float resultDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSdoti( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.resultDevHostPtr : t2d_msg_data.resultDevHostPtr), t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSdoti() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSetMatDiagType ( void )
{
  hfinf( "[daemon] cusparseSetMatDiagType() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
    cusparseDiagType_t diagType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSetMatDiagType( t2d_msg_data.descrA, t2d_msg_data.diagType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSetMatDiagType() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSetMatFillMode ( void )
{
  hfinf( "[daemon] cusparseSetMatFillMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
    cusparseFillMode_t fillMode;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSetMatFillMode( t2d_msg_data.descrA, t2d_msg_data.fillMode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSetMatFillMode() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSetMatIndexBase ( void )
{
  hfinf( "[daemon] cusparseSetMatIndexBase() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
    cusparseIndexBase_t base;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSetMatIndexBase( t2d_msg_data.descrA, t2d_msg_data.base );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSetMatIndexBase() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSetMatType ( void )
{
  hfinf( "[daemon] cusparseSetMatType() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseMatDescr_t descrA;
    cusparseMatrixType_t type;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSetMatType( t2d_msg_data.descrA, t2d_msg_data.type );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSetMatType() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSetPointerMode ( void )
{
  hfinf( "[daemon] cusparseSetPointerMode() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparsePointerMode_t mode;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSetPointerMode( t2d_msg_data.handle, t2d_msg_data.mode );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSetPointerMode() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSetStream ( void )
{
  hfinf( "[daemon] cusparseSetStream() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cudaStream_t streamId;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSetStream( t2d_msg_data.handle, t2d_msg_data.streamId );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSetStream() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgebsr2csr ( void )
{
  hfinf( "[daemon] cusparseSgebsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
    cusparseMatDescr_t descrC;
    float * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgebsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgebsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgebsr2gebsc ( void )
{
  hfinf( "[daemon] cusparseSgebsr2gebsc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const float * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
    float * bscVal;
    int * bscRowInd;
    int * bscColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t baseIdx;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgebsr2gebsc( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.bscVal, t2d_msg_data.bscRowInd, t2d_msg_data.bscColPtr, t2d_msg_data.copyValues, t2d_msg_data.baseIdx, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgebsr2gebsc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgebsr2gebsc_bufferSize ( void )
{
  hfinf( "[daemon] cusparseSgebsr2gebsc_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const float * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgebsr2gebsc_bufferSize( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgebsr2gebsc_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgebsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseSgebsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    cusparseMatDescr_t descrC;
    float * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDimC;
    int colBlockDimC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgebsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgebsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgebsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseSgebsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const float * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    int rowBlockDimC;
    int colBlockDimC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgebsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgebsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgemmi ( void )
{
  hfinf( "[daemon] cusparseSgemmi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    const float * cscValB;
    const int * cscColPtrB;
    const int * cscRowIndB;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgemmi( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.cscValB, t2d_msg_data.cscColPtrB, t2d_msg_data.cscRowIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgemmi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgemvi ( void )
{
  hfinf( "[daemon] cusparseSgemvi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    const float * A;
    int lda;
    int nnz;
    const float * xVal;
    const int * xInd;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
    cusparseIndexBase_t idxBase;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgemvi( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.idxBase, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgemvi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgemvi_bufferSize ( void )
{
  hfinf( "[daemon] cusparseSgemvi_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSize;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgemvi_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, &d2t_msg.pBufferSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgemvi_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgthr ( void )
{
  hfinf( "[daemon] cusparseSgthr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const float * y;
    float * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgthr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgthr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSgthrz ( void )
{
  hfinf( "[daemon] cusparseSgthrz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    float * y;
    float * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSgthrz( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSgthrz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseShyb2csc ( void )
{
  hfinf( "[daemon] cusparseShyb2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    float * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseShyb2csc( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseShyb2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseShyb2csr ( void )
{
  hfinf( "[daemon] cusparseShyb2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    float * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseShyb2csr( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseShyb2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseShyb2dense ( void )
{
  hfinf( "[daemon] cusparseShyb2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    float * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseShyb2dense( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseShyb2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseShybmv ( void )
{
  hfinf( "[daemon] cusparseShybmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    const float * x;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } beta;
    float * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseShybmv( t2d_msg_data.handle, t2d_msg_data.transA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseShybmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseShybsv_analysis ( void )
{
  hfinf( "[daemon] cusparseShybsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseShybsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseShybsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseShybsv_solve ( void )
{
  hfinf( "[daemon] cusparseShybsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t trans;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } alpha;
    cusparseMatDescr_t descra;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
    const float * f;
    float * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseShybsv_solve( t2d_msg_data.handle, t2d_msg_data.trans, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descra, t2d_msg_data.hybA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseShybsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSnnz ( void )
{
  hfinf( "[daemon] cusparseSnnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const float * A;
    int lda;
    int * nnzPerRowCol;
    int * nnzTotalDevHostPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSnnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRowCol, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSnnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSnnz_compress ( void )
{
  hfinf( "[daemon] cusparseSnnz_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    cusparseMatDescr_t descr;
    const float * csrValA;
    const int * csrRowPtrA;
    int * nnzPerRow;
    int * nnzC;
    float tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSnnz_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.descr, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzPerRow, t2d_msg_data.nnzC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSnnz_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneCsr2csr ( void )
{
  hfinf( "[daemon] cusparseSpruneCsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const float * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    float * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneCsr2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneCsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneCsr2csrByPercentage ( void )
{
  hfinf( "[daemon] cusparseSpruneCsr2csrByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const float * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    float percentage;
    cusparseMatDescr_t descrC;
    float * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneCsr2csrByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneCsr2csrByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneCsr2csrByPercentage_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseSpruneCsr2csrByPercentage_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const float * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    float percentage;
    cusparseMatDescr_t descrC;
    const float * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
    pruneInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneCsr2csrByPercentage_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneCsr2csrByPercentage_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneCsr2csrNnz ( void )
{
  hfinf( "[daemon] cusparseSpruneCsr2csrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const float * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneCsr2csrNnz( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneCsr2csrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneCsr2csrNnzByPercentage ( void )
{
  hfinf( "[daemon] cusparseSpruneCsr2csrNnzByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const float * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    float percentage;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneCsr2csrNnzByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneCsr2csrNnzByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneCsr2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseSpruneCsr2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int nnzA;
    cusparseMatDescr_t descrA;
    const float * csrValA;
    const int * csrRowPtrA;
    const int * csrColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    const float * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneCsr2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnzA, t2d_msg_data.descrA, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneCsr2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneDense2csr ( void )
{
  hfinf( "[daemon] cusparseSpruneDense2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const float * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    float * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneDense2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneDense2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneDense2csrByPercentage ( void )
{
  hfinf( "[daemon] cusparseSpruneDense2csrByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    const float * A;
    int lda;
    float percentage;
    cusparseMatDescr_t descrC;
    float * csrValC;
    const int * csrRowPtrC;
    int * csrColIndC;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneDense2csrByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneDense2csrByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneDense2csrByPercentage_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseSpruneDense2csrByPercentage_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    const float * A;
    int lda;
    float percentage;
    cusparseMatDescr_t descrC;
    const float * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
    pruneInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneDense2csrByPercentage_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneDense2csrByPercentage_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneDense2csrNnz ( void )
{
  hfinf( "[daemon] cusparseSpruneDense2csrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const float * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneDense2csrNnz( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneDense2csrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneDense2csrNnzByPercentage ( void )
{
  hfinf( "[daemon] cusparseSpruneDense2csrNnzByPercentage() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const float * A;
    int lda;
    float percentage;
    cusparseMatDescr_t descrC;
    int * csrRowPtrC;
    int * nnzTotalDevHostPtr;
    pruneInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneDense2csrNnzByPercentage( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.percentage, t2d_msg_data.descrC, t2d_msg_data.csrRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneDense2csrNnzByPercentage() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSpruneDense2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseSpruneDense2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    const float * A;
    int lda;
    union {
      struct {
        char ___dummy0[sizeof(const float *) < sizeof(float) ? sizeof(float)-sizeof(const float *) : 0];
        const float * ptr;
      };
      struct {
        char ___dummy1[sizeof(const float *) > sizeof(float) ? sizeof(const float *)-sizeof(float) : 0];
        float val;
      };
    } threshold;
    cusparseMatDescr_t descrC;
    const float * csrValC;
    const int * csrRowPtrC;
    const int * csrColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSpruneDense2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.A, t2d_msg_data.lda, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.threshold.val : t2d_msg_data.threshold.ptr), t2d_msg_data.descrC, t2d_msg_data.csrValC, t2d_msg_data.csrRowPtrC, t2d_msg_data.csrColIndC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSpruneDense2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSroti ( void )
{
  hfinf( "[daemon] cusparseSroti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    float * xVal;
    const int * xInd;
    float * y;
    const float * c;
    const float * s;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSroti( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.c, t2d_msg_data.s, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSroti() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseSsctr ( void )
{
  hfinf( "[daemon] cusparseSsctr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const float * xVal;
    const int * xInd;
    float * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseSsctr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseSsctr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXbsrsm2_zeroPivot ( void )
{
  hfinf( "[daemon] cusparseXbsrsm2_zeroPivot() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    bsrsm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int position;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXbsrsm2_zeroPivot( t2d_msg_data.handle, t2d_msg_data.info, &d2t_msg.position );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXbsrsm2_zeroPivot() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXbsrsv2_zeroPivot ( void )
{
  hfinf( "[daemon] cusparseXbsrsv2_zeroPivot() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    bsrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int position;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXbsrsv2_zeroPivot( t2d_msg_data.handle, t2d_msg_data.info, &d2t_msg.position );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXbsrsv2_zeroPivot() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcoo2csr ( void )
{
  hfinf( "[daemon] cusparseXcoo2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    const int * cooRowInd;
    int nnz;
    int m;
    int * csrSortedRowPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcoo2csr( t2d_msg_data.handle, t2d_msg_data.cooRowInd, t2d_msg_data.nnz, t2d_msg_data.m, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcoo2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcoosortByColumn ( void )
{
  hfinf( "[daemon] cusparseXcoosortByColumn() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    int * cooRowsA;
    int * cooColsA;
    int * P;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcoosortByColumn( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.cooRowsA, t2d_msg_data.cooColsA, t2d_msg_data.P, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcoosortByColumn() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcoosortByRow ( void )
{
  hfinf( "[daemon] cusparseXcoosortByRow() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    int * cooRowsA;
    int * cooColsA;
    int * P;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcoosortByRow( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.cooRowsA, t2d_msg_data.cooColsA, t2d_msg_data.P, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcoosortByRow() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcoosort_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseXcoosort_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const int * cooRowsA;
    const int * cooColsA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcoosort_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.cooRowsA, t2d_msg_data.cooColsA, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcoosort_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcscsort ( void )
{
  hfinf( "[daemon] cusparseXcscsort() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    const int * cscColPtrA;
    int * cscRowIndA;
    int * P;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcscsort( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.cscColPtrA, t2d_msg_data.cscRowIndA, t2d_msg_data.P, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcscsort() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcscsort_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseXcscsort_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const int * cscColPtrA;
    const int * cscRowIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcscsort_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.cscColPtrA, t2d_msg_data.cscRowIndA, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcscsort_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsr2bsrNnz ( void )
{
  hfinf( "[daemon] cusparseXcsr2bsrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    int * bsrSortedRowPtrC;
    int * nnzTotalDevHostPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsr2bsrNnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.bsrSortedRowPtrC, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsr2bsrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsr2coo ( void )
{
  hfinf( "[daemon] cusparseXcsr2coo() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    const int * csrSortedRowPtr;
    int nnz;
    int m;
    int * cooRowInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsr2coo( t2d_msg_data.handle, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.nnz, t2d_msg_data.m, t2d_msg_data.cooRowInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsr2coo() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsr2gebsrNnz ( void )
{
  hfinf( "[daemon] cusparseXcsr2gebsrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrC;
    int * bsrSortedRowPtrC;
    int rowBlockDim;
    int colBlockDim;
    int * nnzTotalDevHostPtr;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsr2gebsrNnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsr2gebsrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsrgeamNnz ( void )
{
  hfinf( "[daemon] cusparseXcsrgeamNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    int * csrSortedRowPtrC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsrgeamNnz( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedRowPtrC, &d2t_msg.nnzTotalDevHostPtr );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsrgeamNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsrgemm2Nnz ( void )
{
  hfinf( "[daemon] cusparseXcsrgemm2Nnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrD;
    int nnzD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    cusparseMatDescr_t descrC;
    int * csrSortedRowPtrC;
    csrgemm2Info_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsrgemm2Nnz( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.descrC, t2d_msg_data.csrSortedRowPtrC, &d2t_msg.nnzTotalDevHostPtr, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsrgemm2Nnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsrgemmNnz ( void )
{
  hfinf( "[daemon] cusparseXcsrgemmNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    int * csrSortedRowPtrC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsrgemmNnz( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedRowPtrC, &d2t_msg.nnzTotalDevHostPtr );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsrgemmNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsrsort ( void )
{
  hfinf( "[daemon] cusparseXcsrsort() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    const int * csrRowPtrA;
    int * csrColIndA;
    int * P;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsrsort( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, t2d_msg_data.P, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsrsort() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsrsort_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseXcsrsort_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const int * csrRowPtrA;
    const int * csrColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsrsort_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrRowPtrA, t2d_msg_data.csrColIndA, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsrsort_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXcsrsv2_zeroPivot ( void )
{
  hfinf( "[daemon] cusparseXcsrsv2_zeroPivot() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    csrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int position;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXcsrsv2_zeroPivot( t2d_msg_data.handle, t2d_msg_data.info, &d2t_msg.position );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXcsrsv2_zeroPivot() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseXgebsr2gebsrNnz ( void )
{
  hfinf( "[daemon] cusparseXgebsr2gebsrNnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    cusparseMatDescr_t descrC;
    int * bsrSortedRowPtrC;
    int rowBlockDimC;
    int colBlockDimC;
    int * nnzTotalDevHostPtr;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseXgebsr2gebsrNnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr), t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseXgebsr2gebsrNnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZaxpyi ( void )
{
  hfinf( "[daemon] cusparseZaxpyi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * xVal;
    const int * xInd;
    cuDoubleComplex * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZaxpyi( t2d_msg_data.handle, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZaxpyi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsr2csr ( void )
{
  hfinf( "[daemon] cusparseZbsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrmm ( void )
{
  hfinf( "[daemon] cusparseZbsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int mb;
    int n;
    int kb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockSize;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrmm( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.kb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockSize, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrmv ( void )
{
  hfinf( "[daemon] cusparseZbsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const cuDoubleComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrsm2_analysis ( void )
{
  hfinf( "[daemon] cusparseZbsrsm2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrsm2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrsm2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrsm2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZbsrsm2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    cusparseMatDescr_t descrA;
    cuDoubleComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrsm2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrsm2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrsm2_solve ( void )
{
  hfinf( "[daemon] cusparseZbsrsm2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    cusparseOperation_t transXY;
    int mb;
    int n;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int blockSize;
    bsrsm2Info_t info;
    const cuDoubleComplex * F;
    int ldf;
    cuDoubleComplex * X;
    int ldx;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrsm2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.transXY, t2d_msg_data.mb, t2d_msg_data.n, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.blockSize, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrsm2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseZbsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZbsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    cusparseMatDescr_t descrA;
    cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseZbsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int mb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    bsrsv2Info_t info;
    const cuDoubleComplex * f;
    cuDoubleComplex * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.mb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZbsrxmv ( void )
{
  hfinf( "[daemon] cusparseZbsrxmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    cusparseOperation_t transA;
    int sizeOfMask;
    int mb;
    int nb;
    int nnzb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedMaskPtrA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedEndPtrA;
    const int * bsrSortedColIndA;
    int blockDim;
    const cuDoubleComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZbsrxmv( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.transA, t2d_msg_data.sizeOfMask, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedMaskPtrA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedEndPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZbsrxmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsc2dense ( void )
{
  hfinf( "[daemon] cusparseZcsc2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsc2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsc2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsc2hyb ( void )
{
  hfinf( "[daemon] cusparseZcsc2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * cscSortedValA;
    const int * cscSortedRowIndA;
    const int * cscSortedColPtrA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsc2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsc2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2bsr ( void )
{
  hfinf( "[daemon] cusparseZcsr2bsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int blockDim;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2bsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.blockDim, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2bsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2csc ( void )
{
  hfinf( "[daemon] cusparseZcsr2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    const cuDoubleComplex * csrSortedVal;
    const int * csrSortedRowPtr;
    const int * csrSortedColInd;
    cuDoubleComplex * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrSortedVal, t2d_msg_data.csrSortedRowPtr, t2d_msg_data.csrSortedColInd, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr, t2d_msg_data.copyValues, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2csr_compress ( void )
{
  hfinf( "[daemon] cusparseZcsr2csr_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descra;
    const cuDoubleComplex * csrValA;
    const int * csrColIndA;
    const int * csrRowPtrA;
    int nnzA;
    const int * nnzPerRow;
    cuDoubleComplex * csrValC;
    int * csrColIndC;
    int * csrRowPtrC;
    cuDoubleComplex tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2csr_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descra, t2d_msg_data.csrValA, t2d_msg_data.csrColIndA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzA, t2d_msg_data.nnzPerRow, t2d_msg_data.csrValC, t2d_msg_data.csrColIndC, t2d_msg_data.csrRowPtrC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2csr_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2csru ( void )
{
  hfinf( "[daemon] cusparseZcsr2csru() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    cuDoubleComplex * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2csru( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2csru() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2dense ( void )
{
  hfinf( "[daemon] cusparseZcsr2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2dense( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseZcsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDim;
    int colBlockDim;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZcsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsr2hyb ( void )
{
  hfinf( "[daemon] cusparseZcsr2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsr2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsr2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrcolor ( void )
{
  hfinf( "[daemon] cusparseZcsrcolor() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const double * fractionToColor;
    int * coloring;
    int * reordering;
    cusparseColorInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int ncolors;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrcolor( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.fractionToColor, &d2t_msg.ncolors, t2d_msg_data.coloring, t2d_msg_data.reordering, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrcolor() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrgeam ( void )
{
  hfinf( "[daemon] cusparseZcsrgeam() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cusparseMatDescr_t descrB;
    int nnzB;
    const cuDoubleComplex * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrgeam( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrgeam() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrgemm ( void )
{
  hfinf( "[daemon] cusparseZcsrgemm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    cusparseMatDescr_t descrA;
    int nnzA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const cuDoubleComplex * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrgemm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrgemm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrgemm2 ( void )
{
  hfinf( "[daemon] cusparseZcsrgemm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const cuDoubleComplex * csrSortedValB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const cuDoubleComplex * csrSortedValD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * csrSortedValC;
    const int * csrSortedRowPtrC;
    int * csrSortedColIndC;
    csrgemm2Info_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrgemm2( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedValB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedValD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrgemm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrgemm2_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseZcsrgemm2_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    int nnzA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseMatDescr_t descrB;
    int nnzB;
    const int * csrSortedRowPtrB;
    const int * csrSortedColIndB;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cusparseMatDescr_t descrD;
    int nnzD;
    const int * csrSortedRowPtrD;
    const int * csrSortedColIndD;
    csrgemm2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrgemm2_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.nnzA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.descrB, t2d_msg_data.nnzB, t2d_msg_data.csrSortedRowPtrB, t2d_msg_data.csrSortedColIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.descrD, t2d_msg_data.nnzD, t2d_msg_data.csrSortedRowPtrD, t2d_msg_data.csrSortedColIndD, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrgemm2_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrmm ( void )
{
  hfinf( "[daemon] cusparseZcsrmm() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrmm( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrmm() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrmm2 ( void )
{
  hfinf( "[daemon] cusparseZcsrmm2() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseOperation_t transB;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuDoubleComplex * B;
    int ldb;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrmm2( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.transB, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.B, t2d_msg_data.ldb, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrmm2() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrmv ( void )
{
  hfinf( "[daemon] cusparseZcsrmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuDoubleComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrmv( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrmv_mp ( void )
{
  hfinf( "[daemon] cusparseZcsrmv_mp() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    const cuDoubleComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrmv_mp( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrmv_mp() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsm_analysis ( void )
{
  hfinf( "[daemon] cusparseZcsrsm_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsm_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsm_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsm_solve ( void )
{
  hfinf( "[daemon] cusparseZcsrsm_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const cuDoubleComplex * F;
    int ldf;
    cuDoubleComplex * X;
    int ldx;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsm_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.F, t2d_msg_data.ldf, t2d_msg_data.X, t2d_msg_data.ldx );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsm_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsv2_analysis ( void )
{
  hfinf( "[daemon] cusparseZcsrsv2_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsv2_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsv2_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsv2_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZcsrsv2_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsv2_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsv2_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsv2_solve ( void )
{
  hfinf( "[daemon] cusparseZcsrsv2_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    csrsv2Info_t info;
    const cuDoubleComplex * f;
    cuDoubleComplex * x;
    cusparseSolvePolicy_t policy;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsv2_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x, t2d_msg_data.policy, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsv2_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsv_analysis ( void )
{
  hfinf( "[daemon] cusparseZcsrsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int nnz;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsrsv_solve ( void )
{
  hfinf( "[daemon] cusparseZcsrsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * csrSortedValA;
    const int * csrSortedRowPtrA;
    const int * csrSortedColIndA;
    cusparseSolveAnalysisInfo_t info;
    const cuDoubleComplex * f;
    cuDoubleComplex * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsrsv_solve( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsrsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsru2csr ( void )
{
  hfinf( "[daemon] cusparseZcsru2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cusparseMatDescr_t descrA;
    cuDoubleComplex * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsru2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.descrA, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsru2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZcsru2csr_bufferSizeExt ( void )
{
  hfinf( "[daemon] cusparseZcsru2csr_bufferSizeExt() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    int nnz;
    cuDoubleComplex * csrVal;
    const int * csrRowPtr;
    int * csrColInd;
    csru2csrInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    size_t pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZcsru2csr_bufferSizeExt( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, t2d_msg_data.csrVal, t2d_msg_data.csrRowPtr, t2d_msg_data.csrColInd, t2d_msg_data.info, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZcsru2csr_bufferSizeExt() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZdense2csc ( void )
{
  hfinf( "[daemon] cusparseZdense2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * A;
    int lda;
    const int * nnzPerCol;
    cuDoubleComplex * cscSortedValA;
    int * cscSortedRowIndA;
    int * cscSortedColPtrA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZdense2csc( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerCol, t2d_msg_data.cscSortedValA, t2d_msg_data.cscSortedRowIndA, t2d_msg_data.cscSortedColPtrA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZdense2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZdense2csr ( void )
{
  hfinf( "[daemon] cusparseZdense2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * A;
    int lda;
    const int * nnzPerRow;
    cuDoubleComplex * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZdense2csr( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZdense2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZdense2hyb ( void )
{
  hfinf( "[daemon] cusparseZdense2hyb() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * A;
    int lda;
    const int * nnzPerRow;
    cusparseHybMat_t hybA;
    int userEllWidth;
    cusparseHybPartition_t partitionType;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZdense2hyb( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRow, t2d_msg_data.hybA, t2d_msg_data.userEllWidth, t2d_msg_data.partitionType );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZdense2hyb() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZdotci ( void )
{
  hfinf( "[daemon] cusparseZdotci() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    const cuDoubleComplex * xVal;
    const int * xInd;
    const cuDoubleComplex * y;
    cuDoubleComplex * resultDevHostPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    cuDoubleComplex resultDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZdotci( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.resultDevHostPtr : t2d_msg_data.resultDevHostPtr), t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZdotci() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZdoti ( void )
{
  hfinf( "[daemon] cusparseZdoti() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int nnz;
    const cuDoubleComplex * xVal;
    const int * xInd;
    const cuDoubleComplex * y;
    cuDoubleComplex * resultDevHostPtr;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    cuDoubleComplex resultDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZdoti( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.resultDevHostPtr : t2d_msg_data.resultDevHostPtr), t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZdoti() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgebsr2csr ( void )
{
  hfinf( "[daemon] cusparseZgebsr2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDim;
    int colBlockDim;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * csrSortedValC;
    int * csrSortedRowPtrC;
    int * csrSortedColIndC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgebsr2csr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.descrC, t2d_msg_data.csrSortedValC, t2d_msg_data.csrSortedRowPtrC, t2d_msg_data.csrSortedColIndC );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgebsr2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgebsr2gebsc ( void )
{
  hfinf( "[daemon] cusparseZgebsr2gebsc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const cuDoubleComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
    cuDoubleComplex * bscVal;
    int * bscRowInd;
    int * bscColPtr;
    cusparseAction_t copyValues;
    cusparseIndexBase_t baseIdx;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgebsr2gebsc( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, t2d_msg_data.bscVal, t2d_msg_data.bscRowInd, t2d_msg_data.bscColPtr, t2d_msg_data.copyValues, t2d_msg_data.baseIdx, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgebsr2gebsc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgebsr2gebsc_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZgebsr2gebsc_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int mb;
    int nb;
    int nnzb;
    const cuDoubleComplex * bsrSortedVal;
    const int * bsrSortedRowPtr;
    const int * bsrSortedColInd;
    int rowBlockDim;
    int colBlockDim;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgebsr2gebsc_bufferSize( t2d_msg_data.handle, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.bsrSortedVal, t2d_msg_data.bsrSortedRowPtr, t2d_msg_data.bsrSortedColInd, t2d_msg_data.rowBlockDim, t2d_msg_data.colBlockDim, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgebsr2gebsc_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgebsr2gebsr ( void )
{
  hfinf( "[daemon] cusparseZgebsr2gebsr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    cusparseMatDescr_t descrC;
    cuDoubleComplex * bsrSortedValC;
    int * bsrSortedRowPtrC;
    int * bsrSortedColIndC;
    int rowBlockDimC;
    int colBlockDimC;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgebsr2gebsr( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.descrC, t2d_msg_data.bsrSortedValC, t2d_msg_data.bsrSortedRowPtrC, t2d_msg_data.bsrSortedColIndC, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgebsr2gebsr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgebsr2gebsr_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZgebsr2gebsr_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int mb;
    int nb;
    int nnzb;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * bsrSortedValA;
    const int * bsrSortedRowPtrA;
    const int * bsrSortedColIndA;
    int rowBlockDimA;
    int colBlockDimA;
    int rowBlockDimC;
    int colBlockDimC;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSizeInBytes;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgebsr2gebsr_bufferSize( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.mb, t2d_msg_data.nb, t2d_msg_data.nnzb, t2d_msg_data.descrA, t2d_msg_data.bsrSortedValA, t2d_msg_data.bsrSortedRowPtrA, t2d_msg_data.bsrSortedColIndA, t2d_msg_data.rowBlockDimA, t2d_msg_data.colBlockDimA, t2d_msg_data.rowBlockDimC, t2d_msg_data.colBlockDimC, &d2t_msg.pBufferSizeInBytes );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgebsr2gebsr_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgemmi ( void )
{
  hfinf( "[daemon] cusparseZgemmi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    int m;
    int n;
    int k;
    int nnz;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    const cuDoubleComplex * cscValB;
    const int * cscColPtrB;
    const int * cscRowIndB;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * C;
    int ldc;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgemmi( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.k, t2d_msg_data.nnz, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.cscValB, t2d_msg_data.cscColPtrB, t2d_msg_data.cscRowIndB, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.C, t2d_msg_data.ldc );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgemmi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgemvi ( void )
{
  hfinf( "[daemon] cusparseZgemvi() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    const cuDoubleComplex * A;
    int lda;
    int nnz;
    const cuDoubleComplex * xVal;
    const int * xInd;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
    cusparseIndexBase_t idxBase;
    void * pBuffer;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgemvi( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y, t2d_msg_data.idxBase, t2d_msg_data.pBuffer );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgemvi() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgemvi_bufferSize ( void )
{
  hfinf( "[daemon] cusparseZgemvi_bufferSize() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    int m;
    int n;
    int nnz;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int pBufferSize;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgemvi_bufferSize( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.nnz, &d2t_msg.pBufferSize );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgemvi_bufferSize() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgthr ( void )
{
  hfinf( "[daemon] cusparseZgthr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const cuDoubleComplex * y;
    cuDoubleComplex * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgthr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgthr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZgthrz ( void )
{
  hfinf( "[daemon] cusparseZgthrz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    cuDoubleComplex * y;
    cuDoubleComplex * xVal;
    const int * xInd;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZgthrz( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.y, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZgthrz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZhyb2csc ( void )
{
  hfinf( "[daemon] cusparseZhyb2csc() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cuDoubleComplex * cscSortedVal;
    int * cscSortedRowInd;
    int * cscSortedColPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZhyb2csc( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.cscSortedVal, t2d_msg_data.cscSortedRowInd, t2d_msg_data.cscSortedColPtr );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZhyb2csc() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZhyb2csr ( void )
{
  hfinf( "[daemon] cusparseZhyb2csr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cuDoubleComplex * csrSortedValA;
    int * csrSortedRowPtrA;
    int * csrSortedColIndA;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZhyb2csr( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.csrSortedValA, t2d_msg_data.csrSortedRowPtrA, t2d_msg_data.csrSortedColIndA );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZhyb2csr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZhyb2dense ( void )
{
  hfinf( "[daemon] cusparseZhyb2dense() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cuDoubleComplex * A;
    int lda;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZhyb2dense( t2d_msg_data.handle, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.A, t2d_msg_data.lda );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZhyb2dense() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZhybmv ( void )
{
  hfinf( "[daemon] cusparseZhybmv() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    const cuDoubleComplex * x;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } beta;
    cuDoubleComplex * y;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZhybmv( t2d_msg_data.handle, t2d_msg_data.transA, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.x, (((t2d_msg_data.____CAT2_BITMAP >> 1) & 0x1) ? &t2d_msg_data.beta.val : t2d_msg_data.beta.ptr), t2d_msg_data.y );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZhybmv() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZhybsv_analysis ( void )
{
  hfinf( "[daemon] cusparseZhybsv_analysis() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    cusparseOperation_t transA;
    cusparseMatDescr_t descrA;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZhybsv_analysis( t2d_msg_data.handle, t2d_msg_data.transA, t2d_msg_data.descrA, t2d_msg_data.hybA, t2d_msg_data.info );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZhybsv_analysis() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZhybsv_solve ( void )
{
  hfinf( "[daemon] cusparseZhybsv_solve() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseOperation_t trans;
    union {
      struct {
        char ___dummy0[sizeof(const cuDoubleComplex *) < sizeof(cuDoubleComplex) ? sizeof(cuDoubleComplex)-sizeof(const cuDoubleComplex *) : 0];
        const cuDoubleComplex * ptr;
      };
      struct {
        char ___dummy1[sizeof(const cuDoubleComplex *) > sizeof(cuDoubleComplex) ? sizeof(const cuDoubleComplex *)-sizeof(cuDoubleComplex) : 0];
        cuDoubleComplex val;
      };
    } alpha;
    cusparseMatDescr_t descra;
    cusparseHybMat_t hybA;
    cusparseSolveAnalysisInfo_t info;
    const cuDoubleComplex * f;
    cuDoubleComplex * x;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZhybsv_solve( t2d_msg_data.handle, t2d_msg_data.trans, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &t2d_msg_data.alpha.val : t2d_msg_data.alpha.ptr), t2d_msg_data.descra, t2d_msg_data.hybA, t2d_msg_data.info, t2d_msg_data.f, t2d_msg_data.x );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZhybsv_solve() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZnnz ( void )
{
  hfinf( "[daemon] cusparseZnnz() [CALL]\n" );
  
  struct __attribute__((packed)) {
    uint8_t ____CAT2_BITMAP;
    cusparseHandle_t handle;
    cusparseDirection_t dirA;
    int m;
    int n;
    cusparseMatDescr_t descrA;
    const cuDoubleComplex * A;
    int lda;
    int * nnzPerRowCol;
    int * nnzTotalDevHostPtr;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
    int nnzTotalDevHostPtr;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZnnz( t2d_msg_data.handle, t2d_msg_data.dirA, t2d_msg_data.m, t2d_msg_data.n, t2d_msg_data.descrA, t2d_msg_data.A, t2d_msg_data.lda, t2d_msg_data.nnzPerRowCol, (((t2d_msg_data.____CAT2_BITMAP >> 0) & 0x1) ? &d2t_msg.nnzTotalDevHostPtr : t2d_msg_data.nnzTotalDevHostPtr) );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZnnz() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZnnz_compress ( void )
{
  hfinf( "[daemon] cusparseZnnz_compress() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int m;
    cusparseMatDescr_t descr;
    const cuDoubleComplex * csrValA;
    const int * csrRowPtrA;
    int * nnzPerRow;
    int * nnzC;
    cuDoubleComplex tol;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZnnz_compress( t2d_msg_data.handle, t2d_msg_data.m, t2d_msg_data.descr, t2d_msg_data.csrValA, t2d_msg_data.csrRowPtrA, t2d_msg_data.nnzPerRow, t2d_msg_data.nnzC, t2d_msg_data.tol );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZnnz_compress() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



/*************************************************
* DO NOT EDIT - AUTOMATICALLY GENERATED FUNCTION *
*************************************************/
hferr_t
handle_HFCUDA_cusparseZsctr ( void )
{
  hfinf( "[daemon] cusparseZsctr() [CALL]\n" );
  
  struct __attribute__((packed)) {
    cusparseHandle_t handle;
    int nnz;
    const cuDoubleComplex * xVal;
    const int * xInd;
    cuDoubleComplex * y;
    cusparseIndexBase_t idxBase;
  } t2d_msg_data;
  
  hfcheck( hfcuda_comm_recv( &t2d_msg_data, sizeof(t2d_msg_data) ));
  struct {
    cusparseStatus_t ____RETVAL;
  } d2t_msg;
  d2t_msg.____RETVAL = cusparseZsctr( t2d_msg_data.handle, t2d_msg_data.nnz, t2d_msg_data.xVal, t2d_msg_data.xInd, t2d_msg_data.y, t2d_msg_data.idxBase );
  
  hfcheck( hfcuda_comm_send( &d2t_msg, sizeof(d2t_msg) ));
  hfinf( "[daemon] cusparseZsctr() [DONE] status=%d\n", d2t_msg.____RETVAL );
  
  return HFOK;
}



