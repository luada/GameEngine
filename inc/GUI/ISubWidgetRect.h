#ifndef __I_SUB_WIDGET_RECT_H__
#define __I_SUB_WIDGET_RECT_H__

#include "Prerequest.h"
#include "ISubWidget.h"
#include "Colour.h"

namespace GUI
{

	class GUI_EXPORT ISubWidgetRect : public ISubWidget
	{
		RTTI_DERIVED(ISubWidgetRect)

	public:
		virtual ~ISubWidgetRect() { }

		virtual void _setUVSet(const FloatRect& rect) { }
		virtual void _setColour(const Colour& value) { }

	};

} // namespace GUI

#endif // __I_SUB_WIDGET_RECT_H__
