#include "precompiled.h"
#include "GUIEditor/PointerManager.h"
#include <GUI.h>

namespace input
{

	PointerManager::PointerManager()
	{
	}

	PointerManager::~PointerManager()
	{
	}

	void PointerManager::CreatePointerManager(size_t handle)
	{
	}

	void PointerManager::DestroyPointerManager()
	{
	}

	void PointerManager::SetPointerVisible(bool value)
	{
		GUI::PointerManager::GetInstance().SetVisible(value);
	}

	void PointerManager::SetPointerName(const std::string& name)
	{
		GUI::PointerManager::GetInstance().SetPointer(name);
	}

} // namespace input
