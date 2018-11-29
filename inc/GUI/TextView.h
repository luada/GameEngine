#ifndef __TEXT_VIEW_H__
#define __TEXT_VIEW_H__

#include "Prerequest.h"
#include "TextureUtility.h"

namespace GUI
{

	class CharInfo
	{
	public:
		CharInfo() : width(0) { }
		CharInfo(const FloatRect& rect, int width) : rect(rect), width(width) { }
		CharInfo(uint32 colour) :rect(-1, 0, 0, 0), width((int)colour) { }

		bool IsColour() const { return rect.left == -1; }
		int GetWidth() const { return width; }
		const FloatRect& GetUVRect() const { return rect; }
		uint32 GetColour() const { return (uint32)width; }

	private:
		FloatRect rect;
		int width;
	};

	typedef std::vector<CharInfo> VectorCharInfo;

	struct LineInfo
	{
		LineInfo() : width(0), offset(0), count(0) { }
		void Clear() { width = 0; count = 0; simbols.clear(); offset = 0; }
		int width;
		int offset;
		size_t count;
		VectorCharInfo simbols;
	};

	typedef std::vector<LineInfo> VectorLineInfo;

	class RollBackPoint
	{
	public:
		RollBackPoint() :
			position(0),
			count(0),
			lenght(0),
			rollback(false)
		{ }

		void Set(size_t position,
			UString::const_iterator& space_point,
			size_t count,
			int length)
		{
			this->position = position;
			this->space_point = space_point;
			this->count = count;
			lenght = length;
			rollback = true;
		}

		void Clear() { rollback = false; }
		bool empty() const { return !rollback; }
		int GetLenght() const { DEBUG_ASSERT(rollback, "rollback point not valid"); return lenght; }
		size_t GetCount() const { DEBUG_ASSERT(rollback, "rollback point not valid"); return count; }
		size_t GetPosition() const { DEBUG_ASSERT(rollback, "rollback point not valid"); return position; }
		UString::const_iterator GetTextIter() { DEBUG_ASSERT(rollback, "rollback point not valid"); return space_point; }

	private:
		size_t position;
		UString::const_iterator space_point;
		size_t count;
		int lenght;
		bool rollback;
	};

	class TextView
	{
	public:
		TextView() :
			mLength(0),
			mFontHeight(0)
		{
		}

		void Update(const UString& text, IFont* font, int height, Align align, VertexColourType format, int maxheight = -1)
		{
			mFontHeight = height;

			static const char convert_colour[64] = { 0,  1,  2,  3,  4,  5,  6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
													 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
													 0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
													 0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0
			                                       };

			mViewSize.Clear();

			RollBackPoint roll_back;
			IntSize result;
			int width = 0;
			size_t count = 0;
			mLength = 0;
			mLineInfo.clear();
			LineInfo line_info;
			int font_height = font->GetDefaultHeight();

			UString::const_iterator end = text.end();
			UString::const_iterator index = text.begin();

			/*if (index == end)
				return;*/

			result.height += height;

			for (; index!=end; ++index)
			{
				Char character = *index;

				if (character == FontCodeType::CR
					|| character == FontCodeType::NEL
					|| character == FontCodeType::LF)
				{
					if (character == FontCodeType::CR)
					{
						UString::const_iterator peeki = index;
						peeki ++;
						if ((peeki != end) && (*peeki == FontCodeType::LF))
							index = peeki; // skip both as one newline
					}

					line_info.width = width;
					line_info.count = count;
					mLength += line_info.count + 1;

					result.height += height;
					if (result.width < width)
						result.width = width;
					width = 0;
					count = 0;

					mLineInfo.push_back(line_info);
					line_info.Clear();

					roll_back.Clear();

					continue;
				}
				else if (character == L'#')
				{
					++ index;
					if (index == end) { --index; continue; } 

					character = *index;
					if (character != L'#')
					{
						uint32 colour = convert_colour[(character-48) & 0x3F];

						for (char i=0; i<5; i++)
						{
							++ index;
							if (index == end) { --index; continue; } 
							colour <<= 4;
							colour += convert_colour[ ((*index) - 48) & 0x3F ];
						}

						texture_utility::ConvertColour(colour, format);

						line_info.simbols.push_back( CharInfo(colour) );

						continue;
					}
				}

				GlyphInfo* info = font->GetGlyphInfo(character);
				if (FontCodeType::Space == character)
				{
					roll_back.Set(line_info.simbols.size(), index, count, width);
				}
				else if (FontCodeType::Tab == character)
				{
					roll_back.Set(line_info.simbols.size(), index, count, width);
				}

				int char_width = info->width;
				if (font_height != height)
				{
					char_width = char_width * height / font_height;
					if (!char_width) char_width = 1;
				}

				if (maxheight != -1
					&& (width + char_width) > maxheight
					&& !roll_back.empty())
				{
					width = roll_back.GetLenght();
					count = roll_back.GetCount();
					index = roll_back.GetTextIter();
					line_info.simbols.erase(line_info.simbols.begin() + roll_back.GetPosition(), line_info.simbols.end());

					line_info.width = width;
					line_info.count = count;
					mLength += line_info.count + 1;

					result.height += height;
					if (result.width < width)
						result.width = width;
					width = 0;
					count = 0;

					mLineInfo.push_back(line_info);
					line_info.Clear();

					roll_back.Clear();

					continue;
				}

				line_info.simbols.push_back(CharInfo(info->uvRect, char_width));
				width += char_width;
				count ++;
			}

			line_info.width = width;
			line_info.count = count;
			mLength += line_info.count;

			mLineInfo.push_back(line_info);

			if (result.width < width)
				result.width = width;

			for (VectorLineInfo::iterator line=mLineInfo.begin(); line!=mLineInfo.end(); ++line)
			{
				if (align.IsRight())
					line->offset = result.width - line->width;
				else if (align.IsHCenter())
					line->offset = (result.width - line->width) / 2;
			}

			mViewSize = result;
		}

		size_t GetCursorPosition(const IntPoint& value)
		{
			const int height = mFontHeight;
			size_t result = 0;
			int top = 0;

			for (VectorLineInfo::const_iterator line=mLineInfo.begin(); line!=mLineInfo.end(); ++line)
			{
				bool lastline = !(line + 1 != mLineInfo.end());

				if (top + height > value.top || lastline)
				{
					top += height;
					int left = line->offset;
					int count = 0;

					for (VectorCharInfo::const_iterator sim=line->simbols.begin(); sim!=line->simbols.end(); ++sim)
					{
						if (sim->IsColour())
							continue;

						if ((left + (sim->GetWidth() / 2)) > value.left)
						{
							break;
						}
						left += sim->GetWidth();
						count ++;
					}

					result += count;
					break;
				}

				if (!lastline)
				{
					top += height;
					result += line->count + 1;
				}
			}

			return result;
		}

		IntPoint GetCursorPoint(size_t position)
		{
			if (position >= mLength + 1) position = mLength;

			size_t curPosition = 0;
			int top = 0;
			int left = 0;
			for (VectorLineInfo::const_iterator line=mLineInfo.begin(); line!=mLineInfo.end(); ++line)
			{
				left = line->offset;
				if (curPosition + line->count >= position)
				{
					for (VectorCharInfo::const_iterator sim=line->simbols.begin(); sim!=line->simbols.end(); ++sim)
					{
						if (sim->IsColour())
							continue;

						if (curPosition == position)
							break;

						curPosition ++;
						left += sim->GetWidth();
					}
					break;
				}
				curPosition += line->count + 1;
				top += mFontHeight;
			}

			return IntPoint(left, top);
		}

		const IntSize& GetViewSize() const { return mViewSize; }
		size_t GetTextLength() const { return mLength; }
		const VectorLineInfo& GetData() { return mLineInfo; }

	private:
		IntSize mViewSize;
		size_t mLength;
		VectorLineInfo mLineInfo;
		int mFontHeight;
	};


} // namespace GUI

#endif // __TEXT_VIEW_H__


