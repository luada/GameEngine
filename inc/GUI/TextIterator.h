#ifndef __TEXT_ITERATOR_H__
#define __TEXT_ITERATOR_H__

#include "Prerequest.h"
#include "Colour.h"
#include "TextChangeHistory.h"
#include "IFont.h"

namespace GUI
{

	class GUI_EXPORT TextIterator
	{
	private:
		TextIterator();

	public:
		TextIterator(const UString& text, VectorChangeInfo * history = nullptr);

		bool MoveNext();

		UString GetTagColour(bool clear = false);

		bool GetTagColour(UString& colour);

		void ClearTagColour() { GetTagColour(true); }

		bool SetTagColour(const Colour& colour);

		bool SetTagColour(UString colour);

		bool SaveStartPoint();

		UString GetFromStart();

		bool EraseFromStart();

		size_t GetPosition() const { return mPosition; }

		const UString& GetText() const { return mText; }

		void InsertText(const UString& insert, bool multiLine);

		void ClearNewLine(UString& text);

		void ClearText() { Clear(); }

		size_t GetSize() const;

		void SetText(const UString& text, bool multiLine);

		void CutMaxLength(size_t max);

		void CutMaxLengthFromBeginning(size_t max);

		static UString GetOnlyText(const UString& text);

		static UString GetTextNewLine() { return L"\n"; }

		static UString GetTextCharInfo(Char _char);

		static UString ConvertTagColour(const Colour& colour);

		static UString ToTagsString(const UString& text);

	private:

		bool GetTagColour(UString& colour, UString::iterator& iter);

		void Insert(UString::iterator& start, UString& insert);

		UString::iterator Erase(UString::iterator start, UString::iterator end);

		void Clear();

	private:
		UString mText;
		UString::iterator mCurrent, mEnd, mSave;

		size_t mPosition;
		mutable size_t mSize;
		bool mFirst;

		VectorChangeInfo * mHistory;

	};

} // namespace GUI

#endif // __TEXT_ITERATOR_H__

