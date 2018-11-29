#ifndef __TCOORD_H__
#define __TCOORD_H__

#include "Prerequest.h"
#include "TPoint.h"
#include "TSize.h"

namespace GUI
{
	namespace types
	{

		template< typename T > struct TCoord
		{
			//@TOLUA_TEMPLATE_BIND(T,int,float)
			//@ExportToLua
			T left, top, width, height;

			//@ExportToLua
			TCoord() : left(0), top(0), width(0), height(0) { }
			//@ExportToLua
			TCoord(T const& left, T const& top, T const& width, T const& height) : left(left), top(top), width(width), height(height) { }
			//@ExportToLua
			TCoord(TCoord<T> const& obj) : left(obj.left), top(obj.top), width(obj.width), height(obj.height) { }
			//@ExportToLua
			TCoord(TPoint<T> const& point, TSize<T> const& size) : left(point.left), top(point.top), width(size.width), height(size.height) { }

			TCoord& operator-=(TCoord const& obj)
			{
				left -= obj.left;
				top -= obj.top;
				width -= obj.width;
				height -= obj.height;
				return *this;
			}

			TCoord& operator+=(TCoord const& obj)
			{
				left += obj.left;
				top += obj.top;
				width += obj.width;
				height += obj.height;
				return *this;
			}

			//@ExportToLua
			TCoord<T> operator-(TCoord<T> const& obj) const
			{
				return TCoord(left - obj.left, top - obj.top, width - obj.width, height - obj.height);
			}

			//@ExportToLua
			TCoord<T> operator-(TPoint<T> const& obj) const
			{
				return TCoord(left - obj.left, top - obj.top, width, height);
			}

			//@ExportToLua
			TCoord<T> operator-(TSize<T> const& obj) const
			{
				return TCoord(left, top, width - obj.width, height - obj.height);
			}

			//@ExportToLua
			TCoord<T> operator+(TCoord<T> const& obj) const
			{
				return TCoord(left + obj.left, top + obj.top, width + obj.width, height + obj.height);
			}

			//@ExportToLua
			TCoord<T> operator+(TPoint<T> const& obj) const
			{
				return TCoord(left + obj.left, top + obj.top, width, height);
			}

			//@ExportToLua
			TCoord<T> operator+(TSize<T> const& obj) const
			{
				return TCoord(left, top, width + obj.width, height + obj.height);
			}

			TCoord& operator=(TCoord const& obj)
			{
				left = obj.left;
				top = obj.top;
				width = obj.width;
				height = obj.height;
				return *this;
			}

			template< typename U >
			TCoord& operator=(TCoord<U> const& obj)
			{
				left = obj.left;
				top = obj.top;
				width = obj.width;
				height = obj.height;
				return *this;
			}

			TCoord& operator=(TPoint<T> const& obj)
			{
				left = obj.left;
				top = obj.top;
				return *this;
			}

			TCoord& operator=(TSize<T> const& obj)
			{
				width = obj.width;
				height = obj.height;
				return *this;
			}

			//@ExportToLua
			bool operator==(TCoord<T> const& obj) const
			{
				return ((left == obj.left) && (top == obj.top) && (width == obj.width) && (height == obj.height));
			}

			bool operator!=(TCoord const& obj) const
			{
				return ! ((left == obj.left) && (top == obj.top) && (width == obj.width) && (height == obj.height));
			}

			//@ExportToLua
			T Right() const
			{
				return left + width;
			}

			//@ExportToLua
			T Bottom() const
			{
				return top + height;
			}

			//@ExportToLua
			void Clear()
			{
				left = top = width = height = 0;
			}

			//@ExportToLua
			void Set(T const& left, T const& top, T const& width, T const& height)
			{
				this->left = left;
				this->top = top;
				this->width = width;
				this->height = height;
			}

			//@ExportToLua
			void Swap(TCoord<T>& value)
			{
				TCoord tmp = value;
				value = *this;
				*this = tmp;
			}

			//@ExportToLua
			bool Empty() const
			{
				return ((left == 0) && (top == 0) && (width == 0) && (height == 0));
			}

			//@ExportToLua
			TPoint<T> Point() const
			{
				return TPoint<T>(left, top);
			}

			//@ExportToLua
			TSize<T> Size() const
			{
				return TSize<T>(width, height);
			}

			//@ExportToLua
			bool Inside(const TPoint<T>&  value) const
			{
				return ((value.left >= left) && (value.left <= Right()) && (value.top >= top) && (value.top <= Bottom()));
			}

			//@ExportToLua
			std::string Print() const
			{
				std::ostringstream stream;
				stream << *this;
				return stream.str();
			}

			//@ExportToLua
			static TCoord<T> Parse(const std::string& value)
			{
				TCoord<T> result;
				std::istringstream stream(value);
				stream >> result.left >> result.top >> result.width >> result.height;
				if (stream.fail()) return TCoord<T>();
				else
				{
					int item = stream.get();
					while (item != -1)
					{
						if (item != ' ' && item != '\t') return TCoord<T>();
						item = stream.get();
					}
				}
				return result;
			}

			friend std::ostream& operator << (std::ostream& stream, const TCoord<T>&  value)
			{
				stream << value.left << " " << value.top << " " << value.width << " " << value.height;
				return stream;
			}

			friend std::istream& operator >> (std::istream& stream, TCoord<T>&  value)
			{
				stream >> value.left >> value.top >> value.width >> value.height;
				if (stream.fail()) value.Clear();
				return stream;
			}

		};

	} // namespace types
} // namespace GUI

#endif // __TCOORD_H__
