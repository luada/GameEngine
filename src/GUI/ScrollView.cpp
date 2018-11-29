#include "Precompiled.h"
#include "ScrollView.h"
#include "SkinManager.h"
#include "ISubWidgetText.h"
#include "VScroll.h"
#include "HScroll.h"

namespace GUI
{

	const int SCROLL_VIEW_MOUSE_WHEEL = 50; 
	const int SCROLL_VIEW_SCROLL_PAGE = 16; 

	ScrollView::ScrollView() :
		mIsFocus(false),
		mIsPressed(false),
		mScrollClient(nullptr),
		mContentAlign(Align::Center)
	{
		mChangeContentByResize = false;
		mContentAlign = Align::Center;
	}

	void ScrollView::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	ScrollView::~ScrollView()
	{
		ShutdownWidgetSkin();
	}

	void ScrollView::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void ScrollView::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mNeedKeyFocus = true;

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mScrollClient, "widget already assigned");
				mScrollClient = (*iter);
				mScrollClient->eventMouseSetFocus = NewDelegate(this, &ScrollView::NotifyMouseSetFocus);
				mScrollClient->eventMouseLostFocus = NewDelegate(this, &ScrollView::NotifyMouseLostFocus);
				mScrollClient->eventMouseWheel = NewDelegate(this, &ScrollView::NotifyMouseWheel);
				mClient = mScrollClient;

				mWidgetClient = mScrollClient->CreateWidget<Widget>("Default", IntCoord(), Align::Default);
				mWidgetClient->eventMouseWheel = NewDelegate(this, &ScrollView::NotifyMouseWheel);
				mWidgetClient->eventMouseSetFocus = NewDelegate(this, &ScrollView::NotifyMouseSetFocus);
				mWidgetClient->eventMouseLostFocus = NewDelegate(this, &ScrollView::NotifyMouseLostFocus);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "VScroll")
			{
				DEBUG_ASSERT( ! mVScroll, "widget already assigned");
				mVScroll = (*iter)->CastType<VScroll>();
				mVScroll->eventScrollChangePosition = NewDelegate(this, &ScrollView::NotifyScrollChangePosition);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "HScroll")
			{
				DEBUG_ASSERT( ! mHScroll, "widget already assigned");
				mHScroll = (*iter)->CastType<HScroll>();
				mHScroll->eventScrollChangePosition = NewDelegate(this, &ScrollView::NotifyScrollChangePosition);
			}
		}

		//ASSERT(nullptr != mScrollClient, "Child Widget Client not found in Skin (ScrollView must have Client)");

		UpdateView();
	}

	void ScrollView::ShutdownWidgetSkin()
	{
		mWidgetClient = nullptr;
		mVScroll = nullptr;
		mHScroll = nullptr;
		mScrollClient = nullptr;
	}

	void ScrollView::NotifyMouseSetFocus(Widget* sender, Widget* old)
	{
		if ((old == mScrollClient) || (mIsFocus))
			return;

		mIsFocus = true;
		UpdateScrollViewState();
	}

	void ScrollView::NotifyMouseLostFocus(Widget* sender, Widget* _new)
	{
		if ((_new == mScrollClient) || (!mIsFocus))
			return;

		mIsFocus = false;
		UpdateScrollViewState();
	}

	void ScrollView::OnKeySetFocus(Widget* old)
	{
		if (!mIsPressed)
		{
			mIsPressed = true;
			UpdateScrollViewState();
		}

		Base::OnKeySetFocus(old);
	}

	void ScrollView::OnKeyLostFocus(Widget* _new)
	{
		if (mIsPressed)
		{
			mIsPressed = false;
			UpdateScrollViewState();
		}

		Base::OnKeyLostFocus(_new);
	}

	void ScrollView::UpdateScrollViewState()
	{
		if (!mEnabled) SetState("disabled");
		else if (mIsPressed)
		{
			if (mIsFocus) SetState("pushed");
			else SetState("normal_checked");
		}
		else if (mIsFocus) SetState("highlighted");
		else SetState("normal");
	}

	void ScrollView::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void ScrollView::SetSize(const IntSize& size)
	{
		Base::SetSize(size);

		UpdateView();
	}

	void ScrollView::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);

		UpdateView();
	}

	void ScrollView::NotifyScrollChangePosition(VScroll* sender, size_t position)
	{
		if (mWidgetClient == nullptr)
			return;

		if (sender == mVScroll)
		{
			IntPoint point = mWidgetClient->GetPosition();
			point.top = -(int)position;
			mWidgetClient->SetPosition(point);
		}
		else if (sender == mHScroll)
		{
			IntPoint point = mWidgetClient->GetPosition();
			point.left = -(int)position;
			mWidgetClient->SetPosition(point);
		}
	}

	void ScrollView::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mWidgetClient == nullptr)
			return;

		if (mVRange != 0)
		{
			IntPoint point = mWidgetClient->GetPosition();
			int offset = -point.top;
			if (rel < 0) offset += SCROLL_VIEW_MOUSE_WHEEL;
			else  offset -= SCROLL_VIEW_MOUSE_WHEEL;

			if (offset < 0) offset = 0;
			else if (offset > (int)mVRange) offset = mVRange;

			if (offset != point.top)
			{
				point.top = -offset;
				if (mVScroll != nullptr)
				{
					mVScroll->SetScrollPosition(offset);
				}
				mWidgetClient->SetPosition(point);
			}
		}
		else if (mHRange != 0)
		{
			IntPoint point = mWidgetClient->GetPosition();
			int offset = -point.left;
			if (rel < 0) offset += SCROLL_VIEW_MOUSE_WHEEL;
			else  offset -= SCROLL_VIEW_MOUSE_WHEEL;

			if (offset < 0) offset = 0;
			else if (offset > (int)mHRange) offset = mHRange;

			if (offset != point.left)
			{
				point.left = -offset;
				if (mHScroll != nullptr)
				{
					mHScroll->SetScrollPosition(offset);
				}
				mWidgetClient->SetPosition(point);
			}
		}
	}

	Widget* ScrollView::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		if (mWidgetClient == nullptr)
			return Base::BaseCreateWidget(style, type, skin, coord, align, layer, name);
		return mWidgetClient->CreateWidgetT(style, type, skin, coord, align, layer, name);
	}

	IntSize ScrollView::GetContentSize()
	{
		return mWidgetClient == nullptr ? IntSize() : mWidgetClient->GetSize();
	}

	IntPoint ScrollView::GetContentPosition()
	{
		return mWidgetClient == nullptr ? IntPoint() : (IntPoint() - mWidgetClient->GetPosition());
	}

	void ScrollView::SetContentPosition(const IntPoint& point)
	{
		if (mWidgetClient != nullptr)
			mWidgetClient->SetPosition(IntPoint() - point);
	}

	IntSize ScrollView::GetViewSize() const
	{
		return mScrollClient == nullptr ? IntSize() : mScrollClient->GetSize();
	}

	size_t ScrollView::GetVScrollPage()
	{
		return SCROLL_VIEW_SCROLL_PAGE;
	}

	size_t ScrollView::GetHScrollPage()
	{
		return SCROLL_VIEW_SCROLL_PAGE;
	}

	void ScrollView::UpdateView()
	{
		UpdateScrollSize();
		UpdateScrollPosition();
	}

	void ScrollView::SetVisibleVScroll(bool value)
	{
		mVisibleVScroll = value;
		UpdateView();
	}

	void ScrollView::SetVisibleHScroll(bool value)
	{
		mVisibleHScroll = value;
		UpdateView();
	}

	void ScrollView::SetCanvasAlign(Align value)
	{
		mContentAlign = value;
		UpdateView();
	}

	void ScrollView::SetCanvasSize(const IntSize& value)
	{
		if (mWidgetClient != nullptr)
			mWidgetClient->SetSize(value); UpdateView();
	}

	void ScrollView::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "ScrollView_VisibleVScroll") SetVisibleVScroll(utility::ParseValue<bool>(value));
		else if (key == "ScrollView_VisibleHScroll") SetVisibleHScroll(utility::ParseValue<bool>(value));
		else if (key == "ScrollView_CanvasAlign") SetCanvasAlign(utility::ParseValue<Align>(value));
		else if (key == "ScrollView_CanvasSize") SetCanvasSize(utility::ParseValue<IntSize>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

	const IntCoord& ScrollView::GetClientCoord()
	{
		return mScrollClient == nullptr ? GetCoord() : mScrollClient->GetCoord();
	}

	IntSize ScrollView::GetCanvasSize()
	{
		return mWidgetClient == nullptr ? IntSize() : mWidgetClient->GetSize();
	}

} // namespace GUI


