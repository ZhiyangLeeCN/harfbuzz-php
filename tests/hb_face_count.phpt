--TEST--
Test hb_face_count()
--FILE--
<?php
$filename = './tests/fonts/test_001.otf';
$blob = hb_blob_create_from_file($filename);
$len = hb_blob_get_length($blob);
if ($len <= 0) {
    die("{$filename} open failed.");
}

$count = hb_face_count($blob);
var_dump($count);
var_dump($count > 0);

hb_blob_destroy($blob);
?>
--EXPECTF--
int(%d)
bool(true)
