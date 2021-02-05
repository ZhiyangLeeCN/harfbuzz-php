#include "hb_subset_helper_func.h"

PHP_FUNCTION(help_add_subset_input_unicode_set)
{
    zval *val = NULL;
    zend_string *str = NULL;
    zend_long z_added = 0;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_STR(str)
    ZEND_PARSE_PARAMETERS_END();

    hb_set_t *set = PHP_HB_RES_FETCH(Z_RES_P(val), hb_set_t);

    z_added = hb_ut_set_add(set, str);
    RETURN_LONG(z_added);
}