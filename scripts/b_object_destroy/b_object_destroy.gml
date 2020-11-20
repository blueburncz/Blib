/// @desc b_object_destroy(_id)
/// @param {real} _id
/// @return {real}
function b_object_destroy(_id)
{
	gml_pragma("forceinline");
	return external_call(global.__b_object_destroy, _id);
}