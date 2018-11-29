#ifndef __COLOUR_WINDOW_BOX_H__
#define __COLOUR_WINDOW_BOX_H__

#include <GUI.h>
#include "BaseItemBox.h"
#include "ColourWindowCellView.h"

namespace demo
{

	class ColourWindowBox : public wraps::BaseItemBox<ColourWindowCellView>
	{
	public:
		ColourWindowBox(GUI::Widget* parent);
		virtual ~ColourWindowBox();

		void AddColourItem(const GUI::Colour& colour, const std::string& name);
	};

} // namespace demo

#endif // __COLOUR_WINDOW_BOX_H__
