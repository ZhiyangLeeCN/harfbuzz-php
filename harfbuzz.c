#include "php_harfbuzz.h"

#include "hb_blob_func.h"
#include "hb_set_func.h"
#include "hb_face_func.h"
#include "hb_font_func.h"
#include "hb_ot_color_func.h"
#include "hb_subset_func.h"
#include "hb_subset_helper_func.h"

PHP_MINIT_FUNCTION(harfbuzz)
{
    php_hb_res_list_register(module_number);
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(harfbuzz)
{
    return SUCCESS;
}

PHP_RINIT_FUNCTION(harfbuzz)
{
#if defined(COMPILE_DL_HARFBUZZ) && defined(ZTS)
    ZEND_TSRMLS_CACHE_UPDATE();
#endif
    return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(harfbuzz)
{
    return SUCCESS;
}

PHP_MINFO_FUNCTION(harfbuzz)
{
    php_info_print_table_start();
    php_info_print_table_header(2, "harfbuzz support", "enabled");
    php_info_print_table_header(2, "harfbuzz lib", PHP_HARFBUZZ_LIB_VERSION);
    php_info_print_table_end();
}

const zend_function_entry harfbuzz_functions[] = {
    PHP_FE(hb_blob_create_from_file,            arginfo_hb_blob_create_from_file)
    PHP_FE(hb_blob_get_length,                  arginfo_hb_blob_get_length)
    PHP_FE(hb_blob_write_data,                  arginfo_hb_blob_write_data)
    PHP_FE(hb_blob_destroy,                     arginfo_hb_blob_destroy)

    PHP_FE(hb_set_create,                       arginfo_hb_set_create)
    PHP_FE(hb_set_add,                          arginfo_hb_set_add)
    PHP_FE(hb_set_has,                          arginfo_hb_set_has)
    PHP_FE(hb_set_del,                          arginfo_hb_set_del)
    PHP_FE(hb_set_is_empty,                     arginfo_hb_set_is_empty)
    PHP_FE(hb_set_reference,                    arginfo_hb_set_reference)
    PHP_FE(hb_set_destroy,                      arginfo_hb_set_destroy)

    PHP_FE(hb_face_create,                      arginfo_hb_face_create)
    PHP_FE(hb_face_count,                       arginfo_hb_face_count)
    PHP_FE(hb_face_destroy,                     arginfo_hb_face_destroy)

    PHP_FE(hb_font_create,                      arginfo_hb_font_create)
    PHP_FE(hb_face_get_glyph_count,             arginfo_hb_face_get_glyph_count)
    PHP_FE(hb_face_reference_blob,              arginfo_hb_face_reference_blob)
    PHP_FE(hb_font_destroy,                     arginfo_hb_font_destroy)

    PHP_FE(hb_ot_color_has_svg,                 arginfo_hb_ot_color_has_svg)
    PHP_FE(hb_ot_color_glyph_reference_svg,     arginfo_hb_ot_color_glyph_reference_svg)

    PHP_FE(hb_subset_input_create_or_fail,      arginfo_hb_subset_input_create_or_fail)
    PHP_FE(hb_subset,                           arginfo_hb_subset)
    PHP_FE(hb_subset_input_unicode_set,         arginfo_hb_subset_input_unicode_set)
    PHP_FE(hb_subset_input_drop_tables_set,     arginfo_hb_subset_input_drop_tables_set)
    PHP_FE(hb_subset_input_destroy,             arginfo_hb_subset_input_destroy)

    PHP_FE(help_add_subset_input_unicode_set,   arginfo_help_add_subset_input_unicode_set)

    PHP_FE_END
};

zend_module_entry harfbuzz_module_entry = {
    STANDARD_MODULE_HEADER,
    "harfbuzz",
    harfbuzz_functions,
    PHP_MINIT(harfbuzz),
    PHP_MSHUTDOWN(harfbuzz),
    PHP_RINIT(harfbuzz),
    PHP_RSHUTDOWN(harfbuzz),
    PHP_MINFO(harfbuzz),
    PHP_HARFBUZZ_VERSION,
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HARFBUZZ
#ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
#endif
ZEND_GET_MODULE(harfbuzz)
#endif