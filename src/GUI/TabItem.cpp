#include "Precompiled.h"
#include "TabItem.h"

namespace GUI
{

	TabItem::TabItem() :
		mOwner(nullptr)
	{
	}

	void TabItem::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		mOwner = GetParent()->CastType<Tab>();
	}

	TabItem::~TabItem()
	{
		mOwner->_notifyDeleteItem(this);
	}

	void TabItem::SetSelected(bool value)
	{
		if (value) SetItemSelected();
	}

	void TabItem::SetCaption(const UString& value)
	{
		mOwner->SetItemName(this, value);
	}

	const UString& TabItem::GetCaption()
	{
		return mOwner->GetItemName(this);
	}

	void TabItem::SetButtonWidth(int width)
	{
		mOwner->SetButtonWidth(this, width);
	}

	int TabItem::GetButtonWidth()
	{
		return mOwner->GetButtonWidth(this);
	}

	const UString& TabItem::GetItemName()
	{
		return mOwner->GetItemName(this);
	}

	void TabItem::SetItemName(const UString& name)
	{
		mOwner->SetItemName(this, name);
	}

	void TabItem::SetItemData(Any data)
	{
		mOwner->SetItemData(this, data);
	}

	void TabItem::SetItemSelected()
	{
		mOwner->SetItemSelected(this);
	}

	void TabItem::RemoveItem()
	{
		mOwner->RemoveItem(this);
	}

	void TabItem::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "TabItem_ButtonWidth") SetButtonWidth(utility::ParseValue<int>(value));
		else if (key == "TabItem_Select") SetSelected(utility::ParseValue<bool>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI
