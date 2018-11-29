#ifndef __COLOUR_H__
#define __COLOUR_H__

#include "Prerequest.h"
#include "Types.h"

namespace GUI
{

	struct GUI_EXPORT Colour
	{
		//@ExportToLua
		float red, green, blue, alpha;

		//@ExportToLua
		static const Colour Zero;
		//@ExportToLua
		static const Colour Black;
		//@ExportToLua
		static const Colour White;
		//@ExportToLua
		static const Colour Red;
		//@ExportToLua
		static const Colour Green;
		//@ExportToLua
		static const Colour Blue;

		//@ExportToLua
		Colour() : red(1), green(1), blue(1), alpha(1) { }
		//@ExportToLua
		Colour(float red, float green, float blue, float alpha = 1) : red(red), green(green), blue(blue), alpha(alpha) { }
		//@ExportToLua
		explicit Colour(const std::string& value) { *this = Parse(value); }


		Colour& operator=(Colour const& value)
		{
			red = value.red;
			green = value.green;
			blue = value.blue;
			alpha = value.alpha;
			return *this;
		}

		//@ExportToLua
		bool operator==(Colour const& value) const
		{
			return ((red == value.red) && (green == value.green) && (blue == value.blue) && (alpha == value.alpha));
		}

		bool operator!=(Colour const& value) const
		{
			return ! (*this == value);
		}

		//@ExportToLua
		void Set(float red, float green, float blue, float alpha = 1)
		{
			this->red = red;
			this->green = green;
			this->blue = blue;
			this->alpha = alpha;
		}

		//@ExportToLua
		void Clear()
		{
			red = green = blue = alpha = 0;
		}

		//@ExportToLua
		std::string Print() const
		{
			std::ostringstream stream;
			stream << *this;
			return stream.str();
		}

		//@ExportToLua
		static Colour Parse(const std::string& value)
		{
			if (!value.empty())
			{
				if (value[0] == '#')
				{
					std::istringstream stream(value.substr(1));
					int result = 0;
					stream >> std::hex >> result;
					if (!stream.fail())
					{
						return Colour( (unsigned char)( result >> 16 ) / 256.0f, (unsigned char)( result >> 8 ) / 256.0f, (unsigned char)( result ) / 256.0f );
					}
				}
				else
				{
					float red, green, blue, alpha = 1;
					std::istringstream stream(value);
					stream >> red >> green >> blue;
					if (!stream.fail())
					{
						if (!stream.eof())
							stream >> alpha;
						return Colour(red, green, blue, alpha);
					}
				}
			}
			return Colour::Zero;
		}

		friend std::ostream& operator << (std::ostream& stream, const Colour&  value)
		{
			stream << value.red << " " << value.green << " " << value.blue << " " << value.alpha;
			return stream;
		}

		friend std::istream& operator >> (std::istream& stream, Colour&  value)
		{
			value.Clear();

			std::string curValue;
			stream >> curValue;

			if (curValue.empty())
				return stream;

			if (curValue[0] == '#')
			{
				value = Colour::Parse(curValue);
			}
			else
			{
				std::istringstream curStream(curValue);
				curStream >> value.red;
				if (curStream.fail())
					value.Clear();
				else
				{
					stream >> value.green >> value.blue;
					if (!stream.eof())
						stream >> value.alpha;
					else
						value.alpha = 1;

					if (stream.fail())
						value.Clear();
				}
			}

			return stream;
		}

	};

} // namespace GUI

#endif // __COLOUR_H__
