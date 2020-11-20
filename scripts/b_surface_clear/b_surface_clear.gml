/// @func b_surface_clear(surface, color, alpha)
/// @param {real} surface
/// @param {real} color
/// @param {real} alpha
function b_surface_clear(argument0, argument1, argument2) {
	gml_pragma("forceinline");
	external_call(global.__bSurfaceClear, argument0, argument1, argument2);


}
