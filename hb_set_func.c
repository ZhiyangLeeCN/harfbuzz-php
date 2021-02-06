//
// author: LiZhiYang
// email: zhiyangleecn@gmail.com
//

#include "hb_set_func.h"

PHP_FUNCTION(hb_set_create)
{
    hb_set_t *set = hb_set_create();
    RETURN_PHP_HB_RES(set, PHP_HB_RES_ID(hb_set_t));
}

PHP_FUNCTION(hb_set_add)
{
    zval *val = NULL;
    zend_long codepoint = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_LONG(codepoint)
    ZEND_PARSE_PARAMETERS_END();

    hb_set_t *set = PHP_HB_RES_FETCH(Z_RES_P(val), hb_set_t);
    hb_set_add(set, codepoint);
}

PHP_FUNCTION(hb_set_has)
{
    zval *val = NULL;
    zend_long codepoint = 0;
    hb_bool_t has = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_LONG(codepoint)
    ZEND_PARSE_PARAMETERS_END();

    hb_set_t *set = PHP_HB_RES_FETCH(Z_RES_P(val), hb_set_t);
    has = hb_set_has(set, codepoint);
    RETURN_BOOL(has)
}

PHP_FUNCTION(hb_set_del)
{
    zval *val = NULL;
    zend_long codepoint = 0;

    ZEND_PARSE_PARAMETERS_START(2, 2)
        Z_PARAM_RESOURCE(val)
        Z_PARAM_LONG(codepoint)
    ZEND_PARSE_PARAMETERS_END();

    hb_set_t *set = PHP_HB_RES_FETCH(Z_RES_P(val), hb_set_t);
    hb_set_del(set, codepoint);
}

PHP_FUNCTION(hb_set_is_empty)
{
    zval *val = NULL;
    hb_bool_t result = 0;

    ZEND_PARSE_PARAMETERS_START(1, 1)
        Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_set_t *set = PHP_HB_RES_FETCH(Z_RES_P(val), hb_set_t);
    result = hb_set_is_empty(set);
    RETURN_BOOL(result)
}

PHP_FUNCTION(hb_set_reference)
{
    zval *val = NULL;
    ZEND_PARSE_PARAMETERS_START(1, 1)
            Z_PARAM_RESOURCE(val)
    ZEND_PARSE_PARAMETERS_END();

    hb_set_t *set = PHP_HB_RES_FETCH(Z_RES_P(val), hb_set_t);
    RETURN_PHP_HB_RES(hb_set_reference(set), PHP_HB_RES_ID(hb_set_t));
}

PHP_FUNCTION(hb_set_destroy)
{
    php_hb_res_destroy(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}