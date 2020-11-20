/// @func b_depthstencil_clear(_depth_stencil, depth, stencil)
/// @param {real} _depth_stencil
/// @param {real} _depth
/// @param {real} _stencil
function b_depthstencil_clear(_depth_stencil, _depth, _stencil)
{
	gml_pragma("forceinline");
	external_call(global.__b_depth_stencil_clear, _depth_stencil, _depth, _stencil);
}