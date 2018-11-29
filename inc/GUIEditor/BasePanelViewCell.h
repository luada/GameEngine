#ifndef __BASE_PANEL_VIEW_CELL_H__
#define __BASE_PANEL_VIEW_CELL_H__

#include <GUI.h>
#include "BaseLayout.h"

namespace wraps
{

	class BasePanelViewCell : public BaseLayout
	{
	public:

		BasePanelViewCell(const std::string& layout, GUI::WidgetPtr parent) :
			BaseLayout(layout, parent),
			mTextCaption(nullptr),
			mWidgetClient(nullptr),
			m_minimized(false)
		{
			mMainWidget->SetPosition(0, 0);

			m_minHeight = mMainWidget->GetHeight() - GetClient()->GetHeight();
			m_maxHeight = mMainWidget->GetHeight();
		}

		virtual ~BasePanelViewCell()
		{
		}

		void SetCaption(const GUI::UString & caption)
		{
			if (mTextCaption) mTextCaption->SetCaption(caption);
		}

		GUI::WidgetPtr GetClient()
		{
			return mWidgetClient ? mWidgetClient : mMainWidget;
		}

		GUI::WidgetPtr GetMainWidget()
		{
			return mMainWidget;
		}

		void SetClientHeight(int height, bool smooth = true)
		{
			m_minHeight = mMainWidget->GetHeight() - GetClient()->GetHeight();
			m_maxHeight = m_minHeight + height;
			if (smooth)
			{
				if (!m_minimized)
				{
					UpdateMinimized();
				}
			}
			else
			{
				mMainWidget->SetSize(mMainWidget->GetWidth(), m_maxHeight);
				eventUpdatePanel(this);
			}
		}

		bool IsMinimized()
		{
			return m_minimized;
		}

		virtual void SetMinimized(bool minimized)
		{
			m_minimized = minimized;
			UpdateMinimized();
		}

		void SetVisible(bool visible) { mMainWidget->SetVisible(visible); }
		bool IsVisible() { return mMainWidget->IsVisible(); }

		GUI::delegates::CDelegate1<BasePanelViewCell*> eventUpdatePanel;

	private:
		void NotifyUpdateAction(GUI::WidgetPtr widget)
		{
			eventUpdatePanel(this);
		}

		void UpdateMinimized()
		{
			const float POSITION_CONTROLLER_TIME = 0.5f;
			if (!m_minimized)
			{
				GUI::IntSize size(mMainWidget->GetWidth(), m_maxHeight);
				GUI::ControllerPosition * controller = CreateControllerPosition(size, POSITION_CONTROLLER_TIME, GUI::NewDelegate(GUI::Action::InertionalMoveFunction));
				controller->eventUpdateAction = NewDelegate(this, &BasePanelViewCell::NotifyUpdateAction);
				GUI::ControllerManager::GetInstance().AddItem(mMainWidget, controller);
			}
			else
			{
				GUI::IntSize size(mMainWidget->GetWidth(), m_minHeight);
				GUI::ControllerPosition * controller = CreateControllerPosition(size, POSITION_CONTROLLER_TIME, GUI::NewDelegate(GUI::Action::InertionalMoveFunction));
				controller->eventUpdateAction = NewDelegate(this, &BasePanelViewCell::NotifyUpdateAction);
				GUI::ControllerManager::GetInstance().AddItem(mMainWidget, controller);
			}
		}

		GUI::ControllerPosition* CreateControllerPosition(const GUI::IntSize& size, float time, GUI::ControllerPosition::FrameAction::IDelegate* action)
		{
			GUI::ControllerItem* item = GUI::ControllerManager::GetInstance().CreateItem(GUI::ControllerPosition::GetClassTypeName());
			GUI::ControllerPosition* controller = item->CastType<GUI::ControllerPosition>();

			controller->SetSize(size);
			controller->SetTime(time);
			controller->SetAction(action);

			return controller;
		}

	protected:
		GUI::StaticTextPtr mTextCaption;
		GUI::WidgetPtr mWidgetClient;
		bool m_minimized;

		int m_minHeight;
		int m_maxHeight;
	};

} // namespace wraps

#endif // __BASE_PANEL_VIEW_CELL_H__
