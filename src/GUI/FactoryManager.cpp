#include "Precompiled.h"
#include "FactoryManager.h"

namespace GUI
{

	INSTANCE_IMPLEMENT(FactoryManager)

	void FactoryManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);


		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void FactoryManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	void FactoryManager::RegisterFactory(const std::string& category, const std::string& type, Delegate::IDelegate* delegate)
	{
		//FIXME
		mRegisterFactoryItems[category][type] = delegate;
	}

	void FactoryManager::UnregisterFactory(const std::string& category, const std::string& type)
	{
		MapRegisterFactoryItem::iterator curCategory = mRegisterFactoryItems.find(category);
		if (curCategory == mRegisterFactoryItems.end())
		{
			return;
		}
		MapFactoryItem::iterator curType = curCategory->second.find(type);
		if (curType == curCategory->second.end())
		{
			return;
		}

		curCategory->second.erase(curType);
	}

	void FactoryManager::UnregisterFactory(const std::string& category)
	{
		MapRegisterFactoryItem::iterator curCategory = mRegisterFactoryItems.find(category);
		if (curCategory == mRegisterFactoryItems.end())
		{
			return;
		}
		mRegisterFactoryItems.erase(curCategory);
	}

	IObject* FactoryManager::CreateObject(const std::string& category, const std::string& type)
	{
		MapRegisterFactoryItem::iterator curCategory = mRegisterFactoryItems.find(category);
		if (curCategory == mRegisterFactoryItems.end())
		{
			return nullptr;
		}
		MapFactoryItem::iterator curType = curCategory->second.find(type);
		if (curType == curCategory->second.end())
		{
			return nullptr;
		}
		if (curType->second.empty())
		{
			return nullptr;
		}

		IObject* result = nullptr;
		curType->second(result);
		return result;
	}

	void FactoryManager::DestroyObject(IObject* object)
	{
		delete object;

		/*MapRegisterFactoryItem::iterator category = mRegisterFactoryItems.find(_category);
		if (category == mRegisterFactoryItems.end())
		{
			return;
		}
		MapFactoryItem::iterator type = category->second.find(_type);
		if (type == category->second.end())
		{
			return;
		}
		if (type->second.empty())
		{
			return;
		}

		type->second(object, nullptr, _version);*/
	}

	bool FactoryManager::IsFactoryExist(const std::string& category, const std::string& type)
	{
		MapRegisterFactoryItem::iterator curCategory = mRegisterFactoryItems.find(category);
		if (curCategory == mRegisterFactoryItems.end())
		{
			return false;
		}
		MapFactoryItem::iterator curType = curCategory->second.find(type);
		if (curType == curCategory->second.end())
		{
			return false;
		}

		return true;
	}

} // namespace GUI
