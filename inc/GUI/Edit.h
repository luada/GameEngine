#ifndef __EDIT_H__
#define __EDIT_H__

#include "Prerequest.h"
#include "StaticText.h"
#include "TextChangeHistory.h"
#include "TextIterator.h"
#include "EventPair.h"
#include "ScrollViewBase.h"

namespace GUI
{

	typedef delegates::CDelegate1<Edit*> EventHandle_EditPtr;

	class GUI_EXPORT Edit :
		public StaticText,
		public ScrollViewBase
	{
		RTTI_DERIVED(Edit)
		DEFINE_GET_THIS(Edit, BASS(StaticText, END))

	public:
		Edit();
 
		/** Colour interval */
		//@ExportToLua
		void SetTextIntervalColour(size_t start, size_t count, const Colour& colour);

		/** Get index of first selected character or ITEM_NONE if nothing selected */
		//@ExportToLua
		size_t GetTextSelectionStart();

		/** Get index of last selected character or ITEM_NONE if nothing selected */
		//@ExportToLua
		size_t GetTextSelectionEnd();

		/** Get length of selected text */
		//@ExportToLua
		size_t GetTextSelectionLength();

		/** Get _count characters with tags from _start position */
		//@ExportToLua
		UString GetTextInterval(size_t start, size_t count);

		/** Set selected text interval
			@param _start of interval
			@param _end of interval
		*/
		//@ExportToLua
		void SetTextSelection(size_t start, size_t end);

		/** delete selected text */
		//@ExportToLua
		void DeleteTextSelection();

		/** Get selected text */
		//@ExportToLua
		UString GetTextSelection();

		/** Is any text selected */
		//@ExportToLua
		bool IsTextSelection();

		/** Colour selected text */
		//@ExportToLua
		void SetTextSelectionColour(const Colour& value);

		/** Set text cursor position */
		//@ExportToLua
		void SetTextCursor(size_t index);
		/** Get text cursor position */
		//@ExportToLua
		size_t GetTextCursor() { return mCursorPosition; }


		/** Set edit text applying tags */
		//@ExportToLua
		virtual void SetCaption(const UString& value);
		/** Get edit text with tags */
		//@ExportToLua
		virtual const UString& GetCaption();

		/** Set edit text without tags */
		//@ExportToLua
		void SetOnlyText(const UString& value);
		/** Get edit text without tags */
		//@ExportToLua
		UString GetOnlyText();

		/** Get text length excluding tags
			For example "#00FF00Hello" length is 5
		*/
		//@ExportToLua
		size_t GetTextLength() const { return mTextLength; }

		//! Sets if surplus characters should push characters off the left side rather than ignored
		//@ExportToLua
		void SetOverflowToTheLeft(bool value) { mOverflowToTheLeft = value; }
		//! Returns true if surplus characters will be pushed off the left rather than ignored
		//@ExportToLua
		bool GetOverflowToTheLeft() { return mOverflowToTheLeft; }

		//! Sets the max amount of text allowed in the edit field.
		//@ExportToLua
		void SetMaxTextLength(size_t value) { mMaxTextLength = value; }
		//! Gets the max amount of text allowed in the edit field.
		//@ExportToLua
		size_t GetMaxTextLength() { return mMaxTextLength; }

		/** Inser text at index Position (text end by default) */
		//@ExportToLua
		void InsertText(const UString& text, size_t index = ITEM_NONE);
		/** Add text */
		//@ExportToLua
		void AddText(const UString& text);

		/** Erase _count characters from _start position */
		//@ExportToLua
		void eraseText(size_t start, size_t count = 1);

		/** Enable or disable edit read only mode\n
			Read only mode: you can't edit text, but can select it.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetEditReadOnly(bool value);
		/** Get edit read only mode flag */
		//@ExportToLua
		bool GetEditReadOnly() { return mModeReadOnly; }

		/** Enable or disable edit password mode\n
			Password mode: you see password chars (*** by default) instead text.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetEditPassword(bool value);
		/** Get edit password mode flag */
		//@ExportToLua
		bool GetEditPassword() { return mModePassword; }

		/** Enable or disable edit multiline mode\n
			Multile mode: new line character moves text to new line.\n
			Otherwise new lines replaced with space and all text is in single line.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetEditMultiLine(bool value);
		/** Get edit multiline mode flag */
		//@ExportToLua
		bool GetEditMultiLine() { return mModeMultiline; }

		/** Enable or disable edit static mode\n
			Static mode is same as read only, but you also can't select text.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetEditStatic(bool value);
		/** Get edit static mode flag */
		//@ExportToLua
		bool GetEditStatic() { return mModeStatic; }

		/** Set edit password character ('*' by default) */
		//@ExportToLua
		void SetPasswordChar(Char value);
		/** Set edit password character ('*' by default). First character of string used. */
		//@ExportToLua
		void SetPasswordChar(const UString& _char);
		/** Get edit password character */
		//@ExportToLua
		Char GetPasswordChar() { return mCharPassword; }

		/** Enable or disable edit word wrap mode\n
			Word Wrap mode: move words to new line if they goes out of width.
			Also in this mode you can't edit or select text.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetEditWordWrap(bool value);
		/** Get edit word wrap mode flag */
		//@ExportToLua
		bool GetEditWordWrap() { return mModeWordWrap; }

		/** Enable or disable tab printing mode\n
			Tab printing mode: when editing text and pressing Tab key it displayed.
			If this mode disabled Tab key ignored.\n
			Disabled (false) by default.
		*/
		//@ExportToLua
		void SetTabPrinting(bool value) { mTabPrinting = value; }
		/** Get edit tab printing wrap mode flag */
		//@ExportToLua
		bool GetTabPrinting() { return mTabPrinting; }

		/** Get invert selected text color property */
		//@ExportToLua
		bool GetInvertSelected();
		/** Enable or disable inverting color of selected text\n
			Enabled (true) by default
		*/
		//@ExportToLua
		void SetInvertSelected(bool value);

		//! @copydoc Widget::SetPosition(const IntPoint& value)
		virtual void SetPosition(const IntPoint& value);
		//! @copydoc Widget::SetSize(const IntSize& value)
		virtual void SetSize(const IntSize& value);
		//! @copydoc Widget::SetCoord(const IntCoord& value)
		virtual void SetCoord(const IntCoord& value);

		/** @copydoc Widget::SetPosition(int left, int top) */
		//@ExportToLua
		void SetPosition(int left, int top) { SetPosition(IntPoint(left, top)); }
		/** @copydoc Widget::SetSize(int width, int height) */
		//@ExportToLua
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }
		/** @copydoc Widget::SetCoord(int left, int top, int width, int height) */
		//@ExportToLua
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		/** Show VScroll when text size larger than Edit */
		//@ExportToLua
		void SetVisibleVScroll(bool value);
		/** Get Show VScroll flag */
		//@ExportToLua
		bool IsVisibleVScroll() { return mVisibleVScroll; }
		/** Get range of vertical Scroll (or 0 if no scroll).
			Range measured in Pixels (full text heiht minus Edit height).
			For example if Edit is 200 pixels height and 40 lines of text
			30 pixels height Each (i.e. 600 pixels total), then return
			value is 400 (= 600 - 200).
		*/
		//@ExportToLua
		size_t GetVScrollRange();
		/** Get current position of vertical Scroll (or 0 if no scroll) */
		//@ExportToLua
		size_t GetVScrollPosition();
		/** Set current position of vertical scroll */
		//@ExportToLua
		void SetVScrollPosition(size_t index);

		/** Show HScroll when text size larger than Edit */
		//@ExportToLua
		void SetVisibleHScroll(bool value);
		/** Get Show HScroll flag */
		//@ExportToLua
		bool IsVisibleHScroll() { return mVisibleHScroll; }
		/** Get range of horizontal Scroll (or 0 if no scroll).
			Range measured in Pixels (full text width minus Edit width).
			For example if Edit is 200 pixels width and the longest line
			is 600 pixels width, then return value is 400 (= 600 - 200).
		*/
		//@ExportToLua
		size_t GetHScrollRange();
		/** Get current position of horizontal Scroll (or 0 if no scroll) */
		//@ExportToLua
		size_t GetHScrollPosition();
		/** Set current position of horizontal scroll */
		//@ExportToLua
		void SetHScrollPosition(size_t index);


		//! @copydoc StaticText::setFontName
		//@ExportToLua
		virtual void SetFontName(const std::string& value);
		//! @copydoc StaticText::setFontHeight
		//@ExportToLua
		virtual void SetFontHeight(int value);

		//! @copydoc StaticText::setTextAlign
		//@ExportToLua
		virtual void SetTextAlign(Align value);

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : Enter Pressed (Ctrl+enter in multiline mode).\n
			signature : void Method(GUI::Edit* sender)
			@param _sender widget that called this event
		*/
		EventPair<EventHandle_WidgetVoid, EventHandle_EditPtr> eventEditSelectAccept;

		/** Event : Text changed.\n
			signature : void Method(GUI::Edit* sender)
			@param _sender widget that called this event
		*/
		EventPair<EventHandle_WidgetVoid, EventHandle_EditPtr> eventEditTextChange;

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~Edit();

		virtual void OnMouseDrag(int left, int top);
		virtual void OnKeyLostFocus(Widget* _new);
		virtual void OnKeySetFocus(Widget* old);
		virtual void OnKeyButtonPressed(KeyCode key, Char _char);

		void NotifyMouseSetFocus(Widget* sender, Widget* old);
		void NotifyMouseLostFocus(Widget* sender, Widget* _new);
		void NotifyMousePressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseReleased(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseDrag(Widget* sender, int left, int top);
		void NotifyMouseButtonDoubleClick(Widget* sender);

		void NotifyScrollChangePosition(VScroll* sender, size_t position);
		void NotifyMouseWheel(Widget* sender, int rel);

		void UpdateView();
		void UpdateViewWithCursor();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		void eraseView();

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

	private:
		void SetText(const UString& text, bool history);
		bool DeleteTextSelect(bool history);
		void InsertText(const UString& text, size_t index, bool history);
		void eraseText(size_t start, size_t count, bool history);
		void SetTextSelectColour(const Colour& colour, bool history);
		void _setTextColour(size_t start, size_t count, const Colour& colour, bool history);

		void FrameEntered(float frame);

		void UpdateEditState();

		void UpdateSelectText();

		void ResetSelect();

		void CommandPosition(size_t undo, size_t redo, size_t length, VectorChangeInfo * info = nullptr);

		bool CommandRedo();
		bool CommandUndo();
		void CommandMerge();
		void CommandResetRedo() { mVectorRedoChangeInfo.clear(); }
		void CommandResetHistory() { mVectorRedoChangeInfo.clear();mVectorUndoChangeInfo.clear(); }
		void SaveInHistory(VectorChangeInfo * info = nullptr);

		void CommandCut();
		void CommandCopy();
		void CommandPast();

		const UString& GetRealString();

		void SetRealString(const UString& caption);

		void UpdateCursorPosition();

		virtual IntSize GetContentSize();
		virtual IntPoint GetContentPosition();
		virtual void SetContentPosition(const IntPoint& point);
		virtual IntSize GetViewSize() const;
		virtual size_t GetVScrollPage();
		virtual size_t GetHScrollPage();

		virtual Align GetContentAlign();

	protected:
		bool mIsPressed;
		bool mIsFocus;

		bool mCursorActive;
		float mCursorTimer;
		float mActionMouseTimer;

		size_t mCursorPosition;
		size_t mTextLength;

		size_t mStartSelect;
		size_t mEndSelect;

		DequeUndoRedoInfo mVectorUndoChangeInfo;
		DequeUndoRedoInfo mVectorRedoChangeInfo;

		bool mMouseLeftPressed;

		bool mModeReadOnly;
		bool mModePassword;
		bool mModeMultiline;
		bool mModeStatic;
		bool mModeWordWrap;

		bool mTabPrinting;

		UString mPasswordText;

		std::string mOriginalPointer;

		Char mCharPassword;

		bool mOverflowToTheLeft;
		size_t mMaxTextLength;

	};

} // namespace GUI

#endif // __EDIT_H__

