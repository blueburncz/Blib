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
		friend class Manager;

		Surface();

		~Surface();

		static gmstring_t mObjectType;

		ID3D11RenderTargetView* mRenderTargetView = NULL;

		ID3D11ShaderResourceView* mShaderResourceView = NULL;
	};
}