--TEST--
Test hb_blob_write_data()
--FILE--
<?php
$filename = './tests/fonts/test_001.otf';
$blob = hb_blob_create_from_file($filename);
$len = hb_blob_get_length($blob);
if ($len <= 0) {
    die("{$filename} open failed.");
}

$tmp_out_path = './tests/tmp_out/';
@mkdir($tmp_out_path);

$tmp_out_filename = $tmp_out_path . 'test_hb_blob_write_data.otf';
$outFd = fopen($tmp_out_filename, 'w');
$writes = hb_blob_write_data($outFd, $blob);

fclose($outFd);
hb_blob_destroy($blob);

var_dump($writes == $len);
var_dump(filesize($tmp_out_filename) == $len);

?>
--EXPECT--
bool(true)
bool(true)
--CLEAN--
<?php
@unlink('./tests/tmp_out/test_hb_blob_write_data.otf');
@rmdir('./tests/tmp_out/');
?>
