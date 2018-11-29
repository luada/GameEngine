#include "Precompiled.h"
#include "Button.h"
#include "ResourceSkin.h"
#include "StaticImage.h"
#include "InputManager.h"

namespace GUI
{

	Button::Button() :
		mIsMousePressed(false),
		mIsMouseFocus(false),
		mIsStateCheck(false),
		mImage(nullptr),
		mModeImage(false)
	{
	}

	void Button::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	Button::~Button()
	{
		ShutdownWidgetSkin();
	}

	void Button::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void Button::InitialiseWidgetSkin(ResourceSkin* info)
	{
		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("ButtonPressed");
			if (iter != properties.end()) SetButtonPressed(utility::ParseValue<bool>(iter->second));
			iter = properties.find("StateCheck");
			if (iter != properties.end()) SetStateCheck(utility::ParseValue<bool>(iter->second));
			iter = properties.find("ModeImage");
			if (iter != properties.end()) SetModeImage(utility::ParseValue<bool>(iter->second));
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Image")
			{
				DEBUG_ASSERT( ! mImage, "widget already assigned");
				mImage = (*iter)->CastType<StaticImage>();
			}
		}
	}

	void Button::ShutdownWidgetSkin()
	{
		mImage = nullptr;
	}

	void Button::OnMouseSetFocus(Widget* old)
	{
		_setMouseFocus(true);

		Base::OnMouseSetFocus(old);
	}

	void Button::OnMouseLostFocus(Widget* _new)
	{
		_setMouseFocus(false);

		Base::OnMouseLostFocus(_new);
	}

	void Button::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		if (id == MouseButton::Left)
		{
			mIsMousePressed = true;
			UpdateButtonState();
		}

		Base::OnMouseButtonPressed(left, top, id);
	}

	void Button::OnMouseButtonReleased(int left, int top, MouseButton id)
	{
		if (id == MouseButton::Left)
		{
			mIsMousePressed = false;
			UpdateButtonState();
		}

		Base::OnMouseButtonReleased(left, top, id);
	}

	void Button::SetImageIndex(size_t index)
	{
		if (mImage) mImage->SetImageIndex(index);
	}

	size_t Button::GetImageIndex()
	{
		if (mImage) return mImage->GetImageIndex();
		return ITEM_NONE;
	}

	void Button::UpdateButtonState()
	{
		if (mIsStateCheck)
		{
			if (!mEnabled) { if (!_setState("disabled_checked")) _setState("disabled"); }
			else if (mIsMousePressed) { if (!_setState("pushed_checked")) _setState("pushed"); }
			else if (mIsMouseFocus) { if (!_setState("highlighted_checked")) _setState("pushed"); }
			else _setState("normal_checked");
		}
		else
		{
			if (!mEnabled) _setState("disabled");
			else if (mIsMousePressed) _setState("pushed");
			else if (mIsMouseFocus) _setState("highlighted");
			else _setState("normal");
		}
	}

	void Button::SetStateCheck(bool check)
	{
		if (mIsStateCheck == check) return;
		mIsStateCheck = check;
		UpdateButtonState();
	}

	void Button::_setMouseFocus(bool focus)
	{
		mIsMouseFocus = focus;
		UpdateButtonState();
	}

	void Button::SetProperty(const std::string& key, const std::string& value)
	{
		/// @wproperty{Button, Button_Pressed, bool} Set pressed state.
		if (key == "Button_Pressed") SetButtonPressed(utility::ParseValue<bool>(value));
		else if (key == "Button_ModeImage") SetModeImage(utility::ParseValue<bool>(value));
		else if (key == "Button_ImageResource") SetImageResource(value);
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

	void Button::BaseUpdateEnable()
	{
		UpdateButtonState();
		if (!mEnabled)
		{
			mIsMouseFocus = false;
		}
	}

	void Button::SetModeImage(bool value)
	{
		mModeImage = value;
		UpdateButtonState();
	}

	bool Button::_setState(const std::string& value)
	{
		if (mModeImage)
		{
			if (mImage)
				mImage->SetItemName(value);

			SetState(value);
			return true;
		}

		return SetState(value);
	}

	void Button::SetImageResource(const std::string& name)
	{
		if (mImage)
			mImage->SetItemResource(name);
		UpdateButtonState();
	}

} // namespace GUI

