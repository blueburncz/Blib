#pragma once

#include "../common.hpp"
#include "../Manager.hpp"
#include "../Object.hpp"
#include <d3d11.h>

namespace D3D11
{
	class ITexture : public Object
	{
	public:
		virtual bool Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format) = 0;

		inline ID3D11Texture2D* GetTexture() const
		{
			return mTexture;
		}

		inline gmreal_t GetWidth() const
		{
			return mWidth;
		}

		inline gmreal_t GetHeight() const
		{
			return mHeight;
		}

		inline void Copy(ID3D11DeviceContext* context, ITexture* dest)
		{
			context->CopyResource(dest->mTexture, mTexture);
		}

	protected:
		friend class Manager;

		ITexture() {}

		virtual ~ITexture() {}

		// This is an interface and it cannot be instantiated, so we won't need this.
		//static gmstring_t mObjectType;

		ID3D11Texture2D* mTexture = NULL;

		gmreal_t mWidth = 0.0;

		gmreal_t mHeight = 0.0;
	};
}