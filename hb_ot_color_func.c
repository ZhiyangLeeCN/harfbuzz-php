#include "hb_ot_color_func.h"

PHP_FUNCTION(hb_ot_color_has_svg)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_face_t *face = PHP_HB_RES_FETCH(Z_RES_P(val), hb_face_t);
    hb_bool_t has = hb_ot_color_has_svg(face);

    RETURN_BOOL(has);
}

PHP_FUNCTION(hb_ot_color_glyph_reference_svg)
{
    zval *val = NULL;
    zend_long glyph_id;
    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_LONG(glyph_id)
    ZEND_PARSE_PARAMETERS_END();
    
    hb_face_t *face = PHP_HB_RES_FETCH(Z_RES_P(val), hb_face_t);
    hb_blob_t *blob = hb_ot_color_glyph_reference_svg(face, (hb_codepoint_t)glyph_id);

    RETURN_PHP_HB_RES(blob, PHP_HB_RES_ID(hb_blob_t));
}