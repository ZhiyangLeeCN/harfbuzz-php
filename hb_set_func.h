//
// author: LiZhiYang
// email: zhiyangleecn@gmail.com
//

#ifndef PHP_HB_HB_SET_FUNC_H
#define PHP_HB_HB_SET_FUNC_H

#include "php_harfbuzz.h"

ZEND_BEGIN_ARG_INFO(arginfo_hb_set_create, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_set_add, 0, 0, 2)
    ZEND_ARG_INFO(0, set)
    ZEND_ARG_INFO(0, codepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_set_has, 0, 0, 2)
    ZEND_ARG_INFO(0, set)
    ZEND_ARG_INFO(0, codepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_set_del, 0, 0, 2)
    ZEND_ARG_INFO(0, set)
    ZEND_ARG_INFO(0, codepoint)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_set_is_empty, 0, 0, 1)
    ZEND_ARG_INFO(0, set)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_set_destroy, 0, 0, 1)
    ZEND_ARG_INFO(0, set)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_set_reference, 0, 0, 1)
                ZEND_ARG_INFO(0, set)
ZEND_END_ARG_INFO()

PHP_FUNCTION(hb_set_create);
PHP_FUNCTION(hb_set_add);
PHP_FUNCTION(hb_set_has);
PHP_FUNCTION(hb_set_del);
PHP_FUNCTION(hb_set_is_empty);
PHP_FUNCTION(hb_set_reference);
PHP_FUNCTION(hb_set_destroy);


#endif //PHP_HB_HB_SET_FUNC_H
