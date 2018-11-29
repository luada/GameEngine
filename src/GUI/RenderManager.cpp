#include "Precompiled.h"
#include "RenderManager.h"

namespace GUI
{

	const std::string INSTANCE_TYPE_NAME("RenderManager");

	RenderManager* RenderManager::msInstance = 0;

	RenderManager::RenderManager() :
		mIsInitialise(false)
	{
		ASSERT(0 == msInstance, "instance " << INSTANCE_TYPE_NAME << " is exsist");
		msInstance = this;
	}

	RenderManager::~RenderManager()
	{
		msInstance = 0;
	}

	RenderManager* RenderManager::GetInstancePtr()
	{
		return msInstance;
	}

	RenderManager& RenderManager::GetInstance()
	{
		ASSERT(0 != msInstance, "instance " << INSTANCE_TYPE_NAME << " was not created");
		return (*msInstance);
	}

} // namespace GUI
