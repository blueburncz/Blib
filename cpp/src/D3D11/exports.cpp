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

GM_EXPORT gmreal_t b_surface_set_target(gmreal_t id)
{
	ID3D11RenderTargetView* rtv;

	// Push current targets to the stack
	ID3D11DepthStencilView* dsv;
	gContext->OMGetRenderTargets(1, &rtv, &dsv);
	gRenderTargetStack.push(rtv);
	gDepthStencilStack.push(dsv);

	// Set new target
	Surface* surface = BGetObject<Surface>(id);
	rtv = surface->GetRenderTargetView(gDevice);
	gContext->OMSetRenderTargets(1, &rtv, NULL);
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_surface_reset_target()
{
	ID3D11RenderTargetView* rtv = gRenderTargetStack.top();
	gRenderTargetStack.pop();
	ID3D11DepthStencilView* dsv = gDepthStencilStack.top();
	gDepthStencilStack.pop();
	gContext->OMSetRenderTargets(1, &rtv, dsv);
	return GM_TRUE;
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

GM_EXPORT gmreal_t b_surface_set_texture(gmreal_t id)
{
	Surface* surface = BGetObject<Surface>(id);
	ID3D11ShaderResourceView* srv = surface->GetShaderResourceView(gDevice);
	gContext->PSSetShaderResources(1, 1, &srv);
	return GM_TRUE;
}