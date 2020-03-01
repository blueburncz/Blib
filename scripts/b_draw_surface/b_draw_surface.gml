/// @func b_draw_surface(surface, x, y)
/// @param {real} surface
/// @param {real} x
/// @param {real} y
shader_set(B_ShSurface);
b_surface_set_texture(argument0);
draw_sprite_ext(B_Spr1x1, 0, argument1, argument2, b_surface_get_width(argument0),
	b_surface_get_height(argument0), 0, c_white, 1);
shader_reset();