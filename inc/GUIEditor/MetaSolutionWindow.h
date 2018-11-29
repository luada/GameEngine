#ifndef __META_SOLUTION_WINDOW_H__
#define __META_SOLUTION_WINDOW_H__

#include "BaseLayout.h"

struct MetaWidget
{
	~MetaWidget()
	{
		while (mChilds.size())
		{
			delete *mChilds.rbegin();
			mChilds.pop_back();
		}
	}
	MetaWidget * mParent;
	std::vector<MetaWidget *> mChilds;
	std::string mName;
	std::string mType;
	GUI::Guid mTarget;
};

struct MetaForm
{
	MetaForm() :mCollapsed(true) { }
	~MetaForm()
	{
		while (mChilds.size())
		{
			delete *mChilds.rbegin();
			mChilds.pop_back();
		}
	}
	std::vector<MetaWidget*> mChilds;
	std::string mDecription;
	std::string mLayoutName;
	GUI::Guid mId;

	bool mCollapsed;
};

class MetaSolutionWindow : public wraps::BaseLayout
{
public:
	MetaSolutionWindow();
	~MetaSolutionWindow();

	void Load(GUI::xml::ElementEnumerator field);
	void Save(GUI::xml::ElementPtr root);
	void Update(GUI::Widget* current) { current_widget = current; }

	bool IsVisible() { return mMainWidget->IsVisible(); }
	void SetVisible(bool visible) { mMainWidget->SetVisible(visible); }
	
	void LoadList();
	void UpdateList();

	typedef GUI::delegates::CDelegate1<const GUI::UString &> EventInfo_UString;
	EventInfo_UString eventLoadFile;
	GUI::EventHandle_WidgetVoid eventSelectWidget;

	GUI::Widget* GetMainWidget() { return mMainWidget; }
private:
	void NotifyCloseWindowButton(GUI::Window* sender, const std::string& name);

	void NotifyListSelectAccept(GUI::List* sender, size_t index);
	void NotifyListChangePosition(GUI::List* sender, size_t index);

	void ParseMetaSolution(GUI::xml::ElementPtr node, const std::string& file, GUI::Version version);
	void CloseMetaSolution();
	MetaWidget * ParseMetaWidget(GUI::xml::ElementPtr node, MetaWidget * parent);

	int AddMetaWidgets(std::vector<MetaWidget*> childs, size_t index, std::string level);
	void CollapseAll();
	void LoadTarget(GUI::Guid target);
	bool FindTarget(GUI::Guid target);

	GUI::Widget* CreateWidget(MetaWidget * widget, GUI::Widget* parent);

	GUI::List* mListTree;
	std::string mMetaSolutionName;
	
	GUI::Widget* current_widget;

	std::vector<MetaForm*> mMetaForms;

	typedef std::pair<std::string, std::string> PairString;
	typedef std::map<std::string, PairString> MapPairString;
	MapPairString mWidgetType;

};

#endif // __META_SOLUTION_WINDOW_H__
