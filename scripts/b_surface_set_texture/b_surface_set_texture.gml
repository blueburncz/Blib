/// @func b_surface_set_texture(surface, slot)
/// @param {real} surface
/// @param {real} slot
function b_surface_set_texture(argument0, argument1) {
	gml_pragma("forceinline");
	external_call(global.__bSurfaceSetTexture, argument0, argument1);


}
