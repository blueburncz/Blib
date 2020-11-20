/// @macro {string} Path to the Blib.dll file.
#macro BLIB_DLL "Blib/Blib.dll"

/// @macro {real} A value returned from object-creating functions, when
/// an object is not created.
#macro B_ID_NONE -1

global.__b_object_exists = external_define(BLIB_DLL, "b_object_exists", dll_cdecl, ty_real, 1, ty_real);
global.__b_object_get_type = external_define(BLIB_DLL, "b_object_get_type", dll_cdecl, ty_string, 1, ty_real);
global.__b_object_destroy = external_define(BLIB_DLL, "b_object_destroy", dll_cdecl, ty_real, 1, ty_real);