// -----------------------------------------------------------------------------

/*
Example how it is being used:

  CUpointer_attribute attr[] = {CU_POINTER_ATTRIBUTE_CONTEXT,
                                CU_POINTER_ATTRIBUTE_MEMORY_TYPE,
                                CU_POINTER_ATTRIBUTE_IS_MANAGED};
  CUcontext context = NULL;
  CUmemorytype mem_type;
  int is_managed = 0;
  void* data[] = {&context, &mem_type, &is_managed};

  CUresult err = cuPointerGetAttributes(3, attr, data, (CUdeviceptr)ptr);
*/

hferr_t handle_HFCUDA_CUDA_cuPointerGetAttributes( void )
{
    hfinf("[daemon] cuPointerGetAttributes() [INIT]\n");

    // https://docs.nvidia.com/cuda/cuda-driver-api/group__CUDA__UNIFIED.html#group__CUDA__UNIFIED_1g0c28ed0aff848042bc0533110e45820c
    // this is pretty ugly, but it seems as if there is no other way.
    // Since void** is provided, we don't know the size of each attribute upfront.
    // Hence, we need to take it from the documentation.
    // Only problem left: maintenance (daemon <-> trapper). :-(
    struct {
        CUpointer_attribute attr;
        unsigned int typesize;
    } supported_attr [] = {
      { CU_POINTER_ATTRIBUTE_CONTEXT, sizeof(CUcontext) },
      { CU_POINTER_ATTRIBUTE_MEMORY_TYPE, sizeof(CUmemorytype) },
      { CU_POINTER_ATTRIBUTE_DEVICE_POINTER, sizeof(void*) }, // ToDo: DoubleCheck
      { CU_POINTER_ATTRIBUTE_HOST_POINTER, sizeof(void*) }, // ToDo: DoubleCheck
      { CU_POINTER_ATTRIBUTE_P2P_TOKENS, sizeof(CUDA_POINTER_ATTRIBUTE_P2P_TOKENS) } ,
      { CU_POINTER_ATTRIBUTE_SYNC_MEMOPS, sizeof(bool) },
      { CU_POINTER_ATTRIBUTE_BUFFER_ID, sizeof(int) }, // ToDo: DoubleCheck
      { CU_POINTER_ATTRIBUTE_IS_MANAGED, sizeof(bool) },
#if CUDA_VERSION >= 9020  // version 9.1 doesn't have it
      { CU_POINTER_ATTRIBUTE_DEVICE_ORDINAL, sizeof(int) }
#endif
    };

    // let's first create a lookup table to speed-up -- could be improved in the init()
    unsigned int maxId = 0;
    unsigned int i;
    for( i = 0; i < sizeof(supported_attr) / sizeof(supported_attr[0]); ++i )
      maxId = supported_attr[ i ].attr > maxId ? supported_attr[ i ].attr : maxId;

    typeof(supported_attr[0])** sup_attr_map = (typeof(supported_attr[0])**) calloc ( (maxId + 1), sizeof(typeof(supported_attr[0])*) );
    for( i = 0; i < sizeof(supported_attr) / sizeof(supported_attr[0]); ++i )
      sup_attr_map[ supported_attr[ i ].attr ] = &supported_attr[ i ];


    hfinf("[daemon] cuPointerGetAttributes() [CALL]\n");

    struct __attribute__((packed)) {
        unsigned int numAttributes;
        CUdeviceptr ptr;
    } t2d_msg_data;
    hfcheck(hfcuda_comm_recv(&t2d_msg_data, sizeof(t2d_msg_data)));
    
    // first allocate for the attributes and then receive them
    unsigned int attr_len = sizeof(CUpointer_attribute) * t2d_msg_data.numAttributes;
    CUpointer_attribute* attr = (CUpointer_attribute*) malloc (attr_len);
    hfcheck(hfcuda_comm_recv(attr, attr_len));


    // now we need to determine the amount of buffer required (same on trapper)
    unsigned int attrlen = 0;
    for( i = 0; i < t2d_msg_data.numAttributes; ++i ) {
      CUpointer_attribute at = attr[ i ];
      if ( ! sup_attr_map[ at ] )
        hferr("Attribute id not supported! %d\n", at);
      attrlen += sup_attr_map[ at ]->typesize;
    }
    attrlen += sizeof(CUresult); // end result will also be part of the buffer
    
    // except that we also require an array of pointers
    unsigned int datalen = sizeof(uintptr_t) * t2d_msg_data.numAttributes;

    // one allocation is sufficient -> just need to point to it afterwards ... 
    char *buf = (char*) malloc (sizeof(char) * (attrlen + datalen));

    // set pointer to data struct and set the pointers into it (put data at back)
    void** data = (void**)(buf + attrlen);
    char *t_buf = buf;
    for( i = 0; i < t2d_msg_data.numAttributes; ++i ) {
      data[i] = (void*)t_buf;
      t_buf += sup_attr_map[ attr[ i ] ]->typesize;
    }
    CUresult* res = (CUresult*) t_buf; // last one

    *res = cuPointerGetAttributes( t2d_msg_data.numAttributes, attr, data, t2d_msg_data.ptr );

    hfcheck(hfcuda_comm_send(buf, attrlen)); // only send the attributes and result

    hfinf("[daemon] cuPointerGetAttributes() [DONE] "
            "result=%d\n",
            *res);

    free(sup_attr_map);
    free(attr);
    free(buf);

    return HFOK;
}

// -----------------------------------------------------------------------------

