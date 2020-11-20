/// @desc b_object_exists(_id)
/// @param {real} _id
/// @return {bool}
function b_object_exists(_id)
{
	gml_pragma("forceinline");
	return external_call(global.__b_object_exists, _id);
}