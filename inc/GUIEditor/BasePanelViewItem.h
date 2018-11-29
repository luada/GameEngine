#ifndef __BASE_PANEL_VIEW_ITEM_H__
#define __BASE_PANEL_VIEW_ITEM_H__

#include <GUI.h>
#include "BaseLayout.h"
#include "BasePanelViewCell.h"

namespace wraps
{

	class BasePanelViewItem : public wraps::BaseLayout
	{
	public:
		BasePanelViewItem(const std::string& layout) :
			BaseLayout("", nullptr),
			mLayout(layout)
		{
		}

		void _initialise(BasePanelViewCell * cell)
		{
			mPanelCell = cell;
			mWidgetClient = mPanelCell->GetClient();

			if ( ! mLayout.empty()) {
				BaseLayout::Initialise(mLayout, mWidgetClient);
				mMainWidget->SetCoord(0, 0, mWidgetClient->GetWidth(), mMainWidget->GetHeight());
				mPanelCell->SetClientHeight(mMainWidget->GetHeight(), false);
			}

			Initialise();
		}

		void _shutdown()
		{
			Shutdown();

			if ( ! mLayout.empty()) {
				BaseLayout::Shutdown();
			}

			mPanelCell = 0;
			mWidgetClient = nullptr;
		}

		
		virtual void NotifyChangeWidth(int width)
		{
		}

		virtual void SetVisible(bool visible)
		{
			mPanelCell->SetVisible(visible);
			mPanelCell->eventUpdatePanel(mPanelCell);
		}

		BasePanelViewCell * GetPanelCell() { return mPanelCell; }

	protected:
		virtual void Initialise() { }
		virtual void Shutdown() { }

	protected:
		BasePanelViewCell * mPanelCell;
		GUI::WidgetPtr mWidgetClient;
		std::string mLayout;
	};

} // namespace wraps

#endif // __BASE_PANEL_VIEW_ITEM_H__
