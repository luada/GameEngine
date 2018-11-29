#ifndef __MESSAGE_BOX_STYLE_H__
#define __MESSAGE_BOX_STYLE_H__

#include "Prerequest.h"

namespace GUI
{


	struct GUI_EXPORT MessageBoxStyle
	{

		//@ExportToLua
		enum Enum
		{
			None = FLAG_NONE,
			Ok = FLAG(0),
			Yes = FLAG(1),
			No = FLAG(2),
			Abort = FLAG(3),
			Retry = FLAG(4),
			Ignore = FLAG(5),
			Cancel = FLAG(6),
			Try = FLAG(7),
			Continue = FLAG(8),

			_IndexUserButton1 = 9, 

			Button1 = FLAG(_IndexUserButton1),
			Button2 = FLAG(_IndexUserButton1 + 1),
			Button3 = FLAG(_IndexUserButton1 + 2),
			Button4 = FLAG(_IndexUserButton1 + 3),

			_CountUserButtons = 4, 
			_IndexIcon1 = _IndexUserButton1 + _CountUserButtons, 

			IconDefault = FLAG(_IndexIcon1),

			IconInfo = FLAG(_IndexIcon1),
			IconQuest = FLAG(_IndexIcon1 + 1),
			IconError = FLAG(_IndexIcon1 + 2),
			IconWarning = FLAG(_IndexIcon1 + 3),

			Icon1 = FLAG(_IndexIcon1),
			Icon2 = FLAG(_IndexIcon1 + 1),
			Icon3 = FLAG(_IndexIcon1 + 2),
			Icon4 = FLAG(_IndexIcon1 + 3),
			Icon5 = FLAG(_IndexIcon1 + 4),
			Icon6 = FLAG(_IndexIcon1 + 5),
			Icon7 = FLAG(_IndexIcon1 + 6),
			Icon8 = FLAG(_IndexIcon1 + 7)
		};

		//@ExportToLua
		MessageBoxStyle(Enum value = None) : value(value) { }

		MessageBoxStyle& operator |= (MessageBoxStyle const& other) { value = Enum(int(value) | int(other.value)); return *this; }
		friend MessageBoxStyle operator | (Enum const& a, Enum const& b) { return MessageBoxStyle(Enum(int(a) | int(b))); }
		MessageBoxStyle operator | (Enum const& a) { return MessageBoxStyle(Enum(int(value) | int(a))); }

		friend bool operator == (MessageBoxStyle const& a, MessageBoxStyle const& b) { return a.value == b.value; }
		friend bool operator != (MessageBoxStyle const& a, MessageBoxStyle const& b) { return a.value != b.value; }

		friend std::ostream& operator << (std::ostream& stream, const MessageBoxStyle&  value)
		{
			//stream << value.Print();
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, MessageBoxStyle&  value)
		{
			std::string curValue;
			stream >> curValue;
			value = MessageBoxStyle::Parse(curValue);
			return stream;
		}

		//@ExportToLua
		size_t GetIconIndex()
		{
			size_t index = 0;
			int num = value >> _IndexIcon1;

			while (num != 0)
			{
				if ((num & 1) == 1) return index;

				++index;
				num >>= 1;
			}

			return ITEM_NONE;
		}

		//@ExportToLua
		size_t GetButtonIndex()
		{
			size_t index = 0;
			int num = value;

			while (num != 0)
			{
				if ((num & 1) == 1) return index;

				++index;
				num >>= 1;
			}

			return ITEM_NONE;
		}

		std::vector<MessageBoxStyle> GetButtons()
		{
			std::vector<MessageBoxStyle> buttons;

			size_t index = 0;
			int num = value;
			while (index < _IndexIcon1)
			{
				if ((num & 1) == 1)
				{
					buttons.push_back( MessageBoxStyle::Enum( FLAG(index) ) );
				}

				++index;
				num >>= 1;
			}

			return buttons;
		}

		typedef std::map<std::string, int> MapAlign;

		//@ExportToLua
		static MessageBoxStyle Parse(const std::string& value)
		{
			MessageBoxStyle result(MessageBoxStyle::Enum(0));
			const MapAlign& map_names = result.GetValueNames();
			const std::vector<std::string>& vec = utility::Split(value);
			for (size_t pos=0; pos<vec.size(); pos++)
			{
				MapAlign::const_iterator iter = map_names.find(vec[pos]);
				if (iter != map_names.end())
				{
					result.value = Enum(int(result.value) | int(iter->second));
				}
				else
				{
					LOG(warning, "Cannot parse type '" << vec[pos] << "'");
				}
			}
			return result;
		}

	private:
		const MapAlign& GetValueNames()
		{
			static MapAlign map_names;

			if (map_names.empty())
			{
				REGISTER_VALUE(map_names, None);
				REGISTER_VALUE(map_names, Ok);
				REGISTER_VALUE(map_names, Yes);
				REGISTER_VALUE(map_names, No);
				REGISTER_VALUE(map_names, Abort);
				REGISTER_VALUE(map_names, Retry);
				REGISTER_VALUE(map_names, Ignore);
				REGISTER_VALUE(map_names, Cancel);
				REGISTER_VALUE(map_names, Try);
				REGISTER_VALUE(map_names, Continue);

				REGISTER_VALUE(map_names, Button1);
				REGISTER_VALUE(map_names, Button2);
				REGISTER_VALUE(map_names, Button3);
				REGISTER_VALUE(map_names, Button4);

				REGISTER_VALUE(map_names, IconDefault);

				REGISTER_VALUE(map_names, IconInfo);
				REGISTER_VALUE(map_names, IconQuest);
				REGISTER_VALUE(map_names, IconError);
				REGISTER_VALUE(map_names, IconWarning);

				REGISTER_VALUE(map_names, Icon1);
				REGISTER_VALUE(map_names, Icon2);
				REGISTER_VALUE(map_names, Icon3);
				REGISTER_VALUE(map_names, Icon4);
				REGISTER_VALUE(map_names, Icon5);
				REGISTER_VALUE(map_names, Icon6);
				REGISTER_VALUE(map_names, Icon7);
				REGISTER_VALUE(map_names, Icon8);
			}

			return map_names;
		}

	private:
		Enum value;
	};

} // namespace GUI

#endif // __MESSAGE_BOX_STYLE_H__


