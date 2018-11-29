#include "Precompiled.h"
#include "ControllerPosition.h"
#include "Gui.h"
#include "InputManager.h"
#include "WidgetManager.h"
#include "Widget.h"
#include "ActionController.h"

namespace GUI
{

	ControllerPosition::ControllerPosition() :
		mTime(1),
		mElapsedTime(0),
		mCalcPosition(false),
		mCalcSize(false)
	{
	}

	void ControllerPosition::SetCoord(const IntCoord& destCoord)
	{
		mDestCoord = destCoord;
		mCalcPosition = true;
		mCalcSize = true;
	}

	void ControllerPosition::SetSize(const IntSize& destSize)
	{
		mDestCoord.width = destSize.width;
		mDestCoord.height = destSize.height;
		mCalcPosition = false;
		mCalcSize = true;
	}

	void ControllerPosition::SetPosition(const IntPoint& destPoint)
	{
		mDestCoord.left = destPoint.left;
		mDestCoord.top = destPoint.top;
		mCalcPosition = true;
		mCalcSize = false;
	}

	void ControllerPosition::PrepareItem(Widget* widget)
	{
		DEBUG_ASSERT(mTime > 0, "Time must be > 0");

		mStartCoord = widget->GetCoord();

		eventPreAction(widget);
	}

	bool ControllerPosition::AddTime(Widget* widget, float time)
	{
		mElapsedTime += time;

		if (mElapsedTime < mTime)
		{
			IntCoord coord;
			eventFrameAction(mStartCoord, mDestCoord, coord, mElapsedTime/mTime);
			if (mCalcPosition)
			{
				if (mCalcSize) widget->SetCoord(coord);
				else widget->SetPosition(coord.Point());
			}
			else if (mCalcSize) widget->SetSize(coord.Size());

			eventUpdateAction(widget);

			return true;
		}

		IntCoord coord;
		eventFrameAction(mStartCoord, mDestCoord, coord, 1.0f);
		if (mCalcPosition)
		{
			if (mCalcSize) widget->SetCoord(coord);
			else widget->SetPosition(coord.Point());
		}
		else if (mCalcSize) widget->SetSize(coord.Size());

		eventUpdateAction(widget);

		eventPostAction(widget);

		return false;
	}

	void ControllerPosition::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Time") SetTime(utility::ParseValue<float>(value));
		else if (key == "Coord") SetCoord(utility::ParseValue<IntCoord>(value));
		else if (key == "Size") SetSize(utility::ParseValue<IntSize>(value));
		else if (key == "Position") SetPosition(utility::ParseValue<IntPoint>(value));
		else if (key == "Function") SetFunction(value);
	}

	void ControllerPosition::SetFunction(const std::string& value)
	{
		if (value == "Inertional") SetAction(GUI::NewDelegate(Action::InertionalMoveFunction));
		else if (value == "Accelerated") SetAction(GUI::NewDelegate(Action::AcceleratedMoveFunction<30>));
		else if (value == "Slowed") SetAction(GUI::NewDelegate(Action::AcceleratedMoveFunction<4>));
		else if (value == "Jump") SetAction(GUI::NewDelegate(Action::JumpMoveFunction<5>));
	}

} // namespace GUI

