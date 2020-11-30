#include "hb_subset_helper.h"
#include "unicode/utypes.h"
#include "unicode/utext.h"

size_t hb_ut_set_add(hb_set_t *codepoints, const char *s, size_t len) 
{
    size_t added = 0;
    UText *ut = NULL;
    UChar32 c = -1;
    UErrorCode status;

    ut = utext_openUTF8(ut, s, len, &status);
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