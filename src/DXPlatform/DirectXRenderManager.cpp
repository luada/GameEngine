#include "DirectXRenderManager.h"
#include "DirectXTexture.h"
#include "DirectXVertexBuffer.h"
#include "DirectXDiagnostic.h"
#include "Gui.h"
#include "Timer.h"

#include <d3dx9.h>

namespace GUI
{

	INSTANCE_IMPLEMENT(DirectXRenderManager)

	void DirectXRenderManager::Initialise(IDirect3DDevice9 *_device)
	{
		PLATFORM_ASSERT(false == mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		PLATFORM_LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		mpD3DDevice = _device;

		mVertexFormat = VertexColourType::ColourARGB;  

		memset(&mInfo, 0, sizeof(mInfo));
		if (mpD3DDevice != nullptr)
		{
			D3DVIEWPORT9 vp;
			mpD3DDevice->GetViewport(&vp);
			SetViewSize(vp.Width, vp.Height);
		}

		mUpdate = false;

		PLATFORM_LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void DirectXRenderManager::Shutdown()
	{
		if (false == mIsInitialise) return;
		PLATFORM_LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		DestroyAllResources();
		mpD3DDevice = nullptr;

		PLATFORM_LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	IVertexBuffer* DirectXRenderManager::CreateVertexBuffer()
	{
		return new DirectXVertexBuffer(mpD3DDevice, this);
	}

	void DirectXRenderManager::DestroyVertexBuffer(IVertexBuffer* buffer)
	{
		delete buffer;
	}

	void DirectXRenderManager::DoRender(IVertexBuffer* buffer, ITexture* texture, size_t count)
	{
		DirectXTexture *dxTex = static_cast<DirectXTexture*>(texture);
		mpD3DDevice->SetTexture(0, dxTex->GetDirectXTexture());
		DirectXVertexBuffer *dxVB = static_cast<DirectXVertexBuffer*>(buffer);
		dxVB->SetToStream(0);
		// curCount in vertexes, triangle_list = vertexes / 3
		mpD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST, 0, count / 3);
	}

	void DirectXRenderManager::DrawOneFrame()
	{
		static Timer timer;
		static unsigned long last_time = timer.GetMilliseconds();
		unsigned long now_time = timer.GetMilliseconds();
		unsigned long time = now_time - last_time;

		Gui* gui = Gui::GetInstancePtr();
		if (gui != nullptr)
			gui->_injectFrameEntered((float)((double)(time) / (double)1000));

		last_time = now_time;

		begin();
		LayerManager::GetInstance().RenderToTarget(this, mUpdate);
		end();

		mUpdate = false;
	}

	void DirectXRenderManager::begin()
	{
		mpD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);

		mpD3DDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
		mpD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG0, D3DTA_DIFFUSE);
		mpD3DDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);

		mpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		mpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG0, D3DTA_DIFFUSE);
		mpD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);

		mpD3DDevice->SetSamplerState( 0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR );
		mpD3DDevice->SetSamplerState( 0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR );
		mpD3DDevice->SetSamplerState( 0, D3DSAMP_MIPFILTER, D3DTEXF_NONE );

		mpD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_CLAMP); 
		mpD3DDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_CLAMP);

		mpD3DDevice->SetRenderState(D3DRS_SRCBLEND,   D3DBLEND_SRCALPHA);
		mpD3DDevice->SetRenderState(D3DRS_DESTBLEND,  D3DBLEND_INVSRCALPHA);

		mpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, FALSE);
		mpD3DDevice->SetRenderState(D3DRS_ZENABLE, FALSE);
		mpD3DDevice->SetRenderState(D3DRS_LIGHTING, 0);
		mpD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);

		mpD3DDevice->SetFVF(D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1);

		D3DXMATRIX m;
		D3DXMatrixIdentity(&m);
		mpD3DDevice->SetTransform(D3DTS_WORLD, &m);
		mpD3DDevice->SetTransform(D3DTS_VIEW, &m);
		mpD3DDevice->SetTransform(D3DTS_PROJECTION, &m);
	}

	void DirectXRenderManager::end()
	{
	}

	ITexture* DirectXRenderManager::CreateTexture(const std::string& name)
	{
		MapTexture::const_iterator item = mTextures.find(name);
		PLATFORM_ASSERT(item == mTextures.end(), "Texture '" << name << "' already exist");

		DirectXTexture* texture = new DirectXTexture(name, mpD3DDevice);
		mTextures[name] = texture;
		return texture;
	}

	void DirectXRenderManager::DestroyTexture(ITexture* texture)
	{
		if (texture == nullptr) return;

		MapTexture::iterator item = mTextures.find(texture->GetName());
		PLATFORM_ASSERT(item != mTextures.end(), "Texture '" << texture->GetName() << "' not found");

		mTextures.erase(item);
		delete texture;
	}

	ITexture* DirectXRenderManager::GetTexture(const std::string& name)
	{
		MapTexture::const_iterator item = mTextures.find(name);
		if (item == mTextures.end()) return nullptr;
		return item->second;
	}

	void DirectXRenderManager::DestroyAllResources()
	{
		for (MapTexture::const_iterator item=mTextures.begin(); item!=mTextures.end(); ++item)
		{
			delete item->second;
		}
		mTextures.clear();
	}

	void DirectXRenderManager::SetViewSize(int width, int height)
	{
		if (height == 0)
			height = 1;
		if (width == 0)
			width = 1;

		mViewSize.Set(width, height);

		mInfo.maximumDepth = 0.0f;
		mInfo.hOffset = -0.5f / float(mViewSize.width);
		mInfo.vOffset = -0.5f / float(mViewSize.height);
		mInfo.aspectCoef = float(mViewSize.height) / float(mViewSize.width);
		mInfo.pixScaleX = 1.0 / float(mViewSize.width);
		mInfo.pixScaleY = 1.0 / float(mViewSize.height);

		Gui* gui = Gui::GetInstancePtr();
		if (gui != nullptr)
		{
			gui->ResizeWindow(mViewSize);
			mUpdate = true;
		}
	}

	void DirectXRenderManager::DeviceLost()
	{
		PLATFORM_LOG(Info, "device D3D lost");

		for (MapTexture::const_iterator item=mTextures.begin(); item!=mTextures.end(); ++item)
		{
			static_cast<DirectXTexture*>(item->second)->DeviceLost();
		}
	}

	void DirectXRenderManager::DeviceRestore()
	{
		PLATFORM_LOG(Info, "device D3D restore");

		for (MapTexture::const_iterator item=mTextures.begin(); item!=mTextures.end(); ++item)
		{
			static_cast<DirectXTexture*>(item->second)->DeviceRestore();
		}

		mUpdate = true;
	}

} // namespace GUI
