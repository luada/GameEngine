#include "Precompiled.h"
#include "ControllerFadeAlpha.h"
#include "Gui.h"
#include "InputManager.h"
#include "WidgetManager.h"
#include "Widget.h"

namespace GUI
{

	ControllerFadeAlpha::ControllerFadeAlpha() :
		mAlpha(1),
		mCoef(1),
		mEnabled(true)
	{
	}

	void ControllerFadeAlpha::PrepareItem(Widget* widget)
	{
		if (!mEnabled) widget->SetEnabledSilent(mEnabled);

		if ((ALPHA_MIN != mAlpha) && (!widget->IsVisible()))
		{
			widget->SetAlpha(ALPHA_MIN);
			widget->SetVisible(true);
		}

		if (!mEnabled) InputManager::GetInstance().UnlinkWidget(widget);

		eventPreAction(widget);
	}

	bool ControllerFadeAlpha::AddTime(Widget* widget, float time)
	{
		float alpha = widget->GetAlpha();

		if (mAlpha > alpha)
		{
			alpha += time * mCoef;
			if (mAlpha > alpha)
			{
				widget->SetAlpha(alpha);
				eventUpdateAction(widget);
				return true;
			}
			else
			{
				widget->SetAlpha(mAlpha);
			}
		}
		else if (mAlpha < alpha)
		{
			alpha -= time * mCoef;
			if (mAlpha < alpha)
			{
				widget->SetAlpha(alpha);
				eventUpdateAction(widget);
				return true;
			}
			else
			{
				widget->SetAlpha(mAlpha);
			}
		}

		eventPostAction(widget);

		return false;
	}

	void ControllerFadeAlpha::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Alpha") SetAlpha(utility::ParseValue<float>(value));
		else if (key == "Coef") SetCoef(utility::ParseValue<float>(value));
		else if (key == "Enabled") SetEnabled(utility::ParseValue<bool>(value));
	}

} // namespace GUI

