#include "Precompiled.h"
#include "HScroll.h"
#include "InputManager.h"
#include "Button.h"
#include "ResourceSkin.h"

namespace GUI
{

	HScroll::HScroll()
	{
	}

	void HScroll::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	HScroll::~HScroll()
	{
		ShutdownWidgetSkin();
	}

	void HScroll::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void HScroll::InitialiseWidgetSkin(ResourceSkin* info)
	{
	}

	void HScroll::ShutdownWidgetSkin()
	{
	}

	void HScroll::UpdateTrack()
	{
		if (mWidgetTrack == nullptr)
			return;

		_forcePeek(mWidgetTrack);
		int pos = GetLineSize();

		if ((mScrollRange < 2) || (pos <= mWidgetTrack->GetWidth()))
		{
			mWidgetTrack->SetVisible(false);
			if ( nullptr != mWidgetFirstPart ) mWidgetFirstPart->SetSize(pos/2, mWidgetFirstPart->GetHeight());
			if ( nullptr != mWidgetSecondPart ) mWidgetSecondPart->SetCoord(pos/2 + mSkinRangeStart, mWidgetSecondPart->GetTop(), pos - pos/2, mWidgetSecondPart->GetHeight());
			return;
		}
		if (!mWidgetTrack->IsVisible())
		{
			mWidgetTrack->SetVisible(true);
		}

		pos = (int)(((size_t)(pos-GetTrackSize()) * mScrollPosition) / (mScrollRange-1) + mSkinRangeStart);

		mWidgetTrack->SetPosition(pos, mWidgetTrack->GetTop());
		if ( nullptr != mWidgetFirstPart )
		{
			int height = pos + mWidgetTrack->GetWidth()/2 - mWidgetFirstPart->GetLeft();
			mWidgetFirstPart->SetSize(height, mWidgetFirstPart->GetHeight());
		}
		if ( nullptr != mWidgetSecondPart )
		{
			int top = pos + mWidgetTrack->GetWidth()/2;
			int height = mWidgetSecondPart->GetWidth() + mWidgetSecondPart->GetLeft() - top;
			mWidgetSecondPart->SetCoord(top, mWidgetSecondPart->GetTop(), height, mWidgetSecondPart->GetHeight());
		}
	}

	void HScroll::TrackMove(int left, int top)
	{
		if (mWidgetTrack == nullptr)
			return;

		const IntPoint& point = InputManager::GetInstance().GetLastLeftPressed();

		int start = mPreActionOffset.left + (left - point.left);
		if (start < (int)mSkinRangeStart) start = (int)mSkinRangeStart;
		else if (start > (mCoord.width - (int)mSkinRangeEnd - mWidgetTrack->GetWidth())) start = (mCoord.width - (int)mSkinRangeEnd - mWidgetTrack->GetWidth());
		if (mWidgetTrack->GetLeft() != start) mWidgetTrack->SetPosition(IntPoint(start, mWidgetTrack->GetTop()));

		int pos = start - (int)mSkinRangeStart + (GetLineSize() - GetTrackSize()) / (((int)mScrollRange-1) * 2);
		pos = pos * (int)(mScrollRange-1) / (GetLineSize() - GetTrackSize());

		if (pos < 0) pos = 0;
		else if (pos >= (int)mScrollRange) pos = (int)mScrollRange - 1;
		if (pos == (int)mScrollPosition) return;

		mScrollPosition = pos;
		eventScrollChangePosition(this, (int)mScrollPosition);
	}

	void HScroll::SetTrackSize(int size)
	{
		if (mWidgetTrack != nullptr)
			mWidgetTrack->SetSize(((int)size < (int)mMinTrackSize)? (int)mMinTrackSize : (int)size, mWidgetTrack->GetHeight());
		UpdateTrack();
	}

	int HScroll::GetTrackSize()
	{
		return mWidgetTrack == nullptr ? 1 : mWidgetTrack->GetWidth();
	}

	int HScroll::GetLineSize()
	{
		return mCoord.width - (int)(mSkinRangeStart + mSkinRangeEnd);
	}

} // namespace GUI

