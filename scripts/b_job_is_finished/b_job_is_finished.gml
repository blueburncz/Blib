/// @func b_job_is_finished(id)
/// @param {real} id
/// @return {bool}
gml_pragma("forceinline");
return external_call(global.__bJobIsFinished, argument0);