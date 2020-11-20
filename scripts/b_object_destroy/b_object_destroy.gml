/// @desc b_object_destroy(id)
/// @param {real} id
/// @return {real}
function b_object_destroy(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bObjectDestroy, argument0);


}
