#ifndef PHP_HB_HB_FONT_FUNC_H
#define PHP_HB_HB_FONT_FUNC_H

#include "php_harfbuzz.h"

ZEND_BEGIN_ARG_INFO(arginfo_hb_font_create, 0)
	ZEND_ARG_INFO(0, face)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_font_destroy, 0)
	ZEND_ARG_INFO(0, font)
ZEND_END_ARG_INFO()

PHP_FUNCTION(hb_font_create);
PHP_FUNCTION(hb_font_destroy);

#endif