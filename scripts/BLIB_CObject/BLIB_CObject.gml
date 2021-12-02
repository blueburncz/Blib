/// @macro {real} A value returned from object-creating functions, when
/// an object is not created.
#macro BLIB_ID_NONE -1

/// @var {ds_map<real, BLIB_CObject>}
/// @private
global.__blibObjectRegistry = ds_map_create();

/// @func BLIB_CObject()
function BLIB_CObject() constructor
{
	/// @var {real}
	/// @readonly
	Id = BLIB_ID_NONE;

	/// @func Register()
	/// @return {BLIB_CObject} Returns `self`.
	/// @private
	static Register = function () {
		gml_pragma("forceinline");
		global.__blibObjectRegistry[? Id] = self;
		return self;
	};

	/// @func Unregister()
	/// @return {BLIB_CObject} Returns `self`.
	/// @private
	static Unregister = function () {
		gml_pragma("forceinline");
		ds_map_delete(global.__blibObjectRegistry, Id);
		return self;
	};

	/// @func Exists(_id)
	/// @return {bool}
	static Exists = function () {
		static _fn = external_define(BLIB_DLL, "blib_object_exists", dll_cdecl, ty_real, 1, ty_real);
		return external_call(_fn, Id);
	};

	/// @func GetType()
	/// @return {string}
	static GetType = function () {
		static _fn = external_define(BLIB_DLL, "blib_object_get_type", dll_cdecl, ty_string, 1, ty_real);
		return external_call(_fn, Id);
	};

	/// @func Destroy()
	static Destroy = function () {
		static _fn = external_define(BLIB_DLL, "blib_object_destroy", dll_cdecl, ty_real, 1, ty_real);
		if (Id == BLIB_ID_NONE)
		{
			return true;
		}
		external_call(_fn, Id);
		Unregister();
	};
}

/// @func blib_get_object(_id)
/// @param {real} _id
/// @return {BLIB_CObject/undefined}
function blib_get_object(_id)
{
	gml_pragma("forceinline");
	return global.__blibObjectRegistry[? _id];
}