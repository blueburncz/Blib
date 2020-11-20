/// @func b_surface_create(width, height, format)
/// @param {real} width
/// @param {real} height
/// @param {real} format
/// @return {real}
function b_surface_create(argument0, argument1, argument2) {
	gml_pragma("forceinline");
	return external_call(global.__bSurfaceCreate, argument0, argument1, argument2);


}
