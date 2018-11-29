#ifndef __WIDGET_DEFINES_H__
#define __WIDGET_DEFINES_H__

#include "Prerequest.h"
#include "Enumerator.h"
#include <vector>
#include <map>

namespace GUI
{

	class Widget;
	class VectorWidgetPtr;
	typedef std::map<std::string, Widget*> MapWidgetPtr;
	typedef Enumerator<VectorWidgetPtr> EnumeratorWidgetPtr;

	class VectorWidgetPtr: public std::vector<Widget*>
	{
	public:
		//@ExportToLua
		size_type Size() const
		{
			return std::vector<Widget*>::size();
		}

		//@ExportToLua
		Widget*& operator[](size_type Pos)
		{
			return std::vector<Widget*>::operator[](Pos);
		}

		//@ExportToLua
		void Resize(size_type Newsize)
		{
			std::vector<Widget*>::resize(Newsize);
		}

		//@ExportToLua
		void Reserve(size_type Count)
		{
			std::vector<Widget*>::reserve(Count);
		}

		//@ExportToLua
		void Clear()
		{
			std::vector<Widget*>::clear();
		}
	};

} // namespace GUI

#endif // __WIDGET_DEFINES_H__
