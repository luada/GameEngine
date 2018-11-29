#ifndef __TPONT_H__
#define __TPONT_H__

#include "Prerequest.h"

namespace GUI
{
	namespace types
	{
		template< typename T > struct TPoint
		{
			//@TOLUA_TEMPLATE_BIND(T,int,float)
			//@ExportToLua
			T left, top;

			//@ExportToLua
			TPoint() : left(0), top(0) { }
			//@ExportToLua
			TPoint(T const& left, T const& top) : left(left), top(top) { }
			//@ExportToLua
			TPoint(TPoint<T> const& o) : left(o.left), top(o.top) { }

			TPoint& operator-=(TPoint const& o)
			{
				left -= o.left;
				top -= o.top;
				return *this;
			}

			TPoint& operator+=(TPoint const& o)
			{
				left += o.left;
				top += o.top;
				return *this;
			}

			//@ExportToLua
			TPoint<T> operator-(TPoint<T> const& o) const
			{
				return TPoint(left - o.left, top - o.top);
			}

			//@ExportToLua
			TPoint<T> operator+(TPoint<T> const& o) const
			{
				return TPoint(left + o.left, top + o.top);
			}

			TPoint& operator=(TPoint const& o)
			{
				left = o.left;
				top = o.top;
				return *this;
			}

			template< typename U >
			TPoint& operator=(TPoint<U> const& o)
			{
				left = o.left;
				top = o.top;
				return *this;
			}

			//@ExportToLua
			bool operator==(TPoint<T> const& o) const
			{
				return ((left == o.left) && (top == o.top));
			}

			bool operator!=(TPoint const& o) const
			{
				return ! ((left == o.left) && (top == o.top));
			}

			//@ExportToLua
			void Clear()
			{
				left = top = 0;
			}

			//@ExportToLua
			void Set(T const& left, T const& top)
			{
				this->left = left;
				this->top = top;
			}

			//@ExportToLua
			void Swap(TPoint<T>& value)
			{
				TPoint tmp = value;
				value = *this;
				*this = tmp;
			}

			//@ExportToLua
			bool Empty() const
			{
				return ((left == 0) && (top == 0));
			}

			//@ExportToLua
			std::string Print() const
			{
				std::ostringstream stream;
				stream << *this;
				return stream.str();
			}

			//@ExportToLua
			static TPoint<T> Parse(const std::string& value)
			{
				TPoint<T> result;
				std::istringstream stream(value);
				stream >> result.left >> result.top;
				if (stream.fail()) return TPoint<T>();
				else
				{
					int item = stream.get();
					while (item != -1)
					{
						if (item != ' ' && item != '\t') return TPoint<T>();
						item = stream.get();
					}
				}
				return result;
			}

			friend std::ostream& operator << (std::ostream& stream, const TPoint<T>&  value)
			{
				stream << value.left << " " << value.top;
				return stream;
			}

			friend std::istream& operator >> (std::istream& stream, TPoint<T>&  value)
			{
				stream >> value.left >> value.top;
				if (stream.fail()) value.Clear();
				return stream;
			}

		};

	} // namespace types
} // namespace GUI

#endif // __TPONT_H__
