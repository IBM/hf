     
__thread hfcomm_t*  tl_hfcuda_conn = NULL;

hferr_t hfcuda_comm_init(int* gl_hfcuda_comm_port,
                         hfcomm_type_t* gl_hfcuda_comm_type)
{
    hfinf("[comm] started\n");

    const char* port_s;
    hfcheck(hfenv(HFCUDA_ENV_PORT, &port_s, HFCUDA_DEF_PORT));
    hfstr_str2int((char*) port_s, gl_hfcuda_comm_port);

    const char* type_s;
    hfcheck(hfenv(HFCUDA_ENV_TYPE, &type_s, HFCUDA_DEF_TYPE));
    hfcheck(hfcomm_str2type((char*) type_s, gl_hfcuda_comm_type));

    return HFOK;
}

hferr_t hfcuda_comm_set(hfcomm_t* conn)
{
    if (!conn) {
        hferr("[comm] hfcuda_comm_set(): null communicator\n");
        return HFERR;
    }

    tl_hfcuda_conn = conn;
    return HFOK;
}

static inline hferr_t hfcuda_comm_send(void* ptr, size_t size)
{
    // don't check pointer -> will be checked in hfcomm_send()
    return hfcomm_send(tl_hfcuda_conn, ptr, size);
}

static inline hferr_t hfcuda_comm_recv(void* ptr, size_t size)
{
    // don't check pointer -> will be checked in hfcomm_recv()
    return hfcomm_recv(tl_hfcuda_conn, ptr, size);
}

