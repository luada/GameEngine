#include "precompiled.h"
#include "PanelItems.h"
#include "EditorWidgets.h"
#include "WidgetTypes.h"
#include "UndoManager.h"

#define ON_EXIT(CODE) class _OnExit { public: void Dummy() const { }; ~_OnExit() { CODE; } } _onExit; _onExit.Dummy()

PanelItems::PanelItems() :
	BasePanelViewItem("PanelItems.layout"),
	mButtonLeft(nullptr),
	mButtonRight(nullptr),
	mButtonSpace(nullptr)
{
}

void PanelItems::Initialise()
{
	mPanelCell->SetCaption(GUI::Localise("Items"));

	AssignWidget(mEdit, "edit");
	AssignWidget(mList, "list");
	AssignWidget(mButtonAdd, "buttonAdd");
	AssignWidget(mButtonDelete, "buttonDelete");
	AssignWidget(mButtonSelect, "buttonSelect");
	mButtonAdd->eventMouseButtonClick = GUI::NewDelegate(this, &PanelItems::NotifyAddItem);
	mButtonDelete->eventMouseButtonClick = GUI::NewDelegate(this, &PanelItems::NotifyDeleteItem);
	mButtonSelect->eventMouseButtonClick = GUI::NewDelegate(this, &PanelItems::NotifySelectSheet);
	mEdit->eventEditSelectAccept = GUI::NewDelegate(this, &PanelItems::NotifyUpdateItem);
	mList->eventListChangePosition = GUI::NewDelegate(this, &PanelItems::NotifySelectItem);

	mButtonLeft = mButtonAdd->GetLeft();
	mButtonRight = mMainWidget->GetWidth() - mButtonSelect->GetRight();
	mButtonSpace = mButtonDelete->GetLeft() - mButtonAdd->GetRight();
}

void PanelItems::Shutdown()
{
}

void PanelItems::NotifyChangeWidth(int width)
{
	int curWidth = mMainWidget->GetClientCoord().width;

	if (mButtonSelect->IsVisible())
	{
		int one_width = (curWidth - (mButtonLeft + mButtonRight + mButtonSpace)) / 3;
		mButtonAdd->SetSize(one_width, mButtonAdd->GetHeight());
		mButtonDelete->SetCoord(mButtonAdd->GetRight() + mButtonSpace, mButtonDelete->GetTop(), one_width, mButtonDelete->GetHeight());
		mButtonSelect->SetCoord(mButtonDelete->GetRight() + mButtonSpace, mButtonSelect->GetTop(), curWidth - (mButtonDelete->GetRight() + mButtonSpace + mButtonRight), mButtonSelect->GetHeight());
	}
	else
	{
		int half_width = (curWidth - (mButtonLeft + mButtonRight + mButtonSpace)) / 2;
		mButtonAdd->SetSize(half_width, mButtonAdd->GetHeight());
		mButtonDelete->SetCoord(mButtonAdd->GetRight() + mButtonSpace, mButtonDelete->GetTop(), curWidth - (mButtonAdd->GetRight() + mButtonSpace + mButtonRight), mButtonDelete->GetHeight());
	}
}

void PanelItems::Update(GUI::Widget* current)
{
	current_widget = current;

	WidgetStyle * widgetType = WidgetTypes::GetInstance().Find(current_widget->GetTypeName());
	//WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);

	if (widgetType->many_items)
	{
		SetVisible(true);
		if (widgetType->name == "Tab") mPanelCell->SetCaption(GUI::Localise("Items"));
		else mPanelCell->SetCaption(GUI::Localise("Items"));
		SyncItems(false);
		if (widgetType->name == "Tab") mButtonSelect->SetVisible(true);
		else mButtonSelect->SetVisible(false);
		mEdit->SetCaption("");
		
		NotifyChangeWidth(0);
	}
	else
	{
		SetVisible(false);
	}
}

void PanelItems::NotifyRectangleDoubleClick(GUI::Widget* sender)
{
	if (current_widget->GetTypeName() == "Tab")
	{
		AddSheetToTab(current_widget);
		// update strings panel
		SyncItems(false);
		UndoManager::GetInstance().AddValue();
	}
}

void PanelItems::AddSheetToTab(GUI::Widget* tab, std::string caption)
{
	GUI::Tab* curTab = tab->CastType<GUI::Tab>();
	GUI::TabItem* sheet = curTab->AddItem(caption);
	WidgetContainer * wc = new WidgetContainer("TabItem", "", sheet, "");
	if (!caption.empty()) wc->mProperty.push_back(std::make_pair("Widget_Caption", caption));
	EditorWidgets::GetInstance().Add(wc);
}

void PanelItems::SyncItems(bool apply, bool add, std::string value)
{
	std::string action;
	
	if (current_widget->GetTypeName() == "Tab") action = "Tab_AddSheet";
	else
	{
		// for example "ComboBox_AddItem", "List_AddItem", etc...
		action = current_widget->GetTypeName() + "_AddItem";
	}

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	if (apply)
	{
		if (add)
		{
			if (action == "Tab_AddSheet")
			{
				AddSheetToTab(current_widget, value);
				UndoManager::GetInstance().AddValue();
			}
			else if (current_widget->IsType<GUI::MenuCtrl>())
			{
				current_widget->CastType<GUI::MenuCtrl>()->AddItem(value);
				UndoManager::GetInstance().AddValue();
			}
			else
			{
				widgetContainer->widget->SetProperty(action, value);
				widgetContainer->mProperty.push_back(std::make_pair(action, value));
			}
		}
		else
		{
			if (action == "Tab_AddSheet")
			{
				EditorWidgets::GetInstance().Remove(current_widget->CastType<GUI::Tab>()->FindItemWith(value));
			}
			else if (current_widget->IsType<GUI::MenuCtrl>())
			{
				size_t item_index = current_widget->CastType<GUI::MenuCtrl>()->FindItemIndexWith(value);
				if (item_index != GUI::ITEM_NONE)
					current_widget->CastType<GUI::MenuCtrl>()->RemoveItemAt(item_index);
			}
			else
			{
				int index = 0;
				for (StringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
				{
					if (iterProperty->first == action)
					{
						if (iterProperty->second == value)
						{
							widgetContainer->mProperty.erase(iterProperty);
							if (current_widget->GetTypeName() == "ComboBox") current_widget->CastType<GUI::ComboBox>()->RemoveItemAt(index);
							else if (current_widget->GetTypeName() == "List") current_widget->CastType<GUI::List>()->RemoveItemAt(index);
							//else if (current_widget->GetTypeName() == "MenuBar") current_widget->CastType<GUI::MenuBar>()->RemoveItemAt(index);
							//else if (current_widget->GetTypeName() == "Message") ->CastType<GUI::Message>(current_widget)->DeleteItem(index);
							return;
						}
						++index;
					}
				}
			}
		}
	}
	else // if !curApply (if load)
	{
		mList->RemoveAllItems();
		if (action == "Tab_AddSheet")
		{
			GUI::Tab* tab = current_widget->CastType<GUI::Tab>();
			for (size_t i = 0; i<tab->GetItemCount(); ++i)
			{
				mList->AddItem(tab->GetItemNameAt(i));
			}
		}
		else if (current_widget->IsType<GUI::MenuCtrl>())
		{
			GUI::MenuCtrl* menu = current_widget->CastType<GUI::MenuCtrl>();
			for (size_t i = 0; i<menu->GetItemCount(); ++i)
			{
				mList->AddItem(menu->GetItemNameAt(i));
			}
		}
		else
		{
			for (StringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
			{
				if (iterProperty->first == action)
				{
					mList->AddItem(iterProperty->second);
				}
			}
		}
	}
}

void PanelItems::NotifyAddItem(GUI::Widget* sender)
{
	SyncItems(true, true, mEdit->GetOnlyText());
	mList->AddItem(mEdit->GetOnlyText());
	UndoManager::GetInstance().AddValue();
}

void PanelItems::NotifyDeleteItem(GUI::Widget* sender)
{
	size_t item = mList->GetIndexSelected();
	if (GUI::ITEM_NONE == item) return;
	SyncItems(true, false, mList->GetItemNameAt(item));
	mList->RemoveItemAt(item);
	UndoManager::GetInstance().AddValue();
}

void PanelItems::NotifySelectSheet(GUI::Widget* sender)
{
	size_t item = mList->GetIndexSelected();
	if (GUI::ITEM_NONE == item) return;
	GUI::Tab* tab = current_widget->CastType<GUI::Tab>();
	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);

	std::string action = "Tab_SelectSheet";
	std::string value = GUI::utility::ToString(item);
	widgetContainer->widget->SetProperty(action, value);

	action = "Sheet_Select";
	for (size_t i = 0; i < tab->GetItemCount(); ++i)
	{
		WidgetContainer * sheetContainer = EditorWidgets::GetInstance().Find(tab->GetItemAt(i));

		if (i == item) MapSet(sheetContainer->mProperty, action, "true");
		else MapErase(sheetContainer->mProperty, action);
	}
	UndoManager::GetInstance().AddValue();
}

void PanelItems::NotifyUpdateItem(GUI::Edit* widget)
{
	size_t item = mList->GetIndexSelected();
	if (GUI::ITEM_NONE == item) { NotifyAddItem(); return; }
	ON_EXIT(UndoManager::GetInstance().AddValue());
	std::string action;
	std::string value = mEdit->GetOnlyText();
	std::string lastitem = mList->GetItemNameAt(item);
	mList->SetItemNameAt(item, value);

	if (current_widget->GetTypeName() == "Tab")
	{
		action = "Widget_Caption";
		GUI::Tab* tab = current_widget->CastType<GUI::Tab>();
		GUI::TabItem* sheet = tab->GetItemAt(item);
		WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(sheet);
		sheet->SetProperty("Widget_Caption", value);
		MapSet(widgetContainer->mProperty, action, value);
		return;
	}
	else if (current_widget->IsType<GUI::MenuCtrl>())
	{
		GUI::MenuCtrl* menu = current_widget->CastType<GUI::MenuCtrl>();
		for (size_t i = 0; i<menu->GetItemCount(); ++i)
		{
			menu->SetItemNameAt(i, mList->GetItemNameAt(i));
		}
	}
	else
	{
		action = current_widget->GetTypeName() + "_AddItem";
	}

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	int index = 0;
	for (StringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
	{
		if (iterProperty->first == action)
		{
			if (iterProperty->second == lastitem)
			{
				iterProperty->second = value;
				if (current_widget->GetTypeName() == "ComboBox") current_widget->CastType<GUI::ComboBox>()->SetItemNameAt(index, value);
				else if (current_widget->GetTypeName() == "List") current_widget->CastType<GUI::List>()->SetItemNameAt(index, value);
				//else if (current_widget->GetTypeName() == "MenuBar") current_widget->CastType<GUI::MenuBar>()->SetItemNameAt(index, value);
				return;
			}
			++index;
		}
	}
}

void PanelItems::NotifySelectItem(GUI::List* widget, size_t position)
{
	size_t index = mList->GetIndexSelected();
	if (GUI::ITEM_NONE == index) return;

	const GUI::UString& value = mList->GetItemNameAt(index);
	mEdit->SetOnlyText(value);

	if (current_widget->IsType<GUI::Tab>())
	{
		current_widget->CastType<GUI::Tab>()->SetIndexSelected(index);
	}
}
