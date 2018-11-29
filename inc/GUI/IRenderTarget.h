#ifndef __I_RENDER_TARGET_H__
#define __I_RENDER_TARGET_H__

#include "Prerequest.h"
#include "RenderTargetInfo.h"

namespace GUI
{

	class ITexture;
	class IVertexBuffer;

	class GUI_EXPORT IRenderTarget
	{
	public:
		IRenderTarget() { }
		virtual ~IRenderTarget() { }

		virtual void begin() = 0;
		virtual void end() = 0;

		virtual void DoRender(IVertexBuffer* buffer, ITexture* texture, size_t count) = 0;

		virtual const RenderTargetInfo& GetInfo() = 0;

	};

} // namespace GUI

#endif // __I_RENDER_TARGET_H__
