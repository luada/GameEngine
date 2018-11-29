#include "precompiled.h"
#include "ColourWindow.h"
#include "DDItemInfo.h"

namespace demo
{

	int ColourWindow::GetRand(int min, int max)
	{
		if (max < min) std::swap(max, min);
		int range = max - min;
		if (range == 0) return 0;
		int result = ::rand() % range;
		if (result < 0) result = -result;
		return min + result;
	}

	ColourWindow::ColourWindow(GUI::Widget* parent) : BaseLayout("ColourWindow.layout", parent)
	{
		AssignWidget(mSliderRed, "Red");
		AssignWidget(mSliderGreen, "Green");
		AssignWidget(mSliderBlue, "Blue");
		AssignWidget(mColour, "Colour");
		AssignWidget(mAdd, "Add");
		AssignWidget(mLine, "Line");
		AssignBase(mBox, "Box");

		mSliderRed->eventScrollChangePosition = GUI::NewDelegate(this, &ColourWindow::NotifyScrollChangePosition);
		mSliderGreen->eventScrollChangePosition = GUI::NewDelegate(this, &ColourWindow::NotifyScrollChangePosition);
		mSliderBlue->eventScrollChangePosition = GUI::NewDelegate(this, &ColourWindow::NotifyScrollChangePosition);

		mRawColourView = mColour->GetSubWidgetMain()->CastType<GUI::RawRect>();

		mAdd->eventMouseButtonClick = GUI::NewDelegate(this, &ColourWindow::NotifyMouseButtonClick);
		mLine->eventEditSelectAccept = GUI::NewDelegate(this, &ColourWindow::NotifyEditSelectAccept);

		if (parent)
		{
			const GUI::IntCoord& coord = parent->GetClientCoord();
			const GUI::IntSize& size = mMainWidget->GetSize();
			mMainWidget->SetPosition(GUI::IntPoint(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height)));
		}

		// update
		NotifyScrollChangePosition(nullptr, 0);
	}

	ColourWindow::~ColourWindow()
	{
		//mBox.Shutdown();
	}

	void ColourWindow::NotifyScrollChangePosition(GUI::VScroll* sender, size_t position)
	{
		GUI::Colour colour(float(mSliderRed->GetScrollPosition()) / float(mSliderRed->GetScrollRange()),
			float(mSliderGreen->GetScrollPosition()) / float(mSliderGreen->GetScrollRange()),
			float(mSliderBlue->GetScrollPosition()) / float(mSliderBlue->GetScrollRange()) );

		mRawColourView->SetRectColour(colour, colour, colour, colour);
	}

	void ColourWindow::NotifyEditSelectAccept(GUI::Edit* sender)
	{
		NotifyMouseButtonClick(nullptr);
	}

	void ColourWindow::NotifyMouseButtonClick(GUI::Widget* sender)
	{
		GUI::Colour colour(float(mSliderRed->GetScrollPosition()) / float(mSliderRed->GetScrollRange()),
			float(mSliderGreen->GetScrollPosition()) / float(mSliderGreen->GetScrollRange()),
			float(mSliderBlue->GetScrollPosition()) / float(mSliderBlue->GetScrollRange()) );

		mBox->AddColourItem(colour, mLine->GetCaption());
		mLine->SetCaption("");
	}

} // namespace demo
