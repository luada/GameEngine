#ifndef __SUB_WIDGET_INFO_H__
#define __SUB_WIDGET_INFO_H__

#include "Prerequest.h"

namespace GUI
{

	struct SubWidgetInfo
	{
		SubWidgetInfo(const std::string& type, const IntCoord& coord, Align align) :
			coord(coord),
			align(align),
			type(type)
		{
		}

		IntCoord coord;
		Align align;
		std::string type;
	};

	typedef std::vector<SubWidgetInfo> VectorSubWidgetInfo;

} // namespace GUI

#endif // __SUB_WIDGET_INFO_H__

