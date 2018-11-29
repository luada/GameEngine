#ifndef __TAB_H__
#define __TAB_H__

#include "Prerequest.h"
#include "Widget.h"
#include "Any.h"
#include "EventPair.h"
#include "ControllerFadeAlpha.h"

namespace GUI
{

	typedef delegates::CDelegate2<Tab*, size_t> EventHandle_TabPtrSizeT;

	class GUI_EXPORT Tab :
		public Widget
	{
		//FIXME
		friend class TabItem;

		RTTI_DERIVED(Tab)
		DEFINE_GET_THIS(Tab, BASS(Widget, END))

	public:
		Tab();

		struct TabItemInfo
		{
			TabItemInfo(int width, const UString& name, TabItem* item, Any data) :
				width(width),
				name(name),
				item(item),
				data(data)
			{
			}

			int width;
			UString name;
			TabItem* item;
			Any data;
		};

		typedef std::vector<TabItemInfo> VectorTabItemInfo;

		//! @copydoc Widget::SetPosition(const IntPoint& value)
		virtual void SetPosition(const IntPoint& value);
		//! @copydoc Widget::SetSize(const IntSize& value)
		virtual void SetSize(const IntSize& value);
		//! @copydoc Widget::SetCoord(const IntCoord& value)
		virtual void SetCoord(const IntCoord& value);

		/** @copydoc Widget::SetPosition(int left, int top) */
		//@ExportToLua
		void SetPosition(int left, int top) { SetPosition(IntPoint(left, top)); }
		/** @copydoc Widget::SetSize(int width, int height) */
		//@ExportToLua
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }
		/** @copydoc Widget::SetCoord(int left, int top, int width, int height) */
		//@ExportToLua
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mItemsInfo.size(); }

		//! Insert an item into a array at a specified position
		TabItem* InsertItemAt(size_t index, const UString& name, Any data = Any::Null);
		//@ExportToLua
		TabItem* InsertItem(size_t index, const UString& name, Widget* value) { return InsertItemAt(index, name, value); }
		//! Insert an item into a array
		TabItem* InsertItem(TabItem* to, const UString& name, Any data = Any::Null)
		{
			return InsertItemAt(GetItemIndex(to), name, data);
		}
		//@ExportToLua
		TabItem* InsertItemEx(TabItem* to, const UString& name, Widget* value) { return InsertItemAt(GetItemIndex(to), name, value); }

		//! Add an item to the end of a array
		TabItem* AddItem(const UString& name, Any data = Any::Null)
		{
			return InsertItemAt(ITEM_NONE, name, data);
		}

		//@ExportToLua
		TabItem* AppendItem(const UString& name, Widget* value)  { return InsertItemAt(ITEM_NONE, name, value); }

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }
		//! Remove item
		//@ExportToLua
		void RemoveItem(TabItem* item) { RemoveItemAt(GetItemIndex(item)); }

		//! Remove all items
		//@ExportToLua
		void RemoveAllItems();


		//! Get item from specified position
		TabItem* GetItemAt(size_t index);
		//@ExportToLua
		TabItem* GetItem(size_t index) { return GetItemAt(index); }

		//! Get item index
		//@ExportToLua
		size_t GetItemIndex(TabItem* item);

		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndex(TabItem* item);

		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndexWith(const UString& name);

		//! Search item, returns the item of the first occurrence in array or nullptr if item not found
		//@ExportToLua
		TabItem* FindItemWith(const UString& name);


		//------------------------------------------------------------------------------//

		//! Get index of selected Item (ITEM_NONE if none selected)
		//@ExportToLua
		size_t GetIndexSelected() { return mIndexSelect; }

		//! Get selected Item (nullptr if none selected)
		//@ExportToLua
		TabItem* GetItemSelected();

		//! Select specified index
		//@ExportToLua
		void SetIndexSelected(size_t index);

		//! Select item
		//@ExportToLua
		void SetItemSelected(TabItem* item) { SetIndexSelected(GetItemIndex(item)); }


		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetItemDataAt(size_t index, Any data);
		//@ExportToLua
		void SetItemData(size_t index, Widget* value) { SetItemDataAt(index, value); }
		//! Replace an item data
		void SetItemData(TabItem* item, Any data) { SetItemDataAt(GetItemIndex(item), data); }
		//@ExportToLua
		void SetItemData(TabItem* item, Widget* value) { SetItemDataAt(GetItemIndex(item), value); }

		//! Clear an item data at a specified position
		void ClearItemDataAt(size_t index) { SetItemDataAt(index, Any::Null); }
		//@ExportToLua
		void ClearItemData(size_t index) { SetItemDataAt(index, Any::Null); }
		//! Clear an item data
		//@ExportToLua
		void ClearItemData(TabItem* item) { ClearItemDataAt(GetItemIndex(item)); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			ASSERT_RANGE(index, mItemsInfo.size(), "Tab::getItemDataAt");
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
		ValueType * GetItemData(TabItem* item, bool _throw = true)
		{
			return GetItemDataAt<ValueType>(GetItemIndex(item), _throw);
		}

		//@ExportToLua
		Widget* GetItemData(TabItem* item)
		{
			return GetItemData(GetItemIndex(item));
		}


		//------------------------------------------------------------------------------//

		//! Replace an item name at a specified position
		void SetItemNameAt(size_t index, const UString& name);
		//@ExportToLua
		void SetItemName(size_t index, const UString& name) { return SetItemNameAt(index, name); }

		//! Replace an item name
		//@ExportToLua
		void SetItemName(TabItem* item, const UString& name) { SetItemNameAt(GetItemIndex(item), name); }

		//! Get item name from specified position
		const UString& GetItemNameAt(size_t index);
		//@ExportToLua
		const UString& GetItemName(size_t index) { return GetItemNameAt(index); }

		//! Get item name
		//@ExportToLua
		const UString& GetItemName(TabItem* item) { return GetItemNameAt(GetItemIndex(item)); }


		//------------------------------------------------------------------------------//

		//! Move all elements so specified becomes visible
		void BeginToItemAt(size_t index);
		//@ExportToLua
		void BeginToItem(size_t index) { return BeginToItemAt(index); }

		//! Move all elements so specified becomes visible
		//@ExportToLua
		void BeginToItem(TabItem* item) { BeginToItemAt(GetItemIndex(item)); }

		//! Move all elements so first becomes visible
		//@ExportToLua
		void BeginToItemFirst() { if (GetItemCount()) BeginToItemAt(0); }

		//! Move all elements so last becomes visible
		//@ExportToLua
		void BeginToItemLast() { if (GetItemCount()) BeginToItemAt(GetItemCount() - 1); }

		//! Move all elements so selected becomes visible
		//@ExportToLua
		void BeginToItemSelected() { if (GetIndexSelected() != ITEM_NONE) BeginToItemAt(GetIndexSelected()); }


		//------------------------------------------------------------------------------//

		//! Set button width at a specified position
		void SetButtonWidthAt(size_t index, int width = DEFAULT);
		//@ExportToLua
		void SetButtonWidth(size_t index, int width = -1) { return SetButtonWidthAt(index, width); }
		//! Set button width
		//@ExportToLua
		void SetButtonWidth(TabItem* item, int width = -1/*DEFAULT*/) { SetButtonWidthAt(GetItemIndex(item), width); }

		//! Get button width at a specified position
		int GetButtonWidthAt(size_t index);
		//@ExportToLua
		int GetButtonWidth(size_t index) { return GetButtonWidthAt(index); }
		//! Get button width
		//@ExportToLua
		int GetButtonWidth(TabItem* item) { return GetButtonWidthAt(GetItemIndex(item)); }

		//------------------------------------------------------------------------------//

		/** Set default button width and disable autowidth mode */
		//@ExportToLua
		void SetButtonDefaultWidth(int value);
		/** Get default button width */
		//@ExportToLua
		int GetButtonDefaultWidth() { return mButtonDefaultWidth; }

		/** Enable or disable button auto width */
		//@ExportToLua
		void SetButtonAutoWidth(bool value);
		/** Get button auto width flag */
		//@ExportToLua
		bool GetButtonAutoWidth() { return mButtonAutoWidth; }

		/** Enable or disable smooth sheets showing */
		//@ExportToLua
		void SetSmoothShow(bool value) { mSmoothShow = value; }
		/** Get smooth sheets showing flag */
		//@ExportToLua
		bool GetSmoothShow() { return mSmoothShow; }

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : Active Tab sheet changed \n
			signature : void Method(GUI::Tab* sender, size_t index)\n
			@param _sender widget that called this event
			@param index Index of selected sheet
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_TabPtrSizeT> eventTabChangeSelect;

	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);


	protected:
		virtual ~Tab();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual Widget* BaseCreateWidget(WidgetStyle style, const std::string& type, const std::string& skin, const IntCoord& coord, Align align, const std::string& layer, const std::string& name);

		void UpdateBar();

		void NotifyPressedButtonEvent(GUI::Widget* sender);
		void NotifyPressedBarButtonEvent(GUI::Widget* sender);

		int _getTextWidth(const UString& text);

		void _showItem(TabItem* sheet, bool show, bool smooth);

		void _createItemButton();

		void _insertItem(size_t index, const UString& name, TabItem* sheet, Any data);

		void _notifyDeleteItem(TabItem* item);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();
		void ActionWidgetHide(Widget* widget);

		ControllerFadeAlpha* CreateControllerFadeAlpha(float alpha, float coef, bool enable);

		Widget* _getWidgetTemplate();
		Widget* _getWidgetBar();

	private:
		int mOffsetTab; 
		bool mButtonShow;
		int mWidthBar; 
		VectorWidgetPtr mItemButton; 
		std::string mButtonSkinName, mEmptySkinName;

		Widget* mWidgetBar;
		Button* mButtonLeft;
		Button* mButtonRight;
		Button* mButtonList;
		Widget* mButtonDecor;
		VectorWidgetPtr mWidgetsPatch; 
		Widget* mEmptyBarWidget;
		Widget* mItemTemplate;

		VectorTabItemInfo mItemsInfo;
		size_t mStartIndex;
		size_t mIndexSelect;

		int mButtonDefaultWidth;
		bool mSmoothShow;
		bool mButtonAutoWidth;

		bool mShutdown;

	};

} // namespace GUI

#endif // __TAB_H__


