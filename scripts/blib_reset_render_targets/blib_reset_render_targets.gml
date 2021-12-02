/// @func blib_reset_render_targets()
function blib_reset_render_targets()
{
	static _fn = external_define(BLIB_DLL, "blib_set_render_targets", dll_cdecl, ty_real, 3, ty_real, ty_string, ty_real);
	external_call(_fn);
}