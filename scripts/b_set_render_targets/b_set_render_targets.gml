/// @func b_set_render_targets(count, surface1, ..., depthstencil)
/// @param {real} _count
/// @param {real} _surface1..8
/// @param {real} _depthstencil
function b_set_render_targets(_count)
{
	var _buffer = global.__b_render_targets_buffer;
	buffer_seek(_buffer, buffer_seek_start, 0);
	for (var i = 0; i < _count; ++i)
	{
		buffer_write(_buffer, buffer_f64, argument[1 + i]);
	}
	external_call(global.__b_set_render_targets, _count, buffer_get_address(_buffer), argument[argument_count - 1]);
}