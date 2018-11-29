#ifndef __WIDGET_EVENT_H__
#define __WIDGET_EVENT_H__

#include "Prerequest.h"
#include "Macros.h"
#include "WidgetDefines.h"
#include "WidgetToolTip.h"
#include "InputDefine.h"

namespace GUI
{

	typedef delegates::CDelegate1<Widget*> EventHandle_WidgetVoid;
	typedef delegates::CDelegate2<Widget*, Widget*> EventHandle_WidgetWidget;
	typedef delegates::CDelegate2<Widget*, bool> EventHandle_WidgetBool;
	typedef delegates::CDelegate2<Widget*, int> EventHandle_WidgetInt;
	typedef delegates::CDelegate2<Widget*, size_t> EventHandle_WidgetSizeT;
	typedef delegates::CDelegate3<Widget*, int, int> EventHandle_WidgetIntInt;
	typedef delegates::CDelegate4<Widget*, int, int, MouseButton> EventHandle_WidgetIntIntButton;
	typedef delegates::CDelegate2<Widget*, KeyCode> EventHandle_WidgetKeyCode;
	typedef delegates::CDelegate3<Widget*, KeyCode, Char> EventHandle_WidgetKeyCodeChar;
	typedef delegates::CDelegate3<Widget*, const std::string&, const std::string&> EventHandle_WidgetStringString;
	typedef delegates::CDelegate3<Widget*, Widget*&, size_t &> EventHandle_WidgetRefWidgetRefSizeT;
	typedef delegates::CDelegate2<Widget*, const ToolTipInfo& > EventHandle_WidgetToolTip;

	/**
	General information about creating delegate for event :
	@example "Delegate usage"
	@code
		void AnyFunc(...) { } // global function

		class AnyClass
		{
		public:
			static void AnyStaticMethod(...) { } // static class method
			void AnyMethod(...) { } // class method
		};

		AnyClass anyObject; // class instance
	@endcode

	delegate creating:
	@code
		eventAny = GUI::NewDelegate(anyFunc);
		eventAny = GUI::NewDelegate(AnyClass::anyStaticMethod);
		eventAny = GUI::NewDelegate(&anyObject, &AnyClass::anyMethod);
	@endcode
	*/

	class GUI_EXPORT WidgetEvent
	{
		friend class InputManager;

    public:
		virtual ~WidgetEvent() { }

	protected:
		WidgetEvent() :
			mWidgetEventSender(0),
			mRootMouseActive(false),
			mRootKeyActive(false)
		{
		}

	public:

		/** Event : Widget lost mouse focus.\n
			signature : void Method(GUI::Widget* sender, GUI::Widget* _new)\n
			@param _sender widget that called this event
			@param _new widget with mouse focus or nullptr
		*/
		EventHandle_WidgetWidget eventMouseLostFocus;

		/** Event : Widget got mouse focus.\n
			signature : void Method(GUI::Widget* sender, GUI::Widget* old)\n
			@param _sender widget that called this event
			@param _old widget with mouse focus or nullptr
		*/
		EventHandle_WidgetWidget eventMouseSetFocus;

		/** Event : Widget mouse move with captured widget.\n
			signature : void Method(GUI::Widget* sender, int left, int top)\n
			@param _sender widget that called this event
			@param _left - pointer position
			@param _top - pointer position
		*/
		EventHandle_WidgetIntInt eventMouseDrag;

		/** Event : Mouse move over widget.\n
			signature : void Method(GUI::Widget* sender, int left, int top)\n
			@param _sender widget that called this event
			@param _left - pointer position
			@param _top - pointer position
		*/
		EventHandle_WidgetIntInt eventMouseMove;

		/** Event : Mouse wheel over widget.\n
			signature : void Method(GUI::Widget* sender, int rel)\n
			@param _sender widget that called this event
			@param _rel relative wheel position
		*/
		EventHandle_WidgetInt eventMouseWheel;

		/** Event : Mouse button pressed.\n
			signature : void Method(GUI::Widget* sender, int left, int top, GUI::MouseButton id)\n
			@param _sender widget that called this event
			@param _left - pointer position
			@param _top - pointer position
			@param _id Mouse button id
		*/
		EventHandle_WidgetIntIntButton eventMouseButtonPressed;

		/** Event : Mouse button released.\n
			signature : void Method(GUI::Widget* sender, int left, int top, GUI::MouseButton id)\n
			@param _sender widget that called this event
			@param _left - pointer position
			@param _top - pointer position
			@param _id Mouse button id
		*/
		EventHandle_WidgetIntIntButton eventMouseButtonReleased;

		/** Event : Mouse button pressed and released.\n
			signature : void Method(GUI::Widget* sender)
			@param _sender widget that called this event
		*/
		EventHandle_WidgetVoid eventMouseButtonClick;

		/** Event : Mouse button double click.\n
			signature : void Method(GUI::Widget* sender)
			@param _sender widget that called this event
		*/
		EventHandle_WidgetVoid eventMouseButtonDoubleClick;

		/** Event : Widget lost keyboard focus.\n
			signature : void Method(GUI::Widget* sender, GUI::Widget* _new)\n
			@param _sender widget that called this event
			@param _new widget with keyboard focus or nullptr
		*/
		EventHandle_WidgetWidget eventKeyLostFocus;

		/** Event : Widget got keyboard focus.\n
			signature : void Method(GUI::Widget* sender, GUI::Widget* old)\n
			@param _sender widget that called this event
			@param _old widget with keyboard focus or nullptr
		*/
		EventHandle_WidgetWidget eventKeySetFocus;

		/** Event : Key pressed.\n
			signature : void Method(GUI::Widget* sender, GUI::KeyCode key, GUI::Char _char)\n
			@param _sender widget that called this event
			@param _key code
			@param _char of pressed Symbol (for multilanguage applications)
		*/
		EventHandle_WidgetKeyCodeChar eventKeyButtonPressed;

		/** Event : Key released.\n
			signature : void Method(GUI::Widget* sender, GUI::KeyCode key)\n
			@param _sender widget that called this event
			@param _key code
		*/
		EventHandle_WidgetKeyCode eventKeyButtonReleased;

		/** Event : Root widget changed mouse focus.\n
			info : this event sends only to root widget\n
			signature : void Method(GUI::Widget* sender, bool focus);
			@param _sender widget that called this event
			@param _focus Is widget got mouse focus.
		*/
		EventHandle_WidgetBool  eventRootMouseChangeFocus;

		/** Event : Root widget changed keyboard focus.\n
			info : this event sends only to root widget\n
			signature : void Method(GUI::Widget* sender, bool focus);
			@param _sender widget that called this event
			@param _focus Is widget got keyboard focus.
		*/
		EventHandle_WidgetBool eventRootKeyChangeFocus;

		/** Event : Event about changing tooltip state.\n
			signature : void Method(GUI::Widget* sender, const GUI::ToolTipInfo& info);
			@param _sender widget that called this event
			@param _info about tooltip
		*/
		EventHandle_WidgetToolTip eventToolTip;

		/** Event : Extendeble event for special cases or plugins.\n
			signature : void Method(GUI::Widget* sender, const std::string& key, const std::string& value);
			@param _sender widget that called this event
			@param _key
			@param _value
		*/
		EventHandle_WidgetStringString eventActionInfo;

		/** Event : Internal request for parent and item index, used for any widget.\n
			signature : void Method(GUI::Widget* sender, GUI::Widget*& container, size_t& index);
			@param _sender widget that called this event
			@param _container parent
			@param index of container
		*/
		EventHandle_WidgetRefWidgetRefSizeT _requestGetContainer;

		/** Event : Widget property changed through SetProperty (in code, or from layout)\n
			signature : void Method(GUI::Widget* sender, const std::string& key, const std::string& value);
			@param _sender widget that called this event
			@param _key
			@param _value
		*/
		EventHandle_WidgetStringString eventChangeProperty;

	protected:

		virtual void OnMouseLostFocus(Widget* _new)
		{
			eventMouseLostFocus(mWidgetEventSender, _new);
		}

		virtual void OnMouseSetFocus(Widget* old)
		{
			eventMouseSetFocus(mWidgetEventSender, old);
		}

		virtual void OnMouseDrag(int left, int top)
		{
			eventMouseDrag(mWidgetEventSender, left, top);
		}

		virtual void OnMouseMove(int left, int top)
		{
			eventMouseMove(mWidgetEventSender, left, top);
		}

		virtual void OnMouseWheel(int rel)
		{
			eventMouseWheel(mWidgetEventSender, rel);
		}

		virtual void OnMouseButtonPressed(int left, int top, MouseButton id)
		{
			eventMouseButtonPressed(mWidgetEventSender, left, top, id);
		}

		virtual void OnMouseButtonReleased(int left, int top, MouseButton id)
		{
			eventMouseButtonReleased(mWidgetEventSender, left, top, id);
		}

		virtual void OnMouseButtonClick()
		{
			eventMouseButtonClick(mWidgetEventSender);
		}

		virtual void OnMouseButtonDoubleClick()
		{
			eventMouseButtonDoubleClick(mWidgetEventSender);
		}

		virtual void OnKeyLostFocus(Widget* _new)
		{
			eventKeyLostFocus(mWidgetEventSender, _new);
		}

		virtual void OnKeySetFocus(Widget* old)
		{
			eventKeySetFocus(mWidgetEventSender, old);
		}

		virtual void OnKeyButtonPressed(KeyCode key, Char _char)
		{
			eventKeyButtonPressed(mWidgetEventSender, key, _char);
		}

		virtual void OnKeyButtonReleased(KeyCode key)
		{
			eventKeyButtonReleased(mWidgetEventSender, key);
		}

		virtual void OnMouseChangeRootFocus(bool focus)
		{
			eventRootMouseChangeFocus(mWidgetEventSender, focus);
		}

		virtual void OnKeyChangeRootFocus(bool focus)
		{
			eventRootKeyChangeFocus(mWidgetEventSender, focus);
		}

		Widget* mWidgetEventSender;

	private:
		bool mRootMouseActive;
		bool mRootKeyActive;
	};

} // namespace GUI

#endif // __WIDGET_EVENT_H__

