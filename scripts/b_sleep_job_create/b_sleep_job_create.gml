/// @func b_sleep_job_create(duration)
/// @param {real} duration
/// @return {real}
function b_sleep_job_create(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bSleepJobCreate, argument0);


}
