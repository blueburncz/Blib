/// @func BLIB_CJob()
/// @extends BLIB_CObject
function BLIB_CJob()
	: BLIB_CObject() constructor
{
	/// @func Start(_id)
	/// @return {BLIB_CJob} Returns `self`.
	static Start = function () {
		static _fn = external_define(BLIB_DLL, "blib_job_start", dll_cdecl, ty_real, 1, ty_real);
		external_call(_fn, Id);
		return self;
	};

	/// @func IsFinished()
	/// @return {bool}
	static IsFinished = function (_id) {
		static _fn = external_define(BLIB_DLL, "blib_job_is_finished", dll_cdecl, ty_real, 1, ty_real);
		return external_call(_fn, Id);
	};
}

/// @func blib_get_finished_job()
/// @return {BLIB_CJob/undefined}
function blib_get_finished_job()
{
	static _fn = external_define(BLIB_DLL, "blib_get_finished_job", dll_cdecl, ty_real, 0);
	return blib_get_object(external_call(_fn));
}