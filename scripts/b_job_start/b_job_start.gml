/// @func b_job_start(_id)
/// @param {real} _id
function b_job_start(_id)
{
	gml_pragma("forceinline");
	external_call(global.__b_job_start, _id);
}