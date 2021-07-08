#include <stdio.h>
#include <stdlib.h>

#include <hfcomm.h>
#include <hfstr.h>

int main(int argc, char** argv)
{
    if (argc < 4) {
        printf("error: missing arguments\n");
        printf("usage: %s <host> <port> <type>\n", argv[0]);
        printf("  host: server IP\n");
        printf("  port: server port\n");
        printf("  type: hfsocket | hfib\n");
        exit(1);
    }

    char*           host;
    int             port;
    hfcomm_type_t   type;

    char* host_s = argv[1];
    char* port_s = argv[2];
    char* type_s = argv[3];

    host = host_s;
    hfstr_str2int(port_s, &port);
    hfcomm_str2type(type_s, &type);

    printf("host: %s\n", host);
    printf("port: %d (%s)\n", port, port_s);
    printf("type: %d (%s)\n", type, type_s);

    hfcomm_t comm;
    hfcomm_client_connect(&comm, host, port, type);

    int num = 1337;
    hfcomm_send(&comm, &num, sizeof(int));

    double d = 3.1416;
    hfcomm_send(&comm, &d, sizeof(double));
   
    int len = 16;
    size_t size = len * sizeof(float);
    float* vec = malloc(size);
    for (int i = 0; i < len; i++)
        vec[i] = (float) i / 10.0;
    hfcomm_send(&comm, vec, size);

    return 0;
}

