#include "hb_subset_helper.h"
#include "unicode/utypes.h"
#include "unicode/utext.h"

zend_long hb_ut_set_add(hb_set_t *codepoints, zend_string *str) 
{
    zend_long added = 0;
    UText *ut = NULL;
    UChar32 c = -1;
    UErrorCode status = U_ZERO_ERROR;

    ut = utext_openUTF8(ut, ZSTR_VAL(str), ZSTR_LEN(str), &status);
    if (U_FAILURE(status)) {
        goto error;
    }

    for (c = UTEXT_NEXT32(ut), added = 0; c != U_SENTINEL; c = UTEXT_NEXT32(ut), added++) {
        hb_set_add(codepoints, c);
    }

error:
    utext_close(ut);
    return added;
}