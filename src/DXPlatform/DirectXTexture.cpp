#include "DirectXTexture.h"
#include "DirectXDataManager.h"
#include "DirectXRTTexture.h"

//#include <d3dx9.h>

namespace GUI
{

	DirectXTexture::DirectXTexture(const std::string& name, IDirect3DDevice9* device) :
		mName(name),
		mpD3DDevice(device),
		mpTexture(NULL),
		mNumElemBytes(0),
		mLock(false),
		mRenderTarget(nullptr),
		mInternalPool(D3DPOOL_MANAGED),
		mInternalFormat(D3DFMT_UNKNOWN),
		mInternalUsage(0)
	{
	}

	DirectXTexture::~DirectXTexture()
	{
		Destroy();
	}

	const std::string& DirectXTexture::GetName() const
	{
		return mName;
	}

	void DirectXTexture::CreateManual(int width, int height, TextureUsage usage, PixelFormat format)
	{
		Destroy();

		mInternalUsage = 0;
		mInternalFormat = D3DFMT_UNKNOWN;

		mSize.Set(width, height);
		mTextureUsage = usage;
		mPixelFormat = format;
		mInternalPool = D3DPOOL_MANAGED;

		if (mTextureUsage == TextureUsage::RenderTarget)
		{
			mInternalUsage |= D3DUSAGE_RENDERTARGET;
			mInternalPool = D3DPOOL_DEFAULT;
		}
		else if (mTextureUsage == TextureUsage::Dynamic)
			mInternalUsage |= D3DUSAGE_DYNAMIC;
		else if (mTextureUsage == TextureUsage::Stream)
			mInternalUsage |= D3DUSAGE_DYNAMIC;

		if (mPixelFormat == PixelFormat::R8G8B8A8)
		{
			mInternalFormat = D3DFMT_A8R8G8B8;
			mNumElemBytes = 4;
		}
		else if (mPixelFormat == PixelFormat::R8G8B8)
		{
			mInternalFormat = D3DFMT_R8G8B8;
			mNumElemBytes = 3;
		}
		else if (mPixelFormat == PixelFormat::L8A8)
		{
			mInternalFormat = D3DFMT_A8L8;
			mNumElemBytes = 2;
		}
		else if (mPixelFormat == PixelFormat::L8)
		{
			mInternalFormat = D3DFMT_L8;
			mNumElemBytes = 1;
		}
		else
		{
			//exception
		}

		if (FAILED(mpD3DDevice->CreateTexture(mSize.width, mSize.height, 1, mInternalUsage, mInternalFormat, mInternalPool, &mpTexture, NULL)))
		{
			//exception
		}

	}

	void DirectXTexture::LoadFromFile(const std::string& filename)
	{
		Destroy();
		mTextureUsage = TextureUsage::Default;
		mPixelFormat = PixelFormat::R8G8B8A8;
    
		std::string fullname = DirectXDataManager::GetInstance().GetDataPath(filename);

		D3DXIMAGE_INFO info;
		D3DXGetImageInfoFromFileA(fullname.c_str(), &info);

		if (info.Format == D3DFMT_A8R8G8B8)
		{
			mPixelFormat = PixelFormat::R8G8B8A8;
			mNumElemBytes = 4;
		}
		else if (info.Format == D3DFMT_R8G8B8)
		{
			mPixelFormat = PixelFormat::R8G8B8;
			mNumElemBytes = 3;
		}
		else if (info.Format == D3DFMT_A8L8)
		{
			mPixelFormat = PixelFormat::L8A8;
			mNumElemBytes = 2;
		}
		else if (info.Format == D3DFMT_L8)
		{
			mPixelFormat = PixelFormat::L8;
			mNumElemBytes = 1;
		}
		else
		{
			//exception
		}

		mSize.Set(info.Width, info.Height);
		if (FAILED(D3DXCreateTextureFromFileA(mpD3DDevice, fullname.c_str(), &mpTexture)))
		{
			char buf[1024];
			sprintf(buf, "texture = %s\nloaded failed!", filename.c_str());
			MessageBoxA(0, buf, 0, MB_ICONERROR);
		}
	}

	void DirectXTexture::Destroy()
	{
		if (mRenderTarget != nullptr)
		{
			delete mRenderTarget;
			mRenderTarget = nullptr;
		}

		if (mpTexture != nullptr)
		{
			int nNewRefCount = mpTexture->Release();

			if (nNewRefCount > 0)
			{
				static char strError[255];
				sprintf( strError, "The texture object failed to cleanup properly.\n"
					"Release() returned a reference count of %d", nNewRefCount );
				MessageBoxA( NULL, strError, "ERROR", MB_OK | MB_ICONEXCLAMATION );
			}

			mpTexture = nullptr;
		}
	}

	int DirectXTexture::GetWidth()
	{
		return mSize.width;
	}

	int DirectXTexture::GetHeight()
	{
		return mSize.height;
	}

	void* DirectXTexture::Lock(TextureUsage access)
	{
		D3DLOCKED_RECT d3dlr;
		if (access == TextureUsage::Write)
		{
			if (SUCCEEDED(mpTexture->LockRect(0, &d3dlr, NULL, D3DLOCK_DISCARD)))
			{
				mLock = true;
			}
			else
			{
				//exception
				return nullptr;
			}
		}
		else
		{
			if (SUCCEEDED(mpTexture->LockRect(0, &d3dlr, NULL, D3DLOCK_READONLY)))
			{
				mLock = true;
			}
			else
			{
				//exception
				return nullptr;
			}
		}

		return d3dlr.pBits;
	}

	void DirectXTexture::Unlock()
	{
		if (SUCCEEDED(mpTexture->UnlockRect(0)))
		{
			mLock = false;
		}
		else
		{
			//exception
		}
	}

	bool DirectXTexture::IsLocked()
	{
		return mLock;
	}

	PixelFormat DirectXTexture::GetFormat()
	{
		return mPixelFormat;
	}

	size_t DirectXTexture::GetNumElemBytes()
	{
		return mNumElemBytes;
	}

	TextureUsage DirectXTexture::GetUsage()
	{
		return mTextureUsage;
	}

	IRenderTarget* DirectXTexture::GetRenderTarget()
	{
		if (mpTexture == nullptr)
			return nullptr;

		if (mRenderTarget == nullptr)
			mRenderTarget = new DirectXRTTexture(mpD3DDevice, mpTexture);

		return mRenderTarget;
	}

	void DirectXTexture::DeviceLost()
	{
		if (mInternalPool == D3DPOOL_DEFAULT)
		{
			Destroy();
		}
	}

	void DirectXTexture::DeviceRestore()
	{
		if (mInternalPool == D3DPOOL_DEFAULT)
		{
			if (FAILED(mpD3DDevice->CreateTexture(mSize.width, mSize.height, 1, mInternalUsage, mInternalFormat, D3DPOOL_DEFAULT, &mpTexture, NULL)))
			{
				MessageBoxA( NULL, "Error recreate texture", "ERROR", MB_OK | MB_ICONEXCLAMATION );
				//exception
			}
		}
	}

} // namespace GUI
