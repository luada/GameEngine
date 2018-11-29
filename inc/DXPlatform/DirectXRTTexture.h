#ifndef __DIRECTX_RTTEXTURE_H__
#define __DIRECTX_RTTEXTURE_H__

#include "Prerequest.h"
#include "ITexture.h"
#include "RenderFormat.h"
#include "IRenderTarget.h"

struct IDirect3DDevice9;
struct IDirect3DTexture9;
struct IDirect3DSurface9;

namespace GUI
{

	class DirectXRTTexture :
		public IRenderTarget
	{
	public:
		DirectXRTTexture(IDirect3DDevice9* device, IDirect3DTexture9* texture);
		virtual ~DirectXRTTexture();

		virtual void begin();
		virtual void end();

		virtual void DoRender(IVertexBuffer* buffer, ITexture* texture, size_t count);

		virtual const RenderTargetInfo& GetInfo() { return mRenderTargetInfo; }

	private:
		IDirect3DDevice9 *mpD3DDevice;
	    IDirect3DTexture9 *mpTexture;
		IDirect3DSurface9* mpRenderSurface;
		IDirect3DSurface9* mpBackBuffer;
		RenderTargetInfo mRenderTargetInfo;
	};

} // namespace GUI

#endif // __DIRECTX_RTTEXTURE_H__
