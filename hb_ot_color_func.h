#ifndef PHP_HB_HB_OT_COLOR_FUNC_H
#define PHP_HB_HB_OT_COLOR_FUNC_H

#include "php_harfbuzz.h"

ZEND_BEGIN_ARG_INFO(arginfo_hb_ot_color_has_svg, 0)
	ZEND_ARG_INFO(0, face)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_hb_ot_color_glyph_reference_svg, 0, 0, 2)
	ZEND_ARG_INFO(0, face)
	ZEND_ARG_INFO(0, glyph_id)
ZEND_END_ARG_INFO()


PHP_FUNCTION(hb_ot_color_has_svg);
PHP_FUNCTION(hb_ot_color_glyph_reference_svg);

#endif