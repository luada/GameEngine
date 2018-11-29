#ifndef __INPUT_MANAGER_H__
#define __INPUT_MANAGER_H__

#include "Prerequest.h"
#include "Macros.h"
#include "Instance.h"
#include "WidgetDefines.h"
#include "IUnlinkWidget.h"
#include "WidgetDefines.h"
#include "XmlDocument.h"
#include "InputDefine.h"
#include "Timer.h"
#include "ILayer.h"
#include "Delegate.h"

namespace GUI
{

	class GUI_EXPORT InputManager : public IUnlinkWidget
	{
		INSTANCE_HEADER(InputManager)

	public:
		void Initialise();
		void Shutdown();

		/** Inject MouseMove event
			@return true if event has been processed by GUI
		*/
		bool InjectMouseMove(int absx, int absy, int absz);
		/** Inject MousePress event
			@return true if event has been processed by GUI
		*/
		bool InjectMousePress(int absx, int absy, MouseButton id);
		/** Inject MouseRelease event
			@return true if event has been processed by GUI
		*/
		bool InjectMouseRelease(int absx, int absy, MouseButton id);

		/** Inject KeyPress event
			@return true if event has been processed by GUI
		*/
		bool InjectKeyPress(KeyCode key, Char text = 0);
		/** Inject KeyRelease event
			@return true if event has been processed by GUI
		*/
		bool InjectKeyRelease(KeyCode key);

		/** Is any widget have mouse focus */
		bool IsFocusMouse() { return mWidgetMouseFocus != nullptr; }
		/** Is any widget have key focus */
		bool IsFocusKey() { return mWidgetKeyFocus != nullptr; }
		/** Is any widget captured mouse */
		bool IsCaptureMouse() { return mIsWidgetMouseCapture; }

		/** Set key focus for _widget */
		void SetKeyFocusWidget(Widget* widget);
		/** Drop key focus for _widget */
		void ResetKeyFocusWidget(Widget* widget);
		/** Drop any key focus */
		void ResetKeyFocusWidget() { SetKeyFocusWidget(nullptr); }

		/** Get mouse focused widget */
		Widget* GetMouseFocusWidget() { return mWidgetMouseFocus; }
		/** Get key focused widget */
		Widget* GetKeyFocusWidget() { return mWidgetKeyFocus; }
		/** Get position of last left mouse button press */
		const IntPoint& GetLastLeftPressed() { return mLastLeftPressed; }
		/** Get current mouse position */
		const IntPoint& GetMousePosition() { return mMousePosition; }

		IntPoint GetMousePositionByLayer();

		/** Drop any mouse focus */
		void ResetMouseFocusWidget();

		/** Add modal widget - all other widgets inaccessible while modal widget exist */
		void AddWidgetModal(Widget* widget);
		/** Remove modal widget */
		void RemoveWidgetModal(Widget* widget);

		/** Return true if any modal widget exist */
		bool IsModalAny() { return !mVectorModalRootWidget.empty(); }

		/** Is control button pressed */
		bool IsControlPressed() { return mIsControlPressed; }
		/** Is shift button pressed */
		bool IsShiftPressed() { return mIsShiftPressed; }

		/** Reset mouse Capture (for example when we dragging and application
			lost focus you should call this)
		*/
		void ResetMouseCaptureWidget() { mIsWidgetMouseCapture = false; }

		void UnlinkWidget(Widget* widget) { _unlinkWidget(widget); }

		/** Event :\n
			signature : void Method(GUI::Widget* widget)\n
			@param _widget
		*/
		delegates::CMultiDelegate1<Widget*>
			eventChangeMouseFocus;

		/** Event :\n
			signature : void Method(GUI::Widget* widget)\n
			@param _widget
		*/
		delegates::CMultiDelegate1<Widget*>
			eventChangeKeyFocus;

	private:
		void _unlinkWidget(Widget* widget);

		void FrameEntered(float frame);

		void FirstEncoding(KeyCode key, bool bIsKeyPressed);

		void StoreKey(KeyCode key, Char text);

		void ResetKey();

	private:
		Widget* mWidgetMouseFocus;
		Widget* mWidgetKeyFocus;
		ILayer* mLayerMouseFocus;
		bool mIsWidgetMouseCapture;
	    Timer mTimer; //used for double click timing

		bool mIsShiftPressed;
		bool mIsControlPressed;
		IntPoint mLastLeftPressed;
		IntPoint mMousePosition;
		KeyCode mHoldKey;
		Char mHoldChar;
		bool mFirstPressKey;
		float mTimerKey;
		int mOldAbsZ;

		VectorWidgetPtr mVectorModalRootWidget;

	};

} // namespace GUI

#endif // __INPUT_MANAGER_H__

