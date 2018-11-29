#ifndef __WIDGET_CREATOR_H__
#define __WIDGET_CREATOR_H__

#include "Prerequest.h"
#include "Types.h"
#include "WidgetStyle.h"

namespace GUI
{

	class GUI_EXPORT IWidgetCreator
	{
		friend class WidgetManager;

	public:
		virtual ~IWidgetCreator() { }

	protected:
		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name) = 0;

		virtual void _destroyChildWidget(Widget* widget) = 0;

		virtual void _destroyAllChildWidget() = 0;

		void _deleteWidget(Widget* widget);

	public:
		virtual void _linkChildWidget(Widget* widget) { }
		virtual void _unlinkChildWidget(Widget* widget) { }

	};

} // namespace GUI

#endif // __WIDGET_CREATOR_H__

