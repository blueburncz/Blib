/// @func BLIB_CSurface(_width, _height, _format)
/// @extends BLIB_CTexture
/// @param {uint} _width
/// @param {uint} _height
/// @param {BLIB_ETextureFormat} _format
function BLIB_CSurface(_width, _height, _format)
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
		static _fn = external_define(BLIB_DLL, "blib_surface_create", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
		Id = external_call(_fn, _width, _height, _format);
		if (Id != BLIB_ID_NONE)
		{
			Register();
		}
	};

	/// @func Clear(_color, _alpha)
	/// @param {uint} _color
	/// @param {real} _alpha
	/// @return {BLIB_CSurface} Returns `self`.
	static Clear = function (_color, _alpha) {
		static _fn = external_define(BLIB_DLL, "blib_surface_clear", dll_cdecl, ty_real, 3, ty_real, ty_real, ty_real);
		external_call(_fn, Id, _color, _alpha);
		return self;
	};

	/// @func SetTexture(_slot)
	/// @param {uint} _slot
	/// @return {BLIB_CSurface} Returns `self`.
	static SetTexture = function (_slot) {
		static _fn = external_define(BLIB_DLL, "blib_surface_set_texture", dll_cdecl, ty_real, 2, ty_real, ty_real);
		external_call(_fn, Id, _slot);
		return self;
	};

	/// @func Draw(_x, _y)
	/// @param {real} _x
	/// @param {real} _y
	/// @return {BLIB_CSurface} Returns `self`.
	static Draw = function (_x, _y) {
		shader_set(BLIB_ShSurface);
		SetTexture(1);
		draw_sprite_ext(BLIB_Spr1x1, 0, _x, _y,
			GetWidth(),
			GetHeight(),
			0, c_white, 1);
		shader_reset();
		return self;
	};
}