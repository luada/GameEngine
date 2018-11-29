#ifndef __TEXTURE_UTILITY_H__
#define __TEXTURE_UTILITY_H__

#include "Prerequest.h"
#include "Colour.h"
#include "RenderFormat.h"

namespace GUI
{

	namespace texture_utility
	{

		GUI_EXPORT const IntSize& GetTextureSize(const std::string& texture, bool cache = true);
		GUI_EXPORT uint32 ToColourARGB(const Colour& colour);

		FORCEINLINE void ConvertColour(uint32& colour, VertexColourType format)
		{
			if (format == VertexColourType::ColourABGR)
				colour = ((colour & 0x00FF0000) >> 16) | ((colour & 0x000000FF) << 16) | (colour & 0xFF00FF00);
		}


	} // namespace texture_utility

} // namespace GUI

#endif // __TEXTURE_UTILITY_H__
