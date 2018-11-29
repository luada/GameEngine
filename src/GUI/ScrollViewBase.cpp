#include "Precompiled.h"
#include "ScrollViewBase.h"
#include "VScroll.h"
#include "HScroll.h"

namespace GUI
{

	ScrollViewBase::ScrollViewBase() :
		mVScroll(nullptr),
		mHScroll(nullptr),
		mClient(nullptr),
		mVisibleHScroll(true),
		mVisibleVScroll(true),
		mVRange(0),
		mHRange(0),
		mChangeContentByResize(false)
	{
	}

	void ScrollViewBase::UpdateScrollSize()
	{
		if (mClient == nullptr)
			return;

		eraseContent();
		IntSize contentSize = GetContentSize();
		IntSize viewSize = GetViewSize();

		if (contentSize.height > viewSize.height)
		{
			if (mVScroll != nullptr)
			{
				if (( ! mVScroll->IsVisible()) && (mVisibleVScroll))
				{
					mVScroll->SetVisible(true);
					mClient->SetSize(mClient->GetWidth() - mVScroll->GetWidth(), mClient->GetHeight());

					if (mChangeContentByResize)
					{
						eraseContent();
						contentSize = GetContentSize();
						viewSize = GetViewSize();
					}

					if (mHScroll != nullptr)
					{
						mHScroll->SetSize(mHScroll->GetWidth() - mVScroll->GetWidth(), mHScroll->GetHeight());

						if ((contentSize.width > viewSize.width) && ( ! mHScroll->IsVisible()) && (mVisibleHScroll))
						{
							mHScroll->SetVisible(true);
							mClient->SetSize(mClient->GetWidth(), mClient->GetHeight() - mHScroll->GetHeight());
							mVScroll->SetSize(mVScroll->GetWidth(), mVScroll->GetHeight() - mHScroll->GetHeight());

							if (mChangeContentByResize)
							{
								eraseContent();
								contentSize = GetContentSize();
								viewSize = GetViewSize();
							}

						}
					}
				}
			}
		}
		else
		{
			if (mVScroll != nullptr)
			{
				if (mVScroll->IsVisible())
				{
					mVScroll->SetVisible(false);
					mClient->SetSize(mClient->GetWidth() + mVScroll->GetWidth(), mClient->GetHeight());

					if (mChangeContentByResize)
					{
						eraseContent();
						contentSize = GetContentSize();
						viewSize = GetViewSize();
					}

					if (mHScroll != nullptr)
					{
						mHScroll->SetSize(mHScroll->GetWidth() + mVScroll->GetWidth(), mHScroll->GetHeight());

						if ((contentSize.width <= viewSize.width) && (mHScroll->IsVisible()))
						{
							mHScroll->SetVisible(false);
							mClient->SetSize(mClient->GetWidth(), mClient->GetHeight() + mHScroll->GetHeight());
							mVScroll->SetSize(mVScroll->GetWidth(), mVScroll->GetHeight() + mHScroll->GetHeight());

							if (mChangeContentByResize)
							{
								eraseContent();
								contentSize = GetContentSize();
								viewSize = GetViewSize();
							}

						}
					}
				}
			}
		}


		if (contentSize.width > viewSize.width)
		{
			if (mHScroll != nullptr)
			{
				if (( ! mHScroll->IsVisible()) && (mVisibleHScroll))
				{
					mHScroll->SetVisible(true);
					mClient->SetSize(mClient->GetWidth(), mClient->GetHeight() - mHScroll->GetHeight());

					if (mChangeContentByResize)
					{
						eraseContent();
						contentSize = GetContentSize();
						viewSize = GetViewSize();
					}

					if (mVScroll != nullptr)
					{
						mVScroll->SetSize(mVScroll->GetWidth(), mVScroll->GetHeight() - mHScroll->GetHeight());

						if ((contentSize.height > viewSize.height) && ( ! mVScroll->IsVisible()) && (mVisibleVScroll))
						{
							mVScroll->SetVisible(true);
							mClient->SetSize(mClient->GetWidth() - mVScroll->GetWidth(), mClient->GetHeight());
							mHScroll->SetSize(mHScroll->GetWidth() - mVScroll->GetWidth(), mHScroll->GetHeight());

							if (mChangeContentByResize)
							{
								eraseContent();
								contentSize = GetContentSize();
								viewSize = GetViewSize();
							}

						}
					}
				}
			}
		}
		else
		{
			if (mHScroll != nullptr)
			{
				if (mHScroll->IsVisible())
				{
					mHScroll->SetVisible(false);
					mClient->SetSize(mClient->GetWidth(), mClient->GetHeight() + mHScroll->GetHeight());

					if (mChangeContentByResize)
					{
						eraseContent();
						contentSize = GetContentSize();
						viewSize = GetViewSize();
					}

					if (mVScroll != nullptr)
					{
						mVScroll->SetSize(mVScroll->GetWidth(), mVScroll->GetHeight() + mHScroll->GetHeight());

						if ((contentSize.height <= viewSize.height) && (mVScroll->IsVisible()))
						{
							mVScroll->SetVisible(false);
							mClient->SetSize(mClient->GetWidth() + mVScroll->GetWidth(), mClient->GetHeight());
							mHScroll->SetSize(mHScroll->GetWidth() + mVScroll->GetWidth(), mHScroll->GetHeight());

							if (mChangeContentByResize)
							{
								eraseContent();
								contentSize = GetContentSize();
								viewSize = GetViewSize();
							}
						}
					}
				}
			}
		}

		mVRange = (viewSize.height >= contentSize.height) ? 0 : contentSize.height - viewSize.height;
		mHRange = (viewSize.width >= contentSize.width) ? 0 : contentSize.width - viewSize.width;

		if (mVScroll != nullptr)
		{
			size_t page = GetVScrollPage();
			mVScroll->SetScrollPage(page);
			mVScroll->SetScrollViewPage(viewSize.width > (int)page ? viewSize.width : page);
			mVScroll->SetScrollRange(mVRange + 1);
			if (contentSize.height) mVScroll->SetTrackSize(int (float(mVScroll->GetLineSize() * viewSize.height) / float(contentSize.height)));
		}
		if (mHScroll != nullptr)
		{
			size_t page = GetHScrollPage();
			mHScroll->SetScrollPage(page);
			mHScroll->SetScrollViewPage(viewSize.height > (int)page ? viewSize.height : page);
			mHScroll->SetScrollRange(mHRange + 1);
			if (contentSize.width) mHScroll->SetTrackSize(int (float(mHScroll->GetLineSize() * viewSize.width) / float(contentSize.width)));
		}
	}

	void ScrollViewBase::UpdateScrollPosition()
	{
		IntSize contentSize = GetContentSize();
		IntPoint contentPoint = GetContentPosition();
		IntPoint offset = contentPoint;

		IntSize viewSize = GetViewSize();

		Align align = GetContentAlign();

		if (contentSize.width > viewSize.width)
		{
			if ((offset.left + viewSize.width) > contentSize.width)
			{
				offset.left = contentSize.width - viewSize.width;
			}
			else if (offset.left < 0)
			{
				offset.left = 0;
			}
		}
		else
		{
			if (align.IsLeft())
			{
				offset.left = 0;
			}
			else if (align.IsRight())
			{
				offset.left = contentSize.width - viewSize.width;
			}
			else
			{
				offset.left = (contentSize.width - viewSize.width) / 2;
			}
		}

		if (contentSize.height > viewSize.height)
		{
			if ((offset.top + viewSize.height) > contentSize.height)
			{
				offset.top = contentSize.height - viewSize.height;
			}
			else if (offset.top < 0)
			{
				offset.top = 0;
			}
		}
		else
		{
			if (align.IsTop())
			{
				offset.top = 0;
			}
			else if (align.IsBottom())
			{
				offset.top = contentSize.height - viewSize.height;
			}
			else
			{
				offset.top = (contentSize.height - viewSize.height) / 2;
			}
		}

		if (offset != contentPoint)
		{
			if (nullptr != mVScroll) mVScroll->SetScrollPosition(offset.top);
			if (nullptr != mHScroll) mHScroll->SetScrollPosition(offset.left);
			SetContentPosition(offset);
		}
	}

} // namespace GUI

