#include <stdio.h> 
#include <stdlib.h>

#include <hfcomm.h>
#include <hfstr.h>

int main(int argc, char** argv)
{
    if (argc < 3) {
        printf("error: missing arguments\n");
        printf("usage: %s <port> <type>\n", argv[0]);
        printf("  port: server port\n"); 
        printf("  type: hfsocket | hfib\n");
        exit(1);
    }

    char*           host = "0.0.0.0";
    int             port;
    hfcomm_type_t   type;

    char* port_s = argv[1];
    char* type_s = argv[2];
    hfstr_str2int(port_s, &port);
    hfcomm_str2type(type_s, &type);

    printf("port: %d (%s)\n", port, port_s);
    printf("type: %d (%s)\n", type, type_s);

    hfcomm_t server;
    hfcomm_t comm;
    hfcomm_server_prepare(&server, host, port, type);
    hfcomm_server_accept(&server, &comm);

    int num;
    hfcomm_recv(&comm, &num, sizeof(int));
    printf("%d\n", num);

    double d;
    hfcomm_recv(&comm, &d, sizeof(double));
    printf("%lf\n", d);

    int len = 16;
    size_t size = len * sizeof(float);
    float* vec = malloc(size);
    hfcomm_recv(&comm, vec, size);
    for (int i = 0; i < len; i++)
        printf("%f\n", vec[i]);

    return 0;
}

