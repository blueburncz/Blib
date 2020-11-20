/// @func b_texture_get_width(surface)
/// @param {real} surface
/// @return {real}
function b_texture_get_width(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bTextureGetWidth, argument0);


}
