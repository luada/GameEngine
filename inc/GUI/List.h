#ifndef __LIST_H__
#define __LIST_H__

#include "Prerequest.h"
#include "Widget.h"
#include "Any.h"
#include "EventPair.h"

namespace GUI
{

	typedef delegates::CDelegate2<List*, size_t> EventHandle_ListPtrSizeT;

	class GUI_EXPORT List :
		public Widget
	{
		RTTI_DERIVED(List)
		DEFINE_GET_THIS(List, BASS(Widget, END))

	public:
		List();

		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mItemsInfo.size(); }

		//! Insert an item into a array at a specified position
		void InsertItemAt(size_t index, const UString& name, Any data = Any::Null);
		//@ExportToLua
		void InsertItem(size_t index, const UString& name, Widget* value = nullptr) { InsertItemAt(index, name, value); }

		//! Add an item to the end of a array
		void AddItem(const UString& name, Any data = Any::Null) { InsertItemAt(ITEM_NONE, name, data); }
		//@ExportToLua
		void AppendItem(const UString& name, Widget* value = nullptr) { InsertItemAt(ITEM_NONE, name, value); }

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }

		//! Remove all items
		//@ExportToLua
		void RemoveAllItems();

		//! Swap items at a specified positions
		void SwapItemsAt(size_t index1, size_t index2);
		//@ExportToLua
		void SwapItems(size_t index1, size_t index2) { SwapItemsAt(index1, index2); }


		//! Search item, returns the position of the first occurrence in array or ITEM_NONE if item not found
		//@ExportToLua
		size_t FindItemIndexWith(const UString& name);


		//------------------------------------------------------------------------------//

		/** Get index of selected Item (ITEM_NONE if none selected) */
		//@ExportToLua
		size_t GetIndexSelected() { return mIndexSelect; }

		/** Select specified index */
		//@ExportToLua
		void SetIndexSelected(size_t index);

		/** Clear item selection */
		//@ExportToLua
		void ClearIndexSelected() { SetIndexSelected(ITEM_NONE); }


		//------------------------------------------------------------------------------//

		//! Replace an item data at a specified position
		void SetItemDataAt(size_t index, Any data);
		//@ExportToLua
		void SetItemData(size_t index, Widget* value) { SetItemDataAt(index, value); }

		//! Clear an item data at a specified position
		void ClearItemDataAt(size_t index) { SetItemDataAt(index, Any::Null); }
		//@ExportToLua
		void ClearItemData(size_t index) { SetItemDataAt(index, Any::Null); }

		//! Get item data from specified position
		template <typename ValueType>
		ValueType * GetItemDataAt(size_t index, bool _throw = true)
		{
			ASSERT_RANGE(index, mItemsInfo.size(), "List::getItemDataAt");
			return mItemsInfo[index].second.CastType<ValueType>(_throw);
		}

		//@ExportToLua
		Widget* GetItemData(size_t index)
		{
			if (index >= 0 && index < mItemsInfo.size())
			{
				return *mItemsInfo[index].second.CastType<Widget*>(false);
			}
			return nullptr;
		}


		//------------------------------------------------------------------------------//

		//! Replace an item name at a specified position
		void SetItemNameAt(size_t index, const UString& name);
		//@ExportToLua
		void SetItemName(size_t index, const UString& name) { SetItemNameAt(index, name); }

		//! Get item name from specified position
		const UString& GetItemNameAt(size_t index);
		//@ExportToLua
		const UString& GetItemName(size_t index) { return GetItemNameAt(index); }


		//------------------------------------------------------------------------------//

		//! Move all elements so specified becomes visible
		void BeginToItemAt(size_t index);
		//@ExportToLua
		void BeginToItem(size_t index) { BeginToItemAt(index); }

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

		/** Return true if item visible
			@param
				index of item
			@param
				_fill false: function return true when whole item is visible
				      true: function return true when at least part of item is visible
		*/
		bool IsItemVisibleAt(size_t index, bool fill = true);
		//@ExportToLua
		bool IsItemVisible(size_t index, bool fill = true) { return IsItemVisibleAt(index, fill); }
		//! Same as List::isItemVisible for selected item
		//@ExportToLua
		bool IsItemSelectedVisible(bool fill = true) { return IsItemVisibleAt(mIndexSelect, fill); }


		//! Set scroll visible when it needed
		//@ExportToLua
		void SetScrollVisible(bool visible);
		//! Set scroll position
		//@ExportToLua
		void SetScrollPosition(size_t position);

		//------------------------------------------------------------------------------------//

		//! @copydoc Widget::SetPosition(const IntPoint& value)
		virtual void SetPosition(const IntPoint& value);
		//! @copydoc Widget::SetSize(const IntSize& value)
		virtual void SetSize(const IntSize& value);
		//! @copydoc Widget::SetCoord(const IntCoord& value)
		virtual void SetCoord(const IntCoord& value);

		/** @copydoc Widget::SetPosition(int left, int top) */
		void SetPosition(int left, int top) { SetPosition(IntPoint(left, top)); }
		//@ExportToLua
		/** @copydoc Widget::SetSize(int width, int height) */
		//@ExportToLua
		void SetSize(int width, int height) { SetSize(IntSize(width, height)); }
		/** @copydoc Widget::SetCoord(int left, int top, int width, int height) */
		//@ExportToLua
		void SetCoord(int left, int top, int width, int height) { SetCoord(IntCoord(left, top, width, height)); }

		//! Return optimal height to fit all items in List
		//@ExportToLua
		int GetOptimalHeight();

		/** @copydoc Widget::SetProperty(const std::string& key, const std::string& value) */
		//@ExportToLua
		virtual void SetProperty(const std::string& key, const std::string& value);

	/*event:*/
		/** Event : Enter pressed or double click.\n
			signature : void Method(GUI::List* sender, size_t index)\n
			@param _sender widget that called this event
			@param index of selected item
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_ListPtrSizeT> eventListSelectAccept;

		/** Event : Selected item position changed.\n
			signature : void Method(GUI::List* sender, size_t index)\n
			@param _sender widget that called this event
			@param index of new item
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_ListPtrSizeT> eventListChangePosition;

		/** Event : Item was selected by mouse.\n
			signature : void Method(GUI::List* sender, size_t index)\n
			@param _sender widget that called this event
			@param index of selected item
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_ListPtrSizeT> eventListMouseItemActivate;

		/** Event : Mouse is over item.\n
			signature : void Method(GUI::List* sender, size_t index)\n
			@param _sender widget that called this event
			@param index of focused item
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_ListPtrSizeT> eventListMouseItemFocus;

		/** Event : Position of scroll changed.\n
			signature : void Method(GUI::List* sender, size_t position)\n
			@param _sender widget that called this event
			@param _position of scroll
		*/
		EventPair<EventHandle_WidgetSizeT, EventHandle_ListPtrSizeT> eventListChangeScroll;

	/*internal:*/
		void _checkAlign();

		void _setItemFocus(size_t position, bool focus);
		void _sendEventChangeScroll(size_t position);

		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~List();

		void BaseChangeWidgetSkin(ResourceSkin* info);

		void OnMouseWheel(int rel);
		void OnKeyLostFocus(Widget* _new);
		void OnKeySetFocus(Widget* old);
		void OnKeyButtonPressed(KeyCode key, Char _char);

		void NotifyScrollChangePosition(VScroll* sender, size_t rel);
		void NotifyMousePressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseDoubleClick(Widget* sender);
		void NotifyMouseWheel(Widget* sender, int rel);
		void NotifyMouseSetFocus(Widget* sender, Widget* old);
		void NotifyMouseLostFocus(Widget* sender, Widget* _new);

		void UpdateScroll();
		void UpdateLine(bool reset = false);
		void _setScrollView(size_t position);

		void _redrawItemRange(size_t start = 0);

		void _redrawItem(size_t index);

		void _selectIndex(size_t index, bool select);

		void _updateState() { SetState(mIsFocus ? "pushed" : "normal"); }

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();
		void _checkMapping(const std::string& owner);

		Widget* _getClientWidget();
		const Widget* _getClientWidget() const;

	private:
		std::string mSkinLine;
		VScroll* mWidgetScroll;

		VectorWidgetPtr mWidgetLines;

		int mHeightLine; 
		int mTopIndex; 
		int mOffsetTop; 
		int mRangeIndex; 
		size_t mLastRedrawLine; 

		size_t mIndexSelect; 
		size_t mLineActive; 

		typedef std::pair<UString, Any> PairItem;
		typedef std::vector<PairItem> VectorItemInfo;
		VectorItemInfo mItemsInfo;

		bool mIsFocus;
		bool mNeedVisibleScroll;

		IntSize mOldSize;

	};

} // namespace GUI

#endif // __LIST_H__


