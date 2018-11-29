#include "precompiled.h"
#include "PropertiesPanelView.h"
#include "EditorWidgets.h"
#include "WidgetTypes.h"
#include "UndoManager.h"
#include "Parse.h"
#include "GroupMessage.h"

#define ON_EXIT(CODE) class _OnExit { public: void Dummy() const { }; ~_OnExit() { CODE; } } _onExit; _onExit.Dummy()

int grid_step;//FIXME_HOOK
int ToGrid(int x) { return x / grid_step * grid_step; }

const std::string DEFAULT_STRING = "[DEFAULT]";
std::string DEFAULT_VALUE;
std::string ERROR_VALUE;

PropertiesPanelView::PropertiesPanelView() : BaseLayout("PropertiesPanelView.layout")
{
	DEFAULT_VALUE = GUI::Localise("ColourDefault") + DEFAULT_STRING;
	ERROR_VALUE = GUI::Localise("ColourError");

	AssignBase(mPanelView, "scroll_View");

	GUI::Window* window = mMainWidget->CastType<GUI::Window>(false);
	if (window != nullptr)
	{
		window->eventWindowChangeCoord = GUI::NewDelegate(this, &PropertiesPanelView::NotifyWindowChangeCoord);
		mOldSize = window->GetSize();
	}

	mPanelMainProperties = new PanelMainProperties();
	mPanelView->AddItem(mPanelMainProperties);
	mPanelMainProperties->eventCreatePair = GUI::NewDelegate(this, &PropertiesPanelView::CreatePropertiesWidgetsPair);
	mPanelMainProperties->eventSetPositionText = GUI::NewDelegate(this, &PropertiesPanelView::SetPositionText);

	mPanelTypeProperties = new PanelProperties();
	mPanelView->AddItem(mPanelTypeProperties);
	mPanelTypeProperties->eventCreatePair = GUI::NewDelegate(this, &PropertiesPanelView::CreatePropertiesWidgetsPair);

	mPanelGeneralProperties = new PanelProperties();
	mPanelView->AddItem(mPanelGeneralProperties);
	mPanelGeneralProperties->eventCreatePair = GUI::NewDelegate(this, &PropertiesPanelView::CreatePropertiesWidgetsPair);

	mPanelItems = new PanelItems();
	mPanelView->AddItem(mPanelItems);

	mPanelUserData = new PanelUserData();
	mPanelView->AddItem(mPanelUserData);

	mPanelControllers = new PanelControllers();
	mPanelView->AddItem(mPanelControllers);
	mPanelControllers->eventCreatePair = GUI::NewDelegate(this, &PropertiesPanelView::CreatePropertiesWidgetsPair);
	mPanelControllers->eventHidePairs = GUI::NewDelegate(this, &PropertiesPanelView::HideWidgetsPairs);

	mPanels.push_back(mPanelMainProperties);
	mPanels.push_back(mPanelTypeProperties);
	mPanels.push_back(mPanelGeneralProperties);
	mPanels.push_back(mPanelItems);
	mPanels.push_back(mPanelUserData);
	mPanels.push_back(mPanelControllers);

	current_widget = nullptr;

	// create widget rectangle
	current_widget_rectangle = GUI::Gui::GetInstance().CreateWidget<GUI::Window>("StretchRectangle", GUI::IntCoord(), GUI::Align::Default, "LayoutEditor_Rectangle");
	current_widget_rectangle->eventWindowChangeCoord = NewDelegate(this, &PropertiesPanelView::NotifyRectangleResize);
	current_widget_rectangle->eventMouseButtonDoubleClick = NewDelegate(mPanelItems, &PanelItems::NotifyRectangleDoubleClick);
	current_widget_rectangle->eventKeyButtonPressed = NewDelegate(this, &PropertiesPanelView::NotifyRectangleKeyPressed);

	arrow_move = false;
}

PropertiesPanelView::~PropertiesPanelView()
{
	mPanelView->RemoveAllItems();
	delete mPanelMainProperties;
	delete mPanelTypeProperties;
	delete mPanelGeneralProperties;
	delete mPanelItems;
	delete mPanelUserData;
	delete mPanelControllers;
}

void PropertiesPanelView::NotifyWindowChangeCoord(GUI::Window* sender)
{
	const GUI::IntSize & size = sender->GetSize();
	if (size != mOldSize)
	{
		mOldSize = size;
		mPanelView->SetNeedUpdate();
	}
}

void PropertiesPanelView::Load(GUI::xml::ElementEnumerator field)
{
	GUI::xml::ElementEnumerator curField = field->GetElementEnumerator();
	VectorPanel::iterator iter = mPanels.begin();
	while (curField.Next())
	{
		std::string key, value;

		if (curField->GetName() == "Property")
		{
			if (!curField->findAttribute("key", key)) continue;
			if (!curField->findAttribute("value", value)) continue;

			if ((key == GUI::utility::ToString("PanelMinimized")) && (iter != mPanels.end()))
			{
				(*iter)->GetPanelCell()->SetMinimized(GUI::utility::ParseBool(value));
				++iter;
			}
		}
	}
}

void PropertiesPanelView::Save(GUI::xml::ElementPtr root)
{
	root = root->CreateChild("PropertiesPanelView");
	GUI::xml::ElementPtr nodeProp;

	for (VectorPanel::iterator iter = mPanels.begin(); iter != mPanels.end(); ++iter)
	{
		nodeProp = root->CreateChild("Property");
		nodeProp->AddAttribute("key", GUI::utility::ToString("Panel","Minimized"));
		nodeProp->AddAttribute("value", (*iter)->GetPanelCell()->IsMinimized());
	}
}

void PropertiesPanelView::NotifyRectangleResize(GUI::Window* sender)
{
	if (!sender->IsVisible()) return;
	
	WidgetContainer * widgetContainer = EditorWidgets::GetInstance().Find(current_widget);
	if (WidgetTypes::GetInstance().Find(current_widget->GetTypeName())->resizeable)
	{
		GUI::IntCoord coord = ConvertCoordToParentCoord(sender->GetCoord(), current_widget);
		GUI::IntCoord old_coord = current_widget->GetCoord();
		// align to grid
		if (!GUI::InputManager::GetInstance().IsShiftPressed() && !arrow_move)
		{
			if ((old_coord.width == coord.width) && (old_coord.height == coord.height)) 
			{
				coord.left = ToGrid(coord.left + grid_step-1 - old_coord.left) + old_coord.left;
				coord.top = ToGrid(coord.top + grid_step-1 - old_coord.top) + old_coord.top;
			}
			else 
			{
				if (old_coord.left != coord.left)
				{
					coord.left = ToGrid(coord.left + grid_step-1);
					coord.width = old_coord.Right() - coord.left;
				}
				else if (old_coord.width != coord.width)
				{
					coord.width = ToGrid(coord.width + old_coord.left) - old_coord.left;
				}

				if (old_coord.top != coord.top)
				{
					coord.top = ToGrid(coord.top + grid_step-1);
					coord.height = old_coord.Bottom() - coord.top;
				}
				else if (old_coord.height != coord.height)
				{
					coord.height = ToGrid(coord.height + old_coord.top) - old_coord.top;
				}
			}
		}
		arrow_move = false;

		current_widget->SetCoord(coord);
		// update coord because of current_widget can have MinMax size
		coord = current_widget->GetCoord();
		SetPositionText(widgetContainer->Position());

		UndoManager::GetInstance().AddValue(PR_POSITION);
	}
	current_widget_rectangle->SetCoord(current_widget->GetAbsoluteCoord());
}

void PropertiesPanelView::NotifyRectangleKeyPressed(GUI::Widget* sender, GUI::KeyCode key, GUI::Char _char)
{
	GUI::IntPoint delta;
	int k = GUI::InputManager::GetInstance().IsShiftPressed() ? 1 : grid_step;
	if (GUI::KeyCode::Tab == key)
	{
		if ((nullptr != current_widget) && (nullptr != current_widget->GetParent()) && (current_widget->GetParent()->GetTypeName() == "Tab")) Update(current_widget->GetParent());
		if (current_widget->GetTypeName() == "Tab")
		{
			GUI::Tab* tab = current_widget->CastType<GUI::Tab>();
			size_t sheet = tab->GetIndexSelected();
			sheet++;
			if (sheet >= tab->GetItemCount()) sheet = 0;
			if (tab->GetItemCount()) tab->SetIndexSelected(sheet);
		}
	}
	else if (GUI::KeyCode::Delete == key)
	{
		if (current_widget)
		{
			EditorWidgets::GetInstance().Remove(current_widget);
			eventRecreate();
			UndoManager::GetInstance().AddValue();
		}
	}
	else if (GUI::KeyCode::ArrowLeft == key)
	{
		delta = GUI::IntPoint(-k, 0);
	}
	else if (GUI::KeyCode::ArrowRight == key)
	{
		delta = GUI::IntPoint(k, 0);
	}
	else if (GUI::KeyCode::ArrowUp == key)
	{
		delta = GUI::IntPoint(0, -k);
	}
	else if (GUI::KeyCode::ArrowDown == key)
	{
		delta = GUI::IntPoint(0, k);
	}

	if (delta != GUI::IntPoint())
	{
		arrow_move = true;
		current_widget_rectangle->SetPosition(current_widget_rectangle->GetPosition() + delta);
		NotifyRectangleResize(current_widget_rectangle);
		UndoManager::GetInstance().AddValue(PR_KEY_POSITION);
	}
}

void PropertiesPanelView::Update(GUI::Widget* current)
{
	current_widget = current;

	if (nullptr == current_widget)
		current_widget_rectangle->SetVisible(false);
	else
	{
		GUI::LayerManager::GetInstance().UpLayerItem(current_widget);
		GUI::IntCoord coord = current_widget->GetCoord();
		GUI::Widget* parent = current_widget->GetParent();
		if (nullptr != parent)
		{
			
			if (parent->GetTypeName() == "TabItem" || parent->GetTypeName() == GUI::TabItem::GetClassTypeName())
			{
				GUI::Tab* tab = parent->GetParent()->CastType<GUI::Tab>();
				GUI::TabItem* sheet = parent->CastType<GUI::TabItem>();
				tab->SetItemSelected(sheet);
			}
			
			if (current_widget->GetTypeName() == "TabItem" || current_widget->GetTypeName() == GUI::TabItem::GetClassTypeName())
			{
				GUI::Tab* tab = parent->CastType<GUI::Tab>();
				GUI::TabItem* sheet = current_widget->CastType<GUI::TabItem>();
				tab->SetItemSelected(sheet);
			}
			coord = current_widget->GetAbsoluteCoord();
		}
		current_widget_rectangle->SetVisible(true);
		current_widget_rectangle->SetCoord(coord);
		GUI::InputManager::GetInstance().SetKeyFocusWidget(current_widget_rectangle);
	}

	// Delete(hide) all previous properties
	for (std::map<GUI::Widget*, std::vector<GUI::StaticText*> >::iterator iterVector = mPropertiesText.begin(); iterVector != mPropertiesText.end(); ++iterVector)
	{
		HideWidgetsPairs(iterVector->first);
	}

	if (nullptr == current_widget)
	{
		mMainWidget->SetVisible(false);
	}
	else
	{
		mMainWidget->SetVisible(true);

		mPairsCounter = 0;
		mPanelMainProperties->Update(current_widget);
		mPairsCounter = 0;
		mPanelTypeProperties->Update(current_widget, PanelProperties::TYPE_PROPERTIES);
		mPairsCounter = 0;
		mPanelGeneralProperties->Update(current_widget, PanelProperties::WIDGET_PROPERTIES);
		mPanelItems->Update(current_widget);
		mPanelUserData->Update(current_widget);
		mPairsCounter = 0;
		mPanelControllers->Update(current_widget);
	}
}

void PropertiesPanelView::HideWidgetsPairs(GUI::Widget* window)
{
	mPairsCounter = 0;
	for (std::vector<GUI::StaticText*>::iterator iter = mPropertiesText[window].begin(); iter != mPropertiesText[window].end(); ++iter)
	{
		(*iter)->SetVisible(false);
	}

	for (GUI::VectorWidgetPtr::iterator iter = mPropertiesElement[window].begin(); iter != mPropertiesElement[window].end(); ++iter)
	{
		(*iter)->SetVisible(false);
	}
}
void PropertiesPanelView::CreatePropertiesWidgetsPair(GUI::Widget* window, const std::string& property, const std::string& value, const std::string& type, int y)
{
	mPairsCounter++;
	int x1 = 0, x2 = 125;
	int w1 = 120;
	int w2 = window->GetWidth() - x2;
	const int h = PropertyItemHeight;

	if (property == "Position")
	{
		x1 = 66;
		w1 = w1 - x1;
	}

	GUI::StaticText* text;
	GUI::Widget* editOrCombo;
	//int string_int_float; // 0 - string, 1 - int, 2 - float

	enum PropertyType
	{
		PropertyType_Edit,
		PropertyType_ComboBox,
		PropertyType_EditAcceptOnly,
		PropertyType_Count
	};

	PropertyType widget_for_type;

	std::string type_names[PropertyType_Count] = { "Edit", "ComboBox", "Edit" };

	if ("Name" == type) widget_for_type = PropertyType_Edit;
	else if ("Skin" == type) widget_for_type = PropertyType_ComboBox;
	else if ("Position" == type) widget_for_type = PropertyType_Edit;
	else if ("Layer" == type) widget_for_type = PropertyType_ComboBox;
	else if ("String" == type) widget_for_type = PropertyType_Edit;
	else if ("StringAccept" == type) widget_for_type = PropertyType_EditAcceptOnly;
	else if ("Align" == type) widget_for_type = PropertyType_ComboBox;
	else if ("FileName" == type) widget_for_type = PropertyType_Edit;
	
	else if ("1 int" == type) widget_for_type = PropertyType_Edit;
	else if ("2 int" == type) widget_for_type = PropertyType_Edit;
	else if ("4 int" == type) widget_for_type = PropertyType_Edit;
	else if ("alpha" == type) widget_for_type = PropertyType_Edit;
	else if ("1 float" == type) widget_for_type = PropertyType_Edit;
	else if ("2 float" == type) widget_for_type = PropertyType_Edit;
	
	else if ("Colour" == type) widget_for_type = PropertyType_Edit; 
	else if ("MessageButton" == type) widget_for_type = PropertyType_ComboBox;
	else widget_for_type = PropertyType_ComboBox;

	if (mPropertiesText[window].size() < mPairsCounter)
	{
		text = window->CreateWidget<GUI::StaticText>("Editor_StaticText", x1, y, w1, h, GUI::Align::Default);
		text->SetTextAlign(GUI::Align::Right);

		mPropertiesText[window].push_back(text);
	}
	else
	{
		text = mPropertiesText[window][mPairsCounter-1];
		text->SetVisible(true);
		text->SetCoord(x1, y, w1, h);
	}
	std::string prop = property;
	// trim widget name
	std::string::iterator iterS;
	iterS = std::find(prop.begin(), prop.end(), '_');
	if (iterS != prop.end()) prop.erase(prop.begin(), ++iterS);

	size_t idx = prop.find_last_of(' ');
	if (idx != std::string::npos) prop = prop.substr(idx);

	text->SetCaption(prop);

	if ((mPropertiesElement[window].Size() < mPairsCounter) ||
		(type_names[widget_for_type] != mPropertiesElement[window][mPairsCounter-1]->GetTypeName()))
	{
		if (widget_for_type == PropertyType_Edit)
		{
			editOrCombo = window->CreateWidget<GUI::Edit>("Edit", x2, y, w2, h, GUI::Align::Top | GUI::Align::HStretch);
			editOrCombo->CastType<GUI::Edit>()->eventEditTextChange = NewDelegate (this, &PropertiesPanelView::NotifyTryApplyProperties);
			editOrCombo->CastType<GUI::Edit>()->eventEditSelectAccept = NewDelegate (this, &PropertiesPanelView::NotifyForceApplyProperties);
		}
		else if (widget_for_type == PropertyType_ComboBox)
		{
			editOrCombo = window->CreateWidget<GUI::ComboBox>("ComboBox", x2, y, w2, h, GUI::Align::Top | GUI::Align::HStretch);
			editOrCombo->CastType<GUI::ComboBox>()->eventComboAccept = NewDelegate (this, &PropertiesPanelView::NotifyForceApplyProperties2);

			editOrCombo->CastType<GUI::ComboBox>()->SetComboModeDrop(true);
		}
		else if (widget_for_type == PropertyType_EditAcceptOnly)
		{
			editOrCombo = window->CreateWidget<GUI::Edit>("Edit", x2, y, w2, h, GUI::Align::Top | GUI::Align::HStretch);
			editOrCombo->CastType<GUI::Edit>()->eventEditSelectAccept = NewDelegate (this, &PropertiesPanelView::NotifyForceApplyProperties);
		}

		if (mPropertiesElement[window].Size() < mPairsCounter)
		{
			mPropertiesElement[window].push_back(editOrCombo);
		}
		else
		{
			GUI::Gui::GetInstance().DestroyWidget(mPropertiesElement[window][mPairsCounter-1]);
			mPropertiesElement[window][mPairsCounter-1] = editOrCombo;
		}
	}
	else
	{
		editOrCombo = mPropertiesElement[window][mPairsCounter-1];
		if (widget_for_type == 1) editOrCombo->CastType<GUI::ComboBox>()->RemoveAllItems();
		editOrCombo->SetVisible(true);
		editOrCombo->SetCoord(x2, y, w2, h);
	}

	// fill possible values
	if (widget_for_type == PropertyType_ComboBox)
	{
		std::vector<std::string> values;
		if (type == "Skin") values = WidgetTypes::GetInstance().Find(current_widget->GetTypeName())->skin;
		else values = WidgetTypes::GetInstance().FindPossibleValues(type);

		for (std::vector<std::string>::iterator iter = values.begin(); iter != values.end(); ++iter)
			editOrCombo->CastType<GUI::ComboBox>()->AddItem(*iter);
	}

	editOrCombo->SetUserString("action", property);
	editOrCombo->SetUserString("type", type);

	if (value.empty())
	{
		editOrCombo->SetCaption(DEFAULT_VALUE);
	}
	else
	{
		editOrCombo->CastType<GUI::Edit>()->SetOnlyText(value);
		CheckType(editOrCombo->CastType<GUI::Edit>(), type);
	}
}

void PropertiesPanelView::SetPositionText(const std::string& caption)
{
	GUI::Widget* window = mPanelMainProperties->GetMainWidget();
	if (window)
	{
		mPropertiesElement[window][1]->SetCaption(caption);
	}
}

bool PropertiesPanelView::CheckType(GUI::Edit* edit, const std::string& type)
{
	bool success = true;
	if ("Name" == type)
	{
		const GUI::UString & text = edit->GetOnlyText();
		size_t index = edit->GetTextCursor();
		WidgetContainer * textWC = EditorWidgets::GetInstance().Find(text);
		if ((!text.empty()) && (nullptr != textWC) &&
			(EditorWidgets::GetInstance().Find(current_widget) != textWC))
		{
			static const GUI::UString colour = ERROR_VALUE;
			edit->SetCaption(colour + text);
			success = false;
		}
		else
		{
			edit->SetCaption(text);
			success = true;
		}
		edit->SetTextCursor(index);
	}
	//else if ("Skin" == type) widget_for_type = PropertyType_ComboBox;
	//else
	if ("Position" == type)
	{
		if (EditorWidgets::GetInstance().Find(current_widget)->relative_mode)
			success = Parse::CheckParse<float>(edit, 4);
		else
			success = Parse::CheckParse<int>(edit, 4);
	}
	
	
	
	else if ("1 int" == type) success = Parse::CheckParse<int>(edit, 1);
	else if ("2 int" == type) success = Parse::CheckParse<int>(edit, 2);
	else if ("4 int" == type) success = Parse::CheckParse<int>(edit, 4);
	else if ("alpha" == type) success = Parse::CheckParseInterval<float>(edit, 1, 0., 1.);
	else if ("1 float" == type) success = Parse::CheckParse<float>(edit, 1);
	else if ("2 float" == type) success = Parse::CheckParse<float>(edit, 2);
	
	//else if ("Colour" == type) success = Parse::CheckParse<float>(edit, 4);
	else if ("FileName" == type) success = Parse::CheckParseFileName(edit);
	return success;
}

void PropertiesPanelView::NotifyApplyProperties(GUI::Widget* sender, bool force)
{
	EditorWidgets * ew = &EditorWidgets::GetInstance();
	WidgetContainer * widgetContainer = ew->Find(current_widget);
	GUI::Edit* senderEdit = sender->CastType<GUI::Edit>();
	std::string action = senderEdit->GetUserString("action");
	std::string value = senderEdit->GetOnlyText();
	std::string type = senderEdit->GetUserString("type");

	ON_EXIT(UndoManager::GetInstance().AddValue(PR_PROPERTIES););

	bool goodData = CheckType(senderEdit, type);

	if (value == DEFAULT_STRING && senderEdit->GetCaption() == DEFAULT_VALUE) value = "";

	if (action == "Name")
	{
		if (goodData)
		{
			widgetContainer->name = value;
			ew->widgets_changed = true;
		}
		return;
	}
	else if (action == "Skin")
	{
		widgetContainer->skin = value;
		if ( GUI::SkinManager::GetInstance().IsExist(widgetContainer->skin) || widgetContainer->skin.empty())
		{
			GUI::xml::Document * savedDoc = ew->SavexmlDocument();
			ew->Clear();
			ew->LoadxmlDocument(savedDoc);
			delete savedDoc;
			eventRecreate();
		}
		else
		{
			std::string mess = GUI::utility::ToString("Skin '", widgetContainer->skin, "' not found. This value will be saved.");
			GroupMessage::GetInstance().AddMessage(mess, GUI::LogManager::Error);
		}
		return;
	}
	else if (action == "Position")
	{
		if (!goodData) return;
		if (widgetContainer->relative_mode)
		{
			std::istringstream str(value);
			GUI::FloatCoord float_coord;
			str >> float_coord;
			float_coord.left = float_coord.left/100;
			float_coord.top = float_coord.top/100;
			float_coord.width = float_coord.width/100;
			float_coord.height = float_coord.height/100;
			GUI::IntCoord coord = GUI::CoordConverter::ConvertFromRelative(float_coord, current_widget->GetCroppedParent() == nullptr ? GUI::Gui::GetInstance().GetViewSize() : current_widget->GetCroppedParent()->GetSize());
			current_widget->SetCoord(coord);
			current_widget_rectangle->SetCoord(current_widget->GetAbsoluteCoord());
			return;
		}
		widgetContainer->widget->SetProperty("Widget_Coord", value);
		current_widget_rectangle->SetCoord(current_widget->GetAbsoluteCoord());
		return;
	}
	else if (action == "Align")
	{
		widgetContainer->align = value;
		widgetContainer->widget->SetAlign(GUI::Align::Parse(value));
		return;
	}
	else if (action == "Layer")
	{
		widgetContainer->layer = value;
		return;
	}
	else
	{
		std::string tmp = action;
		if (SplitString(tmp, ' ') == "Controller")
		{
			int n = GUI::utility::ParseValue<int>(SplitString(tmp, ' '));
			std::string key = SplitString(tmp, ' ');
			widgetContainer->mController[n]->mProperty[key] = value;
			return;
		}
	}

	bool success = false;
	if (goodData || force)
		success = ew->TryToApplyProperty(widgetContainer->widget, action, value);
	else
		return;

	if (success)
	{
		current_widget_rectangle->SetCoord(current_widget->GetAbsoluteCoord());
	}
	else
	{
		senderEdit->SetCaption(DEFAULT_VALUE);
		return;
	}

	
	for (StringPairs::iterator iterProperty = widgetContainer->mProperty.begin(); iterProperty != widgetContainer->mProperty.end(); ++iterProperty)
	{
		if (iterProperty->first == action)
		{
			if (value.empty()) widgetContainer->mProperty.erase(iterProperty);
			else iterProperty->second = value;
			return;
		}
	}

	
	if (!value.empty()) widgetContainer->mProperty.push_back(std::make_pair(action, value));
}

std::string PropertiesPanelView::SplitString(std::string& str, char separator)
{
	size_t spaceIdx = str.find(separator);
	if (spaceIdx == std::string::npos)
	{
		std::string tmp = str;
		str.clear();
		return tmp;
	}
	else
	{
		std::string tmp = str.substr(0, spaceIdx);
		str.erase(0, spaceIdx + 1);
		return tmp;
	}
}

void PropertiesPanelView::NotifyTryApplyProperties(GUI::Edit* sender)
{
	NotifyApplyProperties(sender, false);
}

void PropertiesPanelView::NotifyForceApplyProperties(GUI::Edit* sender)
{
	NotifyApplyProperties(sender, true);
}

void PropertiesPanelView::NotifyForceApplyProperties2(GUI::ComboBox* sender, size_t index)
{
	NotifyApplyProperties(sender, true);
}
