#include "../common.hpp"
#include "Surface.hpp"
#include <d3d11.h>
#include <iostream>

using namespace D3D11;

ID3D11Device* gDevice;

GM_EXPORT gmreal_t b_d3d11_init(gmptr_t device)
{
	gDevice = (ID3D11Device*)device;
	return GM_TRUE;
}

GM_EXPORT gmreal_t b_surface_create(gmreal_t width, gmreal_t height, gmreal_t format)
{
	Surface* surface = CreateObject<Surface>();
	if (!surface->Initialize(gDevice, width, height, format))
	{
		Destroy(surface);
		return -1.0;
	}
	return surface->GetId();
}