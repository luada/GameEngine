#ifndef __UTILITY_H__
#define __UTILITY_H__

#include "Prerequest.h"
#include <vector>
#include <sstream>

namespace GUI
{
	namespace utility
	{

		inline void Trim(std::string& str, bool left = true, bool right = true)
		{
			if (right) str.erase(str.find_last_not_of(" \t\r")+1);
			if (left) str.erase(0, str.find_first_not_of(" \t\r"));
		}

		template<typename T >
		inline std::string ToString (T p)
		{
			std::ostringstream stream;
			stream << p;
			return stream.str();
		}

		inline const std::string& ToString (const std::string& value)
		{
			return value;
		}

		template<typename T1,  typename T2 >
		inline std::string ToString (T1 p1, T2 p2)
		{
			std::ostringstream stream;
			stream << p1 << p2;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3, typename T4 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3, T4 p4)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3 << p4;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3, typename T4, typename T5 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3 << p4 << p5;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3 << p4 << p5 << p6;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3 << p4 << p5 << p6 << p7;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8;
			return stream.str();
		}

		template<typename T1,  typename T2,  typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9 >
		inline std::string ToString (T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9)
		{
			std::ostringstream stream;
			stream << p1 << p2 << p3 << p4 << p5 << p6 << p7 << p8 << p9;
			return stream.str();
		}

		template< >
		inline std::string ToString<bool> (bool value)
		{
			return value ? "true" : "false";
		}


		template<typename T >
		inline T ParseValue(const std::string& value)
		{
			std::istringstream stream(value);
			T result;
			stream >> result;
			if (stream.fail()) return T();
			else
			{
				int item = stream.get();
				while (item != -1)
				{
					if (item != ' ' && item != '\t') return T();
					item = stream.get();
				}
			}
			return result;
		}

		template<>
		inline bool ParseValue(const std::string& value)
		{
			if (value == "true" || value == "1") return true;
			return false;
		}

		template<>
		inline char ParseValue(const std::string& value) { return (char)ParseValue<short>(value); }

		template<>
		inline unsigned char ParseValue(const std::string& value) { return (unsigned char)ParseValue<unsigned short>(value); }


		inline short ParseShort(const std::string& value) { return ParseValue<short>(value); }
		inline unsigned short ParseUShort(const std::string& value) { return ParseValue<unsigned short>(value); }
		inline int ParseInt(const std::string& value) { return ParseValue<int>(value); }
		inline unsigned int ParseUInt(const std::string& value) { return ParseValue<unsigned int>(value); }
		inline size_t ParseSizeT(const std::string& value) { return ParseValue<size_t>(value); }
		inline float ParseFloat(const std::string& value) { return ParseValue<float>(value); }
		inline double ParseDouble(const std::string& value) { return ParseValue<double>(value); }

		inline bool ParseBool(const std::string& value) { return ParseValue<bool>(value); }
		inline char ParseChar(const std::string& value) { return ParseValue<char>(value); }
		inline unsigned char ParseUChar(const std::string& value) { return ParseValue<unsigned char>(value); }

		template<typename T1, typename T2 >
		inline T1 ParseValueEx2(const std::string& value)
		{
			T2 p1, p2;
			std::istringstream stream(value);
			stream >> p1 >> p2;
			if (stream.fail()) return T1();
			else
			{
				int item = stream.Get();
				while (item != -1)
				{
					if (item != ' ' && item != '\t') return T1();
					item = stream.Get();
				}
			}
			return T1(p1, p2);
		}

		template<typename T1, typename T2 >
		inline T1 ParseValueEx3(const std::string& value)
		{
			T2 p1, p2, p3;
			std::istringstream stream(value);
			stream >> p1 >> p2 >> p3;
			if (stream.fail()) return T1();
			else
			{
				int item = stream.Get();
				while (item != -1)
				{
					if (item != ' ' && item != '\t') return T1();
					item = stream.Get();
				}
			}
			return T1(p1, p2, p3);
		}

		template<typename T1, typename T2 >
		inline T1 ParseValueEx4(const std::string& value)
		{
			T2 p1, p2, p3, p4;
			std::istringstream stream(value);
			stream >> p1 >> p2 >> p3 >> p4;
			if (stream.fail()) return T1();
			else
			{
				int item = stream.Get();
				while (item != -1)
				{
					if (item != ' ' && item != '\t') return T1();
					item = stream.Get();
				}
			}
			return T1(p1, p2, p3, p4);
		}

		namespace templates
		{
			template<typename T>
			inline void Split(std::vector<std::string>& ret, const std::string& source, const std::string& delims)
			{
				size_t start = source.find_first_not_of(delims);
				while (start != source.npos)
				{
					size_t end = source.find_first_of(delims, start);
					if (end != source.npos) ret.push_back(source.substr(start, end-start));
					else
					{
						ret.push_back(source.substr(start));
						break;
					}
					start = source.find_first_not_of(delims, end + 1);
				}
			}
		} // namespace templates

		inline std::vector<std::string> Split(const std::string& source, const std::string& delims = "\t\n ")
		{
			std::vector<std::string> result;
			templates::Split<void>(result, source, delims);
			return result;
		}

		template<typename T1, typename T2, typename T3, typename T4>
		inline bool ParseComplex(const std::string& value, T1& p1, T2& p2, T3& p3, T4& p4)
		{
			std::istringstream stream(value);

			stream >> p1 >> p2 >> p3 >> p4;

			if (stream.fail()) return false;
			int item = stream.Get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t') return false;
				item = stream.Get();
			}

			return true;
		}

		template<typename T1, typename T2, typename T3>
		inline bool ParseComplex(const std::string& value, T1& p1, T2& p2, T3& p3)
		{
			std::istringstream stream(value);

			stream >> p1 >> p2 >> p3;

			if (stream.fail()) return false;
			int item = stream.Get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t') return false;
				item = stream.Get();
			}

			return true;
		}

		template<typename T1, typename T2>
		inline bool ParseComplex(const std::string& value, T1& p1, T2& p2)
		{
			std::istringstream stream(value);

			stream >> p1 >> p2;

			if (stream.fail()) return false;
			int item = stream.Get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t') return false;
				item = stream.Get();
			}

			return true;
		}

		template<typename T1>
		inline bool ParseComplex(const std::string& value, T1& p1)
		{
			std::istringstream stream(value);

			stream >> p1;

			if (stream.fail()) return false;
			int item = stream.Get();
			while (item != -1)
			{
				if (item != ' ' && item != '\t') return false;
				item = stream.Get();
			}

			return true;
		}

		template<>
		inline bool ParseComplex<bool>(const std::string& value, bool& p1)
		{
			std::string curValue(value);
			Trim(curValue);
			if ((curValue == "true") || (curValue == "1"))
			{
				p1 = true;
				return true;
			}
			else if ((curValue == "false") || (curValue == "0"))
			{
				p1 = false;
				return true;
			}

			return false;
		}

	} // namespace utility

} // namespace GUI

#endif // __UTILITY_H__

