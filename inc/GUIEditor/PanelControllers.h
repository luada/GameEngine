#ifndef __PANEL_CONTROLLERS_H__
#define __PANEL_CONTROLLERS_H__

#include "BaseLayout.h"
#include "BasePanelViewItem.h"

extern const int PropertyItemHeight;

class PanelControllers : public wraps::BasePanelViewItem
{
public:

	PanelControllers();

	virtual void Initialise();
	virtual void Shutdown();

	void Update(GUI::Widget* current);

	typedef GUI::delegates::CDelegate5<GUI::Widget*, const std::string&, const std::string&, const std::string&, int> EventHandle_EventCreatePair;
	EventHandle_EventCreatePair eventCreatePair;
	GUI::EventHandle_WidgetVoid eventHidePairs;
private:
	virtual void NotifyChangeWidth(int width);

	void NotifyAdd(GUI::Widget* sender = 0);
	void NotifyDelete(GUI::Widget* sender);
	void NotifySelectItem(GUI::List* sender, size_t index);

	void LoadControllerTypes(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version);

	GUI::ComboBox* mControllerName;
	GUI::Button* mButtonAdd;
	GUI::Button* mButtonDelete;
	GUI::List* mList;

	GUI::Widget* current_widget;

	int mButtonLeft, mButtonRight, mButtonSpace;

	std::map<std::string, GUI::MapString> mControllersProperties;
};

#endif // __PANEL_CONTROLLERS_H__
