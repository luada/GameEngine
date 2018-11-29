#ifndef __PANEL_VIEW_CELL_H__
#define __PANEL_VIEW_CELL_H__

#include "BasePanelViewItem.h"

//namespace demo
//{

	class PanelViewCell : public wraps::BasePanelViewCell
	{
	public:
		PanelViewCell(GUI::Widget* parent) : BasePanelViewCell("PanelCell.layout", parent)
		{
			AssignWidget(mTextCaption, "text_Caption");
			AssignWidget(mButtonMinimize, "button_Minimize");
			AssignWidget(mWidgetClient, "widget_Client");

			mTextCaption->eventMouseButtonDoubleClick = GUI::NewDelegate(this, &PanelViewCell::NotifyMouseButtonDoubleClick);
			mButtonMinimize->eventMouseButtonPressed = GUI::NewDelegate(this, &PanelViewCell::NotfyMouseButtonPressed);
		}

		virtual void SetMinimized(bool minimized)
		{
			wraps::BasePanelViewCell::SetMinimized(minimized);
			mButtonMinimize->SetButtonPressed(IsMinimized());
		}

	private:
		void NotfyMouseButtonPressed(GUI::Widget* sender, int left, int top, GUI::MouseButton id)
		{
			if (id == GUI::MouseButton::Left)
			{
				SetMinimized( ! IsMinimized() );
			}
		}

		void NotifyMouseButtonDoubleClick(GUI::Widget* sender)
		{
			SetMinimized( ! IsMinimized() );
		}

	private:
		GUI::Button* mButtonMinimize;

	};

//} // namespace demo

#endif // __PANEL_VIEW_CELL_H__
