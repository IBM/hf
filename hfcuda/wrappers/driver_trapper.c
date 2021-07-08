//  @nmimura 2018-09-25: Similar to CUDA Runtime API, due to how the current
//  device management logic works in HFCUDA, calls that receive device index as
//  input parameter have to be handled with care. For CUDA Driver API wrappers
//  these calls will ignore the parameter on the trapper side and will default
//  to device zero on the daemon side.

CUresult cuDeviceGetAttribute(
    int* pi,
    CUdevice_attribute attrib,
    CUdevice dev)
{
  hfinf("cuDeviceGetAttribute [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuDeviceGetAttribute;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));
  hfcheck(hfcuda_comm_send(&attrib, sizeof(CUdevice_attribute)));
  (void) dev;

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(pi, sizeof(int)));
  hfinf("cuDeviceGetAttribute [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuDeviceTotalMem(
    size_t* bytes,
    CUdevice dev)
{
  hfinf("cuDeviceTotalMem [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuDeviceTotalMem;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));
  (void) dev;

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(bytes, sizeof(size_t)));
  hfinf("cuDeviceTotalMem [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuMemAlloc(
    CUdeviceptr* dptr,
    size_t bytesize)
{
  hfinf("cuMemAlloc [CALL] bytesize=%lu\n", bytesize);
  hfcuda_function_t function = HFCUDA_CUDA_cuMemAlloc;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&bytesize, sizeof(size_t)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(dptr, sizeof(CUdeviceptr)));

  /*
  int device;
  cudaGetDevice(&device);
  hfcheck(hfcuda_am_add_mem_dev(dptr, bytesize, device));
  */

  hfinf("cuMemAlloc [DONE] rc=%d dptr=0x%016lx\n", rc, *dptr);
  return rc;

  /*
  hfcuda_function_t function = HFCUDA_CUDA_cuMemAlloc;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));
  hfcheck(hfcuda_comm_send(&bytesize, sizeof(size_t)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(&dptr, sizeof(CUdeviceptr*)));
  return rc;
  */
}

CUresult cuMemHostAlloc(
    void** pp,
    size_t bytesize,
    unsigned int Flags)
{
  hfinf("cuMemHostAlloc [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuMemHostAlloc;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&bytesize, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&Flags, sizeof(unsigned int)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(pp, sizeof(void*)));

  /*
  int device;
  cudaGetDevice(&device);
  hfcheck(hfcuda_am_add_mem_dev(*pp, bytesize, device));
  */

  *pp = malloc(bytesize);
  hfinf("cuMemHostAlloc [DONE] rc=%d pp=0x%016lx\n", rc, *pp);
  return rc;
}

CUresult cuMemFree(
    CUdeviceptr dptr)
{
  hfinf("cuMemFree [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuMemFree;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&dptr, sizeof(CUdeviceptr)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfinf("cuMemFree [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuMemFreeHost(
    void* p)
{
  hfinf("cuMemFreeHost [CALL]\n");
  free(p);
  hfinf("cuMemFreeHost [DONE]\n");
  return 0;
}

CUresult cuMemAllocHost(
    void** pp,
    size_t bytesize)
{
  return cuMemHostAlloc(pp, bytesize, 0);
}

CUresult cuMemcpyHtoDAsync(
    CUdeviceptr dstDevice,
    const void* srcHost,
    size_t ByteCount,
    CUstream hStream)
{
  return cuMemcpyHtoD(dstDevice, srcHost, ByteCount);
}

CUresult cuDeviceGetName(
    char* name,
    int len,
    CUdevice dev)
{
  hfinf("cuDeviceGetName [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuDeviceGetName;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));
  hfcheck(hfcuda_comm_send(&len, sizeof(int)));
  hfcheck(hfcuda_comm_send(&dev, sizeof(CUdevice)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(name, len));
  hfinf("cuDeviceGetName [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuMemcpyDtoHAsync(
    void* dstHost,
    CUdeviceptr srcDevice,
    size_t ByteCount,
    CUstream hStream)
{
  return cuMemcpyDtoH(dstHost, srcDevice, ByteCount);
}

// -----------------------------------------------------------------------------

#include <elf.h>

#define functions_max 1024
#define params_max    64

typedef struct {
  CUmodule module;         // module pointer associated to function
  CUfunction function;     // function pointer associated to function
  char* name;               // function name
  size_t params;            // number of parameters
  size_t sizes[params_max]; // size of parameters
} function_t;

__thread function_t functions[functions_max] = {0}; // list of functions
__thread int        functions_n = 0;                // number of functions

size_t read_image(
    const void* image,
    CUmodule* module)
{
  Elf64_Ehdr* ehdr = (void*)image;
  hfinf("--read_image: IMAGE          = 0x%016lx\n",
      image);
  hfinf("--read_image: HEADER\n");
  hfinf("--read_image:   e_ident      = %x %c%c%c\n",
      ehdr->e_ident[EI_MAG0],
      ehdr->e_ident[EI_MAG1],
      ehdr->e_ident[EI_MAG2],
      ehdr->e_ident[EI_MAG3]);
  hfinf("--read_image:   e_type       = %d\n", ehdr->e_type);
  hfinf("--read_image:   e_machine    = %d\n", ehdr->e_machine);
  hfinf("--read_image:   e_version    = %d\n", ehdr->e_version);
  hfinf("--read_image:   e_entry      = %d\n", ehdr->e_entry);
  hfinf("--read_image:   e_phoff      = %d\n", ehdr->e_phoff);
  hfinf("--read_image:   e_shoff      = %d\n", ehdr->e_shoff);
  hfinf("--read_image:   e_flags      = %d\n", ehdr->e_flags);
  hfinf("--read_image:   e_ehsize     = %d\n", ehdr->e_ehsize);
  hfinf("--read_image:   e_phentsize  = %d\n", ehdr->e_phentsize);
  hfinf("--read_image:   e_phnum      = %d\n", ehdr->e_phnum);
  hfinf("--read_image:   e_shentsize  = %d\n", ehdr->e_shentsize);
  hfinf("--read_image:   e_shnum      = %d\n", ehdr->e_shnum);
  hfinf("--read_image:   e_shstrndx   = %d\n", ehdr->e_shstrndx);

  size_t ph_final = (ehdr->e_phoff) + (ehdr->e_phentsize) * (ehdr->e_phnum);
  size_t sh_final = (ehdr->e_shoff) + (ehdr->e_shentsize) * (ehdr->e_shnum);
  size_t size     = ph_final > sh_final ? ph_final : sh_final;

  char debug_fn[128] = {0};
  sprintf(debug_fn, "debug.elf.0x%016lx", (uint64_t*)image);
  FILE* debug_f = fopen(debug_fn, "w");
  fwrite(image, sizeof(char), size, debug_f);
  fclose(debug_f);

  Elf64_Shdr* shstrtab =
    (void*)image + ehdr->e_shoff + ehdr->e_shstrndx * ehdr->e_shentsize;
  hfinf("--read_image: SHSTRTAB\n");
  char* aux = (void*)image + shstrtab->sh_offset;
  while (aux < (char*)image + shstrtab->sh_offset + shstrtab->sh_size) {
    hfinf("--read_image:   shstrtab     = %s\n", aux);
    aux = aux + strlen(aux) + 1;
  }

  for (int i = 0; i < ehdr->e_shnum; i++) {
    Elf64_Shdr* shdr = (void*)image + ehdr->e_shoff + i * ehdr->e_shentsize;
    if (!shdr->sh_type)
      continue;

    char* name = (char*)image + shstrtab->sh_offset + shdr->sh_name;

    hfinf("--read_image: SECTION %d\n",
        i);
    hfinf("--read_image:   sh_name      = %d -> %s\n",
        shdr->sh_name, name);
    hfinf("--read_image:   sh_type      = %d\n",
        shdr->sh_type);
    hfinf("--read_image:   sh_flags     = %d\n",
        shdr->sh_flags);
    hfinf("--read_image:   sh_addr      = 0x%016lx\n",
        shdr->sh_addr);
    hfinf("--read_image:   sh_offset    = 0x%016lx (0x%016lx)\n",
        shdr->sh_offset, image + shdr->sh_offset);
    hfinf("--read_image:   sh_size      = %d\n",
        shdr->sh_size);
    hfinf("--read_image:   sh_link      = %d\n",
        shdr->sh_link);
    hfinf("--read_image:   sh_info      = %d\n",
        shdr->sh_info);
    hfinf("--read_image:   sh_addralign = %d\n",
        shdr->sh_addralign);
    hfinf("--read_image:   sh_entsize   = %d\n",
        shdr->sh_entsize);

    char cmp_str[] = ".nv.info.";
    size_t cmp_n = strlen(cmp_str);
    if (!strncmp(name, cmp_str, cmp_n)) {
      char* kernel_name = name + cmp_n;
      char* section = (char*)image + shdr->sh_offset;
      uint16_t* aux = (uint16_t*)section;
      hfwar("0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n",
          aux[0], aux[1], aux[2], aux[3], aux[4]);
      int cbank = 0; // EIATTR_PARAM_CBANK index
      while (aux[cbank] != 0x0a04)
        cbank += 2;
      int kt = cbank + 5; // EIATTR_CBANK_PARAM_SIZE index
      uint16_t kernel_total = aux[kt];

      hfinf("==================================================\n");
      hfinf("--read_image: KERNEL\n");
      hfinf("--read_image:   name         = %s\n", kernel_name);
      hfinf("--read_image:   total        = %d\n", kernel_total);

      int poi = kt + 3; // parameter offset index
      int delta = 8; // index delta
      uint16_t param_ordinal;
      uint16_t param_offset;
      uint16_t param_last;
      uint16_t param_size;
      int param_first = 1;

      do {
        param_ordinal = aux[poi+4];
        hfwar("param_ordinal: %u\n", param_ordinal);
        param_offset  = aux[poi+5];
        if (param_first) {
          param_size = kernel_total - param_offset;

          functions[functions_n].module = NULL;
          functions[functions_n].name   = kernel_name;
          functions[functions_n].params = param_ordinal + 1;
        }
        else  {
          param_size = param_last - param_offset;
        }

        functions[functions_n].sizes[param_ordinal] = param_size;
        hfinf("--read_image:   param:%d offset:%d size:%d\n",
            param_ordinal, param_offset, param_size);
        poi += delta;
        param_last = param_offset;
        param_first = 0;
      } while (param_ordinal);

      functions_n++;
      hfinf("==================================================\n");
    }
  }

  return size;
}

// -----------------------------------------------------------------------------

CUresult cuModuleLoadDataEx(
    CUmodule* module,
    const void* image,
    unsigned int numOptions,
    CUjit_option* options,
    void** optionValues)
{
  hfinf("cuModuleLoadDataEx [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuModuleLoadDataEx;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  size_t image_size = read_image(image, module);
  hfcheck(hfcuda_comm_send(&image_size, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((void*)image, image_size));
  hfcheck(hfcuda_comm_send(&numOptions, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(options, numOptions * sizeof(CUjit_option)));
  hfcheck(hfcuda_comm_send(optionValues, numOptions * sizeof(void*)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(module, sizeof(CUmodule)));
  hfcheck(hfcuda_comm_recv(optionValues, numOptions * sizeof(void*)));

  for (int i = 0; i < functions_n; i++) {
    if (functions[i].module == NULL) {
      functions[i].module = *module;
    }
  }

  hfinf("cuModuleLoadDataEx [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuMemGetInfo(
    size_t* free,
    size_t* total)
{
  hfinf("cuMemGetInfo [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuMemGetInfo;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(free, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(total, sizeof(size_t)));
  hfinf("cuMemGetInfo [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuMemcpyHtoD(
    CUdeviceptr dstDevice,
    const void* srcHost,
    size_t ByteCount)
{
  hfinf("cuMemcpyHtoD [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuMemcpyHtoD;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&dstDevice,  sizeof(CUdeviceptr)));
  hfcheck(hfcuda_comm_send(&ByteCount, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((void*)srcHost, ByteCount));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfinf("cuMemcpyHtoD [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuMemcpyDtoH(
    void* dstHost,
    CUdeviceptr srcDevice,
    size_t ByteCount)
{
  hfinf("cuMemcpyDtoH [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuMemcpyDtoH;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&srcDevice, sizeof(CUdeviceptr)));
  hfcheck(hfcuda_comm_send(&ByteCount, sizeof(size_t)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(dstHost, ByteCount));
  return rc;
}

CUresult cuTexRefSetAddress(
    size_t* ByteOffset,
    CUtexref hTexRef,
    CUdeviceptr dptr,
    size_t bytes)
{
  hfinf("cuTexRefSetAddress [CALL] hTexRef=0x%016lx dptr=0x%016lx bytes=%lu\n",
      hTexRef, dptr, bytes);
  hfcuda_function_t function = HFCUDA_CUDA_cuTexRefSetAddress;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&hTexRef, sizeof(CUtexref)));
  hfcheck(hfcuda_comm_send(&dptr, sizeof(CUdeviceptr)));
  hfcheck(hfcuda_comm_send(&bytes, sizeof(size_t)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  ByteOffset = malloc(sizeof(size_t));
  hfcheck(hfcuda_comm_recv(ByteOffset, sizeof(size_t)));
  hfinf("cuTexRefSetAddress [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuModuleGetFunction(
    CUfunction* hfunc,
    CUmodule hmod,
    const char* name)
{
  hfinf("cuModuleGetFunction [CALL] name=%s\n", name);
  hfcuda_function_t function = HFCUDA_CUDA_cuModuleGetFunction;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&hmod, sizeof(CUmodule)));
  size_t name_len = strlen(name);
  hfcheck(hfcuda_comm_send(&name_len, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((void*)name, name_len));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(hfunc, sizeof(CUfunction)));

  for (int i = 0; i < functions_n; i++) {
    if (functions[i].module == hmod && !(strcmp(functions[i].name, name))) {
      functions[i].function = *hfunc;
      break;
    }
  }

  hfinf("cuModuleGetFunction [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuTexRefSetFormat(
    CUtexref hTexRef,
    CUarray_format fmt,
    int NumPackedComponents)
{
  hfinf("cuTexRefSetFormat [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuTexRefSetFormat;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&hTexRef, sizeof(CUtexref)));
  hfcheck(hfcuda_comm_send(&fmt, sizeof(CUarray_format)));
  hfcheck(hfcuda_comm_send(&NumPackedComponents, sizeof(int)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfinf("cuTexRefSetFormat [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuDeviceGetCount(
    int* count)
{
  hfinf("cuDeviceGetCount [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuDeviceGetCount;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(count, sizeof(int)));
  hfinf("cuDeviceGetCount [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuInit(
    unsigned int Flags)
{
  hfinf("cuInit [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuInit;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));
  hfcheck(hfcuda_comm_send(&Flags, sizeof(unsigned int)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfinf("cuInit [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuModuleGetTexRef(
    CUtexref* pTexRef,
    CUmodule hmod,
    const char* name)
{
  hfinf("cuModuleGetTexRef [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuModuleGetTexRef;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&hmod, sizeof(CUmodule)));
  size_t name_len = strlen(name) + 1;
  hfcheck(hfcuda_comm_send(&name_len, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((void*)name, name_len));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(pTexRef, sizeof(CUtexref)));
  hfinf("cuModuleGetTexRef [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuDeviceGet(
    CUdevice* device,
    int ordinal)
{
  hfinf("cuDeviceGet [CALL]\n");
  hfcuda_function_t function = HFCUDA_CUDA_cuDeviceGet;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));
  hfcheck(hfcuda_comm_send(&ordinal, sizeof(int)));

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfcheck(hfcuda_comm_recv(device, sizeof(CUdevice)));
  hfinf("cuDeviceGet [DONE] rc=%d\n", rc);
  return rc;
}

CUresult cuLaunchKernel(
    CUfunction f,
    unsigned int gridDimX,
    unsigned int gridDimY,
    unsigned int gridDimZ,
    unsigned int blockDimX,
    unsigned int blockDimY,
    unsigned int blockDimZ,
    unsigned int sharedMemBytes,
    CUstream hStream,
    void** kernelParams,
    void** extra)
{
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

  function_t* fu;
  for (int i = 0; i < functions_n; i++) {
    if (functions[i].function == f) {
      fu = &functions[i];
      hfinf("found function: name=%s params=%d\n",
          fu->name, fu->params);
      break;
    }
  }

  hfcuda_function_t function = HFCUDA_CUDA_cuLaunchKernel;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&f, sizeof(CUfunction)));
  hfcheck(hfcuda_comm_send(&gridDimX, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&gridDimY, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&gridDimZ, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&blockDimX, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&blockDimY, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&blockDimZ, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&sharedMemBytes, sizeof(unsigned int)));
  hfcheck(hfcuda_comm_send(&hStream, sizeof(CUstream)));

  int device;
  cudaGetDevice(&device);
  hfcheck(hfcuda_comm_send(&fu->params, sizeof(size_t)));

  for (unsigned int i = 0; i < fu->params; i++) {
    hfcheck(hfcuda_comm_send(&fu->sizes[i], sizeof(size_t)));
    hfcheck(hfcuda_comm_send(kernelParams[i], fu->sizes[i]));
  }

  CUresult rc;
  hfcheck(hfcuda_comm_recv(&rc, sizeof(CUresult)));
  hfinf("cuLaunchKernel [DONE] rc=%d\n", rc);
  return rc;
}

