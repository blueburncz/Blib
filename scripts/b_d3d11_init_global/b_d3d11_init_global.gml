/// @func b_d3d11_init_global()
gml_pragma("global", "b_d3d11_init_global();");

var _bD3d11Init = external_define("Blib.dll", "b_d3d11_init", dll_cdecl, ty_real, 2, ty_string, ty_string);

global.__bDepthStencilClear = external_define("Blib.dll", "b_depthstencil_clear", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__bDepthStencilCreate = external_define("Blib.dll", "b_depthstencil_create", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);

global.__bSetRenderTargets = external_define("Blib.dll", "b_set_render_targets", dll_cdecl, ty_real, 3, ty_real, ty_string, ty_real);
global.__bResetRenderTargets = external_define("Blib.dll", "b_reset_render_targets", dll_cdecl, ty_real, 0);

global.__bSurfaceClear = external_define("Blib.dll", "b_surface_clear", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__bSurfaceCreate = external_define("Blib.dll", "b_surface_create", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__bSurfaceSetTexture = external_define("Blib.dll", "b_surface_set_texture", dll_cdecl, ty_real, 2, ty_real, ty_real);

global.__bTextureGetHeight = external_define("Blib.dll", "b_texture_get_height", dll_cdecl, ty_real, 1, ty_real);
global.__bTextureGetWidth = external_define("Blib.dll", "b_texture_get_width", dll_cdecl, ty_real, 1, ty_real);

var _osInfo = os_get_info();
var _device = _osInfo[? "video_d3d11_device"];
var _context = _osInfo[? "video_d3d11_context"];
external_call(_bD3d11Init, _device, _context);

global.__bRenderTargetsBuffer = buffer_create(8 * buffer_sizeof(buffer_f64), buffer_fixed, 1);