#ifndef PHP_HARFBUZZ_H
#define PHP_HARFBUZZ_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_streams.h"
#include "ext/standard/info.h"

#include "hb_res.h"

#include "cc_wrapper/cc_api_wrapper.h"

extern zend_module_entry harfbuzz_module_entry;
#define phpext_harfbuzz_ptr &harfbuzz_module_entry

#define PHP_HARFBUZZ_VERSION "0.1.0"
#define PHP_HARFBUZZ_LIB_VERSION "2.7.2"

#ifdef PHP_WIN32
#	define PHP_HARFBUZZ_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_HARFBUZZ_API __attribute__ ((visibility("default")))
#else
#	define PHP_HARFBUZZ_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

#define HARFBUZZ_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(harfbuzz, v)

#if defined(ZTS) && defined(COMPILE_DL_HARFBUZZ)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif