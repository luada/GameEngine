#ifndef __FONT_DATA_H__
#define __FONT_DATA_H__

#include "Prerequest.h"

namespace GUI
{

	struct GUI_EXPORT FontCodeType
	{
		enum Enum
		{
			Selected = 6,
			SelectedBack = 7,
			Cursor = 8,
			Tab = 9,
			LF = 0x000A,
			CR = 0x000D,
			Space = 0x0020,
			LatinStart = 0x0021,
			NEL = 0x0085,
			LatinEnd = 0x00A6,
			MAX
		};

		FontCodeType(Enum value = MAX) : value(value) { }

		friend bool operator == (FontCodeType const& a, FontCodeType const& b) { return a.value == b.value; }
		friend bool operator != (FontCodeType const& a, FontCodeType const& b) { return a.value != b.value; }

	private:
		Enum value;
	};

	struct GlyphInfo
	{
		FloatRect uvRect;
		Char codePoint;
		int width;

		GlyphInfo() : codePoint(0), width(0) { }
	};

	typedef std::vector<GlyphInfo> VectorGlyphInfo;

	//FIXME move to std::pair
	class PairCodePoint
	{
	public:
		PairCodePoint() : first(0), last(0) { }
		PairCodePoint(Char first, Char last) : first(first), last(last) { }

		bool IsExist(Char code) const { return code >= first && code <= last; }

	public:
		Char first;
		Char last;
	};

	class RangeInfo
	{
	public:
		RangeInfo() : first(0), last(0) { }
		RangeInfo(Char first, Char last) :
			first(first),
			last(last)
		{
			range.resize(this->last - first + 1);
		}

		bool IsExist(Char code) const { return code >= first && code <= last; }

		GlyphInfo* GetInfo(Char code) { return IsExist(code) ? &range[code - first] : nullptr; }
		void SetInfo(Char code, GlyphInfo* value) { if (IsExist(code)) range[code - first] = *value; }

	public:
		Char first;
		Char last;
		VectorGlyphInfo range;
	};

	// FIXME move to resource font
	class PairCodeCoord
	{
	public:
		PairCodeCoord() : code(0) { }
		PairCodeCoord(Char code, const IntCoord& coord) :
			code(code),
			coord(coord)
		{
		}

		bool operator < (const PairCodeCoord& value) const { return code < value.code; }

		Char code;
		IntCoord coord;
	};

} // namespace GUI

#endif // __FONT_DATA_H__

