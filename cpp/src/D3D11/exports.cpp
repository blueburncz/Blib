#include "../common.hpp"
#include "Surface.hpp"
#include <d3d11.h>
#include <iostream>
#include <stack>

using namespace D3D11;

ID3D11Device* gDevice;

ID3D11DeviceContext* gContext;

std::stack<ID3D11RenderTargetView*> gRenderTargetStack;

std::stack<ID3D11DepthStencilView*> gDepthStencilStack;

std::stack<D3D11_VIEWPORT*> gViewportStack;

GM_EXPORT gmreal_t b_d3d11_init(gmptr_t device, gmptr_t context)
{
	gDevice = reinterpret_cast<ID3D11Device*>(device);
	gContext = reinterpret_cast<ID3D11DeviceContext*>(context);
#ifdef _DEBUG
	std::cout << "Blib: D3D11 initialized" << std::endl;
#endif // _DEBUG
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_surface_create(gmreal_t width, gmreal_t height, gmreal_t format)
{
	Surface* surface = BCreateObject<Surface>();
	if (!surface->Initialize(gDevice, width, height, format))
	{
		BDestroy(surface);
		return ID_NONE;
	}
	return surface->GetId();
}

GM_EXPORT gmreal_t b_surface_get_width(gmreal_t id)
{
	return BGetObject<Surface>(id)->GetWidth();
}

GM_EXPORT gmreal_t b_surface_get_height(gmreal_t id)
{
	return BGetObject<Surface>(id)->GetHeight();
}

GM_EXPORT gmreal_t b_surface_clear(gmreal_t id, gmreal_t color, gmreal_t alpha)
{
	Surface* surface = BGetObject<Surface>(id);
	ID3D11RenderTargetView* rtv = surface->GetRenderTargetView(gDevice);

	UINT32 colorInt = static_cast<UINT32>(color);
	FLOAT r = static_cast<FLOAT>(colorInt & 0xFF) / 255.0f;
	FLOAT g = static_cast<FLOAT>((colorInt >> 8) & 0xFF) / 255.0f;
	FLOAT b = static_cast<FLOAT>((colorInt >> 16) & 0xFF) / 255.0f;

	FLOAT rgba[] = { r, g, b, static_cast<FLOAT>(alpha) };
	gContext->ClearRenderTargetView(rtv, rgba);
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_surface_set_texture(gmreal_t id, gmreal_t slot)
{
	Surface* surface = BGetObject<Surface>(id);
	ID3D11ShaderResourceView* srv = surface->GetShaderResourceView(gDevice);
	gContext->PSSetShaderResources(static_cast<UINT>(slot), 1, &srv);
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_set_render_targets(gmreal_t count, gmptr_t targets, gmreal_t depthstencil)
{
	// Push current targets to the stack
	ID3D11RenderTargetView* rtv;
	ID3D11DepthStencilView* dsv;

	// TODO: Take into account number of previous render targets
	gContext->OMGetRenderTargets(1, &rtv, &dsv);
	gRenderTargetStack.push(rtv);
	gDepthStencilStack.push(dsv);

	// Set new targets
	UINT countInt = static_cast<UINT>(count);
	gmreal_t* targetIds = reinterpret_cast<gmreal_t*>(targets);
	ID3D11RenderTargetView* rtvs[8];

	D3D11_VIEWPORT viewport;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	for (UINT i = 0; i < countInt; ++i)
	{
		Surface* surface = BGetObject<Surface>(targetIds[i]);
		rtvs[i] = surface->GetRenderTargetView(gDevice);
		viewport.Width = static_cast<FLOAT>(surface->GetWidth());
		viewport.Height = static_cast<FLOAT>(surface->GetHeight());
	}

	// TODO: Create DepthStencil object
	gContext->OMSetRenderTargets(countInt, rtvs, NULL);
	gContext->RSSetViewports(1, &viewport);

	return GM_TRUE;
}

GM_EXPORT gmreal_t b_reset_render_targets()
{
	ID3D11RenderTargetView* rtv = gRenderTargetStack.top();
	gRenderTargetStack.pop();
	ID3D11DepthStencilView* dsv = gDepthStencilStack.top();
	gDepthStencilStack.pop();
	gContext->OMSetRenderTargets(1, &rtv, dsv);
	return GM_TRUE;
}