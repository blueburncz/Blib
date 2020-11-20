/// @func b_draw_surface(surface, x, y)
/// @param {real} surface
/// @param {real} x
/// @param {real} y
function b_draw_surface(argument0, argument1, argument2) {
	shader_set(B_ShSurface);
	b_surface_set_texture(argument0, 1);
	draw_sprite_ext(B_Spr1x1, 0, argument1, argument2, b_texture_get_width(argument0),
		b_texture_get_height(argument0), 0, c_white, 1);
	shader_reset();


}
