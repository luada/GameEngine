#ifndef __STATIC_TEXT_H__
#define __STATIC_TEXT_H__

#include "Prerequest.h"
#include "Widget.h"

namespace GUI
{

	class GUI_EXPORT StaticText :
		public Widget
	{
		RTTI_DERIVED(StaticText)
		DEFINE_GET_THIS(StaticText, BASS(Widget, END))

	public:
		StaticText();

		/** Get text region coordinate */
		//@ExportToLua
		IntCoord GetTextRegion();

		/** Get text region size */
		//@ExportToLua
		IntSize GetTextSize();

		/** Set widget text font */
		//@ExportToLua
		virtual void SetFontName(const std::string& value);

		/** Get widget text font name */
		//@ExportToLua
		const std::string& GetFontName();

		/** Set widget text font height */
		//@ExportToLua
		virtual void SetFontHeight(int value);

		/** Get widget text font height */
		//@ExportToLua
		int GetFontHeight();

		/** Set widget text align */
		//@ExportToLua
		virtual void SetTextAlign(Align value);

		/** Get widget text align */
		//@ExportToLua
		Align GetTextAlign();

		/** Set widget text colour */
		//@ExportToLua
		virtual void SetTextColour(const Colour& value);

		/** Get widget text colour */
		//@ExportToLua
		const Colour& GetTextColour();

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~StaticText();

		void BaseChangeWidgetSkin(ResourceSkin* info);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

	};

} // namespace GUI

#endif // __STATIC_TEXT_H__
