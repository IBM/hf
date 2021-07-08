#include "freebsd_tree.h"

typedef struct hfcuda_cudnnDataType_tree_t hfcuda_cudnnDataType_tree_t;
typedef struct hfcuda_cudnnDataType_node_t hfcuda_cudnnDataType_node_t;
struct hfcuda_cudnnDataType_node_t {  
   RB_ENTRY(hfcuda_cudnnDataType_node_t) entry_;
   int deviceid;
   cudnnTensorDescriptor_t descr;
   cudnnDataType_t dataType;
};

static int hfcuda_cudnnDataType_tree_cmp( hfcuda_cudnnDataType_node_t *a,
                                          hfcuda_cudnnDataType_node_t *b )
{
  // first check the device id
  if(a->deviceid < b->deviceid)
    return -1;
  if(b->deviceid < a->deviceid)
    return 1;

  // if the same, we have to look on the descriptor!
  if(a->descr < b->descr)
    return -1;
  if(b->descr < a->descr)
    return 1;

  return 0;
}

// for now we have a hash of 3 elements and subsequently a RB-tree
__thread RB_HEAD(hfcuda_cudnnDataType_tree_t, hfcuda_cudnnDataType_node_t) hfcuda_cudnnDataType_list_head[] = {
  RB_INITIALIZER(&hfcuda_cudnnDataType_list_head[0]),
  RB_INITIALIZER(&hfcuda_cudnnDataType_list_head[1]),
  RB_INITIALIZER(&hfcuda_cudnnDataType_list_head[2])
};
int hfcuda_cudnnDataType_list_hashsize = sizeof(hfcuda_cudnnDataType_list_head) / sizeof(hfcuda_cudnnDataType_list_head[0]);
RB_GENERATE_STATIC(hfcuda_cudnnDataType_tree_t, hfcuda_cudnnDataType_node_t,
                   entry_, hfcuda_cudnnDataType_tree_cmp);  

void ____hfcuda_dump_map_cudnnDataType( int deviceid )
{
    int devhash = deviceid % hfcuda_cudnnDataType_list_hashsize;
    hfcuda_cudnnDataType_node_t* sln;
    for (sln = RB_MIN(hfcuda_cudnnDataType_tree_t, &hfcuda_cudnnDataType_list_head[ devhash ]);
         sln != NULL;
         sln = RB_NEXT(hfcuda_cudnnDataType_tree_t, &hfcuda_cudnnDataType_list_head[ devhash ], sln))
    {  
        hferr("[cudnnDataType] device %d: [0x%016lx]\n", sln->deviceid, sln->descr);
    }
}

hfcuda_cudnnDataType_node_t* ____hfcuda_get_cudnnDataType_node( int deviceid, cudnnTensorDescriptor_t descr )
{
    hfcuda_cudnnDataType_node_t search_ptr;
    search_ptr.deviceid = deviceid;
    search_ptr.descr = descr;
    int devhash = deviceid % hfcuda_cudnnDataType_list_hashsize;
    return RB_FIND(hfcuda_cudnnDataType_tree_t,
                   &hfcuda_cudnnDataType_list_head[ devhash ],
                   &search_ptr);
}

hferr_t hfcuda_set_cudnnDataType( int deviceid, cudnnTensorDescriptor_t descr, cudnnDataType_t dataType )
{
    hfcuda_cudnnDataType_node_t* n = (typeof(n)) malloc (sizeof(*n));
    if(n == NULL)
        return HFERR;      

    n->deviceid = deviceid;
    n->descr = descr;
	n->dataType = dataType;

    int devhash = deviceid % hfcuda_cudnnDataType_list_hashsize;
    typeof(n) res = RB_INSERT(hfcuda_cudnnDataType_tree_t,
                              &hfcuda_cudnnDataType_list_head[ devhash ],
                              n);
    if(res != NULL) { // we hit something ... -> overwrite!
        free(n);
        hfdeb("[cudnnDataType] overwriting existing descr.! descr=0x%016lx dataType=%d device=%d\n", descr, dataType, deviceid );
		res->dataType = dataType;
    }
	else {
	    hfdeb("[cudnnDataType] added descr.: descr=0x%016lx dataType=%d device=%d\n", descr, dataType, deviceid );
	}

    return HFOK;
}

hferr_t hfcuda_get_cudnnDataType( int deviceid, cudnnTensorDescriptor_t descr, cudnnDataType_t *dataType )
{
    hfcuda_cudnnDataType_node_t* n = ____hfcuda_get_cudnnDataType_node( deviceid, descr );
    if( n == NULL ) {
        hferr("[cudnnDataType] couldn't find: descr=0x%016lx device=%d\n", descr, deviceid );
        ____hfcuda_dump_map_cudnnDataType( deviceid );
        return HFERR;
    }
	if( ! dataType ) {
        hferr("[cudnnDataType] no dataType pointer given\n" );
		return HFERR;
	}

	*dataType = n->dataType;
	return HFOK;
}

hferr_t hfcuda_del_cudnnDataType( int deviceid, cudnnTensorDescriptor_t descr )
{
    hfcuda_cudnnDataType_node_t* n = ____hfcuda_get_cudnnDataType_node( deviceid, descr );
    if( n == NULL ) {
        hferr("[cudnnDataType] couldn't find: descr=0x%016lx device=%d\n", descr, deviceid );
        ____hfcuda_dump_map_cudnnDataType( deviceid );
        return HFERR;
    }

    int devhash = deviceid % hfcuda_cudnnDataType_list_hashsize;
    hfcuda_cudnnDataType_node_t* ret = RB_REMOVE( hfcuda_cudnnDataType_tree_t,
                                       &hfcuda_cudnnDataType_list_head[ devhash ],
                                       n );
    if( ret != n ) {
        hferr("[cudnnDataType] couldn't delete: descr=0x%016lx device=%d\n", descr, deviceid );
        return HFERR;
    }
	
	free(ret); // FixME: not sure!

    hfdeb("[cudnnDataType] deleted pointer: descr=0x%016lx device=%d\n", descr, deviceid );

    return HFOK;
}



