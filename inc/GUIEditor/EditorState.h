#ifndef __EDITOR_STATE_H__
#define __EDITOR_STATE_H__

#include "BaseManager.h"
#include "EditorToolTip.h"
#include "PropertiesPanelView.h"
#include "SettingsWindow.h"
#include "WidgetsWindow.h"
#include "MetaSolutionWindow.h"
#include "OpenSaveFileDialog.h"

class EditorWidgets;
class WidgetTypes;
class UndoManager;
struct WidgetContainer;
class GroupMessage;

class EditorState : public base::BaseManager
{
public:

	EditorState() :
		x(0),
		y(0),
		selectDepth(0),
		recreate(0),
		mModeSaveDialog(0),
		testMode(0),
		mToolTip(0),
		mPropertiesPanelView(0),
		mSettingsWindow(0),
		mWidgetsWindow(0),
		mMetaSolutionWindow(0),
		ew(0),
		wt(0),
		um(0),
		mGroupMessage(0)
	{ }
	virtual ~EditorState() { }

	virtual void CreateScene();
	virtual void DestroyScene();
	virtual void SetupResources();

	virtual void InjectMouseMove(int absx, int absy, int absz);
	virtual void InjectMousePress(int absx, int absy, GUI::MouseButton id);
	virtual void InjectMouseRelease(int absx, int absy, GUI::MouseButton id);
	virtual void InjectKeyPress(GUI::KeyCode key, GUI::Char text);
	virtual void InjectKeyRelease(GUI::KeyCode key);

//===================================================================================

	// main panel
	void NotifyLoad();
	bool NotifySave();
	void NotifySettings();
	void NotifyTest();
	void NotifyEndTest();
	void NotifyClear();
	void NotifyQuit();

	template <bool Save>
	void SaveOrLoadLayoutEvent(const GUI::UString& file) { SaveOrLoadLayout(Save, false, file); }

	bool SaveOrLoadLayout(bool Save, bool Silent, const GUI::UString& file);
	void LoadFile(const std::wstring& file);

private:
	void LoadSettings(const GUI::UString& fileName, bool internal);
	void SaveSettings(const GUI::UString& fileName);

	void NotifyConfirmLoadMessage(GUI::Message* sender, GUI::MessageBoxStyle result);

	void NotifyClearMessage(GUI::Message* sender, GUI::MessageBoxStyle result);
	void Clear(bool clearName = true);
	void NotifyConfirmQuitMessage(GUI::Message* sender, GUI::MessageBoxStyle result);

	// menu bar
	void NotifyWidgetsSelect(GUI::MenuCtrl* sender, GUI::MenuItem* item);
	void CreateWidgetPopup(WidgetContainer* container, GUI::MenuCtrl* parentPopup, bool print_name, bool print_type, bool print_skin);
	void NotifyWidgetsUpdate();
	void NotifyOpenSaveEndDialog(bool result);

	void NotifySelectWidget(GUI::Widget* sender);

	void NotifyRecreate() { recreate = true; }

	bool IsNeedSolutionLoad(GUI::xml::ElementEnumerator field);
	bool IsMetaSolution(const GUI::UString& fileName);

	void ClearWidgetWindow();

	void SetModeSaveLoadDialog(bool save, const GUI::UString& filename);

private:
	std::string GetDescriptionString(GUI::Widget* widget, bool print_name, bool print_type, bool print_skin);

	void CreateMainMenu();
	void NotifyPopupMenuAccept(GUI::MenuCtrl* sender, GUI::MenuItem* item);
	void NotifyFrameStarted(float time);

	int ToGrid(int x) { return x / grid_step * grid_step; }

	// tooltips
	void NotifyToolTip(GUI::Widget* sender, const GUI::ToolTipInfo & info);

	// recent files
	static const size_t MAX_RECENT_FILES = 8;
	std::vector<GUI::UString> recentFiles;

	std::vector<GUI::UString> additionalPaths;

	// last click for depth selecting
	int x, y;
	int selectDepth;

	GUI::Widget* current_widget;
	// drop select after skin change
	bool recreate;

	bool mModeSaveDialog;

	// current settings
	//int grid_step;//FIXME_HOOK

	// last loaded/saved file name
	GUI::UString fileName;

	bool testMode;
	GUI::VectorWidgetPtr interfaceWidgets;
	GUI::xml::Document * testLayout;

	EditorToolTip * mToolTip;

	PropertiesPanelView * mPropertiesPanelView;
	SettingsWindow * mSettingsWindow;
	WidgetsWindow * mWidgetsWindow;
	MetaSolutionWindow * mMetaSolutionWindow;
	common::OpenSaveFileDialog* mOpenSaveFileDialog;


	EditorWidgets * ew;
	WidgetTypes * wt;
	UndoManager * um;
	GroupMessage * mGroupMessage;

	GUI::MenuBar* bar;
	GUI::MenuCtrl* mPopupMenuFile;
	GUI::MenuCtrl* mPopupMenuWidgets;
	std::vector<GUI::PopupMenu::ItemInfo> widgetMenus;
};
#endif // __EDITOR_STATE_H__
