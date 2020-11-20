/// @func b_texture_copy(_src, _dest)
/// @param {real} _src
/// @param {real} _dest
function b_texture_copy(_src, _dest)
{
	gml_pragma("forceinline");
	external_call(global.__b_texture_copy, _src, _dest);
}