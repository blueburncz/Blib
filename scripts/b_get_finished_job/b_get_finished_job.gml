/// @func b_get_finished_job()
/// @return {real}
function b_get_finished_job() {
	gml_pragma("forceinline");
	return external_call(global.__bGetFinishedJob);


}
