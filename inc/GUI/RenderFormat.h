#ifndef __RENDER_FORMAT_H__
#define __RENDER_FORMAT_H__

#include "Macros.h"

namespace GUI
{

	struct GUI_EXPORT VertexColourType
	{
		enum Enum
		{
			ColourARGB, // D3D style compact colour
			ColourABGR, // GL style compact colour
			MAX
		};

		VertexColourType(Enum value = MAX) : value(value) { }

		friend bool operator == (VertexColourType const& a, VertexColourType const& b) { return a.value == b.value; }
		friend bool operator != (VertexColourType const& a, VertexColourType const& b) { return a.value != b.value; }

	private:
		Enum value;
	};

	struct GUI_EXPORT PixelFormat
	{
		enum Enum
		{
			Unknow,
			L8, // 1 byte pixel format, 1 byte luminance
			L8A8, // 2 byte pixel format, 1 byte luminance, 1 byte alpha
			R8G8B8, // 24-bit pixel format, 8 bits for red, green and blue.
			R8G8B8A8 // 32-bit pixel format, 8 bits for red, green, blue and alpha.
		};

		PixelFormat(Enum value = Unknow) : value(value) { }

		friend bool operator == (PixelFormat const& a, PixelFormat const& b) { return a.value == b.value; }
		friend bool operator != (PixelFormat const& a, PixelFormat const& b) { return a.value != b.value; }

	private:
		Enum value;
	};

	struct GUI_EXPORT TextureUsage
	{
		enum Enum
		{
			Default = FLAG_NONE,
			Static = FLAG(0),
			Dynamic = FLAG(1),
			Stream = FLAG(2),
			Read = FLAG(3),
			Write = FLAG(4),
			RenderTarget = FLAG(5)
		};

		TextureUsage(Enum value = Default) : value(value) { }

		friend bool operator == (TextureUsage const& a, TextureUsage const& b) { return a.value == b.value; }
		friend bool operator != (TextureUsage const& a, TextureUsage const& b) { return a.value != b.value; }

		TextureUsage& operator |= (TextureUsage const& other) { value = Enum(int(value) | int(other.value)); return *this; }
		friend TextureUsage operator | (Enum const& a, Enum const& b) { return TextureUsage(Enum(int(a) | int(b))); }
		friend TextureUsage operator | (TextureUsage const& a, TextureUsage const& b) { return TextureUsage(Enum(int(a.value) | int(b.value))); }

		bool IsValue(Enum value) { return 0 != (this->value & value); }

	private:
		Enum value;
	};

} // namespace GUI


#endif // __RENDER_FORMAT_H__
