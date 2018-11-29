#include "DirectXVertexBuffer.h"
#include "VertexData.h"

#include <d3d9.h>

namespace GUI
{

	const size_t VERTEX_IN_QUAD = 6;
	const size_t RENDER_ITEM_STEEP_REALLOCK = 5 * VERTEX_IN_QUAD;

	DirectXVertexBuffer::DirectXVertexBuffer(IDirect3DDevice9* device, DirectXRenderManager* pRenderManager) :
		mNeedVertexCount(0),
		mVertexCount(RENDER_ITEM_STEEP_REALLOCK),
		mpD3DDevice(device),
		pRenderManager(pRenderManager),
		mpBuffer(NULL)
	{
	}

	DirectXVertexBuffer::~DirectXVertexBuffer()
	{
		Destroy();
	}

	void DirectXVertexBuffer::SetVertextCount(size_t count)
	{
		if (count != mNeedVertexCount)
		{
			mNeedVertexCount = count;
			Resize();
		}
	}

	size_t DirectXVertexBuffer::GetVertextCount()
	{
		return mNeedVertexCount;
	}

	Vertex* DirectXVertexBuffer::Lock()
	{
		//assert(!mpBuffer && __FUNCTION__);
		void *lockPtr = nullptr;
		if (SUCCEEDED(mpBuffer->Lock(0, 0, (void **)&lockPtr, 0)))
		{
			return (Vertex*)lockPtr;
		}
		return nullptr;
	}

	void DirectXVertexBuffer::Unlock()
	{
		//assert(!mpBuffer && __FUNCTION__);
		if (FAILED(mpBuffer->Unlock()))
		{
			//exception
		}
	}

	bool DirectXVertexBuffer::SetToStream(size_t stream)
	{
		//assert(!mpBuffer && __FUNCTION__);
		if (SUCCEEDED(mpD3DDevice->SetStreamSource(stream, mpBuffer, 0, sizeof(GUI::Vertex))))
			return true;
		return false;
	}

	bool DirectXVertexBuffer::Create()
	{
		DWORD length = mNeedVertexCount * sizeof(GUI::Vertex);
		if (SUCCEEDED(mpD3DDevice->CreateVertexBuffer(length, 0, 0, D3DPOOL_MANAGED, &mpBuffer, nullptr)))
			return false;
		return false;
	}

	void DirectXVertexBuffer::Destroy()
	{
		if (mpBuffer)
		{
			mpBuffer->Release();
			mpBuffer = nullptr;
		}
	}

	void DirectXVertexBuffer::Resize()
	{
		if (mpD3DDevice)
		{
			Destroy();
			Create();
		}
	}

} // namespace GUI
