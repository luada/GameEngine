#include "precompiled.h"
#include "MetaSolutionWindow.h"
//#include "BasisManager.h"
#include "EditorWidgets.h"
#include "UndoManager.h"
#include "WidgetTypes.h"

const std::string LogSection = "LayoutEditor";

MetaSolutionWindow::MetaSolutionWindow() :
	BaseLayout("MetaSolutionWindow.layout")
{
	current_widget = nullptr;
	AssignWidget(mListTree, "ListTree");

	mMainWidget->CastType<GUI::Window>()->eventWindowButtonPressed = GUI::NewDelegate(this, &MetaSolutionWindow::NotifyCloseWindowButton);

	mListTree->eventListSelectAccept = GUI::NewDelegate(this, &MetaSolutionWindow::NotifyListSelectAccept);
	mListTree->eventListChangePosition = GUI::NewDelegate(this, &MetaSolutionWindow::NotifyListChangePosition);

	GUI::ResourceManager::GetInstance().RegisterLoadXmlDelegate("MetaSolution") = GUI::NewDelegate(this, &MetaSolutionWindow::ParseMetaSolution);
}

MetaSolutionWindow::~MetaSolutionWindow()
{
	CloseMetaSolution();
}

void MetaSolutionWindow::Load(GUI::xml::ElementEnumerator field)
{
	GUI::xml::ElementEnumerator curField = field->GetElementEnumerator();
	while (curField.Next())
	{
		std::string key, value;

		if (curField->GetName() == "Property")
		{
			if (!curField->findAttribute("key", key)) continue;
			if (!curField->findAttribute("value", value)) continue;

			if (key == "MetaSolutionName")
			{
				mMetaSolutionName = value;
				GUI::ResourceManager::GetInstance().Load(mMetaSolutionName/*, ""*/);
			}
			//else if (key == "key2") ;//do sth
		}
	}
}

void MetaSolutionWindow::Save(GUI::xml::ElementPtr root)
{
	root = root->CreateChild("MetaSolutionWindow");
	GUI::xml::ElementPtr nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "MetaSolutionName");
	nodeProp->AddAttribute("value", mMetaSolutionName);

	/*nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "ShowName");
	nodeProp->AddAttribute("value", GetShowName());*/
}

void MetaSolutionWindow::NotifyCloseWindowButton(GUI::Window* sender, const std::string& name)
{
	if (name == "close")
	{
		mMainWidget->SetVisible(false);
		mMetaSolutionName = "";
	}
}

void MetaSolutionWindow::NotifyListSelectAccept(GUI::List* sender, size_t index)
{
	if (index == GUI::ITEM_NONE) return;
	GUI::UString line = sender->GetItemNameAt(index);
	if (line[0] == '-' || line[0] == '+')
	{
		MetaForm* mf = *sender->GetItemDataAt<MetaForm*>(index);
		eventLoadFile(mf->mLayoutName);
		CollapseAll();
		mf->mCollapsed = false;
		UpdateList();
	}
	else
	{
		MetaWidget* mw = *sender->GetItemDataAt<MetaWidget*>(index);
		WidgetContainer * container = EditorWidgets::GetInstance().Find(mw->mName);
		if (container == nullptr)
		{
			CreateWidget(mw, current_widget);
		}
		else
		{
			
			if (!mw->mTarget.empty())
			{
				LoadTarget(mw->mTarget);
			}
		}
	}
}

void MetaSolutionWindow::NotifyListChangePosition(GUI::List* sender, size_t index)
{
	if (index == GUI::ITEM_NONE) return;
	GUI::UString line = sender->GetItemNameAt(index);
	if (line[0] == '-' || line[0] == '+')
	{
	}
	else
	{
		
		MetaWidget* mw = *sender->GetItemDataAt<MetaWidget*>(index);

		WidgetContainer * container = EditorWidgets::GetInstance().Find(mw->mName);
		if (container)
		{
			eventSelectWidget(container->widget);
		}
	}
}

void MetaSolutionWindow::ParseMetaSolution(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version)
{
	CloseMetaSolution();
	mMetaSolutionName = file;

	size_t pos = file.find_last_of("\\/");
	if (pos != std::string::npos) mMainWidget->SetCaption(file.substr(pos + 1));
	else mMainWidget->SetCaption(file);

	GUI::xml::ElementEnumerator meta_node = node->GetElementEnumerator();
	while (meta_node.Next())
	{
		if (meta_node->GetName() == "MetaForm")
		{
			MetaForm * metaForm = new MetaForm();

			metaForm->mDecription = meta_node->findAttribute("desc");
			metaForm->mLayoutName = meta_node->findAttribute("layout");
			metaForm->mId = GUI::Guid(meta_node->findAttribute("id"));

			
			GUI::xml::ElementEnumerator metaWidgets = meta_node->GetElementEnumerator();
			while (metaWidgets.Next("MetaWidget"))
			{
				MetaWidget * metaWidget = ParseMetaWidget(metaWidgets.Current(), nullptr);
				metaForm->mChilds.push_back(metaWidget);
			}

			mMetaForms.push_back(metaForm);
		}
		else if (meta_node->GetName() == "WidgetType")
		{
			
			GUI::xml::ElementEnumerator meta_widget = meta_node->GetElementEnumerator();
			while (meta_widget.Next("Widget"))
			{
				mWidgetType[meta_widget->findAttribute("name")] =
					PairString(meta_widget->findAttribute("type"), meta_widget->findAttribute("skin"));
			}
		}
		else if (meta_node->GetName() == "Widget")
		{
			std::string type_name = meta_node->findAttribute("name");

			
			GUI::xml::ElementEnumerator widget = meta_node->GetElementEnumerator();
			while (widget.Next("Property"))
			{
				std::string key = widget->findAttribute("key");
				if (key != "Skin") continue;

				std::string value = widget->findAttribute("value");
				std::string group = widget->findAttribute("group");
				std::string button_name = widget->findAttribute("name");
				if (button_name.empty())
					button_name = value;

				WidgetTypes::GetInstance().AddWidgetSkinType(type_name, value, group, button_name);
			}
		}
	}

	LoadList();
}

void MetaSolutionWindow::CloseMetaSolution()
{
	while (mMetaForms.size())
	{
		delete (*mMetaForms.rbegin());
		mMetaForms.pop_back();
	}
}

MetaWidget * MetaSolutionWindow::ParseMetaWidget(GUI::xml::ElementPtr node, MetaWidget * parent)
{
	MetaWidget * metaWidget = new MetaWidget();
	metaWidget->mName = node->findAttribute("name");
	metaWidget->mType = node->findAttribute("type");
	metaWidget->mParent = parent;

	GUI::xml::ElementEnumerator links = node->GetElementEnumerator();
	while (links.Next("MetaLink"))
	{
		if (metaWidget->mTarget.empty())
			metaWidget->mTarget = GUI::Guid(links->findAttribute("target"));
		else
			LOGGING(LogSection, warning,
				"MetaWidget with name '" + metaWidget->mName +
				"' have more than one target");
	}
	GUI::xml::ElementEnumerator metaWidgets = node->GetElementEnumerator();
	while (metaWidgets.Next("MetaWidget"))
	{
		metaWidget->mChilds.push_back(ParseMetaWidget(metaWidgets.Current(), metaWidget));
	}
	return metaWidget;
}

void MetaSolutionWindow::LoadList()
{
	mListTree->RemoveAllItems();
	for (std::vector<MetaForm*>::iterator iterMF = mMetaForms.begin(); iterMF != mMetaForms.end(); ++iterMF)
	{
		std::string line = GUI::utility::ToString(((*iterMF)->mCollapsed ? "+ " : "- "), (*iterMF)->mLayoutName, "  -  #808080", (*iterMF)->mDecription);
		mListTree->AddItem(line, *iterMF);
	}

	SetVisible(true);
}

void MetaSolutionWindow::UpdateList()
{
	size_t i = 0;
	while (i != mListTree->GetItemCount())
	{
		GUI::UString line = mListTree->GetItemNameAt(i);
		if (line[0] != '-' && line[0] != '+')
			mListTree->RemoveItemAt(i);
		else
			i++;
	}

	i = 0;
	for (std::vector<MetaForm*>::iterator iterMF = mMetaForms.begin(); iterMF != mMetaForms.end(); ++iterMF, ++i)
	{
		if (!(*iterMF)->mCollapsed)
		{
			i += AddMetaWidgets((*iterMF)->mChilds, i, "   ");
		}
	}
}

int MetaSolutionWindow::AddMetaWidgets(std::vector<MetaWidget*> childs, size_t index, std::string level)
{
	const std::string colour_created = "#008000";
	const std::string colour_destroed = "#800000";

	int i = 0;
	for (std::vector<MetaWidget*>::iterator iter = childs.begin(); iter != childs.end(); ++iter)
	{
		i++;
		WidgetContainer * container = EditorWidgets::GetInstance().Find((*iter)->mName);
		GUI::UString line = GUI::utility::ToString(level, "[ ", (*iter)->mType, " ] ",
			container ? colour_created : colour_destroed, (*iter)->mName,
			((*iter)->mTarget.empty() ? "" :
			((FindTarget((*iter)->mTarget) ? colour_created : colour_destroed)+std::string(" [*]"))));
		mListTree->InsertItemAt(index+i, line, *iter);
		i += AddMetaWidgets((*iter)->mChilds, index+i, level + "   ");
	}
	return i;
}

void MetaSolutionWindow::CollapseAll()
{
	for (std::vector<MetaForm*>::iterator iterMF = mMetaForms.begin(); iterMF != mMetaForms.end(); ++iterMF)
	{
		(*iterMF)->mCollapsed = true;
	}
}

void MetaSolutionWindow::LoadTarget(GUI::Guid target)
{
	for (std::vector<MetaForm*>::iterator iterMF = mMetaForms.begin(); iterMF != mMetaForms.end(); ++iterMF)
	{
		if ((*iterMF)->mId == target)
		{
			eventLoadFile((*iterMF)->mLayoutName);
			CollapseAll();
			(*iterMF)->mCollapsed = false;
			UpdateList();
		}
	}
}

bool MetaSolutionWindow::FindTarget(GUI::Guid target)
{
	for (std::vector<MetaForm*>::iterator iterMF = mMetaForms.begin(); iterMF != mMetaForms.end(); ++iterMF)
	{
		if ((*iterMF)->mId == target)
		{
			return true;
		}
	}
	return false;
}

GUI::Widget* MetaSolutionWindow::CreateWidget(MetaWidget * widget, GUI::Widget* parent)
{
	
	if (widget->mParent)
	{
		
		WidgetContainer * trueParent = EditorWidgets::GetInstance().Find(widget->mParent->mName);
		if (!trueParent)
		{
			parent = CreateWidget(widget->mParent, nullptr);
		}
		else
		{
			if (parent == nullptr)
			{
				parent = trueParent->widget;
			}
			else
			{
				
				WidgetContainer * current_widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
				
				while (current_widgetContainer != nullptr && current_widgetContainer != trueParent)
				{
					GUI::Widget* curParent = current_widgetContainer->widget->GetParent();
					current_widgetContainer = EditorWidgets::GetInstance().Find(curParent);
					while (curParent != nullptr && nullptr == current_widgetContainer)
					{
						curParent = curParent->GetParent();
						current_widgetContainer = EditorWidgets::GetInstance().Find(curParent);
					}
					if (curParent == nullptr) current_widgetContainer = nullptr;
				}
				if (current_widgetContainer == nullptr) parent = trueParent->widget;
			}
		}
	}

	std::string new_widget_type = widget->mType;
	std::string new_widget_skin = widget->mType; 

	
	MapPairString::const_iterator iter = mWidgetType.find(widget->mType);
	if (iter != mWidgetType.end())
	{
		new_widget_type = iter->second.first;
		new_widget_skin = iter->second.second;
	}

	int width = 64;
	int height = 32;

	std::string tmpname = "LayoutEditorWidget_" + widget->mName;
	EditorWidgets::GetInstance().global_counter++;

	while (parent && !WidgetTypes::GetInstance().Find(parent->GetTypeName())->parent) parent = parent->GetParent();
	if (parent && WidgetTypes::GetInstance().Find(new_widget_type)->child)
		parent = parent->CreateWidgetT(new_widget_type, new_widget_skin, 0, 0, width, height, GUI::Align::Default, tmpname);
	else
	{
		GUI::IntSize view(GUI::Gui::GetInstance().GetViewSize());
		parent = GUI::Gui::GetInstance().CreateWidgetT(new_widget_type, new_widget_skin, GUI::IntCoord(), GUI::Align::Default, DEFAULT_EDITOR_LAYER, tmpname);
		GUI::IntSize size(parent->GetSize());
		parent->SetCoord((view.width-size.width)/2, (view.height-size.height)/2, width, height);
	}
	parent->SetCaption(GUI::utility::ToString("#888888",new_widget_skin));

	WidgetContainer * widgetContainer = new WidgetContainer(new_widget_type, new_widget_skin, parent, widget->mName);
	EditorWidgets::GetInstance().Add(widgetContainer);
	eventSelectWidget(widgetContainer->widget);

	UndoManager::GetInstance().AddValue();

	return parent;
}
