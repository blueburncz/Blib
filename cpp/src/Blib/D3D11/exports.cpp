#include <Blib/common.hpp>
#include <Blib/Manager.hpp>
#include <Blib/D3D11/DepthStencil.hpp>
#include <Blib/D3D11/Surface.hpp>
#include <stack>

using namespace D3D11;

ID3D11Device* gDevice;

ID3D11DeviceContext* gContext;

/** Current number of render targets. */
UINT gRenderTargetCount = 1;

/** Pop value from here to know how many render targets to pop from the stack. */
std::stack<UINT> gRenderTargetCountStack;

std::stack<ID3D11RenderTargetView*> gRenderTargetStack;

std::stack<ID3D11DepthStencilView*> gDepthStencilStack;

std::stack<D3D11_VIEWPORT> gViewportStack;

GM_EXPORT gmreal_t blib_d3d11_init(gmptr_t device, gmptr_t context)
{
	gDevice = reinterpret_cast<ID3D11Device*>(device);
	gContext = reinterpret_cast<ID3D11DeviceContext*>(context);
	LOG("D3D11 initialized");
	return GM_TRUE;
}

////////////////////////////////////////////////////////////////////////////////
//
// DepthStencil
//

GM_EXPORT gmreal_t blib_depthstencil_clear(gmreal_t id, gmreal_t depth, gmreal_t stencil)
{
	DepthStencil* depthStencil = BGetObject<DepthStencil>(id);
	ID3D11DepthStencilView* dsv = depthStencil->GetDepthStencilView(gDevice);

	gContext->ClearDepthStencilView(dsv, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
		static_cast<FLOAT>(depth), static_cast<UINT8>(stencil));
	return GM_TRUE;
}

GM_EXPORT gmreal_t blib_depthstencil_create(gmreal_t width, gmreal_t height, gmreal_t format)
{
	DepthStencil* depthStencil = BCreateObject<DepthStencil>();
	if (!depthStencil->Initialize(gDevice, width, height, format))
	{
		BDestroy(depthStencil);
		return ID_NONE;
	}
	return depthStencil->GetId();
}

////////////////////////////////////////////////////////////////////////////////
//
// Render target
//

GM_EXPORT gmreal_t blib_reset_render_targets()
{
	ID3D11RenderTargetView* rtvs[8];

	gRenderTargetCount = gRenderTargetCountStack.top();
	gRenderTargetCountStack.pop();

	for (UINT i = 0; i < gRenderTargetCount; ++i)
	{
		rtvs[gRenderTargetCount - i - 1] = gRenderTargetStack.top();
		gRenderTargetStack.pop();
	}

	ID3D11DepthStencilView* dsv = gDepthStencilStack.top();
	gDepthStencilStack.pop();

	gContext->OMSetRenderTargets(gRenderTargetCount, rtvs, dsv);

	D3D11_VIEWPORT viewport = gViewportStack.top();
	gViewportStack.pop();
	gContext->RSSetViewports(1, &viewport);
	
	return GM_TRUE;
}

GM_EXPORT gmreal_t blib_set_render_targets(gmreal_t count, gmptr_t targets, gmreal_t depthStencil)
{
	ID3D11RenderTargetView* rtvs[8];
	ID3D11DepthStencilView* dsv;

	// Push current targets to the stack
	gRenderTargetCountStack.push(gRenderTargetCount);
	gContext->OMGetRenderTargets(gRenderTargetCount, rtvs, &dsv);
	for (UINT i = 0; i < gRenderTargetCount; ++i)
	{
		gRenderTargetStack.push(rtvs[i]);
	}
	gDepthStencilStack.push(dsv);

	// TODO: Take into account number of previous viewports
	D3D11_VIEWPORT viewportPrev;
	UINT viewportCount = 1;

	gContext->RSGetViewports(&viewportCount, &viewportPrev);
	gViewportStack.push(viewportPrev);

	// Set new targets
	gRenderTargetCount = static_cast<UINT>(count);
	gmreal_t* targetIds = reinterpret_cast<gmreal_t*>(targets);

	D3D11_VIEWPORT viewport;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	for (UINT i = 0; i < gRenderTargetCount; ++i)
	{
		Surface* surface = BGetObject<Surface>(targetIds[i]);
		rtvs[i] = surface->GetRenderTargetView(gDevice);
		viewport.Width = static_cast<FLOAT>(surface->GetWidth());
		viewport.Height = static_cast<FLOAT>(surface->GetHeight());
	}

	dsv = (depthStencil != ID_NONE)
		? BGetObject<DepthStencil>(depthStencil)->GetDepthStencilView(gDevice)
		: NULL;

	gContext->OMSetRenderTargets(gRenderTargetCount, rtvs, dsv);
	gContext->RSSetViewports(1, &viewport);

	return GM_TRUE;
}

////////////////////////////////////////////////////////////////////////////////
//
// Surface
//

GM_EXPORT gmreal_t blib_surface_clear(gmreal_t id, gmreal_t color, gmreal_t alpha)
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

GM_EXPORT gmreal_t blib_surface_create(gmreal_t width, gmreal_t height, gmreal_t format)
{
	Surface* surface = BCreateObject<Surface>();
	if (!surface->Initialize(gDevice, width, height, format))
	{
		BDestroy(surface);
		return ID_NONE;
	}
	return surface->GetId();
}

GM_EXPORT gmreal_t blib_surface_set_texture(gmreal_t id, gmreal_t slot)
{
	Surface* surface = BGetObject<Surface>(id);
	ID3D11ShaderResourceView* srv = surface->GetShaderResourceView(gDevice);
	gContext->PSSetShaderResources(static_cast<UINT>(slot), 1, &srv);
	return GM_TRUE;
}

////////////////////////////////////////////////////////////////////////////////
//
// Texture
//

GM_EXPORT gmreal_t blib_texture_copy(gmreal_t src, gmreal_t dest)
{
	BGetObject<ITexture>(src)->Copy(gContext, BGetObject<ITexture>(dest));
	return GM_TRUE;
}

GM_EXPORT gmreal_t blib_texture_get_width(gmreal_t id)
{
	return BGetObject<ITexture>(id)->GetWidth();
}

GM_EXPORT gmreal_t blib_texture_get_height(gmreal_t id)
{
	return BGetObject<ITexture>(id)->GetHeight();
}
