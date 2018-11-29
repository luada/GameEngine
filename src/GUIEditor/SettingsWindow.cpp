#include "precompiled.h"
#include "SettingsWindow.h"
//#include "BasisManager.h"
extern int grid_step;//FIXME_HOOK

SettingsWindow::SettingsWindow() : BaseLayout("SettingsWindow.layout")
{
	AssignWidget(mGridEdit, "gridEdit");
	AssignWidget(mButtonOkSettings, "buttonOkSettings");
	//assignWidget(mComboboxResolution, "comboboxResolution");
	//assignWidget(mComboboxFullscreen, "comboboxFullscreen");
	AssignWidget(mCheckShowName, "checkShowName");
	AssignWidget(mCheckShowType, "checkShowType");
	AssignWidget(mCheckShowSkin, "checkShowSkin");
	AssignWidget(mCheckEdgeHide, "checkEdgeHide");

	mGridEdit->eventEditSelectAccept = GUI::NewDelegate(this, &SettingsWindow::NotifyNewGridStepAccept);
	mGridEdit->eventKeyLostFocus = GUI::NewDelegate(this, &SettingsWindow::NotifyNewGridStep);
	mButtonOkSettings->eventMouseButtonClick = GUI::NewDelegate(this, &SettingsWindow::NotifyOkSettings);

	/*Ogre::ConfigOptionMap map = Ogre::Root::GetSingletonPtr()->GetRenderSystem()->GetConfigOptions();
	Ogre::ConfigOptionMap::iterator iter = map.Find("Video Mode");
	int selectedIdx = 0;
	int wid, hei;
	for (unsigned int j = 0; j<iter->second.possibleValues.Size();j++)
	{
		std::string videoMode = iter->second.possibleValues[j];
		std::string tmp;
		std::istringstream Str(videoMode);
		str >> wid >> tmp >> hei;
		If(iter->second.possibleValues[j] == iter->second.currentValue)
			selectedIdx = j;
		mComboboxResolution->AddItem(GUI::utility::ToString(wid, " x ", hei));
	}
	mComboboxResolution->SetIndexSelected(selectedIdx);

	iter = map.Find("Full Screen");
	selectedIdx = 0;
	for (size_t j = 0; j<iter->second.possibleValues.Size();j++)
	{
		std::string videoMode = iter->second.possibleValues[j];
		If(iter->second.possibleValues[j] == iter->second.currentValue)
			selectedIdx = j;
		mComboboxFullscreen->AddItem(videoMode);
	}
	mComboboxFullscreen->SetIndexSelected(selectedIdx);*/

	mCheckShowName->eventMouseButtonClick = GUI::NewDelegate(this, &SettingsWindow::NotifyToggleCheck);
	mCheckShowType->eventMouseButtonClick = GUI::NewDelegate(this, &SettingsWindow::NotifyToggleCheck);
	mCheckShowSkin->eventMouseButtonClick = GUI::NewDelegate(this, &SettingsWindow::NotifyToggleCheck);
	mCheckEdgeHide->eventMouseButtonClick = GUI::NewDelegate(this, &SettingsWindow::NotifyToggleCheck);
}

void SettingsWindow::Load(GUI::xml::ElementEnumerator field)
{
	GUI::xml::ElementEnumerator curField = field->GetElementEnumerator();
	while (curField.Next())
	{
		std::string key, value;

		if (curField->GetName() == "Property")
		{
			if (!curField->findAttribute("key", key)) continue;
			if (!curField->findAttribute("value", value)) continue;

			if (key == "Grid")
				grid_step = GUI::utility::ParseInt(value);
			else if (key == "ShowName")
				SetShowName(GUI::utility::ParseBool(value));
			else if (key == "ShowType")
				SetShowType(GUI::utility::ParseBool(value));
			else if (key == "ShowSkin")
				SetShowSkin(GUI::utility::ParseBool(value));
			else if (key == "EdgeHide")
				SetEdgeHide(GUI::utility::ParseBool(value));
		}
	}

	if (grid_step <= 0) grid_step = 1;
	mGridEdit->SetCaption(GUI::utility::ToString(grid_step));
}

void SettingsWindow::Save(GUI::xml::ElementPtr root)
{
	root = root->CreateChild("SettingsWindow");
	GUI::xml::ElementPtr nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "Grid");
	nodeProp->AddAttribute("value", grid_step);

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "ShowName");
	nodeProp->AddAttribute("value", GetShowName());

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "ShowType");
	nodeProp->AddAttribute("value", GetShowType());

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "ShowSkin");
	nodeProp->AddAttribute("value", GetShowSkin());

	nodeProp = root->CreateChild("Property");
	nodeProp->AddAttribute("key", "EdgeHide");
	nodeProp->AddAttribute("value", GetEdgeHide());
}

void SettingsWindow::NotifyNewGridStep(GUI::Widget* sender, GUI::Widget* newWidget)
{
	grid_step = GUI::utility::ParseInt(sender->GetCaption());
	if (grid_step <= 0) grid_step = 1;
	sender->SetCaption(GUI::utility::ToString(grid_step));
}

void SettingsWindow::NotifyNewGridStepAccept(GUI::Edit* sender)
{
	NotifyNewGridStep(sender);
}

void SettingsWindow::NotifyOkSettings(GUI::Widget* sender)
{
	//bool fullscreen;
	//int width, height;
	//std::string tmp;
	//std::istringstream Str(mComboboxResolution->GetCaption());
	//str >> width >> tmp >> height;
	//fullscreen = (mComboboxFullscreen->GetCaption() == "Yes");
	//BasisManager::GetInstance().SetFullscreen(fullscreen);//setFullscreen, width, height);
	mMainWidget->SetVisible(false);
}

void SettingsWindow::NotifyToggleCheck(GUI::Widget* sender)
{
	GUI::Button* checkbox = sender->CastType<GUI::Button>();
	checkbox->SetButtonPressed(!checkbox->GetButtonPressed());
	eventWidgetsUpdate();
}
