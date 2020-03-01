/// @func b_set_render_targets(depthstencil, surface1, ...)
/// @param {real} depthstencil
/// @param {real} surface1..8
var _buffer = global.__bRenderTargetsBuffer;
buffer_seek(_buffer, buffer_seek_start, 0);
for (var i = 1; i < argument_count; ++i)
{
	buffer_write(_buffer, buffer_f64, argument[i]);
}
external_call(global.__bSetRenderTargets, argument_count - 1, buffer_get_address(_buffer), argument[0]);