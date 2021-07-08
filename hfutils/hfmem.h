#ifndef _HFMEM_H_
#define _HFMEM_H_

#define ONLY_MSPACES 1 // only use mspace from dl_malloc
#include "dl_malloc.h"

#define hf_malloc( SPACE, BYTES )                  mspace_malloc( SPACE, BYTES )
#define hf_calloc( SPACE, NELEM, ELEM_SIZE )       mspace_calloc( SPACE, NELEM, ELEM_SIZE )
#define hf_realloc( SPACE, PTR, NEWSIZE )          mspace_realloc( SPACE, PTR, NEWSIZE )
#define hf_realloc_in_place( SPACE, PTR, NEWSIZE ) mspace_realloc_in_place( SPACE, PTR, NEWSIZE )
#define hf_memalign( SPACE, ALIGN, BYTES )         mspace_memalign( SPACE, ALIGN, BYTES )
#define hf_free( SPACE, PTR )                      mspace_free( SPACE, PTR )

// should be called only after setDevice() .. or if the GPU is actually being used
int hf_mem_init( mspace* hf_gpu_mem );

#endif /* #ifndef _HFMEM_H_ */
