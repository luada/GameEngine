#ifndef __UNLINK_WIDGET_H__
#define __UNLINK_WIDGET_H__

#include "Prerequest.h"
#include "WidgetDefines.h"

namespace GUI
{

	class GUI_EXPORT IUnlinkWidget
	{
	public:
		virtual ~IUnlinkWidget() { }
		virtual void _unlinkWidget(Widget* widget) = 0;
	};

	typedef std::vector<IUnlinkWidget*> VectorIUnlinkWidget;

} // namespace GUI

#endif // __UNLINK_WIDGET_H__
