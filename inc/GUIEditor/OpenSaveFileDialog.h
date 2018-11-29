#ifndef __OPEN_SAVE_FILE_DIALOG_H__
#define __OPEN_SAVE_FILE_DIALOG_H__

#include <GUI.h>
#include "BaseLayout.h"

namespace common
{

	class OpenSaveFileDialog : public wraps::BaseLayout
	{
	public:
		typedef GUI::delegates::CDelegate1<bool> EventHandle_Result;

	public:
		OpenSaveFileDialog();

		void SetDialogInfo(const GUI::UString& caption, const GUI::UString& button);

		void SetCurrentFolder(const GUI::UString& value = "");
		const GUI::UString& GetCurrentFolder() { return mCurrentFolder; }

		void SetFileMask(const GUI::UString& value);
		const GUI::UString& GetFileMask() const { return mFileMask; }

		void SetFileName(const GUI::UString& value);
		const GUI::UString& GetFileName() const { return mFileName; }

		void SetVisible(bool value) { mMainWidget->SetVisible(value); }
		bool IsVisible() { return mMainWidget->IsVisible(); }

		EventHandle_Result eventEndDialog;

	private:
		void NotifyListChangePosition(GUI::List* sender, size_t index);
		void NotifyListSelectAccept(GUI::List* sender, size_t index);
		void NotifyEditSelectAccept(GUI::Edit* sender);
		void NotifyMouseButtonClick(GUI::Widget* sender);
		void NotifyWindowButtonPressed(GUI::Window* sender, const std::string& name);

		void Update();
		void Accept();

	private:
		GUI::List* mListFiles;
		GUI::Edit* mEditFileName;
		GUI::Edit* mEditCurrentFolder;
		GUI::Button* mButtonOpenSave;

		GUI::UString mCurrentFolder;
		GUI::UString mFileName;
		GUI::UString mFileMask;
	};

} // namespace common

#endif // __OPEN_SAVE_FILE_DIALOG_H__
