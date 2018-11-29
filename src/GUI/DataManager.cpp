#include "Precompiled.h"
#include "DataManager.h"

namespace GUI
{

	const std::string INSTANCE_TYPE_NAME("DataManager");

	DataManager* DataManager::msInstance = 0;

	DataManager::DataManager() :
		mIsInitialise(false)
	{
		ASSERT(0 == msInstance, "instance " << INSTANCE_TYPE_NAME << " is exsist");
		msInstance = this;
	}

	DataManager::~DataManager()
	{
		msInstance = 0;
	}

	DataManager* DataManager::GetInstancePtr()
	{
		return msInstance;
	}

	DataManager& DataManager::GetInstance()
	{
		ASSERT(0 != msInstance, "instance " << INSTANCE_TYPE_NAME << " was not created");
		return (*msInstance);
	}

} // namespace GUI
