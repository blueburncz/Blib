application_surface_enable(true);


vertex_format_begin();
vertex_format_add_position_3d();
vertex_format_add_texcoord();
vFormat = vertex_format_end();

vBuffer = vertex_create_buffer();
vertex_begin(vBuffer, vFormat);
vertex_position_3d(vBuffer, 0, 0, 0); vertex_texcoord(vBuffer, 0, 0);
vertex_position_3d(vBuffer, 1, 0, 0); vertex_texcoord(vBuffer, 1, 0);
vertex_position_3d(vBuffer, 1, 1, 0); vertex_texcoord(vBuffer, 1, 1);
vertex_position_3d(vBuffer, 0, 0, 0); vertex_texcoord(vBuffer, 0, 0);
vertex_position_3d(vBuffer, 1, 1, 0); vertex_texcoord(vBuffer, 1, 1);
vertex_position_3d(vBuffer, 0, 1, 0); vertex_texcoord(vBuffer, 0, 1);
vertex_end(vBuffer);
vertex_freeze(vBuffer);

surfaceWidth = 256;
surfaceHeight = 256;
surface = b_surface_create(surfaceWidth, surfaceHeight, B_EDXGIFormat.R16G16B16A16_FLOAT);
show_debug_message("Surface: " + string(surface));
if (surface != B_ID_NONE)
{
	show_debug_message("Type: " + string(b_object_get_type(surface)));
}