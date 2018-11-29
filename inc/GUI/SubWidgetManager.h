#ifndef __SUB_WIDGET_MANAGER_H__
#define __SUB_WIDGET_MANAGER_H__

#include "Prerequest.h"
#include "Instance.h"

namespace GUI
{

	class GUI_EXPORT SubWidgetManager
	{
		INSTANCE_HEADER(SubWidgetManager)

	public:
		void Initialise();
		void Shutdown();

	};

} // namespace GUI

#endif // __SUB_WIDGET_MANAGER_H__
