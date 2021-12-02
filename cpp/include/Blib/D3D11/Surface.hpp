#pragma once

#include "Texture.hpp"

namespace D3D11
{
	class Surface final : public ITexture
	{
	public:
		bool Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format);

		ID3D11RenderTargetView* GetRenderTargetView(ID3D11Device* device);

		ID3D11ShaderResourceView* GetShaderResourceView(ID3D11Device* device);

	private:
		friend class CManager;

		Surface();

		~Surface();

		static gmstring_t ObjectType;

		ID3D11RenderTargetView* RenderTargetView = NULL;

		ID3D11ShaderResourceView* ShaderResourceView = NULL;
	};
}
