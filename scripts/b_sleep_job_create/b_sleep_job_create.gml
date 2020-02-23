/// @func b_sleep_job_create(duration)
/// @param {real} duration
/// @return {real}
gml_pragma("forceinline");
return external_call(global.__bSleepJobCreate, argument0);