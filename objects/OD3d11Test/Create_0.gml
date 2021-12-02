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
surface = new BLIB_CSurface(surface_width, surface_height, BLIB_ETextureFormat.R16G16B16A16_FLOAT);
if (!surface.Exists())
{
	show_error("Failed to create Surface!", true);
}

depth_stencil = new BLIB_CDepthStencil(surface_width, surface_height, BLIB_ETextureFormat.D24_UNORM_S8_UINT);
if (!depth_stencil.Exists())
{
	show_error("Failed to create DepthStencil!", true);
}