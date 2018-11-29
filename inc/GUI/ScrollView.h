#ifndef __SCROLL_VIEW_H__
#define __SCROLL_VIEW_H__

#include "Prerequest.h"
#include "Widget.h"
#include "ScrollViewBase.h"

namespace GUI
{

	class GUI_EXPORT ScrollView :
		public Widget,
		protected ScrollViewBase
	{
		RTTI_DERIVED(ScrollView)

	public:
		ScrollView();

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

		/** Show VScroll when text size larger than Edit */
		//@ExportToLua
		void SetVisibleVScroll(bool value);
		/** Get Show VScroll flag */
		//@ExportToLua
		bool IsVisibleVScroll() { return mVisibleVScroll; }

		/** Show HScroll when text size larger than Edit */
		//@ExportToLua
		void SetVisibleHScroll(bool value);
		/** Get Show HScroll flag */
		//@ExportToLua
		bool IsVisibleHScroll() { return mVisibleHScroll; }

		/** Set canvas align */
		//@ExportToLua
		void SetCanvasAlign(Align value);
		/** Get canvas align */
		//@ExportToLua
		Align GetCanvasAlign() { return mContentAlign; }

		/** Set canvas size */
		void SetCanvasSize(const IntSize& value);
		/** Set canvas size */
		//@ExportToLua
		void SetCanvasSize(int width, int height) { SetCanvasSize(IntSize(width, height)); }
		/** Get canvas size */
		//@ExportToLua
		IntSize GetCanvasSize();

		/** Get rect where child widgets placed */
		//@ExportToLua
		const IntCoord& GetClientCoord();

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~ScrollView();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		void NotifyMouseSetFocus(Widget* sender, Widget* old);
		void NotifyMouseLostFocus(Widget* sender, Widget* _new);
		void NotifyMousePressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseReleased(Widget* sender, int left, int top, MouseButton id);

		void NotifyScrollChangePosition(VScroll* sender, size_t position);
		void NotifyMouseWheel(Widget* sender, int rel);

		virtual void OnKeyLostFocus(Widget* _new);
		virtual void OnKeySetFocus(Widget* old);

		void UpdateScrollViewState();
		void UpdateView();

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		virtual IntSize GetContentSize();
		virtual IntPoint GetContentPosition();
		virtual void SetContentPosition(const IntPoint& point);
		virtual IntSize GetViewSize() const;
		virtual size_t GetVScrollPage();
		virtual size_t GetHScrollPage();

		virtual Align GetContentAlign() { return mContentAlign; }

	protected:
		bool mIsFocus;
		bool mIsPressed;

		Widget* mScrollClient;
		Align mContentAlign;

	};

} // namespace GUI

#endif // __SCROLL_VIEW_H__

