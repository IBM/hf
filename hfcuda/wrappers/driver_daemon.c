hferr_t handle_HFCUDA_CUDA_cuDeviceGetAttribute()
{
  hfinf("cuDeviceGetAttribute [CALL]\n");
  CUdevice_attribute attrib;
  CUdevice dev = 0;
  hfcheck(hfcuda_comm_recv(&attrib, sizeof(CUdevice_attribute)));

  int pi;
  CUresult rc = cuDeviceGetAttribute(&pi, attrib, dev);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&pi, sizeof(int)));
  hfinf("cuDeviceGetAttribute [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuDeviceTotalMem()
{
  hfinf("cuDeviceTotalMem [CALL]\n");
  CUdevice dev = 0;

  size_t bytes;
  CUresult rc = cuDeviceTotalMem(&bytes, dev);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&bytes, sizeof(size_t)));
  hfinf("cuDeviceTotalMem [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemAlloc()
{
  hfinf("cuMemAlloc [CALL]\n");
  size_t bytesize;
  hfcheck(hfcuda_comm_recv(&bytesize, sizeof(size_t)));
  hfinf("cuMemAlloc: bytesize=%lu\n", bytesize);

  CUdeviceptr dptr;
  CUresult rc = cuMemAlloc(&dptr, bytesize);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&dptr, sizeof(CUdeviceptr)));
  hfinf("cuMemAlloc [DONE] rc=%d dptr=0x%016lx\n", rc, dptr);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemHostAlloc()
{
  hfinf("cuMemHostAlloc [CALL]\n");
  size_t bytesize;
  hfcheck(hfcuda_comm_recv(&bytesize, sizeof(size_t)));
  unsigned int Flags;
  hfcheck(hfcuda_comm_recv(&Flags, sizeof(unsigned int)));

  void* pp;
  CUresult rc = cuMemHostAlloc(&pp, bytesize, Flags);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&pp, sizeof(void*)));
  hfinf("cuMemHostAlloc [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemFree()
{
  hfinf("cuMemFree [CALL]\n");
  CUdeviceptr dptr;
  hfcheck(hfcuda_comm_recv(&dptr, sizeof(CUdeviceptr)));

  CUresult rc = cuMemFree(dptr);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfinf("cuMemFree [DONE]\n");
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemFreeHost() { return HFOK; }

hferr_t handle_HFCUDA_CUDA_cuMemAllocHost() { return HFOK; }

hferr_t handle_HFCUDA_CUDA_cuMemcpyHtoDAsync() { return HFOK; }

hferr_t handle_HFCUDA_CUDA_cuDeviceGetName()
{
  hfinf("cuDeviceGetName [CALL]\n");
  int len;
  hfcheck(hfcuda_comm_recv(&len, sizeof(int)));
  CUdevice dev;
  hfcheck(hfcuda_comm_recv(&dev, sizeof(CUdevice)));

  char* name = malloc(len + 1);
  CUresult rc = cuDeviceGetName(name, len, dev);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(name, len));
  free(name);
  hfinf("cuDeviceGetName [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemcpyDtoHAsync() { return HFOK; }

hferr_t handle_HFCUDA_CUDA_cuModuleLoadDataEx()
{
  hfinf("cuModuleLoadDataEx [CALL]\n");
  size_t image_size;
  hfcheck(hfcuda_comm_recv(&image_size, sizeof(size_t)));
  void* image = malloc(image_size);
  hfcheck(hfcuda_comm_recv(image, image_size));
  unsigned int numOptions;
  hfcheck(hfcuda_comm_recv(&numOptions, sizeof(unsigned int)));
  CUjit_option* options = malloc(numOptions * sizeof(CUjit_option));
  hfcheck(hfcuda_comm_recv(options, numOptions * sizeof(CUjit_option)));
  void** optionValues = malloc(numOptions * sizeof(void*));
  hfcheck(hfcuda_comm_recv(optionValues, numOptions * sizeof(void*)));

  CUmodule module;
  CUresult rc = cuModuleLoadDataEx(
      &module, image, numOptions, options, optionValues);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&module, sizeof(CUmodule)));
  hfcheck(hfcuda_comm_send(optionValues, numOptions * sizeof(void*)));
  free(image);
  free(options);
  free(optionValues);
  hfinf("cuModuleLoadDataEx [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemGetInfo()
{
  hfinf("cuMemGetInfo [CALL]\n");
  size_t free;
  size_t total;

  CUresult rc = cuMemGetInfo(&free, &total);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&free, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&total, sizeof(size_t)));
  hfinf("cuMemGetInfo [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuMemcpyHtoD()
{

  hfinf("cuMemcpyHtoD [CALL]\n");
  CUdeviceptr dstDevice;
  void* srcHost;
  size_t ByteCount;

  hfcheck(hfcuda_comm_recv(&dstDevice,  sizeof(CUdeviceptr)));
  hfcheck(hfcuda_comm_recv(&ByteCount, sizeof(size_t)));
  srcHost = malloc(ByteCount);
  hfcheck(hfcuda_comm_recv(srcHost, ByteCount));

  CUresult rc = cuMemcpyHtoD(dstDevice, srcHost, ByteCount);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  free(srcHost);
  hfinf("cuMemcpyHtoD [DONE]\n");
  return HFOK;

}

hferr_t handle_HFCUDA_CUDA_cuMemcpyDtoH()
{
  hfinf("cuMemcpyDtoH [CALL]\n");
  CUdeviceptr srcDevice;
  hfcheck(hfcuda_comm_recv(&srcDevice, sizeof(CUdeviceptr)));
  size_t ByteCount;
  hfcheck(hfcuda_comm_recv(&ByteCount, sizeof(size_t)));

  void* dstHost = malloc(ByteCount);
  CUresult rc = cuMemcpyDtoH(
      dstHost,
      srcDevice,
      ByteCount);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(dstHost, ByteCount));
  free(dstHost);
  hfinf("cuMemcpyDtoH [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuTexRefSetAddress()
{
  hfinf("cuTexRefSetAddress [CALL]\n");
  CUtexref hTexRef;
  hfcheck(hfcuda_comm_recv(&hTexRef, sizeof(CUtexref)));
  CUdeviceptr dptr;
  hfcheck(hfcuda_comm_recv(&dptr, sizeof(CUdeviceptr)));
  size_t bytes;
  hfcheck(hfcuda_comm_recv(&bytes, sizeof(size_t)));

  size_t ByteOffset;
  CUresult rc = cuTexRefSetAddress(&ByteOffset, hTexRef, dptr, bytes);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&ByteOffset, sizeof(size_t)));
  hfinf("cuTexRefSetAddress [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuModuleGetFunction()
{
  hfinf("cuModuleGetFunction [CALL]\n");
  CUmodule hmod;
  hfcheck(hfcuda_comm_recv(&hmod, sizeof(CUmodule)));
  size_t name_len;
  hfcheck(hfcuda_comm_recv(&name_len, sizeof(size_t)));
  char* name = calloc(name_len + 1, sizeof(char));
  hfcheck(hfcuda_comm_recv(name, name_len));

  CUfunction hfunc;
  CUresult rc = cuModuleGetFunction(&hfunc, hmod, name);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&hfunc, sizeof(CUfunction)));
  hfinf("cuModuleGetFunction [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuTexRefSetFormat()
{
  hfinf("cuTexRefSetFormat [CALL]\n");
  CUtexref hTexRef;
  hfcheck(hfcuda_comm_recv(&hTexRef, sizeof(CUtexref)));
  CUarray_format fmt;
  hfcheck(hfcuda_comm_recv(&fmt, sizeof(CUarray_format)));
  int NumPackedComponents;
  hfcheck(hfcuda_comm_recv(&NumPackedComponents, sizeof(int)));

  CUresult rc = cuTexRefSetFormat(hTexRef, fmt, NumPackedComponents);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfinf("cuTexRefSetFormat [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuDeviceGetCount()
{
  hfinf("cuDeviceGetCount [CALL]\n");

  int count;
  CUresult rc = cuDeviceGetCount(&count);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&count, sizeof(int)));
  return HFOK;
  hfinf("cuDeviceGetCount [DONE] rc=%d\n", rc);
}

hferr_t handle_HFCUDA_CUDA_cuInit()
{
  hfinf("cuInit [CALL]\n");
  unsigned int Flags;
  hfcheck(hfcuda_comm_recv(&Flags, sizeof(unsigned int)));

  CUresult rc = cuInit(Flags);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfinf("cuInit [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuModuleGetTexRef()
{
  hfinf("cuModuleGetTexRef [CALL]\n");
  CUmodule hmod;
  hfcheck(hfcuda_comm_recv(&hmod, sizeof(CUmodule)));
  size_t name_len;
  hfcheck(hfcuda_comm_recv(&name_len, sizeof(size_t)));
  char* name = calloc(name_len, sizeof(char));
  hfcheck(hfcuda_comm_recv(name, name_len));

  CUtexref pTexRef;
  CUresult rc = cuModuleGetTexRef(&pTexRef, hmod, name);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&pTexRef, sizeof(pTexRef)));
  hfinf("cuModuleGetTexRef [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuDeviceGet()
{
  hfinf("cuDeviceGet [CALL]\n");
  int ordinal;
  hfcheck(hfcuda_comm_recv(&ordinal, sizeof(int)));

  CUdevice device;
  CUresult rc = cuDeviceGet(&device, ordinal);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_send(&device, sizeof(CUdevice)));
  hfinf("cuDeviceGet [DONE] rc=%d\n", rc);
  return HFOK;
}

hferr_t handle_HFCUDA_CUDA_cuLaunchKernel()
{
  hfinf("cuLaunchKernel [INIT]\n");
  CUfunction f;
  unsigned int gridDimX;
  unsigned int gridDimY;
  unsigned int gridDimZ;
  unsigned int blockDimX;
  unsigned int blockDimY;
  unsigned int blockDimZ;
  unsigned int sharedMemBytes;
  CUstream hStream;
  void** kernelParams;

  hfcheck(hfcuda_comm_recv(&f, sizeof(CUfunction)));
  hfcheck(hfcuda_comm_recv(&gridDimX, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&gridDimY, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&gridDimZ, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&blockDimX, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&blockDimY, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&blockDimZ, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&sharedMemBytes, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_recv(&hStream, sizeof(CUstream)));

  hfinf("cuLaunchKernel [CALL]\n"
      "\tf=0x%016lx\n"
      "\tgrid=%d,%d,%d\n"
      "\tblock=%d,%d,%d\n"
      "\tsharedMemBytes=%d\n"
      "\thStream=0x%016lx\n",
      f,
      gridDimX, gridDimY, gridDimZ,
      blockDimX, blockDimY, blockDimZ,
      sharedMemBytes, hStream);

  size_t params;
  hfcheck(hfcuda_comm_recv(&params, sizeof(size_t)));
  kernelParams = malloc(params * sizeof(void*));

  for (unsigned int i = 0; i < params; i++) {
    size_t size;
    hfcheck(hfcuda_comm_recv(&size, sizeof(size_t)));
    kernelParams[i] = malloc(size);
    hfcheck(hfcuda_comm_recv(kernelParams[i], size));
  }

  CUresult rc = cuLaunchKernel(
      f,
      gridDimX,
      gridDimY,
      gridDimZ,
      blockDimX,
      blockDimY,
      blockDimZ,
      sharedMemBytes,
      hStream,
      kernelParams,
      0);
  hfcheck(hfcuda_comm_send(&rc, sizeof(CUresult)));
  hfinf("cuLaunchKernel [DONE] rc=%d\n", rc);
  return HFOK;
}

