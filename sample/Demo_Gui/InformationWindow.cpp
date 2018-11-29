#include "precompiled.h"
#include "InformationWindow.h"

namespace demo
{

	InformationWindow::InformationWindow(GUI::Widget* parent) : BaseLayout("InformationWindow.layout", parent),
		mFocus(nullptr)
	{
		AssignWidget(mInfo, "Info");

		GUI::Gui::GetInstance().eventFrameStart += GUI::NewDelegate(this, &InformationWindow::NotifyFrameStart);

		if (parent)
		{
			const GUI::IntCoord& coord = parent->GetClientCoord();
			const GUI::IntSize& size = mMainWidget->GetSize();
			mMainWidget->SetPosition(GUI::IntPoint(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height)));
		}

	}

	InformationWindow::~InformationWindow()
	{
		GUI::Gui::GetInstance().eventFrameStart -= GUI::NewDelegate(this, &InformationWindow::NotifyFrameStart);
	}

	int InformationWindow::GetRand(int min, int max)
	{
		if (max < min) std::swap(max, min);
		int range = max - min;
		if (range == 0) return 0;
		int result = ::rand() % range;
		if (result < 0) result = -result;
		return min + result;
	}

	void InformationWindow::NotifyFrameStart(float time)
	{
		GUI::Widget* focus = GUI::InputManager::GetInstance().GetMouseFocusWidget();
		if (focus == mFocus) return;
		mFocus = focus;

		const std::string tag = "Info";
		std::string info;
		if (mFocus != nullptr)
		{
			while (true)
			{
				if (focus->IsUserString(tag))
				{
					info = focus->GetUserString(tag);
					break;
				}
				if (!focus->GetParent())
				{
					break;
				}
				focus = focus->GetParent();
			}
		}

		mInfo->SetCaption(info);
	}

} // namespace demo
