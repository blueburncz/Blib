#pragma once

#include "../common.hpp"
#include "../Manager.hpp"
#include "../Object.hpp"
#include <d3d11.h>

namespace D3D11
{
	class Surface final : public Object
	{
	public:
		bool Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format);

		ID3D11RenderTargetView* GetRenderTargetView(ID3D11Device* device);

		ID3D11ShaderResourceView* GetShaderResourceView(ID3D11Device* device);

		ID3D11Texture2D* GetTexture() const
		{
			return mTexture;
		}

		gmreal_t GetWidth() const
		{
			return mWidth;
		}

		gmreal_t GetHeight() const
		{
			return mHeight;
		}

	private:
		friend class Manager;

		Surface();

		~Surface();

		static gmstring_t mObjectType;

		ID3D11Texture2D* mTexture = NULL;

		ID3D11RenderTargetView* mRenderTargetView = NULL;

		ID3D11ShaderResourceView* mShaderResourceView = NULL;

		gmreal_t mWidth = 0.0;

		gmreal_t mHeight = 0.0;
	};
}