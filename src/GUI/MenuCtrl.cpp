#include "Precompiled.h"
#include "MenuCtrl.h"
#include "ResourceSkin.h"
#include "MenuItem.h"
#include "StaticImage.h"
#include "MenuBar.h"
#include "WidgetManager.h"
#include "LayerManager.h"
#include "ControllerManager.h"
#include "InputManager.h"
#include "Gui.h"

namespace GUI
{

	const float POPUP_MENU_SPEED_COEF = 3.0f;

	MenuCtrl::MenuCtrl() :
		mHideByAccept(true),
		mMenuDropMode(false),
		mIsMenuDrop(true),
		mHideByLostKey(false),
		mHeightLine(1),
		mSubmenuImageSize(0),
		mShutdown(false),
		mSeparatorHeight(0),
		mAlignVert(true),
		mDistanceButton(0),
		mPopupAccept(false),
		mOwner(nullptr),
		mAnimateSmooth(false)
	{
	}

	void MenuCtrl::_initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name)
	{
		Base::_initialise(style, coord, align, info, parent, croppedParent, creator, name);

		Widget* curParent = GetParent();
		if (curParent)
		{
			mOwner = curParent->CastType<MenuItem>(false);
			if ( ! mOwner )
			{
				Widget* client = curParent;
				curParent = client->GetParent();
				if (curParent && curParent->GetClientWidget())
				{
					mOwner = curParent->CastType<MenuItem>(false);
				}
			}
		}

		InitialiseWidgetSkin(info);
	}

	MenuCtrl::~MenuCtrl()
	{
		mShutdown = true;
		ShutdownWidgetSkin();
	}

	void MenuCtrl::BaseChangeWidgetSkin(ResourceSkin* info)
	{
		ShutdownWidgetSkin();
		Base::BaseChangeWidgetSkin(info);
		InitialiseWidgetSkin(info);
	}

	void MenuCtrl::InitialiseWidgetSkin(ResourceSkin* info)
	{
		mNeedKeyFocus = true;

		for (VectorWidgetPtr::iterator iter=mWidgetChildSkin.begin(); iter!=mWidgetChildSkin.end(); ++iter)
		{
			if (*(*iter)->_getInternalData<std::string>() == "Client")
			{
				DEBUG_ASSERT( ! mWidgetClient, "widget already assigned");
				mWidgetClient = (*iter);
			}
		}
		//ASSERT(nullptr != mWidgetClient, "Child Widget Client not found in Skin (MenuCtrl must have Client)");

		const MapString& properties = info->GetProperties();
		MapString::const_iterator iterS = properties.find("SkinLine");
		if (iterS != properties.end()) mSkinLine = iterS->second;
		//ASSERT(!mSkinLine.empty(), "SkinLine property not Found (MenuCtrl must have SkinLine property)");

		iterS = properties.find("HeightLine");
		if (iterS != properties.end()) mHeightLine = utility::ParseInt(iterS->second);
		if (mHeightLine < 1)
		{
			LOG(warning, "MenuCtrl HeightLine can't be less thah 1. Set to 1.");
			mHeightLine = 1;
		}

		iterS = properties.find("SeparatorHeight");
		if (iterS != properties.end()) mSeparatorHeight = utility::ParseInt(iterS->second);
		iterS = properties.find("SeparatorSkin");
		if (iterS != properties.end()) mSeparatorSkin = iterS->second;

		iterS = properties.find("SubmenuImageSize");
		if (iterS != properties.end()) mSubmenuImageSize = utility::ParseInt(iterS->second);

		iterS = properties.find("SubMenuSkin");
		if (iterS != properties.end()) mSubMenuSkin = iterS->second;
		//ASSERT(!mSubMenuSkin.empty(), "SubMenuSkin property not Found (MenuCtrl must have SubMenuSkin property)");

		iterS = properties.find("SubMenuLayer");
		if (iterS != properties.end()) mSubMenuLayer = iterS->second;
		//ASSERT(!mSubMenuLayer.empty(), "SubMenuLayer property not Found (MenuCtrl must have SubMenuLayer property)");

		iterS = properties.find("AlignVert");
		if (iterS != properties.end()) mAlignVert = utility::ParseBool(iterS->second);
		iterS = properties.find("DistanceButton");
		if (iterS != properties.end()) mDistanceButton = utility::ParseInt(iterS->second);

		if (mSeparatorHeight < 1) mSeparatorHeight = mHeightLine;
	}

	void MenuCtrl::ShutdownWidgetSkin()
	{
		mWidgetClient = nullptr;
	}

	Widget* MenuCtrl::BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name)
	{
		Widget* widget = nullptr;
		if (mWidgetClient != nullptr)
			widget = mWidgetClient->CreateWidgetT(style, type, skin, coord, align, layer, name);
		else
			widget = Base::BaseCreateWidget(style, type, skin, coord, align, layer, name);

		MenuItem* child = widget->CastType<MenuItem>(false);
		if (child)
		{
			_wrapItem(child, mItemsInfo.size(), "", MenuItemType::Normal, "", Any::Null);
		}
		return widget;
	}

	MenuItem* MenuCtrl::InsertItemAt(size_t index, const UString& name, MenuItemType type, const std::string& id, Any data)
	{
		ASSERT_RANGE_INSERT(index, mItemsInfo.size(), "MenuCtrl::insertItemAt");
		if (index == ITEM_NONE) index = mItemsInfo.size();

		MenuItem* item = _getClientWidget()->CreateWidget<MenuItem>(GetSkinByType(type), IntCoord(), Align::Default);
		_wrapItem(item, index, name, type, id, data);

		return item;
	}

	void MenuCtrl::RemoveItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::removeItemAt");

		if ( mItemsInfo[index].submenu )
		{
			WidgetManager::GetInstance().DestroyWidget(mItemsInfo[index].submenu);
		}
		WidgetManager::GetInstance().DestroyWidget(mItemsInfo[index].item);
	}

	void MenuCtrl::RemoveAllItems()
	{
		while (mItemsInfo.size() > 0)
		{
			if ( mItemsInfo.back().submenu )
			{
				WidgetManager::GetInstance().DestroyWidget(mItemsInfo.back().submenu);
			}
			WidgetManager::GetInstance().DestroyWidget(mItemsInfo.back().item);
		}
	}

	const UString& MenuCtrl::GetItemNameAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::getItemNameAt");
		return mItemsInfo[index].name;
	}

	void MenuCtrl::SetButtonImageIndex(Button* button, size_t index)
	{
		StaticImage* image = button->GetStaticImage();
		if ( nullptr == image ) return;
		if (image->GetItemResource())
		{
			static const size_t CountIcons = 2;
			static const char * IconNames[CountIcons + 1] = { "None", "Popup", "" };
			if (index >= CountIcons) index = CountIcons;
			image->SetItemName(IconNames[index]);
		}
		else
		{
			image->SetItemSelect(index);
		}
	}

	void MenuCtrl::Update()
	{
		IntSize size;

		if (mAlignVert)
		{
			for (VectorMenuItemInfo::iterator iter=mItemsInfo.begin(); iter!=mItemsInfo.end(); ++iter)
			{
				int height = iter->type == MenuItemType::Separator ? mSeparatorHeight : mHeightLine;
				iter->item->SetCoord(0, size.height, _getClientWidget()->GetWidth(), height);
				size.height += height + mDistanceButton;

				int width = iter->width;
				if (width > size.width) size.width = width;
			}

		}
		else
		{
			for (VectorMenuItemInfo::iterator iter=mItemsInfo.begin(); iter!=mItemsInfo.end(); ++iter)
			{
				int width = iter->type == MenuItemType::Separator ? mSeparatorHeight : iter->width;
				iter->item->SetCoord(size.width, 0, width, mHeightLine);
				size.width += width + mDistanceButton;
			}
			size.height = mHeightLine;
			size.width = mCoord.width;
		}

		SetSize(size + mCoord.Size() - _getClientWidget()->GetSize());
	}

	void MenuCtrl::SetItemDataAt(size_t index, Any data)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::setItemDataAt");
		mItemsInfo[index].data = data;
	}

	MenuCtrl* MenuCtrl::GetItemChildAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::getItemChildAt");
		return mItemsInfo[index].submenu;
	}

	void MenuCtrl::RemoveItemChildAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::removeItemChildAt");

		if (mItemsInfo[index].submenu != nullptr)
		{
			WidgetManager::GetInstance().DestroyWidget(mItemsInfo[index].submenu);
			mItemsInfo[index].submenu = nullptr;
		}

		Update();
	}

	void MenuCtrl::SetItemNameAt(size_t index, const UString& name)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::setItemNameAt");

		mItemsInfo[index].name = name;
		MenuItem* item = mItemsInfo[index].item;
		item->SetCaption(name);

		Update();
	}

	void MenuCtrl::SetItemIdAt(size_t index, const std::string& id)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::setItemIdAt");
		mItemsInfo[index].id = id;
	}

	const std::string& MenuCtrl::GetItemIdAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::getItemIdAt");
		return mItemsInfo[index].id;
	}

	void MenuCtrl::_notifyDeleteItem(MenuItem* item)
	{
		if (mShutdown) return;

		size_t index = GetItemIndex(item);
		mItemsInfo.erase(mItemsInfo.begin() + index);
		Update();
	}

	void MenuCtrl::_notifyUpdateName(MenuItem* item)
	{
		size_t index = GetItemIndex(item);
		mItemsInfo[index].name = item->GetCaption();

		ISubWidgetText* text = item->GetSubWidgetText();
		mItemsInfo[index].width = text ? (text->GetTextSize().width + item->GetSize().width - text->GetWidth()) : 0;
		Update();
	}

	MenuItemType MenuCtrl::GetItemTypeAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::getItemTypeAt");
		return mItemsInfo[index].type;
	}

	void MenuCtrl::SetItemTypeAt(size_t index, MenuItemType type)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::setItemTypeAt");
		ItemInfo& info = mItemsInfo[index];
		if (info.type == type) return;

		info.type = type;
		info.item->ChangeWidgetSkin(GetSkinByType(type));
		SetButtonImageIndex(info.item, GetIconIndexByType(type ));
		info.item->SetCaption(info.name);

		Update();
	}

	void MenuCtrl::NotifyMenuCtrlAccept(MenuItem* item)
	{
		Widget* sender = this;

		WidgetManager::GetInstance().AddWidgetToUnlink(sender);
		eventMenuCtrlAccept(this, item);
		WidgetManager::GetInstance().RemoveWidgetFromUnlink(sender);

		if (sender == nullptr) return;

		WidgetManager::GetInstance().AddWidgetToUnlink(sender);

		MenuItem* parent_item = GetMenuItemParent();
		if (parent_item)
		{
			MenuCtrl* parent_ctrl = parent_item->GetMenuCtrlParent();
			if (parent_ctrl)
			{
				parent_ctrl->NotifyMenuCtrlAccept(item);
			}
		}

		WidgetManager::GetInstance().RemoveWidgetFromUnlink(sender);

		if (sender == nullptr) return;


		if (mHideByAccept)
		{
			SetVisibleSmooth(false);
		}
		else
		{
			InputManager::GetInstance().SetKeyFocusWidget(nullptr);
		}
	}

	void MenuCtrl::SetItemChildVisibleAt(size_t index, bool visible)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::setItemChildVisibleAt");

		if (visible)
		{
			if (mItemsInfo[index].submenu && mItemsInfo[index].submenu->GetItemCount())
			{

				int offset = mItemsInfo[0].item->GetAbsoluteTop() - this->GetAbsoluteTop();

				const IntCoord& coord = mItemsInfo[index].item->GetAbsoluteCoord();
				IntPoint point(this->GetAbsoluteRect().right, coord.top - offset);

				MenuCtrl* menu = mItemsInfo[index].submenu;

				if (this->mAlignVert)
				{
					if (point.left + menu->GetWidth() > GUI::Gui::GetInstance().GetViewSize().width)
						point.left -= menu->GetWidth();
					if (point.top + menu->GetHeight() > GUI::Gui::GetInstance().GetViewSize().height)
						point.top -= menu->GetHeight();
				}
				else
				{
					point.Set(coord.left, this->GetAbsoluteRect().bottom);
				}

				menu->SetPosition(point);
				menu->SetVisibleSmooth(true);
			}
		}
		else
		{
			if (mItemsInfo[index].submenu)
			{
				mItemsInfo[index].submenu->SetVisibleSmooth(false);
			}
		}
	}

	void MenuCtrl::NotifyRootKeyChangeFocus(Widget* sender, bool focus)
	{
		MenuItem* item = sender->CastType<MenuItem>();
		if (item->GetItemType() == MenuItemType::Popup)
		{
			if (focus)
			{
				if (!mMenuDropMode || mIsMenuDrop)
				{
					item->SetItemChildVisible(true);
					item->SetButtonPressed(true);
				}
			}
			else
			{
				item->SetItemChildVisible(false);
				item->SetButtonPressed(false);
			}
		}
	}

	Widget* MenuCtrl::CreateItemChildByType(size_t index, const std::string& type)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::createItemChildByType");
		RemoveItemChildAt(index);
		Widget* child = mItemsInfo[index].item->CreateWidgetT(WidgetStyle::Popup, type, mSubMenuSkin, IntCoord(), Align::Default, mSubMenuLayer);
		ASSERT(child->IsType<MenuCtrl>(), "child must have MenuCtrl base curType");
		return child;
	}

	void MenuCtrl::NotifyMouseButtonClick(Widget* sender)
	{
		MenuItem* item = sender->CastType<MenuItem>();
		if (mMenuDropMode)
		{
			if (mIsMenuDrop)
			{
				if (item->GetItemType() == MenuItemType::Popup)
				{
					item->SetButtonPressed(false);
					item->SetItemChildVisible(false);
					mIsMenuDrop = false;
				}
			}
			else
			{
				if (item->GetItemType() == MenuItemType::Popup)
				{
					mIsMenuDrop = true;
					item->SetButtonPressed(true);
					item->SetItemChildVisible(true);
					InputManager::GetInstance().SetKeyFocusWidget(item);
				}
			}
		}
		else
		{
			if ((item->GetItemType() == MenuItemType::Popup && mPopupAccept) ||
				item->GetItemType() == MenuItemType::Normal)
			{
				NotifyMenuCtrlAccept(item);
			}
		}

	}

	void MenuCtrl::OnKeyChangeRootFocus(bool focus)
	{
		if (mMenuDropMode)
		{
			mIsMenuDrop = false;
		}
		if ( ! focus && mHideByLostKey)
		{
			SetVisibleSmooth(false);
			eventMenuCtrlClose(this);
		}
		Base::OnKeyChangeRootFocus(focus);
	}

	void MenuCtrl::NotifyMouseSetFocus(Widget* sender, Widget* _new)
	{
		InputManager::GetInstance().SetKeyFocusWidget(sender);
	}

	void MenuCtrl::_wrapItemChild(MenuItem* item, MenuCtrl* widget)
	{
		size_t index = GetItemIndex(item);
		if (mItemsInfo[index].submenu != nullptr)
		{
			WidgetManager::GetInstance().DestroyWidget(mItemsInfo[index].submenu);
		}
		mItemsInfo[index].submenu = widget;
		mItemsInfo[index].submenu->SetVisible(false);

		Update();
	}

	void MenuCtrl::_wrapItem(MenuItem* item, size_t index, const UString& name, MenuItemType type, const std::string& id, Any data)
	{
		item->SetAlign(mAlignVert ? Align::Top | Align::HStretch : Align::Default);
		item->SetCoord(0, 0, _getClientWidget()->GetWidth(), mHeightLine);
		item->eventRootKeyChangeFocus = NewDelegate(this, &MenuCtrl::NotifyRootKeyChangeFocus);
		item->eventMouseButtonClick = NewDelegate(this, &MenuCtrl::NotifyMouseButtonClick);
		item->eventMouseSetFocus = NewDelegate(this, &MenuCtrl::NotifyMouseSetFocus);

		SetButtonImageIndex(item, GetIconIndexByType(type ));

		MenuCtrl* submenu = nullptr;

		ItemInfo info = ItemInfo(item, name, type, submenu, id, data);

		mItemsInfo.insert(mItemsInfo.begin() + index, info);

		item->SetCaption(name);

		Update();
	}

	void MenuCtrl::SetVisible(bool visible)
	{

		if (mAnimateSmooth)
		{
			ControllerManager::GetInstance().RemoveItem(this);
			SetAlpha(ALPHA_MAX);
			SetEnabledSilent(true);
			mAnimateSmooth = false;
		}

		if (visible)
		{
			if (mOwner == nullptr && mHideByLostKey)
			{
				GUI::InputManager::GetInstance().SetKeyFocusWidget(this);
			}
		}

		Base::SetVisible(visible);
	}

	void MenuCtrl::SetVisibleSmooth(bool visible)
	{
		mAnimateSmooth = true;
		ControllerManager::GetInstance().RemoveItem(this);

		if (visible)
		{
			SetEnabledSilent(true);
			if ( ! IsVisible() )
			{
				SetAlpha(ALPHA_MIN);
				Base::SetVisible(true);
			}

			ControllerFadeAlpha* controller = CreateControllerFadeAlpha(ALPHA_MAX, POPUP_MENU_SPEED_COEF, true);
			controller->eventPostAction = NewDelegate(Action::ActionWidgetShow);
			ControllerManager::GetInstance().AddItem(this, controller);
		}
		else
		{
			SetEnabledSilent(false);

			ControllerFadeAlpha* controller = CreateControllerFadeAlpha(ALPHA_MIN, POPUP_MENU_SPEED_COEF, false);
			controller->eventPostAction = NewDelegate(Action::ActionWidgetHide);
			ControllerManager::GetInstance().AddItem(this, controller);
		}
	}

	ControllerFadeAlpha* MenuCtrl::CreateControllerFadeAlpha(float alpha, float coef, bool enable)
	{
		ControllerItem* item = ControllerManager::GetInstance().CreateItem(ControllerFadeAlpha::GetClassTypeName());
		ControllerFadeAlpha* controller = item->CastType<ControllerFadeAlpha>();

		controller->SetAlpha(alpha);
		controller->SetCoef(coef);
		controller->SetEnabled(enable);

		return controller;
	}

	MenuItem* MenuCtrl::InsertItem(MenuItem* to, const UString& name, MenuItemType type, const std::string& id, Any data)
	{
		return InsertItemAt(GetItemIndex(to), name, type, id, data);
	}

	MenuItem* MenuCtrl::AddItem(const UString& name, MenuItemType type, const std::string& id, Any data)
	{
		return InsertItemAt(ITEM_NONE, name, type, id, data);
	}

	void MenuCtrl::RemoveItem(MenuItem* item)
	{
		RemoveItemAt(GetItemIndex(item));
	}

	MenuItem* MenuCtrl::GetItemAt(size_t index)
	{
		ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::getItemAt");
		return mItemsInfo[index].item;
	}

	size_t MenuCtrl::GetItemIndex(MenuItem* item)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].item == item) return pos;
		}
		EXCEPT("item (" << item << ") not found, source 'MenuCtrl::GetItemIndex'");
	}

	MenuItem* MenuCtrl::FindItemWith(const UString& name)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].name == name) return mItemsInfo[pos].item;
		}
		return nullptr;
	}

	MenuItem* MenuCtrl::GetItemById(const std::string& id)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].id == id) return mItemsInfo[pos].item;
		}
		EXCEPT("item Id (" << id << ") not found, source 'MenuCtrl::getItemById'");
	}

	size_t MenuCtrl::GetItemIndexById(const std::string& id)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].id == id) return pos;
		}
		EXCEPT("item Id (" << id << ") not found, source 'MenuCtrl::getItemById'");
	}

	size_t MenuCtrl::FindItemIndexWith(const UString& name)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].name == name) return pos;
		}
		return ITEM_NONE;
	}

	size_t MenuCtrl::FindItemIndex(MenuItem* item)
	{
		for (size_t pos=0; pos<mItemsInfo.size(); pos++)
		{
			if (mItemsInfo[pos].item == item) return pos;
		}
		return ITEM_NONE;
	}

	Widget* MenuCtrl::_getClientWidget()
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

	const Widget* MenuCtrl::_getClientWidget() const
	{
		return mWidgetClient == nullptr ? this : mWidgetClient;
	}

} // namespace GUI

