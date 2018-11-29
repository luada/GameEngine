#include "precompiled.h"
#include "PanelUserData.h"
#include "EditorWidgets.h"
#include "UndoManager.h"

PanelUserData::PanelUserData() :
	BasePanelViewItem("PanelUserData.layout"),
	mEditLeft(nullptr),
	mEditRight(nullptr),
	mEditSpace(nullptr),
	mButtonLeft(nullptr),
	mButtonRight(nullptr),
	mButtonSpace(nullptr)
{
}

void PanelUserData::Initialise()
{
	mPanelCell->SetCaption("UserData");

	AssignWidget(mEditKey, "editKey");
	AssignWidget(mEditValue, "editValue");
	AssignWidget(mButtonAdd, "buttonAdd");
	AssignWidget(mButtonDelete, "buttonDelete");
	AssignWidget(mMultilist, "multilist");

	mButtonAdd->eventMouseButtonClick = GUI::NewDelegate(this, &PanelUserData::NotifyAddUserData);
	mButtonDelete->eventMouseButtonClick = GUI::NewDelegate(this, &PanelUserData::NotifyDeleteUserData);
	mEditKey->eventEditSelectAccept = GUI::NewDelegate(this, &PanelUserData::NotifyUpdateUserData);
	mEditValue->eventEditSelectAccept = GUI::NewDelegate(this, &PanelUserData::NotifyUpdateUserData);
	mMultilist->eventListChangePosition = GUI::NewDelegate(this, &PanelUserData::NotifySelectUserDataItem);

	mMultilist->AddColumn(GUI::Localise("Key"), 1);
	mMultilist->AddColumn(GUI::Localise("Value"), 1);

	mEditLeft = mEditKey->GetLeft();
	mEditRight = mMainWidget->GetWidth() - mEditValue->GetRight();
	mEditSpace = mEditValue->GetLeft() - mEditKey->GetRight();

	mButtonLeft = mButtonAdd->GetLeft();
	mButtonRight = mMainWidget->GetWidth() - mButtonDelete->GetRight();
	mButtonSpace = mButtonDelete->GetLeft() - mButtonAdd->GetRight();
}

void PanelUserData::Shutdown()
{
}

void PanelUserData::Update(GUI::Widget* current)
{
	current_widget = current;

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);

	mMultilist->RemoveAllItems();
	for (StringPairs::iterator iterProperty = widgetContainer->mUserString.begin(); iterProperty != widgetContainer->mUserString.end(); ++iterProperty)
	{
		mMultilist->AddItem(iterProperty->first);
		mMultilist->SetSubItemNameAt(1, mMultilist->GetItemCount() - 1, iterProperty->second);
	}
}

void PanelUserData::NotifyChangeWidth(int width)
{
	const GUI::IntSize & size = mMultilist->GetClientCoord().Size();
	mMultilist->SetColumnWidthAt(0, size.width / 2);
	mMultilist->SetColumnWidthAt(1, size.width - (size.width / 2));

	int curWidth = mMainWidget->GetClientCoord().width;

	int half_width = (curWidth - (mEditLeft + mEditRight + mEditSpace)) / 2;
	mEditKey->SetSize(half_width, mEditKey->GetHeight());
	mEditValue->SetCoord(mEditKey->GetRight() + mEditSpace, mEditValue->GetTop(), curWidth - (mEditKey->GetRight() + mEditSpace + mEditRight), mEditValue->GetHeight());

	half_width = (curWidth - (mButtonLeft + mButtonRight + mButtonSpace)) / 2;
	mButtonAdd->SetSize(half_width, mButtonAdd->GetHeight());
	mButtonDelete->SetCoord(mButtonAdd->GetRight() + mButtonSpace, mButtonDelete->GetTop(), curWidth - (mButtonAdd->GetRight() + mButtonSpace + mButtonRight), mButtonDelete->GetHeight());
}

void PanelUserData::NotifyAddUserData(GUI::Widget* sender)
{
	std::string key = mEditKey->GetOnlyText();
	std::string value = mEditValue->GetOnlyText();
	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	if (MapFind(widgetContainer->mUserString, key) == widgetContainer->mUserString.end())
	{
		mMultilist->AddItem(key);
	}
	mMultilist->SetSubItemNameAt(1, mMultilist->FindSubItemWith(0, key), value);
	MapSet(widgetContainer->mUserString, key, value);
	UndoManager::GetInstance().AddValue();
}

void PanelUserData::NotifyDeleteUserData(GUI::Widget* sender)
{
	size_t item = mMultilist->GetIndexSelected();
	if (GUI::ITEM_NONE == item) return;

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	MapErase(widgetContainer->mUserString, mMultilist->GetItemNameAt(item));
	mMultilist->RemoveItemAt(item);
	UndoManager::GetInstance().AddValue();
}

void PanelUserData::NotifyUpdateUserData(GUI::Edit* widget)
{
	size_t item = mMultilist->GetIndexSelected();
	if (GUI::ITEM_NONE == item)
	{
		NotifyAddUserData();
		return;
	}
	std::string key = mEditKey->GetOnlyText();
	std::string value = mEditValue->GetOnlyText();
	std::string lastkey = mMultilist->GetItemNameAt(item);

	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	mMultilist->RemoveItemAt(mMultilist->FindSubItemWith(0, lastkey));
	MapErase(widgetContainer->mUserString, lastkey);
	if (MapFind(widgetContainer->mUserString, key) == widgetContainer->mUserString.end())
	{
		mMultilist->AddItem(key);
	}
	mMultilist->SetSubItemNameAt(1, mMultilist->FindSubItemWith(0, key), value);
	mMultilist->SetIndexSelected(mMultilist->FindSubItemWith(0, key));
	MapSet(widgetContainer->mUserString, key, value);
	UndoManager::GetInstance().AddValue();
}

void PanelUserData::NotifySelectUserDataItem(GUI::MultiList* widget, size_t index)
{
	size_t item = mMultilist->GetIndexSelected();
	if (GUI::ITEM_NONE == item) return;
	std::string key = mMultilist->GetSubItemNameAt(0, item);
	std::string value = mMultilist->GetSubItemNameAt(1, item);
	mEditKey->SetOnlyText(key);
	mEditValue->SetOnlyText(value);
}
