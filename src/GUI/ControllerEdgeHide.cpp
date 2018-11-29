#include "Precompiled.h"
#include "ControllerEdgeHide.h"
#include "Gui.h"
#include "InputManager.h"
#include "WidgetManager.h"
#include "Widget.h"

namespace GUI
{

#ifndef M_PI
	const float M_PI = 3.141593f;
#endif

	ControllerEdgeHide::ControllerEdgeHide() :
		mTime(1.0),
		mRemainPixels(0),
		mShadowSize(0),
		mElapsedTime(0)
	{
	}

	void ControllerEdgeHide::PrepareItem(Widget* widget)
	{
		RecalculateTime(widget);
		eventPreAction(widget);
	}

	bool ControllerEdgeHide::AddTime(Widget* widget, float time)
	{
		Widget* keyFocus = InputManager::GetInstance().GetKeyFocusWidget();
		Widget* mouseFocus = InputManager::GetInstance().GetMouseFocusWidget();

		while ((keyFocus != nullptr) && (widget != keyFocus))
			keyFocus = keyFocus->GetParent();
		while ((mouseFocus != nullptr) && (widget != mouseFocus))
			mouseFocus = mouseFocus->GetParent();

		// if our curWidget or its children have focus
		bool haveFocus = ((keyFocus != nullptr) || (mouseFocus != nullptr)) || (widget->IsVisible() == false);

		mElapsedTime += (1 - 2*haveFocus) * time;

		if (mElapsedTime >= mTime)
		{
			mElapsedTime = mTime;
		}
		if (mElapsedTime <= 0)
		{
			mElapsedTime = 0.0f;
			return true;
		}

		float k = sin(M_PI * mElapsedTime/mTime - M_PI/2);
		if (k<0) k = (-pow(-k, 0.7f) + 1)/2;
		else k = (pow(k, 0.7f) + 1)/2;

		GUI::IntCoord coord = widget->GetCoord();
		// if curWidget was moved
		if (coord != mLastCoord)
		{
			// if still moving - leave it alone
			if (haveFocus)
				return true;
			else
				RecalculateTime(widget);
		}

		IntSize view_size;
		if (widget->GetCroppedParent() == nullptr)
			view_size = widget->GetLayer()->GetSize();
		else
			view_size = ((Widget*)widget->GetCroppedParent())->GetSize();

		bool nearBorder = false;

		if ((coord.left <= 0) && !(coord.Right() >= view_size.width - 1))
		{
			coord.left = - int( float(coord.width - mRemainPixels - mShadowSize) * k);
			nearBorder = true;
		}
		else if ((coord.top <= 0) && !(coord.Bottom() >= view_size.height - 1))
		{
			coord.top = - int( float(coord.height - mRemainPixels - mShadowSize) * k);
			nearBorder = true;
		}
		else if ((coord.Right() >= view_size.width - 1) && !(coord.left <= 0))
		{
			coord.left = int(float(view_size.width - 1) - float(mRemainPixels)*k - float(coord.width) * (1.f - k));
			nearBorder = true;
		}
		else if ((coord.Bottom() >= view_size.height-1) && !(coord.top <= 0))
		{
			coord.top = int(float(view_size.height-1) - float(mRemainPixels)*k - float(coord.height) * (1.f - k));
			nearBorder = true;
		}

		if (nearBorder)
		{
			widget->SetCoord(coord);
		}
		else
		{
			mElapsedTime = 0;
		}
		mLastCoord = coord;

		eventUpdateAction(widget);

		return true;
	}

	void ControllerEdgeHide::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Time") SetTime(utility::ParseValue<float>(value));
		else if (key == "RemainPixels") SetRemainPixels(utility::ParseValue<int>(value));
		else if (key == "ShadowSize") SetShadowSize(utility::ParseValue<int>(value));
	}

	void ControllerEdgeHide::RecalculateTime(Widget* widget)
	{
		float k = 0;
		const GUI::IntCoord& coord = widget->GetCoord();		IntSize view_size;
		if (widget->GetCroppedParent() == nullptr)
			view_size = widget->GetLayer()->GetSize();
		else
			view_size = ((Widget*)widget->GetCroppedParent())->GetSize();


		// check if curWidget is near any border and not near opposite borders at same time
		if ((coord.left <= 0) && !(coord.Right() >= view_size.width - 1))
		{
			k = - (float) coord.left / (coord.width - mRemainPixels - mShadowSize);
		}
		else if ((coord.top <= 0) && !(coord.Bottom() >= view_size.height - 1))
		{
			k = - (float)coord.top / (coord.height - mRemainPixels - mShadowSize);
		}
		else if ((coord.Right() >= view_size.width - 1) && !(coord.left <= 0))
		{
			k = (float)(coord.Right() - view_size.width + 1 ) / (coord.width - mRemainPixels);
		}
		else if ((coord.Bottom() >= view_size.height - 1) && !(coord.top <= 0))
		{
			k = (float)(coord.Bottom() - view_size.height + 1 ) / (coord.height - mRemainPixels);
		}

		//mElapsedTime = (asin(k)/M_PI + 1./2) * mTime;
		// this is reversed formula from ControllerEdgeHide::addTime k calculation
		if (k > 0.5f)
			mElapsedTime = (asin( pow( 2*k - 1, 1/0.7f))/M_PI + 1.f/2) * mTime;
		else
			mElapsedTime = (asin(-pow(-2*k + 1, 1/0.7f))/M_PI + 1.f/2) * mTime;
	}

} // namespace GUI

