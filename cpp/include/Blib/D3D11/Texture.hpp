#pragma once

#include "../common.hpp"
#include "../Object.hpp"
#include <d3d11.h>

namespace D3D11
{
	class ITexture : public CObject
	{
	public:
		virtual bool Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format) = 0;

		inline ID3D11Texture2D* GetTexture() const
		{
			return Texture;
		}

		inline gmreal_t GetWidth() const
		{
			return Width;
		}

		inline gmreal_t GetHeight() const
		{
			return Height;
		}

		inline void Copy(ID3D11DeviceContext* context, ITexture* dest)
		{
			context->CopyResource(dest->Texture, Texture);
		}

	protected:
		friend class CManager;

		ITexture() {}

		virtual ~ITexture() {}

		// This is an interface and it cannot be instantiated, so we won't need this.
		//static gmstring_t mObjectType;

		ID3D11Texture2D* Texture = NULL;

		gmreal_t Width = 0.0;

		gmreal_t Height = 0.0;
	};
}
