#include "Precompiled.h"
#include "InputManager.h"
#include "Widget.h"
#include "WidgetManager.h"
#include "Gui.h"
#include "WidgetManager.h"

namespace GUI
{
	const unsigned long INPUT_TIME_DOUBLE_CLICK = 250; //measured in milliseconds
	const float INPUT_DELAY_FIRST_KEY = 0.4f;
	const float INPUT_INTERVAL_KEY = 0.05f;

	INSTANCE_IMPLEMENT(InputManager)

	void InputManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		mWidgetMouseFocus = 0;
		mWidgetKeyFocus = 0;
		mLayerMouseFocus = 0;
		mIsWidgetMouseCapture = false;
		mIsShiftPressed = false;
		mIsControlPressed = false;
		mHoldKey = KeyCode::None;
		mHoldChar = 0;
		mFirstPressKey = true;
		mTimerKey = 0.0f;
		mOldAbsZ = 0;

		WidgetManager::GetInstance().RegisterUnlinker(this);
		Gui::GetInstance().eventFrameStart += NewDelegate(this, &InputManager::FrameEntered);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void InputManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		Gui::GetInstance().eventFrameStart -= NewDelegate(this, &InputManager::FrameEntered);
		WidgetManager::GetInstance().UnregisterUnlinker(this);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	bool InputManager::InjectMouseMove(int absx, int absy, int absz)
	{
		mMousePosition.Set(absx, absy);

		int relz = absz - mOldAbsZ;
		mOldAbsZ = absz;

		if (relz != 0)
		{
			bool isFocus = IsFocusMouse();
			if (mWidgetMouseFocus != nullptr) mWidgetMouseFocus->OnMouseWheel(relz);
			return isFocus;
		}

		if (mIsWidgetMouseCapture)
		{
			if (mWidgetMouseFocus != nullptr)
			{
				if (mLayerMouseFocus != nullptr)
				{
					IntPoint point = mLayerMouseFocus->GetPosition(absx, absy);
					mWidgetMouseFocus->OnMouseDrag(point.left, point.top);
				}
			}
			else
				mIsWidgetMouseCapture = false;
			return true;
		}

		Widget* old_mouse_focus = mWidgetMouseFocus;

		Widget* item = LayerManager::GetInstance().GetWidgetFromPoint(absx, absy);

		if (mWidgetMouseFocus == item)
		{
			bool isFocus = IsFocusMouse();
			if (mWidgetMouseFocus != nullptr)
			{
				if (mLayerMouseFocus != nullptr)
				{
					IntPoint point = mLayerMouseFocus->GetPosition(absx, absy);
					mWidgetMouseFocus->OnMouseMove(absx, absy);
				}
			}
			return isFocus;
		}

		if (item)
		{
			Widget* root = item;
			while (root->GetParent()) root = root->GetParent();

			if (!mVectorModalRootWidget.empty())
			{
				if (root != mVectorModalRootWidget.back())
				{
					item = nullptr;
				}
			}

			if (item != nullptr)
			{
				mLayerMouseFocus = root->GetLayer();
			}
		}

		WidgetManager::GetInstance().AddWidgetToUnlink(item);


		//-------------------------------------------------------------------------------------//
		Widget* save_widget = nullptr;

		Widget* root_focus = item;
		while (root_focus != nullptr)
		{
			if (root_focus->mRootMouseActive)
			{
				save_widget = root_focus;
				break;
			}
			root_focus->mRootMouseActive = true;

			WidgetManager::GetInstance().AddWidgetToUnlink(root_focus);
			root_focus->OnMouseChangeRootFocus(true);
			WidgetManager::GetInstance().RemoveWidgetFromUnlink(root_focus);

			if (root_focus)
				root_focus = root_focus->GetParent();
		}

		root_focus = mWidgetMouseFocus;
		while (root_focus != nullptr)
		{
			if (root_focus == save_widget)
			{
				break;
			}
			root_focus->mRootMouseActive = false;

			WidgetManager::GetInstance().AddWidgetToUnlink(root_focus);
			root_focus->OnMouseChangeRootFocus(false);
			WidgetManager::GetInstance().RemoveWidgetFromUnlink(root_focus);

			if (root_focus)
				root_focus = root_focus->GetParent();
		}
		//-------------------------------------------------------------------------------------//

		if ((mWidgetMouseFocus != nullptr) && (mWidgetMouseFocus->IsEnabled()))
		{
			mWidgetMouseFocus->OnMouseLostFocus(item);
		}

		WidgetManager::GetInstance().RemoveWidgetFromUnlink(item);


		if ((item != nullptr) && (item->IsEnabled()))
		{
			item->OnMouseMove(absx, absy);
			item->OnMouseSetFocus(mWidgetMouseFocus);
		}

		mWidgetMouseFocus = item;

		if (old_mouse_focus != mWidgetMouseFocus)
			eventChangeMouseFocus(mWidgetMouseFocus);

		return IsFocusMouse();
	}

	bool InputManager::InjectMousePress(int absx, int absy, MouseButton id)
	{
		Widget* old_key_focus = mWidgetKeyFocus;

		if (!IsFocusMouse())
		{
			ResetKeyFocusWidget();

			if (old_key_focus != mWidgetKeyFocus)
				eventChangeKeyFocus(mWidgetKeyFocus);

			return false;
		}

		//FIXME
		if (!mWidgetMouseFocus->IsEnabled())
			return true;

		if (MouseButton::Left == id)
		{
			mIsWidgetMouseCapture = true;
			if (mLayerMouseFocus != nullptr)
			{
				IntPoint point = mLayerMouseFocus->GetPosition(absx, absy);
				mLastLeftPressed = point;
			}
		}

		Widget* item = mWidgetMouseFocus;
		while ((item != nullptr) && (!item->IsNeedKeyFocus()))
			item = item->GetParent();

		SetKeyFocusWidget(item);

		if (mWidgetMouseFocus != nullptr)
		{
			mWidgetMouseFocus->OnMouseButtonPressed(absx, absy, id);

			if (mWidgetMouseFocus)
			{
				LayerManager::GetInstance().UpLayerItem(mWidgetMouseFocus);

				Widget* pick = mWidgetMouseFocus;
				do
				{
					if (pick->GetWidgetStyle() == WidgetStyle::Overlapped)
					{
						if (pick->GetParent()) pick->GetParent()->_forcePeek(pick);
					}

					pick = pick->GetParent();
				}
				while (pick);
			}
		}

		if (old_key_focus != mWidgetKeyFocus)
			eventChangeKeyFocus(mWidgetKeyFocus);

		return true;
	}

	bool InputManager::InjectMouseRelease(int absx, int absy, MouseButton id)
	{
		if (IsFocusMouse())
		{
			if (!mWidgetMouseFocus->IsEnabled())
				return true;

			mWidgetMouseFocus->OnMouseButtonReleased(absx, absy, id);

			if (mIsWidgetMouseCapture)
			{
				mIsWidgetMouseCapture = false;

				if (nullptr != mWidgetMouseFocus)
				{
					if ((MouseButton::Left == id) && mTimer.GetMilliseconds() < INPUT_TIME_DOUBLE_CLICK)
					{
						mWidgetMouseFocus->OnMouseButtonClick();
						if (nullptr != mWidgetMouseFocus) mWidgetMouseFocus->OnMouseButtonDoubleClick();
					}
					else
					{
						Widget* item = LayerManager::GetInstance().GetWidgetFromPoint(absx, absy);
						if ( item == mWidgetMouseFocus)
						{
							mWidgetMouseFocus->OnMouseButtonClick();
						}
						mTimer.Reset();
					}
				}
			}

			InjectMouseMove(absx, absy, mOldAbsZ);

			return true;
		}

		return false;
	}

	bool InputManager::InjectKeyPress(KeyCode key, Char text)
	{
		FirstEncoding(key, true);

		StoreKey(key, text);

		bool wasFocusKey = IsFocusKey();

		//Pass keystrokes to the current active curText widget
		if (IsFocusKey())
		{
			mWidgetKeyFocus->OnKeyButtonPressed(key, text);
		}

		return wasFocusKey;
	}

	bool InputManager::InjectKeyRelease(KeyCode key)
	{
		FirstEncoding(key, false);

		ResetKey();

		bool wasFocusKey = IsFocusKey();

		if (IsFocusKey()) mWidgetKeyFocus->OnKeyButtonReleased(key);

		return wasFocusKey;
	}

	void InputManager::FirstEncoding(KeyCode key, bool bIsKeyPressed)
	{
		if ((key == KeyCode::LeftShift) || (key == KeyCode::RightShift))
			mIsShiftPressed = bIsKeyPressed;
		if ((key == KeyCode::LeftControl) || (key == KeyCode::RightControl))
			mIsControlPressed = bIsKeyPressed;
	}

	void InputManager::SetKeyFocusWidget(Widget* widget)
	{
		if (widget == mWidgetKeyFocus)
			return;

		//-------------------------------------------------------------------------------------//
		Widget* save_widget = nullptr;

		Widget* root_focus = widget;
		while (root_focus != nullptr)
		{
			if (root_focus->mRootKeyActive)
			{
				save_widget = root_focus;
				break;
			}
			root_focus->mRootKeyActive = true;

			WidgetManager::GetInstance().AddWidgetToUnlink(root_focus);
			root_focus->OnKeyChangeRootFocus(true);
			WidgetManager::GetInstance().RemoveWidgetFromUnlink(root_focus);

			if (root_focus)
				root_focus = root_focus->GetParent();
		}

		root_focus = mWidgetKeyFocus;
		while (root_focus != nullptr)
		{
			if (root_focus == save_widget)
			{
				break;
			}
			root_focus->mRootKeyActive = false;

			WidgetManager::GetInstance().AddWidgetToUnlink(root_focus);
			root_focus->OnKeyChangeRootFocus(false);
			WidgetManager::GetInstance().RemoveWidgetFromUnlink(root_focus);

			if (root_focus)
				root_focus = root_focus->GetParent();
		}
		//-------------------------------------------------------------------------------------//

		if (mWidgetKeyFocus)
		{
			mWidgetKeyFocus->OnKeyLostFocus(widget);
		}

		if (widget && widget->IsNeedKeyFocus())
		{
			widget->OnKeySetFocus(mWidgetKeyFocus);
		}

		mWidgetKeyFocus = widget;
	}

	void InputManager::ResetMouseFocusWidget()
	{
		Widget* root_focus = mWidgetMouseFocus;
		while (root_focus != nullptr)
		{
			root_focus->mRootMouseActive = false;

			WidgetManager::GetInstance().AddWidgetToUnlink(root_focus);
			root_focus->OnMouseChangeRootFocus(false);
			WidgetManager::GetInstance().RemoveWidgetFromUnlink(root_focus);

			if (root_focus)
				root_focus = root_focus->GetParent();
		}

		mIsWidgetMouseCapture = false;
		if (nullptr != mWidgetMouseFocus)
		{
			mWidgetMouseFocus->OnMouseLostFocus(nullptr);
			mWidgetMouseFocus = nullptr;
		}

	}

	void InputManager::_unlinkWidget(Widget* widget)
	{
		if (nullptr == widget) return;
		if (widget == mWidgetMouseFocus)
		{
			mIsWidgetMouseCapture = false;
			mWidgetMouseFocus = nullptr;
		}
		if (widget == mWidgetKeyFocus)
		{
			mWidgetKeyFocus = nullptr;
		}

		for (VectorWidgetPtr::iterator iter=mVectorModalRootWidget.begin(); iter!=mVectorModalRootWidget.end(); ++iter)
		{
			if ((*iter == widget))
			{
				mVectorModalRootWidget.erase(iter);
				break;
			}
		}

	}

	void InputManager::AddWidgetModal(Widget* widget)
	{
		if (nullptr == widget) return;
		ASSERT(nullptr == widget->GetParent(), "Modal curWidget must be root");

		ResetMouseFocusWidget();
		RemoveWidgetModal(widget);
		mVectorModalRootWidget.push_back(widget);

		SetKeyFocusWidget(widget);
		LayerManager::GetInstance().UpLayerItem(widget);
	}

	void InputManager::RemoveWidgetModal(Widget* widget)
	{
		ResetKeyFocusWidget(widget);
		ResetMouseFocusWidget();

		for (VectorWidgetPtr::iterator iter=mVectorModalRootWidget.begin(); iter!=mVectorModalRootWidget.end(); ++iter)
		{
			if ((*iter == widget))
			{
				mVectorModalRootWidget.erase(iter);
				break;
			}
		}
		if (!mVectorModalRootWidget.empty())
		{
			SetKeyFocusWidget(mVectorModalRootWidget.back());
			LayerManager::GetInstance().UpLayerItem(mVectorModalRootWidget.back());
		}
	}

	void InputManager::StoreKey(KeyCode key, Char text)
	{
		mHoldKey = KeyCode::None;
		mHoldChar = 0;

		if ( !IsFocusKey() ) return;
		if ( (key == KeyCode::LeftShift) || (key == KeyCode::RightShift)
			|| (key == KeyCode::LeftControl) || (key == KeyCode::RightControl)
			|| (key == KeyCode::LeftAlt) || (key == KeyCode::RightAlt)
			) return;

		mFirstPressKey = true;
		mHoldKey = key;
		mHoldChar = text;
		mTimerKey = 0.0f;
	}

	void InputManager::ResetKey()
	{
		mHoldKey = KeyCode::None;
		mHoldChar = 0;
	}

	void InputManager::FrameEntered(float frame)
	{
		if ( mHoldKey == KeyCode::None)
			return;

		if ( !IsFocusKey() )
		{
			mHoldKey = KeyCode::None;
			mHoldChar = 0;
			return;
		}

		mTimerKey += frame;

		if (mFirstPressKey)
		{
			if (mTimerKey > INPUT_DELAY_FIRST_KEY)
			{
				mFirstPressKey = false;
				mTimerKey = 0.0f;
			}
		}
		else
		{
			if (mTimerKey > INPUT_INTERVAL_KEY)
			{
				while (mTimerKey > INPUT_INTERVAL_KEY) mTimerKey -= INPUT_INTERVAL_KEY;
				mWidgetKeyFocus->OnKeyButtonPressed(mHoldKey, mHoldChar);
				// focus can be dropped in onKeyButtonPressed
				if ( IsFocusKey() ) mWidgetKeyFocus->OnKeyButtonReleased(mHoldKey);
			}
		}

	}

	void InputManager::ResetKeyFocusWidget(Widget* widget)
	{
		if (mWidgetKeyFocus == widget)
			SetKeyFocusWidget(nullptr);
	}

	IntPoint InputManager::GetMousePositionByLayer()
	{
		if (mLayerMouseFocus != nullptr)
			return mLayerMouseFocus->GetPosition(mMousePosition.left, mMousePosition.top);
		return mMousePosition;
	}

} // namespace GUI

