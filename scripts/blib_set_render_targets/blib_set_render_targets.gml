/// @func blib_set_render_targets(_surface1, ..., depthStencil)
/// @param {real} _surface1..8
/// @param {real} _depthStencil
function blib_set_render_targets()
{
	static _fn = external_define(BLIB_DLL, "blib_set_render_targets", dll_cdecl, ty_real, 3, ty_real, ty_string, ty_real);
	static _buffer = buffer_create(8 * buffer_sizeof(buffer_f64), buffer_fixed, 1);
	buffer_seek(_buffer, buffer_seek_start, 0);
	for (var i = 0; i < argument_count - 1; ++i)
	{
		buffer_write(_buffer, buffer_f64, argument[i].Id);
	}
	external_call(_fn, argument_count - 1, buffer_get_address(_buffer), argument[argument_count - 1].Id);
}