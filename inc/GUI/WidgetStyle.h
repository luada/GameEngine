#ifndef __WIDGET_TYPE_H__
#define __WIDGET_TYPE_H__

#include "Prerequest.h"
#include <string.h>

namespace GUI
{

	struct GUI_EXPORT WidgetStyle
	{
		//@ExportToLua
		enum Enum
		{
			Child, /**< child widget, cropped by parent widget borders, no Overlapping (used by default for child widgets) */
			Popup, /**< popup widget, have parent widget, but not cropped on its borders */
			Overlapped, /**< child widget, cropped by parent widget borders, can Overlap (used by default for root widgets) */
			MAX
		};

		//@ExportToLua
		static WidgetStyle Parse(const std::string& value)
		{
			WidgetStyle type;
			int curValue = 0;
			while (true)
			{
				const char * name = type.GetValueName(curValue);
				if (strcmp(name, "") == 0 || name == value) break;
				curValue++;
			}
			type.value = (Enum)curValue;
			return type;
		}

		//@ExportToLua
		WidgetStyle() : value(MAX) { }
		//@ExportToLua
		WidgetStyle(Enum value) : value(value) { }

		friend bool operator == (WidgetStyle const& a, WidgetStyle const& b) { return a.value == b.value; }
		friend bool operator != (WidgetStyle const& a, WidgetStyle const& b) { return a.value != b.value; }

		friend std::ostream& operator << (std::ostream& stream, const WidgetStyle&  value)
		{
			stream << value.GetValueName(value.value);
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, WidgetStyle&  value)
		{
			std::string curValue;
			stream >> curValue;
			value = WidgetStyle::Parse(curValue);
			return stream;
		}

		//@ExportToLua
		std::string Print() const { return GetValueName(value); }

	private:
		const char * GetValueName(int index) const
		{
			static const char * values[MAX + 1] = { "Child", "Popup", "Overlapped", "" };
			return values[(index < MAX && index >= 0) ? index : MAX];
		}

	private:
		Enum value;
	};

} // namespace GUI

#endif // __WIDGET_TYPE_H__
