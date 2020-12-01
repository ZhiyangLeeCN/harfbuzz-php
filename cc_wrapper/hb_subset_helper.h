#ifndef PHP_HB_HB_SUBSET_HELPER_H
#define PHP_HB_HB_SUBSET_HELPER_H

#include "wrapper_common.h"

#ifdef __cplusplus
extern "C" {
#endif

    zend_long hb_ut_set_add(hb_set_t *codepoints, zend_string *str);

#ifdef __cplusplus
} // extern
#endif

#endif