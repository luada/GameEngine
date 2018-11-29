#ifndef __PANEL_VIEW_H__
#define __PANEL_VIEW_H__

#include "BasePanelView.h"
#include "PanelViewCell.h"

//namespace demo
//{

	class PanelView : public wraps::BasePanelView<PanelViewCell>
	{
	public:
		PanelView(GUI::Widget* parent) : wraps::BasePanelView<PanelViewCell>("", parent) { }

	};

//} // namespace demo

#endif // __PANEL_VIEW_H__
