#ifndef __PANEL_MAIN_PROPERTIES_H__
#define __PANEL_MAIN_PROPERTIES_H__

#include "BaseLayout.h"
#include "BasePanelViewItem.h"
//#include <Ogre.h>

extern const int PropertyItemHeight;

class PanelMainProperties : public wraps::BasePanelViewItem
{
public:

	PanelMainProperties();

	virtual void Initialise();
	virtual void Shutdown();

	void NotifyToggleRelativeMode(GUI::Widget* sender = nullptr);
	void Update(GUI::Widget* current);

	typedef GUI::delegates::CDelegate5<GUI::Widget*, const std::string&, const std::string&, const std::string&, int> EventHandle_EventCreatePair;
	EventHandle_EventCreatePair eventCreatePair;
	typedef GUI::delegates::CDelegate1<const std::string&> EventHandle_EventSetPositionText;
	EventHandle_EventSetPositionText eventSetPositionText;

	GUI::Widget* GetMainWidget() { return mWidgetClient; }
private:
	GUI::Button* mButtonRelativePosition;

	GUI::Widget* current_widget;
};

#endif // __PANEL_MAIN_PROPERTIES_H__
