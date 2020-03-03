/// @func b_set_render_targets(count, surface1, ..., depthstencil)
/// @param {real} count
/// @param {real} surface1..8
/// @param {real} depthstencil
var _buffer = global.__bRenderTargetsBuffer;
buffer_seek(_buffer, buffer_seek_start, 0);
for (var i = 0; i < argument[0]; ++i)
{
	buffer_write(_buffer, buffer_f64, argument[1 + i]);
}
external_call(global.__bSetRenderTargets, argument[0], buffer_get_address(_buffer), argument[argument_count - 1]);