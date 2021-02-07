--TEST--
Test hb_subset()
--FILE--
<?php

function to_uint_32($tagName)
{
    $unpack = unpack('NN', $tagName);
    return $unpack['N'];
}

function open_face_by($filename)
{
    $blob = hb_blob_create_from_file($filename);
    $len = hb_blob_get_length($blob);
    if ($len <= 0) {
        die("{$filename} open failed.");
    }

    $face = hb_face_create($blob, 0);
    hb_blob_destroy($blob);
    return $face;
}

function verify_subset_result($out_filename, $source_face, $subset_face)
{
    $file_subset_face = open_face_by($out_filename);
    $mem_subset_face = $subset_face;
    $source_graphics = hb_face_get_glyph_count($source_face);
    //Because these is `source_face` subset.
    var_dump(hb_face_get_glyph_count($file_subset_face) < $source_graphics &&
        hb_face_get_glyph_count($mem_subset_face) < $source_graphics);
    hb_face_destroy($file_subset_face);
}

function subset_and_verify($face, $input_str, $out_filename)
{
    $input = hb_subset_input_create_or_fail();
    $drop_table_set = hb_subset_input_drop_tables_set($input);
    hb_set_del($drop_table_set, to_uint_32('GSUB'));
    hb_set_del($drop_table_set, to_uint_32('GPOS'));
    hb_set_del($drop_table_set, to_uint_32('GDEF'));
    hb_set_destroy($drop_table_set);

    $input_unicode_set = hb_subset_input_unicode_set($input);
    help_add_subset_input_unicode_set($input_unicode_set, $input_str);
    hb_set_destroy($input_unicode_set);

    $subset_face = hb_subset($face, $input);
    $subset_blob = hb_face_reference_blob($subset_face);

    $out_fd = fopen($out_filename, 'w');
    $writes = hb_blob_write_data($out_fd, $subset_blob);
    if ($writes <= 0) {
        die("subset[{$input_str}] failed.");
    }

    verify_subset_result($out_filename, $face, $subset_face);

    fclose($out_fd);
    hb_subset_input_destroy($input);
    hb_face_destroy($subset_face);
    hb_blob_destroy($subset_blob);
}

@mkdir('./tests/tmp_out/');

subset_and_verify(open_face_by('./tests/fonts/test_001.otf'), '【春a1】', './tests/tmp_out/hb_subset_001.otf');
@unlink('./tests/tmp_out/hb_subset_001.otf');

subset_and_verify(open_face_by('./tests/fonts/test_002.ttf'), '【春a1】', './tests/tmp_out/hb_subset_002.ttf');
@unlink('./tests/tmp_out/hb_subset_002.ttf');

@rmdir('./tests/tmp_out/');
?>
--EXPECT--
bool(true)
bool(true)
