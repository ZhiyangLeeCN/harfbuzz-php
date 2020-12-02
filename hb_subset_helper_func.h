#ifndef PHP_HB_HB_SUBSET_HELPER_FUNC_H
#define PHP_HB_HB_SUBSET_HELPER_FUNC_H

#include "php_harfbuzz.h"
#include "cc_wrapper/hb_subset_helper.h"

ZEND_BEGIN_ARG_INFO_EX(arginfo_help_hb_set_add, 0, 0, 2)
	ZEND_ARG_INFO(0, input)
	ZEND_ARG_INFO(0, s)
ZEND_END_ARG_INFO()

PHP_FUNCTION(help_hb_set_add);

#endif