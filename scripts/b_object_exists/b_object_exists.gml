/// @desc b_object_exists(id)
/// @param {real} id
/// @return {bool}
gml_pragma("forceinline");
return external_call(global.__bObjectExists, argument0);