/// @func b_texture_copy(src, dest)
/// @param {real} src
/// @param {real} dest
function b_texture_copy(argument0, argument1) {
	gml_pragma("forceinline");
	external_call(global.__bTextureCopy, argument0, argument1);


}
