#include "Precompiled.h"
#include "IWidgetCreator.h"
#include "Widget.h"

namespace GUI
{

	void IWidgetCreator::_deleteWidget(Widget* widget)
	{
		delete widget;
	}

} // namespace GUI
