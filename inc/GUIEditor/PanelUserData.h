#ifndef __PANEL_USER_DATA_H__
#define __PANEL_USER_DATA_H__

#include "BaseLayout.h"
#include "BasePanelViewItem.h"

extern const int PropertyItemHeight;

class PanelUserData : public wraps::BasePanelViewItem
{
public:

	PanelUserData();

	virtual void Initialise();
	virtual void Shutdown();

	void Update(GUI::Widget* current);

private:
	virtual void NotifyChangeWidth(int width);

	void NotifyAddUserData(GUI::Widget* sender = 0);
	void NotifyDeleteUserData(GUI::Widget* sender);
	void NotifyUpdateUserData(GUI::Edit* widget);
	void NotifySelectUserDataItem(GUI::MultiList* widget, size_t index);

	GUI::Edit* mEditKey;
	GUI::Edit* mEditValue;
	GUI::Button* mButtonAdd;
	GUI::Button* mButtonDelete;
	GUI::MultiList* mMultilist;

	GUI::Widget* current_widget;

	int mEditLeft, mEditRight, mEditSpace;
	int mButtonLeft, mButtonRight, mButtonSpace;
};

#endif // __PANEL_USER_DATA_H__
