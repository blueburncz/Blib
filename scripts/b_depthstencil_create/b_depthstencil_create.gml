/// @func b_depthstencil_create(width, height, format)
/// @param {real} width
/// @param {real} height
/// @param {real} format
/// @return {real}
gml_pragma("forceinline");
return external_call(global.__bDepthStencilCreate, argument0, argument1, argument2);