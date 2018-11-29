#include "Precompiled.h"
#include "ListCtrl.h"
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

	ListCtrl::ListCtrl() :
		mIndexSelect(ITEM_NONE),
		mIndexActive(ITEM_NONE),
		mIndexAccept(ITEM_NONE),
		mIndexRefuse(ITEM_NONE),
		mIsFocus(false),
		mItemDrag(nullptr),
		mScrollViewPage(1)
	{
		mChangeContentByResize = true;
	}

	void ListCtrl::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	ListCtrl::~ListCtrl()
	{
		ShutdownWidgetSkin();
	}

	size_t ListCtrl::GetHScrollPage()
	{
		return mScrollViewPage;
	}

	size_t ListCtrl::GetVScrollPage()
	{
		return mScrollViewPage;
	}

	void ListCtrl::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void ListCtrl::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mNeedKeyFocus = true;
		mDragLayer = "DragAndDrop";

		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.end();
			iter = properties.find("DragLayer");
			if (iter != properties.end()) mDragLayer = iter->second;
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "VScroll")
			{
				DEBUG_ASSERT( ! mVScroll, "widget already assigned");
				mVScroll = (*iter)->CastType<VScroll>();
				mVScroll->eventScrollChangePosition = NewDelegate(this, &ListCtrl::NotifyScrollChangePosition);
			}
			if (*(*iter)->_getInternalData<std::string>() == "HScroll")
			{
				DEBUG_ASSERT( ! mHScroll, "widget already assigned");
				mHScroll = (*iter)->CastType<HScroll>();
				mHScroll->eventScrollChangePosition = NewDelegate(this, &ListCtrl::NotifyScrollChangePosition);
			}
			else if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mWidgetClient, "widget already assigned");
				mWidgetClient = (*iter);
				mWidgetClient->eventMouseWheel = NewDelegate(this, &ListCtrl::NotifyMouseWheel);
				mWidgetClient->eventMouseButtonPressed = NewDelegate(this, &ListCtrl::NotifyMouseButtonPressed);
				mClient = mWidgetClient;
			}
		}
		//ASSERT(nullptr != mWidgetClient, "Child Widget Client not found in Skin (ListCtrl must have Client) skin ='" << info->GetSkinName() << "'");

		_getClientWidget()->_requestGetContainer = NewDelegate(this, &ListCtrl::_requestGetContainer);

		UpdateFromResize();
	}

	void ListCtrl::ShutdownWidgetSkin()
	{
		mVScroll = nullptr;
		mHScroll = nullptr;
		mClient = nullptr;
		mWidgetClient = nullptr;
	}

	void ListCtrl::SetPosition(const IntPoint& point)
	{
		Base::SetPosition(point);
	}

	void ListCtrl::SetSize(const IntSize& size)
	{
		Base::SetSize(size);
		UpdateFromResize();
	}

	void ListCtrl::SetCoord(const IntCoord& coord)
	{
		Base::SetCoord(coord);
		UpdateFromResize();
	}

	void ListCtrl::UpdateFromResize()
	{
		UpdateMetrics();

		UpdateScrollSize();
		UpdateScrollPosition();

		_updateAllVisible(ITEM_NONE, true, true);
		_resetContainer(true);
	}

	void ListCtrl::_updateAllVisible(size_t index, bool needUpdateContetntSize, bool update)
	{

		bool change = false;

		int top = 0;
		size_t widget_index = 0;

		for (size_t curIndex=0; curIndex<mItemsInfo.size(); ++curIndex)
		{
			ItemDataInfo& info = mItemsInfo[curIndex];

			if ((top + info.size.height) < (mContentPosition.top))
			{
			}
			else if (top > ((mContentPosition.top) + _getClientWidget()->GetHeight()))
			{
			}
			else
			{
				Widget* item = GetItemWidget(widget_index);
				widget_index++;

				if (curIndex == index || ITEM_NONE == index)
				{
					item->_setInternalData((size_t)curIndex);

					item->SetPosition(-mContentPosition.left, top - (mContentPosition.top));
					item->SetVisible(true);

					IBDrawItemInfo data(curIndex, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, update, false);

					IntCoord coord(IntPoint(), info.size);
					requestDrawItem(this, item, data, coord);

					if (info.size != coord.Size())
						change = true;

					info.size = coord.Size();
					item->SetSize(mClient->GetWidth()/*mContentSize.width*/, info.size.height);
				}

			}

			top += info.size.height;
		}

		while (widget_index < mVectorItems.size())
		{
			Widget* item = mVectorItems[widget_index];
			widget_index ++;

			item->SetVisible(false);
			item->_setInternalData((size_t)ITEM_NONE);
		}

		if (change && needUpdateContetntSize)
		{
			UpdateMetrics();

			UpdateScrollSize();
			UpdateScrollPosition();
		}
	}

	Widget* ListCtrl::GetItemWidget(size_t index)
	{
		if (index == mVectorItems.size())
		{

			Widget* item = _getClientWidget()->CreateWidget<Widget>("Default", IntCoord(), Align::Default);

			requestCreateWidgetItem(this, item);

			item->eventMouseWheel = NewDelegate(this, &ListCtrl::NotifyMouseWheel);
			item->eventRootMouseChangeFocus = NewDelegate(this, &ListCtrl::NotifyRootMouseChangeFocus);
			item->eventMouseButtonPressed = NewDelegate(this, &ListCtrl::NotifyMouseButtonPressed);
			item->eventMouseButtonReleased = NewDelegate(this, &ListCtrl::NotifyMouseButtonReleased);
			item->eventMouseButtonDoubleClick = NewDelegate(this, &ListCtrl::NotifyMouseButtonDoubleClick);
			item->eventMouseDrag = NewDelegate(this, &ListCtrl::NotifyMouseDrag);
			item->_requestGetContainer = NewDelegate(this, &ListCtrl::_requestGetContainer);
			item->eventKeyButtonPressed = NewDelegate(this, &ListCtrl::NotifyKeyButtonPressed);
			item->eventKeyButtonReleased = NewDelegate(this, &ListCtrl::NotifyKeyButtonReleased);

			mVectorItems.push_back(item);
		}

		ASSERT_RANGE(index, mVectorItems.size(), "ListCtrl::getItemWidget");

		return mVectorItems[index];
	}

	void ListCtrl::OnMouseWheel(int rel)
	{
		NotifyMouseWheel(nullptr, rel);

		Base::OnMouseWheel(rel);
	}

	void ListCtrl::OnKeySetFocus(Widget* old)
	{
		mIsFocus = true;
		SetState("pushed");

		Base::OnKeySetFocus(old);
	}

	void ListCtrl::OnKeyLostFocus(Widget* _new)
	{
		mIsFocus = false;
		SetState("normal");

		Base::OnKeyLostFocus(_new);
	}

	void ListCtrl::ResetCurrentActiveItem()
	{
		if (mIndexActive != ITEM_NONE)
		{
			//size_t start = (size_t)mFirstVisibleIndex;
			size_t index = mIndexActive;
			mIndexActive = ITEM_NONE;

			//FIXME
			_updateAllVisible(index, true, false);

			/*if ((mIndexActive >= start) && (mIndexActive < (start + mVectorItems.size())))
			{
				IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);

				IntCoord Coord(IntPoint(), mItemsInfo[index].size);

				requestDrawItem(this, mVectorItems[mIndexActive - start], data, coord);

				mItemsInfo[index].size = coord.size();

			}*/
		}
	}

	void ListCtrl::findCurrentActiveItem()
	{
		DEBUG_ASSERT(mIndexActive == ITEM_NONE, "use : ResetCurrentActiveItem() before findCurrentActiveItem()");

		const IntPoint& point = InputManager::GetInstance().GetMousePositionByLayer();

		const IntRect& rect = _getClientWidget()->GetAbsoluteRect();
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
					//FIXME
					_updateAllVisible(index, true, false);

					/*IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
					IntCoord Coord(IntPoint(), mItemsInfo[index].size);
					requestDrawItem(this, item, data, coord);
					mItemsInfo[index].size = coord.size();*/

				}

				break;
			}
		}
	}

	void ListCtrl::_requestGetContainer(Widget* sender, Widget*& container, size_t& index)
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

	void ListCtrl::_setContainerItemInfo(size_t index, bool set, bool accept)
	{
		if (index == ITEM_NONE) return;
		ASSERT_RANGE(index, mItemsInfo.size(), "ListCtrl::_setContainerItemInfo");

		mIndexAccept = (set && accept ) ? index : ITEM_NONE;
		mIndexRefuse = (set && !accept) ? index : ITEM_NONE;

		//FIXME
		_updateAllVisible(index, true, false);

		/*size_t start = (size_t)mFirstVisibleIndex;
		if ((index >= start) && (index < (start + mVectorItems.size())))
		{

			IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);

			IntCoord Coord(IntPoint(), mItemsInfo[index].size);

			requestDrawItem(this, mVectorItems[index - start], data, coord);

			mItemsInfo[index].size = coord.size();

		}*/
	}

	void ListCtrl::SetItemDataAt(size_t index, Any data)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListCtrl::setItemData");
		mItemsInfo[index].data = data;

		//FIXME
		_updateAllVisible(index, true, true);

		/*size_t start = (size_t)mFirstVisibleIndex;
		if ((index >= start) && (index < (start + mVectorItems.size())))
		{
			IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, true, false);
			IntCoord Coord(IntPoint(), mItemsInfo[index].size);
			requestDrawItem(this, mVectorItems[index - start], curData, coord);
			mItemsInfo[index].size = coord.size();
		}*/

		_resetContainer(true);
	}

	void ListCtrl::InsertItemAt(size_t index, Any data)
	{
		ASSERT_RANGE_INSERT(index, mItemsInfo.size(), "ListCtrl::insertItemAt");
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

		_updateAllVisible(ITEM_NONE, true, true);
	}

	void ListCtrl::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListCtrl::removeItemAt");

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

		_updateAllVisible(ITEM_NONE, true, true);
	}

	void ListCtrl::RemoveAllItems()
	{
		if (0 == mItemsInfo.size()) return;
		_resetContainer(false);

		mItemsInfo.clear();

		mIndexSelect = ITEM_NONE;
		mIndexActive = ITEM_NONE;

		UpdateScrollSize();
		UpdateScrollPosition();

		_updateAllVisible(ITEM_NONE, true, true);
	}

	void ListCtrl::RedrawItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListCtrl::redrawItemAt");

		//FIXME
		_updateAllVisible(index, true, true);

		/*size_t start = (size_t)mFirstVisibleIndex;
		if ((index >= start) && (index < (start + mVectorItems.size())))
		{
			IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, true, false);
			IntCoord Coord(IntPoint(), mItemsInfo[index].size);
			requestDrawItem(this, mVectorItems[index - start], data, coord);
			mItemsInfo[index].size = coord.size();
		}*/
	}

	void ListCtrl::SetIndexSelected(size_t index)
	{
		ASSERT_RANGE_AND_NONE(index, mItemsInfo.size(), "ListCtrl::setIndexSelected");
		if (index == mIndexSelect) return;

		//size_t start = (size_t)mFirstVisibleIndex;

		if (mIndexSelect != ITEM_NONE)
		{

			size_t curIndex = mIndexSelect;
			mIndexSelect = ITEM_NONE;

			//FIXME
			_updateAllVisible(curIndex, true, false);

			/*if ((curIndex >= start) && (curIndex < (start + mVectorItems.size())))
			{
				IBDrawItemInfo Data(curIndex, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				IntCoord Coord(IntPoint(), mItemsInfo[curIndex].size);
				requestDrawItem(this, mVectorItems[curIndex - start], data, coord);
				mItemsInfo[curIndex].size = coord.size();
			}*/
		}

		mIndexSelect = index;
		if (mIndexSelect != ITEM_NONE)
		{

			//FIXME
			_updateAllVisible(index, true, false);

			/*if ((index >= start) && (index < (start + mVectorItems.size())))
			{
				IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				IntCoord Coord(IntPoint(), mItemsInfo[index].size);
				requestDrawItem(this, mVectorItems[index - start], data, coord);
				mItemsInfo[index].size = coord.size();
			}*/
		}

	}

	void ListCtrl::NotifyMouseButtonDoubleClick(Widget* sender)
	{
		size_t index = GetIndexByWidget(sender);

		eventSelectItemAccept(this, index);
	}

	void ListCtrl::NotifyKeyButtonPressed(Widget* sender, KeyCode key, Char _char)
	{
		eventNotifyItem(this, IBNotifyItemData(GetIndexByWidget(sender), IBNotifyItemData::KeyPressed, key, _char));
	}

	void ListCtrl::NotifyKeyButtonReleased(Widget* sender, KeyCode key)
	{
		eventNotifyItem(this, IBNotifyItemData(GetIndexByWidget(sender), IBNotifyItemData::KeyReleased, key));
	}

	size_t ListCtrl::GetIndexByWidget(Widget* widget)
	{
		ASSERT(widget, "ListCtrl::GetIndexByWidget : Widget == nullptr");
		if (widget == _getClientWidget()) return ITEM_NONE;
		ASSERT(widget->GetParent() == _getClientWidget(), "ListCtrl::GetIndexByWidget : Widget is not child");

		size_t index = CalcIndexByWidget(widget);
		ASSERT_RANGE(index, mItemsInfo.size(), "ListCtrl::GetIndexByWidget");

		return index;
	}

	size_t ListCtrl::_getContainerIndex(const IntPoint& point)
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

	void ListCtrl::_resetContainer(bool update)
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

	Widget* ListCtrl::GetWidgetByIndex(size_t index)
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

	void ListCtrl::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		Base::OnMouseButtonPressed(left, top, id);
	}

	void ListCtrl::OnMouseButtonReleased(int left, int top, MouseButton id)
	{
		Base::OnMouseButtonReleased(left, top, id);
	}

	void ListCtrl::OnMouseDrag(int left, int top)
	{
		Base::OnMouseDrag(left, top);
	}

	void ListCtrl::RemoveDropItems()
	{
		if (mItemDrag) mItemDrag->SetVisible(false);
	}

	void ListCtrl::UpdateDropItems()
	{
		if (nullptr == mItemDrag)
		{
			IntCoord coord(0, 0, 50, 50);

			//requestCoordItem(this, coord, true);

			mPointDragOffset = coord.Point();

			mItemDrag = Gui::GetInstance().CreateWidget<Widget>("Default", IntCoord(0, 0, coord.width, coord.height), Align::Default, mDragLayer);
			requestCreateWidgetItem(this, mItemDrag);
		}

		const IntPoint& point = InputManager::GetInstance().GetMousePositionByLayer();

		mItemDrag->SetPosition(point.left - mClickInWidget.left + mPointDragOffset.left, point.top - mClickInWidget.top + mPointDragOffset.top);
		mItemDrag->SetVisible(true);
	}

	void ListCtrl::UpdateDropItemsState(const DDWidgetState& state)
	{
		IBDrawItemInfo data;
		data.drop_accept = state.accept;
		data.drop_refuse = state.refuse;

		data.select = false;
		data.active = false;

		data.index = mDropSenderIndex;
		data.update = state.update;
		data.drag = true;

		IntCoord coord;

		requestDrawItem(this, mItemDrag, data, coord);

	}

	void ListCtrl::NotifyMouseDrag(Widget* sender, int left, int top)
	{
		MouseDrag();
	}

	void ListCtrl::NotifyMouseButtonPressed(Widget* sender, int left, int top, MouseButton id)
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

	void ListCtrl::NotifyMouseButtonReleased(Widget* sender, int left, int top, MouseButton id)
	{
		MouseButtonReleased(id);
		eventNotifyItem(this, IBNotifyItemData(GetIndexByWidget(sender), IBNotifyItemData::MouseReleased, left, top, id));
	}

	void ListCtrl::NotifyRootMouseChangeFocus(Widget* sender, bool focus)
	{
		size_t index = CalcIndexByWidget(sender);
		if (focus)
		{
			ASSERT_RANGE(index, mItemsInfo.size(), "ListCtrl::NotifyRootMouseChangeFocus");

			if (mIndexActive != ITEM_NONE)
			{
				size_t old_index = mIndexActive;
				mIndexActive = ITEM_NONE;

				//FIXME 
				_updateAllVisible(old_index, true, false);

				/*IBDrawItemInfo Data(old_index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				IntCoord Coord(IntPoint(), mItemsInfo[old_index].size);
				requestDrawItem(this, mVectorItems[old_index - mFirstVisibleIndex], data, coord);
				mItemsInfo[old_index].size = coord.size();*/

			}

			mIndexActive = index;

			//FIXME
			_updateAllVisible(index, true, false);

			/*IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
			IntCoord Coord(IntPoint(), mItemsInfo[index].size);
			requestDrawItem(this, mVectorItems[*sender->_getInternalData<size_t>()], data, coord);
			mItemsInfo[index].size = coord.size();*/

		}
		else
		{
			if (index < mItemsInfo.size() && mIndexActive == index)
			{
				mIndexActive = ITEM_NONE;

				//FIXME
				_updateAllVisible(index, true, false);

				/*IBDrawItemInfo Data(index, mIndexSelect, mIndexActive, mIndexAccept, mIndexRefuse, false, false);
				IntCoord Coord(IntPoint(), mItemsInfo[index].size);
				requestDrawItem(this, mVectorItems[*sender->_getInternalData<size_t>()], data, coord);
				mItemsInfo[index].size = coord.size();*/

			}
		}
	}

	void ListCtrl::UpdateMetrics()
	{
		IntSize size;

		for (VectorItemInfo::const_iterator item=mItemsInfo.begin(); item!=mItemsInfo.end(); ++item)
		{
			if (size.width < item->size.width)
				size.width = item->size.width;
			size.height += item->size.height;
		}

		mContentSize = size;
	}

	void ListCtrl::NotifyScrollChangePosition(VScroll* sender, size_t index)
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

	void ListCtrl::SetContentPosition(const IntPoint& point)
	{
		mContentPosition = point;

		_updateAllVisible(ITEM_NONE, true, true);
		_resetContainer(true);
	}

	void ListCtrl::NotifyMouseWheel(Widget* sender, int rel)
	{
		if (mContentSize.height <= 0) return;

		int offset = mContentPosition.top;
		if (rel < 0) offset += mScrollViewPage;
		else offset -= mScrollViewPage;

		if (mContentSize.height <= _getClientWidget()->GetHeight()) return;

		if (offset >= mContentSize.height - _getClientWidget()->GetHeight()) offset = mContentSize.height - _getClientWidget()->GetHeight();
		else if (offset < 0) offset = 0;

		if (mContentPosition.top == offset) return;

		ResetCurrentActiveItem();

		mContentPosition.top = offset;

		SetContentPosition(mContentPosition);

		if (!mNeedDrop)
			findCurrentActiveItem();

		if (nullptr != mVScroll) mVScroll->SetScrollPosition(mContentPosition.top);
		if (nullptr != mHScroll) mHScroll->SetScrollPosition(mContentPosition.left);
	}

	void ListCtrl::ResetDrag()
	{
		endDrop(true);
	}

	IntSize ListCtrl::GetContentSize()
	{
		return mContentSize;
	}

	IntPoint ListCtrl::GetContentPosition()
	{
		return mContentPosition;
	}

	IntSize ListCtrl::GetViewSize() const
	{
		return _getClientWidget()->GetSize();
	}

	void ListCtrl::eraseContent()
	{
		_updateAllVisible(ITEM_NONE, false, true);
		UpdateMetrics();
	}

	Align ListCtrl::GetContentAlign()
	{
		return Align::Default;
	}

	Widget* ListCtrl::_getClientWidget()
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

	const Widget* ListCtrl::_getClientWidget() const
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

} // namespace GUI

