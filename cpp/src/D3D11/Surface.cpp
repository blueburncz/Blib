#include "Surface.hpp"
#include <iostream>

using namespace D3D11;

gmstring_t Surface::mObjectType = "Surface";

Surface::Surface()
{
}

Surface::~Surface()
{
	if (mRenderTargetView != NULL)
	{
		mRenderTargetView->Release();
	}

	if (mShaderResourceView != NULL)
	{
		mShaderResourceView->Release();
	}
}

bool Surface::Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format)
{
	D3D11_TEXTURE2D_DESC desc;

	ZeroMemory(&desc, sizeof(desc));
	desc.Width = static_cast<UINT>(width);
	desc.Height = static_cast<UINT>(height);
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = static_cast<DXGI_FORMAT>(static_cast<UINT>(format));
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

ID3D11RenderTargetView* Surface::GetRenderTargetView(ID3D11Device* device)
{
	if (mRenderTargetView == NULL)
	{
		HRESULT res = device->CreateRenderTargetView(mTexture, NULL, &mRenderTargetView);
		if (FAILED(res))
		{
#ifdef _DEBUG
			std::cout << "Blib: Render target view creation failed!" << std::endl;
#endif // _DEBUG
		}
	}
	return mRenderTargetView;
}

ID3D11ShaderResourceView* Surface::GetShaderResourceView(ID3D11Device* device)
{
	if (mShaderResourceView == NULL)
	{
		HRESULT res = device->CreateShaderResourceView(mTexture, NULL, &mShaderResourceView);
		if (FAILED(res))
		{
#ifdef _DEBUG
			std::cout << "Blib: Shader resource view creation failed!" << std::endl;
#endif // _DEBUG
		}
	}
	return mShaderResourceView;
}