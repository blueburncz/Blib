/// @func BLIB_CSleepJob(_duration)
/// @extends BLIB_CJob
/// @param {real} _duration
function BLIB_CSleepJob(_duration)
	: BLIB_CJob() constructor
{
	/// @var {real}
	/// @readonly
	Duration = _duration;

	Create(_duration);

	/// @func Create(_duration)
	/// @param {real} _duration
	static Create = function (_duration) {
		static _fn = external_define(BLIB_DLL, "blib_sleep_job_create", dll_cdecl, ty_real, 1, ty_real);
		Id = external_call(_fn, _duration);
		if (Id != BLIB_ID_NONE)
		{
			Register();
		}
	};
}