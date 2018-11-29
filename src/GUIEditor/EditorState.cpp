#include "precompiled.h"
#include "EditorState.h"
#include "EditorWidgets.h"
#include "WidgetTypes.h"
#include "UndoManager.h"
#include "Main.h"
#include "GroupMessage.h"

const std::string LogSection = "LayoutEditor";

const std::wstring settingsFile = L"settings.xml";
const std::wstring userSettingsFile = L"le_user_settings.xml";

const float POSITION_CONTROLLER_TIME = 0.5f;
const int HIDE_REMAIN_PIXELS = 3;

void EventInfo(GUI::Widget* sender, const std::string& key, const std::string& event)
{
	GUI::GUI_OUT("eventInfo: ", event);
}

template<typename Type>
class PtrHolder
{
public:
	PtrHolder(Type* data) : mData(data) { }
	~PtrHolder() { delete mData; }
private:
	Type* mData;
};

//===================================================================================
void EditorState::SetupResources()
{
	base::BaseManager::SetupResources();
	AddResourceLocation(GetRootMedia() + "/Tools/LayoutEditor");
	AddResourceLocation(GetRootMedia() + "/Tools/LayoutEditor/Panels");
	AddResourceLocation(GetRootMedia() + "/Tools/LayoutEditor/Themes");
	AddResourceLocation(GetRootMedia() + "/Tools/LayoutEditor/Settings");
	AddResourceLocation(GetRootMedia() + "/Common/Wallpapers");
	SetResourceFilename("editor.xml");
}
//===================================================================================
void EditorState::CreateScene()
{
	GetStatisticInfo()->SetVisible(false);

	GUI::LogManager::RegisterSection(LogSection, "GUI.log");

	//FIXME
	// set locale language if it was taken from OS
	//if (! BasisManager::GetInstance().GetLanguage().empty() )
	//	GUI::LanguageManager::GetInstance().SetCurrentLanguage(BasisManager::GetInstance().GetLanguage());
	// if you want to test LanguageManager uncomment next line
	//GUI::LanguageManager::GetInstance().SetCurrentLanguage("Russian");
	testMode = false;

	wt = new WidgetTypes();
	wt->Initialise();
	ew = new EditorWidgets();
	ew->Initialise();
	um = new UndoManager();
	um->Initialise(ew);
	mGroupMessage = new GroupMessage();

	GUI::ResourceManager::GetInstance().Load("initialise.xml");

	mToolTip = new EditorToolTip();
	//GUI::DelegateManager::GetInstance().AddDelegate("eventInfo", GUI::NewDelegate(eventInfo));
	//GUI::DelegateManager::GetInstance().AddDelegate("eventEditorToolTip", GUI::NewDelegate(this, &EditorState::NotifyToolTip));

	interfaceWidgets = GUI::LayoutManager::GetInstance().LoadLayout("interface.layout", "LayoutEditor_");

	// settings window
	mSettingsWindow = new SettingsWindow();
	mSettingsWindow->eventWidgetsUpdate = GUI::NewDelegate(this, &EditorState::NotifyWidgetsUpdate);
	interfaceWidgets.push_back(mSettingsWindow->GetMainWidget());

	// properties panelView
	mPropertiesPanelView = new PropertiesPanelView();
	mPropertiesPanelView->eventRecreate = GUI::NewDelegate(this, &EditorState::NotifyRecreate);
	interfaceWidgets.push_back(mPropertiesPanelView->GetMainWidget());

	mWidgetsWindow = new WidgetsWindow();
	mWidgetsWindow->eventToolTip = GUI::NewDelegate(this, &EditorState::NotifyToolTip);
	mWidgetsWindow->eventSelectWidget = GUI::NewDelegate(this, &EditorState::NotifySelectWidget);
	interfaceWidgets.push_back(mWidgetsWindow->GetMainWidget());

	mMetaSolutionWindow = new MetaSolutionWindow();
	mMetaSolutionWindow->eventLoadFile = GUI::NewDelegate(this, &EditorState::SaveOrLoadLayoutEvent<false>);
	mMetaSolutionWindow->eventSelectWidget = GUI::NewDelegate(this, &EditorState::NotifySelectWidget);
	interfaceWidgets.push_back(mMetaSolutionWindow->GetMainWidget());

	mOpenSaveFileDialog = new common::OpenSaveFileDialog();
	mOpenSaveFileDialog->SetVisible(false);
	mOpenSaveFileDialog->SetFileMask("*.layout");
	mOpenSaveFileDialog->eventEndDialog = GUI::NewDelegate(this, &EditorState::NotifyOpenSaveEndDialog);

	LoadSettings(settingsFile, true);
	LoadSettings(userSettingsFile, false);

	
	CreateMainMenu();

	mPropertiesPanelView->GetMainWidget()->SetCoord(
		GetGUI()->GetViewSize().width - mPropertiesPanelView->GetMainWidget()->GetSize().width,
		bar->GetHeight(),
		mPropertiesPanelView->GetMainWidget()->GetSize().width,
		GetGUI()->GetViewHeight() - bar->GetHeight()
		);

	
	mWidgetsWindow->Initialise();

	if (mSettingsWindow->GetEdgeHide())
	{
		for (GUI::VectorWidgetPtr::iterator iter = interfaceWidgets.begin(); iter != interfaceWidgets.end(); ++iter)
		{
			GUI::ControllerItem* item = GUI::ControllerManager::GetInstance().CreateItem(GUI::ControllerEdgeHide::GetClassTypeName());
			GUI::ControllerEdgeHide* controller = item->CastType<GUI::ControllerEdgeHide>();

			controller->SetTime(POSITION_CONTROLLER_TIME);
			controller->SetRemainPixels(HIDE_REMAIN_PIXELS);
			controller->SetShadowSize(3);

			GUI::ControllerManager::GetInstance().AddItem(*iter, controller);
		}
	}

	Clear();

	/*GUI::Widget* mFpsInfo = mGUI->CreateWidget<GUI::Widget>("ButtonSmall", 20, (int)mGUI->GetViewHeight() - 80, 120, 70, GUI::Align::Left | GUI::Align::Bottom, "Main", "fpsInfo");
	mFpsInfo->SetColour(Ogre::ColourValue::White);*/

	//FIXME
	/*typedef std::vector<std::string> Params;
	Params params = BasisManager::GetInstance().GetCommandParams();
	for (Params::iterator iter=params.begin(); iter!=params.end(); ++iter)
	{
		SaveOrLoadLayout(false, false, iter->C_str());
	}*/
	GetGUI()->eventFrameStart += GUI::NewDelegate(this, &EditorState::NotifyFrameStarted);

	for (std::vector<GUI::UString>::iterator iter = additionalPaths.begin(); iter != additionalPaths.end(); ++iter)
	{
		AddResourceLocation(*iter);
	}
}

void EditorState::DestroyScene()
{
	GetGUI()->eventFrameStart -= GUI::NewDelegate(this, &EditorState::NotifyFrameStarted);

	SaveSettings(userSettingsFile);

	delete mPropertiesPanelView;	
	mPropertiesPanelView = nullptr;

	delete mGroupMessage;

	um->Shutdown();
	delete um;		
	um = nullptr;

	ew->Shutdown();
	delete ew;		
	ew = nullptr;

	wt->Shutdown();
	delete wt;						
	wt = nullptr;

	delete mToolTip;				
	mToolTip = nullptr;

	delete mSettingsWindow;			
	mSettingsWindow = nullptr;

	delete mMetaSolutionWindow;		
	mMetaSolutionWindow = nullptr;

	delete mWidgetsWindow;			
	mWidgetsWindow = nullptr;

	delete mOpenSaveFileDialog;		
	mOpenSaveFileDialog = nullptr;

	GUI::LogManager::UnregisterSection(LogSection);
}

void EditorState::CreateMainMenu()
{
	GUI::VectorWidgetPtr menu_items = GUI::LayoutManager::GetInstance().Load("interface_menu.layout");
	ASSERT(menu_items.Size() == 1, "Error load main menu");
	bar = menu_items[0]->CastType<GUI::MenuBar>();
	bar->SetCoord(0, 0, GetGUI()->GetViewSize().width, bar->GetHeight());

	
	GUI::MenuItem* menu_file = bar->GetItemById("File");
	mPopupMenuFile = menu_file->GetItemChild();
	
	if (recentFiles.size())
	{
		GUI::MenuItem* menu_item = mPopupMenuFile->GetItemById("File/Quit");
		for (std::vector<GUI::UString>::reverse_iterator iter = recentFiles.rbegin(); iter != recentFiles.rend(); ++iter)
		{
			mPopupMenuFile->InsertItem(menu_item, *iter, GUI::MenuItemType::Normal, "File/RecentFiles",  *iter);
		}
		
		mPopupMenuFile->InsertItem(menu_item, "", GUI::MenuItemType::Separator);
	}

	
	GUI::MenuItem* menu_item_test = mPopupMenuFile->GetItemById("File/Test");
	menu_item_test->SetCaption(GUI::LanguageManager::GetInstance().ReplaceTags(menu_item_test->GetCaption()));

	
	GUI::MenuItem* menu_widget = bar->GetItemById("Widgets");
	mPopupMenuWidgets = menu_widget->CreateItemChild();
	//FIXME
	mPopupMenuWidgets->SetPopupAccept(true);

	bar->eventMenuCtrlAccept = NewDelegate(this, &EditorState::NotifyPopupMenuAccept);

	interfaceWidgets.push_back(bar);
}

void EditorState::NotifyPopupMenuAccept(GUI::MenuCtrl* sender, GUI::MenuItem* item)
{
	if (mPopupMenuFile == item->GetMenuCtrlParent())
	{
		std::string id = item->GetItemId();

		if (id == "File/Load")
		{
			NotifyLoad();
		}
		else if (id == "File/Save")
		{
			NotifySave();
		}
		else if (id == "File/SaveAs")
		{
			SetModeSaveLoadDialog(true, fileName);
		}
		else if (id == "File/Clear")
		{
			NotifyClear();
		}
		else if (id == "File/Settings")
		{
			NotifySettings();
		}
		else if (id == "File/Test")
		{
			NotifyTest();
		}
		else if (id == "File/RecentFiles")
		{
			SaveOrLoadLayout(false, false, *item->GetItemData<GUI::UString>());
		}
		else if (id == "File/Quit")
		{
			NotifyQuit();
		}
	}
}

//===================================================================================
void EditorState::InjectMouseMove(int absx, int absy, int absz)
{
	if (testMode)
	{
		base::BaseManager::InjectMouseMove(absx, absy, absz);
		return;
	}

	// drop select depth if we moved mouse
	const int DIST = 2;
	if ((abs(x - absx) > DIST) || (abs(y - absy) > DIST))
	{
		selectDepth = 0;
		x = absx;
		y = absy;
	}

	// align to grid if shift not pressed
	int x2, y2;
	if (GUI::InputManager::GetInstance().IsShiftPressed() == false)
	{
		x2 = ToGrid(absx);
		y2 = ToGrid(absy);
	}
	else
	{
		x2 = absx;
		y2 = absy;
	}

	mWidgetsWindow->CreateNewWidget(x2, y2);

	base::BaseManager::InjectMouseMove(absx, absy, absz);
}
//===================================================================================
void EditorState::InjectMousePress(int absx, int absy, GUI::MouseButton id)
{
	if (testMode)
	{
		return base::BaseManager::InjectMousePress(absx, absy, id);
	}

	if (GUI::InputManager::GetInstance().IsModalAny())
	{
		// if we have modal widgets we can't select any widget
		base::BaseManager::InjectMousePress(absx, absy, id);
		return;
	}

	// align to grid if shift not pressed
	int x1, y1;
	if (GUI::InputManager::GetInstance().IsShiftPressed() == false)
	{
		x1 = ToGrid(absx);
		y1 = ToGrid(absy);
	}
	else
	{
		x1 = absx;
		y1 = absy;
	}

	
	mWidgetsWindow->StartNewWidget(x1, y1, id);

	
	//GUI::LayerItemInfoPtr rootItem = nullptr;
	//GUI::Widget* itemWithRect = static_cast<GUI::Widget*>(GUI::LayerManager::GetInstance().FindWidgetItem(absx, absy, rootItem));
	

	GUI::Widget* item = GUI::LayerManager::GetInstance().GetWidgetFromPoint(absx, absy);

	
	if (item && (item->GetParent() != mPropertiesPanelView->GetWidgetRectangle()))
	{
		
		mPropertiesPanelView->GetWidgetRectangle()->SetVisible(false);
		item = GUI::LayerManager::GetInstance().GetWidgetFromPoint(absx, absy);
	}

	if (nullptr != item)
	{
		// find widget registered as container
		while ((nullptr == ew->Find(item)) && (nullptr != item)) item = item->GetParent();
		GUI::Widget* oldItem = item;

		// try to selectin depth
		int depth = selectDepth;
		while (depth && (nullptr != item))
		{
			item = item->GetParent();
			while ((nullptr == ew->Find(item)) && (nullptr != item)) item = item->GetParent();
			depth--;
		}
		if (nullptr == item)
		{
			item = oldItem;
			selectDepth = 0;
		}

		// found widget
		if (nullptr != item)
		{
			NotifySelectWidget(item);
			if (mWidgetsWindow->GetCreatingStatus() != 1)
			{
				//FIXME
				GetGUI()->InjectMouseMove(absx, absy, 0);
			}
		}
		//FIXME
		GetGUI()->InjectMousePress(absx, absy, id);
	}
	else
	{
		//FIXME
		GetGUI()->InjectMousePress(absx, absy, id);
		NotifySelectWidget(nullptr);
	}

	
	if (current_widget && mWidgetsWindow->GetCreatingStatus() == 0)
	{
		mPropertiesPanelView->GetWidgetRectangle()->SetVisible(true);
	}
	else if (mWidgetsWindow->GetCreatingStatus())
	{
		mPropertiesPanelView->GetWidgetRectangle()->SetVisible(false);
	}

	//base::BaseManager::InjectMousePress(absx, absy, id);
}
//===================================================================================
void EditorState::InjectMouseRelease(int absx, int absy, GUI::MouseButton id)
{
	selectDepth++;
	if (testMode)
	{
		base::BaseManager::InjectMouseRelease(absx, absy, id);
		return;
	}

	if (GUI::InputManager::GetInstance().IsModalAny())
	{
	}
	else
	{
		// align to grid if shift not pressed
		int x2, y2;
		if (GUI::InputManager::GetInstance().IsShiftPressed() == false)
		{
			x2 = ToGrid(absx);
			y2 = ToGrid(absy);
		}
		else
		{
			x2 = absx;
			y2 = absy;
		}

		mWidgetsWindow->FinishNewWidget(x2, y2);
	}

	um->DropLastProperty();

	base::BaseManager::InjectMouseRelease(absx, absy, id);
}
//===================================================================================
void EditorState::InjectKeyPress(GUI::KeyCode key, GUI::Char text)
{
	GUI::InputManager& input = GUI::InputManager::GetInstance();

	if (testMode)
	{
		if (input.IsModalAny() == false)
		{
			if (key == GUI::KeyCode::Escape)
			{
				NotifyEndTest();
			}
		}

		GetGUI()->InjectKeyPress(key, text);
		//base::BaseManager::InjectKeyPress(key, text);
		return;
	}

	if (input.IsModalAny())
	{
		if (mOpenSaveFileDialog->IsVisible())
		{
			if (key == GUI::KeyCode::Escape)
				mOpenSaveFileDialog->eventEndDialog(false);
			else if (key == GUI::KeyCode::Return)
				mOpenSaveFileDialog->eventEndDialog(true);
		}
	}
	else
	{
		if (key == GUI::KeyCode::Escape)
		{
			NotifyQuit();
			return;
		}

		if (input.IsControlPressed())
		{
			if (key == GUI::KeyCode::O
				|| key == GUI::KeyCode::L)
				NotifyLoad();
			else if (key == GUI::KeyCode::S)
				NotifySave();
			else if (key == GUI::KeyCode::Z)
			{
				um->Undo();
				NotifySelectWidget(nullptr);
			}
			else if ((key == GUI::KeyCode::Y) || ((input.IsShiftPressed()) && (key == GUI::KeyCode::Z)))
			{
				um->Redo();
				NotifySelectWidget(nullptr);
			}
			else if (key == GUI::KeyCode::T)
			{
				NotifyTest();
				return;
			}
			else if (key == GUI::KeyCode::R)
			{
				mPropertiesPanelView->ToggleRelativeMode();
				return;
			}
		}
	}

	GetGUI()->InjectKeyPress(key, text);
	//base::BaseManager::InjectKeyPress(key, text);
}
//===================================================================================
void EditorState::InjectKeyRelease(GUI::KeyCode key)
{
	if (testMode)
	{
		return base::BaseManager::InjectKeyRelease(key);
	}

	return base::BaseManager::InjectKeyRelease(key);
}
//===================================================================================
void EditorState::NotifyFrameStarted(float time)
{
	GroupMessage::GetInstance().ShowMessages();

	if (ew->widgets_changed)
	{
		NotifyWidgetsUpdate();
		ew->widgets_changed = false;
	}

	if (recreate)
	{
		recreate = false;
		NotifySelectWidget(nullptr); 
	}

	//return base::BaseManager::FrameStarted(evt);
	//return true;
}
//===================================================================================
/*void EditorState::WindowResize()
{
	if (testMode)
		return;

	// force update
	GUI::Widget* current_widget1 = current_widget;
	current_widget = nullptr;
	NotifySelectWidget(current_widget1);
}*/
//===================================================================================
bool EditorState::IsNeedSolutionLoad(GUI::xml::ElementEnumerator field)
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
				return !value.empty();
			}
		}
	}
	return false;
}
//===================================================================================
void EditorState::LoadSettings(const GUI::UString& fileName, bool internal)
{
	std::string _instance = "Editor";

	GUI::xml::Document doc;
	if (internal)
	{
		GUI::IDataStream* data = GUI::DataManager::GetInstance().GetData(fileName);
		if (data)
		{
			PtrHolder<GUI::IDataStream> holder = PtrHolder<GUI::IDataStream>(data);

			if (!doc.Open(data))
			{
				LOGGING(LogSection, Error, _instance << " : " << doc.GetLastError());
				return;
			}
		}
	}
	else
	{
		if (!doc.Open(fileName))
		{
			LOGGING(LogSection, Error, _instance << " : " << doc.GetLastError());
			return;
		}
	}

	GUI::xml::ElementPtr root = doc.GetRoot();
	if (!root || (root->GetName() != "GUI"))
	{
		LOGGING(LogSection, Error, _instance << " : '" << fileName << "', tag 'GUI' not found");
		return;
	}

	std::string type;
	if (root->findAttribute("type", type))
	{
		if (type == "Settings")
		{
			
			GUI::xml::ElementEnumerator field = root->GetElementEnumerator();
			while (field.Next())
			{
				if (field->GetName() == "PropertiesPanelView") mPropertiesPanelView->Load(field);
				else if (field->GetName() == "SettingsWindow") mSettingsWindow->Load(field);
				else if (field->GetName() == "WidgetsWindow") mWidgetsWindow->Load(field);
				else if (field->GetName() == "MetaSolutionWindow")
				{
					if (IsNeedSolutionLoad(field))
					{
						ClearWidgetWindow();
						mMetaSolutionWindow->Load(field);
					}
				}
				else if (field->GetName() == "RecentFile")
				{
					std::string name;
					if (!field->findAttribute("name", name)) continue;
					recentFiles.push_back(name);
				}
				else if (field->GetName() == "AdditionalPath")
				{
					std::string name;
					if (!field->findAttribute("name", name)) continue;
					additionalPaths.push_back(name);
				}
			}
		}
	}
}

void EditorState::SaveSettings(const GUI::UString& fileName)
{
	std::string _instance = "Editor";

	GUI::xml::Document doc;
	doc.CreateDeclaration();
	GUI::xml::ElementPtr root = doc.CreateRoot("GUI");
	root->AddAttribute("type", "Settings");

	mPropertiesPanelView->Save(root);
	mSettingsWindow->Save(root);
	mWidgetsWindow->Save(root);
	mMetaSolutionWindow->Save(root);

	// cleanup for duplicates

	std::reverse(recentFiles.begin(), recentFiles.end());
	for (size_t i = 0; i < recentFiles.size(); ++i)
		recentFiles.erase(std::remove(recentFiles.begin() + i + 1, recentFiles.end(), recentFiles[i]), recentFiles.end());

	// remove old files
	while (recentFiles.size() > MAX_RECENT_FILES)
		recentFiles.pop_back();
	std::reverse(recentFiles.begin(), recentFiles.end());

	for (std::vector<GUI::UString>::iterator iter = recentFiles.begin(); iter != recentFiles.end(); ++iter)
	{
		GUI::xml::ElementPtr nodeProp = root->CreateChild("RecentFile");
		nodeProp->AddAttribute("name", *iter);
	}

	for (std::vector<GUI::UString>::iterator iter = additionalPaths.begin(); iter != additionalPaths.end(); ++iter)
	{
		GUI::xml::ElementPtr nodeProp = root->CreateChild("AdditionalPath");
		nodeProp->AddAttribute("name", *iter);
	}

	if (!doc.Save(fileName))
	{
		LOGGING(LogSection, Error, _instance << " : " << doc.GetLastError());
		return;
	}
}

void EditorState::NotifyLoad()
{
	if (um->IsUnsaved())
	{
		GUI::Message* message = GUI::Message::CreateMessageBox(
			"Message",
			GUI::Localise("Warning"),
			GUI::Localise("Warn_unsaved_data"),
			GUI::MessageBoxStyle::IconWarning |
			GUI::MessageBoxStyle::Yes | GUI::MessageBoxStyle::No | GUI::MessageBoxStyle::Cancel
			);
		message->eventMessageBoxResult = NewDelegate(this, &EditorState::NotifyConfirmLoadMessage);
		message->SetUserString("FileName", fileName);
		return;
	}

	SetModeSaveLoadDialog(false, fileName);
}

bool EditorState::NotifySave()
{
	if (fileName != "")
	{
		return SaveOrLoadLayout(true, false, fileName);
	}
	else
	{
		SetModeSaveLoadDialog(true, fileName);
		return false;
	}
}

void EditorState::NotifySettings()
{
	mSettingsWindow->SetVisible(true);
	GUI::LayerManager::GetInstance().UpLayerItem(mSettingsWindow->GetMainWidget());
}

void EditorState::NotifyTest()
{
	for (GUI::VectorWidgetPtr::iterator iter = interfaceWidgets.begin(); iter != interfaceWidgets.end(); ++iter)
	{
		if ((*iter)->IsVisible())
		{
			(*iter)->SetUserString("WasVisible", "true");
			(*iter)->SetVisible(false);
		}
	}
	testLayout = ew->SavexmlDocument();
	ew->Clear();
	NotifySelectWidget(nullptr);
	ew->LoadxmlDocument(testLayout, true);
	testMode = true;
}

void EditorState::NotifyEndTest()
{
	for (GUI::VectorWidgetPtr::iterator iter = interfaceWidgets.begin(); iter != interfaceWidgets.end(); ++iter)
	{
		if ((*iter)->GetUserString("WasVisible") == "true")
		{
			(*iter)->SetVisible(true);
		}
	}
	testMode = false;
	Clear(false);
	ew->LoadxmlDocument(testLayout);
}

void EditorState::NotifyClear()
{
	GUI::Message* message = GUI::Message::CreateMessageBox("Message", GUI::Localise("Warning"), GUI::Localise("Warn_delete_all_widgets"), GUI::MessageBoxStyle::IconWarning | GUI::MessageBoxStyle::Yes | GUI::MessageBoxStyle::No);
	message->eventMessageBoxResult = NewDelegate(this, &EditorState::NotifyClearMessage);
}

void EditorState::NotifyClearMessage(GUI::Message* sender, GUI::MessageBoxStyle result)
{
	if (result == GUI::MessageBoxStyle::Yes || result == GUI::MessageBoxStyle::Button1)
	{
		Clear();
	}
}

void EditorState::Clear(bool clearName)
{
	mWidgetsWindow->ClearNewWidget();
	recreate = false;
	if (clearName) fileName = "";
	testMode = false;
	ew->Clear();
	NotifySelectWidget(nullptr);
	um->Shutdown();
	um->Initialise(ew);
	selectDepth = 0;

	if (clearName)
		SetWindowCaption("GUI Layout Editor");
}

void EditorState::NotifyQuit()
{
	if (um->IsUnsaved())
	{
		GUI::Message* message = GUI::Message::CreateMessageBox(
			"Message",
			GUI::Localise("Warning"),
			GUI::Localise("Warn_unsaved_data"),
			GUI::MessageBoxStyle::IconWarning |
			GUI::MessageBoxStyle::Yes | GUI::MessageBoxStyle::No | GUI::MessageBoxStyle::Cancel
			);
		message->eventMessageBoxResult = NewDelegate(this, &EditorState::NotifyConfirmQuitMessage);
		message->SetUserString("FileName", fileName);
		return;
	}

	
	Quit();
}

void EditorState::NotifyConfirmQuitMessage(GUI::Message* sender, GUI::MessageBoxStyle result)
{
	if ( result == GUI::MessageBoxStyle::Yes )
	{
		if (NotifySave())
		{
			
			Quit();
		}
	}
	else if ( result == GUI::MessageBoxStyle::No )
	{
		
		Quit();
	}
	/*else if ( result == GUI::MessageBoxStyle::Cancel )
	{
		// do nothing
	}
	*/
}

bool EditorState::IsMetaSolution(const GUI::UString& fileName)
{
	GUI::xml::Document doc;
	if (!doc.Open(fileName))
	{
		return false;
	}

	GUI::xml::ElementPtr root = doc.GetRoot();
	if (!root || (root->GetName() != "GUI"))
	{
		return false;
	}

	std::string type;
	if (root->findAttribute("type", type))
	{
		if (type == "MetaSolution")
		{
			return true;
		}
	}

	return false;
}

void EditorState::ClearWidgetWindow()
{
	WidgetTypes::GetInstance().ClearAllSkins();
	mWidgetsWindow->ClearAllSheets();
}

void EditorState::LoadFile(const std::wstring& file)
{
	
	bool solution = IsMetaSolution(GUI::UString(file).AsUTF8_c_str());
	if (solution)
	{
		ClearWidgetWindow();
	}

	if (!SaveOrLoadLayout(false, true, GUI::UString(file).AsUTF8_c_str()))
	{
		GUI::ResourceManager::GetInstance().Load(GUI::UString(file).AsUTF8_c_str()/*, ""*/);
	}

	if (solution)
	{
		this->mWidgetsWindow->Initialise();
	}
}

void EditorState::NotifyConfirmLoadMessage(GUI::Message* sender, GUI::MessageBoxStyle result)
{
	if ( result == GUI::MessageBoxStyle::Yes )
	{
		if (NotifySave())
		{
			SetModeSaveLoadDialog(false, fileName);
		}
	}
	else if ( result == GUI::MessageBoxStyle::No )
	{
		SetModeSaveLoadDialog(false, fileName);
	}
	/*else if ( result == GUI::MessageBoxStyle::Cancel )
	{
		// do nothing
	}
	*/
}

void EditorState::NotifyWidgetsUpdate()
{
	if (mMetaSolutionWindow->IsVisible())
		mMetaSolutionWindow->UpdateList();

	bool print_name = mSettingsWindow->GetShowName();
	bool print_type = mSettingsWindow->GetShowType();
	bool print_skin = mSettingsWindow->GetShowSkin();

	mPopupMenuWidgets->RemoveAllItems();
	mPopupMenuWidgets->eventMenuCtrlAccept = GUI::NewDelegate(this, &EditorState::NotifyWidgetsSelect);

	for (std::vector<WidgetContainer*>::iterator iter = ew->widgets.begin(); iter != ew->widgets.end(); ++iter )
	{
		CreateWidgetPopup(*iter, mPopupMenuWidgets, print_name, print_type, print_skin);
	}
}

void EditorState::CreateWidgetPopup(WidgetContainer* container, GUI::MenuCtrl* parentPopup, bool print_name, bool print_type, bool print_skin)
{
	bool submenu = !container->childContainers.empty();

	parentPopup->AddItem(GetDescriptionString(container->widget, print_name, print_type, print_skin), submenu ? GUI::MenuItemType::Popup : GUI::MenuItemType::Normal);
	parentPopup->SetItemDataAt(parentPopup->GetItemCount()-1, container->widget);

	if (submenu)
	{
		GUI::MenuCtrl* child = parentPopup->CreateItemChildAt(parentPopup->GetItemCount()-1);
		child->eventMenuCtrlAccept = GUI::NewDelegate(this, &EditorState::NotifyWidgetsSelect);
		child->SetPopupAccept(true);

		for (std::vector<WidgetContainer*>::iterator iter = container->childContainers.begin(); iter != container->childContainers.end(); ++iter )
		{
			CreateWidgetPopup(*iter, child, print_name, print_type, print_skin);
		}
	}
}

void EditorState::NotifyWidgetsSelect(GUI::MenuCtrl* sender, GUI::MenuItem* item)
{
	GUI::Widget* widget = *item->GetItemData<GUI::Widget*>();
	NotifySelectWidget(widget);
}

void EditorState::NotifySelectWidget(GUI::Widget* sender)
{
	if (sender == current_widget)
	{
		if (current_widget)
		{
			mPropertiesPanelView->GetWidgetRectangle()->SetVisible(true);
			GUI::InputManager::GetInstance().SetKeyFocusWidget(mPropertiesPanelView->GetWidgetRectangle());
		}
		return;
	}

	current_widget = sender;

	mPropertiesPanelView->Update(sender);
	mWidgetsWindow->Update(sender);
	mMetaSolutionWindow->Update(sender);
}

std::string EditorState::GetDescriptionString(GUI::Widget* widget, bool print_name, bool print_type, bool print_skin)
{
	std::string name = "";
	std::string type = "";
	std::string skin = "";

	WidgetContainer * widgetContainer = ew->Find(widget);
	if (print_name)
	{
		if (widgetContainer->name.empty())
		{
			// trim "LayoutEditorWidget_"
			/*name = widget->GetName();
			if (0 == Strncmp("LayoutEditorWidget_", name.C_str(), 19))
			{
					std::string::iterator iter = std::find(name.begin(), name.end(), '_');
					if (iter != name.end()) name.erase(name.begin(), ++iter);
					name = "#{ColourMenuName}" + name;
			}
			name = "#{ColourMenuName}[" + name + "] ";*/
		}
		else
		{
			name = "#{ColourMenuName}'" + widgetContainer->name + "' ";
		}
	}

	if (print_type)
	{
		type = "#{ColourMenuType}[" + widget->GetTypeName() + "] ";
	}

	if (print_skin)
	{
		skin = "#{ColourMenuSkin}" + widgetContainer->skin + " ";
	}
	return GUI::LanguageManager::GetInstance().ReplaceTags(type + skin + name);
}

void EditorState::NotifyToolTip(GUI::Widget* sender, const GUI::ToolTipInfo & info)
{
	if (info.type == GUI::ToolTipInfo::Show)
	{
		mToolTip->Show(sender, info.point);
	}
	else if (info.type == GUI::ToolTipInfo::Hide)
	{
		mToolTip->Hide();
	}
}

void EditorState::NotifyOpenSaveEndDialog(bool result)
{
	if (result)
	{
		GUI::UString file = mOpenSaveFileDialog->GetCurrentFolder() + L"/" + mOpenSaveFileDialog->GetFileName();
		SaveOrLoadLayout(mModeSaveDialog, false, file);
	}
	else
	{
		mOpenSaveFileDialog->SetVisible(false);
	}
}

void EditorState::SetModeSaveLoadDialog(bool save, const GUI::UString& filename)
{
	if (save)
		mOpenSaveFileDialog->SetDialogInfo(GUI::Localise("Save"), GUI::Localise("Save"));
	else
		mOpenSaveFileDialog->SetDialogInfo(GUI::Localise("Load"), GUI::Localise("Load"));

	size_t pos = filename.find_last_of(L"\\/");
	if (pos == GUI::UString::npos)
	{
		mOpenSaveFileDialog->SetFileName(filename);
	}
	else
	{
		mOpenSaveFileDialog->SetCurrentFolder(filename.substr(0, pos));
		mOpenSaveFileDialog->SetFileName(filename.substr(pos + 1));
	}

	mOpenSaveFileDialog->SetVisible(true);
	mModeSaveDialog = save;
}

bool EditorState::SaveOrLoadLayout(bool Save, bool Silent, const GUI::UString& file)
{
	if (!Save) Clear();

	if ( (Save && ew->Save(file)) ||
		(!Save && ew->Load(file)) )
	{
		fileName = file;
		SetWindowCaption(file + " - GUI Layout Editor");
		recentFiles.push_back(file);

		mOpenSaveFileDialog->SetVisible(false);

		um->AddValue();
		um->SetUnsaved(false);
		return true;
	}
	else if (!Silent)
	{
		std::string saveLoad = Save ? GUI::Localise("Save") : GUI::Localise("Load");
		/*GUI::Message* message =*/ GUI::Message::CreateMessageBox(
			"Message",
			GUI::Localise("Warning"),
			"Failed to " + saveLoad + " curFile '" + file + "'",
			GUI::MessageBoxStyle::IconWarning | GUI::MessageBoxStyle::Ok
			);
	}

	return false;
}

APP(EditorState)
