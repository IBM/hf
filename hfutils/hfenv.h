#pragma once

#include <stdlib.h>

#include "hflog.h"

hferr_t hfenv (const char* envar, const char** enval, const char* defval);

