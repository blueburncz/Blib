/// @func b_depthstencil_clear(depthStencil, depth, stencil)
/// @param {real} depthStencil
/// @param {real} depth
/// @param {real} stencil
gml_pragma("forceinline");
external_call(global.__bDepthStencilClear, argument0, argument1, argument2);