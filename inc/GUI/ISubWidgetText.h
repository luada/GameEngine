#ifndef __I_SUB_WIDGET_TEXT_H__
#define __I_SUB_WIDGET_TEXT_H__

#include "Prerequest.h"
#include "ISubWidget.h"
#include "Colour.h"

namespace GUI
{

	class GUI_EXPORT ISubWidgetText : public ISubWidget
	{
		RTTI_DERIVED(ISubWidgetText)

	public:
		virtual ~ISubWidgetText()  { }

		/** Get index of start of selection */
		virtual size_t GetTextSelectionStart() { return 0; }
		/** Get index of end of selection */
		virtual size_t GetTextSelectionEnd() { return 0; }
		/** Set text selection */
		virtual void SetTextSelection(size_t start, size_t end) { }

		virtual bool GetSelectBackground() { return true; }
		virtual void SetSelectBackground(bool normal) { }

		virtual bool GetInvertSelected() { return true; }
		virtual void SetInvertSelected(bool value) { }

		virtual bool IsVisibleCursor() { return false; }
		virtual void SetVisibleCursor(bool value) { }

		virtual size_t GetCursorPosition() { return 0; }
		virtual void SetCursorPosition(size_t index) { }

		virtual void SetWordWrap(bool value) { }

		virtual size_t GetCursorPosition(const IntPoint& point) { return 0; }

		virtual IntCoord GetCursorCoord(size_t position) { return IntCoord(); }

		IntPoint GetCursorPoint(size_t position)
		{
			const IntCoord& coord = GetCursorCoord(position);
			return IntPoint(coord.left + coord.width / 2, coord.top + coord.height / 2);
		}

		IntRect GetCursorRect(size_t position)
		{
			const IntCoord& coord = GetCursorCoord(position);
			return IntRect(coord.left, coord.top, coord.left + coord.width, coord.top + coord.height);
		}

		virtual IntSize GetTextSize() { return IntSize(); }

		virtual void SetViewOffset(const IntPoint& point) { }
		virtual IntPoint GetViewOffset() { return IntPoint(); }

		virtual void SetCaption(const UString& value) { }
		virtual const UString& GetCaption() { static UString caption; return caption; }

		virtual void SetTextColour(const Colour& value) { }
		virtual const Colour& GetTextColour() { return Colour::Zero; }

		virtual void SetFontName(const std::string& value) { }
		virtual const std::string& GetFontName() { static std::string name; return name; }

		virtual void SetFontHeight(int value) { }
		virtual int GetFontHeight() { return 0; }

		virtual void SetTextAlign(Align value) { }
		virtual Align GetTextAlign() { return Align::Default; }

		virtual void SetShiftText(bool value) { }

	};

} // namespace GUI

#endif // __I_SUB_WIDGET_TEXT_H__

