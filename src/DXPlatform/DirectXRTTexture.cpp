#include "DirectXRTTexture.h"
#include "DirectXRenderManager.h"

#include <d3dx9.h>

namespace GUI
{

	DirectXRTTexture::DirectXRTTexture(IDirect3DDevice9* device, IDirect3DTexture9* texture) :
		mpD3DDevice(device),
		mpTexture(texture),
		mpRenderSurface(NULL),
		mpBackBuffer(NULL)
	{
		mpTexture->GetSurfaceLevel(0, &mpRenderSurface);

		D3DSURFACE_DESC info;
		mpTexture->GetLevelDesc(0, &info);
		int width = info.Width;
		int height = info.Height;

		mRenderTargetInfo.maximumDepth = 0.0f;
		mRenderTargetInfo.hOffset = -0.5f / float(width);
		mRenderTargetInfo.vOffset = -0.5f / float(height);
		mRenderTargetInfo.aspectCoef = float(height) / float(width);
		mRenderTargetInfo.pixScaleX = 1.0 / float(width);
		mRenderTargetInfo.pixScaleY = 1.0 / float(height);
	}

	DirectXRTTexture::~DirectXRTTexture()
	{
		if (mpRenderSurface != nullptr)
		{
			mpRenderSurface->Release();
			mpRenderSurface = nullptr;
		}
	}

	void DirectXRTTexture::begin()
	{
		mpD3DDevice->GetRenderTarget(0, &mpBackBuffer);

		mpD3DDevice->SetRenderTarget(0, mpRenderSurface);
		mpD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET,
			D3DCOLOR_RGBA(0, 0, 0, 0), 1, 0);

		mpD3DDevice->BeginScene();
	}

	void DirectXRTTexture::end()
	{
		mpD3DDevice->EndScene();

		mpD3DDevice->SetRenderTarget(0, mpBackBuffer);
		mpBackBuffer->Release();
	}

	void DirectXRTTexture::DoRender(IVertexBuffer* buffer, ITexture* texture, size_t count)
	{
		DirectXRenderManager::GetInstance().DoRender(buffer, texture, count);
	}

} // namespace GUI
