#ifndef __TRECT_H__
#define __TRECT_H__

#include "Prerequest.h"

namespace GUI
{
	namespace types
	{

		template< typename T > struct TRect
		{
			//@TOLUA_TEMPLATE_BIND(T,int,float)
			//@ExportToLua
			T left, top, right, bottom;

			//@ExportToLua
			TRect() : left(0), top(0), right(0), bottom(0) { }
			//@ExportToLua
			TRect(T const& left, T const& top, T const& right, T const& bottom) : left(left), top(top), right(right), bottom(bottom) { }
			//@ExportToLua
			TRect(TRect<T> const& o) : left(o.left), top(o.top), right(o.right), bottom(o.bottom) { }

			TRect& operator-=(TRect const& o)
			{
				left -= o.left;
				top -= o.top;
				right -= o.right;
				bottom -= o.bottom;
				return *this;
			}

			TRect& operator+=(TRect const& o)
			{
				left += o.left;
				top += o.top;
				right += o.right;
				bottom += o.bottom;
				return *this;
			}

			//@ExportToLua
			TRect<T> operator-(TRect<T> const& o) const
			{
				return TRect(left - o.left, top - o.top, right - o.right, bottom - o.bottom);
			}

			//@ExportToLua
			TRect<T> operator+(TRect<T> const& o) const
			{
				return TRect(left + o.left, top + o.top, right + o.right, bottom + o.bottom);
			}

			TRect& operator=(TRect const& o)
			{
				left = o.left;
				top = o.top;
				right = o.right;
				bottom = o.bottom;
				return *this;
			}

			template< typename U >
			TRect& operator=(TRect<U> const& o)
			{
				left = o.left;
				top = o.top;
				right = o.right;
				bottom = o.bottom;
				return *this;
			}

			//@ExportToLua
			bool operator==(TRect<T> const& o) const
			{
				return ((left == o.left) && (top == o.top) && (right == o.right) && (bottom == o.bottom));
			}

			bool operator!=(TRect const& o) const
			{
				return ! ((left == o.left) && (top == o.top) && (right == o.right) && (bottom == o.bottom));
			}

			//@ExportToLua
			T Width() const
			{
				return right - left;
			}

			//@ExportToLua
			T Height() const
			{
				return bottom - top;
			}

			//@ExportToLua
			void Clear()
			{
				left = top = right = bottom = 0;
			}

			//@ExportToLua
			void Set(T const& left, T const& top, T const& right, T const& bottom)
			{
				this->left = left;
				this->top = top;
				this->right = right;
				this->bottom = bottom;
			}

			//@ExportToLua
			void Swap(TRect<T>& value)
			{
				TRect tmp = value;
				value = *this;
				*this = tmp;
			}

			//@ExportToLua
			bool Empty() const
			{
				return ((left == 0) && (top == 0) && (right == 0) && (bottom == 0));
			}

			//@ExportToLua
			bool Inside(const TRect<T>&  value) const
			{
				return ((value.left >= left) && (value.right <= right) && (value.top >= top) && (value.bottom <= bottom));
			}

			//@ExportToLua
			bool Intersect(const TRect<T>&  value) const
			{
				return ((value.left <= right) && (value.right >= left) && (value.top <= bottom) && (value.bottom >= top));
			}

			//@ExportToLua
			bool Inside(const TPoint<T>&  value) const
			{
				return ((value.left >= left) && (value.left <= right) && (value.top >= top) && (value.top <= bottom));
			}

			//@ExportToLua
			std::string Print() const
			{
				std::ostringstream stream;
				stream << *this;
				return stream.str();
			}

			//@ExportToLua
			static TRect<T> Parse(const std::string& value)
			{
				TRect<T> result;
				std::istringstream stream(value);
				stream >> result.left >> result.top >> result.right >> result.bottom;
				if (stream.fail()) return TRect<T>();
				else
				{
					int item = stream.get();
					while (item != -1)
					{
						if (item != ' ' && item != '\t') return TRect<T>();
						item = stream.get();
					}
				}
				return result;
			}

			friend std::ostream& operator << (std::ostream& stream, const TRect<T>&  value)
			{
				stream << value.left << " " << value.top << " " << value.right << " " << value.bottom;
				return stream;
			}

			friend std::istream& operator >> (std::istream& stream, TRect<T>&  value)
			{
				stream >> value.left >> value.top >> value.right >> value.bottom;
				if (stream.fail()) value.Clear();
				return stream;
			}

		};

	} // namespace types
} // namespace GUI

#endif // __TRECT_H__
