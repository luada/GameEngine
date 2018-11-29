#ifndef __TSIZE_H__
#define __TSIZE_H__

#include "Prerequest.h"

namespace GUI
{
	namespace types
	{

		template< typename T > struct TSize
		{
			//@TOLUA_TEMPLATE_BIND(T,int,float)
			//@ExportToLua
			T width, height;

			//@ExportToLua
			TSize() : width(0), height(0) { }
			//@ExportToLua
			TSize(T const& w, T const& h) : width(w), height(h) { }
			//@ExportToLua
			TSize(TSize<T> const& o) : width(o.width), height(o.height) { }

			TSize& operator-=(TSize const& o)
			{
				width -= o.width;
				height -= o.height;
				return *this;
			}

			TSize& operator+=(TSize const& o)
			{
				width += o.width;
				height += o.height;
				return *this;
			}

			//@ExportToLua
			TSize<T> operator-(TSize<T> const& o) const
			{
				return TSize(width - o.width, height - o.height);
			}

			//@ExportToLua
			TSize<T> operator+(TSize<T> const& o) const
			{
				return TSize(width + o.width, height + o.height);
			}

			TSize& operator=(TSize const& o)
			{
				width = o.width;
				height = o.height;
				return *this;
			}

			template< typename U >
			TSize& operator=(TSize<U> const& o)
			{
				width = o.width;
				height = o.height;
				return *this;
			}

			//@ExportToLua
			bool operator==(TSize<T> const& o) const
			{
				return ((width == o.width) && (height == o.height));
			}

			bool operator!=(TSize const& o) const
			{
				return ! ((width == o.width) && (height == o.height));
			}

			//@ExportToLua
			void Clear()
			{
				width = height = 0;
			}

			//@ExportToLua
			void Set(T const& w, T const& h)
			{
				width = w;
				height = h;
			}

			//@ExportToLua
			void Swap(TSize<T>& value)
			{
				TSize tmp = value;
				value = *this;
				*this = tmp;
			}

			//@ExportToLua
			bool Empty() const
			{
				return ((width == 0) && (height == 0));
			}

			//@ExportToLua
			std::string Print() const
			{
				std::ostringstream stream;
				stream << *this;
				return stream.str();
			}

			//@ExportToLua
			static TSize<T> Parse(const std::string& value)
			{
				TSize<T> result;
				std::istringstream stream(value);
				stream >> result.width >> result.height;
				if (stream.fail()) return TSize<T>();
				else
				{
					int item = stream.get();
					while (item != -1)
					{
						if (item != ' ' && item != '\t') return TSize<T>();
						item = stream.get();
					}
				}
				return result;
			}

			friend std::ostream& operator << (std::ostream& stream, const TSize<T>&  value)
			{
				stream << value.width << " " << value.height;
				return stream;
			}

			friend std::istream& operator >> (std::istream& stream, TSize<T>&  value)
			{
				stream >> value.width >> value.height;
				if (stream.fail()) value.Clear();
				return stream;
			}

		};

	} // namespace types
} // namespace GUI

#endif // __TSIZE_H__
