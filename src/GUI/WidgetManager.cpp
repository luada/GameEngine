#include "Precompiled.h"
#include "Gui.h"
#include "WidgetManager.h"
#include "LayerManager.h"
#include "Widget.h"
#include "IWidgetCreator.h"
#include "IWidgetFactory.h"
#include "FactoryManager.h"

#include "Button.h"
#include "Canvas.h"
#include "ComboBox.h"
#include "DDContainer.h"
#include "Edit.h"
#include "HScroll.h"
#include "ItemBox.h"
#include "List.h"
#include "ListBox.h"
#include "ListCtrl.h"
#include "MenuBar.h"
#include "MenuCtrl.h"
#include "MenuItem.h"
#include "Message.h"
#include "MultiList.h"
#include "PopupMenu.h"
#include "Progress.h"
#include "ScrollView.h"
#include "StaticImage.h"
#include "StaticText.h"
#include "Tab.h"
#include "TabItem.h"
#include "VScroll.h"
#include "Widget.h"
#include "Window.h"

namespace GUI
{

	INSTANCE_IMPLEMENT(WidgetManager)

	void WidgetManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		//registerUnlinker(this);

		FactoryManager& factory = FactoryManager::GetInstance();

		factory.RegisterFactory<Button>("Widget");
		factory.RegisterFactory<Canvas>("Widget");
		factory.RegisterFactory<ComboBox>("Widget");
		factory.RegisterFactory<DDContainer>("Widget");
		factory.RegisterFactory<Edit>("Widget");
		factory.RegisterFactory<HScroll>("Widget");
		factory.RegisterFactory<ItemBox>("Widget");
		factory.RegisterFactory<List>("Widget");
		factory.RegisterFactory<ListBox>("Widget");
		factory.RegisterFactory<ListCtrl>("Widget");
		factory.RegisterFactory<MenuBar>("Widget");
		factory.RegisterFactory<MenuCtrl>("Widget");
		factory.RegisterFactory<MenuItem>("Widget");
		factory.RegisterFactory<Message>("Widget");
		factory.RegisterFactory<MultiList>("Widget");
		factory.RegisterFactory<PopupMenu>("Widget");
		factory.RegisterFactory<Progress>("Widget");
		factory.RegisterFactory<ScrollView>("Widget");
		factory.RegisterFactory<StaticImage>("Widget");
		factory.RegisterFactory<StaticText>("Widget");
		factory.RegisterFactory<Tab>("Widget");
		factory.RegisterFactory<TabItem>("Widget");
		factory.RegisterFactory<VScroll>("Widget");
		factory.RegisterFactory<Widget>("Widget");
		factory.RegisterFactory<Window>("Widget");

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void WidgetManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		//unregisterUnlinker(this);

		mFactoryList.clear();
		mDelegates.clear();
		mVectorIUnlinkWidget.clear();

		FactoryManager::GetInstance().UnregisterFactory("Widget");

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	Widget* WidgetManager::CreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, Widget* parent, ICroppedRectangle * cropeedParent, IWidgetCreator * creator, const std::string& name)
	{
		IObject* object = FactoryManager::GetInstance().CreateObject("Widget", type);
		if (object != nullptr)
		{
			Widget* widget = object->CastType<Widget>();
			ResourceSkin* curSkin = SkinManager::GetInstance().GetByName(skin);
			widget->_initialise(style, coord, align, curSkin, parent, cropeedParent, creator, name);

			return widget;
		}

		for (SetWidgetFactory::iterator factory = mFactoryList.begin(); factory != mFactoryList.end(); ++factory)
		{
			if ((*factory)->GetTypeName() == type)
			{
				Widget* widget = (*factory)->CreateWidget(style, skin, coord, align, parent, cropeedParent, creator, name);
				return widget;
			}
		}

		EXCEPT("factory '" << type << "' not found");
		return nullptr;
	}

	void WidgetManager::DestroyWidget(Widget* widget)
	{
		ASSERT(widget != nullptr, "widget is deleted");

		IWidgetCreator * creator = widget->_getIWidgetCreator();
		creator->_destroyChildWidget(widget);
	}

	void WidgetManager::DestroyWidgets(const VectorWidgetPtr& widgets)
	{
		for (VectorWidgetPtr::const_iterator iter = widgets.begin(); iter != widgets.end(); ++iter)
		{
			DestroyWidget(*iter);
		}
	}

	void WidgetManager::DestroyWidgets(EnumeratorWidgetPtr widgets)
	{
		VectorWidgetPtr curWidgets;
		while (widgets.Next())
		{
			curWidgets.push_back(widgets.Current());
		}
		DestroyWidgets(curWidgets);
	}

	void WidgetManager::RegisterUnlinker(IUnlinkWidget * unlink)
	{
		UnregisterUnlinker(unlink);
		mVectorIUnlinkWidget.push_back(unlink);
	}

	void WidgetManager::UnregisterUnlinker(IUnlinkWidget * unlink)
	{
		for (size_t pos=0; pos<mVectorIUnlinkWidget.size(); pos++)
		{
			if (mVectorIUnlinkWidget[pos] == unlink)
			{
				mVectorIUnlinkWidget[pos] = mVectorIUnlinkWidget[mVectorIUnlinkWidget.size()-1];
				mVectorIUnlinkWidget.pop_back();
				break;
			}
		}
	}

	void WidgetManager::UnlinkFromUnlinkers(Widget* widget)
	{
		for (VectorIUnlinkWidget::iterator iter = mVectorIUnlinkWidget.begin(); iter!=mVectorIUnlinkWidget.end(); ++iter)
		{
			(*iter)->_unlinkWidget(widget);
		}
		RemoveWidgetFromUnlink(widget);
	}

	void WidgetManager::AddWidgetToUnlink(Widget* widget)
	{
		if (widget) mUnlinkWidgets.push_back(widget);
	}

	void WidgetManager::RemoveWidgetFromUnlink(Widget*& widget)
	{
		VectorWidgetPtr::iterator iter = std::find(mUnlinkWidgets.begin(), mUnlinkWidgets.end(), widget);
		if (iter != mUnlinkWidgets.end())
		{
			(*iter) = mUnlinkWidgets.back();
			mUnlinkWidgets.pop_back();
		}
		else
		{
			widget = nullptr;
		}
	}

	bool WidgetManager::IsFactoryExist(const std::string& type)
	{
		if (FactoryManager::GetInstance().IsFactoryExist("Widget", type))
		{
			return true;
		}

		for (SetWidgetFactory::iterator factory = mFactoryList.begin(); factory != mFactoryList.end(); ++factory)
		{
			if ((*factory)->GetTypeName() == type)
			{
				return true;
			}
		}

		return false;
	}

} // namespace GUI

