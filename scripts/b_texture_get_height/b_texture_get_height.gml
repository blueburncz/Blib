/// @func b_texture_get_height(surface)
/// @param {real} surface
/// @return {real}
function b_texture_get_height(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bTextureGetHeight, argument0);


}
