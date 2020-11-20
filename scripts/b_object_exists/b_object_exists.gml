/// @desc b_object_exists(id)
/// @param {real} id
/// @return {bool}
function b_object_exists(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bObjectExists, argument0);


}
