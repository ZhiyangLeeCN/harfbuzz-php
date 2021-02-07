--TEST--
Test operate for hb_set_t struct.
--FILE--
<?php

$set = hb_set_create();
hb_set_add($set, 1);
var_dump(hb_set_has($set, 1));

hb_set_del($set, 1);
var_dump(hb_set_is_empty($set));

$ref_set = hb_set_reference($set);
hb_set_destroy($ref_set);
hb_set_destroy($ref_set);

?>
--EXPECT--
bool(true)
bool(true)