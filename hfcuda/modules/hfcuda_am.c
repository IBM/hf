#include <stdint.h>
#include "freebsd_tree.h"

typedef struct hfcuda_am_tree_t hfcuda_am_tree_t;
typedef struct hfcuda_am_node_t hfcuda_am_node_t;
struct hfcuda_am_node_t {  
   RB_ENTRY(hfcuda_am_node_t) entry_;
   uintptr_t addr_bgn;
   uintptr_t addr_end;
   bool isdevice;
   int deviceid;
   char hostname[];
};

static int hfcuda_am_tree_cmp( hfcuda_am_node_t *a,
                               hfcuda_am_node_t *b )
{
  // first check the device id
  if(a->deviceid < b->deviceid)
    return -1;
  if(b->deviceid < a->deviceid)
    return 1;

  // if the same, we have to look now on the addresses
  if(a->addr_end < b->addr_bgn)
    return -1;
  if(b->addr_end < a->addr_bgn)
    return 1;

  return 0;
}

// for now we have a hash of 3 elements and subsequently a RB-tree
__thread RB_HEAD(hfcuda_am_tree_t, hfcuda_am_node_t) hfcuda_am_list_head[] = {
  RB_INITIALIZER(&hfcuda_am_list_head[0]),
  RB_INITIALIZER(&hfcuda_am_list_head[1]),
  RB_INITIALIZER(&hfcuda_am_list_head[2])
};
int hfcuda_am_list_hashsize = sizeof(hfcuda_am_list_head) / sizeof(hfcuda_am_list_head[0]);
RB_GENERATE_STATIC(hfcuda_am_tree_t, hfcuda_am_node_t,
                   entry_, hfcuda_am_tree_cmp);  

void hfcuda_dump_map( int deviceid )
{
    int devhash = deviceid % hfcuda_am_list_hashsize;
    hfcuda_am_node_t* sln;
    for (sln = RB_MIN(hfcuda_am_tree_t, &hfcuda_am_list_head[ devhash ]);
         sln != NULL;
         sln = RB_NEXT(hfcuda_am_tree_t, &hfcuda_am_list_head[ devhash ], sln))
    {  
        hferr("[am] device %d: [0x%016lx-0x%016lx]\n", sln->deviceid, sln->addr_bgn, sln->addr_end);
    }
}

hfcuda_am_node_t* hfcuda_am_mem_check( void* ptr, int deviceid )
{
    hfcuda_am_node_t search_ptr;
    search_ptr.addr_bgn = (uintptr_t)ptr;
    search_ptr.addr_end = ((uintptr_t)ptr);
    search_ptr.deviceid = deviceid;
    int devhash = deviceid % hfcuda_am_list_hashsize;
    return RB_FIND(hfcuda_am_tree_t,
                   &hfcuda_am_list_head[ devhash ],
                   &search_ptr);
}

hferr_t hfcuda_am_add_mem_dev( void* ptr, size_t size, int deviceid )
{
    hfcuda_am_node_t* n = (hfcuda_am_node_t*) malloc (sizeof(hfcuda_am_node_t) + 1);
    if(n == NULL)
        return HFERR;      

    n->addr_bgn = (uintptr_t)ptr;
    n->addr_end = ((uintptr_t)ptr) + size - 1;
    n->isdevice = true;
    n->deviceid = deviceid;
    n->hostname[0] = '\0';

    int devhash = deviceid % hfcuda_am_list_hashsize;
    hfcuda_am_node_t* res = RB_INSERT(hfcuda_am_tree_t,
                                      &hfcuda_am_list_head[ devhash ],
                                      n);
    if(res != NULL) { // we hit something ... not good :-(
        hferr("[am] pointer with overlapping rang exists! ptr=0x%016lx device=%d\n", ptr, deviceid );
        hfcuda_dump_map( deviceid );
        free(n);
        return HFERR;
    }

    hfdeb("[am] added pointer: ptr=0x%016lx size=%lu device=%d\n", ptr, size, deviceid );

    return HFOK;
}

hferr_t hfcuda_am_del_mem_dev( void *ptr, int deviceid )
{
    hfcuda_am_node_t* n = hfcuda_am_mem_check( ptr, deviceid );
    if( n == NULL ) {
        hferr("[am] couldn't find: ptr=0x%016lx device=%d\n", ptr, deviceid );
        hfcuda_dump_map( deviceid );
        return HFERR;
    }

    int devhash = deviceid % hfcuda_am_list_hashsize;
    hfcuda_am_node_t* ret = RB_REMOVE( hfcuda_am_tree_t,
                                       &hfcuda_am_list_head[ devhash ],
                                       n );
    if( ret != n ) {
        hferr("[am] couldn't delete: ptr=0x%016lx device=%d\n", ptr, deviceid );
        return HFERR;
    }

    hfdeb("[am] deleted pointer: ptr=0x%016lx device=%d\n", ptr, deviceid );

    return HFOK;
}







// Variables related to host pointers

typedef enum rPtrAttr {
    rPtrHost,
    rPtrPointer,
    rPtrSize,
} rPtrAttr_t;

struct r_ptrs_t {
    char*               host;
    void                *rPtr;
    UT_hash_handle      hh;  
};

struct h_ptrs_t {
    void                *lPtr;
    size_t              size;
    struct r_ptrs_t     *rPtrs;
    UT_hash_handle      hh;
    pthread_mutex_t     lock;
};

struct h_ptrs_t *m_pointers = NULL;

// -----------------------------------------------------------------------------

hferr_t __hfcuda_am_get_lPtr_hash(
        struct h_ptrs_t** element,
        void* lPtr,
        ptrdiff_t *offset)
{
    *element = NULL;

    if (offset != NULL) {
        ptrdiff_t offset_tmp = 0;
        *offset = offset_tmp;
    }

    // Find the absolute local pointer (first pointer in a memory region) in the hash table
    struct h_ptrs_t *s = NULL;
    HASH_FIND_PTR(m_pointers, &lPtr, s);
    if (s) {
       *element = s;
       return HFOK;
    }

    // Otherwise, find the relative local pointer (any pointer in a memory region)
    for(s=m_pointers; s != NULL; s=(struct h_ptrs_t*)(s->hh.next)) {
        // Calculate the local memory region
        uintptr_t lRegionStart = (uintptr_t) s->lPtr;
        uintptr_t lRegionEnd = (uintptr_t) s->lPtr + (uintptr_t) s->size;

        if(((uintptr_t) lPtr) >= lRegionStart && ((uintptr_t) lPtr) < lRegionEnd)
        {
            *element = s;
            if (offset != NULL) {
                ptrdiff_t offset_tmp = ((char *) lPtr - (char *) s->lPtr);
                *offset = offset_tmp;
            }

            return HFOK;
        }
    }
    hfdeb("[am] the local host pointer=%p is not managed\n", lPtr);
    return HFErrorHostAddrNotManaged;
}


// Add a host pointer to manager.
// -----------------------------------------------------------------------------
//


hferr_t hfcuda_am_add_host_pointer(void* lPtr, void* rPtr, size_t size, char* host)
{
    // Create hash element
    struct h_ptrs_t *s;
    hferr_t hferr = __hfcuda_am_get_lPtr_hash(&s, lPtr, NULL);

    // If local pointer does not exist in the hash table, create a new one
    if ((s == NULL) && (hferr != HFOK)) {
        s = malloc(sizeof(struct h_ptrs_t));
        s->lPtr = lPtr;
        s->rPtrs = NULL;
        s->size = size;
        HASH_ADD_PTR(m_pointers, lPtr, s);
    }

    // A remote pointer will not exist only if the application has created a 
    // local pointer that is pinned and called the function cudaHostRegister.
    if (rPtr) {
        // Create remote pointer element
        struct r_ptrs_t *sRPtr;
        sRPtr = malloc(sizeof(struct r_ptrs_t));
        sRPtr->host = host;
        sRPtr->rPtr = rPtr;

        // Add remote pointer to the hash element
        HASH_ADD_PTR(s->rPtrs, host, sRPtr);
    }

    hfdeb("[am] added the host pointer: lPtr=%p rPtr=%p size=%lu host=%s\n",
           lPtr, rPtr, size, host);

    return HFOK;
}

// -----------------------------------------------------------------------------
hferr_t __setAttribute(
        void** attr,
        struct h_ptrs_t *s,
        char* hostName,
        rPtrAttr_t attrType,
        ptrdiff_t offset)
{
    struct r_ptrs_t *sRPtr;

    switch (attrType) {
        case rPtrSize:
            hfdeb("[am] the memory region has size=%lu\n", s->size);
            *attr = &s->size;
            return HFOK;

        case rPtrPointer:
            HASH_FIND_PTR(s->rPtrs, &hostName, sRPtr);
            if (sRPtr){
                void* ptr = (void*) ((char *) sRPtr->rPtr) + offset;
                hfdeb("[am] the remote pointer%p is in the memory region [%p, %p]"
                      "in host=%s with offset=%lu\n",
                      ptr,
                      sRPtr->rPtr,
                      (void*) ((char *) sRPtr->rPtr + s->size), 
                      sRPtr->host,
                      offset);
                *attr = ptr;
                return HFOK;
            }
        case rPtrHost:
            if (sRPtr){
                hfdeb("[am] the remote pointer=%p is in host=%s\n",
                      sRPtr->rPtr, sRPtr->host);
                *attr = sRPtr->host;
                return HFOK;
            }
            break;
    }

    hfdeb("[am] the local pointer=%p exist in the hash, but is not mapped in host=%s\n",
        s->lPtr, hostName);
    return HFErrorRemoteHostAddrDoesNotExist;

}

// -----------------------------------------------------------------------------


hferr_t hfcuda_am_get_host_pointer_attr(
        void** attr,
        void* lPtr,
        char* hostName,
        rPtrAttr_t attrType)
{
    struct h_ptrs_t *s;
    ptrdiff_t offset;
    if (attr)
        *attr = NULL;

    hferr_t hferr = __hfcuda_am_get_lPtr_hash(&s, lPtr, &offset);

    if ((s != NULL) && (hferr == HFOK)){
        hfdeb("[am] getting attr of the local pointer=%p\n", lPtr);
        return __setAttribute(attr, s, hostName, attrType, offset);
    }

    return hferr;
}

// -----------------------------------------------------------------------------


