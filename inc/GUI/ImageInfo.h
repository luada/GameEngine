#ifndef __IMAGE_INFO_H__
#define __IMAGE_INFO_H__

#include "Prerequest.h"

namespace GUI
{

	struct ImageItem
	{
		ImageItem() : frame_rate(0) { }

		float frame_rate;
		std::vector<FloatRect> images;
	};

	typedef std::vector<ImageItem> VectorImages;

	struct ImageIndexInfo
	{
		ImageIndexInfo(const std::string& texture,
			const IntSize& size,
			const float rate,
			const std::vector<IntPoint>& frames) :
			texture(texture),
			size(size),
			rate(rate),
			frames(frames)
		{
		}

		const std::string& texture;
		const IntSize& size;
		const float rate;
		const std::vector<IntPoint>& frames;
	};

} // namespace GUI

#endif // __IMAGE_INFO_H__
