#include "Precompiled.h"
#include "MultiList.h"
#include "ResourceSkin.h"
#include "Button.h"
#include "StaticImage.h"
#include "List.h"
#include "Gui.h"
#include "WidgetManager.h"

namespace GUI
{

	MultiList::MultiList() :
		mHeightButton(0),
		mWidthBar(0),
		mButtonMain(nullptr),
		mLastMouseFocusIndex(ITEM_NONE),
		mSortUp(true),
		mSortColumnIndex(ITEM_NONE),
		mWidthSeparator(0),
		mOffsetButtonSeparator(2),
		mItemSelected(ITEM_NONE),
		mFrameAdvise(false),
		mClient(nullptr)
	{
	}

	void MultiList::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	MultiList::~MultiList()
	{
		FrameAdvise(false);
		ShutdownWidgetSkin();
	}

	void MultiList::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void MultiList::InitialiseWidgetSkin(ResourceSkin* info)
	{
		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.find("SkinButton");
			if (iter != properties.end()) mSkinButton = iter->second;
			iter = properties.find("HeightButton");
			if (iter != properties.end()) mHeightButton = utility::ParseInt(iter->second);
			if (mHeightButton < 0) mHeightButton = 0;

			iter = properties.find("SkinList");
			if (iter != properties.end()) mSkinList = iter->second;

			iter = properties.find("SkinButtonEmpty");
			if (iter != properties.end())
			{
				mButtonMain = mClient->CreateWidget<Button>(iter->second,
					IntCoord(0, 0, mClient->GetWidth(), mHeightButton), Align::Default);
			}

			iter = properties.find("WidthSeparator");
			if (iter != properties.end()) mWidthSeparator = utility::ParseInt(iter->second);
			iter = properties.find("SkinSeparator");
			if (iter != properties.end()) mSkinSeparator = iter->second;
		}

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mClient, "widget already assigned");
				mClient = (*iter);
				mWidgetClient = (*iter); 
			}
		}
		if (nullptr == mClient) mClient = this;
	}

	void MultiList::ShutdownWidgetSkin()
	{
		mWidgetClient = nullptr;
		mClient = nullptr;
	}

	//----------------------------------------------------------------------------------//
	void MultiList::InsertColumnAt(size_t column, const UString& name, int width, Any data)
	{
		ASSERT_RANGE_INSERT(column, mVectorColumnInfo.size(), "MultiList::insertColumnAt");
		if (column == ITEM_NONE) column = mVectorColumnInfo.size();

		if (!mVectorColumnInfo.empty())
			mVectorColumnInfo.back().list->SetScrollVisible(false);
		else mSortColumnIndex = 0;

		ColumnInfo curColumn;
		curColumn.width = width < 0 ? 0 : width;

		curColumn.list = mClient->CreateWidget<List>(mSkinList, IntCoord(), Align::Left | Align::VStretch);
		curColumn.list->eventListChangePosition = NewDelegate(this, &MultiList::NotifyListChangePosition);
		curColumn.list->eventListMouseItemFocus = NewDelegate(this, &MultiList::NotifyListChangeFocus);
		curColumn.list->eventListChangeScroll = NewDelegate(this, &MultiList::NotifyListChangeScrollPosition);
		curColumn.list->eventListSelectAccept = NewDelegate(this, &MultiList::NotifyListSelectAccept);

		curColumn.button = mClient->CreateWidget<Button>(mSkinButton, IntCoord(), Align::Default);
		curColumn.button->eventMouseButtonClick = NewDelegate(this, &MultiList::NotifyButtonClick);
		curColumn.name = name;
		curColumn.data = data;

		if (!mVectorColumnInfo.empty())
		{
			size_t count = mVectorColumnInfo.front().list->GetItemCount();
			for (size_t pos=0; pos<count; ++pos)
				curColumn.list->AddItem("");
		}

		mVectorColumnInfo.insert(mVectorColumnInfo.begin() + column, curColumn);

		UpdateColumns();

		mVectorColumnInfo.back().list->SetScrollVisible(true);
	}

	void MultiList::SetColumnNameAt(size_t column, const UString& name)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::setColumnNameAt");
		mVectorColumnInfo[column].name = name;
		RedrawButtons();
	}

	void MultiList::SetColumnWidthAt(size_t column, int width)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::setColumnWidthAt");
		mVectorColumnInfo[column].width = width < 0 ? 0 : width;
		UpdateColumns();
	}

	const UString& MultiList::GetColumnNameAt(size_t column)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::getColumnNameAt");
		return mVectorColumnInfo[column].name;
	}

	int MultiList::GetColumnWidthAt(size_t column)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::getColumnWidthAt");
		return mVectorColumnInfo[column].width;
	}

	void MultiList::RemoveColumnAt(size_t column)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::removeColumnAt");

		ColumnInfo& info = mVectorColumnInfo[column];

		WidgetManager& manager = WidgetManager::GetInstance();
		manager.DestroyWidget(info.button);
		manager.DestroyWidget(info.list);

		mVectorColumnInfo.erase(mVectorColumnInfo.begin() + column);

		if (mVectorColumnInfo.empty())
		{
			mSortColumnIndex = ITEM_NONE;
			mItemSelected = ITEM_NONE;
		}
		else
		{
			mSortColumnIndex = 0;
			mSortUp = true;
			SortList();
		}

		UpdateColumns();
	}

	void MultiList::RemoveAllColumns()
	{
		WidgetManager& manager = WidgetManager::GetInstance();
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			manager.DestroyWidget((*iter).button);
			manager.DestroyWidget((*iter).list);
		}
		mVectorColumnInfo.clear();
		mSortColumnIndex = ITEM_NONE;

		UpdateColumns();

		mItemSelected = ITEM_NONE;
	}

	void MultiList::SortByColumn(size_t column, bool backward)
	{
		mSortColumnIndex = column;
		if (backward)
		{
			mSortUp = !mSortUp;
			RedrawButtons();
			if (mFrameAdvise) SortList();

			FlipList();
		}
		else
		{
			mSortUp = true;
			RedrawButtons();
			SortList();
		}
	}

	size_t MultiList::GetItemCount() const
	{
		if (mVectorColumnInfo.empty()) return 0;
		return mVectorColumnInfo.front().list->GetItemCount();
	}

	void MultiList::RemoveAllItems()
	{
		BiIndexBase::RemoveAllItems();
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			(*iter).list->RemoveAllItems();
		}

		mItemSelected = ITEM_NONE;
	}

	/*size_t MultiList::GetItemIndexSelected()
	{
		if (mVectorColumnInfo.empty()) return ITEM_NONE;
		size_t item = mVectorColumnInfo.front().list->GetItemIndexSelected();
		return (ITEM_NONE == item) ? ITEM_NONE : BiIndexBase::ConvertToFace(item);
	}*/

	void MultiList::UpdateBackSelected(size_t index)
	{
		if (index == ITEM_NONE)
		{
			for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
			{
				(*iter).list->ClearIndexSelected();
			}
		}
		else
		{
			//size_t curIndex = BiIndexBase::ConvertToBack(index);
			for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
			{
				(*iter).list->SetIndexSelected(index);
			}
		}
	}

	void MultiList::SetIndexSelected(size_t index)
	{
		if (index == mItemSelected) return;

		ASSERT_RANGE(0, mVectorColumnInfo.size(), "MultiList::setIndexSelected");
		ASSERT_RANGE_AND_NONE(index, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::setIndexSelected");

		mItemSelected = index;
		UpdateBackSelected(BiIndexBase::ConvertToBack(mItemSelected));
	}

	void MultiList::SetSubItemNameAt(size_t column, size_t index, const UString& name)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::setSubItemAt");
		ASSERT_RANGE(index, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::setSubItemAt");

		size_t curIndex = BiIndexBase::ConvertToBack(index);
		mVectorColumnInfo[column].list->SetItemNameAt(curIndex, name);

		if (column == mSortColumnIndex) FrameAdvise(true);
	}

	const UString& MultiList::GetSubItemNameAt(size_t column, size_t index)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::getSubItemNameAt");
		ASSERT_RANGE(index, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::getSubItemNameAt");

		size_t curIndex = BiIndexBase::ConvertToBack(index);
		return mVectorColumnInfo[column].list->GetItemNameAt(curIndex);
	}

	size_t MultiList::FindSubItemWith(size_t column, const UString& name)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::FindSubItemWith");

		size_t index = mVectorColumnInfo[column].list->FindItemIndexWith(name);
		return BiIndexBase::ConvertToFace(index);
	}
	//----------------------------------------------------------------------------------//

	void MultiList::UpdateOnlyEmpty()
	{
		if (nullptr == mButtonMain) return;
		if (mWidthBar >= mClient->GetWidth()) mButtonMain->SetVisible(false);
		else
		{
			mButtonMain->SetCoord(mWidthBar, 0, mClient->GetWidth()-mWidthBar, mHeightButton);
			mButtonMain->SetVisible(true);
		}
	}

	void MultiList::NotifyListChangePosition(List* sender, size_t position)
	{
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			if (sender != (*iter).list) (*iter).list->SetIndexSelected(position);
		}

		UpdateBackSelected(position);

		mItemSelected = BiIndexBase::ConvertToFace(position);

		eventListChangePosition(this, mItemSelected);
	}

	void MultiList::NotifyListSelectAccept(List* sender, size_t position)
	{
		eventListSelectAccept(this, BiIndexBase::ConvertToFace(position));
	}

	void MultiList::NotifyListChangeFocus(List* sender, size_t position)
	{
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			if (sender != (*iter).list)
			{
				if (ITEM_NONE != mLastMouseFocusIndex) (*iter).list->_setItemFocus(mLastMouseFocusIndex, false);
				if (ITEM_NONE != position) (*iter).list->_setItemFocus(position, true);
			}
		}
		mLastMouseFocusIndex = position;
	}

	void MultiList::NotifyListChangeScrollPosition(List* sender, size_t position)
	{
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			if (sender != (*iter).list)
				(*iter).list->SetScrollPosition(position);
		}
	}

	void MultiList::NotifyButtonClick(GUI::Widget* sender)
	{
		size_t index = *sender->_getInternalData<size_t>();
		SortByColumn(index, index == mSortColumnIndex);
	}

	void MultiList::RedrawButtons()
	{
		size_t pos = 0;
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			if (pos == mSortColumnIndex)
			{
				if (mSortUp) SetButtonImageIndex((*iter).button, SORT_UP);
				else SetButtonImageIndex((*iter).button, SORT_DOWN);
			}
			else SetButtonImageIndex((*iter).button, SORT_NONE);
			(*iter).button->SetCaption((*iter).name);
			pos++;
		}
	}

	void MultiList::SetButtonImageIndex(Button* button, size_t index)
	{
		StaticImage* image = button->GetStaticImage();
		if ( nullptr == image ) return;
		if (image->GetItemResource())
		{
			static const size_t CountIcons = 3;
			static const char * IconNames[CountIcons + 1] = { "None", "Up", "Down", "" };
			if (index >= CountIcons) index = CountIcons;
			image->SetItemName(IconNames[index]);
		}
		else
		{
			image->SetItemSelect(index);
		}
	}

	void MultiList::FrameEntered(float frame)
	{
		SortList();
	}

	void MultiList::FrameAdvise(bool advise)
	{
		if ( advise )
		{
			if ( ! mFrameAdvise )
			{
				GUI::Gui::GetInstance().eventFrameStart += GUI::NewDelegate( this, &MultiList::FrameEntered );
				mFrameAdvise = true;
			}
		}
		else
		{
			if ( mFrameAdvise )
			{
				GUI::Gui::GetInstance().eventFrameStart -= GUI::NewDelegate( this, &MultiList::FrameEntered );
				mFrameAdvise = false;
			}
		}
	}

	Widget* MultiList::GetSeparator(size_t index)
	{
		if (!mWidthSeparator || mSkinSeparator.empty()) return nullptr;
		if (index == mVectorColumnInfo.size()-1) return nullptr;

		while (index >= mSeparators.size())
		{
			Widget* separator = mClient->CreateWidget<Widget>(mSkinSeparator, IntCoord(), Align::Default);
			mSeparators.push_back(separator);
		}

		return mSeparators[index];
	}

	void MultiList::UpdateColumns()
	{
		mWidthBar = 0;
		size_t index = 0;
		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			(*iter).list->SetCoord(mWidthBar, mHeightButton, (*iter).width, mClient->GetHeight() - mHeightButton);
			(*iter).button->SetCoord(mWidthBar, 0, (*iter).width, mHeightButton);
			(*iter).button->_setInternalData(index);

			mWidthBar += (*iter).width;

			Widget* separator = GetSeparator(index);
			if (separator)
			{
				separator->SetCoord(mWidthBar, 0, mWidthSeparator, mClient->GetHeight());
			}

			mWidthBar += mWidthSeparator;
			index++;
		}

		RedrawButtons();
		UpdateOnlyEmpty();
	}

	void MultiList::FlipList()
	{
		if (ITEM_NONE == mSortColumnIndex) return;

		size_t last = mVectorColumnInfo.front().list->GetItemCount();
		if (0 == last) return;
		last --;
		size_t first = 0;

		while (first < last)
		{
			BiIndexBase::SwapItemsBackAt(first, last);
			for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
			{
				(*iter).list->SwapItemsAt(first, last);
			}

			first++;
			last--;
		}

		UpdateBackSelected(BiIndexBase::ConvertToBack(mItemSelected));
	}

	bool MultiList::Compare(List* list, size_t left, size_t right)
	{
		bool result = false;
		if (mSortUp) std::swap(left, right);
		if (requestOperatorLess.empty()) result = list->GetItemNameAt(left) < list->GetItemNameAt(right);
		else requestOperatorLess(this, mSortColumnIndex, list->GetItemNameAt(left), list->GetItemNameAt(right), result);
		return result;
	}

	void MultiList::SortList()
	{
		if (ITEM_NONE == mSortColumnIndex) return;

		List* list = mVectorColumnInfo[mSortColumnIndex].list;

		size_t count = list->GetItemCount();
		if (0 == count) return;

		// shell sort
		int first, last;
		for (size_t step = count>>1; step>0 ; step >>= 1)
		{
			for (size_t i=0;i<(count-step);i++)
			{
				first=i;
				while (first>=0)
				{
					last = first+step;
					if (Compare(list, first, last))
					{
						BiIndexBase::SwapItemsBackAt(first, last);
						for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
						{
							(*iter).list->SwapItemsAt(first, last);
						}
					}
					first--;
				}
			}
		}

		FrameAdvise(false);

		UpdateBackSelected(BiIndexBase::ConvertToBack(mItemSelected));
	}

	void MultiList::InsertItemAt(size_t index, const UString& name, Any data)
	{
		ASSERT_RANGE(0, mVectorColumnInfo.size(), "MultiList::insertItemAt");
		ASSERT_RANGE_INSERT(index, mVectorColumnInfo.front().list->GetItemCount(), "MultiList::insertItemAt");
		if (ITEM_NONE == index) index = mVectorColumnInfo.front().list->GetItemCount();

		if ((mItemSelected != ITEM_NONE) && (index <= mItemSelected)) mItemSelected ++;

		size_t curIndex = BiIndexBase::InsertItemAt(index);

		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			(*iter).list->InsertItemAt(curIndex, "");
		}
		mVectorColumnInfo.front().list->SetItemNameAt(curIndex, name);
		mVectorColumnInfo.front().list->SetItemDataAt(curIndex, data);

		FrameAdvise(true);
	}

	void MultiList::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(0, mVectorColumnInfo.size(), "MultiList::removeItemAt");
		ASSERT_RANGE(index, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::removeItemAt");

		size_t curIndex = BiIndexBase::RemoveItemAt(index);

		for (VectorColumnInfo::iterator iter=mVectorColumnInfo.begin(); iter!=mVectorColumnInfo.end(); ++iter)
		{
			(*iter).list->RemoveItemAt(curIndex);
		}

		size_t count = mVectorColumnInfo.begin()->list->GetItemCount();
		if (count == 0) mItemSelected = ITEM_NONE;
		else if (mItemSelected != ITEM_NONE)
		{
			if (index < mItemSelected) mItemSelected --;
			else if ((index == mItemSelected) && (mItemSelected == count)) mItemSelected --;
		}
		UpdateBackSelected(BiIndexBase::ConvertToBack(mItemSelected));
	}

	void MultiList::SwapItemsAt(size_t index1, size_t index2)
	{
		ASSERT_RANGE(0, mVectorColumnInfo.size(), "MultiList::removeItemAt");
		ASSERT_RANGE(index1, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::swapItemsAt");
		ASSERT_RANGE(index2, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::swapItemsAt");

		BiIndexBase::SwapItemsFaceAt(index1, index2);

		// FIXME
	}

	void MultiList::SetColumnDataAt(size_t index, Any data)
	{
		ASSERT_RANGE(index, mVectorColumnInfo.size(), "MultiList::setColumnDataAt");
		mVectorColumnInfo[index].data = data;
	}

	void MultiList::SetSubItemDataAt(size_t column, size_t index, Any data)
	{
		ASSERT_RANGE(column, mVectorColumnInfo.size(), "MultiList::setSubItemDataAt");
		ASSERT_RANGE(index, mVectorColumnInfo.begin()->list->GetItemCount(), "MultiList::setSubItemDataAt");

		size_t curIndex = BiIndexBase::ConvertToBack(index);
		mVectorColumnInfo[column].list->SetItemDataAt(curIndex, data);
	}

} // namespace GUI


