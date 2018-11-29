#include "precompiled.h"
#include "WidgetsWindow.h"
#include "EditorWidgets.h"
#include "WidgetTypes.h"
#include "UndoManager.h"

const int MARGIN = 2;

WidgetsWindow::WidgetsWindow() : BaseLayout("WidgetsWindow.layout")
{
	current_widget = nullptr;
	AssignWidget(mTabSkins, "tabSkins");
}

void WidgetsWindow::UpdateSize()
{
	if (mTabSkins->GetItemCount() == 0)
	{
		mMainWidget->SetVisible(false);
		return;
	}

	int w = widgetsButtonWidth, h = widgetsButtonHeight;
	GUI::TabItem* sheet = mTabSkins->GetItemAt(0);

	const GUI::IntSize& sheet_size = sheet->GetSize();
	int width = mTabSkins->GetWidth() - sheet_size.width;
	int height = mTabSkins->GetHeight() - sheet_size.height;

	mTabSkins->SetSize(width + widgetsButtonsInOneLine * w + 2*MARGIN, height + mMaxLines*h + 2*MARGIN);

	
	size_t index = mTabSkins->FindItemIndexWith(skinSheetName);
	if (index != GUI::ITEM_NONE) mTabSkins->SetIndexSelected(index);

	width = mMainWidget->GetWidth() - mMainWidget->GetClientCoord().width;
	height = mMainWidget->GetHeight() - mMainWidget->GetClientCoord().height;

	const GUI::IntSize& size = GUI::Gui::GetInstance().GetViewSize();
	mMainWidget->SetCoord(0, size.height - (height + mTabSkins->GetHeight()), width + mTabSkins->GetWidth(), height + mTabSkins->GetHeight());

	mMainWidget->SetVisible(true);
}

void WidgetsWindow::Initialise()
{
	int w = widgetsButtonWidth, h = widgetsButtonHeight;

	GUI::TabItem* sheet = nullptr;
	mMaxLines = 0;
	for (SkinGroups::iterator iter = WidgetTypes::GetInstance().skin_groups.begin(); iter != WidgetTypes::GetInstance().skin_groups.end(); ++iter)
	{
		sheet = mTabSkins->AddItem(iter->first);
		int i = 0;
		for (VectorSkinInfo::iterator iterSkin = iter->second.begin(); iterSkin != iter->second.end(); ++iterSkin)
		{
			GUI::Button* button = sheet->CreateWidget<GUI::Button>("ButtonSmall",
				i%widgetsButtonsInOneLine * w + MARGIN, i/widgetsButtonsInOneLine * h + MARGIN, w, h,
				GUI::Align::Top|GUI::Align::Left, GUI::utility::ToString(iterSkin->widget_type, iterSkin->widget_skin));
			button->SetCaption(iterSkin->widget_button_name);
			button->SetTextAlign(GUI::Align::Center);
			button->SetUserString("widget", iterSkin->widget_type);
			button->SetUserString("skin", iterSkin->widget_skin);

			GUI::ResourceSkin* skin_info = GUI::SkinManager::GetInstance().GetByName(iterSkin->widget_skin);
			GUI::IntSize skinDefaultSize;
			if (skin_info != nullptr) skinDefaultSize = skin_info->GetSize();

			button->SetUserString("width", GUI::utility::ToString(skinDefaultSize.width));
			button->SetUserString("height", GUI::utility::ToString(skinDefaultSize.height));

			button->eventMouseButtonClick = GUI::NewDelegate(this, &WidgetsWindow::NotifySelectWidgetType);
			button->eventMouseButtonDoubleClick = GUI::NewDelegate(this, &WidgetsWindow::NotifySelectWidgetTypeDoubleclick);
			button->SetNeedToolTip(true);
			button->eventToolTip = GUI::NewDelegate(this, &WidgetsWindow::NotifyToolTip);
			i++;
		}
		mMaxLines = std::max((i+widgetsButtonsInOneLine-1)/widgetsButtonsInOneLine, mMaxLines);
	}

	UpdateSize();
}

void WidgetsWindow::Load(GUI::xml::ElementEnumerator field)
{
	GUI::xml::ElementEnumerator curField = field->GetElementEnumerator();
	while (curField.Next())
	{
		std::string key, value;

		if (curField->GetName() == "Property")
		{
			if (!curField->findAttribute("key", key)) continue;
			if (!curField->findAttribute("value", value)) continue;

			if (key == "widgetsButtonWidth") widgetsButtonWidth = GUI::utility::ParseInt(value);
			else if (key == "widgetsButtonHeight") widgetsButtonHeight = GUI::utility::ParseInt(value);
			else if (key == "widgetsButtonsInOneLine") widgetsButtonsInOneLine = GUI::utility::ParseInt(value);
			else if (key == "lastSkinGroup") skinSheetName = value;
		}
	}
}

void WidgetsWindow::Save(GUI::xml::ElementPtr root)
{
	root = root->CreateChild("WidgetsWindow");
	GUI::xml::ElementPtr nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "widgetsButtonWidth");
	nodeProp->AddAttribute("value", widgetsButtonWidth);

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "widgetsButtonHeight");
	nodeProp->AddAttribute("value", widgetsButtonHeight);

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "widgetsButtonsInOneLine");
	nodeProp->AddAttribute("value", widgetsButtonsInOneLine);

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "lastSkinGroup");
	size_t sheet_index = mTabSkins->GetIndexSelected();
	if (sheet_index != GUI::ITEM_NONE)
		nodeProp->AddAttribute("value", mTabSkins->GetItemNameAt(sheet_index));
}

void WidgetsWindow::ClearNewWidget()
{
	new_widget_type = "";
	new_widget_skin = "";
	creating_status = 0;
}

void WidgetsWindow::StartNewWidget(int x1, int y1, GUI::MouseButton id)
{
	mX1 = x1;
	mY1 = y1;
	if (id == GUI::MouseButton::Left && !creating_status && new_widget_type != "")
		creating_status = 1;
}

void WidgetsWindow::CreateNewWidget(int x2, int y2)
{
	mX2 = x2;
	mY2 = y2;
	GUI::IntCoord coord(std::min(mX1, mX2), std::min(mY1, mY2), abs(mX1 - mX2), abs(mY1 - mY2));
	if ((creating_status == 1) && ((mX1-mX2)*(mY1-mY2) != 0))
	{
		
		if (!GUI::WidgetManager::GetInstance().IsFactoryExist(new_widget_type))
		{
			creating_status = 0;
		}
		else
		{
			creating_status = 2;

			
			std::string tmpname = GUI::utility::ToString("LayoutEditorWidget_", new_widget_type, EditorWidgets::GetInstance().global_counter);
			EditorWidgets::GetInstance().global_counter++;
			
			while (current_widget && !WidgetTypes::GetInstance().Find(current_widget->GetTypeName())->parent) current_widget = current_widget->GetParent();
			if (current_widget && WidgetTypes::GetInstance().Find(new_widget_type)->child)
			{
				coord = coord - current_widget->GetPosition();
				current_widget = current_widget->CreateWidgetT(new_widget_type, new_widget_skin, coord, GUI::Align::Default, tmpname);
			}
			else
			{
				current_widget = GUI::Gui::GetInstance().CreateWidgetT(new_widget_type, new_widget_skin, coord, GUI::Align::Default, DEFAULT_EDITOR_LAYER, tmpname);
			}

			current_widget->SetCaption(GUI::utility::ToString("#888888",new_widget_skin));
		}
	}
	else if (creating_status == 2)
	{
		coord = ConvertCoordToParentCoord(coord, current_widget);
		current_widget->SetCoord(coord);
	}
}

void WidgetsWindow::FinishNewWidget(int x2, int y2)
{
	mX2 = x2;
	mY2 = y2;
	if (creating_status > 0)
	{
		if ((mX1-mX2)*(mY1-mY2) != 0)
		{
			
			WidgetContainer * widgetContainer = new WidgetContainer(new_widget_type, new_widget_skin, current_widget);
			EditorWidgets::GetInstance().Add(widgetContainer);
			current_widget = nullptr;
			eventSelectWidget(widgetContainer->widget);
			GUI::Gui::GetInstance().FindWidget<GUI::Button>(GUI::utility::ToString(new_widget_type, new_widget_skin))->SetButtonPressed(false);
			new_widget_type = "";
			new_widget_skin = "";
			UndoManager::GetInstance().AddValue();
		}
		else
		{
			
			if ((creating_status > 1) && current_widget) GUI::WidgetManager::GetInstance().DestroyWidget(current_widget);
			GUI::Gui::GetInstance().FindWidget<GUI::Button>(GUI::utility::ToString(new_widget_type, new_widget_skin))->SetButtonPressed(false);
			new_widget_type = "";
			new_widget_skin = "";
			if (creating_status == 2) EditorWidgets::GetInstance().global_counter--;
		}
		creating_status = 0;
	}
}

void WidgetsWindow::NotifySelectWidgetType(GUI::Widget* sender)
{
	new_widget_type = sender->GetUserString("widget");
	new_widget_skin = sender->GetUserString("skin");
	sender->CastType<GUI::Button>()->SetButtonPressed(true);
}

void WidgetsWindow::NotifySelectWidgetTypeDoubleclick(GUI::Widget* sender)
{
	new_widget_type = sender->GetUserString("widget");
	
	if (!GUI::WidgetManager::GetInstance().IsFactoryExist(new_widget_type))
	{
		return;
	}

	new_widget_skin = sender->GetUserString("skin");
	int width = GUI::utility::ParseInt(sender->GetUserString("width"));
	int height = GUI::utility::ParseInt(sender->GetUserString("height"));

	std::string tmpname = GUI::utility::ToString("LayoutEditorWidget_", new_widget_type, EditorWidgets::GetInstance().global_counter);
	EditorWidgets::GetInstance().global_counter++;

	while (current_widget && !WidgetTypes::GetInstance().Find(current_widget->GetTypeName())->parent) current_widget = current_widget->GetParent();
	if (current_widget && WidgetTypes::GetInstance().Find(new_widget_type)->child)
	{
		current_widget = current_widget->CreateWidgetT(new_widget_type, new_widget_skin, 0, 0, width, height, GUI::Align::Default, tmpname);
	}
	else
	{
		GUI::IntSize view(GUI::Gui::GetInstance().GetViewSize());
		current_widget = GUI::Gui::GetInstance().CreateWidgetT(new_widget_type, new_widget_skin, GUI::IntCoord(), GUI::Align::Default, DEFAULT_EDITOR_LAYER, tmpname);
		GUI::IntSize size(current_widget->GetSize());
		current_widget->SetCoord((view.width-size.width)/2, (view.height-size.height)/2, width, height);
	}
	current_widget->SetCaption(GUI::utility::ToString("#888888",new_widget_skin));

	WidgetContainer * widgetContainer = new WidgetContainer(new_widget_type, new_widget_skin, current_widget);
	EditorWidgets::GetInstance().Add(widgetContainer);
	current_widget = nullptr;
	eventSelectWidget(widgetContainer->widget);
	GUI::Gui::GetInstance().FindWidget<GUI::Button>(GUI::utility::ToString(new_widget_type, new_widget_skin))->SetButtonPressed(false);
	new_widget_type = "";
	new_widget_skin = "";

	UndoManager::GetInstance().AddValue();
}

void WidgetsWindow::ClearAllSheets()
{
	mTabSkins->RemoveAllItems();
	UpdateSize();
}
