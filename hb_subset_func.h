#ifndef PHP_HB_HB_SUBSET_FUNC_H
#define PHP_HB_HB_SUBSET_FUNC_H

#include "php_harfbuzz.h"

ZEND_BEGIN_ARG_INFO(arginfo_hb_subset_input_create_or_fail, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_subset, 0, 0, 2)
	ZEND_ARG_INFO(0, face)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_subset_input_unicode_set, 0)
    ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_subset_input_drop_tables_set, 0)
    ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_subset_input_destroy, 0)
	ZEND_ARG_INFO(0, blob)
ZEND_END_ARG_INFO()

PHP_FUNCTION(hb_subset_input_create_or_fail);
PHP_FUNCTION(hb_subset);
PHP_FUNCTION(hb_subset_input_unicode_set);
PHP_FUNCTION(hb_subset_input_drop_tables_set);
PHP_FUNCTION(hb_subset_input_destroy);

#endif