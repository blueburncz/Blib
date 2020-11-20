/// @func b_depthstencil_clear(depthStencil, depth, stencil)
/// @param {real} depthStencil
/// @param {real} depth
/// @param {real} stencil
function b_depthstencil_clear(argument0, argument1, argument2) {
	gml_pragma("forceinline");
	external_call(global.__bDepthStencilClear, argument0, argument1, argument2);


}
