#ifndef __MENU_ITEM_H__
#define __MENU_ITEM_H__

#include "Prerequest.h"
#include "Button.h"
#include "MenuCtrl.h"

namespace GUI
{

	class GUI_EXPORT MenuItem :
		public Button
	{
		RTTI_DERIVED(MenuItem)
		DEFINE_GET_THIS(MenuItem, BASS(Button, END))

	public:
		MenuItem();

		/** @copydoc Widget::SetCaption(const UString& value) */
		//@ExportToLua
		virtual void SetCaption(const UString& value);

		//! Replace an item name
		//@ExportToLua
		void SetItemName(const UString& value);
		//! Get item name
		//@ExportToLua
		const UString& GetItemName();

		//! Replace an item name
		void SetItemData(Any value);
		//@ExportToLua
		void SetItemData(Widget* value) { SetItemData(Any(value)); }

		//! Get item data
		template <typename ValueType>
		ValueType* GetItemData(bool _throw = true)
		{
			return mOwner->GetItemData<ValueType>(this, _throw);
		}

		//@ExportToLua
		Widget* GetItemDataEx()
		{
			return mOwner->GetItemDataEx(this);
		}

		//! Remove item
		//@ExportToLua
		void RemoveItem();

		//! Replace an item id at a specified position
		//@ExportToLua
		void SetItemId(const std::string& value);
		//! Get item id from specified position
		//@ExportToLua
		const std::string& GetItemId();

		//! Get item index
		//@ExportToLua
		size_t GetItemIndex();

		/** Create child Item (submenu), MenuItem can have only one child */
		//@ExportToLua
		MenuCtrl* CreateItemChild();

		/** Create specific type child Item (submenu), MenuItem can have only one child */
		template <typename Type>
		Type * CreateItemChildT()
		{
			return mOwner->createItemChildT<Type>(this);
		}

		/** Set item Type (see MenuItemType) */
		//@ExportToLua
		void SetItemType(MenuItemType value);
		/** Get item Type (see MenuItemType) */
		//@ExportToLua
		MenuItemType GetItemType();

		/** Hide or show child Item (submenu) */
		//@ExportToLua
		void SetItemChildVisible(bool value);

		/** Get parent MenuCtrl */
		//@ExportToLua
		MenuCtrl* GetMenuCtrlParent() { return mOwner; }

		/** Get child Item (submenu) */
		//@ExportToLua
		MenuCtrl* GetItemChild();

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);


	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);


	protected:
		virtual ~MenuItem();

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		virtual void BaseChangeWidgetSkin(ResourceSkin* info);
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

	private:
		virtual void OnMouseButtonPressed(int left, int top, MouseButton id);
		virtual void OnMouseButtonReleased(int left, int top, MouseButton id);

	private:
		MenuCtrl* mOwner;

	};

} // namespace GUI

#endif // __MENU_ITEM_H__
