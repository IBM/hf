#include "../hfio/hfio.h"

FILE* hf_gpu_fopen(
    const char* pathname,
    const char* mode)
{
  //printf("[hfcuda] hf_gpu_fopen\n");
  hfcuda_function_t function = HFCUDA_IO_hf_gpu_fopen;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  size_t pathname_len = strlen(pathname) + 1;
  hfcheck(hfcuda_comm_send(&pathname_len, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((char*) pathname, pathname_len));
  size_t mode_len = strlen(pathname) + 1;
  hfcheck(hfcuda_comm_send(&mode_len, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((char*) mode, mode_len));

  FILE* fp;
  hfcheck(hfcuda_comm_recv(&fp, sizeof(FILE*)));
  return fp;
}

size_t hf_gpu_fwrite(
    const void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  //printf("[hfcuda] hf_gpu_fwrite\n");
  hfcuda_function_t function = HFCUDA_IO_hf_gpu_fwrite;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&ptr, sizeof(const void*)));
  hfcheck(hfcuda_comm_send(&size, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&nitems, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&stream, sizeof(FILE*)));

  size_t written;
  hfcheck(hfcuda_comm_recv(&written, sizeof(size_t)));
  return written;
}

size_t hf_gpu_fread(
    void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  //printf("[hfcuda] hf_gpu_fread\n");
  hfcuda_function_t function = HFCUDA_IO_hf_gpu_fread;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&ptr, sizeof(const void*)));
  hfcheck(hfcuda_comm_send(&size, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&nitems, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&stream, sizeof(FILE*)));

  size_t read;
  hfcheck(hfcuda_comm_recv(&read, sizeof(size_t)));
  return read;
}

int hf_gpu_fclose(
    FILE* stream)
{
  //printf("[hfcuda] hf_gpu_fclose\n");
  hfcuda_function_t function = HFCUDA_IO_hf_gpu_fclose;
  hfcheck(hfcuda_comm_send(&function, sizeof(hfcuda_function_t)));

  hfcheck(hfcuda_comm_send(&stream, sizeof(FILE*)));

  int ret;
  hfcheck(hfcuda_comm_recv(&ret, sizeof(int)));
  return ret;
}

//
//  ============================================================================
//

//
//  File pointers managed by I/O wrapper.
//  io_map is an array of file pointers managed by the wrapper.
//  Combined to the io_cnt counter, this is used as a map of pointers,
//  mapping virtual pointers to the actual file pointers that exist on
//  remote nodes. The virtual addresses are built by combining the counter
//  value and the offset io_offset.
//

FILE* io_map[64];
size_t io_cnt = 0;
size_t io_offset = 0xFFFF000000000000;

//
//  cudaMemPrefetchAsync addresses managed by I/O wrapper.
//  For this particular set of tests with checkpointing,
//  cudaMemPrefetchAsync is used to implement the ATS version in which
//  data is brought seamlessly from GPU to CPU to be checkpointed.
//  This version of the wrapper simply ships the function to the
//  other side while sending the data to be prefetched. Since the address
//  must be valid on the daemon side, the memory region is allocated and
//  initialized there, then the pointer address is brought back to the
//  trapper. Since the checkpointing implementation uses the original
//  (trapper-side) pointer address, we need to translate from trapper
//  address to daemon address.
//

void*  cmpa_addr[64]; // cudaMemPrefetchAsync map
void*  cmpa_tran[64];
size_t cmpa_cnt = 0;

//
//  Trapper wrapper for fopen()
//

FILE* fopen(
    const char *pathname,
    const char *mode)
{
  // Prepare string for comparison.
  // If the file name starts with ckpt.rem, the file
  // must be handled on the remote node.
  char aux[512] = {0};
  strcpy(aux, pathname);
  char cmp[] = "ckpt.rem";
  aux[strlen(cmp)] = '\0';

  // Compare to decide if fopen() (and further file handling)
  // must take place locally (therefore using the original fopen()
  // function obtained via dlsym()) or remotely (by shipping the function
  // to be handled by the daemon).
  if (strcmp(aux, cmp)) {
    FILE* (*fopen_original)(
      const char*,
      const char*)
      = dlsym(RTLD_NEXT, "fopen");
    return fopen_original(pathname, mode);
  }

  printf("[trapper] preloaded fopen: %s\n", pathname);

  // Send wrapper function code.
  hfcuda_function_t function = HFCUDA_IO_fopen;
  hfcheck(hfcuda_comm_send(&function, sizeof(function)));

  // Send file path (length then string itself).
  size_t pathname_len = strlen(pathname) + 1;
  hfcheck(hfcuda_comm_send(&pathname_len, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((void*) pathname, pathname_len));

  // Send mode string (length then string itself).
  size_t mode_len = strlen(mode) + 1;
  hfcheck(hfcuda_comm_send(&mode_len, sizeof(size_t)));
  hfcheck(hfcuda_comm_send((void*) mode, mode_len));

  // Receive file pointer address from remote node.
  // Store this address in the array of file pointers
  // managed by this I/O wrapper. The address returned to the caller
  // is a fake address based on the internal address counter plus an
  // offset (usually transforming this address into an out of bounds
  // value). Later, when any function receives this sort of address
  // it knows we are handling a file pointer on a remote device.
  FILE* fp;
  hfcheck(hfcuda_comm_recv(&fp, sizeof(fp)));
  io_map[io_cnt] = fp;
  printf("[trapper] preloaded fopen: 0x%016lx -> 0x%016lx\n",
      io_offset + io_cnt, (size_t) fp);
  return (FILE*) (io_offset + io_cnt++);
}

//
//  Trapper wrapper for fwrite()
//

size_t fwrite(
    const void* ptr,
    size_t size,
    size_t nitems,
    FILE* stream)
{
  if ((size_t) stream < io_offset) {
    size_t (*fwrite_original)(
        const void*,
        size_t,
        size_t,
        FILE*)
      = dlsym(RTLD_NEXT, "fwrite");
    return fwrite_original(ptr, size, nitems, stream);
  }

  printf("[trapper] preloaded fwrite: stream: 0x%016lx -> 0x%016lx; ptr=0x%016lx\n",
      (size_t) stream, (size_t) io_map[(size_t) stream - io_offset], (size_t) ptr);

  hfcuda_function_t function = HFCUDA_IO_fwrite;
  hfcheck(hfcuda_comm_send(&function, sizeof(function)));

  void* cmpa_remote;
  for (size_t i = 0; i < cmpa_cnt; i++) {
    printf("[trapper] preloaded fwrite: check: "
           "cmpa_addr[%lu]=0x%016lx => cmpa_tran[%lu]=0x%016lx\n",
           i, (size_t) cmpa_addr[i],
           i, (size_t) cmpa_tran[i]);
    if (cmpa_addr[i] == ptr) {
      cmpa_remote = cmpa_tran[i];
      printf("[trapper] preloaded fwrite: FOUND cmpa_remote=0x%016lx\n",
          (size_t) cmpa_remote);
      break;
    }
  }

  printf("[trapper] preloaded fwrite: "
         "cmpa_remote=0x%016lx size=%lu nitems=%lu\n",
      (size_t) cmpa_remote, size, nitems);

  hfcheck(hfcuda_comm_send(&cmpa_remote, sizeof(void*)));
  hfcheck(hfcuda_comm_send(&size, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&nitems, sizeof(size_t)));
  hfcheck(hfcuda_comm_send(&io_map[(size_t) stream - io_offset], sizeof(FILE*)));

  size_t written;
  hfcheck(hfcuda_comm_recv(&written, sizeof(size_t)));
  printf("[trapper] preloaded fwrite: %lu\n", written);
  return written;
}

