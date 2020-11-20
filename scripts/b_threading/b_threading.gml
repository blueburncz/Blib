global.__b_job_start = external_define(BLIB_DLL, "b_job_start", dll_cdecl, ty_real, 1, ty_real);
global.__b_job_is_finished  = external_define(BLIB_DLL, "b_job_is_finished", dll_cdecl, ty_real, 1, ty_real);
global.__b_get_finished_job = external_define(BLIB_DLL, "b_get_finished_job", dll_cdecl, ty_real, 0);
global.__b_sleep_job_create = external_define(BLIB_DLL, "b_sleep_job_create", dll_cdecl, ty_real, 1, ty_real);