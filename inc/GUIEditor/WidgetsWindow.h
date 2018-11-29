#ifndef __WIDGETS_WINDOW_H__
#define __WIDGETS_WINDOW_H__

#include "BaseLayout.h"

class WidgetsWindow : public wraps::BaseLayout
{
public:
	WidgetsWindow();

	void Initialise();

	void Load(GUI::xml::ElementEnumerator field);
	void Save(GUI::xml::ElementPtr root);
	void Update(GUI::Widget* current) { current_widget = current; }

	void ClearAllSheets();

	void ClearNewWidget();
	void StartNewWidget(int x1, int y1, GUI::MouseButton id);
	void CreateNewWidget(int x2, int y2);
	void FinishNewWidget(int x2, int y2);

	int GetCreatingStatus() { return creating_status; }

	GUI::EventHandle_WidgetVoid eventSelectWidget;
	GUI::EventHandle_WidgetToolTip eventToolTip;

	GUI::Widget* GetMainWidget() { return mMainWidget; }

private:
	void NotifyToolTip(GUI::Widget* sender, const GUI::ToolTipInfo & info) { eventToolTip(sender, info); }
	void NotifySelectWidgetType(GUI::Widget* sender);
	void NotifySelectWidgetTypeDoubleclick(GUI::Widget* sender);

	void UpdateSize();

private:
	GUI::Tab* mTabSkins;

	int widgetsButtonWidth;
	int widgetsButtonHeight;
	int widgetsButtonsInOneLine;
	std::string skinSheetName;

	GUI::Widget* current_widget;

	// info for new widget
	int mX1, mY1, mX2, mY2;
	// 0 - none, 1 - mouse pressed (prepare), 2 - mouse moved (widget created)
	int creating_status;

	std::string new_widget_type;
	std::string new_widget_skin;
	int mMaxLines;
};

#endif // __WIDGETS_WINDOW_H__
