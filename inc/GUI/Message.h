#ifndef __MESSAGE_H__
#define __MESSAGE_H__

#include "Prerequest.h"
#include "Window.h"
#include "ResourceImageSet.h"
#include "EventPair.h"
#include "MessageStyle.h"
#include "ControllerFadeAlpha.h"

namespace GUI
{

	typedef delegates::CDelegate2<Message*, MessageBoxStyle> EventHandle_MessagePtrMessageStyle;

	class GUI_EXPORT Message :
		public Window
	{
		RTTI_DERIVED(Message)
		DEFINE_GET_THIS(Message, BASS(Window, END))

	public:
		Message();

		/** Set message text*/
		//@ExportToLua
		void SetMessageText(const UString& value);

		/** Create button with specific name*/
		//@ExportToLua
		MessageBoxStyle AddButtonName(const UString& name);

		/** Set smooth message showing*/
		//@ExportToLua
		void SetSmoothShow(bool value);

		/** Get name of default layer for Message*/
		//@ExportToLua
		const std::string& GetDefaultLayer() { return mDefaultLayer; }

		/** Set message icon*/
		//@ExportToLua
		void SetMessageIcon(MessageBoxStyle value);
		/** Set fade under message*/
		//@ExportToLua
		void SetWindowFade(bool value);

		//@ExportToLua
		void endMessage(MessageBoxStyle result);
		//@ExportToLua
		void endMessage();

		/** Create button using MessageBoxStyle*/
		//@ExportToLua
		void SetMessageButton(MessageBoxStyle value);

		/** Set message Style (button and icon)*/
		//@ExportToLua
		void SetMessageStyle(MessageBoxStyle value);

		//@ExportToLua
		void SetMessageModal(bool value);

		/** Static method for creating message with one command
			@param
				_modal if true all other GUI elements will be blocked untill message is closed
			@param
				_style any combination of flags from ViewValueInfo
			@param
				_button1 ... _button4 specific buttons names
		*/
		//@ExportToLua
		static GUI::Message* CreateMessageBox(const std::string& skin,
			const UString& caption,
			const UString& message,
			MessageBoxStyle style = MessageBoxStyle::Ok | MessageBoxStyle::IconDefault,
			const std::string& layer = "",
			bool modal = true,
			const std::string& button1 = "",
			const std::string& button2 = "",
			const std::string& button3 = "",
			const std::string& button4 = "");


		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : button on message window pressed.\n
			signature : void Method(GUI::Message* sender, GUI::MessageBoxStyle result)\n
			@param _sender widget that called this event
			@param _result - id of pressed button
		*/
		EventHandle_MessagePtrMessageStyle eventMessageBoxResult;

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~Message();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		void UpdateSize();
		void NotifyButtonClick(GUI::Widget* sender);
		void ClearButton();

		void OnKeyButtonPressed(KeyCode key, Char _char);
		void _destroyMessage(MessageBoxStyle result);

		UString GetButtonName(MessageBoxStyle style);
		const char * GetIconName(size_t index);
		const char * GetButtonName(size_t index);
		const char * GetButtonTag(size_t index);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		ControllerFadeAlpha* CreateControllerFadeAlpha(float alpha, float coef, bool enable);

	private:
		IntSize mOffsetText;
		Widget* mWidgetText;

		std::string mButtonSkin, mButtonType;
		IntSize mButtonSize, mButtonOffset;

		VectorWidgetPtr mVectorButton;
		MessageBoxStyle mInfoOk;
		MessageBoxStyle mInfoCancel;
		bool mSmoothShow;

		std::string mDefaultLayer, mDefaultCaption;
		std::string mFadeSkin, mFadeLayer;
		Widget* mWidgetFade;
		StaticImage* mIcon;
		int mLeftOffset1;
		int mLeftOffset2;

	};

} // namespace GUI

#endif // __MESSAGE_H__
