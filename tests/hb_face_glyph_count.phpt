--TEST--
Test hb_face_get_glyph_count()
--FILE--
<?php
$filename = './tests/fonts/test_001.otf';
$blob = hb_blob_create_from_file($filename);
$len = hb_blob_get_length($blob);
if ($len <= 0) {
    die("{$filename} open failed.");
}

$face = hb_face_create($blob, 0);
$glyph_count = hb_face_get_glyph_count($face);
//file `./tests/fonts/test_001.otf` total contain 29 graphics.
var_dump($glyph_count == 29);

hb_face_destroy($face);
hb_blob_destroy($blob);
?>
--EXPECT--
bool(true)