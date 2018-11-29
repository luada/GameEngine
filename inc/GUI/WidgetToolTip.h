#ifndef __WIDGET_TOOLTIP_H__
#define __WIDGET_TOOLTIP_H__

#include "Prerequest.h"
#include "Types.h"
#include "WidgetToolTip.h"

namespace GUI
{

	/** Info about tootip state */
	struct ToolTipInfo
	{
		enum ToolTipType
		{
			Hide,
			Show
		};

		ToolTipInfo(ToolTipType type) :
			type(type), index(ITEM_NONE) { }

		ToolTipInfo(ToolTipType type, size_t index, const IntPoint& point) :
			type(type), index(index), point(point) { }

		ToolTipType type;
		size_t index;
		IntPoint point;
	};

} // namespace GUI

#endif //__WIDGET_TOOLTIP_H__
