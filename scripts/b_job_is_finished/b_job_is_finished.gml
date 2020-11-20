/// @func b_job_is_finished(_id)
/// @param {real} _id
/// @return {bool}
function b_job_is_finished(_id)
{
	gml_pragma("forceinline");
	return external_call(global.__b_job_is_finished, _id);
}