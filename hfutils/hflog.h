#pragma once

#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>

#include <pthread.h>

typedef enum hflog_level {
    HFLOG_LEVEL_TRACE,
    HFLOG_LEVEL_DEBUG,
    HFLOG_LEVEL_INFO,
    HFLOG_LEVEL_WARNING,
    HFLOG_LEVEL_ERROR,
    HFLOG_LEVEL_OFF,
} hflog_level_t;

typedef enum hferr {
    HFOK  = 0,
    HFERR = -1,
    HFErrorRemoteHostAddrDoesNotExist = -2,
    HFErrorHostAddrNotManaged = -3,
} hferr_t;

hferr_t hflog (hflog_level_t level, char* fmt, ...);

#define hftra(fmt, ...) hflog(HFLOG_LEVEL_TRACE,   fmt, ##__VA_ARGS__)
#define hfdeb(fmt, ...) hflog(HFLOG_LEVEL_DEBUG,   fmt, ##__VA_ARGS__)
#define hfinf(fmt, ...) hflog(HFLOG_LEVEL_INFO,    fmt, ##__VA_ARGS__)
#define hfwar(fmt, ...) hflog(HFLOG_LEVEL_WARNING, fmt, ##__VA_ARGS__)
#define hferr(fmt, ...) hflog(HFLOG_LEVEL_ERROR,   fmt, ##__VA_ARGS__)

#define hfcheck( err ) \
({ \
    hferr_t ____err = err; \
    if (____err) { \
        hferr("[hferr] ERROR: %d in %s() %s:%d\n", \
               ____err, __FUNCTION__, __FILE__, __LINE__ ); \
        exit(____err); \
    } \
    ____err; \
})
