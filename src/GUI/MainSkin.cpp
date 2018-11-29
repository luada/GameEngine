#include "Precompiled.h"
#include "MainSkin.h"
#include "RenderItem.h"
#include "LayerManager.h"
#include "CommonStateInfo.h"

namespace GUI
{

	MainSkin::MainSkin() :
		SubSkin()
	{
	}

	MainSkin::~MainSkin()
	{
	}

	void MainSkin::_setAlign(const IntSize& oldsize, bool update)
	{
		mCurrentCoord.Set(0, 0, mCroppedParent->GetWidth(), mCroppedParent->GetHeight());
		mAlign = Align::Stretch;

		Base::_setAlign(oldsize, update);
	}

} // namespace GUI
