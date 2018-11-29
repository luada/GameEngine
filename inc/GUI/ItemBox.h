#ifndef __ITEM_BOX_H__
#define __ITEM_BOX_H__

#include "Prerequest.h"
#include "DDContainer.h"
#include "IBItemInfo.h"
#include "Any.h"
#include "EventPair.h"
#include "ScrollViewBase.h"

namespace GUI
{

	typedef delegates::CDelegate2<ItemBox*, Widget*> EventHandle_ItemBoxPtrWidgetPtr;
	typedef delegates::CDelegate3<ItemBox*, IntCoord&, bool> EventHandle_ItemBoxPtrIntCoordRefBool;
	typedef delegates::CDelegate3<ItemBox*, Widget*, const IBDrawItemInfo &> EventHandle_ItemBoxPtrWidgetPtrCIBCellDrawInfoRef;
	typedef delegates::CDelegate2<ItemBox*, size_t> EventHandle_ItemBoxPtrSizeT;
	typedef delegates::CDelegate2<ItemBox*, const IBNotifyItemData &> EventHandle_ItemBoxPtrCIBNotifyCellDataRef;

	class GUI_EXPORT ItemBox :
		public DDContainer,
		protected ScrollViewBase
	{
		RTTI_DERIVED(ItemBox)
		DEFINE_GET_THIS(ItemBox, BASS(DDContainer, END))

	public:
		ItemBox();

		//------------------------------------------------------------------------------//

		//! Get number of items
		//@ExportToLua
		size_t GetItemCount() const { return mItemsInfo.size(); }

		//! Insert an item into a array at a specified position
		void InsertItemAt(size_t index, Any data = Any::Null);
		//@ExportToLua
		void InsertItem(size_t index, Widget* value = nullptr) { InsertItemAt(index, value); }

		//! Add an item to the end of a array
		void AddItem(Any data = Any::Null) { InsertItemAt(ITEM_NONE, data); }
		//@ExportToLua
		void AppendItem(Widget* value = nullptr) { InsertItemAt(ITEM_NONE, value); }

		//! Remove item at a specified position
		void RemoveItemAt(size_t index);
		//@ExportToLua
		void RemoveItem(size_t index) { RemoveItemAt(index); }

		//! Remove all items
		//@ExportToLua
		void RemoveAllItems();

		//! Redraw at a specified position
		void RedrawItemAt(size_t index);
		//@ExportToLua
		void RedrawItem(size_t index) { RedrawItemAt(index); }

		//! Redraw all items
		//@ExportToLua
		void RedrawAllItems();


		//------------------------------------------------------------------------------//

		//! Get index of selected Item (ITEM_NONE if none selected)
		//@ExportToLua
		size_t GetIndexSelected() { return mIndexSelect; }

		//! Select specified index
		//@ExportToLua
		void SetIndexSelected(size_t index);

		//! Clear item selection
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
			ASSERT_RANGE(index, mItemsInfo.size(), "ItemBox::getItemDataAt");
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


		/** Set vertical alignment grid mode */
		//@ExportToLua
		void SetItemBoxAlignVert(bool value);
		/** Get vertical alignment grid mode flag */
		//@ExportToLua
		bool GetItemBoxAlignVert() { return mAlignVert; }

		/** Get item index by item Widget pointer */
		//@ExportToLua
		size_t GetIndexByWidget(Widget* widget);

		/** Get widget created for drop */
		//@ExportToLua
		Widget* GetWidgetDrag() { return mItemDrag; }

		/** Get item Widget pointer by item index if it is visible
			@note returned widget can be deleted, so this pointer
			is valid only at time when you got it and can be invalid
			next frame
		*/
		//@ExportToLua
		Widget* GetWidgetByIndex(size_t index);

		/** Interrupt drag as if widget was dropped into empty space */
		//@ExportToLua
		void ResetDrag();

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

	/*event:*/
		/** Event : request for creating new item
			signature : void Method(GUI::ItemBox* sender, GUI::Widget* item)
			@param _sender widget that called this event
			@param _item widget item pointer
		*/
		EventHandle_ItemBoxPtrWidgetPtr requestCreateWidgetItem;

		/** Event : request for item coordinate
			signature : void Method(GUI::ItemBox* sender, GUI::IntCoord& coord, bool drag)
			@param _sender widget that called this event
			@param coord write heer item coordinate
			@param _drag is this item dragging
		*/
		EventHandle_ItemBoxPtrIntCoordRefBool requestCoordItem;

		/** Event : request for item redraw
			signature : void Method(GUI::ItemBox* sender, GUI::Widget* item, const GUI::IBDrawItemInfo& info)
			@param _sender widget that called this event
			@param _item widget item pointer
			@param _info item info
		*/
		EventHandle_ItemBoxPtrWidgetPtrCIBCellDrawInfoRef requestDrawItem;

		/** Event : doubleclick or enter pressed on item
			signature : void Method(GUI::ItemBox* sender, size_t index)
			@param _sender widget that called this event
			@param index item index
		*/
		EventHandle_ItemBoxPtrSizeT eventSelectItemAccept;

		/** Event : position of selected item was changed
			signature : void Method(GUI::ItemBox* sender, size_t index)
			@param _sender widget that called this event
			@param index item index
		*/
		EventHandle_ItemBoxPtrSizeT eventChangeItemPosition;

		/** Event : click on item
			signature : void Method(GUI::ItemBox* sender, size_t index)
			@param _sender widget that called this event
			@param index item index
		*/
		EventHandle_ItemBoxPtrSizeT eventMouseItemActivate;

		/** Event : notify about event in item widget
			signature : void Method(GUI::ItemBox* sender, const GUI::IBNotifyItemData& info)
			@param _sender widget that called this event
			@param _info info about item notify
		*/
		EventHandle_ItemBoxPtrCIBNotifyCellDataRef eventNotifyItem;


	/*internal:*/
		virtual void _initialise(WidgetStyle style, const IntCoord& coord, Align align, ResourceSkin* info, Widget* parent, ICroppedRectangle * croppedParent, IWidgetCreator * creator, const std::string& name);

	protected:
		virtual ~ItemBox();

		struct ItemDataInfo
		{
			ItemDataInfo(Any data) :
				data(data) { }
			Any data;
		};
		typedef std::vector<ItemDataInfo> VectorItemInfo;

		void BaseChangeWidgetSkin(ResourceSkin* info);

		virtual void OnMouseButtonPressed(int left, int top, MouseButton id);
		virtual void OnMouseButtonReleased(int left, int top, MouseButton id);
		virtual void OnMouseDrag(int left, int top);

		virtual void OnMouseWheel(int rel);
		virtual void OnKeyLostFocus(Widget* _new);
		virtual void OnKeySetFocus(Widget* old);

		void NotifyKeyButtonPressed(Widget* sender, KeyCode key, Char _char);
		void NotifyKeyButtonReleased(Widget* sender, KeyCode key);
		void NotifyScrollChangePosition(VScroll* sender, size_t index);
		void NotifyMouseWheel(Widget* sender, int rel);
		void NotifyRootMouseChangeFocus(Widget* sender, bool focus);
		void NotifyMouseButtonDoubleClick(Widget* sender);
		void _requestGetContainer(Widget* sender, Widget*& container, size_t& index);
		void NotifyMouseDrag(Widget* sender, int left, int top);
		void NotifyMouseButtonPressed(Widget* sender, int left, int top, MouseButton id);
		void NotifyMouseButtonReleased(Widget* sender, int left, int top, MouseButton id);


		virtual void RemoveDropItems();
		virtual void UpdateDropItems();
		virtual void UpdateDropItemsState(const DDWidgetState& state);

		void UpdateMetrics();

		void _updateAllVisible(bool redraw);

		void UpdateFromResize();

		Widget* GetItemWidget(size_t index);

		void _setContainerItemInfo(size_t index, bool set, bool accept);

		void ResetCurrentActiveItem();
		void findCurrentActiveItem();

		virtual size_t _getContainerIndex(const IntPoint& point);

		virtual void _resetContainer(bool update);

	private:
		void InitialiseWidgetSkin(ResourceSkin* info);
		void ShutdownWidgetSkin();

		size_t CalcIndexByWidget(Widget* widget);

		void RequestItemSize();

		virtual IntSize GetContentSize();
		virtual IntPoint GetContentPosition();
		virtual IntSize GetViewSize() const;
		virtual void eraseContent();
		virtual size_t GetHScrollPage();
		virtual size_t GetVScrollPage();
		virtual Align GetContentAlign();
		virtual void SetContentPosition(const IntPoint& point);

		IntRect _getClientAbsoluteRect();
		Widget* _getClientWidget();
		const Widget* _getClientWidget() const;

	private:
		VectorWidgetPtr mVectorItems;

		IntSize mSizeItem;

		IntSize mContentSize;
		IntPoint mContentPosition;

		int mCountItemInLine;
		int mCountLines;

		int mFirstVisibleIndex;
		int mFirstOffsetIndex;

		size_t mIndexSelect;
		size_t mIndexActive;
		size_t mIndexAccept;
		size_t mIndexRefuse;

		bool mIsFocus;

		VectorItemInfo mItemsInfo;

		Widget* mItemDrag;
		IntPoint mPointDragOffset;

		bool mAlignVert;

		std::string mDragLayer;

	};

} // namespace GUI

#endif // __ITEM_BOX_H__

