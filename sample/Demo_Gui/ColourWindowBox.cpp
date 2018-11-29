#include "precompiled.h"
#include "ColourWindowBox.h"

namespace demo
{

	ColourWindowBox::ColourWindowBox(GUI::Widget* parent) : wraps::BaseItemBox<ColourWindowCellView>("", parent)
	{
	}

	ColourWindowBox::~ColourWindowBox()
	{
		size_t count = GetItemBox()->GetItemCount();
		for (size_t pos=0; pos<count; ++pos)
		{
			delete *GetItemBox()->GetItemDataAt<ColourWindowCellData*>(pos);
		}
	}

	void ColourWindowBox::AddColourItem(const GUI::Colour& colour, const std::string& name)
	{
		AddItem(new ColourWindowCellData(colour, name));
	}

} // namespace demo
