#ifndef __PROPERTIES_PANEL_VIEW_H__
#define __PROPERTIES_PANEL_VIEW_H__

//#include "PanelView.h"
//#include "PanelViewWindow.h"
#include "BaseLayout.h"
#include "PanelView.h"
#include "PanelMainProperties.h"
#include "PanelProperties.h"
#include "PanelItems.h"
#include "PanelUserData.h"
#include "PanelControllers.h"

extern int grid_step;//FIXME_HOOK

class PropertiesPanelView : public wraps::BaseLayout
{
public:
	PropertiesPanelView();
	virtual ~PropertiesPanelView();

	void Load(GUI::xml::ElementEnumerator field);
	void Save(GUI::xml::ElementPtr root);
	void Update(GUI::Widget* current);

	// widget editing
	void NotifyRectangleResize(GUI::Window* sender);
	void NotifyRectangleKeyPressed(GUI::Widget* sender, GUI::KeyCode key, GUI::Char _char);


	void HideWidgetsPairs(GUI::Widget* window);
	void CreatePropertiesWidgetsPair(GUI::Widget* window, const std::string& property, const std::string& value, const std::string& type, int y);
	GUI::Window* GetWidgetRectangle() { return current_widget_rectangle; }

	void SetPositionText(const std::string& caption);
	void ToggleRelativeMode() { mPanelMainProperties->NotifyToggleRelativeMode(); }

	typedef GUI::delegates::CDelegate0 EventInfo;
	EventInfo eventRecreate;

	GUI::Widget* GetMainWidget() { return mMainWidget; }

private:
	void NotifyWindowChangeCoord(GUI::Window* sender);
	bool CheckType(GUI::Edit* edit, const std::string& type);
	void NotifyApplyProperties(GUI::Widget* sender, bool force);
	void NotifyTryApplyProperties(GUI::Edit* sender); // calls notifyApplyProperties
	void NotifyForceApplyProperties(GUI::Edit* widget); // calls notifyApplyProperties
	void NotifyForceApplyProperties2(GUI::ComboBox* widget, size_t index); // calls notifyApplyProperties

	std::string SplitString(std::string& str, char separator);
private:
	GUI::IntSize mOldSize;
	PanelView* mPanelView;

	// properties window
	size_t mPairsCounter;
	std::map<GUI::Widget*, std::vector<GUI::StaticText*> > mPropertiesText;
	std::map<GUI::Widget*, GUI::VectorWidgetPtr> mPropertiesElement;

	PanelMainProperties * mPanelMainProperties;
	PanelProperties * mPanelTypeProperties;
	PanelProperties * mPanelGeneralProperties;
	PanelItems * mPanelItems;
	PanelUserData * mPanelUserData;
	PanelControllers * mPanelControllers;

	typedef std::vector<wraps::BasePanelViewItem*> VectorPanel;
	VectorPanel mPanels;

	GUI::Widget* current_widget;
	GUI::Window* current_widget_rectangle;

	// widget was moved by keyboard arrows
	bool arrow_move;
};

#endif // __PROPERTIES_PANEL_VIEW_H__
