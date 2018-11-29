#include "Precompiled.h"
#include "Guid.h"
#if   PLATFORM == PLATFORM_LINUX || PLATFORM == PLATFORM_APPLE
#include <uuid/uuid.h>
#elif PLATFORM == PLATFORM_WIN32
#include <objbase.h>
#endif

namespace GUI
{
	const char Guid::convert_hex[64] = { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 64, 64, 64, 64, 64, 64,
										64, 10, 11, 12, 13, 14, 15, 64, 64, 64, 64, 64, 64, 64, 64, 64,
										64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
										64, 10, 11, 12, 13, 14, 15, 64, 64, 64, 64, 64, 64, 64, 64, 64
	                                   };

	Guid Guid::Parse(const std::string& value)
	{
		Guid ret;
		size_t start=0;
		if (value.size() == 38)
		{
			start ++;
#if DEBUG_MODE == 1
			if ((value[0] != '{') || (value[37] != '}'))
			{
				return ret;
			}
#endif
		}
		else if (value.size() != 36)
		{
			return ret;
		}

#if DEBUG_MODE == 1
		if ((value[start + 8] != '-') || (value[start + 13] != '-') || (value[start + 18] != '-') || (value[start + 23] != '-'))
		{
			return ret;
		}
#endif

#define CONVERT_HEX(curValue) ((convert_hex[ ((curValue) - 48) & 0x3F]) & 0x3F)

#if DEBUG_MODE == 1
	#define CHECK_CONVERT_HEX(curValue) \
		{ \
			char tmp = ((curValue) - 48); \
			if ((tmp > 63) || (tmp < 0)) \
			{ \
				/*LOG(Error, "error parse guid'" << value << "'");*/ \
				return Guid(); \
			} \
			tmp = convert_hex[(int)tmp]; \
			if (tmp > 63) \
			{ \
				/*LOG(Error, "error parse guid'" << value << "'");*/ \
				return Guid(); \
			} \
		}
#else
	#define CHECK_CONVERT_HEX(curValue)
#endif


		size_t count = 8;
		size_t pos = start;
		while (count > 0)
		{
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data1 <<= 4;
			ret.original.data1 += CONVERT_HEX(value[pos]);
			count --;
			pos ++;
		}

		count = 4;
		pos ++;
		while (count > 0)
		{
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data2 <<= 4;
			ret.original.data2 += CONVERT_HEX(value[pos]);
			count --;
			pos ++;
		}

		count = 4;
		pos ++;
		while (count > 0)
		{
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data3 <<= 4;
			ret.original.data3 += CONVERT_HEX(value[pos]);
			count --;
			pos ++;
		}

		count = 2; 
		pos ++;
		size_t num = 0;
		while (count > 0)
		{
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data4[num] = CONVERT_HEX(value[pos++]) << 4;
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data4[num++] += CONVERT_HEX(value[pos++]);
			count --;
		}

		count = 6; 
		pos ++;
		while (count > 0)
		{
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data4[num] = CONVERT_HEX(value[pos++]) << 4;
			CHECK_CONVERT_HEX(value[pos]);
			ret.original.data4[num++] += CONVERT_HEX(value[pos++]);
			count --;
		}

#undef CHECK_CONVERT_HEX
#undef CONVERT_HEX

	    return ret;
	}

	std::string Guid::Print() const
	{
		const size_t SIZE = 39;
		char buff[SIZE];

		sprintf(buff, "{%.8X-%.4X-%.4X-%.2X%.2X-%.2X%.2X%.2X%.2X%.2X%.2X}", (int)(original.data1), (int)(original.data2), (int)(original.data3),
			(int)(original.data4[0]), (int)(original.data4[1]),
			(int)(original.data4[2]), (int)(original.data4[3]), (int)(original.data4[4]), (int)(original.data4[5]), (int)(original.data4[6]), (int)(original.data4[7]));

		return buff;
	}

	Guid Guid::Generate()
	{
		Guid ret;
#if PLATFORM == PLATFORM_WIN32
		HRESULT result = CoCreateGuid((GUID*)&ret.original.data1);
		ASSERT(S_OK == result, "Error generate GUID");
#elif PLATFORM == PLATFORM_LINUX
		Uuid_generate(ret.vec._data1);
#else
		//FIXME
		Uuid_generate(ret.vec._data1);// or what else?
#endif
		return ret;
	}

} // namespace GUI


