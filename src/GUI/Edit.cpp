#include "Precompiled.h"
#include "Gui.h"
#include "Edit.h"
#include "ResourceSkin.h"
#include "SkinManager.h"
#include "InputManager.h"
#include "ClipboardManager.h"
#include "PointerManager.h"
#include "ISubWidgetText.h"
#include "VScroll.h"
#include "HScroll.h"

namespace GUI
{

	const float EDIT_CURSOR_TIMER  = 0.7f;
	const float EDIT_ACTION_MOUSE_TIMER  = 0.05f;
	const int EDIT_CURSOR_MAX_POSITION = 100000;
	const int EDIT_CURSOR_MIN_POSITION = -100000;
	const size_t EDIT_MAX_UNDO = 128;
	const size_t EDIT_DEFAULT_MAX_TEXT_LENGTH = 2048;
	const float EDIT_OFFSET_HORZ_CURSOR = 10.0f; 
	const int EDIT_ACTION_MOUSE_ZONE = 1500; 
	const std::string EDIT_CLIPBOARD_TYPE_TEXT = "Text";
	const int EDIT_MOUSE_WHEEL = 50; 

	Edit::Edit() :
		mIsPressed(false),
		mIsFocus(false),
		mCursorActive(false),
		mCursorTimer(0),
		mActionMouseTimer(0),
		mCursorPosition(0),
		mTextLength(0),
		mStartSelect(ITEM_NONE),
		mEndSelect(0),
		mMouseLeftPressed(false),
		mModeReadOnly(false),
		mModePassword(false),
		mModeMultiline(false),
		mModeStatic(false),
		mModeWordWrap(false),
		mTabPrinting(false),
		mCharPassword('*'),
		mOverflowToTheLeft(false),
		mMaxTextLength(EDIT_DEFAULT_MAX_TEXT_LENGTH)
	{
		mChangeContentByResize = true;
	}

	void Edit::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	Edit::~Edit()
	{
		ShutdownWidgetSkin();
	}

	void Edit::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void Edit::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mOriginalPointer = mPointer;

		mNeedKeyFocus = true;

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mWidgetClient, "widget already assigned");
				mWidgetClient = (*iter);
				mWidgetClient->eventMouseSetFocus = NewDelegate(this, &Edit::NotifyMouseSetFocus);
				mWidgetClient->eventMouseLostFocus = NewDelegate(this, &Edit::NotifyMouseLostFocus);
				mWidgetClient->eventMouseButtonPressed = NewDelegate(this, &Edit::NotifyMousePressed);
				mWidgetClient->eventMouseButtonReleased = NewDelegate(this, &Edit::NotifyMouseReleased);
				mWidgetClient->eventMouseDrag = NewDelegate(this, &Edit::NotifyMouseDrag);
				mWidgetClient->eventMouseButtonDoubleClick = NewDelegate(this, &Edit::NotifyMouseButtonDoubleClick);
				mWidgetClient->eventMouseWheel = NewDelegate(this, &Edit::NotifyMouseWheel);
				mClient = mWidgetClient;
			}
			else if (*(*iter)->_getInternalData<std::string>() == "VScroll")
			{
				DEBUG_ASSERT( ! mVScroll, "widget already assigned");
				mVScroll = (*iter)->CastType<VScroll>();
				mVScroll->eventScrollChangePosition = NewDelegate(this, &Edit::NotifyScrollChangePosition);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "HScroll")
			{
				DEBUG_ASSERT( ! mHScroll, "widget already assigned");
				mHScroll = (*iter)->CastType<HScroll>();
				mHScroll->eventScrollChangePosition = NewDelegate(this, &Edit::NotifyScrollChangePosition);
			}
		}

		//ASSERT(nullptr != mWidgetClient, "Child Widget Client not found in Skin (Edit must have Client)");

		if (mWidgetClient != nullptr)
		{
			ISubWidgetText* text = mWidgetClient->GetSubWidgetText();
			if (text) mText = text;
		}

		//ASSERT(nullptr != mText, "TextEdit not found in Skin (Edit or Client must have TextEdit)");

		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.end();
			if ((iter = properties.find("WordWrap")) != properties.end()) SetEditWordWrap(utility::ParseValue<bool>(iter->second));
			else if ((iter = properties.find("InvertSelected")) != properties.end()) SetInvertSelected(utility::ParseValue<bool>(iter->second));
		}

		UpdateScrollSize();

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();
	}

	void Edit::ShutdownWidgetSkin()
	{
		mWidgetClient = nullptr;
		mVScroll= nullptr;
		mHScroll = nullptr;
	}

	void Edit::NotifyMouseSetFocus(Widget* sender, Widget* old)
	{
		if ( (old == mWidgetClient) || (mIsFocus) ) return;
		mIsFocus = true;
		UpdateEditState();
	}

	void Edit::NotifyMouseLostFocus(Widget* sender, Widget* _new)
	{
		if ( (_new == mWidgetClient) || (!mIsFocus) ) return;
		mIsFocus = false;
		UpdateEditState();
	}

	void Edit::NotifyMousePressed(Widget* sender, int left, int top, MouseButton id)
	{
		if (mText == nullptr)
			return;

		if (mModeStatic)
			return;

		IntPoint point = InputManager::GetInstance().GetLastLeftPressed();
		mCursorPosition = mText->GetCursorPosition(point);
		mText->SetCursorPosition(mCursorPosition);
		mText->SetVisibleCursor(true);
		mCursorTimer = 0;
		UpdateSelectText();

		if (id == MouseButton::Left) mMouseLeftPressed = true;
	}

	void Edit::NotifyMouseReleased(Widget* sender, int left, int top, MouseButton id)
	{
		mMouseLeftPressed = false;
	}

	void Edit::NotifyMouseDrag(Widget* sender, int left, int top)
	{
		if (mText == nullptr)
			return;

		if (mModeStatic) return;

		mText->SetVisibleCursor(true);

		mCursorTimer = 0;
		mActionMouseTimer = 0;

		size_t Old = mCursorPosition;
		IntPoint point(left, top);
		mCursorPosition = mText->GetCursorPosition(point);
		if (Old == mCursorPosition) return;

		mText->SetCursorPosition(mCursorPosition);

		if (mStartSelect == ITEM_NONE) mStartSelect = Old;

		mEndSelect = (size_t)mCursorPosition;
		if (mStartSelect > mEndSelect) mText->SetTextSelection(mEndSelect, mStartSelect);
		else mText->SetTextSelection(mStartSelect, mEndSelect);

	}

	void Edit::NotifyMouseButtonDoubleClick(Widget* sender)
	{
		if (mText == nullptr)
			return;

		if (mModeStatic)
			return;

		const IntPoint& lastPressed = InputManager::GetInstance().GetLastLeftPressed();

		size_t cursorPosition = mText->GetCursorPosition(lastPressed);
		mStartSelect = cursorPosition;
		mEndSelect = cursorPosition;

		UString text = this->GetOnlyText();
		UString::reverse_iterator iterBack = text.rend() - cursorPosition;
		UString::iterator iterForw = text.begin() + cursorPosition;

		while (iterBack != text.rend())
		{
			if (((*iterBack)<265) && (ispunct(*iterBack) || isspace(*iterBack))) break;
			iterBack++;
			mStartSelect--;
		}
		while (iterForw != text.end())
		{
			if (((*iterForw)<265) && (ispunct(*iterForw) || isspace(*iterForw))) break;
			iterForw++;
			mEndSelect++;
		}

		mText->SetCursorPosition(mEndSelect);
		mText->SetTextSelection(mStartSelect, mEndSelect);
	}

	void Edit::OnMouseDrag(int left, int top)
	{
		NotifyMouseDrag(nullptr, left, top);

		Base::OnMouseDrag(left, top);
	}

	void Edit::OnKeySetFocus(Widget* old)
	{
		if (!mIsPressed)
		{
			mIsPressed = true;
			UpdateEditState();

			if (!mModeStatic)
			{
				if (mText != nullptr)
				{
					mCursorActive = true;
					Gui::GetInstance().eventFrameStart += NewDelegate(this, &Edit::FrameEntered);
					mText->SetVisibleCursor(true);
					mText->SetSelectBackground(true);
					mCursorTimer = 0;
				}
			}
		}

		Base::OnKeySetFocus(old);
	}

	void Edit::OnKeyLostFocus(Widget* _new)
	{
		if (mIsPressed)
		{
			mIsPressed = false;
			UpdateEditState();

			if (mText != nullptr)
			{
				mCursorActive = false;
				Gui::GetInstance().eventFrameStart -= NewDelegate(this, &Edit::FrameEntered);
				mText->SetVisibleCursor(false);
				mText->SetSelectBackground(false);
			}
		}

		Base::OnKeyLostFocus(_new);
	}

	void Edit::OnKeyButtonPressed(KeyCode key, Char _char)
	{
		if (mText == nullptr || mWidgetClient == nullptr)
		{
			Base::OnKeyButtonPressed(key, _char);
			return;
		}

		if (mModeStatic)
		{
			Base::OnKeyButtonPressed(key, _char);
			return;
		}

		InputManager& input = InputManager::GetInstance();

		mText->SetVisibleCursor(true);
		mCursorTimer = 0.0f;

		if (key == KeyCode::Escape)
		{
			InputManager::GetInstance().SetKeyFocusWidget(nullptr);
		}
		else if (key == KeyCode::Backspace)
		{
			if (!mModeReadOnly)
			{
				if (!DeleteTextSelect(true))
				{
					if (mCursorPosition != 0)
					{
						mCursorPosition--;
						eraseText(mCursorPosition, 1, true);
					}
				}
				eventEditTextChange(this);
			}

		}
		else if (key == KeyCode::Delete)
		{
			if (input.IsShiftPressed()) CommandCut();
			else if (!mModeReadOnly)
			{
				if (!DeleteTextSelect(true))
				{
					if (mCursorPosition != mTextLength)
					{
						eraseText(mCursorPosition, 1, true);
					}
				}
				eventEditTextChange(this);
			}

		}
		else if (key == KeyCode::Insert)
		{
			if (input.IsShiftPressed()) CommandPast();
			else if (input.IsControlPressed()) CommandCopy();

		}
		else if ((key == KeyCode::Return) || (key == KeyCode::NumpadEnter))
		{
			if (!mModeReadOnly)
			{
				if ((mModeMultiline) && (!input.IsControlPressed()))
				{
					size_t size = mVectorUndoChangeInfo.size();
					DeleteTextSelect(true);
					InsertText(TextIterator::GetTextNewLine(), mCursorPosition, true);
					if ((size+2) == mVectorUndoChangeInfo.size()) CommandMerge();
					eventEditTextChange(this);
				}
				else
				{
					eventEditSelectAccept(this);
				}
			}

		}
		else if (key == KeyCode::ArrowRight)
		{
			if ((mCursorPosition) < mTextLength)
			{
				mCursorPosition ++;
				mText->SetCursorPosition(mCursorPosition);
				UpdateSelectText();
			}
			else if (IsTextSelection() && !input.IsShiftPressed())
			{
				ResetSelect();
			}

		}
		else if (key == KeyCode::ArrowLeft)
		{
			if (mCursorPosition != 0)
			{
				mCursorPosition --;
				mText->SetCursorPosition(mCursorPosition);
				UpdateSelectText();
			}
			else if (IsTextSelection() && !input.IsShiftPressed())
			{
				ResetSelect();
			}

		}
		else if (key == KeyCode::ArrowUp)
		{
			IntPoint point = mText->GetCursorPoint(mCursorPosition);
			point.top -= mText->GetFontHeight();
			size_t old = mCursorPosition;
			mCursorPosition = mText->GetCursorPosition(point);
			if ( old == mCursorPosition )
			{
				if (mCursorPosition != 0)
				{
					mCursorPosition = 0;
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}
			else
			{
				mText->SetCursorPosition(mCursorPosition);
				UpdateSelectText();
			}

		}
		else if (key == KeyCode::ArrowDown)
		{
			IntPoint point = mText->GetCursorPoint(mCursorPosition);
			point.top += mText->GetFontHeight();
			size_t old = mCursorPosition;
			mCursorPosition = mText->GetCursorPosition(point);
			if ( old == mCursorPosition )
			{
				if (mCursorPosition != mTextLength)
				{
					mCursorPosition = mTextLength;
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}
			else
			{
				mText->SetCursorPosition(mCursorPosition);
				UpdateSelectText();
			}

		}
		else if (key == KeyCode::Home)
		{
			if ( !input.IsControlPressed())
			{
				IntPoint point = mText->GetCursorPoint(mCursorPosition);
				point.left = EDIT_CURSOR_MIN_POSITION;
				size_t old = mCursorPosition;
				mCursorPosition = mText->GetCursorPosition(point);
				if ( old != mCursorPosition )
				{
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}
			else
			{
				if (0 != mCursorPosition)
				{
					mCursorPosition = 0;
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}

		}
		else if (key == KeyCode::End)
		{
			if ( !  input.IsControlPressed())
			{
				IntPoint point = mText->GetCursorPoint(mCursorPosition);
				point.left = EDIT_CURSOR_MAX_POSITION;
				size_t old = mCursorPosition;
				mCursorPosition = mText->GetCursorPosition(point);
				if ( old != mCursorPosition )
				{
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}
			else
			{
				if (mTextLength != mCursorPosition)
				{
					mCursorPosition = mTextLength;
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}

		}
		else if (key == KeyCode::PageUp)
		{
			IntPoint point = mText->GetCursorPoint(mCursorPosition);
			point.top -= (mWidgetClient->GetHeight() > mText->GetFontHeight()) ? mWidgetClient->GetHeight() : mText->GetFontHeight();
			size_t old = mCursorPosition;
			mCursorPosition = mText->GetCursorPosition(point);
			if ( old == mCursorPosition )
			{
				if (mCursorPosition != 0)
				{
					mCursorPosition = 0;
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}
			else
			{
				mText->SetCursorPosition(mCursorPosition);
				UpdateSelectText();
			}

		}
		else if (key == KeyCode::PageDown)
		{
			IntPoint point = mText->GetCursorPoint(mCursorPosition);
			point.top += (mWidgetClient->GetHeight() > mText->GetFontHeight()) ? mWidgetClient->GetHeight() : mText->GetFontHeight();
			size_t old = mCursorPosition;
			mCursorPosition = mText->GetCursorPosition(point);
			if ( old == mCursorPosition )
			{
				if (mCursorPosition != mTextLength)
				{
					mCursorPosition = mTextLength;
					mText->SetCursorPosition(mCursorPosition);
					UpdateSelectText();
				}
				else if (IsTextSelection() && !input.IsShiftPressed())
				{
					ResetSelect();
				}
			}
			else
			{
				mText->SetCursorPosition(mCursorPosition);
				UpdateSelectText();
			}

		}
		else if ((key == KeyCode::LeftShift) || (key == KeyCode::RightShift))
		{
			if (mStartSelect == ITEM_NONE)
			{
				mStartSelect = mEndSelect = mCursorPosition;
			}
		}
		else if (_char != 0)
		{

			if (!input.IsControlPressed())
			{
				if (!mModeReadOnly)
				{
					if (_char != '\t' || mTabPrinting)
					{
						size_t size = mVectorUndoChangeInfo.size();
						DeleteTextSelect(true);
						InsertText(TextIterator::GetTextCharInfo(_char), mCursorPosition, true);
						if ((size+2) == mVectorUndoChangeInfo.size()) CommandMerge();
						eventEditTextChange(this);
					}
				}
			}
			else if (key == KeyCode::C)
			{
				CommandCopy();

			}
			else if (key == KeyCode::X)
			{
				CommandCut();

			}
			else if (key == KeyCode::V)
			{
				CommandPast();

			}
			else if (key == KeyCode::A)
			{
				SetTextSelection(0, mTextLength);

			}
			else if (key == KeyCode::Z)
			{
				CommandUndo();

			}
			else if (key == KeyCode::Y)
			{
				CommandRedo();

			}
		}

		Base::OnKeyButtonPressed(key, _char);
	}

	void Edit::FrameEntered(float frame)
	{
		if (mText == nullptr)
			return;

		if (mModeStatic)
			return;

		if (mCursorActive)
		{
			mCursorTimer += frame;

			if (mCursorTimer > EDIT_CURSOR_TIMER)
			{
				mText->SetVisibleCursor(!mText->IsVisibleCursor());
				while (mCursorTimer > EDIT_CURSOR_TIMER) mCursorTimer -= EDIT_CURSOR_TIMER;
			}
		}

		if (mMouseLeftPressed)
		{
			mActionMouseTimer += frame;

			if (mActionMouseTimer > EDIT_ACTION_MOUSE_TIMER)
			{

				IntPoint mouse = InputManager::GetInstance().GetMousePositionByLayer();
				const IntRect& view = mWidgetClient->GetAbsoluteRect();
				mouse.left -= view.left;
				mouse.top -= view.top;
				IntPoint point;

				bool Action = false;

				if ( (mouse.top < 0) && (mouse.top > -EDIT_ACTION_MOUSE_ZONE) )
				{
					if ( (mouse.left > 0) && (mouse.left <= mWidgetClient->GetWidth()) )
					{
						point = mText->GetCursorPoint(mCursorPosition);
						point.top -= mText->GetFontHeight();
						Action = true;
					}
				}
				else if ( (mouse.top > mWidgetClient->GetHeight()) && (mouse.top < (mWidgetClient->GetHeight() + EDIT_ACTION_MOUSE_ZONE)) )
				{
					if ( (mouse.left > 0) && (mouse.left <= mWidgetClient->GetWidth()) )
					{
						point = mText->GetCursorPoint(mCursorPosition);
						point.top += mText->GetFontHeight();
						Action = true;
					}
				}

				if ( (mouse.left < 0) && (mouse.left > -EDIT_ACTION_MOUSE_ZONE) )
				{
					point = mText->GetCursorPoint(mCursorPosition);
					point.left -= (int)EDIT_OFFSET_HORZ_CURSOR;
					Action = true;
				}
				else if ( (mouse.left > mWidgetClient->GetWidth()) && (mouse.left < (mWidgetClient->GetWidth() + EDIT_ACTION_MOUSE_ZONE)) )
				{
					point = mText->GetCursorPoint(mCursorPosition);
					point.left += (int)EDIT_OFFSET_HORZ_CURSOR;
					Action = true;
				}

				if (Action)
				{
					size_t old = mCursorPosition;
					mCursorPosition = mText->GetCursorPosition(point);

					if ( old != mCursorPosition )
					{

						mText->SetCursorPosition(mCursorPosition);

						mEndSelect = (size_t)mCursorPosition;
						if (mStartSelect > mEndSelect) mText->SetTextSelection(mEndSelect, mStartSelect);
						else mText->SetTextSelection(mStartSelect, mEndSelect);

						UpdateViewWithCursor();
					}

				}
				else mActionMouseTimer = 0;

				while (mActionMouseTimer > EDIT_ACTION_MOUSE_TIMER) mActionMouseTimer -= EDIT_ACTION_MOUSE_TIMER;
			}

		} // if (mMouseLeftPressed)
	}

	void Edit::SetTextCursor(size_t index)
	{
		ResetSelect();

		if (index > mTextLength) index = mTextLength;
		if (mCursorPosition == index) return;
		mCursorPosition = index;

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();
	}

	void Edit::SetTextSelection(size_t start, size_t end)
	{
		if (start > mTextLength) start = mTextLength;
		if (end > mTextLength) end = mTextLength;

		mStartSelect = start;
		mEndSelect = end;

		if (mText != nullptr)
		{
			if (mStartSelect > mEndSelect) mText->SetTextSelection(mEndSelect, mStartSelect);
			else mText->SetTextSelection(mStartSelect, mEndSelect);
		}

		if (mCursorPosition == mEndSelect) return;
		mCursorPosition = mEndSelect;

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
	}

	bool Edit::DeleteTextSelect(bool history)
	{
		if ( ! IsTextSelection()) return false;

		size_t start = GetTextSelectionStart();
		size_t end =  GetTextSelectionEnd();

		eraseText(start, end - start, history);

		return true;
	}

	void Edit::ResetSelect()
	{
		if (mStartSelect != ITEM_NONE)
		{
			mStartSelect = ITEM_NONE;
			if (mText != nullptr)
				mText->SetTextSelection(0, 0);
		}
	}

	void Edit::CommandPosition(size_t undo, size_t redo, size_t length, VectorChangeInfo * info)
	{
		if (info != nullptr) info->push_back(TextCommandInfo(undo, redo, length));
	}

	void Edit::CommandMerge()
	{
		if (mVectorUndoChangeInfo.size() < 2) return; 
		VectorChangeInfo info = mVectorUndoChangeInfo.back();
		mVectorUndoChangeInfo.pop_back();

		for (VectorChangeInfo::iterator iter=info.begin(); iter!=info.end(); ++iter)
		{
			mVectorUndoChangeInfo.back().push_back((*iter));
		}
	}

	bool Edit::CommandUndo()
	{
		if (mVectorUndoChangeInfo.empty()) return false;

		ResetSelect();

		VectorChangeInfo info = mVectorUndoChangeInfo.back();
		mVectorUndoChangeInfo.pop_back();
		mVectorRedoChangeInfo.push_back(info);

		UString text = GetRealString();

		for (VectorChangeInfo::reverse_iterator iter=info.rbegin(); iter!=info.rend(); iter++)
		{

			if ((*iter).type == TextCommandInfo::COMMAND_INSERT) text.erase((*iter).start, (*iter).text.size());
			else if ((*iter).type == TextCommandInfo::COMMAND_ERASE) text.insert((*iter).start, (*iter).text);
			else
			{
				mCursorPosition = (*iter).undo;
				mTextLength = (*iter).length;
			}
		}

		SetRealString(text);

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();

		eventEditTextChange(this);

		return true;
	}

	bool Edit::CommandRedo()
	{
		if (mVectorRedoChangeInfo.empty()) return false;

		ResetSelect();

		VectorChangeInfo info = mVectorRedoChangeInfo.back();
		mVectorRedoChangeInfo.pop_back();
		mVectorUndoChangeInfo.push_back(info);

		UString text = GetRealString();

		for (VectorChangeInfo::iterator iter=info.begin(); iter!=info.end(); ++iter)
		{

			if ((*iter).type == TextCommandInfo::COMMAND_INSERT) text.insert((*iter).start, (*iter).text);
			else if ((*iter).type == TextCommandInfo::COMMAND_ERASE) text.erase((*iter).start, (*iter).text.size());
			else
			{
				mCursorPosition = (*iter).redo;
				mTextLength = (*iter).length;
			}

		}

		SetRealString(text);

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();

		eventEditTextChange(this);

		return true;
	}

	void Edit::SaveInHistory(VectorChangeInfo * info)
	{
		if (info == nullptr) return;
		if ( info->empty() ) return;
		if ( (info->size() == 1) && (info->back().type == TextCommandInfo::COMMAND_POSITION)) return;

		mVectorUndoChangeInfo.push_back(*info);
		if (mVectorUndoChangeInfo.size() > EDIT_MAX_UNDO)
			mVectorUndoChangeInfo.pop_front();
	}

	UString Edit::GetTextInterval(size_t start, size_t count)
	{
		if (start > mTextLength) start = mTextLength;
		size_t end = start + count;

		TextIterator iterator(GetRealString());

		UString colour = mText == nullptr ? "" : TextIterator::ConvertTagColour(mText->GetTextColour());

		bool need_colour = true;

		while (iterator.MoveNext())
		{
			size_t pos = iterator.GetPosition();

			if (pos < start)
			{
				iterator.GetTagColour(colour);

				continue;
			}

			else if (pos == start)
			{
				need_colour = ! iterator.GetTagColour(colour);
				iterator.SaveStartPoint();

			}

			else if (pos == end) break;

		}

		if (need_colour) return colour + iterator.GetFromStart();
		return iterator.GetFromStart();
	}

	void Edit::_setTextColour(size_t start, size_t count, const Colour& colour, bool history)
	{
		CommandResetRedo();

		VectorChangeInfo * curHistory = nullptr;
		if (history) curHistory = new VectorChangeInfo();

		size_t end = start + count;

		TextIterator iterator(GetRealString(), curHistory);

		UString curColour = mText == nullptr ? "" : TextIterator::ConvertTagColour(mText->GetTextColour());

		while (iterator.MoveNext())
		{

			size_t pos = iterator.GetPosition();

			iterator.GetTagColour(curColour);

			if (pos < start) continue;

			else if (pos == start)
				iterator.SetTagColour(colour);

			else if (pos < end)
				iterator.ClearTagColour();

			else if (pos == end)
			{
				iterator.SetTagColour(curColour);
				break;
			}

		}

		CommandPosition(start, start+count, mTextLength, curHistory);

		if (history)
		{
			SaveInHistory(curHistory);
			delete curHistory;
		}
		else CommandResetHistory();

		SetRealString(iterator.GetText());

	}

	void Edit::SetTextSelectColour(const Colour& colour, bool history)
	{
		if ( !IsTextSelection()) return;
		size_t start = GetTextSelectionStart();
		size_t end =  GetTextSelectionEnd();
		_setTextColour(start, end-start, colour, history);
	}

	UString Edit::GetTextSelection()
	{
		if ( !IsTextSelection()) return "";
		size_t start = GetTextSelectionStart();
		size_t end =  GetTextSelectionEnd();
		return GetTextInterval(start, end-start);
	}

	void Edit::SetEditPassword(bool password)
	{
		if (mModePassword == password) return;
		mModePassword = password;
		if (mModePassword)
		{
			if (mText != nullptr)
			{
				mPasswordText = mText->GetCaption();
				mText->SetCaption(UString(mTextLength, '*'));
			}
		}
		else
		{
			if (mText != nullptr)
			{
				mText->SetCaption(mPasswordText);
				mPasswordText.clear();
			}
		}
		UpdateView();
		CommandResetHistory();
	}

	void Edit::SetText(const UString& caption, bool history)
	{
		ResetSelect();

		VectorChangeInfo * curHistory = nullptr;
		if (history) curHistory = new VectorChangeInfo();

		TextIterator iterator(GetRealString(), curHistory);

		iterator.SetText(caption, mModeMultiline || mModeWordWrap);

		if (mOverflowToTheLeft)
		{
			iterator.CutMaxLengthFromBeginning(mMaxTextLength);
		}
		else
		{
			iterator.CutMaxLength(mMaxTextLength);
		}

		size_t old = mTextLength;
		mCursorPosition = mTextLength = iterator.GetSize();

		CommandPosition(0, mTextLength, old, curHistory);

		if (history)
		{
			SaveInHistory(curHistory);
			delete curHistory;
		}
		else CommandResetHistory();

		SetRealString(iterator.GetText());

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();
	}

	void Edit::InsertText(const UString& text, size_t start, bool history)
	{
		ResetSelect();

		if (text.empty()) return;

		if ((mOverflowToTheLeft == false) && (mTextLength == mMaxTextLength)) return;

		VectorChangeInfo * curHistory = nullptr;
		if (history) curHistory = new VectorChangeInfo();

		TextIterator iterator(GetRealString(), curHistory);

		UString colour = mText == nullptr ? "" : TextIterator::ConvertTagColour(mText->GetTextColour());
		bool need_colour = ( (text.size() > 6) && (text[0] == L'#') && (text[1] != L'#') );

		while (iterator.MoveNext())
		{

			size_t pos = iterator.GetPosition();

			if (need_colour) iterator.GetTagColour(colour);

			if (pos == start) break;

		}

		if (need_colour) iterator.SetTagColour(colour);

		iterator.InsertText(text, mModeMultiline || mModeWordWrap);

		if (mOverflowToTheLeft)
		{
			iterator.CutMaxLengthFromBeginning(mMaxTextLength);
		}
		else
		{
			iterator.CutMaxLength(mMaxTextLength);
		}

		size_t old = mTextLength;
		mTextLength = iterator.GetSize();
		mCursorPosition += mTextLength - old;

		CommandPosition(start, start + mTextLength - old, old, curHistory);

		if (history)
		{
			SaveInHistory(curHistory);
			delete curHistory;
		}
		else CommandResetHistory();

		SetRealString(iterator.GetText());

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();
	}

	void Edit::eraseText(size_t start, size_t count, bool history)
	{
		if (count == 0) return;

		ResetSelect();

		VectorChangeInfo * curHistory = nullptr;
		if (history) curHistory = new VectorChangeInfo();

		TextIterator iterator(GetRealString(), curHistory);

		UString colour;
		size_t end = start + count;
		bool need_colour = false;

		while (iterator.MoveNext())
		{

			size_t pos = iterator.GetPosition();

			if (pos < start)
			{
				iterator.GetTagColour(colour);
				continue;
			}

			else if (pos == start)
			{
				if ( ! colour.empty())
				{
					need_colour = true;
					colour.clear();
				}
				iterator.GetTagColour(colour);
				iterator.SaveStartPoint();
			}

			else if (pos < end)
			{
				iterator.GetTagColour(colour);
			}

			else if (pos == end)
			{
				if ( ! colour.empty()) need_colour = true;
				if ( iterator.GetTagColour(colour)) need_colour = false;

				break;
			}

		}

		iterator.EraseFromStart();
		if (need_colour) iterator.SetTagColour(colour);

		CommandPosition(start + count, start, mTextLength, curHistory);

		mCursorPosition = start;
		mTextLength -= count;

		if (history)
		{
			SaveInHistory(curHistory);
			delete curHistory;
		}
		else CommandResetHistory();

		SetRealString(iterator.GetText());

		if (mText != nullptr)
			mText->SetCursorPosition(mCursorPosition);
		UpdateSelectText();
	}

	void Edit::CommandCut()
	{
		if ( IsTextSelection() && (!mModePassword) )
		{
			ClipboardManager::GetInstance().SetClipboardData(EDIT_CLIPBOARD_TYPE_TEXT, GetTextSelection());
			if (!mModeReadOnly)
			{
				DeleteTextSelect(true);
				eventEditTextChange(this);
			}
		}
		else ClipboardManager::GetInstance().ClearClipboardData(EDIT_CLIPBOARD_TYPE_TEXT);
	}

	void Edit::CommandCopy()
	{
		if ( IsTextSelection() && (!mModePassword) ) ClipboardManager::GetInstance().SetClipboardData(EDIT_CLIPBOARD_TYPE_TEXT, GetTextSelection());
		else ClipboardManager::GetInstance().ClearClipboardData(EDIT_CLIPBOARD_TYPE_TEXT);
	}

	void Edit::CommandPast()
	{
		std::string clipboard = ClipboardManager::GetInstance().GetClipboardData(EDIT_CLIPBOARD_TYPE_TEXT);
		if ( (!mModeReadOnly) && ( !clipboard.empty()) )
		{
			size_t size = mVectorUndoChangeInfo.size();
			DeleteTextSelect(true);
			InsertText(clipboard, mCursorPosition, true);
			if ((size+2) == mVectorUndoChangeInfo.size()) CommandMerge();
			eventEditTextChange(this);
		}
	}

	const UString& Edit::GetRealString()
	{
		if (mModePassword) return mPasswordText;
		else if (mText == nullptr) return mPasswordText;

		return mText->GetCaption();
	}

	void Edit::SetRealString(const UString& caption)
	{
		if (mModePassword)
		{
			mPasswordText = caption;
			if (mText != nullptr)
				mText->SetCaption(UString(mTextLength, mCharPassword));
		}
		else
		{
			if (mText != nullptr)
				mText->SetCaption(caption);
		}
	}

	void Edit::SetPasswordChar(Char _char)
	{
		mCharPassword = _char;
		if (mModePassword)
		{
			if (mText != nullptr)
				mText->SetCaption(UString(mTextLength, mCharPassword));
		}
	}

	void Edit::UpdateEditState()
	{
		if (!mEnabled) SetState("disabled");
		else if (mIsPressed)
		{
			if (mIsFocus) SetState("pushed");
			else SetState("normal_checked");
		}
		else if (mIsFocus) SetState("highlighted");
		else SetState("normal");
	}

	void Edit::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void Edit::eraseView()
	{
		if (mModeWordWrap)
		{
			if (mText != nullptr)
				mText->SetWordWrap(true);
		}

		UpdateView();
	}

	void Edit::SetSize(const IntSize& size)
	{
		Base::SetSize(size);

		eraseView();
	}

	void Edit::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);

		eraseView();
	}

	void Edit::SetCaption(const UString& value)
	{
		SetText(value, false);
	}

	const UString& Edit::GetCaption()
	{
		return GetRealString();
	}

	void Edit::UpdateSelectText()
	{
		if (!mModeStatic)
		{

			InputManager& input = InputManager::GetInstance();
			if ( (input.IsShiftPressed()) && (mStartSelect != ITEM_NONE) )
			{
				mEndSelect = (size_t)mCursorPosition;
				if (mText != nullptr)
				{
					if (mStartSelect > mEndSelect) mText->SetTextSelection(mEndSelect, mStartSelect);
					else mText->SetTextSelection(mStartSelect, mEndSelect);
				}

			}
			else if (mStartSelect != ITEM_NONE)
			{
				mStartSelect = ITEM_NONE;
				if (mText != nullptr)
					mText->SetTextSelection(0, 0);
			}
		}

		UpdateViewWithCursor();
	}

	void Edit::SetTextAlign(Align align)
	{
		Base::SetTextAlign(align);

		UpdateView();
	}

	void Edit::NotifyScrollChangePosition(VScroll* sender, size_t position)
	{
		if (mText == nullptr)
			return;

		if (sender == mVScroll)
		{
			IntPoint point = mText->GetViewOffset();
			point.top = position;
			mText->SetViewOffset(point);
		}
		else if (sender == mHScroll)
		{
			IntPoint point = mText->GetViewOffset();
			point.left = position;
			mText->SetViewOffset(point);
		}
	}

	void Edit::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mText == nullptr)
			return;

		if (mVRange != 0)
		{
			IntPoint point = mText->GetViewOffset();
			int offset = point.top;
			if (rel < 0) offset += EDIT_MOUSE_WHEEL;
			else  offset -= EDIT_MOUSE_WHEEL;

			if (offset < 0) offset = 0;
			else if (offset > (int)mVRange) offset = mVRange;

			if (offset != point.top)
			{
				point.top = offset;
				if (mVScroll != nullptr)
					mVScroll->SetScrollPosition(offset);
				mText->SetViewOffset(point);
			}
		}
		else if (mHRange != 0)
		{
			IntPoint point = mText->GetViewOffset();
			int offset = point.left;
			if (rel < 0) offset += EDIT_MOUSE_WHEEL;
			else  offset -= EDIT_MOUSE_WHEEL;

			if (offset < 0) offset = 0;
			else if (offset > (int)mHRange) offset = mHRange;

			if (offset != point.left)
			{
				point.left = offset;
				if (mHScroll != nullptr)
					mHScroll->SetScrollPosition(offset);
				mText->SetViewOffset(point);
			}
		}
	}

	void Edit::SetEditWordWrap(bool value)
	{
		mModeWordWrap = value;
		if (mText != nullptr)
			mText->SetWordWrap(mModeWordWrap);

		eraseView();
	}

	void Edit::SetFontName(const std::string& value)
	{
		Base::SetFontName(value);

		eraseView();
	}

	void Edit::SetFontHeight(int value)
	{
		Base::SetFontHeight(value);

		eraseView();
	}

	void Edit::UpdateView()
	{
		UpdateScrollSize();
		UpdateScrollPosition();
	}

	void Edit::UpdateViewWithCursor()
	{
		UpdateScrollSize();
		UpdateCursorPosition();
		UpdateScrollPosition();
	}

	void Edit::UpdateCursorPosition()
	{
		if (mText == nullptr || mWidgetClient == nullptr)
			return;

		IntSize textSize = mText->GetTextSize();

		IntPoint point = mText->GetViewOffset();
		IntPoint offset = point;

		IntRect cursor = mText->GetCursorRect(mCursorPosition);
		cursor.right ++;

		const IntRect& view = mWidgetClient->GetAbsoluteRect();

		if (!view.Inside(cursor))
		{
			// FIXME проверить, помоему просто >
			if (textSize.width >= view.Width())
			{
				if (cursor.left < view.left)
				{
					offset.left = point.left - (view.left - cursor.left);
					if ((float(view.Width()) - EDIT_OFFSET_HORZ_CURSOR) > EDIT_OFFSET_HORZ_CURSOR) offset.left -= int(EDIT_OFFSET_HORZ_CURSOR);
				}
				else if (cursor.right > view.right)
				{
					offset.left = point.left + (cursor.right - view.right);
					if ((float(view.Width()) - EDIT_OFFSET_HORZ_CURSOR) > EDIT_OFFSET_HORZ_CURSOR) offset.left += int(EDIT_OFFSET_HORZ_CURSOR);
				}
			}

			if (textSize.height >= view.Height())
			{
				if (cursor.top < view.top)
				{
					offset.top = point.top - (view.top - cursor.top);
				}
				else if (cursor.bottom > view.bottom)
				{
					offset.top = point.top + (cursor.bottom - view.bottom);
				}
			}

		}

		if (offset != point)
		{
			mText->SetViewOffset(offset);
			if (mVScroll != nullptr)
				mVScroll->SetScrollPosition(offset.top);
			if (mHScroll != nullptr)
				mHScroll->SetScrollPosition(offset.left);
		}
	}

	void Edit::SetContentPosition(const IntPoint& point)
	{
		if (mText != nullptr)
			mText->SetViewOffset(point);
	}

	IntSize Edit::GetViewSize() const
	{
		return mWidgetClient == nullptr ? GetSize() : mWidgetClient->GetSize();
	}

	IntSize Edit::GetContentSize()
	{
		return mText == nullptr ? IntSize() : mText->GetTextSize();
	}

	size_t Edit::GetVScrollPage()
	{
		return (size_t)GetFontHeight();
	}

	size_t Edit::GetHScrollPage()
	{
		return (size_t)GetFontHeight();
	}

	IntPoint Edit::GetContentPosition()
	{
		return mText == nullptr ? IntPoint() : mText->GetViewOffset();
	}

	Align Edit::GetContentAlign()
	{
		return mText == nullptr ? Align::Default : mText->GetTextAlign();
	}

	void Edit::SetTextIntervalColour(size_t start, size_t count, const Colour& colour)
	{
		_setTextColour(start, count, colour, false);
	}

	size_t Edit::GetTextSelectionStart()
	{
		return (mStartSelect == ITEM_NONE) ? ITEM_NONE : (mStartSelect > mEndSelect ? mEndSelect : mStartSelect);
	}

	size_t Edit::GetTextSelectionEnd()
	{
		return (mStartSelect == ITEM_NONE) ? ITEM_NONE : (mStartSelect > mEndSelect ? mStartSelect : mEndSelect);
	}

	bool Edit::IsTextSelection()
	{
		return ( (mStartSelect != ITEM_NONE) && (mStartSelect != mEndSelect) );
	}

	void Edit::DeleteTextSelection()
	{
		DeleteTextSelect(false);
	}

	void Edit::SetTextSelectionColour(const Colour& colour)
	{
		SetTextSelectColour(colour, false);
	}

	size_t Edit::GetTextSelectionLength()
	{
		return mEndSelect - mStartSelect;
	}

	void Edit::SetOnlyText(const UString& text)
	{
		SetText(TextIterator::ToTagsString(text), false);
	}

	UString Edit::GetOnlyText()
	{
		return TextIterator::GetOnlyText(GetRealString());
	}

	void Edit::InsertText(const UString& text, size_t index)
	{
		InsertText(text, index, false);
	}

	void Edit::AddText(const UString& text)
	{
		InsertText(text, ITEM_NONE, false);
	}

	void Edit::eraseText(size_t start, size_t count)
	{
		eraseText(start, count, false);
	}

	void Edit::SetEditReadOnly(bool read)
	{
		mModeReadOnly = read;
		CommandResetHistory();
	}

	void Edit::SetEditMultiLine(bool multi)
	{
		mModeMultiline = multi;
		if (!mModeMultiline)
		{
			SetText(GetRealString(), false);
		}
		else UpdateView();
		CommandResetHistory();
	}

	void Edit::SetEditStatic(bool _static)
	{
		mModeStatic = _static;
		ResetSelect();

		if (mWidgetClient != nullptr)
		{
			if (mModeStatic) mWidgetClient->SetPointer("");
			else mWidgetClient->SetPointer(mOriginalPointer);
		}
	}

	void Edit::SetPasswordChar(const UString& _char)
	{
		if (!_char.empty()) SetPasswordChar(_char[0]);
	}

	void Edit::SetVisibleVScroll(bool value)
	{
		mVisibleVScroll = value;
		UpdateView();
	}

	void Edit::SetVisibleHScroll(bool value)
	{
		mVisibleHScroll = value;
		UpdateView();
	}

	void Edit::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "Edit_CursorPosition") SetTextCursor(utility::ParseValue<size_t>(value));
		else if (key == "Edit_TextSelect") SetTextSelection(utility::ParseValue< types::TSize<size_t> >(value).width, utility::ParseValue< types::TSize<size_t> >(value).height);
		else if (key == "Edit_ReadOnly") SetEditReadOnly(utility::ParseValue<bool>(value));
		else if (key == "Edit_Password") SetEditPassword(utility::ParseValue<bool>(value));
		else if (key == "Edit_MultiLine") SetEditMultiLine(utility::ParseValue<bool>(value));
		else if (key == "Edit_PasswordChar") SetPasswordChar(value);
		else if (key == "Edit_MaxTextLength") SetMaxTextLength(utility::ParseValue<size_t>(value));
		else if (key == "Edit_OverflowToTheLeft") SetOverflowToTheLeft(utility::ParseValue<bool>(value));
		else if (key == "Edit_Static") SetEditStatic(utility::ParseValue<bool>(value));
		else if (key == "Edit_VisibleVScroll") SetVisibleVScroll(utility::ParseValue<bool>(value));
		else if (key == "Edit_VisibleHScroll") SetVisibleHScroll(utility::ParseValue<bool>(value));
		else if (key == "Edit_WordWrap") SetEditWordWrap(utility::ParseValue<bool>(value));
		else if (key == "Edit_TabPrinting") SetTabPrinting(utility::ParseValue<bool>(value));
		else if (key == "Edit_InvertSelected") SetInvertSelected(utility::ParseValue<bool>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

	size_t Edit::GetVScrollRange()
	{
		return mVRange + 1;
	}

	size_t Edit::GetVScrollPosition()
	{
		return mText == nullptr ? 0 : mText->GetViewOffset().top;
	}

	void Edit::SetVScrollPosition(size_t index)
	{
		if (mText == nullptr)
			return;

		if (index > mVRange)
			index = mVRange;

		IntPoint point = mText->GetViewOffset();
		point.top = index;

		mText->SetViewOffset(point);
		if (mVScroll != nullptr)
			mVScroll->SetScrollPosition(point.top);
	}

	size_t Edit::GetHScrollRange()
	{
		return mHRange + 1;
	}

	size_t Edit::GetHScrollPosition()
	{
		return mText == nullptr ? 0 : mText->GetViewOffset().left;
	}

	void Edit::SetHScrollPosition(size_t index)
	{
		if (mText == nullptr)
			return;

		if (index > mHRange)
			index = mHRange;

		IntPoint point = mText->GetViewOffset();
		point.left = index;

		mText->SetViewOffset(point);
		if (mHScroll != nullptr)
			mHScroll->SetScrollPosition(point.left);
	}

	bool Edit::GetInvertSelected()
	{
		return mText == nullptr ? false : mText->GetInvertSelected();
	}

	void Edit::SetInvertSelected(bool value)
	{
		if (mText != nullptr)
			mText->SetInvertSelected(value);
	}

} // namespace GUI


