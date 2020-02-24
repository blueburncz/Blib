/// @func b_init_global()
gml_pragma("global", "b_init_global();");
global.__bObjectExists  = external_define("Blib.dll", "b_object_exists", dll_cdecl, ty_real, 1, ty_real);
global.__bObjectGetType = external_define("Blib.dll", "b_object_get_type", dll_cdecl, ty_string, 1, ty_real);
global.__bObjectDestroy = external_define("Blib.dll", "b_object_destroy", dll_cdecl, ty_real, 1, ty_real);