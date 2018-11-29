#ifndef __WINDOW_H__
#define __WINDOW_H__

#include "Prerequest.h"
#include "Widget.h"
#include "EventPair.h"
#include "ControllerFadeAlpha.h"

namespace GUI
{

	// OBSOLETE
	typedef delegates::CDelegate2<Widget*, const std::string&> EventHandle_WidgetString;
	typedef delegates::CDelegate2<Window*, const std::string&> EventHandle_WindowPtrCStringRef;
	typedef delegates::CDelegate1<Window*> EventHandle_WindowPtr;

	class GUI_EXPORT Window :
		public Widget
	{
		RTTI_DERIVED(Window)
		DEFINE_GET_THIS(Window, BASS(Widget, END))

	public:
		Window();

		/** @copydoc Widget::setVisible */
		//@ExportToLua
		virtual void SetVisible(bool value);

		/** Hide or show window smooth */
		//@ExportToLua
		void SetVisibleSmooth(bool value);

		/** Hide window smooth and then destroy it */
		//@ExportToLua
		void DestroySmooth();

		/** Enable or disable auto alpha mode */
		//@ExportToLua
		void SetAutoAlpha(bool value);

		/** Get auto alpha mode flag */
		//@ExportToLua
		bool GetAutoAlpha() { return mIsAutoAlpha; }

		/** Set window caption */
		//@ExportToLua
		virtual void SetCaption(const UString& value);

		/** Get window caption */
		//@ExportToLua
		virtual const UString& GetCaption();

		/** Get window caption widget */
		//@ExportToLua
		Widget* GetCaptionWidget() { return mWidgetCaption; }

		/** Set minimal possible window size */
		void SetMinSize(const IntSize& value);

		/** Set minimal possible window size */
		//@ExportToLua
		void SetMinSize(int width, int height) { SetMinSize(IntSize(width, height)); }

		/** Get minimal possible window size */
		//@ExportToLua
		IntSize GetMinSize();

		/** Set maximal possible window size */

		void SetMaxSize(const IntSize& value);
		/** Set maximal possible window size */
		//@ExportToLua
		void SetMaxSize(int width, int height) { SetMaxSize(IntSize(width, height)); }

		/** Get maximal possible window size */
		//@ExportToLua
		IntSize GetMaxSize();

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

		/** Get snap to borders mode flag */
		//@ExportToLua
		bool GetSnap() { return mSnap; }

		/** Enable or disable snap to borders mode */
		//@ExportToLua
		void SetSnap(bool value) { mSnap = value; }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : Window button pressed.\n
			signature : void Method(GUI::Window* sender, const std::string& name)
			@param _sender widget that called this event
			@param _name of pressed button
		*/
		EventPair<EventHandle_WidgetString, EventHandle_WindowPtrCStringRef> eventWindowButtonPressed;

		/** Event : Window coordinate Changed (window was resized or moved).\n
			signature : void Method(GUI::Window* sender)
			@param _sender widget that called this event
		*/
		EventPair<EventHandle_WidgetVoid, EventHandle_WindowPtr> eventWindowChangeCoord;

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~Window();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		void OnMouseChangeRootFocus(bool focus);
		void OnKeyChangeRootFocus(bool focus);
		void OnMouseDrag(int left, int top);
		void OnMouseButtonPressed(int left, int top, MouseButton id);

		void NotifyMousePressed(GUI::Widget* sender, int left, int top, MouseButton id);
		void NotifyPressedButtonEvent(GUI::Widget* sender);
		void NotifyMouseDrag(GUI::Widget* sender, int left, int top);

		void UpdateAlpha();

		void AnimateStop(Widget* widget);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		float GetAlphaVisible();
		void GetSnappedCoord(IntCoord& coord);

		ControllerFadeAlpha* CreateControllerFadeAlpha(float alpha, float coef, bool enable);

	private:
		Widget* mWidgetCaption;

		IntCoord mPreActionCoord;

		bool mMouseRootFocus;
		bool mKeyRootFocus;

		bool mIsAutoAlpha;

		IntRect mMinmax;

		bool mSnap; 

		IntCoord mCurrentActionScale;
		bool mAnimateSmooth;

	};

} // namespace GUI

#endif // __WINDOW_H__


