#ifndef __BASE_CELL_VIEW_H__
#define __BASE_CELL_VIEW_H__

#include <GUI.h>
#include "BaseLayout.h"

namespace wraps
{

	template<typename DataType>
	class BaseCellView : public BaseLayout
	{
	public:
		typedef DataType Type;

	protected:
		BaseCellView(const std::string& layout, GUI::WidgetPtr parent) : BaseLayout(layout, parent) { }

	};

} // namespace wraps

#endif // __BASE_CELL_VIEW_H__
