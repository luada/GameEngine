#ifndef __CAST_WIDGET_H__
#define __CAST_WIDGET_H__

#include "Prerequest.h"
#include "Widget.h"

namespace GUI
{

#ifndef DONT_USE_OBSOLETE

	template <typename T>
	OBSOLETE("use : template<typename Type> Type* Widget::CastType(bool _throw)")
	T* CastWidget(Widget * widget)
	{
		DEBUG_ASSERT(nullptr != widget, "Error static cast, curWidget == nullptr");
		return widget->CastType<T>();
	}

#endif // DONT_USE_OBSOLETE

} // namespace GUI

#endif // __CAST_WIDGET_H__

