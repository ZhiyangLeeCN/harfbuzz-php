#include "hb_blob_func.h"

PHP_FUNCTION(hb_blob_create_from_file)
{
    char *filename = NULL;
    size_t filename_len;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_STRING(filename, filename_len)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = hb_blob_create_from_file(filename);
    RETURN_PHP_HB_RES(blob, PHP_HB_RES_ID(hb_blob_t));
}

PHP_FUNCTION(hb_blob_get_length)
{
    zval *val = NULL;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = PHP_HB_RES_FETCH(Z_RES_P(val), hb_blob_t);
    unsigned int len = hb_blob_get_length(blob);

    RETURN_LONG(len);
}

PHP_FUNCTION(hb_blob_get_data)
{
    zval *val = NULL;
    zend_string *result = NULL;
    const char *ptr = NULL;
    const char *data = NULL;
    unsigned length = 0;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = PHP_HB_RES_FETCH(Z_RES_P(val), hb_blob_t);
    data = hb_blob_get_data(blob, &length);

    if (length == 0) {
        RETURN_EMPTY_STRING();
    } else {
        result = zend_string_alloc(length, 0);
        ptr = ZSTR_VAL(result);
        memcpy((void *)ptr, data, length);

        RETURN_STRING(result);
    }
}

PHP_FUNCTION(hb_blob_destroy)
{
    php_hb_res_destroy(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}