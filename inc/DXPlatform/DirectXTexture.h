#ifndef __DIRECTX_TEXTURE_H__
#define __DIRECTX_TEXTURE_H__

#include "Prerequest.h"
#include "ITexture.h"
#include "RenderFormat.h"
#include "Types.h"

#include <d3dx9.h>

namespace GUI
{

	class DirectXTexture : public ITexture
	{
	public:
		DirectXTexture(const std::string& name, IDirect3DDevice9* device);
		virtual ~DirectXTexture();

		virtual const std::string& GetName() const;

		virtual void CreateManual(int width, int height, TextureUsage usage, PixelFormat format);
		virtual void LoadFromFile(const std::string& filename);
		virtual void SaveToFile(const std::string& filename) { }

		virtual void Destroy();

		virtual void* Lock(TextureUsage access);
		virtual void Unlock();
		virtual bool IsLocked();

		virtual int GetWidth();
		virtual int GetHeight();

		virtual PixelFormat GetFormat();
		virtual TextureUsage GetUsage();
		virtual size_t GetNumElemBytes();

		virtual IRenderTarget* GetRenderTarget();

	/*internal:*/
		IDirect3DTexture9 * GetDirectXTexture() { return mpTexture; }
		void DeviceLost();
		void DeviceRestore();

	private:
		IDirect3DDevice9 *mpD3DDevice;
	    IDirect3DTexture9 *mpTexture;
		IntSize mSize;
		TextureUsage mTextureUsage;
		PixelFormat mPixelFormat;
		size_t mNumElemBytes;
		bool mLock;
		std::string mName;
		IRenderTarget* mRenderTarget;
		D3DPOOL mInternalPool;
		D3DFORMAT mInternalFormat;
		unsigned long mInternalUsage;
	};

} // namespace GUI

#endif // __DIRECTX_TEXTURE_H__
