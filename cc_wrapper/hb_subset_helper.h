#ifndef PHP_HB_HB_SUBSET_HELPER_H
#define PHP_HB_HB_SUBSET_ICU_HELPER_H

#include "cc_api_wrapper.h"

extern "C" {
    size_t hb_ut_set_add(hb_set_t *codepoints, const char *s, size_t len);
}

#endif