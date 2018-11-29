#include "precompiled.h"
#include "PanelProperties.h"
#include "EditorWidgets.h"

PanelProperties::PanelProperties() : BasePanelViewItem("PanelProperties.layout")
{
}

void PanelProperties::Initialise()
{
	mPanelCell->SetCaption(GUI::Localise("Widget_type_propertes"));
}

void PanelProperties::Shutdown()
{
}

size_t PanelProperties::AddParametrs(WidgetStyle * widgetType, WidgetContainer * widgetContainer, int& y)
{
	size_t count = widgetType->parameter.size();

	for (StringPairs::iterator iter = widgetType->parameter.begin(); iter != widgetType->parameter.end(); ++iter)
	{
		std::string value = "";
		for (StringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
		{
			if (iterProperty->first == iter->first)
			{
				value = iterProperty->second;
				break;
			}
		}
		eventCreatePair(mWidgetClient, iter->first, value, iter->second, y);
		y += PropertyItemHeight;
	}

	if (widgetType->base != "Widget")
	{
		widgetType = WidgetTypes::GetInstance().Find(widgetType->base);
		count += AddParametrs(widgetType, widgetContainer, y);
	}

	return count;
}

void PanelProperties::Update(GUI::Widget* current, PropertiesGroup group)
{
	int y = 0;

	WidgetStyle * widgetType = WidgetTypes::GetInstance().Find(current->GetTypeName());
	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current);

	if (group == TYPE_PROPERTIES)
	{
		GUI::LanguageManager::GetInstance().AddUserTag("widget_type", current->GetTypeName());
		if (widgetType->name == "Widget")
		{
			if (current->GetTypeName() != "Widget")
			{
				mPanelCell->SetCaption(GUI::LanguageManager::GetInstance().ReplaceTags(GUI::Localise("Properties_not_available")));
				y += PropertyItemHeight;
			}
			else
			{
				SetVisible(false);
			}
		}
		else
		{
			mPanelCell->SetCaption(GUI::LanguageManager::GetInstance().ReplaceTags(GUI::Localise("Widget_type_propertes")));

			size_t count = AddParametrs(widgetType, widgetContainer, y);

			SetVisible( count > 0 );
		}
	}
	else if (group == WIDGET_PROPERTIES)
	{
		mPanelCell->SetCaption(GUI::Localise("Other_properties"));

		if (current->GetTypeName() != "TabItem" &&
			current->GetTypeName() != GUI::TabItem::GetClassTypeName())
		{
			SetVisible(true);
			//base properties (from Widget)
			WidgetStyle * baseType = WidgetTypes::GetInstance().Find("Widget");
			for (StringPairs::iterator iter = baseType->parameter.begin(); iter != baseType->parameter.end(); ++iter)
			{
				std::string value = "";
				for (StringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
				{
					if (iterProperty->first == iter->first)
					{
						value = iterProperty->second;
						break;
					}
				}

				eventCreatePair(mWidgetClient, iter->first, value, iter->second, y);
				y += PropertyItemHeight;
			}
		}
		else
		{
			SetVisible(false);
		}
	}

	mPanelCell->SetClientHeight(y);
}
