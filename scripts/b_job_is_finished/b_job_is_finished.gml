/// @func b_job_is_finished(id)
/// @param {real} id
gml_pragma("forceinline");
return external_call(global.__bJobIsFinished, argument0);