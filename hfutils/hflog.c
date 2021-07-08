#include "hflog.h"
#include "hfstr.h"
#include "hfenv.h"

hflog_level_t       gl_hflog_level      = HFLOG_LEVEL_ERROR;
bool                gl_hflog_color      = false;
pthread_mutex_t     gl_hflog_mutex;
__thread pid_t      gl_hflog_tid;

const char* HFLOG_ENVAR_LEVEL  = "HFLOG_LEVEL";
const char* HFLOG_ENVAR_COLOR  = "HFLOG_COLOR";

const char* hflog_level_str[] = {
    "TRACE",
    "DEBUG",
    "INFO",
    "WARN",
    "ERROR",
};

#define COLOR_RESET   "\033[00m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_GRAY    "\033[90m"

const char* hflog_color[] = {
    COLOR_GRAY,
    COLOR_CYAN,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_RED,
};

#define HFLOG_BUFFER 1024

void    hflog_init      ();
hferr_t hflog_str2level (const char* str, hflog_level_t* level);

hferr_t hflog(hflog_level_t level, char* fmt, ...)
{
    if (level < gl_hflog_level)
        return HFERR;

    char  msg[HFLOG_BUFFER] = {0};
    char* buf = msg;

    if (gl_hflog_color)
        buf += sprintf(buf, "%s", hflog_color[level]);
    buf += sprintf(buf, "[ %-5s ] ", hflog_level_str[level]);
    gl_hflog_tid = syscall(SYS_gettid);
    buf += sprintf(buf, "%s (%06d) ", getenv("HOSTNAME"), (int) gl_hflog_tid);
    if (gl_hflog_color)
        buf += sprintf(buf, "%s", COLOR_RESET);
    strcat(msg, fmt);

    pthread_mutex_lock(&gl_hflog_mutex);
    va_list ap;
    va_start(ap, fmt);
    vprintf(msg, ap);
    va_end(ap);
    pthread_mutex_unlock(&gl_hflog_mutex);

    return HFOK;
}

__attribute__((constructor)) void hflog_init()
{
    hferr_t err;

    const char* level;
    if (!(err = hfenv(HFLOG_ENVAR_LEVEL, &level, NULL)))
        err = hflog_str2level(level, &gl_hflog_level);
    if (err)
        hfinf("[hflog] using default level configuration: %s\n",
                hflog_level_str[gl_hflog_level]);

    const char* color;
    if (!(err = hfenv(HFLOG_ENVAR_COLOR, &color, NULL)))
        err = hfstr_str2bool(color, &gl_hflog_color);
    if (err)
        hfinf("[hflog] using default color configuration: %s\n",
                gl_hflog_color ? "ON" : "OFF");

    pthread_mutex_init(&gl_hflog_mutex, NULL);
}

hferr_t hflog_str2level(const char* str, hflog_level_t* level)
{
    if      (strcmp(str, "TRACE")   == 0)
        *level = HFLOG_LEVEL_TRACE;
    else if (strcmp(str, "DEBUG")   == 0)
        *level = HFLOG_LEVEL_DEBUG;
    else if (strcmp(str, "INFO")    == 0)
        *level = HFLOG_LEVEL_INFO;
    else if (strcmp(str, "WARNING") == 0)
        *level = HFLOG_LEVEL_WARNING;
    else if (strcmp(str, "ERROR")   == 0)
        *level = HFLOG_LEVEL_ERROR;
    else if (strcmp(str, "OFF")     == 0)
        *level = HFLOG_LEVEL_OFF;

    else {
        hfwar("[hflog] invalid log level option: %s\n", str);
        return HFERR;
    }

    return HFOK;
}

