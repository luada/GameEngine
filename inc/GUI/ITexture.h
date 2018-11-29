#ifndef __I_TEXTURE_H__
#define __I_TEXTURE_H__

#include "Prerequest.h"
#include "IRenderTarget.h"
#include "RenderFormat.h"
#include <string>

namespace GUI
{
	class ITexture;

	class GUI_EXPORT ITextureInvalidateListener
	{
	public:
		virtual void TextureInvalidate(ITexture* texture) = 0;
	};

	class GUI_EXPORT ITexture
	{
	public:
		virtual ~ITexture() { }

		virtual const std::string& GetName() const = 0;

		virtual void CreateManual(int width, int height, TextureUsage usage, PixelFormat format) = 0;
		virtual void LoadFromFile(const std::string& filename) = 0;
		virtual void SaveToFile(const std::string& filename) = 0;

		virtual void SetInvalidateListener(ITextureInvalidateListener* listener) { }

		virtual void Destroy() = 0;

		virtual void* Lock(TextureUsage access) = 0;
		virtual void Unlock() = 0;
		virtual bool IsLocked() = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		virtual PixelFormat GetFormat() = 0;
		virtual TextureUsage GetUsage() = 0;
		virtual size_t GetNumElemBytes() = 0;

		virtual IRenderTarget* GetRenderTarget() { return nullptr; }

	};

} // namespace GUI

#endif // __I_TEXTURE_H__
