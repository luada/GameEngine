#ifndef __WIDGET_CONTAINER_H__
#define __WIDGET_CONTAINER_H__

#include "GUI.h"
//#include <Ogre.h>

typedef std::vector<std::pair<std::string, std::string> > StringPairs;

const std::string DEFAULT_EDITOR_LAYER = "LayoutEditor_Widgets";
const std::string DEFAULT_LAYER = "Back";

struct ControllerInfo
{
	std::string mType;
	GUI::MapString mProperty;
};

struct WidgetContainer
{
	WidgetContainer():
		relative_mode(false)
	{ }
	WidgetContainer(const std::string& type, const std::string& skin, GUI::Widget* widget, const std::string& name = ""):
		widget(widget),
		type(type),
		skin(skin),
		name(name),
		layer(""),
		relative_mode(false)
	{ }

	GUI::Widget* widget;
	std::vector<WidgetContainer*> childContainers;
	StringPairs mProperty;
	StringPairs mUserString;
	std::vector<ControllerInfo*> mController;
	std::string type;
	std::string skin;
	std::string align;
	std::string name;
	std::string layer;
	// not for saving
	std::string Position(bool percent = true)
	{
		if (relative_mode)
		{
			GUI::FloatCoord coord = GUI::CoordConverter::ConvertToRelative(widget->GetCoord(), widget->GetCroppedParent() == nullptr ? GUI::Gui::GetInstance().GetViewSize() : widget->GetCroppedParent()->GetSize());
			std::ostringstream stream;
			if (percent) stream << coord.left*100 << " " << coord.top*100 << " " << coord.width*100 << " " << coord.height*100;
			else stream << coord.left << " " << coord.top << " " << coord.width << " " << coord.height;
			return stream.str();
		}
		return widget->GetCoord().Print();
	}
	bool relative_mode;
};

#endif // __WIDGET_CONTAINER_H__
