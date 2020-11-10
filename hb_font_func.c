#include "hb_font_func.h"

PHP_FUNCTION(hb_font_create)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();
    
    hb_face_t *face = PHP_HB_RES_FETCH(Z_RES_P(val), hb_face_t);
    hb_font_t *font = hb_font_create(face);

    RETURN_PHP_HB_RES(font, PHP_HB_RES_ID(hb_font_t));
}

PHP_FUNCTION(hb_font_destroy)
{
    php_hb_res_destroy(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}