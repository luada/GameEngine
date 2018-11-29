#include "Precompiled.h"
#include "Window.h"
#include "Macros.h"
#include "Gui.h"
#include "ControllerManager.h"
#include "InputManager.h"
#include "WidgetManager.h"
#include "ResourceSkin.h"

namespace GUI
{

	const float WINDOW_ALPHA_ACTIVE = ALPHA_MAX;
	const float WINDOW_ALPHA_FOCUS = 0.7f;
	const float WINDOW_ALPHA_DEACTIVE = 0.3f;
	const float WINDOW_SPEED_COEF = 3.0f;

	const int WINDOW_SNAP_DISTANSE = 10;

	Window::Window() :
		mWidgetCaption(nullptr),
		mMouseRootFocus(false),
		mKeyRootFocus(false),
		mIsAutoAlpha(false),
		mSnap(false),
		mAnimateSmooth(false)
	{
	}

	void Window::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	Window::~Window()
	{
		ShutdownWidgetSkin();
	}

	void Window::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void Window::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mNeedKeyFocus = true;

		mMinmax.Set(0, 0, 3000, 3000);

		bool main_move = false;
		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("Snap");
			if (iter != properties.end()) mSnap = utility::ParseBool(iter->second);
			iter = properties.find("MainMove");
			if (iter != properties.end())
			{
				SetUserString("Scale", "1 1 0 0");
				main_move = true;
			}
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mWidgetClient, "widget already assigned");
				mWidgetClient = (*iter);
				if (main_move)
				{
					(*iter)->SetUserString("Scale", "1 1 0 0");
					(*iter)->eventMouseButtonPressed = NewDelegate(this, &Window::NotifyMousePressed);
					(*iter)->eventMouseDrag = NewDelegate(this, &Window::NotifyMouseDrag);
				}
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Caption")
			{
				DEBUG_ASSERT( ! mWidgetCaption, "widget already assigned");
				mWidgetCaption = (*iter);
				mWidgetCaption->eventMouseButtonPressed = NewDelegate(this, &Window::NotifyMousePressed);
				mWidgetCaption->eventMouseDrag = NewDelegate(this, &Window::NotifyMouseDrag);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Button")
			{
				(*iter)->eventMouseButtonClick = NewDelegate(this, &Window::NotifyPressedButtonEvent);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Action")
			{
				(*iter)->eventMouseButtonPressed = NewDelegate(this, &Window::NotifyMousePressed);
				(*iter)->eventMouseDrag = NewDelegate(this, &Window::NotifyMouseDrag);
			}
		}

	}

	void Window::ShutdownWidgetSkin()
	{
		mWidgetClient = nullptr;
		mWidgetCaption = nullptr;
	}

	Widget* Window::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		ASSERT(mWidgetClient != this, "mWidgetClient can not be this widget");
		if (mWidgetClient != nullptr) return mWidgetClient->CreateWidgetT(style, type, skin, coord, align, layer, name);
		return Base::BaseCreateWidget(style, type, skin, coord, align, layer, name);
	}

	void Window::OnMouseChangeRootFocus(bool focus)
	{
		mMouseRootFocus = focus;
		UpdateAlpha();

		Base::OnMouseChangeRootFocus(focus);
	}

	void Window::OnKeyChangeRootFocus(bool focus)
	{
		mKeyRootFocus = focus;
		UpdateAlpha();

		Base::OnKeyChangeRootFocus(focus);
	}

	void Window::OnMouseDrag(int left, int top)
	{
		NotifyMouseDrag(this, left, top);

		Base::OnMouseDrag(left, top);
	}

	void Window::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		NotifyMousePressed(this, left, top, id);

		Base::OnMouseButtonPressed(left, top, id);
	}

	void Window::NotifyMousePressed(GUI::Widget* sender, int left, int top, MouseButton id)
	{
		if (MouseButton::Left == id)
		{
			mPreActionCoord = mCoord;
			mCurrentActionScale = IntCoord::Parse(sender->GetUserString("Scale"));
		}
	}

	void Window::NotifyPressedButtonEvent(GUI::Widget* sender)
	{
		eventWindowButtonPressed(this, sender->GetUserString("event"));
	}

	void Window::NotifyMouseDrag(GUI::Widget* sender, int left, int top)
	{
		const IntPoint& point = InputManager::GetInstance().GetLastLeftPressed();

		IntCoord coord = mCurrentActionScale;
		coord.left *= (left - point.left);
		coord.top *= (top - point.top);
		coord.width *= (left - point.left);
		coord.height *= (top - point.top);

		if (coord.left == 0 && coord.top == 0)
			SetSize((mPreActionCoord + coord).Size());
		else if (coord.width == 0 && coord.height == 0)
			SetPosition((mPreActionCoord + coord).Point());
		else
			SetCoord(mPreActionCoord + coord);

		eventWindowChangeCoord(this);
	}

	void Window::UpdateAlpha()
	{
		if (!mIsAutoAlpha) return;

		float alpha;
		if (mKeyRootFocus) alpha = WINDOW_ALPHA_ACTIVE;
		else if (mMouseRootFocus) alpha = WINDOW_ALPHA_FOCUS;
		else alpha = WINDOW_ALPHA_DEACTIVE;

		ControllerFadeAlpha * controller = CreateControllerFadeAlpha(alpha, WINDOW_SPEED_COEF, true);
		ControllerManager::GetInstance().AddItem(this, controller);
	}

	void Window::SetAutoAlpha(bool value)
	{
		mIsAutoAlpha = value;
		if (!value) SetAlpha(ALPHA_MAX);
		else
		{
			if (mKeyRootFocus) SetAlpha(WINDOW_ALPHA_ACTIVE);
			else if (mMouseRootFocus) SetAlpha(WINDOW_ALPHA_FOCUS);
			else SetAlpha(WINDOW_ALPHA_DEACTIVE);
		}
	}

	void Window::SetPosition(const IntPoint& point)
	{
		IntPoint curPoint = point;
		if (mSnap)
		{
			IntCoord coord(curPoint, mCoord.Size());
			GetSnappedCoord(coord);
			curPoint = coord.Point();
		}

		Base::SetPosition(curPoint);
	}

	void Window::SetSize(const IntSize& size)
	{
		IntSize curSize = size;

		if (curSize.width < mMinmax.left) curSize.width = mMinmax.left;
		else if (curSize.width > mMinmax.right) curSize.width = mMinmax.right;
		if (curSize.height < mMinmax.top) curSize.height = mMinmax.top;
		else if (curSize.height > mMinmax.bottom) curSize.height = mMinmax.bottom;
		if ((curSize.width == mCoord.width) && (curSize.height == mCoord.height) ) return;

		if (mSnap)
		{
			IntCoord coord(mCoord.Point(), curSize);
			GetSnappedCoord(coord);
			curSize = coord.Size();
		}

		Base::SetSize(curSize);
	}

	void Window::SetCoord(const IntCoord& coord)
	{
		IntPoint pos = coord.Point();
		IntSize size = coord.Size();

		if (size.width < mMinmax.left)
		{
			int offset = mMinmax.left - size.width;
			size.width = mMinmax.left;
			if ((pos.left - mCoord.left) > offset) pos.left -= offset;
			else pos.left = mCoord.left;
		}
		else if (size.width > mMinmax.right)
		{
			int offset = mMinmax.right - size.width;
			size.width = mMinmax.right;
			if ((pos.left - mCoord.left) < offset) pos.left -= offset;
			else pos.left = mCoord.left;
		}
		if (size.height < mMinmax.top)
		{
			int offset = mMinmax.top - size.height;
			size.height = mMinmax.top;
			if ((pos.top - mCoord.top) > offset) pos.top -= offset;
			else pos.top = mCoord.top;
		}
		else if (size.height > mMinmax.bottom)
		{
			int offset = mMinmax.bottom - size.height;
			size.height = mMinmax.bottom;
			if ((pos.top - mCoord.top) < offset) pos.top -= offset;
			else pos.top = mCoord.top;
		}

		if (mSnap)
		{
			IntCoord curCoord(pos, size);
			GetSnappedCoord(curCoord);
			size = curCoord.Size();
		}

		IntCoord curCoord(pos, size);
		if (curCoord == mCoord) return;

		Base::SetCoord(curCoord);
	}

	void Window::SetCaption(const UString& caption)
	{
		if (mWidgetCaption != nullptr) mWidgetCaption->SetCaption(caption);
		else Base::SetCaption(caption);
	}

	const UString& Window::GetCaption()
	{
		if (mWidgetCaption != nullptr) return mWidgetCaption->GetCaption();
		return Base::GetCaption();
	}

	void Window::DestroySmooth()
	{
		ControllerFadeAlpha * controller = CreateControllerFadeAlpha(ALPHA_MIN, WINDOW_SPEED_COEF, false);
		controller->eventPostAction = NewDelegate(Action::ActionWidgetDestroy);
		ControllerManager::GetInstance().AddItem(this, controller);
	}

	void Window::AnimateStop(Widget* widget)
	{
		if (mAnimateSmooth)
		{
			ControllerManager::GetInstance().RemoveItem(this);
			mAnimateSmooth = false;
		}
	}

	void Window::SetVisible(bool visible)
	{

		if (mAnimateSmooth)
		{
			ControllerManager::GetInstance().RemoveItem(this);
			SetAlpha(GetAlphaVisible());
			SetEnabledSilent(true);
			mAnimateSmooth = false;
		}

		Base::SetVisible(visible);
	}

	float Window::GetAlphaVisible()
	{
		return (mIsAutoAlpha && !mKeyRootFocus) ? WINDOW_ALPHA_DEACTIVE : ALPHA_MAX;
	}

	void Window::GetSnappedCoord(IntCoord& coord)
	{
		if (abs(coord.left) <= WINDOW_SNAP_DISTANSE) coord.left = 0;
		if (abs(coord.top) <= WINDOW_SNAP_DISTANSE) coord.top = 0;

		IntSize view_size;
		if (GetCroppedParent() == nullptr)
			view_size = this->GetLayer()->GetSize();
		else
			view_size = ((Widget*)GetCroppedParent())->GetSize();

		if ( abs(coord.left + coord.width - view_size.width) < WINDOW_SNAP_DISTANSE) coord.left = view_size.width - coord.width;
		if ( abs(coord.top + coord.height - view_size.height) < WINDOW_SNAP_DISTANSE) coord.top = view_size.height - coord.height;
	}

	void Window::SetVisibleSmooth(bool visible)
	{
		mAnimateSmooth = true;
		ControllerManager::GetInstance().RemoveItem(this);

		if (visible)
		{
			SetEnabledSilent(true);
			if ( ! IsVisible() )
			{
				SetAlpha(ALPHA_MIN);
				Base::SetVisible(true);
			}
			ControllerFadeAlpha * controller = CreateControllerFadeAlpha(GetAlphaVisible(), WINDOW_SPEED_COEF, true);
			controller->eventPostAction = NewDelegate(this, &Window::AnimateStop);
			ControllerManager::GetInstance().AddItem(this, controller);
		}
		else
		{
			SetEnabledSilent(false);
			ControllerFadeAlpha * controller = CreateControllerFadeAlpha(ALPHA_MIN, WINDOW_SPEED_COEF, false);
			controller->eventPostAction = NewDelegate(Action::ActionWidgetHide);
			ControllerManager::GetInstance().AddItem(this, controller);
		}
	}

	ControllerFadeAlpha* Window::CreateControllerFadeAlpha(float alpha, float coef, bool enable)
	{
		ControllerItem* item = ControllerManager::GetInstance().CreateItem(ControllerFadeAlpha::GetClassTypeName());
		ControllerFadeAlpha* controller = item->CastType<ControllerFadeAlpha>();

		controller->SetAlpha(alpha);
		controller->SetCoef(coef);
		controller->SetEnabled(enable);

		return controller;
	}

	void Window::SetMinSize(const IntSize& value)
	{
		mMinmax.left = value.width;
		mMinmax.top = value.height;
	}

	IntSize Window::GetMinSize()
	{
		return IntSize(mMinmax.left, mMinmax.top);
	}

	void Window::SetMaxSize(const IntSize& value)
	{
		mMinmax.right = value.width;
		mMinmax.bottom = value.height;
	}

	IntSize Window::GetMaxSize()
	{
		return IntSize(mMinmax.right, mMinmax.bottom);
	}

	void Window::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Window_AutoAlpha") SetAutoAlpha(utility::ParseValue<bool>(value));
		else if (key == "Window_Snap") SetSnap(utility::ParseValue<bool>(value));
		else if (key == "Window_MinSize") SetMinSize(utility::ParseValue<IntSize>(value));
		else if (key == "Window_MaxSize") SetMaxSize(utility::ParseValue<IntSize>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

