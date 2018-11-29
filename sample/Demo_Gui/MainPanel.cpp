#include "precompiled.h"
#include "MainPanel.h"

namespace demo
{

	MainPanel::MainPanel() : BaseLayout("MainPanel.layout")
	{
		mMainWidget->SetPosition(10, 10);

		AssignWidget(mButtonNew, "New");
		AssignWidget(mButtonLoad, "Load");
		AssignWidget(mButtonQuit, "Quit");
		AssignWidget(mComboCreate, "CreateObject");

		mButtonNew->eventMouseButtonClick = GUI::NewDelegate(this, &MainPanel::NotifyMouseButtonClick);
		mButtonLoad->eventMouseButtonClick = GUI::NewDelegate(this, &MainPanel::NotifyMouseButtonClick);
		mButtonQuit->eventMouseButtonClick = GUI::NewDelegate(this, &MainPanel::NotifyMouseButtonClick);
		mComboCreate->eventComboAccept = GUI::NewDelegate(this, &MainPanel::NotifyComboAccept);
	}

	void MainPanel::AddObject(const GUI::UString & name)
	{
		mComboCreate->AddItem(name);
	}

	void MainPanel::NotifyMouseButtonClick(GUI::Widget* sender)
	{
		if (sender == mButtonNew) eventAction(EventNew, 0);
		else if (sender == mButtonLoad) eventAction(EventLoad, 0);
		else if (sender == mButtonQuit) eventAction(EventQuit, 0);
	}

	void MainPanel::NotifyComboAccept(GUI::ComboBox* sender, size_t index)
	{
		eventAction(EventCreate, index);

		mComboCreate->SetIndexSelected(GUI::ITEM_NONE);
		mComboCreate->SetCaption("Select Type");
	}

} // namespace demo
