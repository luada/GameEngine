#include "Precompiled.h"
#include "SubWidgetManager.h"
#include "FactoryManager.h"
#include "CommonStateInfo.h"

#include "SubSkin.h"
#include "MainSkin.h"
#include "RotatingSkin.h"
#include "SimpleText.h"
#include "EditText.h"
#include "RawRect.h"
#include "TileRect.h"

namespace GUI
{

	INSTANCE_IMPLEMENT(SubWidgetManager)

	void SubWidgetManager::Initialise()
	{
		ASSERT(!mIsInitialise, INSTANCE_TYPE_NAME << " initialised twice");
		LOG(Info, "* Initialise: " << INSTANCE_TYPE_NAME);

		FactoryManager& factory = FactoryManager::GetInstance();

		factory.RegisterFactory<SubSkinStateInfo>("BasisSkin/State", "SubSkin");
		factory.RegisterFactory<SubSkinStateInfo>("BasisSkin/State", "MainSkin");
		factory.RegisterFactory<SubSkinStateInfo>("BasisSkin/State", "RotatingSkin");
		factory.RegisterFactory<SubSkinStateInfo>("BasisSkin/State", "RawRect");
		factory.RegisterFactory<TileRectStateInfo>("BasisSkin/State", "TileRect");
		factory.RegisterFactory<EditTextStateInfo>("BasisSkin/State", "EditText");
		factory.RegisterFactory<EditTextStateInfo>("BasisSkin/State", "SimpleText");

		factory.RegisterFactory<SubSkin>("BasisSkin");
		factory.RegisterFactory<MainSkin>("BasisSkin");
		factory.RegisterFactory<RotatingSkin>("BasisSkin");
		factory.RegisterFactory<RawRect>("BasisSkin");
		factory.RegisterFactory<TileRect>("BasisSkin");
		factory.RegisterFactory<EditText>("BasisSkin");
		factory.RegisterFactory<SimpleText>("BasisSkin");

		LOG(Info, INSTANCE_TYPE_NAME << " successfully initialized");
		mIsInitialise = true;
	}

	void SubWidgetManager::Shutdown()
	{
		if (!mIsInitialise) return;
		LOG(Info, "* Shutdown: " << INSTANCE_TYPE_NAME);

		FactoryManager& factory = FactoryManager::GetInstance();

		factory.UnregisterFactory("BasisSkin/State", "SubSkin");
		factory.UnregisterFactory("BasisSkin/State", "MainSkin");
		factory.UnregisterFactory("BasisSkin/State", "RotatingSkin");
		factory.UnregisterFactory("BasisSkin/State", "RawRect");
		factory.UnregisterFactory("BasisSkin/State", "TileRect");
		factory.UnregisterFactory("BasisSkin/State", "EditText");
		factory.UnregisterFactory("BasisSkin/State", "SimpleText");

		factory.UnregisterFactory<SubSkin>("BasisSkin");
		factory.UnregisterFactory<MainSkin>("BasisSkin");
		factory.UnregisterFactory<RotatingSkin>("BasisSkin");
		factory.UnregisterFactory<RawRect>("BasisSkin");
		factory.UnregisterFactory<TileRect>("BasisSkin");
		factory.UnregisterFactory<EditText>("BasisSkin");
		factory.UnregisterFactory<SimpleText>("BasisSkin");

		LOG(Info, INSTANCE_TYPE_NAME << " successfully shutdown");
		mIsInitialise = false;
	}

} // namespace GUI
