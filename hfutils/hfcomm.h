#ifndef _HFCOMM_H_
#define _HFCOMM_H_

#include <stddef.h>

#include "hfib.h"
#include "hflog.h"
#include "hfmxm.h"
#include "hfsocket.h"

typedef enum {
    HFCOMM_SOCKET,
    HFCOMM_IB,
    HFCOMM_MXM
} hfcomm_type_t;

typedef struct {
    hfcomm_type_t   type;

    void* hfconn; 
    hferr_t (*send)(void* conn, void* ptr, size_t size);
    hferr_t (*recv)(void* conn, void* ptr, size_t size);

    hferr_t (*conn_free)(void* conn);
} hfcomm_t;

hferr_t hfcomm_client_connect (hfcomm_t* client, char* host, int port, hfcomm_type_t type);
hferr_t hfcomm_server_prepare (hfcomm_t* server, char* host, int port, hfcomm_type_t type);
hferr_t hfcomm_server_accept  (hfcomm_t* server, hfcomm_t* conn);

static inline hferr_t hfcomm_send(hfcomm_t* conn, void* ptr, size_t size) 
{
  if( __builtin_expect( conn && conn->send, 1 ) )
    return (*conn->send)(conn->hfconn, ptr, size);
  else
    return HFERR;
}
static inline hferr_t hfcomm_recv (hfcomm_t* conn, void* ptr, size_t size)
{
  if( __builtin_expect( conn && conn->recv, 1 ) )
    return (*conn->recv)(conn->hfconn, ptr, size);
  else
    return HFERR;
}
static hferr_t hfcomm_free(hfcomm_t* conn) 
{
  if( conn && conn->conn_free ) {
    hferr_t err = (*conn->conn_free)( conn->hfconn );
    free( conn->hfconn ); // was allocated here!
    return err;
  }
  else
    return HFERR;
}

hferr_t hfcomm_str2type( char* str, hfcomm_type_t* type);
const char* hfcomm_type2str( hfcomm_type_t type );

#endif /* #ifndef _HFCOMM_H_ */
