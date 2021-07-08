#pragma once

#include <errno.h>
#include <stddef.h>
#include <string.h>

#include <linux/socket.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/ip.h>
#include <arpa/inet.h> 

#include <rdma/rsocket.h>

#include "hflog.h"

typedef int rsocket_t;

typedef struct {
    rsocket_t socket;
} hfib_t;

hferr_t hfib_client_connect (hfib_t* client, char* host, int port);
hferr_t hfib_server_prepare (hfib_t* server, char* host, int port);
hferr_t hfib_server_accept  (hfib_t* server, hfib_t* conn);

hferr_t hfib_send (hfib_t* conn, void* ptr, size_t size);
hferr_t hfib_recv (hfib_t* conn, void* ptr, size_t size);

hferr_t hfib_client_free (hfib_t* client);
hferr_t hfib_server_free (hfib_t* server);

