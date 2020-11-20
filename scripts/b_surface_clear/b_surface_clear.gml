/// @func b_surface_clear(_surface, _color, _alpha)
/// @param {real} _surface
/// @param {real} _color
/// @param {real} _alpha
function b_surface_clear(_surface, _color, _alpha)
{
	gml_pragma("forceinline");
	external_call(global.__b_surface_clear, _surface, _color, _alpha);
}