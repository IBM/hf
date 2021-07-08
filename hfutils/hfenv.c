#include "hfenv.h"

hferr_t hfenv(const char* envar, const char** enval, const char* defval)
{
    *enval = getenv(envar);

    if (*enval == NULL) {
        hfwar("[hfenv] environment variable not found: %s\n", envar);

        if (defval) {
            hfinf("[hfenv] using default value: %s\n", defval);
            *enval = defval;
        }
        else {
            return HFERR;
        }
    }

    return HFOK;
}

