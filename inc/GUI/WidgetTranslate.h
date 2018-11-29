#ifndef __WIDGET_TRANSLATE_H__
#define __WIDGET_TRANSLATE_H__

#include "Prerequest.h"

namespace GUI
{

	inline int GetWidgetWidth(Widget* widget, bool vert)
	{
		return vert ? widget->GetWidth() : widget->GetHeight();
	}

	inline int GetWidgetHeight(Widget* widget, bool vert)
	{
		return vert ? widget->GetHeight() : widget->GetWidth();
	}

	inline int GetWidgetLeft(Widget* widget, bool vert)
	{
		return vert ? widget->GetLeft() : widget->GetTop();
	}

	inline int GetWidgetTop(Widget* widget, bool vert)
	{
		return vert ? widget->GetTop() : widget->GetLeft();
	}

	inline void SetWidgetSize(Widget* widget, int width, int height, bool vert)
	{
		vert ? widget->SetSize(width, height) : widget->SetSize(height, width);
	}

	inline void SetWidgetCoord(Widget* widget, int left, int top, int width, int height, bool vert)
	{
		vert ? widget->SetCoord(left, top, width, height) : widget->SetCoord(top, left, height, width);
	}

	inline void ConvertWidgetCoord(IntCoord& coord, bool vert)
	{
		if ( ! vert )
		{
			std::swap(coord.left, coord.top);
			std::swap(coord.width, coord.height);
		}
	}

} // namespace GUI

#endif // __WIDGET_TRANSLATE_H__
