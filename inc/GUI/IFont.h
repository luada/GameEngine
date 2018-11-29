#ifndef __I_FONT_H__
#define __I_FONT_H__

#include "Prerequest.h"
#include "ISerializable.h"
#include "IResource.h"
#include "FontData.h"

namespace GUI
{

	class ITexture;

	class GUI_EXPORT IFont : public IResource
	{
		RTTI_DERIVED(IFont)

	public:
		IFont() { }
		virtual ~IFont() { }

		virtual GlyphInfo* GetGlyphInfo(Char id) = 0;

		virtual ITexture* GetTextureFont() = 0;

		virtual int GetDefaultHeight() = 0;

	};

} // namespace GUI

#endif // __I_FONT_H__
