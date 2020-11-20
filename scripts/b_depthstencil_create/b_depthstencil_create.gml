/// @func b_depthstencil_create(_width, _height, _format)
/// @param {real} _width
/// @param {real} _height
/// @param {B_ETextureFormat} _format
/// @return {real}
function b_depthstencil_create(_width, _height, _format)
{
	gml_pragma("forceinline");
	return external_call(global.__b_depth_stencil_create, _width, _height, _format);
}