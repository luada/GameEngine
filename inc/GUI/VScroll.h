#ifndef __VSCROLL_H__
#define __VSCROLL_H__

#include "Prerequest.h"
#include "Widget.h"
#include "EventPair.h"

namespace GUI
{

	typedef delegates::CDelegate2<VScroll*, size_t> EventHandle_VScrollPtrSizeT;

	class GUI_EXPORT VScroll :
		public Widget
	{
		RTTI_DERIVED(VScroll)
		DEFINE_GET_THIS(VScroll, BASS(Widget, END))

	public:
		VScroll();

		/** Set scroll range */
		//@ExportToLua
		void SetScrollRange(size_t value);
		/** Get scroll range */
		//@ExportToLua
		size_t GetScrollRange() { return mScrollRange; }

		/** Set scroll Position (value from 0 to range - 1) */
		//@ExportToLua
		void SetScrollPosition(size_t value);
		/** Get scroll Position (value from 0 to range - 1) */
		//@ExportToLua
		size_t GetScrollPosition() { return mScrollPosition; }

		/** Set scroll page
			@param _page Tracker step when buttons pressed
		*/
		//@ExportToLua
		void SetScrollPage(size_t value) { mScrollPage = value; }
		/** Get scroll page */
		//@ExportToLua
		size_t GetScrollPage() { return mScrollPage; }

		/** Set scroll view page
			@param _viewPage Tracker step when pressed on scroll line
		*/
		//@ExportToLua
		void SetScrollViewPage(size_t value) { mScrollViewPage = value; }
		/** Get scroll view page */
		//@ExportToLua
		size_t GetScrollViewPage() { return mScrollViewPage; }

		/** Get size in pixels of area where scroll moves */
		//@ExportToLua
		virtual int GetLineSize();

		/** Set size of track in pixels
			@param _value in pixels, if less than MinTrackSize, MinTrackSize used
		*/
		//@ExportToLua
		virtual void SetTrackSize(int value);
		/** Get size of track in pixels */
		//@ExportToLua
		virtual int GetTrackSize();

		/** Set minimal track Size (used for setTrackSize)*/
		//@ExportToLua
		void SetMinTrackSize(int value) { mMinTrackSize = value; }
		/** Get minimal track size */
		//@ExportToLua
		int GetMinTrackSize() { return mMinTrackSize; }

		/** Enable or disable move to click mode.\n
			Move to click mode: Tracker moves to cursor when pressed on scroll line.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetMoveToClick(bool value) { mMoveToClick = value; }
		/** Get move to click mode flag */
		//@ExportToLua
		bool GetMoveToClick() { return mMoveToClick; }

		//! @copydoc Widget::SetPosition(const IntPoint& value)
		virtual void SetPosition(const IntPoint& value);
		//! @copydoc Widget::SetSize(const IntSize& value)
		virtual void SetSize(const IntSize& value);
		//! @copydoc Widget::SetCoord(const IntCoord& value)
		virtual void SetCoord(const IntCoord& value);

		/** @copydoc Widget::SetPosition(int left, int top) */
		//@ExportToLua
		void SetPosition(int left, int top) { SetPosition(IntPoint(left, top)); }
		/** @copydoc Widget::SetSize(int width, int height) */
		//@ExportToLua
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }
		/** @copydoc Widget::SetCoord(int left, int top, int width, int height) */
		//@ExportToLua
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : scroll tracker position changed.\n
			signature : void Method(GUI::VScroll* sender, size_t position)\n
			@param _sender widget that called this event
			@param _position - new tracker position
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_VScrollPtrSizeT> eventScrollChangePosition;


	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~VScroll();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual void UpdateTrack();
		virtual void TrackMove(int left, int top);

		virtual void OnMouseWheel(int rel);

		void NotifyMousePressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseReleased(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseDrag(Widget* sender, int left, int top);
		void NotifyMouseWheel(Widget* sender, int rel);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

	protected:
		Button* mWidgetStart;
		Button* mWidgetEnd;
		Button* mWidgetTrack;
		Button* mWidgetFirstPart;
		Button* mWidgetSecondPart;

		IntPoint mPreActionOffset;

		size_t mSkinRangeStart;
		size_t mSkinRangeEnd;

		size_t mScrollRange;
		size_t mScrollPosition;
		size_t mScrollPage; 
		size_t mScrollViewPage; 

		int mMinTrackSize;
		bool mMoveToClick;

	};

} // namespace GUI

#endif // __VSCROLL_H__


