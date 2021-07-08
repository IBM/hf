const char*     gl_hfcuda_shlib_appso;  
__thread void*  tl_hfcuda_shlib_handle;

hferr_t hfcuda_shlib_init()
{
    if (hfenv(HFCUDA_ENV_APPSO, &gl_hfcuda_shlib_appso, NULL)) {
        hferr("[shlib] missing application shared library configuration\n");
        return HFERR;
    }

    return HFOK;
}

hferr_t hfcuda_shlib_load()
{
    if (strcmp(gl_hfcuda_shlib_appso, ".") == 0) {
        hfinf("[shlib] ignoring shared library configuration\n");
        return HFOK;
    }

    if (!(tl_hfcuda_shlib_handle = dlopen(gl_hfcuda_shlib_appso, RTLD_LAZY))) {
        hferr("[shlib] dlopen() failed for library \'%s\': %s\n",
                gl_hfcuda_shlib_appso, dlerror());
        return HFERR;
    }

    return HFOK;
}

hferr_t hfcuda_shlib_sym(const void** ptr, const char* func_name)
{
    *ptr = dlsym(tl_hfcuda_shlib_handle, func_name);

    if (!(*ptr)) {
        hferr("[shlib] could not open/find function \'%s\': %s\n", 
                func_name, dlerror());
        return HFERR;
    }

    return HFOK;
}

