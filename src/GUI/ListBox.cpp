#include "Precompiled.h"
#include "ListBox.h"
#include "Button.h"

namespace GUI
{

	ListBox::ListBox() :
		mHeightLine(0)
	{
		requestCreateWidgetItem = GUI::NewDelegate(this, &ListBox::NotifyCreateWidgetItem);
		requestDrawItem = GUI::NewDelegate(this, &ListBox::NotifyDrawItem);
	}

	void ListBox::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		InitialiseWidgetSkin(info);
	}

	ListBox::~ListBox()
	{
		ShutdownWidgetSkin();
	}

	void ListBox::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void ListBox::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mHeightLine = 20;
		mChangeContentByResize = false;

		const MapString& properties = info->GetProperties();
		if (!properties.empty())
		{
			MapString::const_iterator iter = properties.end();
			iter = properties.find("SkinLine");
			if (iter != properties.end()) mSkinLine = iter->second;
			iter = properties.find("HeightLine");
			if (iter != properties.end()) mHeightLine = utility::ParseInt(iter->second);
		}

		_setScrollViewPage(mHeightLine);
	}

	void ListBox::ShutdownWidgetSkin()
	{
	}

	void ListBox::NotifyCreateWidgetItem(GUI::ListCtrl* sender, GUI::Widget* item)
	{
		const GUI::IntSize& size = item->GetSize();

		GUI::Button* text = item->CreateWidget<GUI::Button>(mSkinLine, GUI::IntCoord(0, 0, size.width, size.height), GUI::Align::Stretch);

		text->SetNeedMouseFocus(false);

		item->SetUserData(text);
	}

	void ListBox::NotifyDrawItem(GUI::ListCtrl* sender, GUI::Widget* item, const GUI::IBDrawItemInfo& info, GUI::IntCoord& coord)
	{
		GUI::Button* text = *item->GetUserData<GUI::Button*>();

		if (info.update)
		{
			text->SetCaption(mItemsInfo[info.index]);

			GUI::IntSize size = text->GetTextSize() + (text->GetSize() - text->GetTextRegion().Size());
			size.height = mHeightLine;
			coord.Set(0, 0, size.width, size.height);
		}

		text->SetButtonPressed(info.select);
		text->_setMouseFocus(info.active);
	}

	void ListBox::InsertItemAt(size_t index, const UString& name, Any data)
	{
		ASSERT_RANGE_INSERT(index, mItemsInfo.size(), "ListBox::insertItemAt");
		if (index == ITEM_NONE) index = mItemsInfo.size();

		mItemsInfo.insert(mItemsInfo.begin() + index, name);

		Base::InsertItemAt(index, data);
	}

	void ListBox::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListBox::removeItemAt");
		mItemsInfo.erase(mItemsInfo.begin() + index);

		Base::RemoveItemAt(index);
	}

	void ListBox::RemoveAllItems()
	{
		mItemsInfo.clear();

		Base::RemoveAllItems();
	}

	void ListBox::SwapItemsAt(size_t index1, size_t index2)
	{
		ASSERT_RANGE(index1, mItemsInfo.size(), "ListBox::swapItemsAt");
		ASSERT_RANGE(index2, mItemsInfo.size(), "ListBox::swapItemsAt");

		if (index1 == index2) return;

		std::swap(mItemsInfo[index1], mItemsInfo[index2]);

		Base::RedrawItemAt(index1);
		Base::RedrawItemAt(index2);
	}

	size_t ListBox::FindItemIndexWith(const UString& name)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos] == name) return pos;
		}
		return ITEM_NONE;
	}

	void ListBox::SetItemNameAt(size_t index, const UString& name)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListBox::setItemNameAt");

		Base::RedrawItemAt(index);
	}

	const UString& ListBox::GetItemNameAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListBox::getItemNameAt");

		return mItemsInfo[index];
	}

	void ListBox::BeginToItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "ListBox::beginToItemAt");

		//FIXME
	}

} // namespace GUI
