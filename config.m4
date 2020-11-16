PHP_ARG_WITH([harfbuzz],
  [for harfbuzz support],
  [AS_HELP_STRING([--with-harfbuzz],
    [for harfbuzz support])])

if test "$PHP_HARFBUZZ" != "no"; then

    HARFBUZZ_EXIT_DIR=PHP_EXT_DIR(harfbuzz)
    PHP_ADD_INCLUDE(lib/src)

    PHP_REQUIRE_CXX()
    PHP_HARFBUZZ_CXX_FLAGS="-DHAVE_INTEL_ATOMIC_PRIMITIVES -DHAVE_ROUNDF -DHB_NO_MMAP -DHB_NO_RESOURCE_FORK \
      -DHB_NO_SUBSET_LAYOUT -DHB_NO_SUBSET_CFF -DHB_NO_FALLBACK_SHAPE -DHB_NO_WIN1256 -DHB_EXPERIMENTAL_API"
    PHP_HARFBUZZ_SOURCES="harfbuzz.c hb_res.c\
			hb_blob_func.c hb_face_func.c hb_font_func.c hb_ot_color_func.c hb_subset_func.c"
    PHP_NEW_EXTENSION(harfbuzz, $PHP_HARFBUZZ_SOURCES, $ext_shared, ,$PHP_HARFBUZZ_CXX_FLAGS)

    LIB_HARFBUZZ_SOURCES="lib/src/hb-aat-layout.cc lib/src/hb-aat-map.cc lib/src/hb-blob.cc\
			lib/src/hb-buffer-serialize.cc lib/src/hb-buffer.cc lib/src/hb-common.cc lib/src/hb-coretext.cc lib/src/hb-directwrite.cc\
			lib/src/hb-draw.cc lib/src/hb-face.cc lib/src/hb-fallback-shape.cc lib/src/hb-font.cc lib/src/hb-ft.cc lib/src/hb-gdi.cc lib/src/hb-glib.cc\
			lib/src/hb-gobject-structs.cc lib/src/hb-graphite2.cc lib/src/hb-icu.cc lib/src/hb-map.cc lib/src/hb-number.cc lib/src/hb-ot-cff1-table.cc\
			lib/src/hb-ot-cff2-table.cc lib/src/hb-ot-color.cc lib/src/hb-ot-face.cc lib/src/hb-ot-font.cc lib/src/hb-ot-layout.cc lib/src/hb-ot-map.cc\
			lib/src/hb-ot-math.cc lib/src/hb-ot-meta.cc lib/src/hb-ot-metrics.cc lib/src/hb-ot-name.cc lib/src/hb-ot-shape-complex-arabic.cc\
			lib/src/hb-ot-shape-complex-default.cc lib/src/hb-ot-shape-complex-hangul.cc lib/src/hb-ot-shape-complex-hebrew.cc\
			lib/src/hb-ot-shape-complex-indic-table.cc lib/src/hb-ot-shape-complex-indic.cc lib/src/hb-ot-shape-complex-khmer.cc\
			lib/src/hb-ot-shape-complex-myanmar.cc lib/src/hb-ot-shape-complex-thai.cc lib/src/hb-ot-shape-complex-use-table.cc\
			lib/src/hb-ot-shape-complex-use.cc lib/src/hb-ot-shape-complex-vowel-constraints.cc lib/src/hb-ot-shape-fallback.cc\
			lib/src/hb-ot-shape-normalize.cc lib/src/hb-ot-shape.cc lib/src/hb-ot-tag.cc lib/src/hb-ot-var.cc lib/src/hb-set.cc lib/src/hb-shape-plan.cc\
			lib/src/hb-shape.cc lib/src/hb-shaper.cc lib/src/hb-static.cc lib/src/hb-style.cc lib/src/hb-subset-cff-common.cc lib/src/hb-subset-cff1.cc\
			lib/src/hb-subset-cff2.cc lib/src/hb-subset-input.cc lib/src/hb-subset-plan.cc lib/src/hb-subset.cc lib/src/hb-ucd.cc lib/src/hb-unicode.cc lib/src/hb-uniscribe.cc"
    PHP_HARFBUZZ_CXX_FLAGS="$PHP_HARFBUZZ_CXX_FLAGS -std=c++11"
    PHP_ADD_SOURCES_X($HARFBUZZ_EXIT_DIR, $LIB_HARFBUZZ_SOURCES, $PHP_HARFBUZZ_CXX_FLAGS, shared_objects_harfbuzz, yes)
    
fi