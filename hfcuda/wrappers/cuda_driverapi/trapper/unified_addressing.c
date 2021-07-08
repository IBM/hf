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

CUresult cuPointerGetAttributes( unsigned int numAttributes,
                                 CUpointer_attribute* attributes,
                                 void** data,
                                 CUdeviceptr ptr )
{
    hfinf("[trapper] cuPointerGetAttributes() [INIT]\n" );

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


    hfinf("[trapper] cuPointerGetAttributes() [CALL]\n" );

    // send first the amount of attributes interested in
    struct __attribute__((packed)) {
        hf_msgdescr_t header;
        struct __attribute__((packed)) {
            unsigned int numAttributes;
            CUdeviceptr ptr;
        } data;
    } t2d_msg;
    HF_MSGDESCR_SET( &t2d_msg.header,
                     HFCUDA_CUDA_cuPointerGetAttributes );
    t2d_msg.data.numAttributes = numAttributes;
    t2d_msg.data.ptr = ptr;
    hfcheck(hfcuda_comm_send(&t2d_msg, sizeof(t2d_msg)));

    // we only need to send the attributes that we want to query.
    hfcheck(hfcuda_comm_send(attributes, numAttributes * sizeof(CUpointer_attribute)));


    // now we need to determine the amount of buffer required (same on daemon)
    unsigned int bufsize = 0;
    for( i = 0; i < numAttributes; ++i )
      bufsize += sup_attr_map[ attributes[ i ] ]->typesize;
    bufsize += sizeof(CUresult); // end result will also be part of the buffer
    char *buf = (char*) malloc (sizeof(char) * bufsize);

    hfcheck(hfcuda_comm_recv(buf, bufsize));


    // got all of it .. now let's move on -> data[*] is pointer!
    char *t_buf = buf;
    for( i = 0; i < numAttributes; ++i ) {
      unsigned int typesize = sup_attr_map[ attributes[ i ] ]->typesize;
      switch( typesize ) {
      case sizeof(uint8_t):
        if(data[i])
          *(uint8_t*)data[i] = *(uint8_t*)t_buf;
        break;
      case sizeof(uint16_t):
        if(data[i])
          *(uint16_t*)data[i] = *(uint16_t*)t_buf;
        break;
      case sizeof(uint32_t):
        if(data[i])
          *(uint32_t*)data[i] = *(uint32_t*)t_buf;
        break;
      case sizeof(uint64_t):
        if(data[i])
          *(uint64_t*)data[i] = *(uint64_t*)t_buf;
        break;
      default:
        if(data[i])
          memcpy(data[i], t_buf, typesize);
        break;
      }
      t_buf += typesize;
    }
    CUresult cudaResult = *(CUresult*)t_buf;

    hfinf("[trapper] cuPointerGetAttributes() [DONE] "
            "result=%d\n",
            cudaResult);

    free(sup_attr_map);
    free(buf);

    return cudaResult;
}

// -----------------------------------------------------------------------------

