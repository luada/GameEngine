#ifndef __PANEL_PROPERTIES_H__
#define __PANEL_PROPERTIES_H__

#include "BaseLayout.h"
#include "BasePanelViewItem.h"
#include "WidgetTypes.h"
#include "WidgetContainer.h"

extern const int PropertyItemHeight;

class PanelProperties : public wraps::BasePanelViewItem
{
public:

	PanelProperties();

	virtual void Initialise();
	virtual void Shutdown();

	enum PropertiesGroup { TYPE_PROPERTIES, WIDGET_PROPERTIES };
	void Update(GUI::Widget* current_widget, PropertiesGroup group);

	typedef GUI::delegates::CDelegate5<GUI::Widget*, const std::string&, const std::string&, const std::string&, int> EventHandle_EventCreatePair;
	EventHandle_EventCreatePair eventCreatePair;

private:
	size_t AddParametrs(WidgetStyle * widgetType, WidgetContainer * widgetContainer, int& y);

};

#endif // __PANEL_PROPERTIES_H__
