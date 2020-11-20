application_surface_enable(true);

vertex_format_begin();
vertex_format_add_position_3d();
vertex_format_add_texcoord();
vformat = vertex_format_end();

vbuffer = vertex_create_buffer();
vertex_begin(vbuffer, vformat);
vertex_position_3d(vbuffer, 0, 0, 0); vertex_texcoord(vbuffer, 0, 0);
vertex_position_3d(vbuffer, 1, 0, 0); vertex_texcoord(vbuffer, 1, 0);
vertex_position_3d(vbuffer, 1, 1, 0); vertex_texcoord(vbuffer, 1, 1);
vertex_position_3d(vbuffer, 0, 0, 0); vertex_texcoord(vbuffer, 0, 0);
vertex_position_3d(vbuffer, 1, 1, 0); vertex_texcoord(vbuffer, 1, 1);
vertex_position_3d(vbuffer, 0, 1, 0); vertex_texcoord(vbuffer, 0, 1);
vertex_end(vbuffer);
vertex_freeze(vbuffer);

surface_width = 256;
surface_height = 256;
surface = b_surface_create(surface_width, surface_height, B_ETextureFormat.R16G16B16A16_FLOAT);
if (surface == B_ID_NONE)
{
	show_error("Surface create failed!", true);
}

depth_stencil = b_depthstencil_create(surface_width, surface_height, B_ETextureFormat.D24_UNORM_S8_UINT);
if (depth_stencil == B_ID_NONE)
{
	show_error("DepthStencil create failed!", true);
}