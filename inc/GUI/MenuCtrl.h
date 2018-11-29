#ifndef __MENU_CTRL_H__
#define __MENU_CTRL_H__

#include "Prerequest.h"
#include "Types.h"
#include "MenuItemType.h"
#include "Widget.h"
#include "Any.h"
#include "EventPair.h"
#include "MenuItemType.h"
#include "ControllerFadeAlpha.h"

namespace GUI
{

	typedef delegates::CDelegate2<MenuCtrl*, MenuItem*> EventHandle_MenuCtrlPtrMenuItemPtr;
	typedef delegates::CDelegate1<MenuCtrl*> EventHandle_MenuCtrlPtr;

	class GUI_EXPORT MenuCtrl :
		public Widget
	{
		RTTI_DERIVED(MenuCtrl)
		DEFINE_GET_THIS(MenuCtrl, BASS(Widget, END))

	public:
		MenuCtrl();

		//@ExportToLua
		enum ItemImage
		{
			ItemImageNone,
			ItemImagePopup
		};

		struct ItemInfo
		{
			ItemInfo(MenuItem* item, const UString& name, MenuItemType type, MenuCtrl* submenu, const std::string& id, Any data) :
				item(item),
				name(name),
				type(type),
				submenu(submenu),
				id(id),
				data(data),
				width(0)
			{
			}

			/** Item */
			MenuItem* item;
			/** Item name*/
			UString name;
			/** Widget have separator after item */
			MenuItemType type;
			/** Sub Menu (or nullptr if no submenu) */
			MenuCtrl* submenu;
			/** Item id*/
			std::string id;
			/** User data */
			Any data;
			/** Item width */
			int width;
		};

		typedef std::vector<ItemInfo> VectorMenuItemInfo;

	public:
		/** @copydoc Widget::setVisible */
		//@ExportToLua
		virtual void SetVisible(bool value);

		/** Hide or show Menu smooth */
		//@ExportToLua
		void SetVisibleSmooth(bool value);

		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mItemsInfo.size(); }

		//! Insert an item into a array at a specified position
		MenuItem* InsertItemAt(size_t index, const UString& name, MenuItemType type = MenuItemType::Normal, const std::string& id = "", Any data = Any::Null);
		//@ExportToLua
		MenuItem* InsertItem(size_t index, const UString& name, MenuItemType type = MenuItemType::Normal, const std::string& id = "", Widget* value = nullptr)
		{
			return InsertItemAt(index, name, type, id, value);
		}
		//! Insert an item into a array
		MenuItem* InsertItem(MenuItem* to, const UString& name, MenuItemType type = MenuItemType::Normal, const std::string& id = "", Any data = Any::Null);
		//@ExportToLua
		MenuItem* InsertItemEx(MenuItem* to, const UString& name, MenuItemType type = MenuItemType::Normal, const std::string& id = "", Widget* value = nullptr)
		{
			return InsertItem(to, name, type, id, value);
		}

		//! Add an item to the end of a array
		MenuItem* AddItem(const UString& name, MenuItemType type = MenuItemType::Normal, const std::string& id = "", Any data = Any::Null);
		//@ExportToLua
		MenuItem* AppendItem(const UString& name, MenuItemType type = MenuItemType::Normal, const std::string& id = "", Widget* value = nullptr)
		{
			return AddItem(name, type, id, value);
		}

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }
		//! Remove item
		//@ExportToLua
		void RemoveItem(MenuItem* item);

		//! Remove all items
		//@ExportToLua
		void RemoveAllItems();


		//! Get item from specified position
		MenuItem* GetItemAt(size_t index);
		//@ExportToLua
		MenuItem* GetItem(size_t index) { return GetItemAt(index); }

		//! Get item index
		//@ExportToLua
		size_t GetItemIndex(MenuItem* item);

		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndex(MenuItem* item);

		//! Search item, returns the item of the first occurrence in array or nullptr if item not found
		//@ExportToLua
		MenuItem* FindItemWith(const UString& name);

		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetItemDataAt(size_t index, Any data);
		//@ExportToLua
		void SetItemData(size_t index, Widget* value) { SetItemDataAt(index, value); }
		//! Replace an item data
		void SetItemData(MenuItem* item, Any data) { SetItemDataAt(GetItemIndex(item), data); }
		//@ExportToLua
		void SetItemData(MenuItem* item, Widget* value) { SetItemDataAt(GetItemIndex(item), value); }

		//! Clear an item data at a specified position
		void ClearItemDataAt(size_t index) { SetItemDataAt(index, Any::Null); }
		//@ExportToLua
		void ClearItemData(size_t index) { SetItemDataAt(index, Any::Null); }
		//! Clear an item data
		//@ExportToLua
		void ClearItemData(MenuItem* item) { ClearItemDataAt(GetItemIndex(item)); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			ASSERT_RANGE(index, mItemsInfo.size(), "MenuCtrl::getItemDataAt");
			return mItemsInfo[index].data.CastType<ValueType>(_throw);
		}

		//@ExportToLua
		Widget* GetItemData(size_t index)
		{
			if (index >= 0 && index < mItemsInfo.size())
			{
				return *mItemsInfo[index].data.CastType<Widget*>(false);
			}
			return nullptr;
		}
		//! Get item data
		template <typename ValueType>
		ValueType * GetItemData(MenuItem* item, bool _throw = true)
		{
			return GetItemDataAt<ValueType>(GetItemIndex(item), _throw);
		}

		//@ExportToLua
		Widget* GetItemDataEx(MenuItem* item) { return GetItemData(GetItemIndex(item)); }

		//! Replace an item id at a specified position
		void SetItemIdAt(size_t index, const std::string& id);
		//@ExportToLua
		void SetItemID(size_t index, const std::string& id) { SetItemIdAt(index, id); }
		//! Replace an item id
		//@ExportToLua
		void SetItemId(MenuItem* item, const std::string& id) { SetItemIdAt(GetItemIndex(item), id); }

		//! Get item id from specified position
		const std::string& GetItemIdAt(size_t index);
		//@ExportToLua
		const std::string& GetItemID(size_t index) { return GetItemIdAt(index); }
		//! Get item id
		//@ExportToLua
		const std::string& GetItemId(MenuItem* item) { return GetItemIdAt(GetItemIndex(item)); }

		/** Get item by id */
		//@ExportToLua
		MenuItem* GetItemById(const std::string& id);

		/** Get item index by id */
		//@ExportToLua
		size_t GetItemIndexById(const std::string& id);
		//------------------------------------------------------------------------------//

		//! Replace an item name at a specified position
		void SetItemNameAt(size_t index, const UString& name);
		//@ExportToLua
		void SetItemName(size_t index, const UString& name) { SetItemNameAt(index, name); }
		//! Replace an item name
		//@ExportToLua
		void SetItemName(MenuItem* item, const UString& name) { SetItemNameAt(GetItemIndex(item), name); }

		//! Get item from specified position
		const UString& GetItemNameAt(size_t index);
		//@ExportToLua
		const UString& GetItemName(size_t index) { return GetItemNameAt(index); }
		//! Get item from specified position
		//@ExportToLua
		const UString& GetItemName(MenuItem* item) { return GetItemNameAt(GetItemIndex(item)); }

		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndexWith(const UString& name);

		/** Show or hide Item (submenu) at a specified position */
		void SetItemChildVisibleAt(size_t index, bool visible);
		//@ExportToLua
		void SetItemChildVisible(size_t index, bool visible) { SetItemChildVisibleAt(index, visible); }
		/** Show or hide Item (submenu) */
		//@ExportToLua
		void SetItemChildVisible(MenuItem* item, bool visible) { SetItemChildVisibleAt(GetItemIndex(item), visible); }

		//------------------------------------------------------------------------------//

		/** Create specific type child Item (submenu) for item by index */
		template <typename Type>
		Type * CreateItemChildTAt(size_t index)
		{
			return static_cast<Type*>(CreateItemChildByType(index, Type::GetClassTypeName()));
		}

		/** Create specific type child Item (submenu) for item */
		template <typename Type>
		Type * CreateItemChildT(MenuItem* item) { return CreateItemChildTAt<Type>(GetItemIndex(item)); }

		/** Get child Item (submenu) from item by index */
		MenuCtrl* GetItemChildAt(size_t index);
		//@ExportToLua
		MenuCtrl* GetItemChild(size_t index) { return GetItemChildAt(index); }

		/** Get child Item (submenu) from item */
		//@ExportToLua
		MenuCtrl* GetItemChild(MenuItem* item) { return GetItemChildAt(GetItemIndex(item)); }

		/** Create child Item (submenu) for item by index */
		MenuCtrl* CreateItemChildAt(size_t index) { return CreateItemChildTAt<MenuCtrl>(index); }
		//@ExportToLua
		MenuCtrl* CreateItemChild(size_t index)   { return CreateItemChildTAt<MenuCtrl>(index); }

		/** Create child Item (submenu) for item */
		//@ExportToLua
		MenuCtrl* CreateItemChild(MenuItem* item) { return CreateItemChildAt(GetItemIndex(item)); }

		/** Remove child Item (submenu) for item by index */
		void RemoveItemChildAt(size_t index);
		//@ExportToLua
		void RemoveItemChild(size_t index) { RemoveItemChildAt(index); }

		/** Remove child Item (submenu) for item */
		//@ExportToLua
		void RemoveItemChild(MenuItem* item) { RemoveItemChildAt(GetItemIndex(item)); }


		/** Get item Type (see MenuItemType) from item by index */
		MenuItemType GetItemTypeAt(size_t index);
		//@ExportToLua
		MenuItemType GetItemType(size_t index) { return GetItemTypeAt(index); }

		/** Get item Type (see MenuItemType) from item */
		//@ExportToLua
		MenuItemType GetItemType(MenuItem* item) { return GetItemTypeAt(GetItemIndex(item)); }

		/** Set item Type (see MenuItemType) from item by index */
		void SetItemTypeAt(size_t index, MenuItemType type);
		//@ExportToLua
		void SetItemType(size_t index, MenuItemType type) { SetItemTypeAt(index, type); }
		/** Set item Type (see MenuItemType) from item */
		//@ExportToLua
		void SetItemType(MenuItem* item, MenuItemType type) { SetItemTypeAt(GetItemIndex(item), type); }

		/** Set mode when clicking on item with submenu generate eventMenuCtrlAccept and closes menu */
		//@ExportToLua
		void SetPopupAccept(bool value) { mPopupAccept = value; }
		//@ExportToLua
		/** Get mode when clicking on item with submenu generate eventMenuCtrlAccept and closes menu */
		//@ExportToLua
		bool GetPopupAccept() { return mPopupAccept; }

		/** Get parent menu item or nullptr if no item */
		//@ExportToLua
		MenuItem* GetMenuItemParent() { return mOwner; }


	/*event:*/
		/** Event : Enter pressed or mouse clicked.\n
			signature : void Method(GUI::MenuCtrl* sender, GUI::MenuItem* item)\n
			@param _sender widget that called this event
			@param _item Selected item
		*/
		EventHandle_MenuCtrlPtrMenuItemPtr eventMenuCtrlAccept;

		/** Event : Menu was closed by select or focus change.\n
			signature : void Method(GUI::MenuCtrl* sender)\n
			@param _sender widget that called this event
		*/
		EventHandle_MenuCtrlPtr eventMenuCtrlClose;


	/*internal:*/
		void _notifyDeleteItem(MenuItem* item);
		void _notifyUpdateName(MenuItem* item);
		void _wrapItemChild(MenuItem* item, MenuCtrl* widget);

		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~MenuCtrl();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		virtual void OnKeyChangeRootFocus(bool focus);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		void NotifyRootKeyChangeFocus(Widget* sender, bool focus);
		void NotifyMouseButtonClick(Widget* sender);
		void NotifyMouseSetFocus(Widget* sender, Widget* _new);

		const std::string& GetSkinByType(MenuItemType type)
		{
			return type == MenuItemType::Separator ? mSeparatorSkin : mSkinLine;
		}

		size_t GetIconIndexByType(MenuItemType type)
		{
			return type == MenuItemType::Popup ? ItemImagePopup : ItemImageNone;
		}

		void Update();

		void SetButtonImageIndex(Button* button, size_t index);

		MenuItemType GetItemType(bool submenu, bool separator)
		{
			if (submenu) return MenuItemType::Popup;
			else if (separator)  return MenuItemType::Separator;
			return MenuItemType::Normal;
		}

		void NotifyMenuCtrlAccept(MenuItem* item);

		Widget* CreateItemChildByType(size_t index, const std::string& type);

		void _wrapItem(MenuItem* item, size_t index, const UString& name, MenuItemType type, const std::string& id, Any data);

		ControllerFadeAlpha* CreateControllerFadeAlpha(float alpha, float coef, bool enable);

		Widget* _getClientWidget();
		const Widget* _getClientWidget() const;

	protected:
		bool mHideByAccept;
		bool mMenuDropMode;
		bool mIsMenuDrop;
		bool mHideByLostKey;

	private:
		VectorMenuItemInfo mItemsInfo;

		int mHeightLine;
		std::string mSkinLine;

		int mSubmenuImageSize;

		std::string mSubMenuSkin;
		std::string mSubMenuLayer;

		bool mShutdown;

		int mSeparatorHeight;
		std::string mSeparatorSkin;

		bool mAlignVert;
		int mDistanceButton;
		bool mPopupAccept;
		MenuItem* mOwner;
		bool mAnimateSmooth;

	};

} // namespace GUI

#endif // __MENU_CTRL_H__

