#ifndef __COORD_CONVERTER_H__
#define __COORD_CONVERTER_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	class GUI_EXPORT CoordConverter
	{
	public:
		/** Convert pixel coordinates to texture UV coordinates */
		static FloatRect ConvertTextureCoord(const IntCoord& coord, const IntSize& textureSize)
		{
			if (!textureSize.width || !textureSize.height) return FloatRect();
			return FloatRect(
			(float)coord.left / (float)textureSize.width,
			(float)coord.top / (float)textureSize.height,
			(float)coord.Right() / (float)textureSize.width,
			(float)coord.Bottom() / (float)textureSize.height);
		}

		/* Convert from relative to pixel coordinates.
			@param coord relative coordinates.
		*/
		static IntCoord ConvertFromRelative(const FloatCoord& coord, const IntSize& view)
		{
			return IntCoord(int(coord.left * view.width), int(coord.top * view.height), int(coord.width * view.width), int(coord.height * view.height));
		}

		/* Convert from relative to pixel coordinates.
			@param coord relative coordinates.
		*/
		static IntSize ConvertFromRelative(const FloatSize& size, const IntSize& view)
		{
			return IntSize(int(size.width * view.width), int(size.height * view.height));
		}

		/* Convert from relative to pixel coordinates.
			@param coord relative coordinates.
		*/
		static IntPoint ConvertFromRelative(const FloatPoint& point, const IntSize& view)
		{
			return IntPoint(int(point.left * view.width), int(point.top * view.height));
		}

		/* Convert from pixel to relative coordinates.
			@param coord pixel coordinates.
		*/
		static FloatCoord ConvertToRelative(const IntCoord& coord, const IntSize& view)
		{
			return FloatCoord(coord.left / (float)view.width, coord.top / (float)view.height, coord.width / (float)view.width, coord.height / (float)view.height);
		}

		static FloatSize ConvertToRelative(const IntSize& size, const IntSize& view)
		{
			return FloatSize(size.width / (float)view.width, size.height / (float)view.height);
		}

		static FloatPoint ConvertToRelative(const IntPoint& point, const IntSize& view)
		{
			return FloatPoint(point.left / (float)view.width, point.top / (float)view.height);
		}

	};

} // namespace GUI

#endif // __COORD_CONVERTER_H__
