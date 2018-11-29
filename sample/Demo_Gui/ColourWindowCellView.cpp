#include "precompiled.h"
#include "ColourWindowCellView.h"

namespace demo
{

	void ColourWindowCellView::GetCellDimension(GUI::Widget* sender, GUI::IntCoord & coord, bool drop)
	{
		coord.Set(0, 0, sender->GetClientCoord().width, 20);
	}

	ColourWindowCellView::ColourWindowCellView(GUI::Widget* parent) :
		wraps::BaseCellView<ColourWindowCellData>("ColourWindowCellView.layout", parent)
	{
		mMainWidget->SetCoord(0, 0, parent->GetWidth(), parent->GetHeight());
		mMainWidget->SetAlign(GUI::Align::Stretch);

		AssignWidget(mText, "Text");
		AssignWidget(mColour, "Colour");

		mRawColourView = mColour->GetSubWidgetMain()->CastType<GUI::RawRect>();
	}

	void ColourWindowCellView::Update(const GUI::IBDrawItemInfo & info, ColourWindowCellData * data)
	{

		if (info.update)
		{
			mText->SetCaption(data->GetName());
			mRawColourView->SetRectColour(data->GetColour(), data->GetColour(), data->GetColour(), data->GetColour());
		}

		if (info.active)
		{
			mText->SetTextColour(GUI::Colour::White);
		}
		else
		{
			mText->SetTextColour(GUI::Colour::Black);
		}

		if (info.select)
		{
			mColour->SetVisible(true);
		}
		else
		{
			mColour->SetVisible(false);
		}

	}

} // namespace demo
