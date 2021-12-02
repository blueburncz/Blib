#pragma once

#include "Texture.hpp"

namespace D3D11
{
	class DepthStencil final : public ITexture
	{
	public:
		bool Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format);

		ID3D11DepthStencilView* GetDepthStencilView(ID3D11Device* device);

	private:
		friend class CManager;

		DepthStencil();

		~DepthStencil();

		static gmstring_t ObjectType;

		ID3D11DepthStencilView* DepthStencilView = NULL;
	};
}
