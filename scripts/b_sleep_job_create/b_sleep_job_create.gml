/// @func b_sleep_job_create(_duration)
/// @param {real} _duration
/// @return {real}
function b_sleep_job_create(_duration)
{
	gml_pragma("forceinline");
	return external_call(global.__b_sleep_job_create, _duration);
}