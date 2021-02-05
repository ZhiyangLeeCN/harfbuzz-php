#include "hb_subset_func.h"
#include "cc_wrapper/hb_subset_helper.h"

PHP_FUNCTION(hb_subset_input_create_or_fail)
{
    hb_subset_input_t *input = hb_subset_input_create_or_fail();
    RETURN_PHP_HB_RES(input, PHP_HB_RES_ID(hb_subset_input_t));
}

PHP_FUNCTION(hb_set_add)
{
    zval *val = NULL;
    zend_long add_c = 0;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_LONG(add_c)
    ZEND_PARSE_PARAMETERS_END();

    hb_subset_input_t *input = PHP_HB_RES_FETCH(Z_RES_P(val), hb_subset_input_t);
    hb_set_t *codepoints = hb_subset_input_unicode_set (input);

    hb_set_add(codepoints, add_c);
}

PHP_FUNCTION(hb_subset)
{
    zval *face_val = NULL;
    zval *input_val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(face_val)
        Z_PARAM_RESOURCE(input_val)
    ZEND_PARSE_PARAMETERS_END();

    hb_face_t *face = PHP_HB_RES_FETCH(Z_RES_P(face_val), hb_face_t);
    hb_subset_input_t *input = PHP_HB_RES_FETCH(Z_RES_P(input_val), hb_subset_input_t);

    hb_face_t *result = hb_subset(face, input);
    RETURN_PHP_HB_RES(result, PHP_HB_RES_ID(hb_face_t));
}

PHP_FUNCTION(hb_subset_input_destroy)
{
    php_hb_res_destroy(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}