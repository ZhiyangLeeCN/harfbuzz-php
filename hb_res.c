#include "hb_res.h"

DEF_PHP_HB_RES_ID(hb_blob_t);
DEF_PHP_HB_RES_ID(hb_set_t);
DEF_PHP_HB_RES_ID(hb_face_t);
DEF_PHP_HB_RES_ID(hb_font_t);
DEF_PHP_HB_RES_ID(hb_subset_input_t);

PHP_HB_RES_DTOR_FUNCTION(hb_blob_t)
{
    hb_blob_t *blob = (hb_blob_t *)resource->ptr;
    hb_blob_destroy(blob);
}

PHP_HB_RES_DTOR_FUNCTION(hb_set_t)
{
    hb_set_t *set = (hb_set_t *)resource->ptr;
    hb_set_destroy(set);
}

PHP_HB_RES_DTOR_FUNCTION(hb_face_t)
{
    hb_face_t *face = (hb_face_t *)resource->ptr;
    hb_face_destroy(face);
}

PHP_HB_RES_DTOR_FUNCTION(hb_font_t)
{
    hb_font_t *font = (hb_font_t *)resource->ptr;
    hb_font_destroy(font);
}

PHP_HB_RES_DTOR_FUNCTION(hb_subset_input_t)
{
    hb_subset_input_t *font = (hb_subset_input_t *)resource->ptr;
    hb_subset_input_destroy(font);
}

void php_hb_res_list_register(int module_number)
{
    PHP_HB_RES_REGISTER(hb_blob_t, PHP_HB_RES_DTOR(hb_blob_t), module_number);
    PHP_HB_RES_REGISTER(hb_set_t, PHP_HB_RES_DTOR(hb_set_t), module_number);
    PHP_HB_RES_REGISTER(hb_face_t, PHP_HB_RES_DTOR(hb_face_t), module_number);
    PHP_HB_RES_REGISTER(hb_font_t, PHP_HB_RES_DTOR(hb_font_t), module_number);
    PHP_HB_RES_REGISTER(hb_subset_input_t, PHP_HB_RES_DTOR(hb_subset_input_t), module_number);
}

void php_hb_res_destroy(INTERNAL_FUNCTION_PARAMETERS)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    zend_list_close(Z_RES_P(val));
}