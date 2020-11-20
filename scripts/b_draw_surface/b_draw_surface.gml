/// @func b_draw_surface(_surface, _x, _y)
/// @param {real} _surface
/// @param {real} _x
/// @param {real} _y
function b_draw_surface(_surface, _x, _y)
{
	shader_set(B_ShSurface);
	b_surface_set_texture(_surface, 1);
	draw_sprite_ext(B_Spr1x1, 0, _x, _y,
		b_texture_get_width(_surface),
		b_texture_get_height(_surface),
		0, c_white, 1);
	shader_reset();
}