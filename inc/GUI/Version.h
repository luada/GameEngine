#ifndef __VERSION_H__
#define __VERSION_H__

#include "Prerequest.h"
#include "Types.h"
#include "Utility.h"

namespace GUI
{

	class GUI_EXPORT Version
	{
	public:
		Version() : value(0) { }
		Version(uint8 major, uint8 minor, uint16 patch) : value((uint32(major) << 24) + (uint32(minor) << 16) + uint32(patch)) { }
		Version(uint8 major, uint8 minor) : value((uint32(major) << 24) + (uint32(minor) << 16)) { }
		explicit Version(const std::string& value) : value(Parse(value).value) { }

		friend bool operator < (Version const& a, Version const& b) { return a.GetPoorVersion() < b.GetPoorVersion(); }
		friend bool operator >= (Version const& a, Version const& b) { return !(a < b); }
		friend bool operator > (Version const& a, Version const& b) { return (b < a); }
		friend bool operator <= (Version const& a, Version const& b) { return !(a > b); }

		friend bool operator == (Version const& a, Version const& b) { return !(a < b) && !(a > b); }
		friend bool operator != (Version const& a, Version const& b) { return !(a == b); }

		friend std::ostream& operator << (std::ostream& stream, const Version&  value)
		{
			stream << value.Print();
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, Version&  value)
		{
			std::string curValue;
			stream >> curValue;
			value = Version::Parse(curValue);
			return stream;
		}

		uint8 GetMajor() const { return uint8((value & 0xFF000000) >> 24); }
		uint8 GetMinor() const { return uint8((value & 0x00FF0000) >> 16); }
		uint16 GetPatch() const { return uint16(value & 0x0000FFFF); }

		uint32 GetPoorVersion() const { return value & 0xFFFF0000; }
		uint32 GetFullVersion() const { return value; }

		std::string Print() const
		{
			if (GetPatch() == 0) return utility::ToString(GetMajor(), ".", GetMinor());
			return utility::ToString(GetMajor(), ".", GetMinor(), ".", GetPatch());
		}

		static Version Parse(const std::string& value)
		{
			const std::vector<std::string>& vec = utility::Split(value, ".");
			if (vec.empty()) return Version();
			uint8 major = (uint8)utility::ParseValue<int>(vec[0]);
			uint8 minor = vec.size() > 1 ? (uint8)utility::ParseValue<int>(vec[1]) : uint8(0);
			uint16 patch = vec.size() > 2 ? (uint16)utility::ParseValue<int>(vec[2]) : uint16(0);
			return Version(major, minor, patch);
		}

	private:
		union
		{
			uint32 value;
			uint8 value_data[4];
		};
	};

} // namespace GUI

#endif // __VERSION_H__
