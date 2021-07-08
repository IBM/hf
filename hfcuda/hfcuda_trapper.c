#include "hfcuda_common.c"

#include "modules/hfcuda_am.c"
#include "modules/hfcuda_comm.c"
#include "modules/hfcuda_cudnnDataType.c"
#include "modules/hfcuda_package.h"
#include "modules/hfcuda_functions.h"
#include "modules/hfcuda_vdm.c"

#include "wrappers/io/trapper.c"
#include "wrappers/driver_trapper.c"

#include "wrappers/cudart/trapper/device.c"
#include "wrappers/cudart/trapper/execution.c"
#include "wrappers/cudart/trapper/memory.c"
#include "wrappers/cudart/trapper/profiler.c"

#include "wrappers/cuda_driverapi/trapper/unified_addressing.c"

#include "wrappers/trapper_fnc_auto.c"

__attribute__((constructor)) void trapper_init(void)
{
    int gl_hfcuda_comm_port;
    hfcomm_type_t gl_hfcuda_comm_type;
    hfcheck(hfcuda_comm_init(&gl_hfcuda_comm_port, &gl_hfcuda_comm_type));
    hfcheck(hfcuda_vdm_init(gl_hfcuda_comm_port, gl_hfcuda_comm_type));
}

