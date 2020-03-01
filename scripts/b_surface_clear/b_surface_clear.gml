/// @func b_surface_clear(surface, color, alpha)
/// @param {real} surface
/// @param {real} color
/// @param {real} alpha
gml_pragma("forceinline");
external_call(global.__bSurfaceClear, argument0, argument1, argument2);