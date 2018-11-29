#include "precompiled.h"
#include "OpenSaveFileDialog.h"

#include "FileSystemInfo.h"

namespace common
{

	OpenSaveFileDialog::OpenSaveFileDialog() : BaseLayout("OpenSaveFileDialog.layout")
	{
		AssignWidget(mListFiles, "ListFiles");
		AssignWidget(mEditFileName, "EditFileName");
		AssignWidget(mEditCurrentFolder, "EditCurrentFolder");
		AssignWidget(mButtonOpenSave, "ButtonOpenSave");

		mListFiles->eventListChangePosition = GUI::NewDelegate(this, &OpenSaveFileDialog::NotifyListChangePosition);
		mListFiles->eventListSelectAccept = GUI::NewDelegate(this, &OpenSaveFileDialog::NotifyListSelectAccept);
		mEditFileName->eventEditSelectAccept = GUI::NewDelegate(this, &OpenSaveFileDialog::NotifyEditSelectAccept);
		mButtonOpenSave->eventMouseButtonClick = GUI::NewDelegate(this, &OpenSaveFileDialog::NotifyMouseButtonClick);

		mMainWidget->CastType<GUI::Window>()->eventWindowButtonPressed = GUI::NewDelegate(this, &OpenSaveFileDialog::NotifyWindowButtonPressed);

		mFileMask = L"*.*";
		mCurrentFolder = GetSystemCurrentFolder();

		Update();
	}

	void OpenSaveFileDialog::NotifyWindowButtonPressed(GUI::Window* sender, const std::string& name)
	{
		if (name == "close")
			eventEndDialog(false);
	}

	void OpenSaveFileDialog::NotifyEditSelectAccept(GUI::Edit* sender)
	{
		Accept();
	}

	void OpenSaveFileDialog::NotifyMouseButtonClick(GUI::Widget* sender)
	{
		Accept();
	}

	void OpenSaveFileDialog::SetDialogInfo(const GUI::UString& caption, const GUI::UString& button)
	{
		mMainWidget->SetCaption(caption);
		mButtonOpenSave->SetCaption(button);
	}

	void OpenSaveFileDialog::NotifyListChangePosition(GUI::List* sender, size_t index)
	{
		if (index == GUI::ITEM_NONE)
		{
			mEditFileName->SetCaption("");
		}
		else
		{
			FileInfo info = *sender->GetItemDataAt<FileInfo>(index);
			if (!info.folder)
				mEditFileName->SetCaption(info.name);
		}
	}

	void OpenSaveFileDialog::NotifyListSelectAccept(GUI::List* sender, size_t index)
	{
		if (index == GUI::ITEM_NONE) return;

		FileInfo info = *sender->GetItemDataAt<FileInfo>(index);
		if (info.folder)
		{
			if (info.name == L"..")
			{
				size_t curIndex = mCurrentFolder.find_last_of(L"\\/");
				if (curIndex != std::string::npos)
				{
					mCurrentFolder = mCurrentFolder.substr(0, curIndex);
				}
			}
			else
			{
				mCurrentFolder = ConcatenatePath (mCurrentFolder.AsWStr(), info.name);
			}

			Update();
		}
		else
		{
			Accept();
		}
	}

	void OpenSaveFileDialog::Accept()
	{
		mFileName = mEditFileName->GetCaption();
		if (!mFileName.empty())
			eventEndDialog(true);
	}

	void OpenSaveFileDialog::SetCurrentFolder(const GUI::UString& folder)
	{
		mCurrentFolder = folder.empty() ? GUI::UString(GetSystemCurrentFolder()) : folder;

		Update();
	}

	void OpenSaveFileDialog::Update()
	{
		mEditCurrentFolder->SetCaption(mCurrentFolder);

		mListFiles->RemoveAllItems();

		// add all folders first
		VectorFileInfo infos;
		GetSystemFileList(infos, mCurrentFolder, L"*.*");

		for(VectorFileInfo::iterator item=infos.begin(); item!=infos.end(); ++item)
		{
			if ((*item).folder)
				mListFiles->AddItem(L"[" + (*item).name + L"]", *item);
		}

		// add files by given mask
		infos.clear();
		GetSystemFileList(infos, mCurrentFolder, mFileMask);

		for(VectorFileInfo::iterator item=infos.begin(); item!=infos.end(); ++item)
		{
			if (!(*item).folder)
				mListFiles->AddItem((*item).name, *item);
		}
	}

	void OpenSaveFileDialog::SetFileName(const GUI::UString& value)
	{
		mFileName = value;
		mEditFileName->SetCaption(value);
	}

	void OpenSaveFileDialog::SetFileMask(const GUI::UString& value)
	{
		mFileMask = value;

		Update();
	}

} // namespace common
