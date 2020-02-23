/// @desc b_object_get_type(id)
/// @param {real} id
/// @return {string}
gml_pragma("forceinline");
return external_call(global.__bObjectGetType, argument0);