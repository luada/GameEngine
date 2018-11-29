#include "Precompiled.h"
#include "Gui.h"
#include "ControllerManager.h"
#include "WidgetManager.h"
#include "FactoryManager.h"

#include "ControllerEdgeHide.h"
#include "ControllerFadeAlpha.h"
#include "ControllerPosition.h"

namespace GUI
{

	INSTANCE_IMPLEMENT(ControllerManager)

	void ControllerManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		WidgetManager::GetInstance().RegisterUnlinker(this);

		const std::string factory_type = "Controller";

		FactoryManager::GetInstance().RegisterFactory<ControllerEdgeHide>(factory_type);
		FactoryManager::GetInstance().RegisterFactory<ControllerFadeAlpha>(factory_type);
		FactoryManager::GetInstance().RegisterFactory<ControllerPosition>(factory_type);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void ControllerManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		const std::string factory_type = "Controller";

		FactoryManager::GetInstance().UnregisterFactory<ControllerEdgeHide>(factory_type);
		FactoryManager::GetInstance().UnregisterFactory<ControllerFadeAlpha>(factory_type);
		FactoryManager::GetInstance().UnregisterFactory<ControllerPosition>(factory_type);

		WidgetManager::GetInstance().UnregisterUnlinker(this);
		Clear();

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	void ControllerManager::Clear()
	{
		for (ListControllerItem::iterator iter=mListItem.begin(); iter!=mListItem.end(); ++iter)
		{
			delete (*iter).second;
		}
		mListItem.clear();
	}

	ControllerItem* ControllerManager::CreateItem(const std::string& type)
	{
		IObject* object = FactoryManager::GetInstance().CreateObject("Controller", type);
		return object == nullptr ? nullptr : object->CastType<ControllerItem>();
	}

	void ControllerManager::AddItem(Widget* widget, ControllerItem * item)
	{
		if (0 == mListItem.size()) Gui::GetInstance().eventFrameStart += NewDelegate(this, &ControllerManager::FrameEntered);

		item->PrepareItem(widget);

		for (ListControllerItem::iterator iter=mListItem.begin(); iter!=mListItem.end(); ++iter)
		{
			if ((*iter).first == widget)
			{
				if ((*iter).second->GetTypeName() == item->GetTypeName())
				{
					delete (*iter).second;
					(*iter).second = item;
					return;
				}
			}
		}

		mListItem.push_back(PairControllerItem(widget, item));
	}

	void ControllerManager::RemoveItem(Widget* widget)
	{
		for (ListControllerItem::iterator iter=mListItem.begin(); iter!=mListItem.end(); ++iter)
		{
			if ((*iter).first == widget) (*iter).first = nullptr;
		}
	}

	void ControllerManager::_unlinkWidget(Widget* widget)
	{
		RemoveItem(widget);
	}

	void ControllerManager::FrameEntered(float time)
	{
		for (ListControllerItem::iterator iter=mListItem.begin(); iter!=mListItem.end(); /*added in body*/)
		{
			if (nullptr == (*iter).first)
			{
				delete (*iter).second;
				iter = mListItem.erase(iter);
				continue;
			}

			if ((*iter).second->AddTime((*iter).first, time))
			{
				++iter;
				continue;
			}

			(*iter).first = nullptr;
		}

		if (0 == mListItem.size()) Gui::GetInstance().eventFrameStart -= NewDelegate(this, &ControllerManager::FrameEntered);
	}

} // namespace GUI

