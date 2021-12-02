#include <Blib/D3D11/DepthStencil.hpp>

using namespace D3D11;

gmstring_t DepthStencil::ObjectType = "DepthStencil";

DepthStencil::DepthStencil()
{
}

DepthStencil::~DepthStencil()
{
	if (DepthStencilView != NULL)
	{
		DepthStencilView->Release();
	}
}

bool DepthStencil::Initialize(ID3D11Device* device, gmreal_t width, gmreal_t height, gmreal_t format)
{
	D3D11_TEXTURE2D_DESC desc;

	ZeroMemory(&desc, sizeof(desc));
	desc.Width = static_cast<UINT>(width);
	desc.Height = static_cast<UINT>(height);
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = static_cast<DXGI_FORMAT>(static_cast<UINT>(format));
	desc.SampleDesc.Count = 1;
	desc.SampleDesc.Quality = 0;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	desc.CPUAccessFlags = 0;
	desc.MiscFlags = 0;

	HRESULT res = device->CreateTexture2D(&desc, NULL, &Texture);

	if (FAILED(res))
	{
		return false;
	}

	Width = width;
	Height = height;

	return true;
}

ID3D11DepthStencilView* DepthStencil::GetDepthStencilView(ID3D11Device* device)
{
	if (DepthStencilView == NULL)
	{
		device->CreateDepthStencilView(Texture, NULL, &DepthStencilView);
	}
	return DepthStencilView;
}
