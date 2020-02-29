/// @func b_d3d11_init_global()
gml_pragma("global", "b_d3d11_init_global();");

var _bD3d11Init = external_define("Blib.dll", "b_d3d11_init", dll_cdecl, ty_real, 1, ty_string);
global.__bSurfaceCreate = external_define("Blib.dll", "b_surface_create", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);

var _osInfo = os_get_info();
var _device = _osInfo[? "video_d3d11_device"];
external_call(_bD3d11Init, _device);