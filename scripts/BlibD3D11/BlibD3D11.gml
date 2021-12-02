var _init = external_define(BLIB_DLL, "blib_d3d11_init", dll_cdecl, ty_real, 2, ty_string, ty_string);
var _osInfo = os_get_info();
var _device = _osInfo[? "video_d3d11_device"];
var _context = _osInfo[? "video_d3d11_context"];
external_call(_init, _device, _context);