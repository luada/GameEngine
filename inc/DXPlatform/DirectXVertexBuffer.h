#ifndef __DIRECTX_VERTEX_BUFFER_H__
#define __DIRECTX_VERTEX_BUFFER_H__

#include "Prerequest.h"
#include "IVertexBuffer.h"
#include "DirectXRenderManager.h"

struct IDirect3DDevice9;
struct IDirect3DVertexBuffer9;

namespace GUI
{

	class DirectXVertexBuffer : public IVertexBuffer
	{
	public:
		DirectXVertexBuffer(IDirect3DDevice9 *_device, DirectXRenderManager *_pRenderManager);
		virtual ~DirectXVertexBuffer();

		virtual void SetVertextCount(size_t count);
		virtual size_t GetVertextCount();

		virtual Vertex* Lock();
		virtual void Unlock();

	/*internal:*/
		virtual bool SetToStream(size_t stream);

	private:
		bool Create();
		void Destroy();
		void Resize();

	private:
		IDirect3DDevice9 *mpD3DDevice;
		IDirect3DVertexBuffer9 *mpBuffer;
	    DirectXRenderManager *pRenderManager;

		size_t mVertexCount;
		size_t mNeedVertexCount;
	};

} // namespace GUI

#endif // __DIRECTX_VERTEX_BUFFER_H__
