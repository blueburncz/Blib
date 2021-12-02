/// @func BLIB_CDepthStencil(_width, _height, _format)
/// @extends BLIB_CTexture
/// @param {uint} _width
/// @param {uint} _height
/// @param {BLIB_ETextureFormat} _format
function BLIB_CDepthStencil(_width, _height, _format)
	: BLIB_CTexture() constructor
{
	/// @var {BLIB_ETextureFormat}
	/// @readonly
	Format = _format;

	Create(_width, _height, _format);

	/// @func Create(_width, _height, _format)
	/// @param {uint} _width
	/// @param {uint} _height
	/// @param {BLIB_ETextureFormat} _format
	/// @private
	static Create = function (_width, _height, _format) {
		static _fn = external_define(BLIB_DLL, "blib_depthstencil_create", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
		Id = external_call(_fn, _width, _height, _format);
		if (Id != BLIB_ID_NONE)
		{
			Register();
		}
	};

	/// @func Clear(_depth, _stencil)
	/// @param {real} _depth
	/// @param {real} _stencil
	/// @return {BLIB_CDepthStencil} Returns `self`.
	static Clear = function (_depth, _stencil) {
		static _fn = external_define(BLIB_DLL, "blib_depthstencil_clear", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
		external_call(_fn, Id, _depth, _stencil);
		return self;
	};
}