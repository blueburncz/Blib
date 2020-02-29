var _surface = b_surface_create(1024, 576, DXGI_FORMAT_R16G16B16A16_FLOAT);
show_debug_message("Surface: " + string(_surface));
if (_surface != -1)
{
	show_debug_message("Type: " + string(b_object_get_type(_surface)));
}