#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#include "hflog.h"
#include "hfstr.h"

int intpow(int base, int exp)
{
    int result = 1;

    for (int i = 0; i < exp; i++)
        result *= base;

    return result;
}

hferr_t hfstr_char2int(const char char_, int* int_)
{
    if (!isdigit(char_)) {
        hfwar("[hfstr] invalid character (char2int): %c\n", char_);
        return HFERR;
    }

    *int_ = char_ - '0';
    return HFOK;
}

hferr_t hfstr_str2int(const char* str_, int* int_)
{
    *int_ = 0;
    int len = strlen(str_);

    for (int i = len - 1; i >= 0; i--) {

        if (str_[i] == '-' && i == 0) {
            *int_ = -(*int_);
            continue;
        }

        int digit;
        if (hfstr_char2int(str_[i], &digit)) {
            hfwar("[hfstr] invalid character (str2int): %c\n", str_[i]);
            return HFERR;
        }

        *int_ += digit * intpow(10, len - 1 - i);
    }

    return HFOK;
}

hferr_t hfstr_str2bool(const char* str_, bool* bool_)
{
    if      (strcmp(str_, "true")  == 0)
        *bool_ = true;
    else if (strcmp(str_, "false") == 0)
        *bool_ = false;
    else if (strcmp(str_, "yes")   == 0)
        *bool_ = true;
    else if (strcmp(str_, "no")    == 0)
        *bool_ = false;
    else {
        hfwar("[hfstr] invalid string (str2bool): %s\n", str_);
        return HFERR;
    }

    return HFOK;
}

hferr_t hfstr_bool2str(bool bool_, const char** str_)
{
    *str_ = bool_ ? "true" : "false";
    return HFOK;
}

