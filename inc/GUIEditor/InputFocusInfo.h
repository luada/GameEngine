#ifndef __INPUT_FOCUS_INFO_H__
#define __INPUT_FOCUS_INFO_H__

#include <GUI.h>

namespace diagnostic
{

	class InputFocusInfo
	{
	public:
		InputFocusInfo() :
			mFocusVisible(false),
			mMouseHelper(nullptr),
			mKeyHelper(nullptr),
			mWidgetMouseFocus(nullptr),
			mWidgetKeyFocus(nullptr),
			mOldMouseFocus(nullptr),
			mOldKeyFocus(nullptr)
		{
			GUI::InputManager::GetInstance().eventChangeMouseFocus += GUI::NewDelegate(this, &InputFocusInfo::NotifyChangeMouseFocus);
			GUI::InputManager::GetInstance().eventChangeKeyFocus += GUI::NewDelegate(this, &InputFocusInfo::NotifyChangeKeyFocus);
			GUI::Gui::GetInstance().eventFrameStart += GUI::NewDelegate(this, &InputFocusInfo::NotifyFrameStart);
		}

		~InputFocusInfo()
		{
			GUI::InputManager::GetInstance().eventChangeMouseFocus -= GUI::NewDelegate(this, &InputFocusInfo::NotifyChangeMouseFocus);
			GUI::InputManager::GetInstance().eventChangeKeyFocus -= GUI::NewDelegate(this, &InputFocusInfo::NotifyChangeKeyFocus);
			GUI::Gui::GetInstance().eventFrameStart -= GUI::NewDelegate(this, &InputFocusInfo::NotifyFrameStart);

			if (mKeyHelper != nullptr)
				GUI::Gui::GetInstance().DestroyWidget(mKeyHelper);
			if (mMouseHelper != nullptr)
				GUI::Gui::GetInstance().DestroyWidget(mMouseHelper);
		}

		bool GetFocusVisible() { return mFocusVisible; }

		void SetFocusVisible(bool value)
		{
			mFocusVisible = value;
			if (!mFocusVisible)
			{
				if (mMouseHelper)
					mMouseHelper->SetVisible(false);
				if (mKeyHelper)
					mKeyHelper->SetVisible(false);
			}
		}

	private:
		void NotifyChangeMouseFocus(GUI::WidgetPtr widget)
		{
			if (mFocusVisible)
			{
				mWidgetMouseFocus = widget;
				UpdateFocusWidgetHelpers();
			}
		}

		void NotifyChangeKeyFocus(GUI::WidgetPtr widget)
		{
			if (mFocusVisible)
			{
				mWidgetKeyFocus = widget;
				UpdateFocusWidgetHelpers();
			}
		}

		void NotifyFrameStart(float time)
		{
			if (mFocusVisible)
				UpdateFocusWidgetHelpers(false);
		}

		void UpdateFocusWidgetHelpers(bool updateinfo = true)
		{
			const std::string layer = "Statistic";
			const std::string skin_mouse = "RectGreen";
			const std::string skin_key = "RectBlue";

			if ((mWidgetMouseFocus != mOldMouseFocus)
				|| ((mWidgetMouseFocus != nullptr)
				&& (mMouseHelper != nullptr)
				&& mWidgetMouseFocus->GetAbsoluteCoord() != mMouseHelper->GetAbsoluteCoord()))
			{
				mOldMouseFocus = mWidgetMouseFocus;

				if (mMouseHelper == nullptr)
				{
					if (!GUI::LayerManager::GetInstance().IsExist(layer)) return;
					if (!GUI::SkinManager::GetInstance().IsExist(skin_mouse)) return;
					mMouseHelper = GUI::Gui::GetInstance().CreateWidget<GUI::Widget>(skin_mouse, GUI::IntCoord(), GUI::Align::Default, layer);
					mMouseHelper->SetNeedMouseFocus(false);
				}

				if (mWidgetMouseFocus)
				{
					if (updateinfo)
						GUI::GUI_OUT("mouse focus : ", mWidgetMouseFocus->GetName());
					mMouseHelper->SetCoord(mWidgetMouseFocus->GetAbsoluteCoord());
					mMouseHelper->SetVisible(true);
				}
				else
				{
					if (updateinfo)
						GUI::GUI_OUT("mouse focus : nullptr");
					mMouseHelper->SetVisible(false);
				}
			}

			if ((mWidgetKeyFocus != mOldKeyFocus)
				|| ((mWidgetKeyFocus != nullptr)
				&& (mKeyHelper != nullptr)
				&& mWidgetKeyFocus->GetAbsoluteCoord() != mKeyHelper->GetAbsoluteCoord()))
			{
				mOldKeyFocus = mWidgetKeyFocus;

				if (mKeyHelper == nullptr)
				{
					if (!GUI::LayerManager::GetInstance().IsExist(layer)) return;
					if (!GUI::SkinManager::GetInstance().IsExist(skin_key)) return;
					mKeyHelper = GUI::Gui::GetInstance().CreateWidget<GUI::Widget>(skin_key, GUI::IntCoord(), GUI::Align::Default, layer);
					mKeyHelper->SetNeedMouseFocus(false);
				}
				if (mWidgetKeyFocus)
				{
					if (updateinfo)
						GUI::GUI_OUT("key focus : ", mWidgetKeyFocus->GetName());
					mKeyHelper->SetCoord(mWidgetKeyFocus->GetAbsoluteCoord());
					mKeyHelper->SetVisible(true);
				}
				else
				{
					if (updateinfo)
						GUI::GUI_OUT("key focus : nullptr");
					mKeyHelper->SetVisible(false);
				}
			}
		}

	private:
		bool mFocusVisible;
		GUI::WidgetPtr mMouseHelper;
		GUI::WidgetPtr mKeyHelper;

		GUI::WidgetPtr mWidgetMouseFocus;
		GUI::WidgetPtr mWidgetKeyFocus;
		GUI::WidgetPtr mOldMouseFocus;
		GUI::WidgetPtr mOldKeyFocus;

	};

} // namespace diagnostic

#endif // __INPUT_FOCUS_INFO_H__
