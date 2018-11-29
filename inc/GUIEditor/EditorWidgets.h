#ifndef __EDITOR_WIDGETS_H__
#define __EDITOR_WIDGETS_H__

#include <sstream>
#include "WidgetContainer.h"

void MapSet(StringPairs & map, const std::string &_key, const std::string &_value);
StringPairs::iterator MapFind(StringPairs & map, const std::string &_key);
void MapErase(StringPairs & map, const std::string &_key);


GUI::IntCoord ConvertCoordToParentCoord(const GUI::IntCoord& coord, GUI::Widget* widget);

class EditorWidgets
{
	//INSTANCE_HEADER(EditorWidgets);
	private:
		static EditorWidgets* msInstance;
		bool mIsInitialise;
	public:
		EditorWidgets();
		~EditorWidgets();
		static EditorWidgets& GetInstance();
		static EditorWidgets* GetInstancePtr();

public:
	void Initialise();
	void Shutdown();
	bool Load(const GUI::UString& fileName);
	bool Save(const GUI::UString& fileName);
	void LoadxmlDocument(GUI::xml::Document * doc, bool test = false);
	GUI::xml::Document * SavexmlDocument();
	WidgetContainer * Find(GUI::Widget* widget);
	WidgetContainer * Find(const std::string& name);
	void Add(WidgetContainer * container);
	void Remove(GUI::Widget* widget);
	void Remove(WidgetContainer * container);
	void Clear();

	bool TryToApplyProperty(GUI::Widget* widget, const std::string& key, const std::string& value, bool test = false);

	std::vector<WidgetContainer*> widgets;
	int global_counter;
	bool widgets_changed;
private:
	WidgetContainer * _find(GUI::Widget* widget, const std::string& name, std::vector<WidgetContainer*> widgets);

	void ParseWidget(GUI::xml::ElementEnumerator & widget, GUI::Widget* parent, bool test = false);
	void SerialiseWidget(WidgetContainer * container, GUI::xml::ElementPtr node);

	void LoadIgnoreParameters(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version);

	std::vector<std::string> ignore_parameters;
};

#endif // __EDITOR_WIDGETS_H__
