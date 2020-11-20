/// @func b_job_start(id)
/// @param {real} id
function b_job_start(argument0) {
	gml_pragma("forceinline");
	external_call(global.__bJobStart, argument0);


}
