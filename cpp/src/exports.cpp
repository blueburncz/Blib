#include "common.hpp"
#include "Manager.hpp"
#include "Object.hpp"

GM_EXPORT gmstring_t b_object_get_type(gmreal_t id)
{
	return GetObject<Object>(id)->GetType();
}