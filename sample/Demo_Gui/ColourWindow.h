#ifndef __COLOUR_WINDOW_H__
#define __COLOUR_WINDOW_H__

#include <GUI.h>
#include "BaseLayout.h"
#include "ColourWindowBox.h"

namespace demo
{

	class ColourWindow : public wraps::BaseLayout
	{
	public:
		ColourWindow(GUI::Widget* parent);
		virtual ~ColourWindow();

	private:
		void NotifyScrollChangePosition(GUI::VScroll* sender, size_t position);
		void NotifyMouseButtonClick(GUI::Widget* sender);
		void NotifyEditSelectAccept(GUI::Edit* sender);
		int GetRand(int min, int max);

	private:
		GUI::HScroll* mSliderRed;
		GUI::HScroll* mSliderGreen;
		GUI::HScroll* mSliderBlue;

		GUI::Widget* mColour;
		GUI::RawRect * mRawColourView;
		GUI::Button* mAdd;
		GUI::Edit* mLine;

		ColourWindowBox * mBox;

	};

} // namespace demo

#endif // __COLOUR_WINDOW_H__
