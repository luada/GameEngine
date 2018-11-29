#ifndef __DIRECTX_RENDER_MANAGER_H__
#define __DIRECTX_RENDER_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"
#include "RenderFormat.h"
#include "IVertexBuffer.h"
#include "RenderManager.h"

struct IDirect3DDevice9;

namespace GUI
{

	class DirectXRenderManager :
		public RenderManager,
		public IRenderTarget
	{
		INSTANCE_HEADER(DirectXRenderManager)

	public:
		void Initialise(IDirect3DDevice9 *_device);
		void Shutdown();

		virtual const IntSize& GetViewSize() const { return mViewSize; }

		virtual VertexColourType GetVertexFormat() { return mVertexFormat; }

		virtual IVertexBuffer* CreateVertexBuffer();
		virtual void DestroyVertexBuffer(IVertexBuffer* buffer);

		virtual ITexture* CreateTexture(const std::string& name);
		virtual void DestroyTexture(ITexture* texture);
		virtual ITexture* GetTexture(const std::string& name);

		virtual void begin();
		virtual void end();

		virtual void DoRender(IVertexBuffer* buffer, ITexture* texture, size_t count);

	    virtual const RenderTargetInfo& GetInfo() { return mInfo; }

	/*internal:*/
		void DrawOneFrame();
		void SetViewSize(int width, int height);

		void DeviceLost();
		void DeviceRestore();

	private:
		void DestroyAllResources();

	private:
	    IDirect3DDevice9 *mpD3DDevice;
		IntSize mViewSize;
		VertexColourType mVertexFormat;
		RenderTargetInfo mInfo;
		bool mUpdate;

		typedef std::map<std::string, ITexture*> MapTexture;
		MapTexture mTextures;
	};

} // namespace GUI

#endif // __DIRECTX_RENDER_MANAGER_H__
