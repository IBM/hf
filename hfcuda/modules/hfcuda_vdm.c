/*
  all of these functions are called on the trapper
  The trapper runs the init at the beginning, hence there is no need anymore
  to init again ... 
*/

// -----------------------------------------------------------------------------

typedef struct {             
    char*               host;       
    int                 device;    
    hfcomm_t            comm;     
} hfcuda_vdm_t;

// -----------------------------------------------------------------------------

hfcuda_vdm_t*   gl_hfcuda_vdm_list;      
int             gl_hfcuda_vdm_count;    
__thread int    tl_hfcuda_vdm_curr = -1;

#define HFCUDA_VDM_BUFFER 16           

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_init(int gl_hfcuda_comm_port,
                        hfcomm_type_t gl_hfcuda_comm_type)
{
    hfinf("[vdm] started\n");

    const char* devices;
    if (hfenv(HFCUDA_ENV_DEVICES, &devices, NULL)) {
        hferr("[vdm] missing devices configuration\n");
        return HFERR;
    }

    gl_hfcuda_vdm_count = 1;
    for (unsigned int i = 0; i < strlen(devices); i++) {
        if (devices[i] == HFCUDA_DEVICES_SEP) {
            gl_hfcuda_vdm_count++;
        }
    }

    hfinf("[vdm] found %d virtual devices\n", gl_hfcuda_vdm_count);

    gl_hfcuda_vdm_list = malloc(gl_hfcuda_vdm_count * sizeof(hfcuda_vdm_t));

    const char* ch = devices;

    for (int i = 0; i < gl_hfcuda_vdm_count; i++) {

        hftra("[vdm] (debug) devices=%s\n", devices);

        size_t size    = HFCUDA_VDM_BUFFER * sizeof(char);
        char* host     = malloc(size);
        memset(host, 0, size);
        char* device_s = malloc(HFCUDA_VDM_BUFFER * sizeof(char));
        memset(device_s, 0, size);

        char* host_p   = host;
        char* device_p = device_s;

        while (*ch && *ch != HFCUDA_PAIR_SEP)    *host_p++   = *ch++;
        if    (*ch)                               ch++;
        while (*ch && *ch != HFCUDA_DEVICES_SEP) *device_p++ = *ch++;
        if    (*ch)                               ch++;

        hfinf("[vdm] virtual device %d: host=%s device=%s type=%s\n", 
                i, host, device_s, hfcomm_type2str(gl_hfcuda_comm_type));

        if (strlen(host) == 0) {
            hferr("[vdm] empty host for virtual device\n");
            return HFERR;
        }

        int device;
        if (hfstr_str2int(device_s, &device)) {
            hferr("[vdm] invalid device: %s\n", device_s);
            return HFERR;
        }

        gl_hfcuda_vdm_list[i].host   = host;
        gl_hfcuda_vdm_list[i].device = device;

        if (hfcomm_client_connect(&(gl_hfcuda_vdm_list[i].comm),
                                  gl_hfcuda_vdm_list[i].host,
                                  gl_hfcuda_comm_port + device,
                                  gl_hfcuda_comm_type)) {
            hferr("[vdm] could not connect to server: %s\n",
                    gl_hfcuda_vdm_list[i].host);
            return HFERR;
        }
    }

    tl_hfcuda_vdm_curr = -1;
    if (cudaSetDevice(0)) {
        hferr("[vdm] initial cudaSetDevice() failed\n");
        return HFERR;
    }

    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_get_device(int* device)
{
    *device = tl_hfcuda_vdm_curr;
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_get_real(int* real)
{
    *real = gl_hfcuda_vdm_list[tl_hfcuda_vdm_curr].device;
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_get_count(int* count)
{
    *count = gl_hfcuda_vdm_count;
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_set(int device)
{
    tl_hfcuda_vdm_curr = device;
    hfcuda_comm_set(&(gl_hfcuda_vdm_list[tl_hfcuda_vdm_curr].comm));

    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_get_curr_host(char** host)
{
    if (!gl_hfcuda_vdm_list)
        return HFERR;

    *host = gl_hfcuda_vdm_list[tl_hfcuda_vdm_curr].host;
    return HFOK;
}

// -----------------------------------------------------------------------------

hferr_t hfcuda_vdm_get_curr_device(int* device)
{
    if (!gl_hfcuda_vdm_list)
        return HFERR;

    *device = tl_hfcuda_vdm_curr;
    return HFOK;
}


