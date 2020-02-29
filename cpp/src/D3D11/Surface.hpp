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

	private:
		friend class Manager;

		Surface();

		~Surface();

		static gmstring_t mObjectType;

		ID3D11Texture2D* mTexture = NULL;

		gmreal_t mWidth = 0.0;

		gmreal_t mHeight = 0.0;
	};
}