#include "Precompiled.h"
#include "Gui.h"
#include "Widget.h"

#include "InputManager.h"
#include "SubWidgetManager.h"
#include "LogManager.h"
#include "SkinManager.h"
#include "WidgetManager.h"
#include "LayerManager.h"
#include "FontManager.h"
#include "ControllerManager.h"
#include "PointerManager.h"
#include "ClipboardManager.h"
#include "LayoutManager.h"
#include "PluginManager.h"
#include "DynLibManager.h"
#include "LanguageManager.h"
#include "ResourceManager.h"
#include "RenderManager.h"
#include "FactoryManager.h"

namespace GUI
{

	const std::string INSTANCE_TYPE_NAME("Gui");

	Gui* Gui::msInstance = nullptr;

	Gui* Gui::GetInstancePtr()
	{
		return msInstance;
	}

	Gui& Gui::GetInstance()
	{
		ASSERT(0 != msInstance, "instance " << INSTANCE_TYPE_NAME << " was not created");
		return (*msInstance);
	}

	Gui::Gui() :
		mIsInitialise(false)
	{
		ASSERT(0 == msInstance, "instance " << INSTANCE_TYPE_NAME << " is exsist");
		msInstance = this;
	}

	Gui::~Gui()
	{
		msInstance = nullptr;
	}

	void Gui::Initialise(const std::string& core, const std::string& logFileName)
	{
		LogManager::RegisterSection(LOG_SECTION, logFileName);

		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");

		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);
		LOG(Info, "* GUI version "
			<< VERSION_MAJOR << "."
			<< VERSION_MINOR << "."
			<< VERSION_PATCH);

		mResourceManager = new ResourceManager();
		mLayerManager = new LayerManager();
		mWidgetManager = new WidgetManager();
		mInputManager = new InputManager();
		mSubWidgetManager = new SubWidgetManager();
		mSkinManager = new SkinManager();
		mFontManager = new FontManager();
		mControllerManager = new ControllerManager();
		mPointerManager = new PointerManager();
		mClipboardManager = new ClipboardManager();
		mLayoutManager = new LayoutManager();
		mDynLibManager = new DynLibManager();
		mPluginManager = new PluginManager();
		mLanguageManager = new LanguageManager();
		mFactoryManager = new FactoryManager();

		mResourceManager->Initialise();
		mLayerManager->Initialise();
		mWidgetManager->Initialise();
		mInputManager->Initialise();
		mSubWidgetManager->Initialise();
		mSkinManager->Initialise();
		mFontManager->Initialise();
		mControllerManager->Initialise();
		mPointerManager->Initialise();
		mClipboardManager->Initialise();
		mLayoutManager->Initialise();
		mDynLibManager->Initialise();
		mPluginManager->Initialise();
		mLanguageManager->Initialise();
		mFactoryManager->Initialise();

		WidgetManager::GetInstance().RegisterUnlinker(this);

		if ( core.empty() == false ) mResourceManager->Load(core);

		mViewSize = RenderManager::GetInstance().GetViewSize();
		ResizeWindow(mViewSize);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void Gui::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		_destroyAllChildWidget();

		mPointerManager->Shutdown();
		mInputManager->Shutdown();
		mSkinManager->Shutdown();
		mSubWidgetManager->Shutdown();
		mLayerManager->Shutdown();
		mFontManager->Shutdown();
		mControllerManager->Shutdown();
		mClipboardManager->Shutdown();
		mLayoutManager->Shutdown();
		mPluginManager->Shutdown();
		mDynLibManager->Shutdown();
		mLanguageManager->Shutdown();
		mResourceManager->Shutdown();
		mFactoryManager->Shutdown();

		WidgetManager::GetInstance().UnregisterUnlinker(this);
		mWidgetManager->Shutdown();

		delete mPointerManager;
		delete mWidgetManager;
		delete mInputManager;
		delete mSkinManager;
		delete mSubWidgetManager;
		delete mLayerManager;
		delete mFontManager;
		delete mControllerManager;
		delete mClipboardManager;
		delete mLayoutManager;
		delete mDynLibManager;
		delete mPluginManager;
		delete mLanguageManager;
		delete mResourceManager;
		delete mFactoryManager;

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");

		// last gui log
		LogManager::UnregisterSection(LOG_SECTION);

		mIsInitialise = false;
	}

	bool Gui::InjectMouseMove(int absx, int absy, int absz) { return mInputManager->InjectMouseMove(absx, absy, absz); }
	bool Gui::InjectMousePress(int absx, int absy, MouseButton id) { return mInputManager->InjectMousePress(absx, absy, id); }
	bool Gui::InjectMouseRelease(int absx, int absy, MouseButton id) { return mInputManager->InjectMouseRelease(absx, absy, id); }

	bool Gui::InjectKeyPress(KeyCode key, Char text) { return mInputManager->InjectKeyPress(key, text); }
	bool Gui::InjectKeyRelease(KeyCode key) { return mInputManager->InjectKeyRelease(key); }


	Widget* Gui::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		Widget* widget = WidgetManager::GetInstance().CreateWidget(style, type, skin, coord, align, nullptr, nullptr, this, name);
		mWidgetChild.push_back(widget);
		if (!layer.empty()) LayerManager::GetInstance().AttachToLayerNode(layer, widget);
		return widget;
	}

	Widget* Gui::findWidgetT(const std::string& name, bool _throw)
	{
		for (VectorWidgetPtr::iterator iter = mWidgetChild.begin(); iter!=mWidgetChild.end(); ++iter)
		{
			Widget* widget = (*iter)->FindWidget(name);
			if (widget != nullptr) return widget;
		}
		ASSERT(!_throw, "Widget '" << name << "' not found");
		return nullptr;
	}

	void Gui::_destroyChildWidget(Widget* widget)
	{
		ASSERT(nullptr != widget, "invalid curWidget pointer");

		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), widget);
		if (iter != mWidgetChild.end())
		{
			GUI::Widget* curWidget = *iter;

			*iter = mWidgetChild.back();
			mWidgetChild.pop_back();

			mWidgetManager->UnlinkFromUnlinkers(widget);

			_deleteWidget(curWidget);
		}
		else EXCEPT("Widget '" << widget->GetName() << "' not found");
	}

	void Gui::_destroyAllChildWidget()
	{
		while (!mWidgetChild.empty())
		{
			Widget* widget = mWidgetChild.back();
			mWidgetChild.pop_back();

			//widget->DetachWidget();

			mWidgetManager->UnlinkFromUnlinkers(widget);

			_deleteWidget(widget);
		}
	}

	bool Gui::Load(const std::string& file)
	{
		return mResourceManager->Load(file);
	}

	void Gui::DestroyWidget(Widget* widget)
	{
		mWidgetManager->DestroyWidget(widget);
	}

	void Gui::DestroyWidgets(VectorWidgetPtr& widgets)
	{
		mWidgetManager->DestroyWidgets(widgets);
	}

	void Gui::DestroyWidgets(EnumeratorWidgetPtr& widgets)
	{
		mWidgetManager->DestroyWidgets(widgets);
	}

	void Gui::SetVisiblePointer(bool value)
	{
		mPointerManager->SetVisible(value);
	}

	bool Gui::IsVisiblePointer()
	{
		return mPointerManager->IsVisible();
	}

	void Gui::_injectFrameEntered(float time)
	{
		eventFrameStart(time);
	}

	void Gui::_unlinkWidget(Widget* widget)
	{
		eventFrameStart.Clear(widget);
	}

	void Gui::_linkChildWidget(Widget* widget)
	{
		VectorWidgetPtr::iterator iter = std::find(mWidgetChild.begin(), mWidgetChild.end(), widget);
		ASSERT(iter == mWidgetChild.end(), "widget already exist");
		mWidgetChild.push_back(widget);
	}

	void Gui::_unlinkChildWidget(Widget* widget)
	{
		VectorWidgetPtr::iterator iter = std::remove(mWidgetChild.begin(), mWidgetChild.end(), widget);
		ASSERT(iter != mWidgetChild.end(), "widget not found");
		mWidgetChild.erase(iter);
	}

	void Gui::ResizeWindow(const IntSize& size)
	{
		IntSize oldViewSize = mViewSize;
		mViewSize = size;

		for (VectorWidgetPtr::iterator iter = mWidgetChild.begin(); iter!=mWidgetChild.end(); ++iter)
		{
			((ICroppedRectangle*)(*iter))->_setAlign(oldViewSize, true);
		}
	}

} // namespace GUI

