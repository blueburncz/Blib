/// @desc b_object_get_type(id)
/// @param {real} id
/// @return {string}
function b_object_get_type(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bObjectGetType, argument0);


}
