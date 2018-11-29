#include "precompiled.h"
#include "EditorWidgets.h"
//#include "BasisManager.h"
#include "WidgetTypes.h"
#include "GroupMessage.h"

const std::string LogSection = "LayoutEditor";

//INSTANCE_IMPLEMENT(EditorWidgets)
const std::string INSTANCE_TYPE_NAME("EditorWidgets");
EditorWidgets* EditorWidgets::msInstance = nullptr;
EditorWidgets* EditorWidgets::GetInstancePtr() { return msInstance; }
EditorWidgets& EditorWidgets::GetInstance() { ASSERT(0 != msInstance, "instance " << INSTANCE_TYPE_NAME << " was not created"); return (*msInstance); }
EditorWidgets::EditorWidgets() :
	mIsInitialise(false),
	global_counter(0),
	widgets_changed(false)
{
	ASSERT(0 == msInstance, "instance " << INSTANCE_TYPE_NAME << " is exsist");
	msInstance = this;
}
EditorWidgets::~EditorWidgets()
{
	msInstance = nullptr;
}

void MapSet(StringPairs & map, const std::string &_key, const std::string &_value)
{
	bool find = false;
	for (StringPairs::iterator iter=map.begin(); iter!=map.end(); ++iter)
	{
		if (iter->first == _key)
		{
			iter->second = _value;
			find = true;
		}
	}
	if (!find)
	{
		map.push_back(std::make_pair(_key, _value));
	}
}

StringPairs::iterator MapFind(StringPairs & map, const std::string &_key)
{
	StringPairs::iterator iter = map.begin();
	for (; iter!=map.end(); ++iter)
	{
		if (iter->first == _key) break;
	}
	return iter;
}

void MapErase(StringPairs & map, const std::string &_key)
{
	for (StringPairs::iterator iter = map.begin(); iter != map.end(); ++iter)
	{
		if (iter->first == _key)
		{
			map.erase(iter);
			return;
		}
	}
}

GUI::IntCoord ConvertCoordToParentCoord(const GUI::IntCoord& coord, GUI::Widget* widget)
{
	GUI::IntCoord curCoord = coord;
	GUI::Widget* parent = widget->GetParent();
	while (nullptr != parent)
	{
		curCoord = curCoord - parent->GetPosition();
		
		parent = parent->GetParent();
	}
	return curCoord;
}

void EditorWidgets::Initialise()
{
	global_counter = 0;
	widgets_changed = true;

	GUI::ResourceManager::GetInstance().RegisterLoadXmlDelegate("IgnoreParameters") = GUI::NewDelegate(this, &EditorWidgets::LoadIgnoreParameters);
}

void EditorWidgets::Shutdown()
{
	for (std::vector<WidgetContainer*>::iterator iter = widgets.begin(); iter != widgets.end(); ++iter) delete *iter;
	widgets.clear();
}

bool EditorWidgets::Load(const GUI::UString& fileName)
{
	std::string _instance = "Editor";

	GUI::xml::Document doc;
	if (!doc.Open(fileName))
	{
		LOGGING(LogSection, Error, _instance << " : " << doc.GetLastError());
		return false;
	}

	GUI::xml::ElementPtr root = doc.GetRoot();
	if ( (nullptr == root) || (root->GetName() != "GUI") )
	{
		LOGGING(LogSection, Error, _instance << " : '" << fileName << "', tag 'GUI' not found");
		return false;
	}

	std::string type;
	if (root->findAttribute("type", type))
	{
		if (type == "Layout")
		{
			
			GUI::xml::ElementEnumerator widget = root->GetElementEnumerator();
			while (widget.Next("Widget")) ParseWidget(widget, 0);
		}
		else
		{
			return false;
		}
	}

	widgets_changed = true;
	return true;
}

bool EditorWidgets::Save(const GUI::UString& fileName)
{
	std::string _instance = "Editor";

	GUI::xml::Document doc;
	doc.CreateDeclaration();
	GUI::xml::ElementPtr root = doc.CreateRoot("GUI");
	root->AddAttribute("type", "Layout");

	for (std::vector<WidgetContainer*>::iterator iter = widgets.begin(); iter != widgets.end(); ++iter)
	{
		
		if (nullptr == (*iter)->widget->GetParent()) SerialiseWidget(*iter, root);
	}

	if (!doc.Save(fileName))
	{
		LOGGING(LogSection, Error, _instance << " : " << doc.GetLastError());
		return false;
	}

	return true;
}

void EditorWidgets::LoadxmlDocument(GUI::xml::Document * doc, bool test)
{
	GUI::xml::ElementPtr root = doc->GetRoot();

	std::string type;
	if (root->findAttribute("type", type))
	{
		if (type == "Layout")
		{
			
			GUI::xml::ElementEnumerator widget = root->GetElementEnumerator();
			while (widget.Next("Widget")) ParseWidget(widget, 0, test);
		}
	}
	widgets_changed = true;
}

GUI::xml::Document * EditorWidgets::SavexmlDocument()
{
	GUI::xml::Document * doc = new GUI::xml::Document();

	doc->CreateDeclaration();
	GUI::xml::ElementPtr root = doc->CreateRoot("GUI");
	root->AddAttribute("type", "Layout");

	for (std::vector<WidgetContainer*>::iterator iter = widgets.begin(); iter != widgets.end(); ++iter)
	{
		
		if (nullptr == (*iter)->widget->GetParent()) SerialiseWidget(*iter, root);
	}

	return doc;
}

void EditorWidgets::Add(WidgetContainer * container)
{
	if (nullptr == container->widget->GetParent())
	{
		if ("" == container->layer) container->layer = DEFAULT_LAYER;
		widgets.push_back(container);
	}
	else
	{
		GUI::Widget* parent = container->widget->GetParent();
		WidgetContainer * containerParent = Find(parent);
		while (NULL == containerParent)
		{
			parent = parent->GetParent();
			if (parent == nullptr) return;
			containerParent = Find(parent);
		}
		containerParent->childContainers.push_back(container);
	}
	widgets_changed = true;
}

void EditorWidgets::Remove(GUI::Widget* widget)
{
	Remove(Find(widget));
	widgets_changed = true;
}

void EditorWidgets::Remove(WidgetContainer * container)
{
	std::vector<WidgetContainer*>::reverse_iterator iter;
	while (container->childContainers.empty() == false)
	{
		iter = container->childContainers.rbegin();
		Remove(*iter);
	}

	if (nullptr != container)
	{
		if (nullptr == container->widget->GetParent())
		{
			widgets.erase(std::find(widgets.begin(), widgets.end(), container));
		}
		else
		{
			GUI::Widget* parent = container->widget->GetParent();
			WidgetContainer * containerParent = Find(parent);
			while (NULL == containerParent)
			{
				parent = parent->GetParent();
				if (parent == nullptr) return;
				containerParent = Find(parent);
			}

			containerParent->childContainers.erase(std::find(containerParent->childContainers.begin(), containerParent->childContainers.end(), container));
		}

		GUI::Gui::GetInstance().DestroyWidget(container->widget);

		delete container;
	}
	widgets_changed = true;
}

void EditorWidgets::Clear()
{
	while (!widgets.empty())
	{
		Remove(widgets[widgets.size()-1]);
	}
	global_counter = 0;
}

WidgetContainer * EditorWidgets::Find(GUI::Widget* widget)
{
	return _find(widget, "", widgets);
}

WidgetContainer * EditorWidgets::Find(const std::string& name)
{
	return _find(NULL, name, widgets);
}

WidgetContainer * EditorWidgets::_find(GUI::Widget* widget, const std::string& name, std::vector<WidgetContainer*> widgets)
{
	for (std::vector<WidgetContainer*>::iterator iter = widgets.begin(); iter != widgets.end(); ++iter)
	{
		if (((*iter)->widget == widget) || ((name.empty() == false) && ((*iter)->name == name)))
		{
			return *iter;
		}
		WidgetContainer * retContainer = _find(widget, name, (*iter)->childContainers);
		if (retContainer) return retContainer;
	}
	return nullptr;
}

void EditorWidgets::ParseWidget(GUI::xml::ElementEnumerator & widget, GUI::Widget* parent, bool test)
{
	WidgetContainer * container = new WidgetContainer();
	
	GUI::IntCoord coord;
	GUI::Align align = GUI::Align::Default;
	std::string position;
	//std::string layer;

	widget->findAttribute("name", container->name);
	widget->findAttribute("type", container->type);
	widget->findAttribute("skin", container->skin);
	widget->findAttribute("layer", container->layer);
	if (widget->findAttribute("align", container->align)) align = GUI::Align::Parse(container->align);
	if (widget->findAttribute("position", position)) coord = GUI::IntCoord::Parse(position);
	if (widget->findAttribute("position_real", position))
	{
		container->relative_mode = true;
		
		coord = GUI::CoordConverter::ConvertFromRelative(GUI::FloatCoord::Parse(position), parent == nullptr ? GUI::Gui::GetInstance().GetViewSize() : parent->GetSize());
	}

	
	if (!container->name.empty())
	{
		WidgetContainer * iter = Find(container->name);
		if (nullptr != iter)
		{
			static long renameN=0;
			// FIXME : not translated string
			std::string mess = GUI::utility::ToString("Widget with name '", container->name, "' already exist. Renamed to '", container->name, renameN, "'.");
			LOGGING(LogSection, warning, mess);
			GroupMessage::GetInstance().AddMessage(mess, GUI::LogManager::warning);
			container->name = GUI::utility::ToString(container->name, renameN++);
		}
	}

	std::string tmpname = container->name;
	if (tmpname.empty())
	{
		tmpname = GUI::utility::ToString(container->type, global_counter);
		global_counter++;
	}

	
	tmpname = "LayoutEditorWidget_" + tmpname;

	
	std::string skin = container->skin;
	bool exist = GUI::SkinManager::GetInstance().IsExist(container->skin);
	if ( !exist && !container->skin.empty())
	{
		skin = WidgetTypes::GetInstance().Find(container->type)->default_skin;
		std::string tmp;
		if (skin.empty()) tmp = "empty skin";
		else  tmp = "'" + skin + "'";
		// FIXME : not translated string
		std::string mess = GUI::utility::ToString("'", container->skin, "' skin not found , temporary changed to ", tmp);
		GroupMessage::GetInstance().AddMessage(mess, GUI::LogManager::Error);
	}

	if (nullptr == parent)
	{
		container->widget = GUI::Gui::GetInstance().CreateWidgetT(container->type, skin, coord, align, DEFAULT_EDITOR_LAYER/*layer*/, tmpname);
	}
	else
	{
		container->widget = parent->CreateWidgetT(container->type, skin, coord, align, tmpname);
	}

	Add(container);

	
	GUI::xml::ElementEnumerator curWidget = widget->GetElementEnumerator();
	while (curWidget.Next())
	{
		std::string key, value, type;

		if (curWidget->GetName() == "Widget") ParseWidget(curWidget, container->widget, test);
		else if (curWidget->GetName() == "Property")
		{
			
			if (!curWidget->findAttribute("key", key)) continue;
			if (!curWidget->findAttribute("value", value)) continue;

			
			if ( TryToApplyProperty(container->widget, key, value, test) == false ) continue;

			container->mProperty.push_back(std::make_pair(key, value));
		}
		else if (curWidget->GetName() == "UserString")
		{
			
			if (!curWidget->findAttribute("key", key)) continue;
			if (!curWidget->findAttribute("value", value)) continue;
			//container->mUserString.Insert(std::make_pair(key, value));
			container->mUserString.push_back(std::make_pair(key, value));
		}
		else if (curWidget->GetName() == "Controller")
		{
			
			if (!curWidget->findAttribute("type", type)) continue;
			ControllerInfo* controllerInfo = new ControllerInfo();
			controllerInfo->mType = type;

			GUI::ControllerItem* item = nullptr;
			if (test)
			{
				item = GUI::ControllerManager::GetInstance().CreateItem(type);
			}

			GUI::xml::ElementEnumerator prop = curWidget->GetElementEnumerator();
			while (prop.Next("Property"))
			{
				if (!prop->findAttribute("key", key)) continue;
				if (!prop->findAttribute("value", value)) continue;
				controllerInfo->mProperty[key] = value;
				if (item)
				{
					item->SetProperty(key, value);
				}
			}
			if (item)
			{
				GUI::ControllerManager::GetInstance().AddItem(container->widget, item);
			}

			container->mController.push_back(controllerInfo);
		}

	};
}

bool EditorWidgets::TryToApplyProperty(GUI::Widget* widget, const std::string& key, const std::string& value, bool test)
{
 	try
	{
		if (key == "Image_Texture")
		{
			if (!GUI::DataManager::GetInstance().IsDataExist(value))
			{
				GroupMessage::GetInstance().AddMessage("No such " + key + ": '" + value + "'. This curValue will be saved.", GUI::LogManager::warning);
				return true;
			}
		}

		if (test || std::find(ignore_parameters.begin(), ignore_parameters.end(), key) == ignore_parameters.end())
		{
			widget->SetProperty(key, value);
		}
		
		//Ogre::Root::GetSingleton().RenderOneFrame();
	}
	catch(...)
	{
		GroupMessage::GetInstance().AddMessage("Can't apply '" + key + "'property.", GUI::LogManager::Error);
		return false;
	}
	return true;
}

void EditorWidgets::SerialiseWidget(WidgetContainer * container, GUI::xml::ElementPtr node)
{
	GUI::xml::ElementPtr curNode = node->CreateChild("Widget");

	curNode->AddAttribute("type", container->type);
	curNode->AddAttribute("skin", container->skin);
	if (!container->relative_mode) curNode->AddAttribute("position", container->Position());
	else curNode->AddAttribute("position_real", container->Position(false));
	if ("" != container->align) curNode->AddAttribute("align", container->align);
	if ("" != container->layer) curNode->AddAttribute("layer", container->layer);
	if ("" != container->name) curNode->AddAttribute("name", container->name);

	for (StringPairs::iterator iter = container->mProperty.begin(); iter != container->mProperty.end(); ++iter)
	{
		GUI::xml::ElementPtr nodeProp = curNode->CreateChild("Property");
		nodeProp->AddAttribute("key", iter->first);
		nodeProp->AddAttribute("value", iter->second);
	}

	for (StringPairs::iterator iter = container->mUserString.begin(); iter != container->mUserString.end(); ++iter)
	{
		GUI::xml::ElementPtr nodeProp = curNode->CreateChild("UserString");
		nodeProp->AddAttribute("key", iter->first);
		nodeProp->AddAttribute("value", iter->second);
	}

	for (std::vector<ControllerInfo*>::iterator iter = container->mController.begin(); iter != container->mController.end(); ++iter)
	{
		GUI::xml::ElementPtr nodeController = curNode->CreateChild("Controller");
		nodeController->AddAttribute("type", (*iter)->mType);
		for (GUI::MapString::iterator iterProp = (*iter)->mProperty.begin(); iterProp != (*iter)->mProperty.end(); ++iterProp)
		{
			GUI::xml::ElementPtr nodeProp = nodeController->CreateChild("Property");
			nodeProp->AddAttribute("key", iterProp->first);
			nodeProp->AddAttribute("value", iterProp->second);
		}
	}

	for (std::vector<WidgetContainer*>::iterator iter = container->childContainers.begin(); iter != container->childContainers.end(); ++iter)
	{
		SerialiseWidget(*iter, curNode);
	}
}

void EditorWidgets::LoadIgnoreParameters(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version)
{
	GUI::xml::ElementEnumerator parameter = node->GetElementEnumerator();
	while (parameter.Next("Parameter"))
	{
		std::string name = parameter->findAttribute("key");
		ignore_parameters.push_back(name);
	}
}
