/*!
    @file
    @author     Albert Semenov
    @date       08/2008
    @module
*/
#include "precompiled.h"
#include "DemoKeeper.h"
#include "Main.h"

#ifdef OGRE_PLATFORM

#include "Ogre/RenderBox/RenderBox.h"

namespace demo
{
	std::vector<wraps::RenderBox*> mRenderBoxes;
}

#endif // OGRE_PLATFORM

namespace demo
{

	DemoKeeper::DemoKeeper() :
		mEditorWindow(nullptr),
		mMainPanel(nullptr),
		mInformationWindow(nullptr),
		mColourWindow(nullptr)
	{
	}

	void DemoKeeper::SetupResources()
	{
		base::BaseManager::SetupResources();
		AddResourceLocation(GetRootMedia() + "/Demos/Demo_Gui");
		AddResourceLocation(GetRootMedia() + "/Common/Scene");
		AddResourceLocation(GetRootMedia() + "/Common/Wallpapers");
	}

	void DemoKeeper::CreateScene()
	{
		CreateDefaultScene();
		return;
		GUI::VectorWidgetPtr& root = GUI::LayoutManager::GetInstance().Load("BackHelp.layout");
		root.at(0)->FindWidget("Text")->SetCaption("Demonstration of using different widgets and Styles (something like Ogre Demo_Gui).");

		mMainPanel = new MainPanel();
		mMainPanel->eventAction = GUI::NewDelegate(this, &DemoKeeper::NotifyEventAction);
		mMainPanel->AddObject("FrameWindow");
		mMainPanel->AddObject("Horizontal Scrollbar");
		mMainPanel->AddObject("Vertical Scrollbar");
		mMainPanel->AddObject("StaticText");
		mMainPanel->AddObject("StaticImage");
		mMainPanel->AddObject("Render to Texture");

		mEditorWindow = new EditorWindow();
    }

	void DemoKeeper::DestroyScene()
	{
		DestroyWindows();
return;
		delete mEditorWindow;
		mEditorWindow = nullptr;
		delete mMainPanel;
		mMainPanel = nullptr;
	}

	void DemoKeeper::DestroyWindows()
	{
		delete mInformationWindow;
		mInformationWindow = nullptr;

		delete mColourWindow;
		mColourWindow = nullptr;
	}

	void DemoKeeper::CreateWindows()
	{
		DestroyWindows();

		mInformationWindow = new InformationWindow(mEditorWindow->GetView());
		mColourWindow = new ColourWindow(mEditorWindow->GetView());
	}

	int GetRand(int min, int max)
	{
		if (max < min) std::swap(max, min);
		int range = max - min;
		if (range == 0) return 0;
		int result = ::rand() % range;
		if (result < 0) result = -result;
		return min + result;
	}

	void DemoKeeper::NotifyEventAction(MainPanel::TypeEvents action, size_t index)
	{
		if (action == MainPanel::EventQuit)
		{
			Quit();
		}
		else if (action == MainPanel::EventNew)
		{

#ifdef OGRE_PLATFORM

			for (std::vector<wraps::RenderBox*>::iterator item=mRenderBoxes.begin(); item!=mRenderBoxes.end(); ++item)
			{
				delete *item;
			}
			mRenderBoxes.Clear();

#endif // OGRE_PLATFORM

			DestroyWindows();
			mEditorWindow->ClearView();
		}
		else if (action == MainPanel::EventLoad)
		{
			CreateWindows();
		}
		else if (action == MainPanel::EventCreate)
		{
			GUI::Widget* view = mEditorWindow->GetView();
			const GUI::IntCoord& coord = view->GetClientCoord();

			if (index == 0)
			{
				const GUI::IntSize size(80, 80);
				GUI::Window* window = view->CreateWidget<GUI::Window>(GUI::WidgetStyle::Overlapped, "WindowCS", GUI::IntCoord(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height), size.width, size.height), GUI::Align::Default);
				window->SetCaption("Frame");
				window->SetMinSize(size.width, size.height);
			}
			else if (index == 1)
			{
				const GUI::IntSize size(180, 15);
				GUI::HScroll* scroll = view->CreateWidget<GUI::HScroll>("HScroll", GUI::IntCoord(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height), size.width, size.height), GUI::Align::Default);
				scroll->SetScrollRange(200);
				scroll->SetScrollPosition(10);
				scroll->SetScrollPage(1);
				scroll->SetScrollViewPage(20);
			}
			else if (index == 2)
			{
				const GUI::IntSize size(15, 180);
				GUI::VScroll* scroll = view->CreateWidget<GUI::VScroll>("VScroll", GUI::IntCoord(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height), size.width, size.height), GUI::Align::Default);
				scroll->SetScrollRange(200);
				scroll->SetScrollPosition(10);
				scroll->SetScrollPage(1);
				scroll->SetScrollViewPage(20);
			}
			else if (index == 3)
			{
				const GUI::IntSize size(80, 26);
				GUI::StaticText* text = view->CreateWidget<GUI::StaticText>("StaticText", GUI::IntCoord(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height), size.width, size.height), GUI::Align::Default);
				text->SetCaption("StaticText");
			}
			else if (index == 4)
			{
				const GUI::IntSize size(50, 50);
				GUI::StaticImage* image = view->CreateWidget<GUI::StaticImage>("StaticImage", GUI::IntCoord(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height), size.width, size.height), GUI::Align::Default);
				image->SetImageInfo("core.png", GUI::IntCoord(50, 203, 50, 50), GUI::IntSize(50, 50));
				image->SetImageIndex(0);
			}
			else if (index == 5)
			{
				const GUI::IntSize size(150, 150);
				GUI::Window* window = view->CreateWidget<GUI::Window>(GUI::WidgetStyle::Overlapped, "WindowC", GUI::IntCoord(GetRand(0, coord.width - size.width), GetRand(0, coord.height - size.height), size.width, size.height), GUI::Align::Default);
				window->SetCaption("Render");
				GUI::Canvas* canvas = window->CreateWidget<GUI::Canvas>("Canvas", GUI::IntCoord(0, 0, window->GetClientCoord().width, window->GetClientCoord().height), GUI::Align::Stretch);

#ifdef OGRE_PLATFORM

				wraps::RenderBox* box = new wraps::RenderBox();
				box->SetCanvas(canvas);
				box->SetViewport(getCamera());
				box->SetBackgroundColour(GUI::Colour::Black);
				mRenderBoxes.push_back(box);

#endif // OGRE_PLATFORM

			}
		}
	}

} // namespace demo

APP(demo::DemoKeeper)
