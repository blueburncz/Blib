#include "common.hpp"
#include "Manager.hpp"
#include "Object.hpp"

GM_EXPORT gmreal_t b_object_exists(gmreal_t id)
{
	return Exists(id)
		? GM_TRUE
		: GM_FALSE;
}

GM_EXPORT gmstring_t b_object_get_type(gmreal_t id)
{
	return GetObject<Object>(id)->GetType();
}

GM_EXPORT gmreal_t b_object_destroy(gmreal_t id)
{
	Destroy(id);
	return GM_TRUE;
}