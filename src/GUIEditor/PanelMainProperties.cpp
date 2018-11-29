#include "precompiled.h"
#include "PanelMainProperties.h"
#include "EditorWidgets.h"
#include "WidgetTypes.h"

extern const int PropertyItemHeight = 22;

PanelMainProperties::PanelMainProperties() : BasePanelViewItem("PanelMainProperties.layout"),
	current_widget(nullptr)
{
}

void PanelMainProperties::Initialise()
{
	mPanelCell->SetCaption(GUI::Localise("Main_properties"));

	AssignWidget(mButtonRelativePosition, "buttonRelativePosition");
	mButtonRelativePosition->eventMouseButtonClick = GUI::NewDelegate(this, &PanelMainProperties::NotifyToggleRelativeMode);
}

void PanelMainProperties::Shutdown()
{
}

void PanelMainProperties::NotifyToggleRelativeMode(GUI::Widget* sender)
{
	if (current_widget)
	{
		WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
		if (widgetContainer->relative_mode) mButtonRelativePosition->SetCaption(GUI::Localise("to_percents"));
		else mButtonRelativePosition->SetCaption(GUI::Localise("to_pixels"));
		widgetContainer->relative_mode = !widgetContainer->relative_mode;
		eventSetPositionText(widgetContainer->Position());
	}
}

void PanelMainProperties::Update(GUI::Widget* current)
{
	int y = 0;
	current_widget = current;

	WidgetStyle * widgetType = WidgetTypes::GetInstance().Find(current_widget->GetTypeName());
	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);

	eventCreatePair(mWidgetClient, "Name", widgetContainer->name, "Name", y);
	y += PropertyItemHeight;

	if (widgetType->resizeable)
	{
		// update caption of LayoutEditor_buttonRelativePosition
		mButtonRelativePosition->SetVisible(true);
		if (widgetContainer->relative_mode) mButtonRelativePosition->SetCaption(GUI::Localise("to_pixels"));
		else mButtonRelativePosition->SetCaption(GUI::Localise("to_percents"));

		eventCreatePair(mWidgetClient, "Position", widgetContainer->Position(), "Position", y);
		y += PropertyItemHeight;
	}
	else
	{
		mButtonRelativePosition->SetVisible(false);
	}

	eventCreatePair(mWidgetClient, "Align", widgetContainer->align, "Align", y);
	y += PropertyItemHeight;

	if (nullptr == current_widget->GetParent())
	{
		eventCreatePair(mWidgetClient, "Layer", widgetContainer->layer, "Layer", y);
		y += PropertyItemHeight;
	}

	if (widgetType->skin.size() > 1)
	{
		eventCreatePair(mWidgetClient, "Skin", widgetContainer->skin, "Skin", y);
		y += PropertyItemHeight;
	}

	mWidgetClient->_forcePeek(mButtonRelativePosition);
	mPanelCell->SetClientHeight(y);
}
