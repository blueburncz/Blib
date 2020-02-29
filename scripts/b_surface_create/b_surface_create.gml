/// @func b_surface_create(width, height, format)
/// @param {real} width
/// @param {real} height
/// @param {real} format
gml_pragma("forceinline");
return external_call(global.__bSurfaceCreate, argument0, argument1, argument2);