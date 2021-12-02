/// @func BLIB_CTexture()
/// @extends BLIB_CObject
function BLIB_CTexture()
	: BLIB_CObject() constructor
{
	/// @func BLIB_CTexture(_dest)
	/// @param {BLIB_CTexture} _dest
	/// @return {BLIB_CTexture} Returns `self`.
	static Copy = function (_dest) {
		static _fn = external_define(BLIB_DLL, "blib_texture_copy", dll_cdecl, ty_real, 2, ty_real, ty_real);
		external_call(_fn, Id, _dest.Id);
		return self;
	};

	/// @func GetWidth()
	/// @return {real}
	static GetWidth = function () {
		static _fn = external_define(BLIB_DLL, "blib_texture_get_width", dll_cdecl, ty_real, 1, ty_real);
		return external_call(_fn, Id);
	};

	/// @func GetHeight()
	/// @return {real}
	static GetHeight = function () {
		static _fn = external_define(BLIB_DLL, "blib_texture_get_height", dll_cdecl, ty_real, 1, ty_real);
		return external_call(_fn, Id);
	};
}