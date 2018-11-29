#include "Precompiled.h"
#include "SimpleText.h"
#include "RenderItem.h"
#include "LayerNode.h"
#include "FontManager.h"
#include "CommonStateInfo.h"
#include "RenderManager.h"

namespace GUI
{

	SimpleText::SimpleText() :
		EditText()
	{
		mIsAddCursorWidth = false;
	}

	SimpleText::~SimpleText()
	{
	}

	void SimpleText::SetViewOffset(const IntPoint& point)
	{
	}

	void SimpleText::DoRender()
	{
		bool _update = mRenderItem->GetCurrentUpdate();
		if (_update) mTextOutDate = true;

		if (nullptr == mFont) return;
		if (!mVisible || mEmptyView) return;

		if (mTextOutDate) UpdateRawData();

		const IntSize& size = mTextView.GetViewSize();

		if (mTextAlign.IsRight())
			mViewOffset.left = - (mCoord.width - size.width);
		else if (mTextAlign.IsHCenter())
			mViewOffset.left = - ((mCoord.width - size.width) / 2);
		else
			mViewOffset.left = 0;

		if (mTextAlign.IsBottom())
			mViewOffset.top = - (mCoord.height - size.height);
		else if (mTextAlign.IsVCenter())
			mViewOffset.top = - ((mCoord.height - size.height) / 2);
		else
			mViewOffset.top = 0;

		Base::DoRender();
	}

} // namespace GUI
