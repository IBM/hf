#pragma once

#include <errno.h>
#include <stddef.h>
#include <string.h>

#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <arpa/inet.h>  

#include "hflog.h"

typedef int socket_t;

typedef struct {
    socket_t socket;
} hfsocket_t;

hferr_t hfsocket_client_connect (hfsocket_t* client,   char* host, int port);
hferr_t hfsocket_server_prepare (hfsocket_t* server, char* host, int port);
hferr_t hfsocket_server_accept  (hfsocket_t* server, hfsocket_t* conn);

hferr_t hfsocket_send (hfsocket_t* conn, void* ptr, size_t size);
hferr_t hfsocket_recv (hfsocket_t* conn, void* ptr, size_t size);

hferr_t hfsocket_client_free (hfsocket_t* conn);
hferr_t hfsocket_server_free (hfsocket_t* server);

