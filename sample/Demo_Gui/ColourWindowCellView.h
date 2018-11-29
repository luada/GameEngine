#ifndef __COLOUR_WINDOW_CELL_VIEW_H__
#define __COLOUR_WINDOW_CELL_VIEW_H__

#include <GUI.h>
#include "BaseCellView.h"
#include "ColourWindowCellData.h"

namespace demo
{

	class ColourWindowCellView : public wraps::BaseCellView<ColourWindowCellData>
	{
	public:
		ColourWindowCellView(GUI::Widget* parent);

		void Update(const GUI::IBDrawItemInfo & info, ColourWindowCellData * data);
		static void GetCellDimension(GUI::Widget* sender, GUI::IntCoord & coord, bool drop);

	private:

		GUI::StaticText* mText;
		GUI::Widget* mColour;
		GUI::RawRect * mRawColourView;

	};

} // namespace demo

#endif // __COLOUR_WINDOW_CELL_VIEW_H__
