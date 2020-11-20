/// @func b_texture_get_width(_texture)
/// @param {real} _texture
/// @return {real}
function b_texture_get_width(_texture)
{
	gml_pragma("forceinline");
	return external_call(global.__b_texture_get_width, _texture);
}