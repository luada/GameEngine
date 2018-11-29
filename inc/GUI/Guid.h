#ifndef __GUID_H__
#define __GUID_H__

#include "Prerequest.h"
#include "Types.h"
#include <memory.h>

namespace GUI
{

	class GUI_EXPORT Guid
	{
	public:
		Guid() { fast._data1 = fast._data2 = fast._data3 = fast._data4 = 0; }
		Guid(Guid const& value) { *this = value; }
		explicit Guid(const std::string& value) { *this = Parse(value); }
		explicit Guid(unsigned char(&_id)[16]) { ::memcpy((void*)&vec._data1[0], (void*)&_id[0], 16); }

		bool operator == (Guid const& comp) const
		{
			return comp.fast._data1 == fast._data1
				&& comp.fast._data2 == fast._data2
				&& comp.fast._data3 == fast._data3
				&& comp.fast._data4 == fast._data4;
		}

		bool operator != (Guid const& comp) const
		{
			return ! (*this == comp);
		}

		bool operator < (Guid const& comp) const
		{
			if (comp.fast._data1 < fast._data1) return true;
			else if (comp.fast._data1 > fast._data1) return false;
			if (comp.fast._data2 < fast._data2) return true;
			else if (comp.fast._data2 > fast._data2) return false;
			if (comp.fast._data3 < fast._data3) return true;
			else if (comp.fast._data3 > fast._data3) return false;
			if (comp.fast._data4 < fast._data4) return true;
			return false;
		}

		Guid& operator = (Guid const& rvalue)
		{
			fast._data1 = rvalue.fast._data1;
			fast._data2 = rvalue.fast._data2;
			fast._data3 = rvalue.fast._data3;
			fast._data4 = rvalue.fast._data4;
			return *this;
		}

		bool empty() const
		{
			return fast._data1 == 0
				&& fast._data2 == 0
				&& fast._data3 == 0
				&& fast._data4 == 0;
		}

		void Clear()
		{
			fast._data1 = fast._data2 = fast._data3 = fast._data4 = 0;
		}

		std::string Print() const;
		static Guid Parse(const std::string& value);
		static Guid Generate();

		friend std::ostream& operator << (std::ostream& stream, const Guid&  value)
		{
			stream << value.Print();
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, Guid&  value)
		{
			std::string curValue;
			stream >> curValue;
			if (stream.fail()) value.Clear();
			else value = Guid::Parse(curValue);
			return stream;
		}

	private:
		static const char convert_hex[64];

		struct _original
		{
			uint32 data1;
			uint16 data2, data3;
			uint8 data4[8];
		};
		struct _fast
		{
			uint32 _data1, _data2, _data3, _data4;
		};
		struct _vec
		{
			unsigned char _data1[16];
		};

		union
		{
			_original original;
			_fast fast;
			_vec vec;
		};

	};

} // namespace GUI

#endif // __GUID_H__

