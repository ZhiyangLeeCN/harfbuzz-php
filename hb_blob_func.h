#ifndef PHP_HB_HB_BLOB_FUNC_H
#define PHP_HB_HB_BLOB_FUNC_H

#include "php_harfbuzz.h"

ZEND_BEGIN_ARG_INFO(arginfo_hb_blob_create_from_file, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_blob_get_length, 0)
	ZEND_ARG_INFO(0, blob)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_blob_get_data, 0)
	ZEND_ARG_INFO(0, blob)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_blob_destroy, 0)
	ZEND_ARG_INFO(0, blob)
ZEND_END_ARG_INFO()

PHP_FUNCTION(hb_blob_create_from_file);
PHP_FUNCTION(hb_blob_get_length);
PHP_FUNCTION(hb_blob_get_data);
PHP_FUNCTION(hb_blob_destroy);

#endif