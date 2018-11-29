#ifndef __BUTTON_H__
#define __BUTTON_H__

#include "Prerequest.h"
#include "StaticText.h"

namespace GUI
{

	class GUI_EXPORT Button :
		public StaticText
	{
		RTTI_DERIVED(Button)
		DEFINE_GET_THIS(Button, BASS(StaticText, END))

	public:
		Button();

		//! OLD Set button check state
		//@ExportToLua
		void SetButtonPressed(bool value) { SetStateCheck(value); }

		//! OLD Get buton check
		//@ExportToLua
		bool GetButtonPressed() { return GetStateCheck(); }

		//! Set button check state
		//@ExportToLua
		void SetStateCheck(bool value);

		//! Get buton check
		//@ExportToLua
		bool GetStateCheck() { return mIsStateCheck; }

		//! Set image Index (image should be defined in skin)
		//@ExportToLua
		void SetImageIndex(size_t value);
		//! Get image index
		//@ExportToLua
		size_t GetImageIndex();

		/** Enable or disable Image mode\n
			Image mode: when button state changed Image on button also change it's picture.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetModeImage(bool value);
		/** Get Image mode flag */
		//@ExportToLua
		bool GetModeImage() { return mModeImage; }

		/** Get pointer to glyph image for this Button (if it exist in button skin) */
		//@ExportToLua
		StaticImage* GetStaticImage() { return mImage; }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

		void _setMouseFocus(bool focus);

	protected:
		virtual ~Button();

		virtual void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual void OnMouseLostFocus(Widget* _new);
		virtual void OnMouseSetFocus(Widget* old);
		virtual void OnMouseButtonPressed(int left, int top, MouseButton id);
		virtual void OnMouseButtonReleased(int left, int top, MouseButton id);

		virtual void BaseUpdateEnable();

		bool _setState(const std::string& value);
		void SetImageResource(const std::string& name);

	private:
		void UpdateButtonState();

		void ShutdownWidgetSkin();
		void InitialiseWidgetSkin(ResourceSkin* info);

	private:
		bool mIsMousePressed;
		bool mIsMouseFocus;
		bool mIsStateCheck;

		StaticImage* mImage;
		bool mModeImage;

	};

} // namespace GUI

#endif // __BUTTON_H__

