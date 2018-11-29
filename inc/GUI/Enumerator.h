#ifndef __ENUMERATOR_H__
#define __ENUMERATOR_H__

#include <assert.h>

namespace GUI
{

	/** Class for comfortable using of vectors with small while loop
	instead iterators. Performance is same as with iterators.
	Enumerator usage
	@example Enumerator
	@code
		typedef std::vector<std::string> VectorString;
		typedef Enumerator<VectorString> EnumeratorVectorString;

		VectorString vec;
		vec.push_back("value");
		//EnumeratorVectorString Enum_vec(vec.begin(), vec.end());
		EnumeratorVectorString Enum_vec(vec);
		while (enum_vec.Next())
		{
			std::string value = enum_vec.Current();
		}

		typedef std::pair<std::string, std::string> PairString;
		typedef std::map<PairString> MapString;

		MapString map;
		map["key"] = "value";
		//EnumeratorMapString Enum_map(map.begin(), map.end());
		EnumeratorMapString Enum_map(map);
		while (enum_map.Next())
		{
			std::string key = enum_map.Current().first;
			std::string value = enum_map.Current().second;
		}
	@endcode
	*/

	template<typename T>
	class Enumerator
	{
	private:
		Enumerator() { }

	public:
		explicit Enumerator(const T& container) :
			m_first(true),
			m_current(container.begin()),
			m_end(container.end())
		{
		}

		Enumerator(typename T::const_iterator first, typename T::const_iterator end) :
			m_first(true),
			m_current(first),
			m_end(end)
		{
		}

		bool Next()
		{
			if (m_current == m_end) return false;
			else if (m_first)
			{
				m_first = false;
				return true;
			}
			++ m_current;
			if (m_current == m_end) return false;
			return true;
		}

		typename T::const_reference operator->() const { assert(m_current != m_end); return (*m_current); }
		typename T::const_reference Current() { assert(m_current != m_end); return (*m_current); }

	private:
		bool m_first;
		typename T::const_iterator m_current;
		typename T::const_iterator m_end;
	};

} // namespace GUI

#endif // __ENUMERATOR_H__
