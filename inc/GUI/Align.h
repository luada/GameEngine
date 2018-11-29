#ifndef __ALIGN_H__
#define __ALIGN_H__

#include "Prerequest.h"
#include "Macros.h"
#include "Diagnostic.h"
#include "Utility.h"
#include <map>
#include <vector>

namespace GUI
{

	struct GUI_EXPORT Align
	{
		//@ExportToLua
		enum Enum
		{
			HCenter = FLAG_NONE, /**< center horizontally */
			VCenter = FLAG_NONE, /**< center vertically */
			Center = HCenter | VCenter, /**< center in the dead center */

			Left = FLAG(1), /**< value from the Left (and center vertically) */
			Right = FLAG(2), /**< value from the Right (and center vertically) */
			HStretch = Left | Right, /**< stretch horizontally proportionate to parent Window (and center vertically) */

			Top = FLAG(3), /**< value from the Top (and center horizontally) */
			Bottom = FLAG(4), /**< value from the Bottom (and center horizontally) */
			VStretch = Top | Bottom, /**< stretch vertically proportionate to parent Window (and center horizontally) */

			Stretch = HStretch | VStretch, /**< stretch proportionate to parent window */
			Default = Left | Top, /**< default Value (value from left and top) */

			HRelative = FLAG(5),
			VRelative = FLAG(6),
			Relative = HRelative | VRelative
		};

		//@ExportToLua
		Align(Enum value = Default) : value(value) { }

		//@ExportToLua
		bool IsHCenter() const { return HCenter == (value & ((int)HStretch | (int)HRelative)); }

		//@ExportToLua
		bool IsVCenter() const { return VCenter == (value & ((int)VStretch | (int)VRelative)); }

		//@ExportToLua
		bool IsCenter() const { return Center == (value & ((int)Stretch | (int)Relative)); }

		//@ExportToLua
		bool IsLeft() const { return Left == (value & ((int)HStretch | (int)HRelative)); }

		//@ExportToLua
		bool IsRight() const { return Right == (value & ((int)HStretch | (int)HRelative)); }

		//@ExportToLua
		bool IsHStretch() const { return HStretch == (value & ((int)HStretch | (int)HRelative)); }

		//@ExportToLua
		bool IsTop() const { return Top == (value & ((int)VStretch | (int)VRelative)); }

		//@ExportToLua
		bool IsBottom() const { return (Bottom == (value & ((int)VStretch | (int)VRelative))); }

		//@ExportToLua
		bool IsVStretch() const { return (VStretch == (value & ((int)VStretch | (int)VRelative))); }

		//@ExportToLua
		bool IsStretch() const { return (Stretch == (value & ((int)Stretch | (int)Relative))); }

		//@ExportToLua
		bool IsDefault() const { return (Default == (value & ((int)Stretch | (int)Relative))); }

		//@ExportToLua
		bool IsHRelative() const { return HRelative == (value & (int)HRelative); }

		//@ExportToLua
		bool IsVRelative() const { return VRelative == (value & (int)VRelative); }

		//@ExportToLua
		bool IsRelative() const { return Relative == (value & (int)Relative); }

		Align& operator |= (Align const& other) { value = Enum(int(value) | int(other.value)); return *this; }
		friend Align operator | (Enum const& a, Enum const& b) { return Align(Enum(int(a) | int(b))); }
		friend Align operator | (Align const& a, Align const& b) { return Align(Enum(int(a.value) | int(b.value))); }

		friend bool operator == (Align const& a, Align const& b) { return a.value == b.value; }
		friend bool operator != (Align const& a, Align const& b) { return a.value != b.value; }

		typedef std::map<std::string, int> MapAlign;

		//@ExportToLua
		static Align Parse(const std::string& value)
		{
			Align result(Enum(0));
			const MapAlign& map_names = result.GetValueNames();
			const std::vector<std::string>& vec = utility::Split(value);
			for (size_t pos=0; pos<vec.size(); pos++)
			{
				MapAlign::const_iterator iter = map_names.find(vec[pos]);
				if (iter != map_names.end())
				{
					result.value = Enum(int(result.value) | int(iter->second));
				}
			}
			return result;
		}

		//@ExportToLua
		std::string Print() const
		{
			std::string result;

			if (value & Left)
			{
				if (value & Right) result = "HStretch";
				else result = "Left";
			}
			else if (value & Right) result = "Right";
			else result = "HCenter";

			if (value & Top)
			{
				if (value & Bottom) result += " VStretch";
				else result += " Top";
			}
			else if (value & Bottom) result += " Bottom";
			else result += " VCenter";

			return result;
		}

		friend std::ostream& operator << (std::ostream& stream, const Align&  value)
		{
			stream << value.Print();
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, Align&  value)
		{
			value.value = Enum(0);
			std::string curValue;
			stream >> curValue;

			const MapAlign& map_names = value.GetValueNames();
			MapAlign::const_iterator iter = map_names.find(curValue);
			if (iter != map_names.end())
				value.value = Enum(int(value.value) | int(iter->second));


			if (!stream.eof())
			{
				std::string value2;
				stream >> value2;
				iter = map_names.find(value2);
				if (iter != map_names.end())
					value.value = Enum(int(value.value) | int(iter->second));
			}

			return stream;
		}

	private:
		const MapAlign& GetValueNames() const
		{
			static MapAlign map_names;

			if (map_names.empty())
			{
				// OBSOLETE
				map_names["ALIGN_HCENTER"] = HCenter;
				map_names["ALIGN_VCENTER"] = VCenter;
				map_names["ALIGN_CENTER"] = Center;
				map_names["ALIGN_LEFT"] = Left;
				map_names["ALIGN_RIGHT"] = Right;
				map_names["ALIGN_HSTRETCH"] = HStretch;
				map_names["ALIGN_TOP"] = Top;
				map_names["ALIGN_BOTTOM"] = Bottom;
				map_names["ALIGN_VSTRETCH"] = VStretch;
				map_names["ALIGN_STRETCH"] = Stretch;
				map_names["ALIGN_DEFAULT"] = Default;

				REGISTER_VALUE(map_names, HCenter);
				REGISTER_VALUE(map_names, VCenter);
				REGISTER_VALUE(map_names, Center);
				REGISTER_VALUE(map_names, Left);
				REGISTER_VALUE(map_names, Right);
				REGISTER_VALUE(map_names, HStretch);
				REGISTER_VALUE(map_names, Top);
				REGISTER_VALUE(map_names, Bottom);
				REGISTER_VALUE(map_names, VStretch);
				REGISTER_VALUE(map_names, Stretch);
				REGISTER_VALUE(map_names, Default);
				REGISTER_VALUE(map_names, HRelative);
				REGISTER_VALUE(map_names, VRelative);
				REGISTER_VALUE(map_names, Relative);
			}

			return map_names;
		}

	private:
		Enum value;
	};

} // namespace GUI

#endif // __ALIGN_H__
