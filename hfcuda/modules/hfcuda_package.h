#ifndef _HFCUDA_PACKAGE_H_
#define _HFCUDA_PACKAGE_H_

#include "modules/hfcuda_functions.h"

typedef struct  {
    hfcuda_function_t func;
} __attribute__((packed)) hf_msgdescr_t;

#define HF_MSGDESCR_SET( PHEAD, FUNC ) \
    ((PHEAD)->func = (FUNC))

#endif /* #ifndef _HFCUDA_PACKAGE_H_ */
