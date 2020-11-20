/// @func b_threading_init_global()
function b_threading_init_global() {
	gml_pragma("global", "b_threading_init_global();");
	global.__bJobStart = external_define(BLIB_DLL, "b_job_start", dll_cdecl, ty_real, 1, ty_real);
	global.__bJobIsFinished  = external_define(BLIB_DLL, "b_job_is_finished", dll_cdecl, ty_real, 1, ty_real);
	global.__bGetFinishedJob = external_define(BLIB_DLL, "b_get_finished_job", dll_cdecl, ty_real, 0);
	global.__bSleepJobCreate = external_define(BLIB_DLL, "b_sleep_job_create", dll_cdecl, ty_real, 1, ty_real);


}
