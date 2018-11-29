#include "Precompiled.h"
#include "DynLibManager.h"

namespace GUI
{

	INSTANCE_IMPLEMENT(DynLibManager)

	void DynLibManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void DynLibManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		StringDynLibMap::iterator it;

		// unload and delete resources
		for (it = mLibsMap.begin(); it != mLibsMap.end(); ++it)
		{
			it->second->Unload();
			delete it->second;
		}

		// Empty the list
		mLibsMap.clear();

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

	DynLib* DynLibManager::Load(const std::string &fileName)
	{
		StringDynLibMap::iterator it = mLibsMap.find(fileName);

		if (it != mLibsMap.end())
		{
			return it->second;
		}

		DynLib *pLib = new DynLib(fileName);
		if (!pLib->Load())
		{
			delete pLib;
			return 0;
		}

		mLibsMap[fileName] = pLib;
		return pLib;
	}

	void DynLibManager::Unload(DynLib *library)
	{
		StringDynLibMap::iterator it = mLibsMap.find(library->GetName());

		if (it != mLibsMap.end())
			mLibsMap.erase(it);

		library->Unload();
		delete library;
	}
}
