#include "precompiled.h"
#include "EditorToolTip.h"
#include "SkinManager.h"

EditorToolTip::EditorToolTip() : BaseLayout("EditorToolTip.layout")
{
	AssignWidget(mText, "Text");

	minWidth = GUI::utility::ParseInt(mMainWidget->GetUserString("minWidth"));
	minHeight = GUI::utility::ParseInt(mMainWidget->GetUserString("minHeight"));
	lastWidget = nullptr;
}

void EditorToolTip::Show(const GUI::UString & text, const GUI::IntPoint & point)
{
	if (text.empty()) return;

	SetPosition(point);
	mText->SetCaption(GUI::LanguageManager::GetInstance().ReplaceTags(text));
	mMainWidget->SetVisible(true);
}

void EditorToolTip::Show(GUI::Widget* sender, const GUI::IntPoint & point)
{
	static const GUI::UString colour_error = GUI::LanguageManager::GetInstance().GetTag("ColourError");
	static const GUI::UString colour_success = GUI::LanguageManager::GetInstance().GetTag("ColourSuccess");

	std::string widget = sender->GetUserString("widget");
	bool exist = GUI::WidgetManager::GetInstance().IsFactoryExist(widget);
	std::string skin = sender->GetUserString("skin");
	std::string text = "Widget: " + (exist ? colour_success : colour_error) + widget + colour_success +
		"\nSkin: " + skin +
		"\nDefaultSize: " + sender->GetUserString("width") + " x " + sender->GetUserString("height")
		;

	mText->SetCaption(text);

	int width = GUI::utility::ParseInt(sender->GetUserString("width"));
	int height = GUI::utility::ParseInt(sender->GetUserString("height"));

	const int MARGIN = 5;
	const int LINE_HEIGHT = 22;
	const int LINES = 3;

	
	GUI::SkinManager & manager = GUI::SkinManager::GetInstance();
	if (manager.IsExist(skin))
	{
		
		GUI::IntSize max_size;

		GUI::ResourceSkin* info = manager.GetByName(skin);
		if (info != nullptr)
		{
			const GUI::VectorChildSkinInfo & child = info->GetChild();
			for (size_t pos=0; pos<child.size(); ++pos)
			{
				const std::string& child_skin = child[pos].skin;
				if (!manager.IsExist(child_skin)) continue;
				const GUI::ResourceSkin * child_info = manager.GetByName(child_skin);
				const GUI::IntSize & child_size = child[pos].coord.Size();
				GUI::IntSize dif_size = child_info->GetSize() - child_size;

				if (max_size.width < dif_size.width) max_size.width = dif_size.width;
				if (max_size.height < dif_size.height) max_size.height = dif_size.height;
			}
		}

		
		width += max_size.width;
		height += max_size.height;
	}

	mMainWidget->SetSize(std::max(minWidth, width + 2*MARGIN), std::max(minHeight, height + LINE_HEIGHT*LINES + 2*MARGIN));
	if (lastWidget) GUI::Gui::GetInstance().DestroyWidget(lastWidget);
	lastWidget = mMainWidget->CreateWidgetT("Widget", skin, MARGIN, MARGIN + LINE_HEIGHT*LINES, width, height, GUI::Align::Default);
	lastWidget->SetCaption(skin);

	SetPosition(point);
	mMainWidget->SetVisible(true);
}

void EditorToolTip::Hide()
{
	mMainWidget->SetVisible(false);
}

void EditorToolTip::SetPosition(const GUI::IntPoint & point)
{
	const GUI::IntPoint offset(10, 10);

	GUI::IntPoint curPoint = point + offset;
	GUI::Gui * gui = GUI::Gui::GetInstancePtr();

	const GUI::IntSize & size = mMainWidget->GetSize();

	if ((curPoint.left + size.width) > gui->GetViewSize().width)
	{
		curPoint.left -= offset.left + offset.left + size.width;
	}
	if ((curPoint.top + size.height) > gui->GetViewSize().height)
	{
		curPoint.top -= offset.top + offset.top + size.height;
	}

	mMainWidget->SetPosition(curPoint);
}
