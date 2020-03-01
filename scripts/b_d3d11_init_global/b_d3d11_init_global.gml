/// @func b_d3d11_init_global()
gml_pragma("global", "b_d3d11_init_global();");

var _osInfo = os_get_info();
var _device = _osInfo[? "video_d3d11_device"];
var _context = _osInfo[? "video_d3d11_context"];

var _bD3d11Init = external_define("Blib.dll", "b_d3d11_init", dll_cdecl, ty_real, 2, ty_string, ty_string);
global.__bSurfaceCreate = external_define("Blib.dll", "b_surface_create", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
global.__bSurfaceGetHeight = external_define("Blib.dll", "b_surface_get_height", dll_cdecl, ty_real, 1, ty_real);
global.__bSurfaceGetWidth = external_define("Blib.dll", "b_surface_get_width", dll_cdecl, ty_real, 1, ty_real);
global.__bSurfaceSetTarget = external_define("Blib.dll", "b_surface_set_target", dll_cdecl, ty_real, 1, ty_real);
global.__bSurfaceResetTarget = external_define("Blib.dll", "b_surface_reset_target", dll_cdecl, ty_real, 0);
global.__bSurfaceSetTexture = external_define("Blib.dll", "b_surface_set_texture", dll_cdecl, ty_real, 1, ty_real);
global.__bSurfaceClear = external_define("Blib.dll", "b_surface_clear", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);

external_call(_bD3d11Init, _device, _context);