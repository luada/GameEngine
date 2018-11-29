#ifndef __RENDER_MANAGER_H__
#define __RENDER_MANAGER_H__

#include "Prerequest.h"
#include "RenderFormat.h"
#include "ITexture.h"
#include "IVertexBuffer.h"
#include "IRenderTarget.h"

namespace GUI
{

	class GUI_EXPORT RenderManager
	{
	public:
		RenderManager();
		virtual ~RenderManager() = 0;

		static RenderManager& GetInstance();
		static RenderManager* GetInstancePtr();

		virtual IVertexBuffer* CreateVertexBuffer() = 0;
		virtual void DestroyVertexBuffer(IVertexBuffer* buffer) = 0;

		virtual ITexture* CreateTexture(const std::string& name) = 0;
		virtual void DestroyTexture(ITexture* texture) = 0;
		virtual ITexture* GetTexture(const std::string& name) = 0;

		//FIXME
		virtual const IntSize& GetViewSize() const = 0;

		virtual VertexColourType GetVertexFormat() = 0;

		virtual bool IsFormatSupported(PixelFormat format, TextureUsage usage) { return true; }

#if DEBUG_MODE == 1
		virtual bool CheckTexture(ITexture* texture) { return true; }
#endif

	private:
		static RenderManager* msInstance;
		bool mIsInitialise;
	};

} // namespace GUI

#endif // __RENDER_MANAGER_H__
