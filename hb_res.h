#ifndef PHP_HB_PHP_HB_RES_H
#define PHP_HB_PHP_HB_RES_H

#include "php_harfbuzz.h"

#define PHP_HB_RES_ID(name) php_hb_##name##_res_id
#define DEF_PHP_HB_RES_ID(name) int PHP_HB_RES_ID(name)
#define DEF_EXTERN_PHP_HB_RES_ID(name) extern DEF_PHP_HB_RES_ID(name)
#define SET_PHP_HB_RES_ID(name, id) PHP_HB_RES_ID(name) = id

#define PHP_HB_RES_DTOR(name) php_hb_##name##_res_dtor
#define PHP_HB_RES_DTOR_FUNCTION(name) void PHP_HB_RES_DTOR(name)(zend_resource *resource)

#define PHP_HB_RES_FETCH(resource, name) zend_fetch_resource(resource, #name, PHP_HB_RES_ID(name))

#define RETURN_PHP_HB_RES(type, res_id) \
    do {    \
        zend_resource *resource = zend_register_resource(type, res_id); \
        RETURN_RES(resource);   \
    } while(0)   \

#define PHP_HB_RES_REGISTER(name, res_dtor, module_number) \
    PHP_HB_RES_ID(name) = zend_register_list_destructors_ex(res_dtor, NULL, #name, module_number)

DEF_EXTERN_PHP_HB_RES_ID(hb_blob_t);
DEF_EXTERN_PHP_HB_RES_ID(hb_face_t);
DEF_EXTERN_PHP_HB_RES_ID(hb_font_t);
DEF_EXTERN_PHP_HB_RES_ID(hb_subset_input_t);

void php_hb_res_list_register(int module_number);
void php_hb_res_destroy(INTERNAL_FUNCTION_PARAMETERS);

#endif