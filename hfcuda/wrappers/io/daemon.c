#include "../hfio/hfio.h"

hferr_t handle_HFCUDA_IO_hf_gpu_fopen()
{
  hfinf("hf_gpu_fopen\n");
  size_t pathname_len;
  hfcheck(hfcuda_comm_recv(&pathname_len, sizeof(size_t)));
  char* pathname = calloc(pathname_len, sizeof(char));
  hfcheck(hfcuda_comm_recv(pathname, pathname_len));
  size_t mode_len;
  hfcheck(hfcuda_comm_recv(&mode_len, sizeof(size_t)));
  char* mode = calloc(mode_len, sizeof(char));  
  hfcheck(hfcuda_comm_recv(mode, mode_len));

  FILE* fp = hf_gpu_fopen(pathname, mode);
  hfcheck(hfcuda_comm_send(&fp, sizeof(FILE*)));
  return HFOK;
}

hferr_t handle_HFCUDA_IO_hf_gpu_fwrite()
{
  hfinf("hf_gpu_fwrite\n");
  void* ptr;
  size_t size;
  size_t nitems;
  FILE* stream;

  hfcheck(hfcuda_comm_recv(&ptr, sizeof(const void*)));
  hfcheck(hfcuda_comm_recv(&size, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&nitems, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&stream, sizeof(FILE*)));

  size_t written = hf_gpu_fwrite(ptr, size, nitems, stream);
  hfcheck(hfcuda_comm_send(&written, sizeof(size_t)));
  return HFOK;
}

hferr_t handle_HFCUDA_IO_hf_gpu_fread()
{
  hfinf("hf_gpu_fread\n");
  void* ptr;
  size_t size;
  size_t nitems;
  FILE* stream;

  hfcheck(hfcuda_comm_recv(&ptr, sizeof(const void*)));
  hfcheck(hfcuda_comm_recv(&size, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&nitems, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&stream, sizeof(FILE*)));

  size_t read = hf_gpu_fread(ptr, size, nitems, stream);
  hfcheck(hfcuda_comm_send(&read, sizeof(size_t)));
  return HFOK;
}

hferr_t handle_HFCUDA_IO_hf_gpu_fclose()
{
  hfinf("hf_gpu_fclose\n");
  FILE* stream;

  hfcheck(hfcuda_comm_recv(&stream, sizeof(FILE*)));

  int ret = hf_gpu_fclose(stream);
  hfcheck(hfcuda_comm_send(&ret, sizeof(int)));
  return HFOK;
}

//
//  ============================================================================
//

//
//  Daemon handler for fopen()
//

hferr_t handle_HFCUDA_IO_fopen()
{
  printf("preloaded fopen\n");

  size_t pathname_len;
  hfcheck(hfcuda_comm_recv(&pathname_len, sizeof(size_t)));
  char* pathname = malloc(pathname_len);
  hfcheck(hfcuda_comm_recv(pathname, pathname_len));

  size_t mode_len;
  hfcheck(hfcuda_comm_recv(&mode_len, sizeof(size_t)));
  char* mode = malloc(mode_len);
  hfcheck(hfcuda_comm_recv(mode, mode_len));

  printf("preloaded fopen: %s\n", pathname);

  FILE** fpp = malloc(sizeof(FILE*));
  *fpp = fopen(pathname, mode);
  hfcheck(hfcuda_comm_send(fpp, sizeof(FILE*)));

  printf("[daemon] preloaded fopen: 0x%016lx\n", (size_t) *fpp);

  return HFOK;
}

//
//  Daemon handler for fwrite()
//

hferr_t handle_HFCUDA_IO_fwrite()
{
  void* ptr;
  size_t size;
  size_t nitems;
  FILE* stream;

  printf("[daemon] preloaded fwrite\n");

  hfcheck(hfcuda_comm_recv(&ptr, sizeof(void*)));
  hfcheck(hfcuda_comm_recv(&size, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&nitems, sizeof(size_t)));
  hfcheck(hfcuda_comm_recv(&stream, sizeof(FILE*)));

  printf("[daemon] preloaded fwrite: "
         "ptr=0x%016lx size=%lu nitems=%lu stream=0x%016lx\n",
         (size_t) ptr, size, nitems, (size_t) stream);

  size_t written = fwrite(ptr, size, nitems, stream);
  if (written < nitems) {
    printf("[daemon] fwrite(): %d: %s\n",
        errno, strerror(errno));
  }
  hfcheck(hfcuda_comm_send(&written, sizeof(size_t)));

  printf("[daemon] preloaded fwrite: %lu\n", written);

  return HFOK;
}

