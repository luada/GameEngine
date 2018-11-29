#include "Precompiled.h"
#include "VScroll.h"
#include "InputManager.h"
#include "Button.h"
#include "ResourceSkin.h"

namespace GUI
{

	const int SCROLL_MOUSE_WHEEL = 50; 

	VScroll::VScroll() :
		mWidgetStart(nullptr),
		mWidgetEnd(nullptr),
		mWidgetTrack(nullptr),
		mWidgetFirstPart(nullptr),
		mWidgetSecondPart(nullptr),
		mSkinRangeStart(0),
		mSkinRangeEnd(0),
		mScrollRange(0),
		mScrollPosition(0),
		mScrollPage(0),
		mScrollViewPage(0),
		mMinTrackSize(0),
		mMoveToClick(false)
	{
	}

	void VScroll::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	VScroll::~VScroll()
	{
		ShutdownWidgetSkin();
	}

	void VScroll::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void VScroll::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mScrollPage = 1;
		mScrollViewPage = 1;

		for (VectorWidgetPtr::iterator iter = mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Start")
			{
				DEBUG_ASSERT( ! mWidgetStart, "widget already assigned");
				mWidgetStart = (*iter)->CastType<Button>();
				mWidgetStart->eventMouseButtonPressed = NewDelegate(this, &VScroll::NotifyMousePressed);
				mWidgetStart->eventMouseWheel = NewDelegate(this, &VScroll::NotifyMouseWheel);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "End")
			{
				DEBUG_ASSERT( ! mWidgetEnd, "widget already assigned");
				mWidgetEnd = (*iter)->CastType<Button>();
				mWidgetEnd->eventMouseButtonPressed = NewDelegate(this, &VScroll::NotifyMousePressed);
				mWidgetEnd->eventMouseWheel = NewDelegate(this, &VScroll::NotifyMouseWheel);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Track")
			{
				DEBUG_ASSERT( ! mWidgetTrack, "widget already assigned");
				mWidgetTrack = (*iter)->CastType<Button>();
				mWidgetTrack->eventMouseDrag = NewDelegate(this, &VScroll::NotifyMouseDrag);
				mWidgetTrack->eventMouseButtonPressed = NewDelegate(this, &VScroll::NotifyMousePressed);
				mWidgetTrack->eventMouseButtonReleased = NewDelegate(this, &VScroll::NotifyMouseReleased);
				mWidgetTrack->eventMouseWheel = NewDelegate(this, &VScroll::NotifyMouseWheel);
				mWidgetTrack->SetVisible(false);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "FirstPart")
			{
				DEBUG_ASSERT( ! mWidgetFirstPart, "widget already assigned");
				mWidgetFirstPart = (*iter)->CastType<Button>();
				mWidgetFirstPart->eventMouseButtonPressed = NewDelegate(this, &VScroll::NotifyMousePressed);
				mWidgetFirstPart->eventMouseWheel = NewDelegate(this, &VScroll::NotifyMouseWheel);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "SecondPart")
			{
				DEBUG_ASSERT( ! mWidgetSecondPart, "widget already assigned");
				mWidgetSecondPart = (*iter)->CastType<Button>();
				mWidgetSecondPart->eventMouseButtonPressed = NewDelegate(this, &VScroll::NotifyMousePressed);
				mWidgetSecondPart->eventMouseWheel = NewDelegate(this, &VScroll::NotifyMouseWheel);
			}
		}

		// slider don't have buttons
		//ASSERT(nullptr != mWidgetTrack, "Child Button Track not found in Skin (Scroll must have Track)");

		const MapString& properties = info->GetProperties();
		MapString::const_iterator iter = properties.find("TrackRangeMargins");
		if (iter != properties.end())
		{
			IntSize range = IntSize::Parse(iter->second);
			mSkinRangeStart = range.width;
			mSkinRangeEnd = range.height;
		}
		else
		{
			mSkinRangeStart = 0;
			mSkinRangeEnd = 0;
		}
		iter = properties.find("MinTrackSize");
		if (iter != properties.end()) mMinTrackSize = utility::ParseInt(iter->second);
		else mMinTrackSize = 0;

		iter = properties.find("MoveToClick");
		if (iter != properties.end()) mMoveToClick = utility::ParseBool(iter->second);
	}

	void VScroll::ShutdownWidgetSkin()
	{
		mWidgetStart = nullptr;
		mWidgetEnd = nullptr;
		mWidgetTrack = nullptr;
		mWidgetFirstPart = nullptr;
		mWidgetSecondPart = nullptr;
	}

	void VScroll::UpdateTrack()
	{
		if (mWidgetTrack == nullptr)
			return;

		_forcePeek(mWidgetTrack);
		int pos = GetLineSize();

		if ((mScrollRange < 2) || (pos <= mWidgetTrack->GetHeight()))
		{
			mWidgetTrack->SetVisible(false);
			if ( nullptr != mWidgetFirstPart ) mWidgetFirstPart->SetSize(mWidgetFirstPart->GetWidth(), pos/2);
			if ( nullptr != mWidgetSecondPart ) mWidgetSecondPart->SetCoord(mWidgetSecondPart->GetLeft(), pos/2 + (int)mSkinRangeStart, mWidgetSecondPart->GetWidth(), pos - pos/2);
			return;
		}
		if (!mWidgetTrack->IsVisible())
		{
			mWidgetTrack->SetVisible(true);
		}

		pos = (int)(((size_t)(pos-GetTrackSize()) * mScrollPosition) / (mScrollRange-1) + mSkinRangeStart);

		mWidgetTrack->SetPosition(mWidgetTrack->GetLeft(), pos);
		if ( nullptr != mWidgetFirstPart )
		{
			int height = pos + mWidgetTrack->GetHeight()/2 - mWidgetFirstPart->GetTop();
			mWidgetFirstPart->SetSize(mWidgetFirstPart->GetWidth(), height);
		}
		if ( nullptr != mWidgetSecondPart )
		{
			int top = pos + mWidgetTrack->GetHeight()/2;
			int height = mWidgetSecondPart->GetHeight() + mWidgetSecondPart->GetTop() - top;
			mWidgetSecondPart->SetCoord(mWidgetSecondPart->GetLeft(), top, mWidgetSecondPart->GetWidth(), height);
		}
	}

	void VScroll::TrackMove(int left, int top)
	{
		if (mWidgetTrack == nullptr)
			return;

		const IntPoint& point = InputManager::GetInstance().GetLastLeftPressed();

		int start = mPreActionOffset.top + (top - point.top);
		if (start < (int)mSkinRangeStart) start = (int)mSkinRangeStart;
		else if (start > (mCoord.height - (int)mSkinRangeEnd - mWidgetTrack->GetHeight())) start = (mCoord.height - (int)mSkinRangeEnd - mWidgetTrack->GetHeight());
		if (mWidgetTrack->GetTop() != start) mWidgetTrack->SetPosition(mWidgetTrack->GetLeft(), start);

		int pos = start - (int)mSkinRangeStart + (GetLineSize() - GetTrackSize()) / (((int)mScrollRange-1) * 2);
		pos = pos * (int)(mScrollRange-1) / (GetLineSize() - GetTrackSize());

		if (pos < 0) pos = 0;
		else if (pos >= (int)mScrollRange) pos = (int)mScrollRange - 1;
		if (pos == (int)mScrollPosition) return;

		mScrollPosition = pos;
		eventScrollChangePosition(this, (int)mScrollPosition);
	}

	void VScroll::NotifyMousePressed(Widget* sender, int left, int top, MouseButton id)
	{
		eventMouseButtonPressed(this, left, top, id);

		if (MouseButton::Left != id) return;

		if (mMoveToClick && mWidgetTrack != sender)
		{
			mPreActionOffset = InputManager::GetInstance().GetLastLeftPressed();
			const IntPoint& point = InputManager::GetInstance().GetMousePositionByLayer() - GetAbsolutePosition();

			TrackMove(point.left, point.top);

		}
		else if (sender == mWidgetStart)
		{
			if (mScrollPosition == 0) return;

			if (mScrollPosition > mScrollPage) mScrollPosition -= mScrollPage;
			else mScrollPosition = 0;

			eventScrollChangePosition(this, (int)mScrollPosition);
			UpdateTrack();

		}
		else if (sender == mWidgetEnd)
		{
			if ( (mScrollRange < 2) || (mScrollPosition >= (mScrollRange-1)) ) return;

			if ((mScrollPosition + mScrollPage) < (mScrollRange-1)) mScrollPosition += mScrollPage;
			else mScrollPosition = mScrollRange - 1;

			eventScrollChangePosition(this, (int)mScrollPosition);
			UpdateTrack();

		}
		else if (sender == mWidgetFirstPart)
		{
			if (mScrollPosition == 0) return;

			if (mScrollPosition > mScrollViewPage) mScrollPosition -= mScrollViewPage;
			else mScrollPosition = 0;

			eventScrollChangePosition(this, (int)mScrollPosition);
			UpdateTrack();

		}
		else if (sender == mWidgetSecondPart)
		{
			if ( (mScrollRange < 2) || (mScrollPosition >= (mScrollRange-1)) ) return;

			if ((mScrollPosition + mScrollViewPage) < (mScrollRange-1)) mScrollPosition += mScrollViewPage;
			else mScrollPosition = mScrollRange - 1;

			eventScrollChangePosition(this, (int)mScrollPosition);
			UpdateTrack();

		}
		else if (sender == mWidgetTrack)
		{
			mPreActionOffset.left = sender->GetLeft();
			mPreActionOffset.top = sender->GetTop();
		}
	}

	void VScroll::NotifyMouseReleased(Widget* sender, int left, int top, MouseButton id)
	{
		UpdateTrack();
	}

	void VScroll::NotifyMouseDrag(Widget* sender, int left, int top)
	{
		TrackMove(left, top);
	}

	void VScroll::SetScrollRange(size_t range)
	{
		if (range == mScrollRange) return;
		mScrollRange = range;
		mScrollPosition = (mScrollPosition < mScrollRange) ? mScrollPosition : 0;
		UpdateTrack();
	}

	void VScroll::SetScrollPosition(size_t position)
	{
		if (position == mScrollPosition) return;
		if (position >= mScrollRange) position = 0;
		mScrollPosition = position;
		UpdateTrack();
	}

	void VScroll::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void VScroll::SetSize(const IntSize& size)
	{
		Base::SetSize(size);
		UpdateTrack();
	}

	void VScroll::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);
		UpdateTrack();
	}

	void VScroll::SetTrackSize(int size)
	{
		if (mWidgetTrack != nullptr)
			mWidgetTrack->SetSize(mWidgetTrack->GetWidth(), ((int)size < (int)mMinTrackSize)? (int)mMinTrackSize : (int)size);
		UpdateTrack();
	}

	int VScroll::GetTrackSize()
	{
		return mWidgetTrack == nullptr ? 1 : mWidgetTrack->GetHeight();
	}

	int VScroll::GetLineSize()
	{
		return mCoord.height - (int)(mSkinRangeStart + mSkinRangeEnd);
	}

	void VScroll::OnMouseWheel(int rel)
	{
		NotifyMouseWheel(nullptr, rel);

		Base::OnMouseWheel(rel);
	}

	void VScroll::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mScrollRange < 2) return;

		int offset = mScrollPosition;
		if (rel < 0) offset += SCROLL_MOUSE_WHEEL;
		else offset -= SCROLL_MOUSE_WHEEL;

		if (offset < 0) offset = 0;
		else if (offset > (int)(mScrollRange - 1)) offset = mScrollRange - 1;

		if ((size_t)offset != mScrollPosition)
		{
			mScrollPosition = offset;
			eventScrollChangePosition(this, (int)mScrollPosition);
			UpdateTrack();
		}
	}

	void VScroll::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Scroll_Range") SetScrollRange(utility::ParseValue<size_t>(value));
		else if (key == "Scroll_Position") SetScrollPosition(utility::ParseValue<size_t>(value));
		else if (key == "Scroll_Page") SetScrollPage(utility::ParseValue<size_t>(value));
		else if (key == "Scroll_ViewPage") SetScrollViewPage(utility::ParseValue<size_t>(value));
		else if (key == "Scroll_MoveToClick") SetMoveToClick(utility::ParseValue<bool>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI


