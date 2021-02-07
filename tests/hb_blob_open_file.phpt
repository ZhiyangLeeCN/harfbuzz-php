--TEST--
Test function hb_blob_create_from_file()
--FILE--
<?php
$filename = './tests/fonts/test_001.otf';
$blob = hb_blob_create_from_file($filename);
$len = hb_blob_get_length($blob);
if ($len <= 0) {
    die("{$filename} open failed.");
} else {
    var_dump($len);
}
hb_blob_destroy($blob);
?>
--EXPECTF--
int(%d)
