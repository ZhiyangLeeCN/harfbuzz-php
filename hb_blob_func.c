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
    size_t len = 0;
    
    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = PHP_HB_RES_FETCH(Z_RES_P(val), hb_blob_t);
    len = hb_blob_get_length(blob);

    RETURN_LONG(len);
}

PHP_FUNCTION(hb_blob_write_data)
{
    const char *data = NULL;
    zval *out = NULL;
    zval *res = NULL;
    php_stream *stream = NULL;
    size_t ret = 0;
    unsigned int len = 0;

    
    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(out)
        Z_PARAM_RESOURCE(res)
    ZEND_PARSE_PARAMETERS_END();

    hb_blob_t *blob = PHP_HB_RES_FETCH(Z_RES_P(res), hb_blob_t);
    data = hb_blob_get_data(blob, &len);

    if (len == 0) {
        RETURN_LONG(0);
    } else {
        php_stream_from_res(stream, Z_RES_P(out));
        ret = php_stream_write(stream, data, len);

        RETURN_LONG(ret);
    }
}

PHP_FUNCTION(hb_blob_destroy)
{
    php_hb_res_destroy(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}