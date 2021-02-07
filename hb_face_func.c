#include "hb_face_func.h"

PHP_FUNCTION(hb_face_count)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = PHP_HB_RES_FETCH(Z_RES_P(val), hb_blob_t);
    unsigned int count = hb_face_count(blob);
    RETURN_LONG(count)
}

PHP_FUNCTION(hb_face_create)
{
    zval *val = NULL;
    zend_long index;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_LONG(index)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = PHP_HB_RES_FETCH(Z_RES_P(val), hb_blob_t);
    hb_face_t *face = hb_face_create(blob, (unsigned int)index);

    RETURN_PHP_HB_RES(face, PHP_HB_RES_ID(hb_face_t));
}

PHP_FUNCTION(hb_face_get_glyph_count)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();
    
    hb_face_t *face = PHP_HB_RES_FETCH(Z_RES_P(val), hb_face_t);
    unsigned int glyph_count = hb_face_get_glyph_count(face);

    RETURN_LONG(glyph_count)
}

PHP_FUNCTION(hb_face_reference_blob)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();
    
    hb_face_t *face = PHP_HB_RES_FETCH(Z_RES_P(val), hb_face_t);
    hb_blob_t *blob = hb_face_reference_blob(face);
    RETURN_PHP_HB_RES(blob, PHP_HB_RES_ID(hb_blob_t));
}

PHP_FUNCTION(hb_face_destroy)
{
    php_hb_res_destroy(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}