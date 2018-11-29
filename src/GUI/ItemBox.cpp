#include "Precompiled.h"
#include "ItemBox.h"
#include "Button.h"
#include "VScroll.h"
#include "HScroll.h"
#include "ResourceSkin.h"
#include "InputManager.h"
#include "Gui.h"
#include "WidgetTranslate.h"
#include "WidgetManager.h"

namespace GUI
{

	ItemBox::ItemBox() :
		mCountItemInLine(0),
		mCountLines(0),
		mFirstVisibleIndex(0),
		mFirstOffsetIndex(0),
		mIndexSelect(ITEM_NONE),
		mIndexActive(ITEM_NONE),
		mIndexAccept(ITEM_NONE),
		mIndexRefuse(ITEM_NONE),
		mIsFocus(false),
		mItemDrag(nullptr),
		mAlignVert(true)
	{
		mChangeContentByResize = true;
	}

	void ItemBox::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	ItemBox::~ItemBox()
	{
		ShutdownWidgetSkin();
	}

	void ItemBox::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void ItemBox::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mNeedKeyFocus = true;
		mDragLayer = "DragAndDrop";

		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("AlignVert");
			if (iter != properties.end()) mAlignVert = utility::ParseBool(iter->second);
			iter = properties.find("DragLayer");
			if (iter != properties.end()) mDragLayer = iter->second;
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "VScroll")
			{
				DEBUG_ASSERT( ! mVScroll, "widget already assigned");
				mVScroll = (*iter)->CastType<VScroll>();
				mVScroll->eventScrollChangePosition = NewDelegate(this, &ItemBox::NotifyScrollChangePosition);
			}
			if (*(*iter)->_getInternalData<std::string>() == "HScroll")
			{
				DEBUG_ASSERT( ! mHScroll, "widget already assigned");
				mHScroll = (*iter)->CastType<HScroll>();
				mHScroll->eventScrollChangePosition = NewDelegate(this, &ItemBox::NotifyScrollChangePosition);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mWidgetClient, "widget already assigned");
				mWidgetClient = (*iter);
				mWidgetClient->eventMouseWheel = NewDelegate(this, &ItemBox::NotifyMouseWheel);
				mWidgetClient->eventMouseButtonPressed = NewDelegate(this, &ItemBox::NotifyMouseButtonPressed);
				mClient = mWidgetClient;
			}
		}
		//ASSERT(nullptr != mWidgetClient, "Child Widget Client not found in Skin (ItemBox must have Client) skin ='" << info->GetSkinName() << "'");

		if (mWidgetClient != nullptr)
			mWidgetClient->_requestGetContainer = NewDelegate(this, &ItemBox::_requestGetContainer);

		RequestItemSize();

		UpdateScrollSize();
		UpdateScrollPosition();
	}

	void ItemBox::ShutdownWidgetSkin()
	{
		mVScroll = nullptr;
		mHScroll = nullptr;
		mClient = nullptr;
		mWidgetClient = nullptr;
	}

	void ItemBox::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void ItemBox::SetSize(const IntSize& size)
	{
		Base::SetSize(size);
		UpdateFromResize();
	}

	void ItemBox::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);
		UpdateFromResize();
	}

	void ItemBox::RequestItemSize()
	{
		IntCoord coord(0, 0, 1, 1);

		requestCoordItem(this, coord, false);

		mSizeItem = coord.Size();
		ASSERT((mSizeItem.width > 0 && mSizeItem.height > 0), "(mSizeItem.width > 0 && mSizeItem.height > 0)  at requestCoordWidgetItem");
	}

	void ItemBox::UpdateFromResize()
	{
		RequestItemSize();

		UpdateScrollSize();
		UpdateScrollPosition();

		_updateAllVisible(true);
		_resetContainer(true);
	}

	void ItemBox::_updateAllVisible(bool redraw)
	{
		int count_visible = 0;
		if (mAlignVert)
		{
			count_visible = (_getClientWidget()->GetHeight() / mSizeItem.height) + 2;
		}
		else
		{
			count_visible = (_getClientWidget()->GetWidth() / mSizeItem.width) + 2;
		}

		size_t start = (mFirstVisibleIndex * mCountItemInLine);
		size_t count = (count_visible * mCountItemInLine) + start;

		size_t index = 0;
		for (size_t pos = start; pos<count; ++pos, ++index)
		{
			if (pos >= mItemsInfo.size()) break;

			Widget* item = GetItemWidget(index);
			if (mAlignVert)
			{
				item->SetPosition(((int)index % mCountItemInLine) * mSizeItem.width - mContentPosition.left,
					(((int)index / mCountItemInLine) * mSizeItem.height)  - mFirstOffsetIndex);
			}
			else
			{
				item->SetPosition((((int)index / mCountItemInLine) * mSizeItem.width)  - mFirstOffsetIndex,
					((int)index % mCountItemInLine) * mSizeItem.height - mContentPosition.top);
			}

			item->SetSize(mSizeItem);
			item->SetVisible(true);

			if (redraw)
			{
				IBDrawItemInfo data(pos, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, true, false);
				requestDrawItem(this, item, data);
			}

		}

		while (index < mVectorItems.size())
		{
			mVectorItems[index]->SetVisible(false);
			index ++;
		}

	}

	Widget* ItemBox::GetItemWidget(size_t index)
	{
		if (index == mVectorItems.size())
		{

			RequestItemSize();

			Widget* item = _getClientWidget()->CreateWidget<Widget>("Default", IntCoord(0, 0, mSizeItem.width, mSizeItem.height), Align::Default);

			requestCreateWidgetItem(this, item);

			item->eventMouseWheel = NewDelegate(this, &ItemBox::NotifyMouseWheel);
			item->eventRootMouseChangeFocus = NewDelegate(this, &ItemBox::NotifyRootMouseChangeFocus);
			item->eventMouseButtonPressed = NewDelegate(this, &ItemBox::NotifyMouseButtonPressed);
			item->eventMouseButtonReleased = NewDelegate(this, &ItemBox::NotifyMouseButtonReleased);
			item->eventMouseButtonDoubleClick = NewDelegate(this, &ItemBox::NotifyMouseButtonDoubleClick);
			item->eventMouseDrag = NewDelegate(this, &ItemBox::NotifyMouseDrag);
			item->_requestGetContainer = NewDelegate(this, &ItemBox::_requestGetContainer);
			item->eventKeyButtonPressed = NewDelegate(this, &ItemBox::NotifyKeyButtonPressed);
			item->eventKeyButtonReleased = NewDelegate(this, &ItemBox::NotifyKeyButtonReleased);

			item->_setInternalData((size_t)mVectorItems.size());

			mVectorItems.push_back(item);
		}

		ASSERT_RANGE(index, mVectorItems.size(), "ItemBox::getItemWidget");

		return mVectorItems[index];
	}

	void ItemBox::OnMouseWheel(int rel)
	{
		NotifyMouseWheel(nullptr, rel);

		Base::OnMouseWheel(rel);
	}

	void ItemBox::OnKeySetFocus(Widget* old)
	{
		mIsFocus = true;
		SetState("pushed");

		Base::OnKeySetFocus(old);
	}

	void ItemBox::OnKeyLostFocus(Widget* _new)
	{
		mIsFocus = false;
		SetState("normal");

		Base::OnKeyLostFocus(_new);
	}

	void ItemBox::ResetCurrentActiveItem()
	{
		if (mIndexActive != ITEM_NONE)
		{
			size_t start = (size_t)(mFirstVisibleIndex * mCountItemInLine);
			size_t index = mIndexActive;
			mIndexActive = ITEM_NONE;

			if ((mIndexActive >= start) && (mIndexActive < (start + mVectorItems.size())))
			{
				IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);

				requestDrawItem(this, mVectorItems[mIndexActive - start], data);
			}
		}
	}

	void ItemBox::findCurrentActiveItem()
	{
		DEBUG_ASSERT(mIndexActive == ITEM_NONE, "use : ResetCurrentActiveItem() before findCurrentActiveItem()");

		const IntPoint& point = InputManager::GetInstance().GetMousePositionByLayer();

		const IntRect& rect = _getClientAbsoluteRect();
		if ((point.left < rect.left) || (point.left > rect.right) || (point.top < rect.top) || (point.top > rect.bottom))
		{
			return;
		}

		for (size_t pos=0; pos<mVectorItems.size(); ++pos)
		{
			Widget* item = mVectorItems[pos];
			const IntRect& abs_rect = item->GetAbsoluteRect();
			if ((point.left>= abs_rect.left) && (point.left <= abs_rect.right) && (point.top>= abs_rect.top) && (point.top <= abs_rect.bottom))
			{

				size_t index = CalcIndexByWidget(item);
				if (index < mItemsInfo.size())
				{

					mIndexActive = index;
					IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);

					requestDrawItem(this, item, data);
				}

				break;
			}
		}
	}

	void ItemBox::_requestGetContainer(Widget* sender, Widget*& container, size_t& index)
	{
		if (sender == _getClientWidget())
		{
			container = this;
			index = ITEM_NONE;
		}
		else
		{
			size_t curIndex = CalcIndexByWidget(sender);
			if (curIndex < mItemsInfo.size())
			{
				container = this;
				index = curIndex;
			}
		}
	}

	void ItemBox::_setContainerItemInfo(size_t index, bool set, bool accept)
	{
		if (index == ITEM_NONE) return;
		ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::_setContainerItemInfo");

		mIndexAccept = (set && accept ) ? index : ITEM_NONE;
		mIndexRefuse = (set && !accept) ? index : ITEM_NONE;

		size_t start = (size_t)(mFirstVisibleIndex * mCountItemInLine);
		if ((index >= start) && (index < (start + mVectorItems.size())))
		{
			IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
			requestDrawItem(this, mVectorItems[index - start], data);
		}
	}

	void ItemBox::SetItemDataAt(size_t index, Any data)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::setItemData");
		mItemsInfo[index].data = data;

		size_t start = (size_t)(mFirstVisibleIndex * mCountItemInLine);
		if ((index >= start) && (index < (start + mVectorItems.size())))
		{
			IBDrawItemInfo curData(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, true, false);
			requestDrawItem(this, mVectorItems[index - start], curData);
		}

		_resetContainer(true);
	}

	void ItemBox::InsertItemAt(size_t index, Any data)
	{
		ASSERT_RANGE_INSERT(index, mItemsInfo.size(), "ItemBox::insertItemAt");
		if (index == ITEM_NONE) index = mItemsInfo.size();

		_resetContainer(false);

		ResetCurrentActiveItem();

		mItemsInfo.insert(mItemsInfo.begin() + index, ItemDataInfo(data));

		if (mIndexSelect != ITEM_NONE)
		{
			if (mIndexSelect >= index)
			{
				mIndexSelect ++;
			}
		}

		UpdateScrollSize();
		UpdateScrollPosition();

		findCurrentActiveItem();

		_updateAllVisible(true);
	}

	void ItemBox::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::removeItemAt");

		_resetContainer(false);
		ResetCurrentActiveItem();

		mItemsInfo.erase(mItemsInfo.begin() + index);

		if (mIndexSelect != ITEM_NONE)
		{
			if (mItemsInfo.empty())
			{
				mIndexSelect = ITEM_NONE;
			}
			else if ((mIndexSelect > index) || (mIndexSelect == mItemsInfo.size()))
			{
				mIndexSelect --;
			}
		}

		UpdateScrollSize();
		UpdateScrollPosition();

		findCurrentActiveItem();

		_updateAllVisible(true);
	}

	void ItemBox::RemoveAllItems()
	{
		if (0 == mItemsInfo.size()) return;
		_resetContainer(false);

		mItemsInfo.clear();

		mIndexSelect = ITEM_NONE;
		mIndexActive = ITEM_NONE;

		UpdateScrollSize();
		UpdateScrollPosition();

		_updateAllVisible(true);
	}

	void ItemBox::RedrawItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::redrawItemAt");

		size_t start = (size_t)(mFirstVisibleIndex * mCountItemInLine);
		if ((index >= start) && (index < (start + mVectorItems.size())))
		{
			IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, true, false);
			requestDrawItem(this, mVectorItems[index - start], data);
		}
	}

	void ItemBox::SetIndexSelected(size_t index)
	{
		ASSERT_RANGE_AND_NONE(index, mItemsInfo.size(), "ItemBox::setIndexSelected");
		if (index == mIndexSelect) return;

		size_t start = (size_t)(mFirstVisibleIndex * mCountItemInLine);

		if (mIndexSelect != ITEM_NONE)
		{
			size_t curIndex = mIndexSelect;
			mIndexSelect = ITEM_NONE;

			if ((curIndex >= start) && (curIndex < (start + mVectorItems.size())))
			{
				IBDrawItemInfo data(curIndex, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				requestDrawItem(this, mVectorItems[curIndex - start], data);
			}
		}

		mIndexSelect = index;
		if (mIndexSelect != ITEM_NONE)
		{
			if ((index >= start) && (index < (start + mVectorItems.size())))
			{
				IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				requestDrawItem(this, mVectorItems[index - start], data);
			}
		}

	}

	void ItemBox::NotifyMouseButtonDoubleClick(Widget* sender)
	{
		size_t index = GetIndexByWidget(sender);

		eventSelectItemAccept(this, index);
	}

	void ItemBox::SetItemBoxAlignVert(bool vert)
	{
		if (mAlignVert == vert) return;
		mAlignVert = vert;

		mCountItemInLine = -1;
		UpdateFromResize();
	}

	void ItemBox::NotifyKeyButtonPressed(Widget* sender, KeyCode key, Char _char)
	{
		eventNotifyItem(this, IBNotifyItemData(GetIndexByWidget(sender), IBNotifyItemData::KeyPressed, key, _char));
	}

	void ItemBox::NotifyKeyButtonReleased(Widget* sender, KeyCode key)
	{
		eventNotifyItem(this, IBNotifyItemData(GetIndexByWidget(sender), IBNotifyItemData::KeyReleased, key));
	}

	size_t ItemBox::GetIndexByWidget(Widget* widget)
	{
		ASSERT(widget, "ItemBox::GetIndexByWidget : Widget == nullptr");
		if (widget == _getClientWidget()) return ITEM_NONE;
		ASSERT(widget->GetParent() == _getClientWidget(), "ItemBox::GetIndexByWidget : Widget is not child");

		size_t index = CalcIndexByWidget(widget);
		ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::GetIndexByWidget");

		return index;
	}

	size_t ItemBox::_getContainerIndex(const IntPoint& point)
	{
		for (VectorWidgetPtr::iterator iter=mVectorItems.begin(); iter!=mVectorItems.end(); ++iter)
		{
			if ((*iter)->IsVisible())
			{
				if ((*iter)->GetAbsoluteRect().Inside(point))
				{
					return GetIndexByWidget(*iter);
				}
			}
		}
		return ITEM_NONE;
	}

	void ItemBox::_resetContainer(bool update)
	{
		Base::_resetContainer(update);

		if ( ! update)
		{
			WidgetManager& instance = WidgetManager::GetInstance();
			for (VectorWidgetPtr::iterator iter=mVectorItems.begin(); iter!=mVectorItems.end(); ++iter)
			{
				instance.UnlinkFromUnlinkers(*iter);
			}
		}
	}

	Widget* ItemBox::GetWidgetByIndex(size_t index)
	{
		for (VectorWidgetPtr::iterator iter=mVectorItems.begin(); iter!=mVectorItems.end(); ++iter)
		{
			if ((*iter)->IsVisible())
			{
				size_t curIndex = GetIndexByWidget(*iter);

				if (curIndex == index) return (*iter);
			}
		}
		return nullptr;
	}

	void ItemBox::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		Base::OnMouseButtonPressed(left, top, id);
	}

	void ItemBox::OnMouseButtonReleased(int left, int top, MouseButton id)
	{
		Base::OnMouseButtonReleased(left, top, id);
	}

	void ItemBox::OnMouseDrag(int left, int top)
	{
		Base::OnMouseDrag(left, top);
	}

	void ItemBox::RemoveDropItems()
	{
		if (mItemDrag) mItemDrag->SetVisible(false);
	}

	void ItemBox::UpdateDropItems()
	{
		if (nullptr == mItemDrag)
		{
			IntCoord coord;

			requestCoordItem(this, coord, true);

			mPointDragOffset = coord.Point();

			mItemDrag = Gui::GetInstance().CreateWidget<Widget>("Default", IntCoord(0, 0, coord.width, coord.height), Align::Default, mDragLayer);
			requestCreateWidgetItem(this, mItemDrag);
		}

		const IntPoint& point = InputManager::GetInstance().GetMousePosition();

		mItemDrag->SetPosition(point.left - mClickInWidget.left + mPointDragOffset.left, point.top - mClickInWidget.top + mPointDragOffset.top);
		mItemDrag->SetVisible(true);
	}

	void ItemBox::UpdateDropItemsState(const DDWidgetState& state)
	{
		IBDrawItemInfo data;
		data.drop_accept = state.accept;
		data.drop_refuse = state.refuse;

		data.select = false;
		data.active = false;

		data.index = mDropSenderIndex;
		data.update = state.update;
		data.drag = true;

		requestDrawItem(this, mItemDrag, data);
	}

	void ItemBox::NotifyMouseDrag(Widget* sender, int left, int top)
	{
		MouseDrag();
	}

	void ItemBox::NotifyMouseButtonPressed(Widget* sender, int left, int top, MouseButton id)
	{
		MouseButtonPressed(id);

		if ( MouseButton::Left == id)
		{
			size_t old = mIndexSelect;

			if (sender == _getClientWidget())
			{
				SetIndexSelected(ITEM_NONE);
			}
			else
			{
				mDropSenderIndex = GetIndexByWidget(sender);

				SetIndexSelected(mDropSenderIndex);
			}

			mClickInWidget = InputManager::GetInstance().GetLastLeftPressed() - sender->GetAbsolutePosition();

			eventMouseItemActivate(this, mIndexSelect);
			if (old != mIndexSelect) eventChangeItemPosition(this, mIndexSelect);
		}

		eventNotifyItem(this, IBNotifyItemData(GetIndexByWidget(sender), IBNotifyItemData::MousePressed, left, top, id));
	}

	void ItemBox::NotifyMouseButtonReleased(Widget* sender, int left, int top, MouseButton id)
	{
		MouseButtonReleased(id);
		size_t index = CalcIndexByWidget(sender);
		if (index >= GetItemCount()) return;
		eventNotifyItem(this, IBNotifyItemData(index, IBNotifyItemData::MouseReleased, left, top, id));
	}

	void ItemBox::NotifyRootMouseChangeFocus(Widget* sender, bool focus)
	{
		size_t index = CalcIndexByWidget(sender);
		if (focus)
		{
			ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::NotifyRootMouseChangeFocus");

			if (mIndexActive != ITEM_NONE)
			{
				size_t old_index = mIndexActive;
				mIndexActive = ITEM_NONE;
				IBDrawItemInfo data(old_index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				requestDrawItem(this, mVectorItems[old_index - (mFirstVisibleIndex * mCountItemInLine)], data);
			}

			mIndexActive = index;
			IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
			requestDrawItem(this, mVectorItems[*sender->_getInternalData<size_t>()], data);
		}
		else
		{
			if (index < mItemsInfo.size() && mIndexActive == index)
			{
				mIndexActive = ITEM_NONE;
				IBDrawItemInfo data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				requestDrawItem(this, mVectorItems[*sender->_getInternalData<size_t>()], data);
			}
		}
	}

	void ItemBox::UpdateMetrics()
	{
		if (mAlignVert)
		{
			mCountItemInLine = _getClientWidget()->GetWidth() / mSizeItem.width;
		}
		else
		{
			mCountItemInLine = _getClientWidget()->GetHeight() / mSizeItem.height;
		}

		if (1 > mCountItemInLine) mCountItemInLine = 1;

		mCountLines = mItemsInfo.size() / mCountItemInLine;
		if (0 != (mItemsInfo.size() % mCountItemInLine)) mCountLines ++;

		if (mAlignVert)
		{
			mContentSize.width = (mSizeItem.width * mCountItemInLine);
			mContentSize.height = (mSizeItem.height * mCountLines);
		}
		else
		{
			mContentSize.width = (mSizeItem.width * mCountLines);
			mContentSize.height = (mSizeItem.height * mCountItemInLine);
		}
	}

	void ItemBox::NotifyScrollChangePosition(VScroll* sender, size_t index)
	{
		if (sender == mVScroll)
		{
			mContentPosition.top = (int)index;
		}
		else if (sender == mHScroll)
		{
			mContentPosition.left = (int)index;
		}

		SetContentPosition(mContentPosition);
	}

	void ItemBox::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mAlignVert)
		{
			if (mContentSize.height <= 0) return;

			int offset = mContentPosition.top;
			if (rel < 0) offset += mSizeItem.height;
			else offset -= mSizeItem.height;

			if (offset >= mContentSize.height - _getClientWidget()->GetHeight()) offset = mContentSize.height - _getClientWidget()->GetHeight();
			else if (offset < 0) offset = 0;

			if (mContentPosition.top == offset) return;

			ResetCurrentActiveItem();

			mContentPosition.top = offset;
		}
		else
		{
			if (mContentSize.width <= 0) return;

			int offset = mContentPosition.left;
			if (rel < 0) offset += mSizeItem.width;
			else  offset -= mSizeItem.width;

			if (offset >= mContentSize.width - _getClientWidget()->GetWidth()) offset = mContentSize.width - _getClientWidget()->GetWidth();
			else if (offset < 0) offset = 0;

			if (mContentPosition.left == offset) return;

			ResetCurrentActiveItem();

			mContentPosition.left = offset;
		}

		SetContentPosition(mContentPosition);

		if (!mNeedDrop)
			findCurrentActiveItem();

		if (nullptr != mVScroll) mVScroll->SetScrollPosition(mContentPosition.top);
		if (nullptr != mHScroll) mHScroll->SetScrollPosition(mContentPosition.left);
	}

	void ItemBox::SetContentPosition(const IntPoint& point)
	{
		mContentPosition = point;

		int old = mFirstVisibleIndex;

		if (mAlignVert)
		{
			mFirstVisibleIndex = mContentPosition.top / mSizeItem.height;
			mFirstOffsetIndex = mContentPosition.top % mSizeItem.height;
		}
		else
		{
			mFirstVisibleIndex = mContentPosition.left / mSizeItem.width;
			mFirstOffsetIndex = mContentPosition.left % mSizeItem.width;
		}

		_updateAllVisible(old != mFirstVisibleIndex);
		_resetContainer(true);
	}

	void ItemBox::RedrawAllItems()
	{
		_updateAllVisible(true);
	}

	void ItemBox::ResetDrag()
	{
		endDrop(true);
	}

	size_t ItemBox::CalcIndexByWidget(Widget* widget)
	{
		return *widget->_getInternalData<size_t>() + (mFirstVisibleIndex * mCountItemInLine);
	}

	IntSize ItemBox::GetContentSize()
	{
		return mContentSize;
	}

	IntPoint ItemBox::GetContentPosition()
	{
		return mContentPosition;
	}

	IntSize ItemBox::GetViewSize() const
	{
		return _getClientWidget()->GetSize();
	}

	void ItemBox::eraseContent()
	{
		UpdateMetrics();
	}

	size_t ItemBox::GetHScrollPage()
	{
		return mSizeItem.width;
	}

	size_t ItemBox::GetVScrollPage()
	{
		return mSizeItem.height;
	}

	Align ItemBox::GetContentAlign()
	{
		return Align::Default;
	}

	IntRect ItemBox::_getClientAbsoluteRect()
	{
		return _getClientWidget()->GetAbsoluteRect();
	}

	Widget* ItemBox::_getClientWidget()
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

	const Widget* ItemBox::_getClientWidget() const
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

} // namespace GUI

