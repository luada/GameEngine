#include "precompiled.h"
#include "WidgetTypes.h"

const std::string LogSection = "LayoutEditor";

INSTANCE_IMPLEMENT(WidgetTypes)

void WidgetTypes::Initialise()
{
	//loadTypes();
	GUI::ResourceManager::GetInstance().RegisterLoadXmlDelegate("Widgets") = GUI::NewDelegate(this, &WidgetTypes::LoadWidgets);
	GUI::ResourceManager::GetInstance().RegisterLoadXmlDelegate("Values") = GUI::NewDelegate(this, &WidgetTypes::LoadValues);
}

void WidgetTypes::Shutdown()
{
	for (std::vector<WidgetStyle*>::iterator iter = widget_types.begin(); iter != widget_types.end(); ++iter) delete *iter;
	widget_types.clear();
	for (std::vector<PossibleValue*>::iterator iter = possible_values.begin(); iter != possible_values.end(); ++iter) delete *iter;
	possible_values.clear();
}

WidgetStyle* WidgetTypes::Find(std::string type)
{
	for (std::vector<WidgetStyle*>::iterator iter = widget_types.begin(); iter != widget_types.end(); ++iter)
	{
		if ((*iter)->name == type)
		{
			return *iter;
		}
	}
	return Find("Widget");
}

std::vector<std::string> WidgetTypes::FindPossibleValues(std::string name)
{
	for (std::vector<PossibleValue*>::iterator iter = possible_values.begin(); iter != possible_values.end(); ++iter)
	{
		if ((*iter)->name == name)
		{
			return (*iter)->values;
		}
	}
	return std::vector<std::string>();
}

WidgetStyle * WidgetTypes::GetWidgetType(const std::string& name)
{
	
	for (VectorWidgetType::iterator iter=widget_types.begin(); iter!=widget_types.end(); ++iter)
	{
		if ((*iter)->name == name) return (*iter);
	}

	WidgetStyle * type = new WidgetStyle(name);
	widget_types.push_back(type);

	return type;
}

void WidgetTypes::AddWidgetSkinType(const std::string& type, const std::string& skin, const std::string& group, const std::string& button_name)
{
	WidgetStyle * widget_type = GetWidgetType(type);

	skin_groups[group.empty() ? DEFAULT_GOROUP_NAME : group].push_back(SkinInfo(skin, widget_type->name, button_name));
	widget_type->skin.push_back(skin);
}

void WidgetTypes::LoadWidgets(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version)
{
	GUI::xml::ElementEnumerator widgets = node->GetElementEnumerator();
	while (widgets.Next("Widget"))
	{
		WidgetStyle * widget_type = GetWidgetType(widgets->findAttribute("name"));

		
		GUI::xml::ElementEnumerator field = widgets->GetElementEnumerator();
		while (field.Next())
		{
			std::string key, value, group;

			if (field->GetName() == "Property")
			{
				if (!field->findAttribute("key", key)) continue;
				if (!field->findAttribute("value", value)) continue;
				field->findAttribute("group", group);
				if (key == "Skin")
				{
					std::string button_name = field->findAttribute("name");
					if (button_name.empty())
						button_name = value;

					if (group.empty()) group = DEFAULT_GOROUP_NAME;
					skin_groups[group].push_back(SkinInfo(value, widget_type->name, button_name));
					widget_type->skin.push_back(value);
				}
				else if (key == "DefaultSkin") widget_type->default_skin = value;
				else if (key == "Parent") widget_type->parent = GUI::utility::ParseBool(value);
				else if (key == "Child") widget_type->child = GUI::utility::ParseBool(value);
				else if (key == "Resizeable") widget_type->resizeable = GUI::utility::ParseBool(value);
				else if (key == "ItemManager") widget_type->many_items = GUI::utility::ParseBool(value);
				else if (key == "Base") widget_type->base = value;
			}
			else if (field->GetName() == "Parameter")
			{
				if (!field->findAttribute("key", key)) continue;
				if (!field->findAttribute("value", value)) continue;
				//widget_type->parameter.Insert(std::make_pair(key, value));
				widget_type->parameter.push_back(std::make_pair(key, value));
			}
		}

		if (widget_type->base.empty()) widget_type->base = "Widget";

	}
}

PossibleValue * WidgetTypes::GetPossibleValue(const std::string& name)
{

	PossibleValue * possible_value = nullptr;
	for (std::vector<PossibleValue*>::iterator iter=possible_values.begin(); iter!=possible_values.end(); ++iter)
	{
		if ((*iter)->name == name)
		{
			return (*iter);
		}
	}

	if (possible_value == nullptr)
	{
		possible_value = new PossibleValue();
		possible_value->name = name;
		possible_values.push_back(possible_value);
	}

	return possible_value;
}

void WidgetTypes::LoadValues(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version)
{
	GUI::xml::ElementEnumerator widgets = node->GetElementEnumerator();
	while (widgets.Next("Value"))
	{
		std::string name = widgets->findAttribute("name");
		PossibleValue * possible_value = GetPossibleValue(name);

		
		std::string merge = widgets->findAttribute("merge");
		
		if (merge == "add")
		{
		}
		
		else if (merge == "replace")
		{
			possible_value->values.clear();
		}

		
		GUI::xml::ElementEnumerator field = widgets->GetElementEnumerator();
		while (field.Next())
		{
			std::string key, value;

			if (field->GetName() == "Property")
			{
				if (!field->findAttribute("key", key)) continue;
				possible_value->values.push_back(GUI::LanguageManager::GetInstance().ReplaceTags(key));
			}

		}
	}

}

void WidgetTypes::ClearAllSkins()
{
	for (VectorWidgetType::iterator iter=widget_types.begin(); iter!=widget_types.end(); ++iter)
	{
		(*iter)->skin.clear();
	}

	skin_groups.clear();
}
