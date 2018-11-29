#ifndef __PANEL_ITEMS_H__
#define __PANEL_ITEMS_H__

#include "BaseLayout.h"
#include "BasePanelViewItem.h"

//#include <Ogre.h>

extern const int PropertyItemHeight;

class PanelItems : public wraps::BasePanelViewItem
{
public:

	PanelItems();

	virtual void Initialise();
	virtual void Shutdown();

	void Update(GUI::Widget* current);

	void NotifyRectangleDoubleClick(GUI::Widget* sender);

private:
	void AddSheetToTab(GUI::Widget* tab, std::string caption = "");
	void SyncItems(bool apply, bool add = false, std::string value = "");
	void NotifyAddItem(GUI::Widget* sender = 0);
	void NotifyDeleteItem(GUI::Widget* sender);
	void NotifySelectSheet(GUI::Widget* sender);
	void NotifyUpdateItem(GUI::Edit* widget);
	void NotifySelectItem(GUI::List* widget, size_t position);
	virtual void NotifyChangeWidth(int width);

	GUI::Edit* mEdit;
	GUI::List* mList;
	GUI::Button* mButtonAdd;
	GUI::Button* mButtonDelete;
	GUI::Button* mButtonSelect;

	GUI::Widget* current_widget;

	int mButtonLeft, mButtonRight, mButtonSpace;
};

#endif // __PANEL_ITEMS_H__
