#include "hfsocket.h"

hferr_t hfsocket_client_connect(hfsocket_t* client, char* host, int port)
{
    hfdeb("[hfsocket] connecting to: host=%s port=%d\n", host, port);

    if ((client->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        hferr("[hfsocket] socket() error %d: %s\n", errno, strerror(errno));
        return HFERR;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (!inet_aton(host, (struct in_addr*) &addr.sin_addr.s_addr)) {
        hferr("[hfsocket] inet_aton() error\n");
        return HFERR;
    }

    if (connect((client->socket), (struct sockaddr*) &addr, sizeof(addr))) {
        hferr("[hfsocket] connect() error %d: %s\n", errno, strerror(errno));
        return HFERR;
    }

    hfdeb("[hfsocket] connected: host=%s port=%d client=0x%016lx socket=%d\n",
            host, port, client, client->socket);

    return HFOK;
}

hferr_t hfsocket_server_prepare(hfsocket_t* server, char* host, int port)
{
    hfdeb("[hfsocket] preparing server: host=%s port=%d\n", host, port);

    if ((server->socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        hferr("[hfsocket] socket() error %d: %s\n", errno, strerror(errno));
        return HFERR;
    }

    int enable = 1;
    if ((setsockopt(server->socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable))) < 0) {
        hfwar("[hfsocket] setsockopt() error %d: %s\n", errno, strerror(errno));
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);

    if (!inet_aton(host, (struct in_addr*) &addr.sin_addr.s_addr)) {
        hferr("[hfsocket] inet_aton() error\n");
        return HFERR;
    }

    if (bind(server->socket, (struct sockaddr*) &addr, sizeof(addr))) {
        hferr("[hfsocket] bind() error %d: %s\n", errno, strerror(errno));
        return HFERR;
    }

    if (listen(server->socket, 1)) {
        hferr("[hfsocket] listen() error %d: %s\n", errno, strerror(errno));
        return HFERR;
    }

    hfdeb("[hfsocket] server prepared: host=%s port=%d server=0x%016lx socket=%d\n",
            host, port, server, server->socket);

    return HFOK;
}

hferr_t hfsocket_server_accept(hfsocket_t* server, hfsocket_t* conn)
{
    hfdeb("[hfsocket] waiting for connection\n");

    if ((conn->socket = accept(server->socket, NULL, NULL)) < 0) {
        hferr("[hfsocket] accept() error %d: %s\n", errno, strerror(errno));
        return HFERR;
    }

    hfdeb("[hfsocket] done\n");

    return HFOK;
}

hferr_t hfsocket_send(hfsocket_t* conn, void* ptr, size_t size)
{
    hfdeb("[hfsocket] send: ptr=0x%016lx size=%lu\n", ptr, size);

    size_t left = size;
    char* r_ptr = (char*)ptr;
    while (left != 0) {
        ssize_t n = send(conn->socket, r_ptr, left, 0);
        r_ptr    += n;
        left     -= n;

        if (n < 0) {
            hferr("[hfsocket] error: send() failed: %s :  ptr=0x%016lx size=%lu\n", strerror(errno), ptr, size);
            return HFERR;
        }
    }

    return HFOK;
}


hferr_t hfsocket_recv(hfsocket_t* conn, void* ptr, size_t size)
{
    hfdeb("[hfsocket] recv: ptr=0x%016lx size=%lu\n", ptr, size);

    size_t left = size;
    char* r_ptr = (char*)ptr;
    while (left != 0) {

        ssize_t n = recv(conn->socket, r_ptr, left, 0);
        r_ptr    += n;
        left     -= n;

        if (n < 0) {
            hferr("[hfsocket] error: recv() failed: %s :  ptr=0x%016lx size=%lu\n", strerror(errno), ptr, size);
            return HFERR;
        }

        if (n == 0) {
            hfdeb("[hfsocket] peer disconnected\n");
            return HFOK;
        }
    }

    return HFOK;
}

hferr_t hfsocket_client_free(hfsocket_t* client)
{
    close(client->socket);
    return HFOK;
}

hferr_t hfsocket_server_free(hfsocket_t* server)
{
    close(server->socket);
    return HFOK;
}


