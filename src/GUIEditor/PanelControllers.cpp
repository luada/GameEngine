#include "precompiled.h"
#include "PanelControllers.h"
#include "EditorWidgets.h"
#include "UndoManager.h"

PanelControllers::PanelControllers() :
	BasePanelViewItem("PanelControllers.layout"),
	mControllerName(nullptr),
	mButtonAdd(nullptr),
	mButtonDelete(nullptr),
	mList(nullptr),
	current_widget(nullptr),
	mButtonLeft(0),
	mButtonRight(0),
	mButtonSpace(0)
{
}

void PanelControllers::Initialise()
{
	mPanelCell->SetCaption("Controllers");

	AssignWidget(mControllerName, "controllerName");
	AssignWidget(mButtonAdd, "buttonAdd");
	AssignWidget(mButtonDelete, "buttonDelete");
	AssignWidget(mList, "list");

	mButtonAdd->eventMouseButtonClick = GUI::NewDelegate(this, &PanelControllers::NotifyAdd);
	mButtonDelete->eventMouseButtonClick = GUI::NewDelegate(this, &PanelControllers::NotifyDelete);
	mList->eventListChangePosition = GUI::NewDelegate(this, &PanelControllers::NotifySelectItem);

	mButtonLeft = mButtonAdd->GetLeft();
	mButtonRight = mMainWidget->GetWidth() - mButtonDelete->GetRight();
	mButtonSpace = mButtonDelete->GetLeft() - mButtonAdd->GetRight();

	
	GUI::ResourceManager::GetInstance().RegisterLoadXmlDelegate("ControllerTypes") = GUI::NewDelegate(this, &PanelControllers::LoadControllerTypes);
	GUI::ResourceManager::GetInstance().Load("controllers.xml");
}

void PanelControllers::Shutdown()
{
}

void PanelControllers::Update(GUI::Widget* current)
{
	current_widget = current;

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);

	mList->RemoveAllItems();
	for (std::vector<ControllerInfo*>::iterator iter = widgetContainer->mController.begin(); iter != widgetContainer->mController.end(); ++iter)
	{
		mList->AddItem((*iter)->mType, *iter);
	}

	mPanelCell->SetClientHeight(mButtonDelete->GetCoord().Bottom());
}

void PanelControllers::NotifyChangeWidth(int width)
{
	int curWidth = mMainWidget->GetClientCoord().width;

	int half_width = (curWidth - (mButtonLeft + mButtonRight + mButtonSpace)) / 2;
	mButtonAdd->SetSize(half_width, mButtonAdd->GetHeight());
	mButtonDelete->SetCoord(mButtonAdd->GetRight() + mButtonSpace, mButtonDelete->GetTop(), curWidth - (mButtonAdd->GetRight() + mButtonSpace + mButtonRight), mButtonDelete->GetHeight());
}

void PanelControllers::NotifyAdd(GUI::Widget* sender)
{
	std::string key = mControllerName->GetOnlyText();
	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);

	ControllerInfo* controllerInfo = new ControllerInfo();
	controllerInfo->mType = key;
	widgetContainer->mController.push_back(controllerInfo);

	mList->AddItem(key, controllerInfo);
	UndoManager::GetInstance().AddValue();
}

void PanelControllers::NotifyDelete(GUI::Widget* sender)
{
	size_t item = mList->GetIndexSelected();
	if (GUI::ITEM_NONE == item) return;

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	std::vector<ControllerInfo*>::iterator iter = std::find(widgetContainer->mController.begin(), widgetContainer->mController.end(), *mList->GetItemDataAt<ControllerInfo*>(item));
	if (iter != widgetContainer->mController.end())
	{
		delete *iter;
		widgetContainer->mController.erase(iter);
	}

	mList->RemoveItemAt(item);
	UndoManager::GetInstance().AddValue();

	
	NotifySelectItem(mList, mList->GetIndexSelected());
}

void PanelControllers::NotifySelectItem(GUI::List* sender, size_t index)
{
	size_t item = mList->GetIndexSelected();
	if (GUI::ITEM_NONE == item)
	{
		
		eventHidePairs(mWidgetClient);
		return;
	}

	std::string key = mList->GetItemNameAt(item);
	mControllerName->SetOnlyText(key);

	int y = mButtonDelete->GetCoord().Bottom();
	eventHidePairs(mWidgetClient);
	if (mControllersProperties.find(key) != mControllersProperties.end())
	{
		ControllerInfo* controllerInfo = *mList->GetItemDataAt<ControllerInfo*>(item);

		for (GUI::MapString::iterator iter = mControllersProperties[key].begin(); iter != mControllersProperties[key].end(); ++iter)
		{
			std::string val = "";
			if (controllerInfo->mProperty.find(iter->first) != controllerInfo->mProperty.end())
				val = controllerInfo->mProperty[iter->first];
			eventCreatePair(mWidgetClient, GUI::utility::ToString("Controller ", item, " ", iter->first), val, iter->second, y);

			y += PropertyItemHeight;
		}
	}
	mPanelCell->SetClientHeight(y);
}

void PanelControllers::LoadControllerTypes(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version)
{
	GUI::xml::ElementEnumerator controller = node->GetElementEnumerator();
	while (controller.Next("Controller"))
	{
		GUI::MapString controllerProperties;
		std::string name = controller->findAttribute("name");
		mControllerName->AddItem(name);
		GUI::xml::ElementEnumerator prop = controller->GetElementEnumerator();
		while (prop.Next("Property"))
		{
			controllerProperties[prop->findAttribute("key")] = prop->findAttribute("type");
		}
		mControllersProperties[name] = controllerProperties;
	}
}
