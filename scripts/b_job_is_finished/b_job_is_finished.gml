/// @func b_job_is_finished(id)
/// @param {real} id
/// @return {bool}
function b_job_is_finished(argument0) {
	gml_pragma("forceinline");
	return external_call(global.__bJobIsFinished, argument0);


}
