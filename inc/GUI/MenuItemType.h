#ifndef __MENU_ITEM_TYPE_H__
#define __MENU_ITEM_TYPE_H__

#include "Prerequest.h"

namespace GUI
{

	struct GUI_EXPORT MenuItemType
	{
		enum Enum
		{
			Normal,
			Popup,
			Separator,
			MAX
		};

		static MenuItemType Parse(const std::string& value)
		{
			MenuItemType type;
			int curValue = 0;
			while (true)
			{
				const char * name = type.GetValueName(curValue);
				if (strcmp(name, "") == 0 || name == value) break;
				curValue++;
			}
			type.value = MenuItemType::Enum(curValue);
			return type;
		}

		MenuItemType(Enum value = MAX) : value(value) { }

		friend bool operator == (MenuItemType const& a, MenuItemType const& b) { return a.value == b.value; }
		friend bool operator != (MenuItemType const& a, MenuItemType const& b) { return a.value != b.value; }

		friend std::ostream& operator << (std::ostream& stream, const MenuItemType&  value)
		{
			stream << value.GetValueName(value.value);
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, MenuItemType&  value)
		{
			std::string curValue;
			stream >> curValue;
			value = MenuItemType::Parse(curValue);
			return stream;
		}

		std::string Print() const { return GetValueName(value); }

	private:
		const char * GetValueName(int index) const
		{
			static const char * values[MAX + 1] = { "Normal", "Popup", "Separator", "" };
			return values[(index < MAX && index >= 0) ? index : MAX];
		}

	private:
		Enum value;
	};

} // namespace GUI

#endif // __MENU_ITEM_TYPE_H__
