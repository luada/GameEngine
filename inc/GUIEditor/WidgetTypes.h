#ifndef __WIDGET_TYPES_H__
#define __WIDGET_TYPES_H__

struct SkinInfo
{
	SkinInfo(const std::string& widget_skin, const std::string& widget_type, const std::string& widget_button_name) :
		widget_skin(widget_skin), widget_type(widget_type), widget_button_name(widget_button_name) { }
	std::string widget_skin;
	std::string widget_type;
	std::string widget_button_name;
};
typedef std::vector<SkinInfo> VectorSkinInfo;
typedef std::map<std::string, VectorSkinInfo> SkinGroups;

typedef std::pair<std::string, std::string> PairString;
typedef std::vector<PairString> StringPairs;

const std::string DEFAULT_GOROUP_NAME = "Default";

struct WidgetStyle
{
	WidgetStyle(const std::string& name) : name(name), parent(false), child(true), resizeable(true), many_items(false) { }
	std::string name;
	std::string base;
	std::vector<std::string> skin;
	std::string default_skin;
	StringPairs parameter;
	// can have child widgets
	bool parent;
	// can have farent
	bool child;
	// can be selected
	bool resizeable;
	// have many items (such as List, ComboBox, Tab, MenuBar, etc...)
	bool many_items;
};

struct PossibleValue{
	std::string name;
	std::vector<std::string> values;
};

class WidgetTypes
{
	INSTANCE_HEADER(WidgetTypes)

public:
	void Initialise();
	void Shutdown();
	WidgetStyle* Find(std::string type);
	std::vector<std::string> FindPossibleValues(std::string name);

	void ClearAllSkins();

	typedef std::vector<WidgetStyle*> VectorWidgetType;
	VectorWidgetType widget_types;

	std::vector<PossibleValue*> possible_values;
	SkinGroups skin_groups;

	void AddWidgetSkinType(const std::string& type, const std::string& skin, const std::string& group, const std::string& button_name);

private:
	//void LoadTypes();
	void LoadWidgets(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version);
	void LoadValues(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version);

	WidgetStyle * GetWidgetType(const std::string& name);

	PossibleValue * GetPossibleValue(const std::string& name);

};

#endif // __WIDGET_TYPES_H__
