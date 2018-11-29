#ifndef __SCROLL_VIEW_BASE_H__
#define __SCROLL_VIEW_BASE_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	class ScrollViewBase
	{

	protected:
		ScrollViewBase();
		virtual ~ScrollViewBase() { }

		void UpdateScrollSize();
		void UpdateScrollPosition();

		virtual IntSize GetContentSize() { return IntSize(); }
		virtual IntPoint GetContentPosition() { return IntPoint(); }
		virtual void SetContentPosition(const IntPoint& value) { }
		virtual IntSize GetViewSize() const { return IntSize(); }
		virtual size_t GetHScrollPage() { return 1; }
		virtual size_t GetVScrollPage() { return 1; }

		virtual Align GetContentAlign() { return Align::Center; }

		virtual void eraseContent() { }

	protected:
		VScroll* mVScroll;
		HScroll* mHScroll;
		Widget* mClient;

		bool mVisibleHScroll;
		bool mVisibleVScroll;

		size_t mVRange;
		size_t mHRange;

		bool mChangeContentByResize;

	};

} // namespace GUI

#endif // __SCROLL_VIEW_BASE_H__

