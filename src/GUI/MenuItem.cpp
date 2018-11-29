#include "Precompiled.h"
#include "MenuItem.h"
#include "SkinManager.h"
#include "SubWidgetManager.h"

namespace GUI
{

	MenuItem::MenuItem() :
		mOwner(nullptr)
	{
	}

	void MenuItem::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		Widget* curParent = GetParent();
		ASSERT(curParent, "MenuItem must have curParent MenuCtrl");
		if (!curParent->IsType<MenuCtrl>())
		{
			Widget* client = curParent;
			curParent = client->GetParent();
			ASSERT(curParent, "MenuItem must have curParent MenuCtrl");
			ASSERT(curParent->GetClientWidget() == client, "MenuItem must have curParent MenuCtrl");
			ASSERT(curParent->IsType<MenuCtrl>(), "MenuItem must have curParent MenuCtrl");
		}
		mOwner = curParent->CastType<MenuCtrl>();

		InitialiseWidgetSkin(info);

		this->mNeedKeyFocus = true;
	}

	MenuItem::~MenuItem()
	{
		ShutdownWidgetSkin();
		mOwner->_notifyDeleteItem(this);
	}

	Widget* MenuItem::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		Widget* widget = Base::BaseCreateWidget(style, type, skin, coord, align, layer, name);
		MenuCtrl* child = widget->CastType<MenuCtrl>(false);
		if (child) mOwner->_wrapItemChild(this, child);
		return widget;
	}

	void MenuItem::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Button::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void MenuItem::InitialiseWidgetSkin(ResourceSkin* info)
	{
	}

	void MenuItem::ShutdownWidgetSkin()
	{
	}

	void MenuItem::OnMouseButtonPressed(int left, int top, MouseButton id)
	{
		Base::OnMouseButtonPressed(left, top, id);
	}

	void MenuItem::OnMouseButtonReleased(int left, int top, MouseButton id)
	{
		Base::OnMouseButtonReleased(left, top, id);
	}

	void MenuItem::SetCaption(const UString& value)
	{
		Button::SetCaption(value);
		mOwner->_notifyUpdateName(this);
	}

	const UString& MenuItem::GetItemName()
	{
		return mOwner->GetItemName(this);
	}

	void MenuItem::SetItemName(const UString& value)
	{
		mOwner->SetItemName(this, value);
	}

	void MenuItem::SetItemData(Any data)
	{
		mOwner->SetItemData(this, data);
	}

	void MenuItem::RemoveItem()
	{
		mOwner->RemoveItem(this);
	}

	void MenuItem::SetItemId(const std::string& id)
	{
		mOwner->SetItemId(this, id);
	}

	const std::string& MenuItem::GetItemId()
	{
		return mOwner->GetItemId(this);
	}

	size_t MenuItem::GetItemIndex()
	{
		return mOwner->GetItemIndex(this);
	}

	MenuCtrl* MenuItem::CreateItemChild()
	{
		return mOwner->CreateItemChild(this);
	}

	void MenuItem::SetItemType(MenuItemType type)
	{
		mOwner->SetItemType(this, type);
	}

	MenuItemType MenuItem::GetItemType()
	{
		return mOwner->GetItemType(this);
	}

	void MenuItem::SetItemChildVisible(bool visible)
	{
		mOwner->SetItemChildVisible(this, visible);
	}

	MenuCtrl* MenuItem::GetItemChild()
	{
		return mOwner->GetItemChild(this);
	}

	void MenuItem::SetProperty(const std::string& key, const std::string& value)
	{
		if (key == "MenuItem_Id") SetItemId(value);
		else if (key == "MenuItem_Type") SetItemType(utility::ParseValue<MenuItemType>(value));
		else
		{
			Base::SetProperty(key, value);
			return;
		}
		eventChangeProperty(this, key, value);
	}

} // namespace GUI

