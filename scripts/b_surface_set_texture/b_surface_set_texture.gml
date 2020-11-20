/// @func b_surface_set_texture(surface, slot)
/// @param {real} _surface
/// @param {real} _slot
function b_surface_set_texture(_surface, _slot)
{
	gml_pragma("forceinline");
	external_call(global.__b_surface_set_texture, _surface, _slot);
}