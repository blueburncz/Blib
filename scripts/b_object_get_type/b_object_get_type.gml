/// @desc b_object_get_type(_id)
/// @param {real} _id
/// @return {string}
function b_object_get_type(_id)
{
	gml_pragma("forceinline");
	return external_call(global.__b_object_get_type, _id);
}