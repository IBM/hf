#include "hfcomm.h"

struct {
    const char *str;
    hfcomm_type_t type;
} hfcomm_type[] = {
    { "hfsocket", HFCOMM_SOCKET },
    { "hfib", HFCOMM_IB },
    { "hfmxm", HFCOMM_MXM }
};

hferr_t hfcomm_client_connect(hfcomm_t* client, char* host, int port, hfcomm_type_t type) 
{
    hfdeb("[hfcomm] hfcomm_client_connect(): hfcomm=0x%016lx host=%s port=%d type=%d=%s\n",
            client, host, port, type, hfcomm_type2str(type));

    client->type = type;

    switch (client->type) {

        case HFCOMM_SOCKET:
            client->hfconn = (void*) malloc (sizeof(hfsocket_t));
            client->send = (typeof(client->send)) &hfsocket_send;
            client->recv = (typeof(client->recv)) &hfsocket_recv;
            client->conn_free = (typeof(client->conn_free)) &hfsocket_client_free;
            return hfsocket_client_connect(client->hfconn, host, port);

        case HFCOMM_IB:
            client->hfconn = (void*) malloc (sizeof(hfib_t));
            client->send = (typeof(client->send)) &hfib_send;
            client->recv = (typeof(client->recv)) &hfib_recv;
            client->conn_free = (typeof(client->conn_free)) &hfib_client_free;
            return hfib_client_connect(client->hfconn, host, port);

        case HFCOMM_MXM:
            client->hfconn = (void*) malloc (sizeof(hfmxm_t));
            client->send = (typeof(client->send)) &hfmxm_send;
            client->recv = (typeof(client->recv)) &hfmxm_recv;
            client->conn_free = (typeof(client->conn_free)) &hfmxm_client_free;
            return hfmxm_client_connect(client->hfconn, host, port);

        default:
            hferr("[hfcomm] hfcomm_client_connect() error: invalid hfcomm type: %d (%s)\n", 
                    client->type,  hfcomm_type2str(client->type));
            return HFERR;
    }

    return HFOK;
}

hferr_t hfcomm_server_prepare(hfcomm_t* server, char* host, int port, hfcomm_type_t type) 
{
    hfdeb("[hfcomm] hfcomm_server_prepare(): hfcomm=0x%016lx host=%s port=%d type=%d=%s\n",
            server, host, port, type,  hfcomm_type2str(type));

    server->type = type;

    switch (server->type) {

        case HFCOMM_SOCKET:
            server->hfconn = (void*) malloc(sizeof(hfsocket_t));   
            server->send = (typeof(server->send)) &hfsocket_send;
            server->recv = (typeof(server->recv)) &hfsocket_recv;
            server->conn_free = (typeof(server->conn_free)) &hfsocket_server_free;
            return hfsocket_server_prepare(server->hfconn, host, port);

        case HFCOMM_IB:
            server->hfconn = (void*) malloc(sizeof(hfib_t));
            server->send = (typeof(server->send)) &hfib_send;
            server->recv = (typeof(server->recv)) &hfib_recv;
            server->conn_free = (typeof(server->conn_free)) &hfib_server_free;
            return hfib_server_prepare(server->hfconn, host, port);

        case HFCOMM_MXM:
            server->hfconn = (void*) malloc(sizeof(hfmxm_t));
            server->send = (typeof(server->send)) &hfmxm_send;
            server->recv = (typeof(server->recv)) &hfmxm_recv;
            server->conn_free = (typeof(server->conn_free)) &hfmxm_server_free;
            return hfmxm_server_prepare(server->hfconn, host, port);

        default:
            hferr("[hfcomm] hfcomm_server_prepare(): invalid hfcomm type: %d (%s)\n",
                    server->type,  hfcomm_type2str(server->type));
            return HFERR;
    }

    return HFOK;
}

hferr_t hfcomm_server_accept(hfcomm_t* server, hfcomm_t* conn)
{
    switch (server->type) {

        case HFCOMM_SOCKET:
            conn->type = HFCOMM_SOCKET;
            conn->hfconn = (void*) malloc(sizeof(hfsocket_t));
            conn->send = (typeof(conn->send)) &hfsocket_send;
            conn->recv = (typeof(conn->recv)) &hfsocket_recv;
            conn->conn_free = (typeof(conn->conn_free)) &hfsocket_server_free;
            return hfsocket_server_accept(server->hfconn, conn->hfconn);

        case HFCOMM_IB:
            conn->type = HFCOMM_IB;
            conn->hfconn = (void*) malloc(sizeof(hfib_t));
            conn->send = (typeof(conn->send)) &hfib_send;
            conn->recv = (typeof(conn->recv)) &hfib_recv;
            conn->conn_free = (typeof(conn->conn_free)) &hfib_server_free;
            return hfib_server_accept(server->hfconn, conn->hfconn);

        case HFCOMM_MXM:
            conn->type = HFCOMM_MXM;
            conn->hfconn = (void*) malloc(sizeof(hfmxm_t));
            conn->send = (typeof(conn->send)) &hfmxm_send;
            conn->recv = (typeof(conn->recv)) &hfmxm_recv;
            conn->conn_free = (typeof(conn->conn_free)) &hfmxm_server_free;
            return hfmxm_server_accept(server->hfconn, conn->hfconn);

        default:
            return HFERR;
    }

    return HFOK;
}

hferr_t hfcomm_str2type(char* str, hfcomm_type_t* type)
{
    for (unsigned i = 0; i < sizeof(hfcomm_type) / sizeof(hfcomm_type[0]); i++) {
        if (strcmp(str, hfcomm_type[i].str) == 0) {
            (*type) = hfcomm_type[i].type;
            return HFOK;
        }
    }

    hfwar("[hfcomm] invalid hfcomm option: %s\n", str);
    return HFERR;
}

const char* hfcomm_type2str( hfcomm_type_t type )
{
    for (unsigned i = 0; i < sizeof(hfcomm_type) / sizeof(hfcomm_type[0]); i++) {
        if ( hfcomm_type[i].type == type ) {
            return hfcomm_type[i].str;
        }
    }
    hfwar("[hfcomm] invalid hfcomm option: %d\n", type);
    return NULL;
}

