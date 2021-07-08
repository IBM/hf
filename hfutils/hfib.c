#include "hfib.h"

//
//  Connect client to remote server.
//  ----------------------------------------------------------------------------
//

hferr_t hfib_client_connect(hfib_t* client, char* host, int port)
{
    hfdeb("[hfib] hfib_client_connect() [CALL] connecting to: host=%s port=%d\n", host, port);

    if ((client->socket = rsocket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        hferr("[hfib] hfib_client_connect(): rsocket() error %d: %s\n", 
                errno, strerror(errno));
        return HFERR;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (!inet_aton(host, (struct in_addr*) &addr.sin_addr.s_addr)) {
        hferr("[hfib] hfib_client_connect(): inet_aton() error\n");
        return HFERR;
    }

    if (rconnect(client->socket, (struct sockaddr*) &addr, sizeof(addr))) {
        hferr("[hfib] hfib_client_connect(): rconnect() error %d: %s\n",
                errno, strerror(errno));
        return HFERR;
    }

    hfdeb("[hfib] hfib_client_connect() [DONE]\n");

    return HFOK;
}

//
//  Prepare server to accept incoming connections.
//  ----------------------------------------------------------------------------
//

hferr_t hfib_server_prepare(hfib_t* server, char* host, int port)
{
    hfdeb("[hfib] hfib_server_prepare() [CALL] host=%s port=%d\n",
            host, port);

    if ((server->socket = rsocket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        hferr("[hfib] hfib_server_prepare(): rsocket() error %d: %s\n",
                errno, strerror(errno));
        return HFERR;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (!inet_aton(host, (struct in_addr*) &addr.sin_addr.s_addr)) {
        hferr("[hfib] hfib_server_prepare(): inet_aton() error\n");
        return HFERR;
    }

    if (rbind(server->socket, (struct sockaddr*) &addr, sizeof(addr))) {
        hferr("[hfib] hfib_server_prepare(): rbind() error %d: %s\n",
                errno, strerror(errno));
        return HFERR;
    }

    if (rlisten(server->socket, 1)) {
        hferr("[hfib] hfib_server_prepare(): rlisten() error %d: %s\n", 
                errno, strerror(errno));
        return HFERR;
    }    

    hfdeb("[hfib] hfib_server_prepare() [DONE]\n");

    return HFOK;
}

//
//  Accept incoming connection.
//  ----------------------------------------------------------------------------
//

hferr_t hfib_server_accept(hfib_t* server, hfib_t* conn)
{
    hfdeb("[hfib] hfib_server_accept() [CALL]\n");

    if ((conn->socket = raccept(server->socket, NULL, NULL)) < 0) {
        hferr("[hfsocket] hfib_server_accept(): raccept() error %d: %s\n", 
                errno, strerror(errno));
        return HFERR;
    }    

    hfdeb("[hfib] hfib_server_accept() [DONE]\n");

    return HFOK;
}

hferr_t hfib_send(hfib_t* conn, void* ptr, size_t size)
{
    hfdeb("[hfib] hfib_send() [CALL] ptr=0x%016lx size=%lu\n",
            ptr, size);

    ssize_t n;
    size_t  sent = 0;
    size_t  left = size;
    
    while (sent < size) {

        n     = rsend(conn->socket, ptr + sent, left, 0);
        sent += n;
        left -= n;

        if (n < 0) {
            hferr("[hfsocket] hfib_send(): rsend() error %d: %s\n", 
                    errno, strerror(errno));
            return HFERR;
        }
    }


    hfdeb("[hfib] hfib_send() [DONE]\n");

    return HFOK;
}

hferr_t hfib_recv(hfib_t* conn, void* ptr, size_t size)
{
    hfdeb("[hfib] hfib_recv() [CALL] ptr=0x%016lx size=%lu\n",
            ptr, size);

    ssize_t n;
    size_t  received = 0;
    size_t  left     = size;

    while (received < size) {

        n         = rrecv(conn->socket, ptr + received, left, 0);
        received += n;
        left     -= n;

        if (n < 0) {
            hferr("[hfsocket] hfib_recv(): rrecv() error %d: %s\n", 
                    errno, strerror(errno));
            return HFERR;
        }

        if (n == 0) {
            hfdeb("[hfsocket] hfib_recv(): peer disconnected\n");
            return HFOK;
        }
    }


    hfdeb("[hfib] hfib_recv() [DONE]\n");

    return HFOK;
}

hferr_t hfib_client_free(hfib_t* conn)
{
    (void)conn;
    return HFOK;
}

hferr_t hfib_server_free(hfib_t* server)
{
    (void)server;
    return HFOK;
}

