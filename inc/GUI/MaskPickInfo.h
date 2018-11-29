#ifndef __MASK_PICK_INFO_H__
#define __MASK_PICK_INFO_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	class GUI_EXPORT MaskPickInfo
	{
	public:
		MaskPickInfo() : width(0), height(0) { }

		bool Load(const std::string& file);

		bool Pick(const IntPoint& point, const IntCoord& coord) const
		{
			if ((0 == coord.width) || (0 == coord.height)) return false;

			int x = ((point.left * width)-1) / coord.width;
			int y = ((point.top * height)-1) / coord.height;

			return 0 != data[(size_t)(y * width + x)];
		}

		bool empty() const
		{
			return data.empty();
		}

	private:
		std::vector<uint8> data;
		int width, height;
	};

} // namespace GUI

#endif // __MASK_PICK_INFO_H__
