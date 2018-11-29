#include "Precompiled.h"
#include "TextIterator.h"

namespace GUI
{

	TextIterator::TextIterator() :
		mPosition(0),
		mSize(ITEM_NONE),
		mFirst(true),
		mHistory(nullptr)
	{
	}

	TextIterator::TextIterator(const UString& text, VectorChangeInfo * history) :
		mText(text),
		mCurrent(mText.begin()),
		mEnd(mText.end()),
		mSave(mEnd),
		mPosition(0),
		mSize(ITEM_NONE),
		mFirst(true),
		mHistory(history)
	{
	}

	bool TextIterator::MoveNext()
	{
		if (mCurrent == mEnd) return false;
		else if (mFirst)
		{
			mFirst = false;
			return true;
		}

		for (UString::iterator iter=mCurrent; iter!=mEnd; ++iter)
		{

			if ((*iter) == L'#')
			{

				++ iter;
				if (iter == mEnd)
				{
					mCurrent = mEnd;
					return false;
				}

				if ((*iter) == L'#')
				{

					mPosition ++;
					iter++;
					if (iter == mEnd)
					{
						mCurrent = mEnd;
						return false;
					}

					mCurrent = iter;
					return true;
				}

				for (size_t pos=0; pos<5; pos++)
				{
					++ iter;
					if (iter == mEnd)
					{
						mCurrent = mEnd;
						return false;
					}
				}

			}
			else
			{

				mPosition ++;
				iter++;
				if (iter == mEnd)
				{
					mCurrent = mEnd;
					return false;
				}

				mCurrent = iter;
				return true;
			}
		}

		return false;
	}

	UString TextIterator::GetTagColour(bool clear)
	{
		if (mCurrent == mEnd) return L"";

		UString::iterator iter = mCurrent;
		UString colour;
		while (GetTagColour(colour, iter))
		{
			if (clear)
			{
				iter = mCurrent = Erase(mCurrent, iter);
				mEnd = mText.end();
			}
		}
		return colour;
	}

	bool TextIterator::GetTagColour(UString& colour)
	{
		if (mCurrent == mEnd) return false;

		UString::iterator iter = mCurrent;

		bool ret = false;
		while (true)
		{
			if (!GetTagColour(colour, iter)) break;
			ret = true;
		}

		return ret;
	}

	bool TextIterator::SetTagColour(const Colour& colour)
	{
		if (mCurrent == mEnd) return false;
		ClearTagColour();
		if (mCurrent == mEnd) return false;

		const size_t SIZE = 16;
		wchar_t buff[SIZE];

#ifdef __MINGW32__
		swprintf(buff, L"#%.2X%.2X%.2X\0", (int)(colour.red*255), (int)(colour.green*255), (int)(colour.blue*255));
#else
		swprintf(buff, SIZE, L"#%.2X%.2X%.2X\0", (int)(colour.red*255), (int)(colour.green*255), (int)(colour.blue*255));
#endif
		UString tmpStr = UString(buff);
		Insert(mCurrent, tmpStr);

		return true;
	}

	bool TextIterator::SetTagColour(UString colour)
	{
		if (mCurrent == mEnd) return false;
		ClearTagColour();
		if (mCurrent == mEnd) return false;

		if ( (colour.size() != 7) || (colour.find(L'#', 1) != colour.npos) ) return false;

		Insert(mCurrent, colour);

		return true;
	}

	size_t TextIterator::GetSize() const
	{
		if (mSize != ITEM_NONE) return mSize;
		mSize = mPosition;

		for (UString::iterator iter=mCurrent; iter!=mEnd; ++iter)
		{

			if ((*iter) == L'#')
			{
				++ iter;
				if (iter == mEnd) break;

				if ((*iter) != L'#')
				{
					for (size_t pos=0; pos<5; pos++)
					{
						++ iter;
						if (iter == mEnd)
						{
							--iter;
							break;
						}
					}
					continue;
				}
			}

			mSize ++;
		}

		return mSize;
	}

	UString TextIterator::GetOnlyText(const UString& text)
	{
		UString ret;
		ret.reserve(text.size());

		UString::const_iterator end = text.end();
		for (UString::const_iterator iter=text.begin(); iter!=end; ++iter)
		{

			if ((*iter) == L'#')
			{
				++ iter;
				if (iter == end) break;

				if ((*iter) != L'#')
				{
					for (size_t pos=0; pos<5; pos++)
					{
						++ iter;
						if (iter == end)
						{
							--iter;
							break;
						}
					}
					continue;
				}
			}

			ret.push_back(*iter);
		}

		return ret;
	}

	bool TextIterator::GetTagColour(UString& colour, UString::iterator& iter)
	{
		if ( (iter == mEnd) || ((*iter) != L'#') ) return false;

		++iter;
		if ( (iter == mEnd) || ((*iter) == L'#') ) return false;

		wchar_t buff[16] = L"#FFFFFF\0";
		buff[1] = (wchar_t)(*iter);
		for (size_t pos=2; pos<7; pos++)
		{
			++iter;
			if ( iter == mEnd ) return false;
			buff[pos] = (Char)(*iter);
		}

		++iter;

		colour = buff;
		return true;
	}

	void TextIterator::ClearNewLine(UString& text)
	{
		for (UString::iterator iter=text.begin(); iter!=text.end(); ++iter)
		{
			if ( ((*iter) == FontCodeType::NEL) ||
				((*iter) == FontCodeType::CR) ||
				((*iter) == FontCodeType::LF) )
			{
				(*iter) = FontCodeType::Space;
			}
		}
	}

	bool TextIterator::SaveStartPoint()
	{
		if (mCurrent == mEnd) return false;
		mSave = mCurrent;
		return true;
	}

	UString TextIterator::GetFromStart()
	{
		if (mSave == mEnd) return L"";
		size_t start = mSave-mText.begin();
		return mText.substr(start, mCurrent-mText.begin()-start);
	}

	bool TextIterator::EraseFromStart()
	{
		if (mSave == mEnd) return false;
		mCurrent = Erase(mSave, mCurrent);
		mSave = mEnd = mText.end();
		return true;
	}

	void TextIterator::InsertText(const UString& insert, bool multiLine)
	{
		UString text = insert;
		if (!multiLine) ClearNewLine(text);
		Insert(mCurrent, text);
	}

	void TextIterator::SetText(const UString& text, bool multiLine)
	{
		Clear();
		UString curText = text;
		if (!multiLine) ClearNewLine(curText);
		Insert(mCurrent, curText);
	}

	UString TextIterator::GetTextCharInfo(Char _char)
	{
		if (_char == L'#') return L"##";
		wchar_t buff[16] = L"_\0";
		buff[0] = _char;
		return buff;
	}

	UString TextIterator::ConvertTagColour(const Colour& colour)
	{
		const size_t SIZE = 16;
		wchar_t buff[SIZE];
//FIXME
#ifdef __MINGW32__
        swprintf(buff, L"#%.2X%.2X%.2X\0", (int)(colour.red*255), (int)(colour.green*255), (int)(colour.blue*255));
#else
        swprintf(buff, SIZE, L"#%.2X%.2X%.2X\0", (int)(colour.red*255), (int)(colour.green*255), (int)(colour.blue*255));
#endif
		return buff;
	}

	UString TextIterator::ToTagsString(const UString& text)
	{
		UString curText(text);
		for (UString::iterator iter=curText.begin(); iter!=curText.end(); ++iter)
		{
			if (L'#' == (*iter)) iter = curText.insert(++iter, L'#');
		}
		return curText;
	}

	void TextIterator::Insert(UString::iterator& start, UString& insert)
	{
		mSize = ITEM_NONE;
		if (mHistory) mHistory->push_back(TextCommandInfo(insert, start-mText.begin(), TextCommandInfo::COMMAND_INSERT));
		size_t pos = start - mText.begin();
		size_t pos_save = (mSave==mEnd) ? ITEM_NONE : start - mText.begin();
		mText.insert(start, insert.begin(), insert.end());
		start = mText.begin() + pos;
		mEnd = mText.end();
		(pos_save==ITEM_NONE) ? mSave = mEnd : mSave = mText.begin() + pos_save;
	}

	UString::iterator TextIterator::Erase(UString::iterator start, UString::iterator end)
	{
		mSize = ITEM_NONE;
		size_t curStart = start-mText.begin();
		if (mHistory) mHistory->push_back(TextCommandInfo(mText.substr(curStart, end-start), curStart, TextCommandInfo::COMMAND_ERASE));
		return mText.erase(start, end);
	}

	void TextIterator::Clear()
	{
		if (mText.empty()) return;

		if (mHistory) mHistory->push_back(TextCommandInfo(mText, 0, TextCommandInfo::COMMAND_ERASE));

		mText.clear();
		mCurrent = mText.begin();
		mEnd = mSave = mText.end();
		mSize = ITEM_NONE;
	}

	void TextIterator::CutMaxLength(size_t max)
	{
		if ( (mSize != ITEM_NONE) && (mSize <= max) ) return;
		if (mPosition > max)
		{
			mSize = mPosition = 0;
			mCurrent = mText.begin();
			mEnd = mSave = mText.end();
		}

		mSize = mPosition;

		for (UString::iterator iter=mCurrent; iter!=mEnd; ++iter)
		{

			if ((*iter) == L'#')
			{
				++ iter;
				if (iter == mEnd) break;

				if ((*iter) != L'#')
				{
					for (size_t pos=0; pos<5; pos++)
					{
						++ iter;
						if (iter == mEnd)
						{
							-- iter;
							break;
						}
					}
					continue;
				}
			}

			if (mSize == max)
			{
				mPosition = mSize; 
				mCurrent = Erase(iter, mEnd);
				mSave = mEnd = mText.end();
				mSize = mPosition; 
				return;
			}

			mSize ++;
		}
	}

	void TextIterator::CutMaxLengthFromBeginning(size_t max)
	{
		size_t size = GetSize();
		if (size <= max) return;

		size_t diff = size - max;

		UString::iterator iter_colour = mEnd;

		UString::iterator iter=mText.begin();
		for (; iter!=mEnd; ++iter)
		{
			if ((*iter) == L'#')
			{
				UString::iterator save = iter;

				++ iter;
				if (iter == mEnd) break;

				if ((*iter) != L'#')
				{
					for (size_t pos=0; pos<5; pos++)
					{
						++ iter;
						if (iter == mEnd)
						{
							-- iter;
							break;
						}
					}
					iter_colour = save;
				}
				continue;
			}
			if (diff == 0) break;
			-- diff;
		}

		UString colour;
		if (iter_colour != mEnd)
		{
			colour.append(iter_colour, iter_colour + size_t(7));
		}

		mCurrent = Erase(mText.begin(), iter);
		mEnd = mText.end();
		mSave = mText.end(); //FIXME
		mPosition = 0;
		mSize = max;

		if ( ! colour.empty() ) SetTagColour(colour);

	}

} // namespace GUI


