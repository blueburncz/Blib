#include <Blib/common.hpp>
#include <Blib/Manager.hpp>
#include <Blib/Object.hpp>

GM_EXPORT gmreal_t blib_object_exists(gmreal_t id)
{
	return BExists(id)
		? GM_TRUE
		: GM_FALSE;
}

GM_EXPORT gmstring_t blib_object_get_type(gmreal_t id)
{
	return BGetObject<CObject>(id)->GetType();
}

GM_EXPORT gmreal_t blib_object_destroy(gmreal_t id)
{
	BDestroy(id);
	return GM_TRUE;
}
