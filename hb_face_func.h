#ifndef PHP_HB_HB_FACE_FUNC_H
#define PHP_HB_HB_FACE_FUNC_H

#include "php_harfbuzz.h"

ZEND_BEGIN_ARG_INFO(arginfo_hb_face_count, 0)
	ZEND_ARG_INFO(0, blob)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_face_create, 0, 0, 2)
	ZEND_ARG_INFO(0, blob)
	ZEND_ARG_INFO(0, index)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_face_get_glyph_count, 0)
	ZEND_ARG_INFO(0, face)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_face_reference_blob, 0)
	ZEND_ARG_INFO(0, face)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_hb_face_destroy, 0)
	ZEND_ARG_INFO(0, face)
ZEND_END_ARG_INFO()

PHP_FUNCTION(hb_face_create);
PHP_FUNCTION(hb_face_count);
PHP_FUNCTION(hb_face_get_glyph_count);
PHP_FUNCTION(hb_face_reference_blob);
PHP_FUNCTION(hb_face_destroy);

#endif