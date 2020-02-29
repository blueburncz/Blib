#pragma once

#include "Surface.hpp"

using namespace D3D11;

gmstring_t Surface::mObjectType = "Surface";

Surface::Surface()
{
}

Surface::~Surface()
{
}

bool Surface::Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format)
{
	D3D11_TEXTURE2D_DESC desc;

	ZeroMemory(&desc, sizeof(desc));
	desc.Width = (UINT)width;
	desc.Height = (UINT)height;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = (DXGI_FORMAT)(UINT)format;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	HRESULT res = device->CreateTexture2D(&desc, NULL, &mTexture);

	if (FAILED(res))
	{
		return false;
	}

	mWidth = width;
	mHeight = height;

	return true;
}