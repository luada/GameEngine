#include "Precompiled.h"
#include "List.h"
#include "Button.h"
#include "VScroll.h"
#include "ResourceSkin.h"
#include "InputManager.h"

namespace GUI
{

	List::List() :
		mWidgetScroll(nullptr),
		mHeightLine(1),
		mTopIndex(0),
		mOffsetTop(0),
		mRangeIndex(-1),
		mLastRedrawLine(0),
		mIndexSelect(ITEM_NONE),
		mLineActive(ITEM_NONE),
		mIsFocus(false),
		mNeedVisibleScroll(true)
	{
	}

	void List::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	List::~List()
	{
		ShutdownWidgetSkin();
	}

	void List::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void List::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mNeedKeyFocus = true;

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "VScroll")
			{
				DEBUG_ASSERT( ! mWidgetScroll, "widget already assigned");
				mWidgetScroll = (*iter)->CastType<VScroll>();
				mWidgetScroll->eventScrollChangePosition = NewDelegate(this, &List::NotifyScrollChangePosition);
				mWidgetScroll->eventMouseButtonPressed = NewDelegate(this, &List::NotifyMousePressed);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mWidgetClient, "widget already assigned");
				mWidgetClient = (*iter);
				mWidgetClient->eventMouseButtonPressed = NewDelegate(this, &List::NotifyMousePressed);
			}
		}
		//ASSERT(nullptr != mWidgetScroll, "Child VScroll not found in Skin (List must have VScroll)");
		//ASSERT(nullptr != mWidgetClient, "Child Widget Client not found in Skin (List must have Client)");

		const MapString& properties = info->GetProperties();
		MapString::const_iterator iterS = properties.find("SkinLine");
		if (iterS != properties.end()) mSkinLine = iterS->second;
		//ASSERT(!mSkinLine.empty(), "SkinLine property not Found (List must have SkinLine property)");

		iterS = properties.find("HeightLine");
		if (iterS != properties.end()) mHeightLine = utility::ParseInt(iterS->second);
		if (mHeightLine < 1) mHeightLine = 1;


		if (mWidgetScroll != nullptr)
		{
			mWidgetScroll->SetScrollPage((size_t)mHeightLine);
			mWidgetScroll->SetScrollViewPage((size_t)mHeightLine);
		}

		UpdateScroll();
		UpdateLine();
	}

	void List::ShutdownWidgetSkin()
	{
		mWidgetScroll = nullptr;
		mWidgetClient = nullptr;
	}

	void List::OnMouseWheel(int rel)
	{
		NotifyMouseWheel(nullptr, rel);

		Base::OnMouseWheel(rel);
	}

	void List::OnKeySetFocus(Widget* old)
	{
		mIsFocus = true;
		_updateState();

		Base::OnKeySetFocus(old);
	}

	void List::OnKeyLostFocus(Widget* _new)
	{
		mIsFocus = false;
		_updateState();

		Base::OnKeyLostFocus(_new);
	}

	void List::OnKeyButtonPressed(KeyCode key, Char _char)
	{
		if (GetItemCount() == 0)
		{
			Base::OnKeyButtonPressed(key, _char);
			return;
		}

		size_t sel = mIndexSelect;

		if (key == KeyCode::ArrowUp)
		{
			if (sel != 0)
			{
				if (sel == ITEM_NONE) sel = 0;
				else sel --;
			}

		}
		else if (key == KeyCode::ArrowDown)
		{
			if (sel == ITEM_NONE) sel = 0;
			else sel ++;

			if (sel >= GetItemCount())
			{
				sel = mIndexSelect;
			}

		}
		else if (key == KeyCode::Home)
		{
			if (sel != 0) sel = 0;

		}
		else if (key == KeyCode::End)
		{
			if (sel != (GetItemCount() - 1))
			{
				sel = GetItemCount() - 1;
			}

		}
		else if (key == KeyCode::PageUp)
		{
			if (sel != 0)
			{
				if (sel == ITEM_NONE) sel = 0;
				else
				{
					size_t page = _getClientWidget()->GetHeight() / mHeightLine;
					if (sel <= page) sel = 0;
					else sel -= page;
				}
			}

		}
		else if (key == KeyCode::PageDown)
		{
			if (sel != (GetItemCount() - 1))
			{
				if (sel == ITEM_NONE) sel = 0;
				else
				{
					sel += _getClientWidget()->GetHeight() / mHeightLine;
					if (sel >= GetItemCount()) sel = GetItemCount() - 1;
				}
			}

		}
		else if ((key == KeyCode::Return) || (key == KeyCode::NumpadEnter))
		{
			if (sel != ITEM_NONE)
			{
				//FIXME 
				eventListSelectAccept(this, sel);

				Base::OnKeyButtonPressed(key, _char);
				return;
			}

		}

		if (sel != mIndexSelect)
		{
			if ( !IsItemVisibleAt(sel))
			{
				BeginToItemAt(sel);
				if (mWidgetScroll != nullptr)
					_sendEventChangeScroll(mWidgetScroll->GetScrollPosition());
			}
			SetIndexSelected(sel);

			// FIXME
			eventListChangePosition(this, mIndexSelect);
		}

		Base::OnKeyButtonPressed(key, _char);
	}

	void List::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mRangeIndex <= 0)
			return;

		if (mWidgetScroll == nullptr)
			return;

		int offset = (int)mWidgetScroll->GetScrollPosition();
		if (rel < 0) offset += mHeightLine;
		else  offset -= mHeightLine;

		if (offset >= mRangeIndex) offset = mRangeIndex;
		else if (offset < 0) offset = 0;

		if ((int)mWidgetScroll->GetScrollPosition() == offset) return;

		mWidgetScroll->SetScrollPosition(offset);
		_setScrollView(offset);
		_sendEventChangeScroll(offset);
	}

	void List::NotifyScrollChangePosition(VScroll* sender, size_t position)
	{
		_setScrollView(position);
		_sendEventChangeScroll(position);
	}

	void List::NotifyMousePressed(Widget* sender, int left, int top, MouseButton id)
	{
		if (MouseButton::Left != id)
			return;

		if (sender == mWidgetScroll)
			return;

		if (sender == _getClientWidget())
		{
			if (mIndexSelect != ITEM_NONE)
			{
				_selectIndex(mIndexSelect, false);
				mIndexSelect = ITEM_NONE;
				eventListChangePosition(this, mIndexSelect);
			}
			eventListMouseItemActivate(this, mIndexSelect);

		}
		else if (sender->IsVisible())
		{

#if DEBUG_MODE == 1
			_checkMapping("List::NotifyMousePressed");
			ASSERT_RANGE(*sender->_getInternalData<size_t>(), mWidgetLines.size(), "List::NotifyMousePressed");
			ASSERT_RANGE(*sender->_getInternalData<size_t>() + mTopIndex, mItemsInfo.size(), "List::NotifyMousePressed");
#endif

			size_t index = *sender->_getInternalData<size_t>() + mTopIndex;

			if (mIndexSelect != index)
			{
				_selectIndex(mIndexSelect, false);
				_selectIndex(index, true);
				mIndexSelect = index;
				eventListChangePosition(this, mIndexSelect);
			}
			eventListMouseItemActivate(this, mIndexSelect);

		}
	}

	void List::NotifyMouseDoubleClick(Widget* sender)
	{
		if (mIndexSelect != ITEM_NONE)
			eventListSelectAccept(this, mIndexSelect);
	}

	void List::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void List::SetSize(const IntSize& size)
	{
		Base::SetSize(size);

		UpdateScroll();
		UpdateLine();
	}

	void List::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);

		UpdateScroll();
		UpdateLine();
	}

	void List::UpdateScroll()
	{
		mRangeIndex = (mHeightLine * (int)mItemsInfo.size()) - _getClientWidget()->GetHeight();

		if (mWidgetScroll == nullptr)
			return;

		if ( (!mNeedVisibleScroll) || (mRangeIndex < 1) || (mWidgetScroll->GetLeft() <= _getClientWidget()->GetLeft()) )
		{
			if (mWidgetScroll->IsVisible())
			{
				mWidgetScroll->SetVisible(false);
				if (mWidgetClient != nullptr)
					mWidgetClient->SetSize(mWidgetClient->GetWidth() + mWidgetScroll->GetWidth(), mWidgetClient->GetHeight());
			}
		}
		else if (!mWidgetScroll->IsVisible())
		{
			if (mWidgetClient != nullptr)
				mWidgetClient->SetSize(mWidgetClient->GetWidth() - mWidgetScroll->GetWidth(), mWidgetClient->GetHeight());
			mWidgetScroll->SetVisible(true);
		}

		mWidgetScroll->SetScrollRange(mRangeIndex + 1);
		if ((int)mItemsInfo.size()) mWidgetScroll->SetTrackSize( mWidgetScroll->GetLineSize() * _getClientWidget()->GetHeight() / mHeightLine / (int)mItemsInfo.size() );
	}

	void List::UpdateLine(bool reset)
	{
		if (reset)
		{
			mOldSize.Clear();
			mLastRedrawLine = 0;
		}

		int position = mTopIndex * mHeightLine + mOffsetTop;

		if (mOldSize.height < mCoord.height)
		{
			int height = (int)mWidgetLines.size() * mHeightLine - mOffsetTop;

			while ( (height <= (_getClientWidget()->GetHeight() + mHeightLine)) && (mWidgetLines.size() < mItemsInfo.size()) )
			{
				Widget* line = _getClientWidget()->CreateWidgetT("Button", mSkinLine, 0, height, _getClientWidget()->GetWidth(), mHeightLine, Align::Top | Align::HStretch);
				line->eventMouseButtonPressed = NewDelegate(this, &List::NotifyMousePressed);
				line->eventMouseButtonDoubleClick = NewDelegate(this, &List::NotifyMouseDoubleClick);
				line->eventMouseWheel = NewDelegate(this, &List::NotifyMouseWheel);
				line->eventMouseSetFocus = NewDelegate(this, &List::NotifyMouseSetFocus);
				line->eventMouseLostFocus = NewDelegate(this, &List::NotifyMouseLostFocus);
				line->_setInternalData((size_t)mWidgetLines.size());
				mWidgetLines.push_back(line);
				height += mHeightLine;
			}

			if (position >= mRangeIndex)
			{
				if (mRangeIndex <= 0)
				{
					if (position || mOffsetTop || mTopIndex)
					{
						position = 0;
						mTopIndex = 0;
						mOffsetTop = 0;
						mLastRedrawLine = 0; 

						int offset = 0;
						for (size_t pos=0; pos<mWidgetLines.size(); pos++)
						{
							mWidgetLines[pos]->SetPosition(0, offset);
							offset += mHeightLine;
						}
					}

				}
				else
				{
					int count = _getClientWidget()->GetHeight() / mHeightLine;
					mOffsetTop = mHeightLine - (_getClientWidget()->GetHeight() % mHeightLine);

					if (mOffsetTop == mHeightLine)
					{
						mOffsetTop = 0;
						count --;
					}

					int top = (int)mItemsInfo.size() - count - 1;

					int offset = 0 - mOffsetTop;
					for (size_t pos=0; pos<mWidgetLines.size(); pos++)
					{
						mWidgetLines[pos]->SetPosition(0, offset);
						offset += mHeightLine;
					}

					position = top * mHeightLine + mOffsetTop;

					if (top != mTopIndex)
					{
						mTopIndex = top;
						_redrawItemRange();
					}

				}
			}

			_redrawItemRange(mLastRedrawLine);

		} // if (old_cy < mCoord.height)

		if (mWidgetScroll != nullptr)
			mWidgetScroll->SetScrollPosition(position);

		mOldSize.width = mCoord.width;
		mOldSize.height = mCoord.height;

#if DEBUG_MODE == 1
		_checkMapping("List::updateLine");
#endif

	}

	void List::_redrawItemRange(size_t start)
	{
		size_t pos = start;
		for (; pos<mWidgetLines.size(); pos++)
		{
			size_t index = pos + (size_t)mTopIndex;

			if (index >= mItemsInfo.size())
			{
				mLastRedrawLine = pos;
				break;
			}
			if (mWidgetLines[pos]->GetTop() > _getClientWidget()->GetHeight())
			{
				mLastRedrawLine = pos;
				break;
			}

			mWidgetLines[pos]->SetVisible(true);
			mWidgetLines[pos]->SetCaption(mItemsInfo[index].first);

			static_cast<Button*>(mWidgetLines[pos])->SetButtonPressed(index == mIndexSelect);
		}

		if (pos >= mWidgetLines.size()) mLastRedrawLine = pos;
		else
		{
			//Widget* focus = InputManager::GetInstance().GetMouseFocusWidget();
			for (; pos<mWidgetLines.size(); pos++)
			{
				static_cast<Button*>(mWidgetLines[pos])->SetButtonPressed(false);
				static_cast<Button*>(mWidgetLines[pos])->SetVisible(false);
				//if (focus == mWidgetLines[pos]) InputManager::GetInstance()._unlinkWidget(focus);
			}
		}

#if DEBUG_MODE == 1
		_checkMapping("List::_redrawItemRange");
#endif

	}

	void List::_redrawItem(size_t index)
	{
		if (index < (size_t)mTopIndex) return;
		index -= (size_t)mTopIndex;
		if (index >= mLastRedrawLine) return;

		ASSERT_RANGE(index, mItemsInfo.size(), "List::_redrawItem");
		mWidgetLines[index]->SetCaption(mItemsInfo[index + mTopIndex].first);

#if DEBUG_MODE == 1
		_checkMapping("List::_redrawItem");
#endif

	}

	void List::InsertItemAt(size_t index, const UString& name, Any data)
	{
		ASSERT_RANGE_INSERT(index, mItemsInfo.size(), "List::insertItemAt");
		if (index == ITEM_NONE) index = mItemsInfo.size();

		mItemsInfo.insert(mItemsInfo.begin() + index, PairItem(name, data));

		if ( (mIndexSelect != ITEM_NONE) && (index <= mIndexSelect) ) mIndexSelect++;

		if ((index <= (size_t)mTopIndex) && (mRangeIndex > 0))
		{
			mTopIndex ++;
			if (mWidgetScroll != nullptr)
			{
				mWidgetScroll->SetScrollRange(mWidgetScroll->GetScrollRange() + mHeightLine);
				if ((int)mItemsInfo.size()) mWidgetScroll->SetTrackSize( mWidgetScroll->GetLineSize() * _getClientWidget()->GetHeight() / mHeightLine / (int)mItemsInfo.size() );
				mWidgetScroll->SetScrollPosition(mTopIndex * mHeightLine + mOffsetTop);
			}
			mRangeIndex += mHeightLine;
		}
		else
		{
			int offset = ((int)index - mTopIndex) * mHeightLine - mOffsetTop;

			if (_getClientWidget()->GetHeight() < (offset - mHeightLine))
			{
				if (mWidgetScroll != nullptr)
				{
					mWidgetScroll->SetScrollRange(mWidgetScroll->GetScrollRange() + mHeightLine);
					if ((int)mItemsInfo.size()) mWidgetScroll->SetTrackSize( mWidgetScroll->GetLineSize() * _getClientWidget()->GetHeight() / mHeightLine / (int)mItemsInfo.size() );
					mWidgetScroll->SetScrollPosition(mTopIndex * mHeightLine + mOffsetTop);
				}
				mRangeIndex += mHeightLine;

			}
			else
			{
				UpdateScroll();
				UpdateLine(true);

			}
		}

#if DEBUG_MODE == 1
		_checkMapping("List::insertItemAt");
#endif

	}

	void List::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "List::removeItemAt");

		mItemsInfo.erase(mItemsInfo.begin() + index);

		if (mItemsInfo.empty()) mIndexSelect = ITEM_NONE;
		else if (mIndexSelect != ITEM_NONE)
		{
			if (index < mIndexSelect) mIndexSelect--;
			else if ( (index == mIndexSelect) && (mIndexSelect == (mItemsInfo.size())) ) mIndexSelect--;
		}

		if (mWidgetLines.size() > mItemsInfo.size())
		{
			mWidgetLines[mItemsInfo.size()]->SetVisible(false);
		}

		if (index < (size_t)mTopIndex)
		{
			mTopIndex --;
			if (mWidgetScroll != nullptr)
			{
				mWidgetScroll->SetScrollRange(mWidgetScroll->GetScrollRange() - mHeightLine);
				if ((int)mItemsInfo.size()) mWidgetScroll->SetTrackSize( mWidgetScroll->GetLineSize() * _getClientWidget()->GetHeight() / mHeightLine / (int)mItemsInfo.size() );
				mWidgetScroll->SetScrollPosition(mTopIndex * mHeightLine + mOffsetTop);
			}
			mRangeIndex -= mHeightLine;
		}
		else
		{
			int offset = ((int)index - mTopIndex) * mHeightLine - mOffsetTop;

			if (_getClientWidget()->GetHeight() < offset)
			{
				if (mWidgetScroll != nullptr)
				{
					mWidgetScroll->SetScrollRange(mWidgetScroll->GetScrollRange() - mHeightLine);
					if ((int)mItemsInfo.size()) mWidgetScroll->SetTrackSize( mWidgetScroll->GetLineSize() * _getClientWidget()->GetHeight() / mHeightLine / (int)mItemsInfo.size() );
					mWidgetScroll->SetScrollPosition(mTopIndex * mHeightLine + mOffsetTop);
				}
				mRangeIndex -= mHeightLine;

			}
			else
			{
				UpdateScroll();
				UpdateLine(true);

			}
		}

#if DEBUG_MODE == 1
		_checkMapping("List::removeItemAt");
#endif

	}

	void List::SetIndexSelected(size_t index)
	{
		ASSERT_RANGE_AND_NONE(index, mItemsInfo.size(), "List::setIndexSelected");
		if (mIndexSelect != index)
		{
			_selectIndex(mIndexSelect, false);
			_selectIndex(index, true);
			mIndexSelect = index;
		}
	}

	void List::_selectIndex(size_t index, bool select)
	{
		if (index == ITEM_NONE) return;
		if (index < (size_t)mTopIndex) return;
		int offset = ((int)index - mTopIndex) * mHeightLine - mOffsetTop;
		if (_getClientWidget()->GetHeight() < offset) return;

		size_t curIndex = index - mTopIndex;
		if (curIndex < mWidgetLines.size())
			static_cast<Button*>(mWidgetLines[curIndex])->SetButtonPressed(select);

#if DEBUG_MODE == 1
		_checkMapping("List::_selectIndex");
#endif

	}

	void List::BeginToItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "List::beginToItemAt");
		if (mRangeIndex <= 0) return;

		int offset = (int)index * mHeightLine;
		if (offset >= mRangeIndex) offset = mRangeIndex;

		if (mWidgetScroll != nullptr)
		{
			if ((int)mWidgetScroll->GetScrollPosition() == offset) return;
			mWidgetScroll->SetScrollPosition(offset);
		}
		NotifyScrollChangePosition(nullptr, offset);

#if DEBUG_MODE == 1
		_checkMapping("List::beginToItemAt");
#endif

	}

	bool List::IsItemVisibleAt(size_t index, bool fill)
	{
		if (index >= mItemsInfo.size()) return false;
		if (mRangeIndex <= 0) return true;

		if (index < (size_t)mTopIndex) return false;

		if (index == (size_t)mTopIndex)
		{
			if ( (mOffsetTop != 0) && (fill) ) return false; 
			return true;
		}

		int offset = ((int)index - mTopIndex) * mHeightLine - mOffsetTop;

		if (_getClientWidget()->GetHeight() < offset) return false;

		if ((_getClientWidget()->GetHeight() < (offset + mHeightLine)) && (fill) ) return false;

		return true;
	}

	void List::RemoveAllItems()
	{
		mTopIndex = 0;
		mIndexSelect = ITEM_NONE;
		mOffsetTop = 0;

		mItemsInfo.clear();

		int offset = 0;
		for (size_t pos=0; pos<mWidgetLines.size(); pos++)
		{
			mWidgetLines[pos]->SetVisible(false);
			mWidgetLines[pos]->SetPosition(0, offset);
			offset += mHeightLine;
		}

		UpdateScroll();
		UpdateLine(true);

#if DEBUG_MODE == 1
		_checkMapping("List::removeAllItems");
#endif

	}

	void List::SetItemNameAt(size_t index, const UString& name)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "List::setItemNameAt");
		mItemsInfo[index].first =name;
		_redrawItem(index);
	}

	void List::SetItemDataAt(size_t index, Any data)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "List::setItemDataAt");
		mItemsInfo[index].second = data;
		_redrawItem(index);
	}

	const UString& List::GetItemNameAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "List::getItemNameAt");
		return mItemsInfo[index].first;
	}

	void List::NotifyMouseSetFocus(Widget* sender, Widget* old)
	{

#if DEBUG_MODE == 1
		ASSERT_RANGE(*sender->_getInternalData<size_t>(), mWidgetLines.size(), "List::NotifyMouseSetFocus");
#endif

		mLineActive = *sender->_getInternalData<size_t>();
		eventListMouseItemFocus(this, mLineActive);
	}

	void List::NotifyMouseLostFocus(Widget* sender, Widget* _new)
	{
		if ((nullptr == _new) || (_new->GetParent() != _getClientWidget()))
		{
			mLineActive = ITEM_NONE;
			eventListMouseItemFocus(this, ITEM_NONE);
		}
	}

	void List::_setItemFocus(size_t index, bool focus)
	{
		ASSERT_RANGE(index, mWidgetLines.size(), "List::_setItemFocus");
		static_cast<Button*>(mWidgetLines[index])->_setMouseFocus(focus);
	}

	void List::SetScrollVisible(bool visible)
	{
		if (mNeedVisibleScroll == visible) return;
		mNeedVisibleScroll = visible;
		UpdateScroll();
	}

	void List::SetScrollPosition(size_t position)
	{
		if (mWidgetScroll != nullptr)
		{
			if (mWidgetScroll->GetScrollRange() > position)
			{
				mWidgetScroll->SetScrollPosition(position);
				_setScrollView(position);
			}
		}
	}

	void List::_setScrollView(size_t position)
	{
		mOffsetTop = ((int)position % mHeightLine);

		int offset = 0 - mOffsetTop;

		for (size_t pos=0; pos<mWidgetLines.size(); pos++)
		{
			mWidgetLines[pos]->SetPosition(IntPoint(0, offset));
			offset += mHeightLine;
		}

		int top = ((int)position / mHeightLine);
		if (top != mTopIndex)
		{
			mTopIndex = top;
			_redrawItemRange();
		}

		_redrawItemRange(mLastRedrawLine);
	}

	void List::_sendEventChangeScroll(size_t position)
	{
		eventListChangeScroll(this, position);
		if (ITEM_NONE != mLineActive) eventListMouseItemFocus(this, mLineActive);
	}

	void List::SwapItemsAt(size_t index1, size_t index2)
	{
		ASSERT_RANGE(index1, mItemsInfo.size(), "List::swapItemsAt");
		ASSERT_RANGE(index2, mItemsInfo.size(), "List::swapItemsAt");

		if (index1 == index2) return;

		std::swap(mItemsInfo[index1], mItemsInfo[index2]);

		_redrawItem(index1);
		_redrawItem(index2);
	}

	void List::_checkMapping(const std::string& owner)
	{
		size_t count_pressed = 0;
		size_t count_show = 0;

		for (size_t pos=0; pos<mWidgetLines.size(); pos++)
		{
			ASSERT(pos == *mWidgetLines[pos]->_getInternalData<size_t>(), owner);
			static_cast<Button*>(mWidgetLines[pos])->GetButtonPressed() ? count_pressed ++ : 0;
			static_cast<Button*>(mWidgetLines[pos])->IsVisible() ? count_show ++ : 0;
		}
		ASSERT(count_pressed < 2, owner);
		//ASSERT((count_show + mOffsetTop) <= mItemsInfo.size(), owner);
	}

	void List::_checkAlign()
	{
		int max_height = mItemsInfo.size() * mHeightLine;
		int visible_height = _getClientWidget()->GetHeight();

		if (visible_height >= max_height)
		{
			ASSERT(mTopIndex == 0, "mTopIndex == 0");
			ASSERT(mOffsetTop == 0, "mOffsetTop == 0");
			int height = 0;
			for (size_t pos=0; pos<mWidgetLines.size(); pos++)
			{
				if (pos >= mItemsInfo.size()) break;
				ASSERT(mWidgetLines[pos]->GetTop() == height, "mWidgetLines[pos]->GetTop() == height");
				height += mWidgetLines[pos]->GetHeight();
			}
		}
	}

	size_t List::FindItemIndexWith(const UString& name)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].first == name) return pos;
		}
		return ITEM_NONE;
	}

	int List::GetOptimalHeight()
	{
		return (mCoord.height - _getClientWidget()->GetHeight()) + (mItemsInfo.size() * mHeightLine);
	}

	void List::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "List_AddItem") AddItem(value);
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

	Widget* List::_getClientWidget()
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

	const Widget* List::_getClientWidget() const
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

} // namespace GUI


