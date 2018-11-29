#ifndef __SETTINGS_WINDOW_H__
#define __SETTINGS_WINDOW_H__

#include "BaseLayout.h"

class SettingsWindow : public wraps::BaseLayout
{
public:
	SettingsWindow();

	void Load(GUI::xml::ElementEnumerator field);
	void Save(GUI::xml::ElementPtr root);

	int GetGridStep();
	void SetGridStep();

	bool GetShowName() { return mCheckShowName->GetButtonPressed(); }
	bool GetShowType() { return mCheckShowType->GetButtonPressed(); }
	bool GetShowSkin() { return mCheckShowSkin->GetButtonPressed(); }
	bool GetEdgeHide() { return mCheckEdgeHide->GetButtonPressed(); }
	void SetShowName(bool pressed) { mCheckShowName->SetButtonPressed(pressed); }
	void SetShowType(bool pressed) { mCheckShowType->SetButtonPressed(pressed); }
	void SetShowSkin(bool pressed) { mCheckShowSkin->SetButtonPressed(pressed); }
	void SetEdgeHide(bool pressed) { mCheckEdgeHide->SetButtonPressed(pressed); }

	typedef GUI::delegates::CDelegate0 EventInfo;
	EventInfo eventWidgetsUpdate;

	GUI::Widget* GetMainWidget() { return mMainWidget; }
	void SetVisible(bool visible) { mMainWidget->SetVisible(visible); }

private:
	void NotifyNewGridStep(GUI::Widget* sender, GUI::Widget* newWidget = 0);
	void NotifyNewGridStepAccept(GUI::Edit* sender); // calls previous method
	void NotifyOkSettings(GUI::Widget* sender);
	void NotifyToggleCheck(GUI::Widget* sender);
private:
	GUI::Edit* mGridEdit;
	GUI::Button* mButtonOkSettings;
	//GUI::ComboBox* mComboboxResolution;
	//GUI::ComboBox* mComboboxFullscreen;
	GUI::Button* mCheckShowName;
	GUI::Button* mCheckShowType;
	GUI::Button* mCheckShowSkin;
	GUI::Button* mCheckEdgeHide;
};

#endif // __SETTINGS_WINDOW_H__
